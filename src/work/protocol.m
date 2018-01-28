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
  ProcCount: 2;          -- number processors

  -- VC0 for requests, VC1 for fwds, VC2 for responses
  VC0: 0;                -- low priority
  VC1: 1;
  VC2: 2;                -- high priority
  NumVCs: VC2 - VC0 + 1;
  QMax: 2;
  NetMax: ProcCount+2;
  

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
                       DataResp, -- send data
                       Inv, -- invalidate
                       InvAck,
		                   WriteBack,
                       Force_WB,
                       NACK,
                       SpontWB, -- spontaneous write back
                       DataRespExclusive
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
      state: enum { HM, HS, HI, HSM, HMS, HMM };
      -- TODO: add transient states here! };

      owner: Node;	
      sharers: multiset [ProcCount] of Node; 
    End;

  ProcState:
    Record
      -- processor state: again, three stable states (M,S,I) but you need to
      -- add transient states to support races
      state: enum { PM, PS, PI, PIM, PIS, PSM
                  };
      cnt: 0..999;
    End;

----------------------------------------------------------------------
-- Variables
----------------------------------------------------------------------
var
  HomeNode:  HomeState;
  Procs: array [Proc] of ProcState;
  Net:   array [Node] of multiset [NetMax] of Message;
  msg_processed: boolean;
  NumberOfAcksPending: 0..ProcCount;
  ReplyTo: Proc;

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
      HomeNode.state := HS;
      AddToSharersList(msg.src);
      Send(DataResp, msg.src, HomeType, VC1, msg.aux, msg.cnt);

    case WriteReq:
      Send(DataRespExclusive, msg.src, HomeType, VC1, msg.aux, msg.cnt);
      HomeNode.state := HM;
      HomeNode.owner := msg.src;

    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HM:
    Assert (IsUndefined(HomeNode.owner) = false) 
       "HomeNode has no owner, but line is Modified";

    switch msg.mtype

    case ReadReq:
      if (HomeNode.owner = msg.src) then
        -- Must be a writeback incoming we have not yet received
        Send(NACK, msg.src, HomeType, VC1, UNDEFINED, msg.cnt);
      else
        Send(Force_WB, HomeNode.owner, HomeType, VC1, msg.src, msg.cnt);
        ReplyTo := msg.src;
        HomeNode.state := HMS;
      endif;

    case WriteReq:
      if (msg.src = HomeNode.owner) then
        -- there must be a waiting WriteBack that we have not yet seen!
        Send(NACK, msg.src, HomeType, VC1, UNDEFINED, msg.cnt);
      else
        HomeNode.state := HMM;
        ReplyTo := msg.src;
        Send(Force_WB, HomeNode.owner, HomeType, VC1, UNDEFINED, msg.cnt);
      endif;
      
    case SpontWB:
      HomeNode.state := HI;
      HomeNode.owner := UNDEFINED;

    else
      ErrorUnhandledMsg(msg, HomeType);

    endswitch;

  case HS:
    Assert (cnt != 0) "sharers list empty, but line is shared";

    switch msg.mtype

    case ReadReq:
      AddToSharersList(msg.src);
      Send(DataResp, msg.src, HomeType, VC2, msg.aux, msg.cnt);

    case WriteReq:
      HomeNode.state := HSM;
      NumberOfAcksPending := ProcCount; 
      ReplyTo := msg.src;

      for proc:Proc do
          Send(Inv, proc, HomeType, VC1, UNDEFINED, msg.cnt);
          -- will need to handle Inv in every processor state
      endfor;
    

    else
      msg_processed := false;

    endswitch;
  
  case HMS:
      switch msg.mtype

      case ReadReq:
        -- We're still waiting for WB
        Send(NACK, msg.src, HomeType, VC1, UNDEFINED, msg.cnt);

      case WriteReq:
        -- We're still waiting for WB
        Send(NACK, msg.src, HomeType, VC1, UNDEFINED, msg.cnt);

      case WriteBack:
        AddToSharersList(ReplyTo);
        Send(DataResp, ReplyTo, HomeType, VC2, UNDEFINED, msg.cnt);
        HomeNode.owner := UNDEFINED;
        ReplyTo := UNDEFINED;
        HomeNode.state := HS;

      case InvAck:
        -- Processor was forced to invalidate before data arrived.
        -- Can safely proceed as if we received data
        AddToSharersList(ReplyTo);
        Send(DataResp, ReplyTo, HomeType, VC2, UNDEFINED, msg.cnt);
        HomeNode.owner := UNDEFINED;
        ReplyTo := UNDEFINED;
        HomeNode.state := HS;

      endswitch;

  case HSM:
      switch msg.mtype

      case ReadReq:
        -- We're still waiting for invalidate(s) 
        Send(NACK, msg.src, HomeType, VC1, UNDEFINED, msg.cnt);

      case WriteReq:
        -- We're still waiting for WB
        Send(NACK, msg.src, HomeType, VC1, UNDEFINED, msg.cnt);

      case InvAck:
        NumberOfAcksPending := NumberOfAcksPending - 1;
        RemoveFromSharersList(msg.src);

        if (NumberOfAcksPending = 0) then
          Send(DataRespExclusive, ReplyTo, HomeType, VC2, UNDEFINED, msg.cnt);
          HomeNode.owner := ReplyTo;
          ReplyTo := UNDEFINED;
          HomeNode.state := HM;
        endif;
           
      endswitch;

  case HMM:
      switch msg.mtype

      case ReadReq:
        -- We're still waiting for WB
        Send(NACK, msg.src, HomeType, VC1, UNDEFINED, msg.cnt);

      case WriteReq:
        -- We're still waiting for WB
        Send(NACK, msg.src, HomeType, VC1, UNDEFINED, msg.cnt);

      case WriteBack:
        Send(DataRespExclusive, ReplyTo, HomeType, VC2, UNDEFINED, msg.cnt);
        HomeNode.owner := ReplyTo;
        ReplyTo := UNDEFINED;
        HomeNode.state := HM;

      case InvAck:
        -- Processor was forced to invalidate before data arrived.
        -- Can safely proceed as if we received data
        Send(DataRespExclusive, ReplyTo, HomeType, VC2, UNDEFINED, msg.cnt);
        HomeNode.owner := ReplyTo;
        ReplyTo := UNDEFINED;
        HomeNode.state := HM;

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

  if (msg.cnt = (Procs[p].cnt-1)) then
      -- have received old message that has since been overriden by another request we've made
  endif;

  switch ps

  case PI:

    switch msg.mtype
      -- TODO: handle message cases here!

    case Inv:
      -- must've already evicted!
      Send(InvAck, msg.src, p, VC2, UNDEFINED, Procs[p].cnt);

    case DataResp:
      -- stale data, do nothing

    case DataRespExclusive:
      -- must also be stale

    case Force_WB:
      -- must've written back already. ignore

    case NACK:
      -- must've been in a transition but then got inv'd,
      -- either way can safely ignore

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
      -- must've already evicted!
      Send(InvAck, msg.src, p, VC2, UNDEFINED, Procs[p].cnt);

    case Force_WB:
      -- As before, but go to I
      ps := PI;
      Send(WriteBack, HomeType, p, VC1, UNDEFINED, Procs[p].cnt);

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
      Send(InvAck, HomeType, p, VC2, UNDEFINED, Procs[p].cnt);
      ps := PI;

    case Force_WB:
      -- must've written back already. ignore

    case DataResp:
     -- this must be a lingering stale response from a previous request that got overriden by an Inv

    case DataRespExclusive:
     -- this must be a lingering stale response from a previous request that got overriden by an Inv

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  -- TODO: add additional states from Proc here!  

  case PIM:
    switch msg.mtype

    case Inv:
      -- Irrelevant snooped inv;
      -- Processor is not a sharer so how can it have been inv?
      Send(InvAck, HomeType, p, VC2, UNDEFINED, Procs[p].cnt);
      
    case DataRespExclusive:
      -- Our request has been fullfilled
      if (msg.cnt = (Procs[p].cnt-1)) then
        ps := PM;
      endif;

    case DataResp:
      -- Stale

    case Force_WB:
      -- Has arrived before we got the data. Will send InvAck to distinguish this case
      -- (on the directory's side). Data will be discarded when it arrives in PI.
      Send(InvAck, HomeType, p, VC2, UNDEFINED, Procs[p].cnt);
      ps := PI;

    case NACK:
      -- request was denied
      ps := PI;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PSM:
    switch msg.mtype

    case DataRespExclusive:
      -- Our request has been fullfilled
      if (msg.cnt = (Procs[p].cnt-1)) then
        ps := PM;
      endif;

    case DataResp:
      -- stale response

    case Inv:
      ps := PIM;
      Send(InvAck, HomeType, p, VC1, UNDEFINED, Procs[p].cnt);

    case Force_WB:
      -- Has arrived before we got the data. Will send InvAck to distinguish this case
      -- (on the directory's side). Data will be discarded when it arrives in PI.
      Send(InvAck, HomeType, p, VC2, UNDEFINED, Procs[p].cnt);
      ps := PI;

    case NACK:
      -- request was denied
      ps := PS;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
      ErrorUnhandledMsg(msg, p);
    endswitch;

  case PIS:
    switch msg.mtype

    case Inv:
      -- Inv arrived before data; data will be discarded in PI.
      ps := PI;
      Send(InvAck, HomeType, p, VC2, UNDEFINED, Procs[p].cnt);

    case DataResp:
      -- Our request has been fullfilled
      if (msg.cnt = (Procs[p].cnt-1)) then
        ps := PS;
      endif;

    case DataRespExclusive:
      -- stale response

    case Force_WB:
      -- must've written back already. ignore

    case NACK:
      -- request was denied
      ps := PI;

    else
      put "in ";
      put ps;
      put ", found unexpected ";
      put msg.mtype;
      put "\n";
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
    Send(ReadReq, HomeType, n, VC0, UNDEFINED, p.cnt);
    p.cnt := p.cnt + 1;
    p.state := PIS;
  endrule;

  rule "write request"
    (p.state = PI)
  ==>
    Send(WriteReq, HomeType, n, VC0, UNDEFINED, p.cnt);
    p.cnt := p.cnt + 1;
    p.state := PIM;
  endrule;

  rule "upgrade request"
    (p.state = PS)
  ==>
    Send(WriteReq, HomeType, n, VC0, UNDEFINED, p.cnt);
    p.cnt := p.cnt + 1;
    p.state := PSM;
  endrule;

  rule "writeback"
    (p.state = PM)
  ==>
    Send(SpontWB, HomeType, n, VC0, UNDEFINED, p.cnt);  
    p.cnt := p.cnt + 1;
    p.state := PI;
  endrule;

  rule "evict"
    (p.state = PS)
  ==>
    p.state := PI; -- silent eviction
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
    Procs[i].cnt := 0;
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

