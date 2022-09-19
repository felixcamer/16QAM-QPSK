*Model File name : nc7sb3157f
************************************************************************
* FAIRCHILD I/O SPICE DECK FOR nc7sb3157
************************************************************************
*
* Model Name: nc7sb3157
* Date Created/Updated :2/19/2001
* Revision Number: 1.0
* Created By: Graham Connolly
*
* Model Type: I/O Subcircuit
* Package models included: SC70_6 MICROPAK_6
* Process: fast
* Verified on Avanti Star-HSPICE Version 2001.4
********************************************************************************
* DISCLAIMER:
********************************************************************************
*
* Fairchild Semiconductor Corporation hereby grants the user of this
* SPICE model a non-exclusive, nontransferable license to use this
* SPICE model under the following terms.  Before using this
* SPICE model, the user should read this license.
*
* The user is granted this license only to use the SPICE model and is
* not granted rights to sell, loan, rent, lease or license the SPICE
* model in whole or in part, or in modified form to anyone other than
* user. User may modify the SPICE model to suit its specific
* applications but rights to derivative works and such modifications
* shall belong to Fairchild.
*
* This SPICE model is provided on an "AS IS" basis and Fairchild Semiconductor
* makes absolutely no warranty with respect to the information contained
* herein.  FAIRCHILD DISCLAIMS AND CUSTOMER WAIVES ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING WARRANTIES OF MERCHANTABILITY OR FITNESS
* FOR A PARTICULAR PURPOSE. The entire risk as to quality and performance
* is with the Customer.  ACCORDINGLY, IN NO EVENT SHALL THE COMPANY BE
* LIABLE FOR ANY DAMAGES, WHETHER IN CONTRACT OR TORT, INCLUDING ANY
* LOST PROFITS OR OTHER INCIDENTAL, CONSEQUENTIAL, EXEMPLARY, OR
* PUNITIVE DAMAGES ARISING OUT OF THE USE OR APPLICATION OF THE SPICE
* model provided in this package.  Further, Fairchild reserves the right
* to make changes without notice to any product herein to improve,
* reliability, function, or design.  Fairchild does not convey any license
* under patent rights or any other intellectual property rights,
* including those of third parties.
*
* Fairchild is not obligated to provide maintenance or support for
* the licensed SPICE model.
*
********************************************************************************
* SPECIAL NOTES:
********************************************************************************
*
*
* Beta HSPICE Model Disclaimer
*
* This HSPICE model is classified as a "Beta Model Only".  "Beta Models" have
* been verified for operation and functionality ONLY.  These models HAVE NOT
* been correlated to current processes or design characteristics.
* It is believed that these "Beta Models" were representative of the design
* and process at the time of their introduction though no level of accuracy
* is implied.
*
* All "Beta Models" are clearly marked "BETA MODEL ONLY".  "Beta Models" are
* used at your own risk and should be treated as an approximate representation
* of the silicon device.  There is no support available for "Beta Models".
* If you have questions or concern regarding this policy please contact your
* local sales representative, the Fairchild Semiconductor Technical Response
* Center (1-877-564-4263) or visit the Fairchild Semiconductor website at
* http://www.fairchildsemi.com
*
**                       All material contained herein is
*                  COPYRIGHT 2001 - Fairchild Semiconductor Corporation
*
*
*
********************************************************************************
*
* THIS MODEL MAY CONTAIN MODIFIED FUNCTIONALITY. IT MAY NOT REPRESENT TIMING
* CHARACTERISTICS OF THE nc7sb3157 OR ANY OTHER FAIRCHILD SEMICONDUCTOR DEVICE.
* IT IS REPRESENTATIVE OF THE BASIC INPUT, OUTPUT CHARACTERISTICS OF THE
* nc7sb3157 DEVICE.
*
* The terminals of this netlist are described as follows:
********************************************************************************
*
*
*	A0	=	Data Bus A
*	SEL	=	Select Pin
*	B0	=	Data Bus B0
*	B1	=	Data Bus B1
*	VCCEXT	=	Power Pin
*	GNDEXT	=	Ground Pin
*
*
*
* Spice Subcircuits for Package Pins
*
************************************************************************************
*
* These files are subcircuit spice models for the Fairchild Semiconductor
* logic devices. They are intended for use as package models
* which will accurately represent the characteristics of the
* indicated package pins.
*
* These model files can be used independently from temperature.
*
* The terminals of these subcircuits are labelled as follows:
*       EXT         node    1
*       I           node    3
*       GNDI        node    GND
*
* SPECIAL NOTES:
*   1. The EXT node is the node which is used to connect external loads
*      to the package.  The INT node is the node which is used to connect
*      input or output subcircuits to the package elements.  In other
*      words, this is the bond pad node.
*   2. The GNDI node is a ground node which is internal to a package.  All
*      subcircuits which represent internal circuits in a package should
*      have their GNDI nodes connected together.  The GNDI node should NOT
*      be connected to a ground reference node which is used with
*      external voltage generators.
*   3. The inductors which are labelled as L$2 represent average bond
*      wire inductances.  They are not part of the inductance matrix for
*      the package lead fingers.
*
***********************************************************************************
* PACKAGES
*
***********************************************************************
*   SC70_6 PACKAGE - CORNER PIN
***********************************************************************
.SUBCKT SC70_6CRNR 1 3 GND
R$1 1 2 0.032
R$2 2 3 10000000
L$1 2 4 0.614NH
L$2 4 3 0.5NH
C$1 3 GND 0.13PF
.ENDS
*
***********************************************************************
*   SC70_6 PACKAGE - CENTER PIN
***********************************************************************
.SUBCKT SC70_6MID 1 3 GND
R$1 1 2 0.0295
R$2 2 3 10000000
L$1 2 4 0.552NH
L$2 4 3 0.5NH
C$1 3 GND 0.13PF
.ENDS
************************************************************************
*   micropak PACKAGE - CORNER PIN
***********************************************************************
.SUBCKT microCRNR 1 3 GND
R$1 1 2 0.049
R$2 2 3 10000000
L$1 2 4 0.32NH
L$2 4 3 0.45NH
C$1 3 GND 0.17PF
.ENDS
*
***********************************************************************
*   micropak PACKAGE - CENTER PIN
***********************************************************************
.SUBCKT microMID 1 3 GND
R$1 1 2 0.049
R$2 2 3 10000000
L$1 2 4 0.41NH
L$2 4 3 0.19NH
C$1 3 GND 0.07PF
.ENDS
*
***********************************************************************
* END OF PACKAGES
***********************************************************************
*
***********************************************************************
* TEST FORCING FUNCTIONS
* (Uncomment the following to test including .END)
***********************************************************************
*
*VPWR0 VCCEXT GNDEXT 5
*VDATA0 A0 GNDEXT PULSE 0.0 5.0  5E-9 2.0E-9 2.0E-9 47.5E-9 100E-9
*VENB0 SEL GNDEXT PULSE 0.0 5.0  15E-9 2.0E-9 2.0E-9 47.5E-9 100E-9
*VGND0 GNDEXT 0  DC  0
*
*********************************************************************
* LOAD
*********************************************************************
*R0 B0 GNDEXT 500
*C0 B0 GNDEXT 50p
*R1 B1 GNDEXT 500
*C1 B1 GNDEXT 50p
**********************************************************************
* OPTIONS
**********************************************************************
*
*.temp = -40
*.OPTION  INGOLD=2 ARTIST=2 PSF=2 post=2
*+        PROBE=0
*+        GMINDC = 1.00000E-12
*+        GMIN   = 1.00000E-12
*+        method = gear LVLTIM = 2 chgtol = 1e-9
*.plot V(A0) V(SEL) V(B0) V(B1)
*.tran 1.0ns 200ns
*
*************************************************************************
* END OF TEST FORCING FUNCTIONS
*************************************************************************
*
***********************************************************************
* XDIE is the top call for the subckt for the die only (no package model)
* XPKG is the top call for the subckt for slice with package model
*
* Uncomment Top call desired
***********************************************************************
*
* XDIE  A0 SEL B0 B1 VCCEXT GNDEXT nc7sb3157f
*
*
*************************************************************************
* PACKAGE CALL
*************************************************************************
*
*XPKG  A0 SEL B0 B1 VCCEXT GNDEXT nc7sb3157fp6
.SUBCKT nc7sb3157fp6 A0 SEL B0 B1 VCCEXT GNDEXT
X0 A0 A0I GNDEXT SC70_6CRNR
X1 SEL SELI GNDEXT SC70_6CRNR
X2 B0 B0I GNDEXT SC70_6MID
X3 B1 B1I GNDEXT SC70_6MID
X4 VCCEXT VCCEXTI GNDEXT SC70_6CRNR
X5 GNDEXT GNDEXTI GNDEXT SC70_6CRNR
X6 A0I SELI B0I B1I VCCEXTI GNDEXTI nc7sb3157f
.ENDS nc7sb3157fp6
*
*
*************************************************************************
* PACKAGE CALL
*************************************************************************
*
*XPKG  A0 SEL B0 B1 VCCEXT GNDEXT nc7sb3157fl6
.SUBCKT nc7sb3157fl6 A0 SEL B0 B1 VCCEXT GNDEXT
X0 A0 A0I GNDEXT MICROCRNR
X1 SEL SELI GNDEXT MICROCRNR
X2 B0 B0I GNDEXT MICROMID
X3 B1 B1I GNDEXT MICROMID
X4 VCCEXT VCCEXTI GNDEXT MICROCRNR
X5 GNDEXT GNDEXTI GNDEXT MICROCRNR
X6 A0I SELI B0I B1I VCCEXTI GNDEXTI nc7sb3157f
.ENDS nc7sb3157fl6
*
*************************************************************************
*
.SUBCKT nc7sb3157f  A0 SEL B0 B1 VCCEXT GNDEXT
X1 A0 B0 B1 SEL GNDEXT VCCEXT SB3157
.ENDS nc7sb3157f
*
.prot FREELIB
Hb4/[GsW<-uh0I#$:-12X=#K9rXI,8\W2d6IL
)C3:=2';7< (92Z77*m;=xi,8*w[-MgxR:sz[z
Fh$#TIy[H$.x5292uv6*m;N[ .o-q
;[XI,8\W2d6z77-Q
7WH2Xx#tiY[h$.X5292UV6c qnu0
'4]W[[XI,8\p:]c367<KoC8z.O;Q
7WV2g7*M;= 26U't:*0 .4\SZUZ
Fhi#k9Rxi,8\P:]C367<kOc8Z.o;q
7W/2/0%W+*7E$.X5+9$4:.##+-4\.Skv<CgSL
)Cu:5x/p7< (9$4:##TIy$2/R0PY
38H$1#F392Z77*m;=xi,8*w<03Hl
!z![k,'$0z;Q]C3A#dsz'xi,8\w2D6il
)'P:=2'5H#TIy[26u' :R0mx=8
o;'xZt%-i:]C387*m;=xL/R0PY
k 26u'T:]C3873)*[%2>_3x(6
mz77*M;]XzT%-I:]c387*M;=XoWy3 O9i*o>++(/1:PxJ)*/*2,_aIHU*E5>J+(*\:)[
a$o):+Z>33P/uS;0.p(9=Uyt5xw/ v;$V49! :$.D($:BS)xJlm'1(=xVW2ba$)!uje/Vh5x<6(:Z
$88d($'bTSXU4W//(=X;w+y0*OB+JM/*+(Xv)*/U2>_3X(9p't\*((e10
Z9$f%47239$f39 257;Q
;[Xh$<#hc2/2JS3((E1:0jyh:x>jy=+p#I25P<8
5C9v2575u):x'[=Q+h/1+S>5w k%*7!3,p*\:0[
Dp:UX+$Y3Q
HO. T,#;39P2h9QPh[vet33J:y0*p7\(3e1:0[
a2 )1-P>\K:k#DYJUX3u_\$+l((eUV9<#9-/B)7bRQ
$92!Y=+P39e'H_;xwSJ2 sQ+hix/<_33H:Z
$$40Y-/BhL
!< OBxL/R0PY
e2Zv9#)<%di,82 OcGJl
!z![k,'$0z;Qw[gAJ##+9$4:##TIy$0
[b##+9$4:##P9! J$\QPh/z
a77C :]C3873)*[%2>_3x(6
e377\) [/26U' :]c387%KR- 0
>#3W!=XzT%3I:]c387*M;=XoWy3 O9i*o>++(/1:PxJ)*/*2,_a3HUuE5>J+(*\:)[
a$o):SZh;p#2*S;0.p(9=UytRx3/Fj)xV49! :$.D($UBSPxJlm'1(=xVW2ba$s!5h(/Vh5x<6(:Z
$88d($ub+*=],(i/(=X;w+y0*OJ+4E[fep<v)*/U2>_3X(9p't\*((e10
>#-W!=XzT%3I:]c367*M;=XoWy- :ra$*!J+(/1:Px<6($X4yt;xmUFj*xJ+9!1SL
T[;-8/-)J3,)$/et33+:50*O<+P((%spHr)*[126yQ_Me/:pXY3C/25pH#T<):)z$5+(i Jp0.+>6
:z:Yq_mEVv7E]+P:25Pj# ;ba$s!Rl3(F:0h<6(UXOy=++:%7(>.q+H/Z
av=# 9X s$4\wwI257<#9-[B:L
!z![k,'$,z![[xH$b#3Y
y 277rwM/%J$%GP-/b:p<;J:X>JY=+P#[25p<8
5C9v257;+C'x'[=Q+h/1+Si#2%'AHz=]P9!1+l
y3wM9v2v=8
XUmp(37Dp:%x7/_5x([J(==yW;ba:$#qpH/1+L
TS2-/b:*#zw%..*5b+pcj_2<*q+HUHh*7K((eUH5<8
_:*g*7!3p:377YJ+JE2x\[_JxP93PY=;X>6
:2h-9((e 0
Z0\;<9iU\-3Q
H*[ /7<KoC8z.O;Q
Hb4/[GsW[-mGXr:SZ[X(860W!=7GT#JW!=7GT#3W2d6z$.X526
e79=# 9xJ+$#<23$XI,8\W2d6I$4\YqM$'.=8
o!$/2h#Ss9= 280Su#9$4:##TIy$2h#9s0]7g7[
4#w[XzT%-h:=2')=#tiY[26U't:W[p.M*2q'Z
Fh$rw+*7H(7\) :*26u' :]C367C 6c.ij6-q
7W*:$#<2m:XzT%-h:]c387*M;]X78+/v2xDhL
)C4p92Z.-# 9X%s$.x5+9$4:.##+\dD6%/3Y
38T57\) 2f280S4>9$4:##TIy$2h#9s0]7g)[
4#w$X78%/)+/XzT%]I:]c387*M;]X78+/v2xDhL
)CHE9[(j<;w+*7V77*m;=xi,8*w!=-gW.Ss>6
e79E# 9xHh$#<2)IXI,8\W2d6I$4\YqM$'.h8
o!$U280S4>9[(jJvw2D6Z$.x5298Z<6tT c/0
'4u4:=2'5E# 9xJE$.X5+9$4:.##+\Dd6%/py
38T97\) (/280S4M9$4:##TIy$2h#9s0]7g7[
4#P2XzT%Vj:=2'5h##+xD(8=#tiY[26U't:==zVb/v2xD+L
)C4M92Z.-# 9X/H$4\2Q*[:$.x5+9$4:.# '=pJ.m*2Qiz
-/R0/.XxZG#duQm$'.<#$:-x#$.x5+9$4:.8
9#9O2G7*m;]xi,8*wuMPh61#=-8h-pXj+(/1:t3jJ:DA$(!U,C/1:pX<6(iz
$GyQ_3e1+9<3+(/257X#$<):HzXrHp[1:p0.P(9$ YTYX)[UepXj+9!1+$.z($sby7J]+(/1(=Xrq
$=6 yt3x>[1S5bJ49!1j$#'K-8 -)=JIc'1+T3JU:OahZx#; *mIyx++y
oh2E70w2D6i$.x529mdV=*$:RA$*!j+(/1:pX<6($x4YTUXW(%:pXj+9!1+l
T[;-8 -p<543/1:t33+:50*O=++p2vHpXj)*[126yQ_EejHSej+(/25p<#T<):Vz$33#/1:p0.+p6
:z:Yq_3E/hPh-U(I25Pb# ;ba$7!Vp(:%jP<<6('XOy=++:%7(>.q+H/Z
o(7\) [U2x7*m;=xi,8\wuMPh81#=-8h-pXj+(/1:t3jJ:DA$)!Ui(s1:pX<6(iz
$GyQ_Wev)S<-uEs257=#$<):Tz<;3p'%V*0.P39$ YTrX>$1H0Bj+9!1+$.z($ibs(X34C/1(=Xrq
$=6 yt-xPUJY0x-49!1j$#'K-8%-0j5hP/%+T3JU:OahZx#; *mIyx++y
oj2E7[w+*7HS7*m;=xOwY3 '9I*O>++(/1:pXj)*/*2,_Aih$/:*Xj+(*\:0[
a$o):tZ<;3P'%v*0.p39=UytuxPUu+5byl9! h$.D($IBS(x34c/1(=xRW2ba$0!Vj([VjPx<6(IZ
$88d($'b+S$54('v(=X-w+y0*OB+4M2j+pBr)*/%2>_3X(9p't\*((e10
Z\T;9rXOwY3 '9[Ow9#=9\2lyh]W Y2\ybRWUm3oWyQ3:\23/4t -ubHl
T#/']mdV_-W+M8OwYqp:=NU>MD((97d'_3xP(25P>8
_:R8Zj_3XCs/(=XUwIw['Y=+iE*\:(7DM%) -s0.+w9pL[_3X3uf(=XUq
$3#*5!R)*/*28SH(3EV(o=uW+N='t_jwR/aY5h+ly
84;Y=+PM[25pe#![)j-9J])*[f2\sQ+h/U+$+S*()1-9BjPY
8,HYX+,3/h2mbq6eEFS*xJ+(/25Pb#\M) )z=;q
$4u/y3Rxm'J:PxJ+981:$UJ(mE1E(0.+w9[l'_3)*/F2v+S+-[bV0<8
_:%-'7_Jx#IHY$y92C)\yzi3u(/1:p0.+39pPjXx((e HS[
a;6x 4yh++3S2$Ph#;6X%4Y33X(/1:pXj+981:$0S$()v(=Xrq
$*7;X_.pH21:PxJ+(*\:77DKR-a:Z$u4:\0;J_yx)*::)7[+-/Bj*[
aW[/avZb])*[/2x=QPh2/+t3j4:5GuYX8
_.*7;Y3;X#'%:pXj+9!1J$13((9=jy=8
_ODG*=i+L#$1:pXj)*/f2vu0(Mef:S0.+#96 /Uqj>/Z
$68xD-!/-7$5+(/1:t3ju:]64X_Jx(UFSs7X5-/BE)jyW;B;*(X8
_:\.\ _.,H:%hPxJ+(*\:57\['k7D:_jX)uvT$sdk%)12[yz/O)10
o7G;<k3**0.+p9>7J_yx3S25P<#t%rm*P!V4y
8$ h-%/3)1-p=5,:]p7x,Gu-/b:pXvL:]P7X,gf-[25P<#;;m4'YX+P(:z
$69GF9[AHz<r)$/h269gf9'ahZI<6($XI<12((E1j$y<= 5A:zX;4Y
8=L6/[+-[by;B<6(ix/t%[+-uh-5J#8<) -(E-)*/*28*qpH/HvL
TG8-/b:pXvPW[xaf9x(>e )90.P(9$/YX+HM:v26-ZM-[Z
$>*Q+hi T97k8<da:Zb#/Zb.*s!5)*[ 2[ODv-UBYT33py
8>!xmQP9! :$s2;f)%-S<<63/xAa9%(cEu+T33+:k,;6.[((ejV(<8
_%R2*p!Y4:kIaYi<6($xf61'2-/Xa _jq
$07(y33x3[1:PxJ+981:$gSP-!U-)Hj+(/1:t3jP:47H3_vXp:f(=X]q
$47jy3;xc'V:PxJ+9!1j$r[p-2Bj*b<6((Xmx=Q63e +pXj+(/257i8
_rk *=i+L#i1:pXj)*/%2G%Quh[f(OXvw2Y7*;xJW%X=*p!j+3ujVl
T#t 5a:ZxJ+e(1S$sST-[bs*><6(sxIJ.q+H/ 2J,<Y%) 0
o742!)12GDQP:4_*(0.uE92\YX+,p6
:(3\q4:DI*p7x=+) 2,Uq6PEFt(xJ+(/255$8
_:dczyj#=f)123,\(39i4yx8
_fD[*77%!()uhZEyWI01*p7%!')10
oU$$-/XL\-Q+:d4/yx#=rkA:zX3i)$z
$,RG((9i;P_Jx(/ Y(<#M'/a:$,[D<)10
oU[d<)1238DKi)%:P7x5OBC*p7%! *a:L
Tx! *A:$,W23)12,gSP-/z
->md)f9MDv=*$:]MD/7%)6*I*)e#2;*_*5<#90-mdV_;W6*6UHM\(mE 0
o7G$2o. YB# 0wMDv_3w+>0oWyQ+:X.FY=+4#*\:*[
aWFW['yb+49!1v$Uc  )%-90.+w9P4[_3xm*\:([
a;FKa55!J+(/1:Px<6(SXfF_-)*/*28SH(3*:h(7\D'X2*p[
aWr/A)0=+3:0=*9!Y3>*\:;7$F-!U-p>-+(/1:t33LY
84aY33XW2f:pXj+9!1J$+s*()\vZh5+(/1:P0.+39,HYX+3E/U0
oG-((E1)0hyW.Ua55!5I)/1:Px<_(/X]S-Q6Eeh+*Xj+(/2$pX8
_I/A)zJUL9!1y$#%o-[25pe#;6x1*P!RWo\7hyx+Uw/ 0
oY92c)\SZ<J+(/1:P0.+39PpJxX(*'B)PxJ+(/1(oxJWo\7h,_V)$/V0
oY92cda:Zx-W9x=:yx+p:*7;X_.4HI1:PxJ+(*\:57dkr-A:z<rq
$9-uG%QPh'2$p<#$()%2xXQ39!1T$-3((6
:2gOZ((E%+$G<2')12g=q+:5%*7[
a;ina:$yxF-/x3V9X(mU1:$.'mz)\)zXj+(/1:p0.+C6
:268Xf-/Bh57x5-[x3//QP>iz
$<m:[-!f-0=;+(/1:t3ju:=_;[%T5-/B+$sdk%)12[yz/O) (=Xrq
$9> /s0(C*\:07g# )\hZxJ+(/1:P0.+>9$a3\Q3hiz
$6yCFfk *p!jip2 26YcfFK%*P!J+c2HY$.D#[r>/yx+U:%6D\%Q+h'1Jl
T*k%-2HY=<_($xi/s0)C) (==jw2\=!YX+P:%2Lj1Q+h/j0
o1%ta51**0.+#93(J1J(cSX</_uxm(u(=xuW+.ahL
TG8-/b:pXr,>2xaf9x(Me1+00.P(9$/YX+,(sf26-ZM-/B+)h;Q
$O#*P!VjP2Xof9x((e%2[ozV-[bJSH<63/xaAyt(3e%))0.P(6
:Aa-T(w*\h77gdoratZ=],9! h$S2KF)*-7E])*[ 2[G[t25a:Z$8
_%R2*p!5w%r>*70.+w9EiG8S((94'T_.pHS1:PxJ+(*::P[
aW.X *=<++(/1:pXj)*/ 2M%3=-[25p>#\ 'A57!j+(/1:pX<6('z
$$R[P-!%-0$;+(/1:t3j,:03HY3rX3/1:pXj+9! V$RGP-!*-pXj+(/1:t3jiY
8x;j_.Ph2%:pXj+(*::07*5 ) :pX#/ 5A:zXjP(( 0
o.s$-/B:P=5,39>'6_JW2X$*p7s=9\>*7[
aO WahZ<#$t) 2MDQ+:*_*7[
a)FOa+$u%((9CL8_3wida57!yU(/1:Px<63SZ
$$ux -[bV$,%((9il8_3WfDA:l
T%m+) 23rJ(c/X4\xq+:R4;YX8
_I0=*p7%![)12,R0((9i;P_JQ
$d=:yx#='N0*p7x$zBA:z=#=;%04YX8
_Iypu,_.uh/1:pXj+(*::S7%! *a:$U$29)123Gsp-/Z
$$uW23)10
Z0\;<9[;8Y-S0]7G0[
+KR->]J7c 6C.IJ63W!=Xd\%#tiY[26U'ty
o +$m$2:w[26u' :]C387kvo[[;$,Q_Ee1:pXj+(/25pi#m-8/-pXj+(/1:t3jHY
8= YTUX#'h:)=5+9! J$1z($$be5>ji321(==-w2%A$9!j,#:/:pX<6(2xi/_AHh/fe)Hj+(*\:9[
a ;%a$s!-U):%h*E<6([Xz:9q_mE%j9h-pe(25P=#9-[B:$Ys)u]a:Zx8
93:xD\%##+9$4:.#TIy$2>MDp25XLYTYX(/1:pXj+9!1T$uQ_Ee1:pXj+(/25p$8
_'%A$7!v3#(1:pX<63[x;/_APh:Ue;Xj+(*\H77*;-8 -p>U,(/1:t3j4:]0*O=++E$f:pXj)*/v0
o#';-8 -)<]I>$/jT3Jp:=6Uyt3x>IFS)IVU9!1h$\qpH/X J0kt-/B:L
!KVO*I2>mdP25xi>mzwf*-(3_v,:X6( _-4:O./>MD(m9-(:9cv+)u-7[
aW%5$oWyQu:=.7>md(39[N/\t;-/x'W)QPhif(=XYq
$9i78%qUHI25P>#M!=7*5!5)*/*2VUg(3Eu(=xuQ
$%iAy3-x(/1:PxJ+9!1v$)L(c*\:(7\/a) (o=uW+N='t_jq
$94:YJrPhuxmG_5XEu/(=X]wr-A5S!jLC/1:pX<63sz
$\sQ63e*y;Xj+(/25pB#Y f1*=>+I)/1:PxJ)*/ 2M=Q+huh:S[
a\c)1-PjRIe9,)y3-x):J:PxJ+981:$g;F-!h-*<Y+(/1:tTj+Y
8C:YJ+3Ws25p$# f3AHt3j,:%-'P_JxP9PpJ=q+H'*:7[
a;6x%*=h+4(/1:PxJ)*/ 2V+s+i)\jZjJ+(/1:P0a+(9PpJ=X(>*::0[
a;6x%4yx++c92'gxq+H[X(J10(*IB+PxJ+(/1(=x-WOB4/YX+4p6
:2<9[2-[bJtTj4:51*570+-u25pi#F3)10
o7[d<)1-5<#\9x=*P7[p-/X;5_3Q
$%c!yx#;I-A:$8DKi)u)Px#T;DG*=J++(/1:pXj)*/%0
o7*5i-a:Z=-WIyAH$8z*-[/+l
T9VtJA5;!rPM/1:pX<6('xz 1g20Ya:Z<#/OB>*p7G;<kp*70.+p6
:2[yz/[)%(=Xrw%W7*==++(/1:PxJ)*//26s%9-ub+l
T*;!-Ia7_jX(:vy77*;!-iA5_Jx(/%Y*$#toW3l[-q+H'X :m$2-/bJpB8
_2B>/t=QP981T$.z/[*%*70.P(9$PGoQ+h[x t,S$-/b:9[
a$F];;P_y)*/F2X0s$()%v$*Z(wEuEs0.+w9[<y=8
_%.A:zXj+p(/y$slkI)U-p<r)*[126-Q+h(1V;7*f<da:Z<VIm6
:OF_Jx>$VY$\lkI)1-57GD<mAHzB;i9! :$s2;0) -5Jv)*[10
oS2f0)*(==3W%nPlyI+p#(257=#/Zbi*(!3,#*\h77g\']$;yx+hy
8>Lt_jX)9>l[_3)*/*2'.[5 )12\%<(*[BvPxJ+(/1(oxJQ
$9,'7_.4h/1:pXj+(*\:77W23RAHt3jL:47JY33X(/1:pXj+9!1Jl
T#!'[A55!rHM/1:pX<6((xmx=Q6pe :pXj+(/257>#!%[A5(!j+(/1:pX<6(:z
$$1S(*[by5Xj+(/1(OXrw2y7*7Xj+:k7;YX++([1e7[
at 5a:ZxJp)( 2[%*((9$'6_jw r2p[_3Q
$377y=+4:5_*77W[-/x( _3q
$*iOy<#mf)12,,\(39c4y33xe'1:PxJ+9! vL
T#mI=AHz>#=F)123,\(39I4YX8
_fD[*77%!()%:$U$+-/XL\1Q+Y
8CmG_jwF03*P7x![)1231J((6
:4gxq+:R=!/_jwI5GuYX+P:R6 /uQ+Y
8C3v9x(*'b:pXj+(/1(OX;wF07(yx#MRx2*P7%\ [a:L
T#m.X *p[
+90%2l$\T;3==28\TK:r2pT,qI#973TdqUP9MDx\t;-uxPt8z#0=A)z=8
_:K=I>MD(c9[dH\T;-[Xz_9kvo)12JM4(3EVET3Jly
8xLh#S(3e%V)0.+W9C78%QPh:h(=XUwod>*7!;)*/*2v,G(3e );0.+W6
:fF_-xP*\:(7\/a) -00apw9[!G%<((94:y$-IHSZ
$\1QPh[UHt3j,:03*9!53#*\H;7$/-/b:S<#y F1*p!5u([z
$M=Q+h( :*7wU-!H-;hy+(/1:T3JU:4U*7J+PM6
:]s-q6PEuj9xJ+(/2$Px#M()u-PEu)*/*28,4(3*\:;7dy /AHz>r4Y
8x <%3((EF+*$#;6X%*=$+J3'1:pXj)*/ 2v+S+I)1-7=;q
$%-'7UqIH/ vTtJI:%-'5uQ63e1:pXj+(/2$pX#) 51*00.+p6
:(J10(*[BYPxJ+(/1(=x3Wob4/yx+hwIXp/1s(eEJ(oxVW'/a:ZbyQ
$93:y>+U#*\h)70P-[by)<<6(ix;A9Q+Y
8,(j1Q6MefJ5Xj+(/25pB#$3)12gbqpy
8p4A_.JhsfTpXj+(*\:;7dm[)U-;X;)*/f2:YZM-$/:L
T*5INA5)!3H)/1:pX<6('xI:U0((E1);h;WiYa:ZEV3e96ud_U+Y
8xpwd:(*(BS5=J+(/1(=x-W+J=ajm'((ej)0i#/OB>*p7G;<kp*p[
aW%%0ax_Y)*/v2[4s(eE vT3J4:]>l>_Jx>IZ
$6yCFfk *p!jP)(xiv40=%'A:zXj+>sxIV40=%-ahT3J4:%6D\%Q+h[1sl
T*k%-2HY=+4p*::*7*K%-2jy=+j9!1t$.9$Z)1-Pb#;9R7;YX++Miz
$G,**'/AHz$]u9!1+$-<2'/A)*!-3:.0*7!u,c*\:(7\8-[B:*>8
_%.A:zXj+>[*H$slkI)/-7J5)*[126-Q+h2Us07*f<dahL
TK8-/b+7i5wu.04yx+U:KgUw_;x)*\h77gdoMa)Z$<63[Z
$[o0V-[257X#/z%I*5!;49! :$S2KF)%-s<<63/XaM1*T')1-9>U4Y
8>Lt_jXEixa3sQJ9!1T$)*$;xa:$s:((6
:MJ0q63E hPxJ+(/2$Px#\ [A5S!vi(/1:pX<6([x]j=%(>evs;0.+#6
:]Jbq6mE%j0xJ+(/25Pb#!'[aYZbyU9!1E$R0P-! -7<j+(/1:t33JY
84a7_.Jhsf+pXj+(*\:57[2-'bH;0A+>9$3J_]+(9>'G_jX(/ )9>8
_:]7;yx++(/HEPh#/ ]AHzHYL9!1V$.st-/B:77s=9\>*7[
aW7x8*P7[[-[x] _U)*'h2tDQ+h(v0
o0%9-IX43_jwIR[*77XM-!V-;Iu+(/1:T3-hy
8x4,#q3:RI*p7%=+) 23Uq+y
8I48_3wF01*s=+,e9Cmp_jwF0=*P[
aMR5a:$,$F-/x4\-q+:R4aYX++3:jTl
Tx!%)1231J((E1:7$u4:d=:yx#='N0*p[
aM'n0*P7%5obc*5xJWIypu,_jwF07(yx8
_I07(YX#=.X *p7x\ [A:l
!< OBx78+/V2XdHl
!z![k,'$4\yQm$'.B##+9.mj7*m;=xi,8*q
u[V2wrsW!=XI,8\W2d6z$\t;3==23_alH/1:PxJ+(*\:(7X($SB:PxJ+(/1(=x5Q
$5P*o=+h>SFY)=5)*[ 2g9q_3EJS*E5I32257=#to):hZ=-,#:/:P0.+P9$Uyt3x3'FE)hJ+9!1+L
T\5O):Hz<rPC'hVp0.+39[3/_APhivH5BYL(*\:77K(3e12v%<92)1-p[
kp>9.MJ7c :]c367*M;]XoWy3T'9i*o>++(/1:PxJ)*/*2,_aUH:1:PxJ+(*\:0[
a$o):SZ<3,#/1:P0.p39=UytVxP[FEPxJ+9! h$.D($UBh9I]+(/1(=xRW2ba$s!3hw(1:Px<6(IZ
$88d($:by)e;i)(j(=X-w+y0*OH+H>(Us9e5)*/%2>_3X(9p't\*((e10
Z\T;9rXOwY3t'9$Ow9#=9\2lyh]W Y2\ybRWUm3oWyQ3:\23/4t -ubHl
T#/']mdV_-W+M8OwYqp:=NU>MD((97d'_3xP(25P>8
_:R8Zj_-Xp*\:*7x#+XAJz$<6($x ,sQPhu25pi8
_OR>*=B++(/1:pXj)*/h2'*Qu9!1T$#G*-[2$7i# Z57(yx8
_:01*s<3xm94;y$+lm:25PE#![)\)ZxyU(/1:P0.pe6
:M[_.pH$JEPxJ+(*\:5792A/A5*!vH(/1:pX<6([x]7_JxmS1)L
TWu-/b:S<vL:4U*=B+H>21:pXj)$/12mj0(*SBv0>J+(/1(oxJQ
$d1*s!;je*\:97\=7) (=x]WO\7:YX+4:%-'7_jXC$1Hl
Tdy 'A5)!r+(/1:pX<6([x <%jm-!%-SXj+(/1:tTj+:%-'7uQi981+l
Tdy 'C*p!ju:*7;p_jX392'G-Q6pev:pXj+(/25pB#;<03*P!R4y
8xp/1s(3E%(oxRW'/aj$-J(m*\:(70p-/Z
$$12k-/bJ07W) 5A:$13((9=JY=8
_ODG*p7DM[)12:yzm-uU:p7*5ina5s!J+(/1:Px<6('Z
$$.'m[)1-7B#M;) 2:9H(3:V0
o+T[T)\EZ<33(/1:P0.+c9[\GsSV;)1-07g;<Ka:$SDK%%ahT3J4y
8xAV9gf-'25P<#/!XA57!j+(/1:pX<6(:xI[,k(mEV0
o.D#[r>hyx++>IJh$.d#[R>JYX++('jV97*;!-Iax_jXC9P3wrs((E%:5[
at<K3(7_3)$/*269gf9'ahT33+:]-;a_Jx39P(3%[((E1YL
T[=2F=:Y><6((x/t%[+-'h2f9QJhuf)t3jJ:=#*7[
a/,)1-PxJ4#:J2[*ZM-UB:0<<63/XIX_Jx#/HE$.0kI)1-0Hv3Y
8M<YX+iWij2>*ZM-/Bj$S2K0) -5jV)*[12[ODv-[Bjsh<63/Z
$[o0V-$257=#/z%I*(!3,#*\H77GD<RATz=],9! H$sW$2]=*p!5q
$Ki(yx+h:kIaY=<6($xf61'2-/Xmj0Q63eh:pXj+(/2$pX8
_:47hy3Rx(/1:PxJ+9!1h$GspF) (=xyW.x%*==++(/1:PxJ)*/%0
o7$$3)\jZ<53(/1:P0.+#94/7_.4H[1:PxJ+(*\h*7$/3)\tZxJ+(/1:P0.+>6
:2g%q63EJjPxJ+(/2$P<#t;xahPxJW%x=*P!J+3/FhL
T*2')1-pX3H#[xaj.Q+:]7Iyx#2f*-aY=8
_7X8*7!rw'jah$G:((92\y=8
_9RM*07X=-/X43#qp:DC*==+LC/1:pXj)*[h0
o7XM+) -*7%=-/xL3#QP:rc*P[
a=i=ah$,$+-'12,Rj((9iMg_JQ
$d4;yx#=r-A:$U$f-/XLGXQ+Y
8C;p_jwF5gUyx#M'n0*P!3WFYPU,_JQ
$d6 /Uq6cE1:PxJ+(/2$Pj#=rX2*p7x! *A:$,W23)10
o7X\ [a:L
!KVO*I2>mdP+5xZ>mzwf*-(3_v,:X6( _-4:O./>MD(m9-(:9cv+)u-7[
aW%5$oWyQu:=.7>md(39[N/\t;-/x'W)QPhif(=XYq
$9i78%qpH'HST3Jj:d8zJ_3x>S25PI#;IkAHzJ<6($x 3SqpH[uET3Jjy
8E<YB+49!1T$#G*-[b+tT3J:=g;J0q+:01*9BvXE6
:Mg_3x3U (=x]WR-aYZ$;,9! E$rg((E1)0792a/a:Z$-+36
:]7_Jx#[1v$g-(*sbe)>j+(/1(=X-w.Uahs!33y
8,)x_.4hu%ypXj+(*::p7x+-ub:;i<6($xZ3)QP9!1e$Y92() -*<RQ
$9pPj=Q+h(vV97DY 'a59!upc/1:Px<6([X <%JM-/Bh7j8
_O\7H,_vX([h(OXvwo\7j,_.pH/1:PxJ+(*::P7<2'/a+T3J4y
82'G-Q63ej:pXj+(/25p=#;<03*p!5Jp9-uG%QLh22$pH#$()1-5>8
_:-1**!-,9! s$-3(3EJS00.+P9=!/_JQ
$42'g_.3H(%jPxJ+(*\:57[P-/x;5_3q
$%c!y3uxe(*:PxJ+9!1E$YXf-UBEPj<6((X3v9x(W:10
o.'MZ)\SZ=5h(/1:P0.+c9$3,-Q+h/Ue)J#m;)1-;H;L:Y0>yIJQ
$9-D DQ6#e/J7Xj+(/25pB# T5>'w8q+H2u+(7g;<Ka:$SDK%%a:L
T#/ob>/y><6(IXah%QLh[h(=Xrw2kIoYX+ip6
:IV40=%[a:Zx3h#9$ H-%/c)1-PxJIe9$ h-%/[) (=XrwoY.MJ_Jx3//0
o.Z/[* *7!R4981v$.z/[*%*7!U)*/*26+[D-/b:57D)Fx=*P!J3P6
:;3.H$() -9E-)*/V2X0s$()uvZb;W,BAHzi]u9!1T$#l(3e1V*[
a/,)1-PxJI3$ 2[*ZM-:Bhs$<63/XIX_Jx)U/+$.0kI) 0
o\L((EVh($#9,BC*p!-w%N0DYJ+H9! H$s2;0)U-90.P36
:Aa-T(3*\hP7gdorajZjR)*[12[oz=-'b)00.P(9>]g.*$-/BY*IRQ
$Ki(yx+lP9>l[_u)*/*2'.[5 )12[dq+y
84't_.Ph[ :pXj+(*::p7w23)\)ZhV+(/1:P0.+39,'7,qIHI/ET3J,y
8,'5_.3h'%+pXj+(*\:57$$3)j-5>-)*/f2\-3(*[Bh0xJ+(/1(==uQ
$0>hy3uxe(V:PxJ+9!1j$1s(cE ETtJI:]6'Yej+:K7;yx++([uY*[
aW2X=*p!j+(sf:)7g22) -)>y)*/H26%*((e1H$%%)6kAHl
T#o wA:$1:(39,\yI<6cSX( _Jx#IZ
$t,K(p9clyx#MF=ah$ux(*ibe(ij+(/1(=B5q
$9C48_;wFra:$,% -[XL,_jq
$rczy=#=r/A)7!]L:d4:yx#=r5A:l
Tx!')123r0((9Cmx_jwF0>*P!Jp>2*0
oU$/-/XLGXQ+h/1H9irwI51*p7%$Zba:L
Tx$zBA:$,';<DAJpX#M;%04yx#=rX2*p[
aMRx2*P7%\ [a:$Uw23)10
Z0\;<98z<6Tt C%0
Z9$f%472H#9S0]7G)7c :M4'$.X5+9$4:.8
93ixD\%##+9$4:##TIy[2>MDp+5XLYT3X)/1:pXj+9!1y$uQ_>e1:pXj+(/25p$8
_'%A$(!]uE//H9X<63'x;/_AJh(%VpH3H(*\H57*;-8j-pe]i>/1:t3jH:]0*O$++#(/spXj)*/j0
o#';-8u-5b5Ic[HET3Jp:=6Uyt;xc'JS5=y,9!1h$\qpH/X J0kt-/B:L
\3i:m4'$4\w2D6i$.x529mdV=*$:RA$7!5+(/1:pX<6(2x4YTYX(/1:pXj+9!1yl
T[;-8 -)J],(/1:t33P:50*O=+iM(f:pXj)*[ 26yQ_3e1V(ej+(/25p<#T<):HzXYJ#/1:p0.+p6
:z:Yq_3E/+;hVj>'25P=# ;ba$7!V4#:/t)b<6([XOy=++:%7(>.q+H/Z
->md)f9MDv=*$:]MD/7%)6*I*)e#2;*_*5<#90-mdV_;W6*6UHM\(mE 0
o7G$2o. YB# 0wMDv_3w+>0oWyQ+:X.FY=+4#*\:*[
aWFW['yb+49!1v$Uc  )%-90.+w9P4[_3xm*\:([
a;FKa55!J+(/1:Px<6(SXfF_-)*/*28SH(3*:h(7\D'X2*p[
aWr/A)0=+3:0=*9!Y3>*\:;7$F-!U-p>-+(/1:t33LY
84aY33XW2f:pXj+9!1J$+s*()\vZh5+(/1:P0.+39,HYX+3E/U0
oG-((E1)0hyW.Ua55!5I)/1:Px<_(/X]S-Q6Eeh+*Xj+(/2$pX8
_I/A)zJUL9!1y$#%o-[25pe#;6x1*P!RWo\7hyx+Uw/ 0
oY92c)\SZ<J+(/1:P0.+39PpJxX(*'B)PxJ+(/1(oxJWo\7h,_V)$/V0
oY92cda:Zx-W9x=:yx+p:*7;X_.4HI1:PxJ+(*\:57dkr-A:z<rq
$9-uG%QPh'2$p<#$()%2xXQ39!1T$-3((6
:2gOZ((E%+$G<2')12g=q+:5%*7[
a;ina:$yxF-/x3V9X(mU1:$.'mz)\)zXj+(/1:p0.+C6
:268Xf-/Bh57x5-[x3//QP>iz
$<m:[-!f-0=;+(/1:t3ju:=_;[%T5-/B+$sdk%)12[yz/O) (=Xrq
$9> /s0(C*\:07g# )\hZxJ+(/1:P0.+>9$a3\Q3hiz
$6yCFfk *p!jip2 26YcfFK%*P!J+c2HY$.D#[r>/yx+U:%6D\%Q+h'1Jl
T*k%-2HY=<_($xi/s0)C) (==jw2\=!YX+P:%2Lj1Q+h/j0
o1%ta51**0.+#93(J1J(cSX</_uxm(u(=xuW+.ahL
TG8-/b:pXr,>2xaf9x(Me1+00.P(9$/YX+,(sf26-ZM-/B+)h;Q
$O#*P!VjP2Xof9x((e%2[ozV-[bJSH<63/xaAyt(3e%))0.P(6
:Aa-T(w*\h77gdoratZ=],9! h$S2KF)*-7E])*[ 2[G[t25a:Z$8
_%R2*p!5w%r>*70.+w9EiG8S((94'T_.pHS1:PxJ+(*::P[
aW.X *=<++(/1:pXj)*/ 2M%3=-[25p>#\ 'A57!j+(/1:pX<6('z
$$R[P-!%-0$;+(/1:t3j,:03HY3rX3/1:pXj+9! V$RGP-!*-pXj+(/1:t3jiY
8x;j_.Ph2%:pXj+(*::07*5 ) :pX#/ 5A:zXjP(( 0
o.s$-/B:P=5,39>'6_JW2X$*p7s=9\>*7[
aO WahZ<#$t) 2MDQ+:*_*7[
a)FOa+$u%((9CL8_3wida57!yU(/1:Px<63SZ
$$ux -[bV$,%((9il8_3WfDA:l
T%m+) 23rJ(c/X4\xq+:R4;YX8
_I0=*p7%![)12,R0((9i;P_JQ
$d=:yx#='N0*p7x$zBA:z=#=;%04YX8
_Iypu,_.uh/1:pXj+(*::S7%! *a:$U$29)123Gsp-/Z
$$uW23)10
Z\T;9rXOwY3 '9[Ow9#=9\2lyh]W Y2\ybRWUm3oWyQ3:\23/4t -ubHl
T#/']mdV_-W+M8OwYqp:=NU>MD((97d'_3xP(25P>8
_:R8Zj_3XCs/(=XUwIw['Y=+iE*\:(7DM%) -s0.+w9pL[_3X3uf(=XUq
$3#*5!R)*/*28SH(3EV(o=uW+N='t_jwR/aY5h+ly
84;Y=+PM[25pe#![)j-9J])*[f2\sQ+h/U+$+S*()1-9BjPY
8,HYX+,3/h2mbq6eEFS*xJ+(/25Pb#\M) )z=;q
$4u/y3Rxm'J:PxJ+981:$UJ(mE1E(0.+w9[l'_3)*/F2v+S+-[bV0<8
_:%-'7_Jx#IHY$y92C)\yzi3u(/1:p0.+39pPjXx((e HS[
a;6x 4yh++3S2$Ph#;6X%4Y33X(/1:pXj+981:$0S$()v(=Xrq
$*7;X_.pH21:PxJ+(*\:77DKR-a:Z$u4:\0;J_yx)*::)7[+-/Bj*[
aW[/avZb])*[/2x=QPh2/+t3j4:5GuYX8
_.*7;Y3;X#'%:pXj+9!1J$13((9=jy=8
_ODG*=i+L#$1:pXj)*/f2vu0(Mef:S0.+#96 /Uqj>/Z
$68xD-!/-7$5+(/1:t3ju:]64X_Jx(UFSs7X5-/BE)jyW;B;*(X8
_:\.\ _.,H:%hPxJ+(*\:57\['k7D:_jX)uvT$sdk%)12[yz/O)10
o7G;<k3**0.+p9>7J_yx3S25P<#t%rm*P!V4y
8$ h-%/3)1-p=5,:]p7x,Gu-/b:pXvL:]P7X,gf-[25P<#;;m4'YX+P(:z
$69GF9[AHz<r)$/h269gf9'ahZI<6($XI<12((E1j$y<= 5A:zX;4Y
8=L6/[+-[by;B<6(ix/t%[+-uh-5J#8<) -(E-)*/*28*qpH/HvL
TG8-/b:pXvPW[xaf9x(>e )90.P(9$/YX+HM:v26-ZM-[Z
$>*Q+hi T97k8<da:Zb#/Zb.*s!5)*[ 2[ODv-UBYT33py
8>!xmQP9! :$s2;f)%-S<<63/xAa9%(cEu+T33+:k,;6.[((ejV(<8
_%R2*p!Y4:kIaYi<6($xf61'2-/Xa _jq
$07(y33x3[1:PxJ+981:$gSP-!U-)Hj+(/1:t3jP:47H3_vXp:f(=X]q
$47jy3;xc'V:PxJ+9!1j$r[p-2Bj*b<6((Xmx=Q63e +pXj+(/257i8
_rk *=i+L#i1:pXj)*/%2G%Quh[f(OXvw2Y7*;xJW%X=*p!j+3ujVl
T#t 5a:ZxJ+e(1S$sST-[bs*><6(sxIJ.q+H/ 2J,<Y%) 0
o742!)12GDQP:4_*(0.uE92\YX+,p6
:(3\q4:DI*p7x=+) 2,Uq6PEFt(xJ+(/255$8
_:dczyj#=f)123,\(39i4yx8
_fD[*77%!()uhZEyWI01*p7%!')10
oU$$-/XL\-Q+:d4/yx#=rkA:zX3i)$z
$,RG((9i;P_Jx(/ Y(<#M'/a:$,[D<)10
oU[d<)1238DKi)%:P7x5OBC*p7%! *a:L
Tx! *A:$,W23)12,gSP-/z
-t#dk:w[P.m*2Q:z
-/R0/.Xx78+/V2Xd)$4\w00726u' :]C36[
kpP9.MJ7c :]c387*M;=XoWy3 '9i*o>++(/1:PxJ)*/*2,_apH21:PxJ+(*\:0[
a$o):)Zj5pcS/h90.p39=Uyt;xm2 j*h3h9! h$.D($'Bh9E]I>/1(=xRW2ba$5!3h#(/SPx<6(IZ
$88d($$bype]4($j(=X-w+y0*Oi+H((f+pi5)*/%2>_3X(9p't\*((e10
>=VW0072H##tiY$26U't:o. 7.[wF):vZxJ+(/1:P0.+w9c*oh+h#21:PxJ)*/V0
o1D($2Bt(bR+(/1(==3W'ba$9!ujcI1:Px<63[XIV_a4HU*:;xJ+(*\:07*K-8V-sIJ,(/1:T3J4y
8[3v_Auhuv:(X;iC*\:57\5<):JzJr+W/Us50.+C9M*7!jwOX2o6_jX(6
BOwY<=:O. 7.[W2O.U$,<Y9raS;7s59jaj07KV[o. YJ#y9y07W#Q3h[z
$$S[tuMP*57\v!O. y=# 4bmdV_JW Me*7!R,9!1vL
T#=!=7*5!r)*/h2,4\2-'byt3jJ:%CaY=+39!1Tl
Td=%)\JzXj+(/1:p0.+E9E<YB<6($xZ[/QP98 T$#2$ *a:L
T#!()u+7!;WR5aYZ>;I9!1E$r0(*UB:*bJ+(/1(==yQ
$0>*==+j)(1:PxJ)*/%2<%h+-!h-)$j+(/1:t3jP:4 *P!;l(UZ
$MBQ+h/U+)>#\M)\Jz$vH(/1:p0A+(9,)X_.lHSVvPxJ+(*::P[
aM()u-sIy)*/J28,4(3*\:;7dy /A:z<#;6X *p!-J([z
$v+Su-!/-0Xj+(/1:t3jP:%-'puQ6CeU:pXj+(/2$pX#;6X 4YH<_(iz
$v+SuI)1-pB#) 51*p!3w9X=/Y3rXp/1:pXj+9!1J$YZ![)1-0<8
_:\0;J_3xc*::07[+-'X/P_;)*/*2X=q+y
8x;A9Q+h'v2M0S$-/x;7_jw''AHl
Tdmz)12VU0((96 /uQ3M/1268Xd-!u-PxJ+(/1:T3JUy
8xi:u0((e J$U'(396UD_3IP6
:pwd:(*(B+7jJ+(/1(=x-W+J=ajm'((ev2[YZ/-/XAV9g;-[25P<8
_:KPU[-qU9!1+$sC2-! -pXj+(/1:t3ji:]>l>_;xP6
:IV40=%[a:ZxV4)[Xiv40=%'A:zXju)sj26yCFfk3*p!-woY.MJ_Jxc/%0
o.Z/[* *70a+w9$U[-<U-[257x#t65g*P!3Wo*i'g_Jx(2Z
$G,**'/AVt3j,:-2'GXQuE9#uYi+3#u25pi# ,) 0
oSL((E1:P<]I)9></Uq3H/V+T33+:]3*P!]+e(Xix9x((evs)J8
_U.A:zHU4)9m</Uq+H'XAa9T(3E%))0.p(9>!VMqpH'uST33+y
8>!xmQJ9! H$s2;f)*-7e])*[ 2[oz=-$bH;e<63[xaM1*T')1-9[
a/F*a:Z$#/fkAHt3jJ:3$;:%q+:07(Y33XE/1:pXj+981:l
T#\ [a50!J+(/1:Px<6([X]J=%(3*\:*7w2c)\hZxJ+(/1:P0.+c6
:2\13(*'B+9jJ+(/1(=x]WR- *=<+p(/1:PxJ)*[H2\S3(*$B:PxJ+(/1(=xVQ
$9='y33x)'1:PxJ+981+$.'2-[1:P7g2')1-Px3+#[Z
$6%[((e1:7$]P:k7iYX#t ]a:$%%)6kAHl
T42!) -07[[-[X] _JW9jahL
T<=U)v2,,q+:dizy=#mI)\Hz>-+(/1:p0.PE6
:2,U\(3EH23,Q+:RIZY=#=i)10
o,X -[XL\XQu(9Cmp_jwF0=*P[
aMR5a:$,$F-/x4\-q+:R=:YX8
_I51*p7%$Zba:$U[d<)1-77%5obc*P[
aM;%04y3-x(/1:PxJ+981)$,$29)12,RS)-/xLM%3((6
:2,Gsp-/Z
->md)f9MDv=\$:=MD/7%)6*I*)e#2;*_*5<#90-mdV_;W6*6UHM\(mE 0
o7G$2o. YB# 0wMDv_3w+>0oWyQ+:X.FY=+4#*\:*[
aWFW['y=+Ue:25PI#M!=7*7!Vl9!1t$yx/-[b)t3jJ:%iAy=+pm(25PI8
_7.AJz<<6($xZ[/QPhi2$7i# Z57(yx#!()jJ)!Yq
$0=*7!333*\:;7$f-2BYsE<63(XM[_Jx(UV2<%H+-/BY5x3Q
$4 *P!]p(SX]5_.Lh(/VpXj+(*\:57w3-[u-7j8
_.u3*=<+3C21:pXj)$/12,XQ3h/fTt3jJ:=IFY=<6((x <%J(3EH+0[
aWO\7HYX+,psj2V+sU-!J-(=-+(/1:T3Jp:%-'PUq+H[ )L
Tdy [C*)!jPE*::)7DY 'c*==++(/1:PxJ)$/12T%[+-I25P<8
_9X=/Y33X)/1:pXj+9!1H$yz![)1-9irw6B='Y>+H981s$1j((e%Vl
T#F()h-5e<63:x/7_3x):V(=xRW'n0*P[
a\9x=*=j+,c'1:PxJ)*/%2G=Q+:5%*7[
a;ina5(!y,w/1:Px<6((X ,-q3H(1)T3J,:ypu,_Ui(6
:I:U2(*:Bh9$J+(/1(=x-W2yC/YX++M(/)$u'((efsS>#5<fatP[
aW6m_\Y3]X>' :pXj+9!1J$#:$%x.3yx+hmI*2[YZ/-/XAV9g;-/Z
$$SDK%-avT3J4:k8'Y>+PE*\:07*/foA:zHrq
$]P7X,gp-/B:7$]W2%8/3S-((E1:PhyW2%8/3s0(3*\:07D5007*P!3+>6
:I/S0)3) -0<<_(SXi/s0)C) -(0.+W9$PGoQ+h/%2V0%2')1-PjRQ
$5iID1J(3EJE50.+P93(J1J(mSBjs7lk-[bT;B<6($xZf_3X(sh0
oSL((E1:Ph3j39></UqIH[uYT33+:]3*P!53>IXix9x(36
:OF_JxP[*Y$\lkI)1-57GD<mA)z$<63[xaAyt(Mej(==3q
$Kg/w_3)*[12[OD=-'B)00.p(9>!/,Quhuv(==jw%4=I61q+H2Ht0[
a/F*a:Z>RW%r>*(0.+w9EiG8S((9>\yx8
_rX2*==+P3/1:pXj)$/12m%3(*UBS)xJ+(/1(=x3W.x lyh+4>(25PE8
_.X%*=J+uCi1:pXj)*/%2\13()e%V50.+#94/7_.pH[V:PxJ+(*\h([
a!%[a5(!y,P/1:Px<6('X;J_-x3(2$Ph#T;XAepX#/ 5a:ZxJpm2H0
o7*2')1-pXjL#//2[%*(3E/v*0.+e9$'6_jX([x'309/-[z
$$)S#-/x; _3W.jatT3-l:*_*P!]4y
82L>_rwira:$U% -[X4,_.4h(*TpXj+(*\J9[
aWID[*S7%=-/Xl3#qp:RC*p[
a=i=ah$,$+-u -;>#MR/a:$,$$-/z
$,R[((9iMX_JWI03*p7%!%)1-P=Vhw6
:4\Sq+:R=:YX++([jT07x$()12312K-/Z
$,12k-/xL:yzm-'1:$U';<da:$,$29)10
oU$29)123Gsp-/X4m%3((6
B(8YZW!=-Gw.sSm6
B(8YZW[-mGXr:SZ[Z
-/R0/.Xxu\-3w'932t##TIy[26u'TY
38eS7< :*[g87*m;=xi,8*w!=-gW.Ss36
e7;h#)+C[2T#/t:]c387*M;]X78+/v2xDjL
\rw+*7V77< Q]xZt%;i:]C367kvo[$23_ALh/1:pXj+(*\:(7x($'bJ)Xj+(/1(=X;q
$5P*oh+33/FE;xJ)*/F2g9q_>EuhPE],(/25PE#to):jZE3U>$F:P0.+m9$Uyt-x#[%S(EJ+9!1)L
T\5O):sz>Ui):U+50.+>9[3/_Aihs*s9H;4C*\:)7K(3e12v%<92)1-p[
kI:=2'*=#)+C[280s3>9$4:##90% Z$,q_eE1:PxJ+(/25PI#M-8 -5>J+(/1:T3J3y
8= YT-XWuf:(>vi9!1e$1z($'bTSejJE:/(=X]w2%A$7!5H>sfe)H<6(uxi/_APh2js*e]i>*\:S[
a ;%a$;!;3e2 t*E<6(:Xz:9q_#Eu)*$3je(25Ph#9-[B:$Ys)u]a:Zx8
9)9$4:##TIy[26u' :]C387kvo[[23_ALh/1:pXj+(*\:(7x($[bypXj+(/1(=Xvq
$5P*oj+I3Su:)h-)*[12g9q_mE/h*jJI>'257x#to):jZxyl#(/SP0.+>9$Uyt-x(SHE;hV+9!1SL
T\5O):TzHY3([1J)0.+M9[3/_AJh:h)p=ju>*\:S7K(3e12v%<92)1-p[
'4P9[(JjVW[9h:p0.3:oAHzX8
5p2x;$#<2E[xvPx<6m9m*7!JQ
Hb4/[GsW!=-Gw.sSc98z$M$2:]c387*M;]Z
o7<#VrXx787*m;=xi,8\wuMPh81#=-8h-pXj+(/1:t3jJ:DA$7!3Lp'1:pX<6(:z
$GyQ_3evTpHYJ)'257X#$<):Hz>]+>s1+*0.P(9$ YT3XCu1:9Bv+9!1s$.z($[b)0>j3(:1(=Xvq
$=6 yt3x([1v)EVh9!1j$#'K-8 -P=Jl>(/YT3JU:OahZx#; *mIyx++y
o s$m$2:w[26u'T:]C367kvo[$;$,Q_Ee1:pXj+(/25pi#m-8U-0>vi(/1:t3jiY
8= YTvXMs/+5Xj+9! :$1z($ibySi-i(/1(==jw2%A$S!5+E21:pX<6(:xi/_Aih[v)*>j+(*\:)[
a ;%a$s!J4(/%E*x<6(UXz:9q_mE1+Px-,e/25Pj#9-[B:$Ys)u]a:Zx8
XUmp(37KVO[$;$.KV<9I(<0%(>(x':0:(CixOw-kvo)u2<0'K!M[*s!3Q
$9>;6\t;-'xZW4KVO) 28az90%A:$%to-[b+;0.+E6
:234\2-'B+T3Jl:d8zJ_-x)*\:(7DM%) -s0.+w6
: 3Sq6cE1:PxJ+(/25P>#O,)%(=xuW+K;*70apw9[!G%<((6
:2\XQ3p[b)$R[()eh))0.+#94/Y3;X(s%:pXj+9! Vl
T$/-! -($]+(/1:t3ju:\7>P_.lH:J:PxJ+(*\:77WP-/b)*X;q
$4%*P!J3P:H2mjq6cEJS9xJ+(/2$Px#\M-A5*!Y4E/1:pX<_(/z
$,XQ3hu*Vt3jH:=IFY=<6((x <%J((EV2V+sp-/Bj(x3Q
$%-'5_.IHI1:PxJ+(*\:77DY /c*=b+3(/1:PxJ)$/12V+spi)/(oxRQ
$%-'5Uq+H/%2T%[+-/Bh$0s$[)\+Z<J+(/1:P0.+c9pu\-Q+hiv0
o79k'XAHzB<_(ix;p_-w[/A)t3jJ:- *p[
aW'n0*P!-4:42'g_JW'[a:$1-(36
: ,Oq+:%C/YX#5obc*sjJ+:]64A_.3h/1:pXj+(*\:5[
aW2Yc/yx+pc9C3Y=#5<FAH)<8
_6m_\Y3]Xp[U:pXj+9!1J$#:$%x.3yx+4:kpu[_jw%%0av_3)*/v0
o7G;<k3*50.+p9>7J_.pH/1:PxJ+(*\:)7*/foA)z<8
_2%8/3s3((e1s0$3w2%8/3S-((E1:5$yh:]P7X,gf-/Bj$y'VrXA:zBjuY
8$u[-<P-[2$pi#T<k3(5_3)*[126+[D-/bH$y<= 5A:zX5q
$5iID1J(e*\:;70) 51*5>#8<)*-sE;)*/*28*qpy
8><YX++(/ve)$#/,BC*S!j4p*\Hp7*F-/bep>]w2-04yx+4>:u0
o\L((E/t0$#9,BC*p!-w%N0DY=+uM:257X#/z%.*7!-3>*\Hp[
a/Z-.*(0.p39>!V,qjH[FET33p:KgU3_ux3(F(==3W%4=I61q+H2Z
$[,<((ej2[,g(3*\:(74T'y7*p7$29)\hZ>J+(/1:P0a+(6
:2M%3(*ib:pXj+(/1(=X3w.X LY=<6(sx]jBQ63e1:pXj+(/25pB8
_:0=HY3-Xp2U:pXj+9!1e$R0P-!v-7Xj+(/1:t33L:0>HY3UX(/1:pXj+9!1sl
T#$ )\Hz$-+(/1:p0A+p9$3j_3+(/xaj1Q+h/1Hpe3q
$]7;yx++([JE77g22)126%*((97lT+g(36
:fJ4qpHIX; _3w.JA:$0:(36
:(3\q4:DI*p7x=+) 2,Uq63EHjPxJ+(/257>8
_:DCZY=+L:ri*P7%=+) 23uQ+Y
8I48_3wF01*5x#MR/a:$,$$-/z
$,R[((9iMX_JWI03*p7%$()10
oU[+-/XLGoz((9C;A9Q+h[xL:yzm-/z
$,8dkI)\JzXj+(/1:p0A+M9iMJ0q+:d4'T_JWF47hyx8
_:D,'7_jq
HO. T,#90% zg7\90bXlT+<=-:F2J8<[-'V2>m090%A)$+<5<w.ZYJ+PY
8xAg.kvo)%28Mc90%ah$#_KuMP*P7sv7) -0E<6(SZ
$$,C  ) -5>v)*/*2,4\2-[bs*0.+W9P4[_3xm*\:(7d=%) -7J])*/*0
o)L(cEV(=xuW+K;*7!R)$[*28o[29)12\xqhc:BvL
T$$-[bHS=<6((xmx_5X)uf(==]wrkA:zX;4:\7>p_jX)'1Hl
TWP-/be7XYw.'a5*!]Ie/1:Px<6('X]S_33h[U0
oG;f-!V-sb5+(/1:TtJ+:d1*s!J,w*\:(7\=7) (=x]WO\7:Y=+Lpiz
$$Y923)1-;<yh:%-'5_.Hh$ JpXj+(*\:77dy /C*p!3PM6
: <%3M-:B:7><_(:X <%-m-! -pXj+(/1:tTj+:*7;p_r)*/v0
o0s$[)\hZ$J+(/1:P0.+39PU\-q+H2*+$+Z$ )H-90a+>9=:yx+Ue6
:2XxqlH'F(==VW[[AHz$v49!1+$12k-/z
$M0S$-!U-;B-+(/1:t3ju:5 *P7[U-[Z
$vu2(*$bV;ij+(/1(=X]wOD3*S!]+M*\:;7';<dat)x8
_2yC!Y3vX32j:pXj+9!1J$.'M[)1-Pj]Im9c3yx+,>UH2:9h(W/z
$$+T[T)\EZh-p(/1:P0.+c9[\GsSV;)1-9JrJ:kpu[_jw%%0av_jq
$9> /s0(E*\:07g# )H-7><6(IXI[,k((E/+L
T*;!-Ia7_jX([je$.d#[R>JYX++(//V$.D#[r>/y=<6(IX :m$2-/bHpH8
_2B>/t=QPhiv(OXYw2b>/TbqpH$25PI#t65g*P!JU:%2Lj1Q+h/U+l
T[=2F=:Y=+H#'25p<#F9X=:YJYXCux</_3xw(%(=xuW+.ahZxyly
8><YX++(//H(=#/,BC*)!33)*\Hp7*F-/bySHrw2-04y=8
_U.A:z<3J)9m</Uq+H'XAa9T(mEJ(==3W%nPdyj+h9! hL
TGD[mAHt33+:kG 3_-XMi257X#/Zbi*5!;49! :$sW$2]=*p!5LWiz
$[,<((eh+$s%/-$25pi#O256'yx#/t)10
ors)-! -7=J+(/1:TtJ+:47HY3;X>:1:pXj+9!1H$gSPf)/-0H])*/f0
oGsU-!u-5bR+(/1:T3JU:0=hy$+Ue'25PE#![[A57!34(/1:pX<63$z
$\s3(*$bV;<j+(/1(=X-w'XAJz=])$//268s(#/12[%[((e1:7J5LY
8xIJ1q+H/1:*EJI:k7iY=+iEs25p>#t ]a:Zx3W r2p[_3Q
$9e'H_JW'JAH$g:(W*\J*7<[-/be0[
a)FOa+$u%((9CL8_3wida50!]jw/1:Px<6c2Z
$$UX -UXL3_jwfR[*77%M-/Z
$3u\(39iMP_;pH(H2,Rj((9iMg_JQ
$d4;yx#=r-A:$U$f-/XL\sQ+h/ s9i8
_I0>*p7%$()1-Px3hwIX4gxq+:R=!/_jq
$d=!/_JWFYPU,_-+(9C3v9x((9iMJ0q+y
8Cmj0Q+:R,'7_jwI47HYX8
X9=pu$4\yQm$'.B8
X<03aM%##+\dD6%/P:w[2WRSw2D6Z$.x526
mh07T! 98z$.X5+9$4:##90% ZG7%($SB:PxJ+(/1(=xuWi):tZE3pc/1:P0.+P6
:;V_apH//Y;E3j>*\hP7[K-8 -s$5,e:*:T33+:]P*o>+U(//h9xJ)*/V269q_#E/vPx]h(/25P<8
_+yp*O=+432%T)=])*/%288z($[b+7$-J>[f(=X-wU) -p7d29o$*p!jq
u[/2wrsW!=XI,8*W2d6I$\t;3]=23_alH/1:PxJ+(*\:(7X($'B)*E5+(/1(=xVQ
$5P*oj+Iw$%+PxJ)*[12g9q_mE/t(bR+(/257x#to):jZ$V,((1:P0.+>9$Uyt-x):F:;xJ+9!1SL
T\5O):sz<ULM$1+50.+M9[3/_Aihi*VSij4C*\:S7K(3e12v%<92)1-p[
+90%2l$\T;3]=26\TK:r2pT,qI#973TdqUP9MDx\t;-uxPt8z#0=A)z=8
_:K=I>MD(c9[dH\T;-[Xz_9kvo)12JM4(3EVET3Jly
8xLh#S(Cev(=XYwIw['YB+H9!1T$yx/-[b)t3jJY
8pL[_.uh/1:pXj+(*\:*748-'25pi# %FAHtT3J:=g;J0q+y
8xMP_;43Eu2\1qhHSuST3J,:03*=j++e'1:PxJ)*[H0
org(*[Bt9EJ+(/1(=x-W6X;:Y3YX>21:pXj+9!1H$G3((EuvPj8
_.'A:zX;4>sx]S_.uh2/ypXj+(*::p7w3[)\vZ>Rl(/1:P0a+(6
:4P_;xm$H(=x5W+re*70.+#9pPjXQ+hix <%3((e%Tp=8
_O\7JY3vXp/1:pXj+9!1H$y92(DA55!;+(/1:pX<_(/x <%3m-:2$p<8
_O\7J,_jX('x(j1j((e 2t%[F-!v-0Xj+(/1:t3ju:%0MX_JxPIZ
$$+Z$ ) -50a+P9=:yb#f()u(=xuW[[a:L
T#$zBA:zBrw.*7;YX#$3)12GBQPY
8p4A_jwod3*P7';<DA)SXjw2Yc!y3;x(/1:PxJ+9!1jL
T#T;D3*p!3u:d6*77'Ka) S0[
aY0j_*=E+43U1:PxJ)*/%28D[/ m6*p!rw%%0Ayx#/ob> y=<6(IZ
$$SDK%-ajT3J4:k8'Y33X(/1:pXj+9!1s$.g=u)u-0[
atoW3l[=q+H//+9=#TOw3L[BQ+h/1J9>5w2%8/3s0((e%2V8T! )1-5x-Q
$]0AX03(3*::(7*K%-2jy=<63/XI<12((E 2V0%2')1-P$8
_'R$>GXQL9!1e$-<2'/AJ*7lk-$b);J<6($xZf_3q
$K#*P!J+(IFS97g8<da)ZxR49! :$.0((EF:*E#T[BC*p!ri>uz
$>*Q+h:*+97k8<da:Zb#/Zb.*7!-3>*\hP7gdoMahZb;I9! :L
TGD[mATt33P:kG 3_UX3(f(==3w%N0LYi+P#(257=#/.5$iG_jX)6
:A30q+H2Xa3sQP9!1T$)*$;xa:$RS)-! -*Xj+(/1:tTj+Y
8x]J=q6PE1:PxJ+(/25P=#\ [i*70.+e9,'5_.pH/1:PxJ+(*\:5[
aWR5 *=b+4)U1:PxJ)*/F2\-3(*IBhPxJ+(/1(==yWRK *=I++(/1:PxJ)*//0
o7[2-! -9bJ+(/1:TtJ4:]6'y=J+(9>'g_Jx(/ :;=8
_2X=*p!j+32fH$sST-/xIJ.q+:XI(<sQPY
8E'h_3Xp9=\y=#\T)12Tdqpy
82L>_rwira:$U% -[X4,_.Phs%:pXj+(*\H*[
aWid[*7!yWfRA:$,% -[xl,_JQ
$rczy=#=r/AJp7x!()123r[((6
:4\1q+:R4/YX#MR-a:$,[+-/z
$,1j((9i;a9q+:d=!/_Jx39i3V9X((6
:4:YZM-!%-PxJ+(/1:TtJ3:R4't_jwI07(YX#=.X *p[
aWi47hyx8
XUmp(37KVO[[;$#KV<9I(<0%(>(x':0:(CixOw-kvo)u2<0'K!M[*s!3Q
$9>;6\t;-'xZW4KVO) 28az90%A:$%to-[b+;0.+E6
:234\2-[Bj*h<6($X4H#s(3E/vT3Jj:%CaY=+39!1T$Y%/-[BhsE<6($Z
$'*Quhi25pi# %FAHz<<_3$xza1s)-/Xmp_5u>eh0
or[(3E )70.+#94/y$+hm(257E#!%)1-PjRW6x;:yx+hc/ 0
oG3((EFhP>#\C)\VzevL(/1:p0.+C9,)y=;x3UZ
$MJ0(*ib)5$j+(/1(OXjwI/A)zX]J9!1T$#%o-[25pe#;6x1*7!y4P6
:2v+SP-/be0>5wo\7jy35xw[%:PxJ+9!1h$Y92(da:Z=33y
8pPj=x(>e1H*0A+>9PpJbX(*[B:PxJ+(/1(oxJW9x=:y<<6(IZ
$t%[F-! -9Xj+(/1:t3jP:%0mx_jX)$v2<9[2-sbytTji:51*p!-LY
8x/p_YXC(257H#f3) -9hR)*/V2gOZ((6
:]T%[(*UBE5bJ+(/1(=x-W'[A:$1-(36
: ,Oq6wEHE(xJ+(/25PE#;i-a)ZEJ39!1E$8dkI)*sp[
at;dg*=h+p)21:PxJ)*/%268xF-/b:Sev3:D6*p!]iMsx3//qj(6
:2<m:[-!f-)B3+(/1:t3ju:=_;[%T5-/BYs<uW%%0Ayx#/ob> yx8
_:KPU[-ql9!1+$sC2-sbH*0.+p9$a3\Q+h:v0
o.D#[r>hyx++32F26YcfFK%*P!J+(:H26yCFfk3*70.+p9P3wrs((E :)[
at<K3(7_3xPI2$P>#T<k3(5_3XW*\:(7*y'NA:zX-wo*i'g_Jx(UV0
o1%ta51*7!5,c*\:070) 51*s>+Um9#uY=+J#'25pi# ,) -p>Yq
$K#*P!J+(: t77g8<daSZ=;h9! :$.0((EJ))<#T[BC*7[
a9,)1-0=uh:o#u,_jXC9>!/mQ3h2257=#/z%.*S!5)*[ 0
oS2f0) (==JW%nPlyb+3P*\hP7GD<RAJzJr)*[12[G[t25a:Z$yjP6
:A30q+HSV2[,g(w*\:(74T'y7*p7g[-/Z
$\%<(*[bH7Xj+(/1(OXjw.x *=j+I>/1:PxJ)*/ 2m%3=-:B+)E<6((Z
$M%-(*ubJ5<j+(/1(=X-wr5 *9!-LC*\:;7$f3)\hZ=R+(/1:P0.pw6
:M[=q6wEHE0xJ+(/25Pb#$ )%-7E<_(:Xi:%Q,(/xAJ1q+H/1hs$yQ
$9$'G_jX(/1V;Xvw%x$*7!Vle*\:*7*22)1-p=#2f*-aY=8
_:377YX#$T) 2mdqj9!%v$0:((EF+L
T<=U)v2,,q+:dizy=#mI)\+zeUJ(/1:p0.u)6
:2,u\(M9ilyx#=F=ah$,x((6
:l,#qp:R4:YJ3X#sx4\xq+:R4;YX8
_I0=*p7%![)12,R0((9iM[_Jx([/Y([
aMRKa:$,[+-/b:p=5Jp9C;p_jwF5gUyx8
_I5GuYX#=;%04YBj+:d6 /Uq+:R4't_jq
$d4'T_JWF47hyx#M.x *P[
+)+%02H#9S0]7G7[
+)+%02/r0py
e0mxsW2:w[/\D//Um0gAH#)+c32h#Ss9=xi,8\w2D6il
\Uw2D6Z$.x5+9$4:##TIy[2>MDp+9I*O>++(/1:pXj)*/*2,_Auh$*:)Xj+(*\:0[
a$o):)Z$V+e$Ht50.p39=UytRxe2JSP>;U9! h$.D($'BEPx-+e/1(=xRW2ba$s!yp#SHvPx<6(IZ
$88d($:b)9X-L>[1(=X-w+y0*OH+3)/%V)=j)*/%2>_3X(9p't\*((e10
>=JW!=7GT##)+C326U' :]c387KVO[[23_alH/1:PxJ+(*\:(7X($UBYPxJ+(/1(=xRQ
$5P*oI+h>'1v)=5)*[ 2g9q_wEJS5xyI32257=#to):SZI5,#:/:P0.+P9$UytVxw2FE)hJ+9!1+L
T\5O):)zJvJ3i1y00.+C9[3/_A3hu/T7<jHp*\:57K(3e12v%<92)1-p[
kl:W['.0\W9=D/$.X529$4:.#90% i$,q_eE1:PxJ+(/25PI#M-8u-5xJ+(/1:T3J4y
8= YT5X(ifepXj+9! H$1z($2b:0e]+(/1(==3w2%A$)!-+W(1:pX<6(ixi/_Aih'1T;Xj+(*\:0[
a ;%a$s!VhwS :5<<6('Xz:9q_mE/Y(>3+cI25Pb#9-[B:$Ys)u]a:Zx8
93[x78%/)+92Z.-#TIy$26u'T:O. 7.#=-8h-pXj+(/1:t3jJ:DA$*!Y+(/1:pX<6(iz
$GyQ_3ejVSe]+(/257X#$<):Hz$Y3#(1:p0.P(9$ YT3X3:hT;Xj+9!1s$.z($[bH)>U,(/1(=Xvq
$=6 yt3xc:*EPh-l9!1j$#'K-8 -5hu,(:%vT3JU:OahZx#; *mIyx++y
e2Zv9##+-4\.sKV<cGsl
!KVO*I2>mdP+%xZ>mzwf*-(3_v,:X6( _-4:O./>MD(m9-(:9cv+)u-7[
aW%5$oWyQu:=.7>md(39[N/\t;-/x'W)QPhif(=XYq
$9i78%qpH'HST3Jj:d8zJ_3x>S25PI#;IkAHzJ<6($x 3SqpH[uET3Jjy
8E<YB+49!1T$#G*-[b+tT3J:=g;J0q+:01*9BvXE6
:Mg_3x3U (=x]WR-aYZ$;,9! E$rg((E1)0792a/a:Z$-+36
:]7_Jx#[1v$g-(*sbe)>j+(/1(=X-w.Uahs!33y
8,)x_.4hu%ypXj+(*::p7x+-ub:;i<6($xZ3)QP9!1e$Y92() -*<RQ
$9pPj=Q+h(vV97DY 'a59!upc/1:Px<6([X <%JM-/Bh7j8
_O\7H,_vX([h(OXvwo\7j,_.pH/1:PxJ+(*::P7<2'/a+T3J4y
82'G-Q63ej:pXj+(/25p=#;<03*p!5Jp9-uG%QLh22$pH#$()1-5>8
_:-1**!-,9! s$-3(3EJS00.+P9=!/_JQ
$42'g_.3H(%jPxJ+(*\:57[P-/x;5_3q
$%c!y3uxe(*:PxJ+9!1E$YXf-UBEPj<6((X3v9x(W:10
o.'MZ)\SZ=5h(/1:P0.+c9$3,-Q+h/Ue)J#m;)1-;H;L:Y0>yIJQ
$9-D DQ6#e/J7Xj+(/25pB# T5>'w8q+H2u+(7g;<Ka:$SDK%%a:L
T#/ob>/y><6(IXah%QLh[h(=Xrw2kIoYX+ip6
:IV40=%[a:Zx3h#9$ H-%/c)1-PxJIe9$ h-%/[) (=XrwoY.MJ_Jx3//0
o.Z/[* *7!R4981v$.z/[*%*7!U)*/*26+[D-/b:57D)Fx=*P!J3P6
:;3.H$() -9E-)*/V2X0s$()uvZb;W,BAHzi]u9!1T$#l(3e1V*[
a/,)1-PxJI3$ 2[*ZM-:Bhs$<63/XIX_Jx)U/+$.0kI) 0
o\L((EVh($#9,BC*p!-w%N0DYJ+H9! H$s2;0)U-90.P36
:Aa-T(3*\hP7gdorajZjR)*[12[oz=-'b)00.P(9>]g.*$-/BY*IRQ
$Ki(yx+lP9>l[_u)*/*2'.[5 )12[dq+y
84't_.Ph[ :pXj+(*::p7w23)\)ZhV+(/1:P0.+39,'7,qIHI/ET3J,y
8,'5_.3h'%+pXj+(*\:57$$3)j-5>-)*/f2\-3(*[Bh0xJ+(/1(==uQ
$0>hy3uxe(V:PxJ+9!1j$1s(cE ETtJI:]6'Yej+:K7;yx++([uY*[
aW2X=*p!j+(sf:)7g22) -)>y)*/H26%*((e1H$%%)6kAHl
T#o wA:$1:(39,\yI<6cSX( _Jx#IZ
$t,K(p9clyx#MF=ah$ux(*ibe(ij+(/1(=B5q
$9C48_;wFra:$,% -[XL,_jq
$rczy=#=r/A)7!]L:d4:yx#=r5A:l
Tx!')123r0((9Cmx_jwF0>*P!Jp>2*0
oU$/-/XLGXQ+h/1H9irwI51*p7%$Zba:L
Tx$zBA:$,';<DAJpX#M;%04yx#=rX2*p[
aMRx2*P7%\ [a:$Uw23)10
Z\T;9rXOwY3t:]md/7%)6*i*)E#2;*_*5<#90-MDv_;w6*6uhm\(Me 0
o7g$2O. yb# 0WmdV_3W+>0OwYq+:x.fy=+4#*\:*[
aWfw['YB+49!1V$uC  )%-90.+W9p4[_3XM*\:(7D=%)\jZxJ+(/1:P0.+e6
:2'*Qu9!1T$#G*-[2$7i# Z57(yx#!()U+7!;q
$94;y$+lm:25PE#![)\)ZxyU(/1:P0.pe94aY33XW2f:pXj+9!1Jl
T92A/A5*!vH(/1:pX<6([x]7_JxmS1)$g-((e1)0HYq
$4u*=b+h>21:PxJ)$/12MJ0(*sbV0>j+(/1(OXjwI/A)zJUL9!1yl
T\=7) (=X]wo\7:yx+4:%-'7_Jxc$1h$y92C)\sz<j+(/1:p0.+36
:2V+s+i)\jZjJ+(/1:P0a+(9PpJ=X(>*::07dy 'C*p!juY
82'GXQ+h[x(j10(*ib+pXj+(/1(=X-wob4/yx+4P9-uG%QPh'2$p<8
_:51*570+-U25PI#f3)12gOZ((E%+L
T#\9X=*p7[P-/x;5_3wODG*p[
a;i-a:$8dkI)U)pX#t;dg*=j++(/1:PxJ)*/%268Xf-/Bh5[
aWiYah$8Z*-[/+$+t[t)\ez<33(/1:p0.+C6
:z 1g20Ya:Z<#/OB>*p7G;<kp*70.+p9> /S0(c*\:0[
a/!xa57!J+(/1:Px<6(:Xi[,K(Mev26yCFfk *p!jip2 0
o.D#[r>jyx++('Jv97*;!-iAX_Jxc9p3WRS((e%:57*K%-2hy=<_($Z
$69GF9'AHt33+:]-;A_jX39p(3%[((e1y$1%TA51**0.+#6
:/T%[+-'H2F9qjHUF)T3Jj:=#*77g8-/B:PxR,>2Z
$[*zm-ub:0<<63/xix_jX#/he$.0Ki)1-0hV3:o#*p!vJp2z
$>*zm-/bJ$s2k0) -5Jv)*[12[odV-[bJSH<63/xaA-t(W*\H7[
a/Z%i*(!3,#*\h77gd<ratZ=],9! h$Sw$2]=*P!5W%r2*P!5Q
$KiAy=<6($XF61'2-/xMJ0q63EH:PxJ+(/2$Px8
_.X *=<++(/1:pXj)*/ 2M%3=-[25p>#\ 'A57!j+(/1:pX<6('z
$\13(*'b+9Jj+(/1(=X]wr- *=<+P(/1:pXj)*[h2\s3(*$b:pXj+(/1(=Xvq
$57*==+hc/1:PxJ)$/V268s(3/1:$Ss$-/B:P=J,39$'g_Jx(/ Y;=8
_:k7iYX#t ]a:$%%)6kAH$)s#-[B+L
T[[-[x] _jw9JAH$0%9-iz
$,,Q+:DIZY=#Mi)\hZ>-+(/1:P0.pe9c48_3xe6
:23,q+:rizy=#=I)123u\(36
:l\xqU(9cMP_JWf0=*p7X!')10
o,$f-/X4\-Q+:r=:yx#m'/A:l
T%$zBA:$u[D<)1-77%5OBC*p7X5obc*=b++(/1:PxJ)$/u0
o7%! *a:$U$29)123Gsp-/X4m%3((6
BOwY<=:O. 7## uM02309)F)/E$%')T)%+$\tFUmp*S79);B8D8_;X36
:2[1*90%aj$#T#uMP*77\%<O. yx#203ahZ<])*/H0
o7%#+XAHzBYi9!1T$uC  ) -)><6($x ,SqpHU25PI#;fkAHz=;,9!1Tl
T48-'b+t3jJ:=>>Y=+498 T$#2$ *a:$Rj()'/-*[
a!') -7j3)*/F2\-qhH2uET33,:0>*P!J3P9-'Dxq+H2%:7[
a\3)1-;=Jl:4%*=>+,>s1:pXj)*/%2mjqpmE )L
TW3[)\+zJ-H(/1:p0A+(9C:YJ++#$25pi# f3AHt3j,:%-'P_3xeIV0
o7dy [A:zerL)9PpJbq6)E*h5xJ+(/25P=#;6x14yx+p3UZ
$v+SPI)/-p=Y)$//2V+sUi)\hZxJ+(/1:P0a+(92'gxq49!1+L
T<2'-A57!5+(/1:pX<6([x /R0((ejT079k'XAVz$<_(:x;p_jXCsz
$$-j(Ee%et33i:- *7!5IP*\:07[d<)10
oG<2')\)ZE-U(/1:P0.+c9=HYX#$C) 0
oYXd-!*-*Eu+(/1:T3J,:%c/yj+,(U25PE#5OBC*(Hjq
$]64a_.IH[JYPxJ+(*\:57*5I-A:zX;,>ux4:_jX#:UV$8Z*-$10
o79VtJA5;!vu3/1:pX<6('xz 1g20Ya:Z$;4w9> /Sq+:KPU[Yq+y
8xAV9gf-S25P<#/!XAVz=Y)*/v26s%9-/bs0[
atoW3l[=q+H/ Y;7*;!-iA5_Jx(/1S*7*;!-Iax_3)*/v2V8T! )1-7xVQ
$]0AX03(3EV+TtJl:]0ax0-(3e*(=XUw2\=!YX++C9P(3%[((E1)0[
a$F];;P_3x)(%(=xRW[*7;P_;lH'u2f9QPh$fJt3jJ:=#*7!jLE6
:AF_Jx(/1S7I3W%.04yh+pm2257x#t[)1-9jV4:]3u,_3q
$O#*P!Rpw2Xof9x((e%2[ozV-ubyt33P:kG W_;X)*\H7[
a/Z-.*70.p(9>!V,qUHUV(==JW%N0LYB+3p*\Hp7g\']$;yx+he$V0
oS%)-/Bv07g=%)*(=xuW7]=3j_jw%ja:L
T$29)\Hz=3+(/1:p0A+(9,'7_.3H:/:PxJ+(*\:77w23raSZ<V,9!1EL
TW2C)\)zB-4(/1:p0.+C94;7_5XCs%(=X]wR- *==+pP/1:PxJ)*[*0
orgp-!*-*ER+(/1:T3JU:57*5!3,981S$.'2-(1:$Ss$-/B:P=;he6
:26%[((e1:p>]+>9>'6_3x>SH(=xyW2X$*p!jP:XI(<sQPY
8xFj4Q+:5_*77w[-$255>#)T)1-;<8
_9RM*07X=-/X43#qp:DC*=<+,W$1:pXj)*'j0
o7xm+)U23,q+:rizy=#=I)10
o,X -[XL\XQ33efV$U$+-/XL\1Q+Y
8CmG_jwF03*P7x![)123rg((E1h)$uQ
$d4Ayx#='/A:zXjP)$v2,1j((9i;a9q+y
8C;A9Q+:R6 /uQu(/x4:YZM-/XL\%<((6
:4\%<((9i]J=q+:d,'7_JQ
HO. T,#90%%z$#kv<9i(<0%(>(X':0:(cIXoW-KVO)U2<0'k!m[*S!3q
$9>;6\T;-'Xzw4kvo) 28AZ90%a:$%TO-[B+;0.+e6
:234\2-[bJ*H<6($x4h#S(3e/Vt3jJ:%cAy=+39!1t$y%/-[bHSe<6($z
$'*Quhi25pi# %FAHz<<_3$xza1s)-/Xmp_5u>eh0
or[(3E )70.+#94/y$+hm(257E#!%)1-PjRW6x;:yx+hc/ 0
oG3((EFhP>#\C)\VzevL(/1:p0.+C9,)y=;x3UZ
$MJ0(*ib)5$j+(/1(OXjwI/A)zX]J9!1T$#%o-[25pe#;6x1*7!y4P6
:2v+SP-/be0>5wo\7jy35xw[%:PxJ+9!1h$Y92(da:Z=33y
8pPj=x(>e1H*0A+>9PpJbX(*[B:PxJ+(/1(oxJW9x=:y<<6(IZ
$t%[F-! -9Xj+(/1:t3jP:%0mx_jX)$v2<9[2-sbytTji:51*p!-LY
8x/p_YXC(257H#f3) -9hR)*/V2gOZ((6
:]T%[(*UBE5bJ+(/1(=x-W'[A:$1-(36
: ,Oq6wEHE(xJ+(/25PE#;i-a)ZEJ39!1E$8dkI)*sp[
at;dg*=h+p)21:PxJ)*/%268xF-/b:Sev3:D6*p!]iMsx3//qj(6
:2<m:[-!f-)B3+(/1:t3ju:=_;[%T5-/BYs<uW%%0Ayx#/ob> yx8
_:KPU[-ql9!1+$sC2-sbH*0.+p9$a3\Q+h:v0
o.D#[r>hyx++32F26YcfFK%*P!J+(:H26yCFfk3*70.+p9P3wrs((E :)[
at<K3(7_3xPI2$P>#T<k3(5_3XW*\:(7*y'NA:zX-wo*i'g_Jx(UV0
o1%ta51*7!5,c*\:070) 51*s>+Um9#uY=+J#'25pi# ,) -p>Yq
$K#*P!J+(: t77g8<daSZ=;h9! :$.0((EJ))<#T[BC*7[
a9,)1-0=uh:o#u,_jXC9>!/mQ3h2257=#/z%.*S!5)*[ 0
oS2f0) (==JW%nPlyb+3P*\hP7GD<RAJzJr)*[12[G[t25a:Z$yjP6
:A30q+HSV2[,g(w*\:(74T'y7*p7g[-/Z
$\%<(*[bH7Xj+(/1(OXjw.x *=j+I>/1:PxJ)*/ 2m%3=-:B+)E<6((Z
$M%-(*ubJ5<j+(/1(=X-wr5 *9!-LC*\:;7$f3)\hZ=R+(/1:P0.pw6
:M[=q6wEHE0xJ+(/25Pb#$ )%-7E<_(:Xi:%Q,(/xAJ1q+H/1hs$yQ
$9$'G_jX(/1V;Xvw%x$*7!Vle*\:*7*22)1-p=#2f*-aY=8
_:377YX#$T) 2mdqj9!%v$0:((EF+L
T<=U)v2,,q+:dizy=#mI)\+zeUJ(/1:p0.u)6
:2,u\(M9ilyx#=F=ah$,x((6
:l,#qp:R4:YJ3X#sx4\xq+:R4;YX8
_I0=*p7%![)12,R0((9iM[_Jx([/Y([
aMRKa:$,[+-/b:p=5Jp9C;p_jwF5gUyx8
_I5GuYX#=;%04YBj+:d6 /Uq+:R4't_jq
$d4'T_JWF47hyx#M.x *P[
+)+%02/-;pP$Z
[z0\;Y
e4Z68t29k70
*.END
