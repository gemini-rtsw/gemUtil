[schematic2]
uniq 6
[tools]
[detail]
w -412 491 100 0 HB inhier.HB.P -616 488 -208 488 ecalcs.$(src)Hb2Health.INPA
w 960 235 100 0 HMSG esirs.$(src)Health.OMSS 944 232 976 232 976 136 1136 136 outhier.HMSG.p
w 1040 267 100 0 HLTH esirs.$(src)Health.VAL 944 264 1136 264 outhier.HLTH.p
w 960 299 100 0 FLNK esirs.$(src)Health.FLNK 944 296 976 296 976 392 1136 392 outhier.FLNK.p
w 100 -165 100 0 n#1 elongouts.$(src)OldHb.VAL 48 -168 152 -168 152 -8 -320 -8 -320 456 -208 456 ecalcs.$(src)Hb2Health.INPB
w -372 -133 100 0 n#-1 elongouts.$(src)OldHb.DOL -208 -136 -536 -136 -536 488 junction
w -436 107 100 0 n#2 inhier.SLNK.P -664 104 -208 104 ecalcs.$(src)Hb2Health.SLNK
w 136 331 100 0 n#3 ecalcs.$(src)Hb2Health.FLNK 80 328 192 328 192 -48 -360 -48 -360 -168 -208 -168 elongouts.$(src)OldHb.SLNK
w 304 299 100 0 n#4 ecalcs.$(src)Hb2Health.VAL 80 296 528 296 esirs.$(src)Health.INP
w 148 771 100 0 n#5 timer.timer#2.FLNK -25 768 320 768 320 136 528 136 esirs.$(src)Health.SLNK
w 58 -126 -100 0 n#5 elongouts.$(src)OldHb.FLNK 48 -136 320 -136 320 136 junction
s -64 509 100 0 #define HEALTH_GOOD 0
s -64 485 100 0 #define HEALTH_BAD 2
[cell use]
use bb200tr -832 -440 -100 0 frame
xform 0 448 384
use inhier -680 63 100 0 SLNK
xform 0 -664 104
use inhier -674 484 100 0 HB
xform 0 -616 488
use outhier 1104 351 100 0 FLNK
xform 0 1120 392
use outhier 1104 95 100 0 HMSG
xform 0 1120 136
use outhier 1104 223 100 0 HLTH
xform 0 1120 264
use esirs 722 40 100 0 $(src)Health
xform 0 736 200
p 688 200 100 0 1 FTVL:LONG
p 604 342 100 0 1 SNAM:hb2healthSirSub
p 640 40 100 1024 0 name:
p 638 40 100 0 -1 PV:$(top)
use elongouts -82 -265 100 0 $(src)OldHb
xform 0 -80 -168
p -166 -265 100 0 -1 PV:$(top)
p -167 -294 100 0 1 OMSL:closed_loop
use ecalcs -115 32 100 0 $(src)Hb2Health
xform 0 -64 280
p -27 447 100 0 1 CALC:(A=B)?2:0
p -199 32 100 0 -1 PV:$(top)
use timer -216 624 100 0 timer#2
xform 0 -112 728
p -224 670 100 0 1 setdev:dev $(src)
[comments]
