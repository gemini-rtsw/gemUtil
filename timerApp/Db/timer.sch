[schematic2]
uniq 5
[tools]
[detail]
w 1072 243 100 0 FLNK efanouts.efanouts#11.LNK1 896 240 1248 240 outhier.FLNK.p
w 280 -13 100 0 n#1 ecalcouts.$(dev)TmrCalc.VAL 264 -16 296 -16 296 152 -176 152 -176 48 -56 48 ecalcouts.$(dev)TmrCalc.INPA
w -152 19 100 0 n#2 elongouts.$(dev)TmrDelay.VAL -248 16 -56 16 ecalcouts.$(dev)TmrCalc.INPB
w -493 51 100 0 n#3 hwin.hwin#20.in -496 48 -496 48 elongouts.$(dev)TmrDelay.DOL
w 436 -77 100 0 n#4 ecalcouts.$(dev)TmrCalc.OUT 264 -80 608 -80 608 -16 640 -16 hwoutl.hwoutl#22.outp
s -844 -118 100 0 Delay can be changed with a dbput() to this record. Default is $(delay)
s -156 106 100 0 Output processing is triggered every B scans
[cell use]
use bb200tr -960 -888 -100 0 frame
xform 0 320 -64
use outhier 1216 199 100 0 FLNK
xform 0 1232 240
use efanouts 656 23 100 0 efanouts#11
xform 0 776 176
p 768 16 100 1024 -1 name:$(top)$(dev)TmrFo
use ecalcouts 100 -135 100 0 $(dev)TmrCalc
xform 0 104 -16
p 32 8 100 0 1 CALC:(A+1)%B
p 4 -182 100 0 1 OOPT:Transition To Zero
p 16 -135 100 0 -1 PV:$(top)
p 8 -136 100 0 0 name:$(top)$(I)
p 32 -21 100 0 1 SCAN:$(scanres)
p -128 24 75 0 0 pproc(INPB):PP
p -96 24 75 0 0 palrm(INPB):NMS
use elongouts -385 -85 100 0 $(dev)TmrDelay
xform 0 -368 16
p -469 -85 100 0 -1 PV:$(top)
use hwin -688 32 100 0 hwin#20
xform 0 -592 48
p -685 40 100 0 -1 val(in):$(delay)
use hwoutl 640 -88 100 0 hwoutl#22
xform 0 832 -40
p 738 -25 100 0 -1 val(outp):$(top)$(dev)TmrFo.PROC
[comments]
