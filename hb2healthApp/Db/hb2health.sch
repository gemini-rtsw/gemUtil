[schematic2]
uniq 5
[tools]
[detail]
w -304 851 100 0 n#1 inhier.TIMEOUT.P -240 792 -160 792 -160 768 0 768 egenSubA.$(src):Hb2Health.A
w -112 67 100 0 SLNK inhier.SLNK.P -224 64 0 64 egenSubA.$(src):Hb2Health.SLNK
w -32 611 100 0 n#2 hwin.hwin#1.in -64 608 0 608 egenSubA.$(src):Hb2Health.INPF
w -120 739 100 0 HB inhier.HB.P -240 736 0 736 egenSubA.$(src):Hb2Health.INPB
w 1072 707 100 0 HMSG esirs.$(src):Health.OMSS 1056 704 1088 704 1088 608 1248 608 outhier.HMSG.p
w 1152 739 100 0 HLTH esirs.$(src):Health.VAL 1056 736 1248 736 outhier.HLTH.p
w 1072 771 100 0 FLNK esirs.$(src):Health.FLNK 1056 768 1088 768 1088 864 1248 864 outhier.FLNK.p
w 368 35 100 0 n#3 egenSubA.$(src):Hb2Health.FLNK 288 32 448 32 448 608 640 608 esirs.$(src):Health.SLNK
w 464 771 100 0 n#4 egenSubA.$(src):Hb2Health.VALA 288 768 640 768 esirs.$(src):Health.INP
[cell use]
use bb200tr -832 -440 -100 0 frame
xform 0 448 384
use inhier -240 23 100 0 SLNK
xform 0 -224 64
use inhier -298 732 100 0 HB
xform 0 -240 736
use outhier 1216 823 100 0 FLNK
xform 0 1232 864
use outhier 1216 567 100 0 HMSG
xform 0 1232 608
use outhier 1216 695 100 0 HLTH
xform 0 1232 736
use esirs 834 512 100 0 $(src):Health
xform 0 848 672
p 800 672 100 0 1 FTVL:LONG
p 716 814 100 0 1 SNAM:wsWebHealthSirSub
p 752 512 100 1024 0 name:
p 750 512 100 0 -1 PV:$(top)
use hwin -256 567 100 0 hwin#1
xform 0 -160 608
p -448 608 100 0 -1 val(in):$(top)debugLevel
use egenSubA 133 -34 100 0 $(src):Hb2Health
xform 0 144 400
p 96 768 100 0 1 FTA:LONG
p 96 736 100 0 1 FTB:LONG
p -223 -283 100 0 0 FTC:LONG
p 96 704 100 0 0 FTD:LONG
p -223 -347 100 0 0 FTE:LONG
p 96 704 100 0 1 FTF:LONG
p 96 672 100 0 1 FTVA:LONG
p 96 640 100 0 1 FTVB:LONG
p 96 608 100 0 1 FTVC:LONG
p 74 24 100 0 1 SCAN:Passive
p 51 828 100 0 1 SNAM:wsWebHeartbeatSub
p 112 -32 100 1024 0 name:
p 49 -34 100 0 -1 PV:$(top)
use inhier -350 785 100 0 TIMEOUT
xform 0 -240 792
[comments]
