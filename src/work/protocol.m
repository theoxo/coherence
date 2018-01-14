-- Coherence Protocol Lab
-- Protocol Framework

-- See the lines marked TODO in file below.
-- NOTE: this file will not compile until you fill in some minimal
-- additional states and messages.  Try adding support for just a 
-- read request first (comment out other starting rules).

----------------------------------------------------------------------
-- Constants
----------------------------------------------------------------------
const
  -- TODO: start with this number at 1, then increase to 2 and eventually 3
  ProcCount: 1;          -- number processors

  -- VC0 for requests, VC1 for fwds, VC2 for responses
  VC0: 0;                -- low priority
  VC1: 1;
  VC2: 2;                -- high priority
  NumVCs: VC2 - VC0 + 1;
  QMax: 2;
  NetMax: ProcCount+1;
  

----------------------------------------------------------------------
-- Types
----------------------------------------------------------------------
type
  Proc: scalarset(ProcCount);   -- unordered range of processors
  Home: enum { HomeType };      -- need enumeration for IsMember calls
  Node: union { Home , Proc };

  VCType: VC0..NumVCs-1;

  -- Message enumeration: you must support the first three, but will need to
  -- add more message types (e.g., various ACKs)
  MessageType: enum {  ReadReq,         -- request for shared state
		                   WriteReq,        -- write request
		                   WBReq,            -- writeback request (w/ or wo/ data)
                       -- TODO: add more messages here!
                       AckRead, -- acknowledge request for S
                       AckWrite, -- acknowledge request for M
                       AckWB, -- acknowledge request for writeback
                       AckData, -- acknowledge data has been received
                       DataReqS, -- request data from owner and have it change to S
                       DataReqI, -- request data from owner and have it change to I
                       DataNoReqI, -- go to I, no non-home requestor to send to
                       DataResp, -- send data
                       Inv -- invalidate
                    };

  Message:
    Record
      mtype: MessageType;
      src: Node;
      -- don't need a destination for verification
      vc: VCType;
      aux: Node;  -- participating node (used when forwarding msgs)
      cnt: 0..ProcCount;
    End;

  HomeState:
    Record
      -- home node state: you have three stable states (M,S,I) but need to
      -- add transient states during races
      state: enum { HM, HS, HI, HSd, HId };
      -- TODO: add transient states here! };

      owner: Node;	
      sharers: multiset [ProcCount] of Node; 
    End;

  ProcState:
    Record
      -- processor state: again, three stable states (M,S,I) but you need to
      -- add transient states to support races
      state: enum { PM, PS, PI, PIMad, PIMa, PIMd, PSMa, PMIa, PSI, PMS, PIIa
                  };
    End;

----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
  HomeNode:  HomeState;
  Procs: array [Proc] of ProcState;
  Net:   array [Node] of multiset [NetMax] of Message;
  msg_processed: boolean;

----------------------------------------------------------------------
-- Procedures
----------------------------------------------------------------------
Procedure Send(mtype:MessageType;
	             dst:Node;
	             src:Node;
               vc:VCType;
	             aux:Node;
               cnt:0..ProcCount);
var msg:Message;
Begin
  Assert (MultiSetCount(i:Net[dst], true) < NetMax) "Too many messages";
  msg.mtype := mtype;
  msg.src   := src;
  msg.vc    := vc;
  msg.aux   := aux;
  msg.cnt   := cnt;
  MultiSetAdd(msg, Net[dst]);
End;

Procedure ErrorUnhandledMsg(msg:Message; n:Node);
Begin
  switch msg.mtype
  case WriteReq, ReadReq, WBReq:
    msg_processed := false;  -- we can receive a raw request any time
  else
    error "Unhandled message type!";
  endswitch;
End;

Procedure ErrorUnhandledState();
Begin
  error "Unhandled state!";
End;

Procedure AddToSharersList(n:Node);
Begin
  if MultiSetCount(i:HomeNode.sharers, HomeNode.sharers[i] = n) = 0
  then
    MultiSetAdd(n, HomeNode.sharers);
  endif;
End;

Procedure RemoveFromSharersList(n:Node);
Begin
  MultiSetRemovePred(i:HomeNode.sharers, HomeNode.sharers[i] = n);
End;

