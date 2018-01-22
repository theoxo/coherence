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
                       AckPut,
                       AckRead, -- acknowledge request for S
                       AckWrite, -- acknowledge request for M
                       AckWB, -- acknowledge request for writeback
                       AckData, -- acknowledge data has been received
                       Fwd_GetS, -- request data from owner and have it change to S
                       Fwd_GetM, -- request data from owner and have it change to I
                       DataNoReqI, -- go to I, no non-home requestor to send to
                       DataResp, -- send data
                       Inv, -- invalidate
                       PutS, -- degrade
                       AckInv
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
      state: enum { HM, HS, HI, HSd, HMa, HMd };
      -- TODO: add transient states here! };

      owner: Node;	
      sharers: multiset [ProcCount] of Node; 
    End;

  ProcState:
    Record
      -- processor state: again, three stable states (M,S,I) but you need to
      -- add transient states to support races
      state: enum { PM, PS, PI, PIMad, PIMa, PIMd, PISad, PISa, PISd, PSMad, PSMd, PSMa, PMIa, PSIa, PMS, PIIa
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
  NumberAck: 0..ProcCount;

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
      Send(AckRead, msg.src, HomeType, VC1, msg.aux, UNDEFINED);
      Send(DataResp, msg.src, HomeType, VC2, msg.aux, UNDEFINED);
      -- what should the last 2 arguments be? is the VC convention followed right?


    case WriteReq:
      -- TODO: perform actions here!
      Send(AckWrite, msg.src, HomeType, VC1, msg.aux, UNDEFINED);
      -- Should also send "fake" data response?
      Send(DataResp, msg.src, HomeType, VC2, msg.aux, UNDEFINED);
      HomeNode.state := HM;
      HomeNode.owner := msg.src;

    else
      msg_processed := false;

    endswitch;

  case HM:
    Assert (IsUndefined(HomeNode.owner) = false) 
       "HomeNode has no owner, but line is Modified";

    switch msg.mtype

    case ReadReq:
      -- Need to: get data. Make sure that owner changes to S. Change self to HSd. Allow requestor to obtain S.
      Send(Fwd_GetS, HomeNode.owner, HomeType, VC1, msg.src, UNDEFINED);
      HomeNode.state := HSd;
      AddToSharersList(msg.src);
      AddToSharersList(HomeNode.owner);
      Send(AckRead, msg.src, HomeType, VC1, msg.aux, UNDEFINED);

    case WriteReq:
      -- TODO: perform actions here!
      -- Need to: get data. Make sure that owner changes to I. Self stay in HM. Allow requestor to obtain M.
      Send(Fwd_GetM, HomeNode.owner, HomeType, VC1, msg.src, UNDEFINED);
      Send(AckWrite, msg.src, HomeType, VC1, msg.aux, UNDEFINED);
      HomeNode.state := HMd;
      
    case WBReq:
      HomeNode.state := HI;
      Send(AckWB, msg.src, HomeType, VC1, msg.aux, UNDEFINED);

    else
      msg_processed := false;

    endswitch;

  case HS:
    Assert (cnt != 0) "sharers list empty, but line is shared";

    switch msg.mtype

    case PutS:
      RemoveFromSharersList(msg.src);
      Send(AckPut, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED);

      if MultiSetCount(i:HomeNode.sharers, true) = 0 then
        HomeNode.state := HI;
      endif;

    case ReadReq:
      -- TODO: perform actions here!
      AddToSharersList(msg.src);
      Send(AckRead, msg.src, HomeType, VC1, msg.aux, UNDEFINED);
      Send(DataResp, msg.src, HomeType, VC2, msg.aux, UNDEFINED);

    case WriteReq:
      -- TODO: perform actions here!
      -- invalidate all sharers -- does this syntax work?

      HomeNode.state := HMa;
    NumberAck := MultiSetCount(i:HomeNode.sharers, true);  
      HomeNode.owner := msg.src;

      for proc:Proc do
        RemoveFromSharersList(proc);


        if proc != HomeNode.owner then 
          Send(Inv, proc, HomeType, VC1, UNDEFINED, UNDEFINED); 
        endif;
          -- will need to handle Inv in every processor state

      endfor;
    

    else
      msg_processed := false;

    endswitch;

  -- TODO: add other cases from home node state here!
  case HSd:
      Assert (cnt != 0) "sharers list empty, but line is shared";

      switch msg.mtype

      case DataResp:
        -- Have received data, can safely transition to HS (after having updated memory)
        HomeNode.state := HS;
        -- Let sender know we've received
        Send(AckData, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED); -- note still don't know how to handle cnt

      case PutS:
        RemoveFromSharersList(msg.src);
        Send(AckPut, msg.src, HomeType, VC1, UNDEFINED, UNDEFINED);

        if MultiSetCount(i:HomeNode.sharers, true) = 0 then
          HomeNode.state := HI;
        endif;

      else -- probably want to stall rather than throw error
        msg_processed := false;
      endswitch;


    case HMa:
        switch msg.mtype

        case AckInv:
          NumberAck := NumberAck - 1;
        
          if NumberAck = 0 then
              HomeNode.state := HM;
              Send(AckWrite, msg.src, HomeType, VC1, msg.aux, UNDEFINED);
              Send(DataResp, msg.src, HomeType, VC2, msg.aux, UNDEFINED);
          endif;

        else
          msg_processed := false;

        endswitch;

    case HMd:
        switch msg.mtype

        case DataResp:
        HomeNode.state := HM;

        else
          msg_processed := false;

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
    -- thus there are no cases to consider, other than an unexpected (snooping) Inv or Data (from PIMd -{inv}> PI)
    case Inv:
      -- do nothing

    case DataResp:
      -- do nothing

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PM:

    switch msg.mtype
      -- TODO: handle message cases here!

    case Inv:
      -- do nothing

    case Fwd_GetS:
        -- Have received a forwarded data request from another processor and been asked to go to S.
        ps := PMS;
        Send(DataResp, HomeType, p, VC2, UNDEFINED, UNDEFINED);
        Send(DataResp, msg.aux, p, VC2, UNDEFINED, UNDEFINED);

    case Fwd_GetM:
        -- As before, but go to I
        ps := PMIa;
        Send(DataResp, HomeType, p, VC2, UNDEFINED, UNDEFINED);
        Send(DataResp, msg.aux, p, VC2, UNDEFINED, UNDEFINED);

    case DataNoReqI:
        ps := PMIa;
        Send(DataResp, HomeType, p, VC2, UNDEFINED, UNDEFINED);

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PS:

    switch msg.mtype
      -- TODO: handle message cases here!

    case Inv:
      -- Have been asked to invalidate as someone else has requested write permission
      Send(AckInv, HomeType, p, VC2, UNDEFINED, UNDEFINED);
      ps := PI;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  -- TODO: add additional states from Proc here!  

  case PIMad:
    switch msg.mtype

    case Inv:
      -- Irrelevant snooped inv;
      -- Processor is not a sharer so how can it have been inv?
      -- thus do nothing
    
    case Fwd_GetS:
      -- stall
      msg_processed := false;

    case Fwd_GetM:
      -- stall
      msg_processed := false;

    case DataNoReqI:
      -- stall
      msg_processed := false;

    case AckWrite:
      -- Seen ack, now need data
      ps := PIMd;

    case DataResp:
      ps := PIMa;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PIMa:
    switch msg.mtype

    case Fwd_GetS:
      -- stall
      msg_processed := false;

    case Fwd_GetM:
      -- stall
      msg_processed := false;

    case DataNoReqI:
      -- stall
      msg_processed := false;

    case Inv:
      -- Irrelevant snooped inv;
      -- Processor is not a sharer so how can it have been inv?
      -- thus do nothing

    case AckWrite:
      ps := PM;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PIMd:
    switch msg.mtype

    case Inv:
      -- Irrelevant snooped inv;
      -- Processor is not a sharer so how can it have been inv?
      -- thus do nothing
      
    case DataResp:
      ps := PM;

    case Fwd_GetS:
      -- stall
      msg_processed := false;

    case Fwd_GetM:
      -- stall
      msg_processed := false;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PSMad:
    switch msg.mtype

    case AckWrite:
        ps := PSMd;

    case Inv:
      ps := PIMad;
      Send(AckInv, HomeType, p, VC2, UNDEFINED, UNDEFINED);

    case DataResp:
      ps := PSMa;

    case Fwd_GetS:
      -- stall
      msg_processed := false;

    case Fwd_GetM:
      -- stall
      msg_processed := false;

    case DataNoReqI:
      -- stall
      msg_processed := false;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PSMa:
    switch msg.mtype

    case AckWrite:
        ps := PM;

    case Inv:
      ps := PIMa;

    case Fwd_GetS:
      -- stall
      msg_processed := false;

    case Fwd_GetM:
      -- stall
      msg_processed := false;

    case DataNoReqI:
      -- stall
      msg_processed := false;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PSMd:
    switch msg.mtype

    case DataResp:
      ps := PM;

    case Inv:
      ps := PIMd;

    case Fwd_GetS:
      -- stall
      msg_processed := false;

    case Fwd_GetM:
      -- stall
      msg_processed := false;

    case DataNoReqI:
      -- stall
      msg_processed := false;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PMIa:
    switch msg.mtype

    case Inv:
      -- do nothing

    case Fwd_GetS:
        -- Have received a forwarded data request from another processor and been asked to go to S.
        ps := PSIa;
        Send(DataResp, HomeType, p, VC2, UNDEFINED, UNDEFINED);
        Send(DataResp, msg.aux, p, VC2, UNDEFINED, UNDEFINED);

    case Fwd_GetM:
        -- Only need to send data to req to uphold our end of the trade
        Send(DataResp, msg.aux, p, VC2, UNDEFINED, UNDEFINED);
    
    case AckData:
      -- have received data acknowledgement due to previously having been sent Fwd_GetM
      -- do nothing

    case AckWB:
      --put "have degraded\n";
      ps := PI;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;


  case PMS:
    switch msg.mtype
    
    case AckData:
      ps := PS;

    case Inv:
      -- stall until actual sharer
      msg_processed := false;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PIIa:
    switch msg.mtype

    case AckWrite:
      ps := PI;

    case AckRead:
      ps := PI;

    case AckPut:
      ps := PI;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PISad:
    switch msg.mtype

    case AckRead:
      ps := PISd;

    case Inv:
      -- stall until actual sharer
      msg_processed := false;

    case DataResp:
      -- Have been sent data as other processor owned all tokens for memory location,
      -- thus need to update ours before reading
      ps := PISa;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PISa:
    switch msg.mtype

    case AckRead:
      ps := PS;

    case Inv:
      -- stall until actual sharer
      msg_processed := false;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PISd:
    switch msg.mtype

    case Inv:
      -- stall until actual sharer
      msg_processed := false;

    case DataResp:
      -- Have been sent data as other processor owned all tokens for memory location,
      -- thus need to update ours before reading
      ps := PS;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PSIa:
    switch msg.mtype

    case AckPut:
      ps := PI;


    case Inv:
      -- Already going to I, so do nothing

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;
    
--  case PIIa:
  --  switch msg.mtype

    --case AckPut:
      --ps := PI;

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
    p.state := PISad;
  endrule;

  rule "write request"
    (p.state = PI)
  ==>
    Send(WriteReq, HomeType, n, VC0, UNDEFINED, UNDEFINED);
    -- TODO: any other actions?
    p.state := PIMad;
  endrule;

  rule "upgrade request"
    (p.state = PS)
  ==>
    Send(WriteReq, HomeType, n, VC0, UNDEFINED, UNDEFINED);
    -- TODO: any other actions?
    p.state := PSMad;
  endrule;

  rule "writeback"
    (p.state = PM)
  ==>
    Send(WBReq, HomeType, n, VC0, UNDEFINED, UNDEFINED);  -- fixme
    -- TODO: any other actions?
    p.state := PMIa;
  endrule;

  rule "evict"
    (p.state = PS)
  ==>
    Send(PutS, HomeType, n, VC0, UNDEFINED, UNDEFINED);
    p.state := PSIa;
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

