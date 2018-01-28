# cache_coherence
Cache protocol checked with Murphi. For the cache coherence lab offered by CMU [here](https://users.ece.cmu.edu/~bgold/teaching/coherence.html).
=====
**Sunday 28/01/18** 
Works for 3 processors, but involved a little bit of cheating (namely increasing the network bandwidth from #processors+1 to #processors+3).
Noteworthy: Uses both NACKS and stalls.
Not optimized.

=====
Last issue:
Ran into issues with a race that more or less goes like this:

| C1            | C2                | Directory           | Network                |
| ------------- |:-----------------:|:-------------------:|-----------------------:|
| I             | I                 |  I                  | {}                     |
|GetM/IM        | I                 |  I                  | {getM1}                |
| IM            | GetS/IS           | I                   | {getM1, getS1}         |
|IM             | IS                | <-getS1, Data->C2/S | {DataResp1}            |
| IM            | IS                | <-getM1, Inv->C2/IM | {DataResp1, Inv}       |
| IM            | <-Inv, ->InvAck/I | IM                  | {DataResp1, InvAck}    |
| IM            | I                 | <-InvAck, data->C1/M| {DataResp1, DataResp2} |
| <-DataResp2/M | I                 | M                   | {DataResp1}            |
| M             | GetS/IS           | M                   | {DataResp1, getS2}     |
| M             | **Sees DataResp1, takes it as directoy responding to getS2./S** | M | {getS2} |

Now the directory controller is in M, and C1 thinks it is exclusive yet C2 has (unknowingly) received a stale DataResp.

I tried to solve this by introducing "timestamps" to messages to see whether they were stale or not, but ultimately it seemed to make more sense to just allow the processor to stall Inv messages when it is in IS and IM.

|  test   |   ing  |
| ------  | ------ |
| results | ???    |