Procedure HomeReceive(msg:Message);
var cnt:0..ProcCount;
Begin
  -- compiler barfs if we put this inside the switch
  cnt := MultiSetCount(i:HomeNode.sharers, true);

  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  switch HomeNode.state
  case HI:
    Assert (cnt = 0) "Sharers list non-empty, but line is Invalid";

    switch msg.mtype

    case ReadReq:
      -- TODO: perform actions here!
      HomeNode.state := HS;
      AddToSharersList(msg.src);
      Send(AckRead, msg.src, HomeType, VC2, msg.aux, msg.cnt);
      -- what should the last 2 arguments be? is the VC convention followed right?


    case WriteReq:
      -- TODO: perform actions here!
      HomeNode.state := HM;
      HomeNode.owner := msg.src;
      Send(AckWrite, msg.src, HomeType, VC2, msg.aux, msg.cnt);

    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HM:
    Assert (IsUndefined(HomeNode.owner) = false) 
       "HomeNode has no owner, but line is Modified";

    switch msg.mtype

    case ReadReq:
      -- TODO: perform actions here!
      -- Need to: get data. Make sure that owner changes to S. Change self to HSd. Allow requestor to obtain S.
      Send(DataReqS, HomeNode.owner, HomeType, VC1, msg.src, msg.cnt);
      HomeNode.state := HSd;
      AddToSharersList(msg.src);
      AddToSharersList(HomeNode.owner);
      Send(AckRead, msg.src, HomeType, VC2, msg.aux, msg.cnt);

    case WriteReq:
      -- TODO: perform actions here!
      -- Need to: get data. Make sure that owner changes to I. Self stay in HM. Allow requestor to obtain M.
      Send(DataReqI, HomeNode.owner, HomeType, VC1, msg.src, msg.cnt);
      Send(AckWrite, msg.src, HomeType, VC2, msg.aux, msg.cnt);
      
    case WBReq:
      -- TODO: perform actions here!
      Send(DataNoReqI, HomeNode.owner, HomeType, VC1, msg.aux, msg.cnt);
      HomeNode.state := HId;

    case DataResp:
      -- Have received data as part of a M-to-M transition.
      Send(AckData, msg.src, HomeType, VC2, UNDEFINED, UNDEFINED);

    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HS:
    Assert (cnt != 0) "sharers list empty, but line is shared";

    switch msg.mtype

    case ReadReq:
      -- TODO: perform actions here!
      AddToSharersList(msg.src);
      Send(AckRead, msg.src, HomeType, VC2, msg.aux, msg.cnt);

    case WriteReq:
      -- TODO: perform actions here!
      -- invalidate all sharers -- does this syntax work?

      for proc:Proc do
        RemoveFromSharersList(proc);
        Send(Inv, proc, HomeType, VC0, UNDEFINED, msg.cnt); -- will need to handle Inv in every processor state
      endfor;
    
      HomeNode.state := HM;
      HomeNode.owner := msg.src;
      Send(AckWrite, msg.src, HomeType, VC2, msg.aux, msg.cnt);
      
    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  -- TODO: add other cases from home node state here!
  case HSd:
      Assert (cnt != 0) "sharers list empty, but line is shared";

      switch msg.mtype

      case DataResp:
        -- Have received data, can safely transition to HS (after having updated memory)
        HomeNode.state := HS;
        -- Let sender know we've received
        Send(AckData, msg.src, HomeType, VC2, UNDEFINED, msg.cnt); -- note still don't know how to handle cnt

      else -- probably want to stall rather than throw error
        ErrorUnhandledMsg(msg, HomeType);
      endswitch;

  case HId:
      switch msg.mtype

      case DataResp:
        -- Received data, go to HI
        HomeNode.state := HI;
        -- Let sender know we've received
        Send(AckData, msg.src, HomeType, VC2, UNDEFINED, msg.cnt); -- note still don't know how to handle cnt
      
      else -- again probably not what we want
        ErrorUnhandledMsg(msg, HomeType);
      endswitch;

  ----------------------------
  -- Error catch
  ----------------------------
  else
    ErrorUnhandledState();

  endswitch;
End;

Procedure ProcReceive(msg:Message; p:Proc);
Begin
  -- default to 'processing' message.  set to false otherwise
  msg_processed := true;

  alias ps:Procs[p].state do

  switch ps
  case PI:

    switch msg.mtype
      -- TODO: handle message cases here!

    -- in PI, we don't expect any messages - we want to be the one to initiate a coherence transaction.
    -- thus there are no cases to consider, other than an unexpected (snooping) Inv or Data (from PIMd -> PI)
    case Inv:
      -- do nothing

    case DataResp:
      -- do nothing

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PM:

    switch msg.mtype
      -- TODO: handle message cases here!

    case Inv:
      -- do nothing

    case DataReqS:
        -- Have received a forwarded data request from another processor and been asked to go to S.
        ps := PMS;
        Send(DataResp, HomeType, p, VC0, UNDEFINED, msg.cnt);
        Send(DataResp, msg.aux, p, VC0, UNDEFINED, msg.cnt);

    case DataReqI:
        -- As before, but go to I
        ps := PMIa;
        Send(DataResp, HomeType, p, VC0, UNDEFINED, msg.cnt);
        Send(DataResp, msg.aux, p, VC0, UNDEFINED, msg.cnt);

    case DataNoReqI:
        ps := PMIa;
        Send(DataResp, HomeType, p, VC0, UNDEFINED, msg.cnt);

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PS:

    switch msg.mtype
      -- TODO: handle message cases here!

    case Inv:
      -- Have been asked to invalidate as someone else has requested write permission
      ps := PI;

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  -- TODO: add additional states from Proc here!  

  case PIMad:
    switch msg.mtype

    case Inv:
      ps := PIIa;
    
    case AckWrite:
      -- Seen ack, now need data
      ps := PIMd;

    case DataResp:
      ps := PIMa;

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PIMa:
    switch msg.mtype

    case Inv:
      ps := PIIa;

    case AckWrite:
      ps := PM;

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PIMd:
    switch msg.mtype
      
    case Inv:
      ps := PI;

    case DataResp:
      ps := PM;

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PSMa:
    switch msg.mtype

    case AckWrite:
        ps := PM;

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PMIa:
    switch msg.mtype

    case AckData:
      ps := PI;

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;


  case PMS:
    switch msg.mtype
    
    case AckData:
      ps := PS;

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PIIa:
    switch msg.mtype

    case AckWrite:
      ps := PI;

    else
      ErrorUnhandledMsg(msg, p);
    endswitch;

  ----------------------------
  -- Error catch
  ----------------------------
  else
    ErrorUnhandledState();

  endswitch;

  endalias;
End;

----------------------------------------------------------------------
-- Rules
----------------------------------------------------------------------

-- Processor actions (affecting coherency)
ruleset n:Proc Do
  alias p:Procs[n] Do

  rule "read request"
    p.state = PI 
  ==>
    Send(ReadReq, HomeType, n, VC0, UNDEFINED, UNDEFINED);
    -- TODO: any other actions?
  endrule;

  rule "write request"
    (p.state = PI)
  ==>
    Send(WriteReq, HomeType, n, VC0, UNDEFINED, UNDEFINED);
    -- TODO: any other actions?
  endrule;

  rule "upgrade request"
    (p.state = PS)
  ==>
    Send(WriteReq, HomeType, n, VC0, UNDEFINED, UNDEFINED);
    -- TODO: any other actions?
  endrule;

  rule "writeback"
    (p.state = PM)
  ==>
    Send(WBReq, HomeType, n, VC2, UNDEFINED, UNDEFINED);  -- fixme
    -- TODO: any other actions?
  endrule;

  rule "evict"
    (p.state = PS)
  ==>
    p.state := PI;
  endrule;

  endalias;
endruleset;

-- receive rules
ruleset n:Node do
  choose midx:Net[n] do
    alias chan:Net[n] do
    alias msg:chan[midx] do

    rule "receive"
      (msg.vc = VC2) |
      (msg.vc = VC1 & MultiSetCount(m:chan, chan[m].vc = VC2)  = 0) |
      (msg.vc = VC0 & MultiSetCount(m:chan, chan[m].vc = VC2)  = 0 
                    & MultiSetCount(m:chan, chan[m].vc = VC1)  = 0)
    ==>

      if IsMember(n, Home)
      then
        HomeReceive(msg);

	      if msg_processed
	      then
	        MultiSetRemove(midx, chan);
	      endif;

      else
        ProcReceive(msg, n);

	      if msg_processed
	      then
	        MultiSetRemove(midx, chan);
	      endif;
	  
      endif;

    endrule;
  
    endalias;
    endalias;
  endchoose;  
endruleset;

----------------------------------------------------------------------
-- Startstate
----------------------------------------------------------------------
startstate

  -- home node initialization
  HomeNode.state := HI;
  undefine HomeNode.sharers;
  undefine HomeNode.owner;
  --undefine HomeNode.pending_node;
  
  -- processor initialization
  for i:Proc do
    Procs[i].state := PI;
    -- TODO: any other initialization?
  endfor;

  -- network initialization
  undefine Net;
endstartstate;

----------------------------------------------------------------------
-- Invariants
----------------------------------------------------------------------

invariant "modified w/ empty sharers list"
  HomeNode.state = HM
    ->
      MultiSetCount(i:HomeNode.sharers, true) = 0

