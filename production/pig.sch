v 20110115 2
C 47000 44100 1 0 0 atmega168pa.sym
{
T 47300 49500 5 10 1 1 0 0 1
footprint=atmega328_combo.fp
T 51100 49500 5 10 1 1 0 0 1
refdes=U1
}
C 45200 53300 1 0 0 icsp.sym
{
T 45400 54100 5 10 1 1 0 0 1
footprint=icsp
T 46600 54100 5 10 1 1 0 0 1
refdes=CONN1
}
C 45800 51100 1 0 0 battery-1.sym
{
T 46100 52000 5 10 0 0 0 0 1
device=BATTERY
T 46100 51600 5 10 1 1 0 0 1
refdes=B1
T 46100 52400 5 10 0 0 0 0 1
symversion=0.1
T 46000 51100 5 10 0 1 0 0 1
footprint=CR2032-BAT-HLD.fp
}
C 46800 51100 1 90 0 ground.sym
C 45800 51200 1 0 1 output-2.sym
{
T 44900 51400 5 10 0 0 0 6 1
net=Vcc:1
T 45600 51900 5 10 0 0 0 6 1
device=none
T 44900 51300 5 10 1 1 0 7 1
value=Vcc
}
C 53000 47700 1 0 1 input-2.sym
{
T 53000 47900 5 10 0 0 0 6 1
net=Vcc:1
T 52400 48400 5 10 0 0 0 6 1
device=none
T 52500 47800 5 10 1 1 0 1 1
value=Vcc
}
C 53000 47500 1 0 1 input-2.sym
{
T 53000 47700 5 10 0 0 0 6 1
net=Vcc:1
T 52400 48200 5 10 0 0 0 6 1
device=none
T 52500 47600 5 10 1 1 0 1 1
value=Vcc
}
C 53000 47300 1 0 1 input-2.sym
{
T 53000 47500 5 10 0 0 0 6 1
net=Vcc:1
T 52400 48000 5 10 0 0 0 6 1
device=none
T 52500 47400 5 10 1 1 0 1 1
value=Vcc
}
C 52200 48200 1 90 0 ground.sym
N 51900 48400 51600 48400 4
N 51800 48000 51800 48400 4
N 51800 48200 51600 48200 4
N 51800 48000 51600 48000 4
C 53500 52800 1 0 0 superbutton.sym
{
T 54300 54000 5 10 1 1 0 0 1
refdes=S1
T 53600 53600 5 10 0 1 0 0 1
footprint=SuperButton
}
C 53100 57700 1 270 0 resistor-1.sym
{
T 53500 57400 5 10 0 0 270 0 1
device=RESISTOR
T 52800 57100 5 10 1 1 0 0 1
refdes=R1
T 53300 57100 5 10 1 1 0 0 1
value=10k
T 53100 57700 5 10 0 1 0 0 1
footprint=0805
}
C 53200 57500 1 0 0 capacitor-1.sym
{
T 53400 58200 5 10 0 0 0 0 1
device=CAPACITOR
T 53400 58000 5 10 1 1 0 0 1
refdes=C1
T 53400 58400 5 10 0 0 0 0 1
symversion=0.1
T 53800 58000 5 10 1 1 0 0 1
value=10uF
T 53200 57500 5 10 0 1 0 0 1
footprint=0805
}
C 47000 44800 1 0 1 output-2.sym
{
T 46100 45000 5 10 0 0 0 6 1
net=Sck:1
T 46800 45500 5 10 0 0 0 6 1
device=none
T 46100 44900 5 10 1 1 0 7 1
value=Sck
}
C 47000 45000 1 0 1 output-2.sym
{
T 46100 45200 5 10 0 0 0 6 1
net=Miso:1
T 46800 45700 5 10 0 0 0 6 1
device=none
T 46100 45100 5 10 1 1 0 7 1
value=Miso
}
C 47000 45200 1 0 1 output-2.sym
{
T 46100 45400 5 10 0 0 0 6 1
net=Mosi:1
T 46800 45900 5 10 0 0 0 6 1
device=none
T 46100 45300 5 10 1 1 0 7 1
value=Mosi
}
C 48800 53800 1 0 1 input-2.sym
{
T 48800 54000 5 10 0 0 0 6 1
net=Vcc:1
T 48200 54500 5 10 0 0 0 6 1
device=none
T 48300 53900 5 10 1 1 0 1 1
value=Vcc
}
C 47400 53200 1 0 0 ground.sym
N 47600 53500 47400 53500 4
C 48800 53600 1 0 1 input-2.sym
{
T 48800 53800 5 10 0 0 0 6 1
net=Mosi:1
T 48200 54300 5 10 0 0 0 6 1
device=none
T 48300 53700 5 10 1 1 0 1 1
value=Mosi
}
C 43800 53800 1 0 0 input-2.sym
{
T 43800 54000 5 10 0 0 0 0 1
net=Miso:1
T 44400 54500 5 10 0 0 0 0 1
device=none
T 44300 53900 5 10 1 1 0 7 1
value=Miso
}
C 43800 53600 1 0 0 input-2.sym
{
T 43800 53800 5 10 0 0 0 0 1
net=Sck:1
T 44400 54300 5 10 0 0 0 0 1
device=none
T 44300 53700 5 10 1 1 0 7 1
value=Sck
}
C 43800 53400 1 0 0 input-2.sym
{
T 43800 53600 5 10 0 0 0 0 1
net=Reset:1
T 44400 54100 5 10 0 0 0 0 1
device=none
T 44300 53500 5 10 1 1 0 7 1
value=Reset
}
C 47000 46200 1 0 1 output-2.sym
{
T 46100 46400 5 10 0 0 0 6 1
net=Reset:1
T 46800 46900 5 10 0 0 0 6 1
device=none
T 46100 46300 5 10 1 1 0 7 1
value=Reset
}
C 51800 57600 1 0 0 input-2.sym
{
T 51800 57800 5 10 0 0 0 0 1
net=Reset:1
T 52400 58300 5 10 0 0 0 0 1
device=none
T 52300 57700 5 10 1 1 0 7 1
value=Reset
}
C 53100 55400 1 270 1 input-2.sym
{
T 53300 55400 5 10 0 0 270 6 1
net=Vcc:1
T 53800 56000 5 10 0 0 270 6 1
device=none
T 53400 56200 5 10 1 1 0 1 1
value=Vcc
}
C 55500 57600 1 0 1 input-2.sym
{
T 55500 57800 5 10 0 0 0 6 1
net=Serial_reset:1
T 54900 58300 5 10 0 0 0 6 1
device=none
T 55000 57700 5 10 1 1 0 1 1
value=Serial_reset
}
C 44600 55500 1 0 0 connector6-1.sym
{
T 46400 57300 5 10 0 0 0 0 1
device=CONNECTOR_6
T 44700 57500 5 10 1 1 0 0 1
refdes=CONN2
T 44900 57200 5 10 0 1 0 0 1
footprint=ftdi
}
C 46300 55600 1 0 0 output-2.sym
{
T 47200 55800 5 10 0 0 0 0 1
net=Serial_reset:1
T 46500 56300 5 10 0 0 0 0 1
device=none
T 47200 55700 5 10 1 1 0 1 1
value=Serial_reset
}
C 47000 49100 1 0 1 output-2.sym
{
T 46100 49300 5 10 0 0 0 6 1
net=Uart_Rx:1
T 46800 49800 5 10 0 0 0 6 1
device=none
T 46100 49200 5 10 1 1 0 7 1
value=Uart_Rx
}
C 47000 48900 1 0 1 output-2.sym
{
T 46100 49100 5 10 0 0 0 6 1
net=Uart_Tx:1
T 46800 49600 5 10 0 0 0 6 1
device=none
T 46100 49000 5 10 1 1 0 7 1
value=Uart_Tx
}
C 47700 56200 1 0 1 input-2.sym
{
T 47700 56400 5 10 0 0 0 6 1
net=Uart_Rx:1
T 47100 56900 5 10 0 0 0 6 1
device=none
T 47200 56300 5 10 1 1 0 1 1
value=Uart_Rx
}
C 47700 55900 1 0 1 input-2.sym
{
T 47700 56100 5 10 0 0 0 6 1
net=Uart_Tx:1
T 47100 56600 5 10 0 0 0 6 1
device=none
T 47200 56000 5 10 1 1 0 1 1
value=Uart_Tx
}
C 47200 57000 1 90 0 ground.sym
N 46900 57200 46300 57200 4
N 46700 57200 46700 56900 4
N 46700 56900 46300 56900 4
C 46300 56500 1 0 0 output-2.sym
{
T 47200 56700 5 10 0 0 0 0 1
net=Vcc:1
T 46500 57200 5 10 0 0 0 0 1
device=none
T 47200 56600 5 10 1 1 0 1 1
value=Vcc
}
C 54100 51000 1 0 1 led-1.sym
{
T 53300 51600 5 10 0 0 0 6 1
device=LED
T 53300 51400 5 10 1 1 0 6 1
refdes=LED1
T 53300 51800 5 10 0 0 0 6 1
symversion=0.1
T 54000 51300 5 10 0 1 0 0 1
footprint=0805
}
C 46300 44000 1 0 0 crystal-1.sym
{
T 46500 44500 5 10 0 0 0 0 1
device=CRYSTAL
T 46500 44300 5 10 1 1 0 0 1
refdes=U2
T 46500 44700 5 10 0 0 0 0 1
symversion=0.1
T 46200 43800 5 10 1 1 0 0 1
value=32.768khz
T 46700 44000 5 10 0 1 0 0 1
footprint=ABS07crystal
}
N 47000 44700 46300 44700 4
N 46300 44700 46300 44100 4
N 47000 44500 47000 44100 4
C 47000 48700 1 0 1 output-2.sym
{
T 46100 48900 5 10 0 0 0 6 1
net=Button:1
T 46800 49400 5 10 0 0 0 6 1
device=none
T 46100 48800 5 10 1 1 0 7 1
value=Button
}
C 51300 53700 1 0 0 input-2.sym
{
T 51300 53900 5 10 0 0 0 0 1
net=Button:1
T 51900 54400 5 10 0 0 0 0 1
device=none
T 51800 53800 5 10 1 1 0 7 1
value=Button
}
N 52700 53800 53500 53800 4
C 53000 53800 1 270 0 resistor-1.sym
{
T 53400 53500 5 10 0 0 270 0 1
device=RESISTOR
T 52700 53200 5 10 1 1 0 0 1
refdes=R2
T 53200 53200 5 10 1 1 0 0 1
value=10k
T 53000 53800 5 10 0 1 0 0 1
footprint=0805
}
C 52900 52600 1 0 0 ground.sym
C 56000 53700 1 0 1 input-2.sym
{
T 56000 53900 5 10 0 0 0 6 1
net=Vcc:1
T 55400 54400 5 10 0 0 0 6 1
device=none
T 55500 53800 5 10 1 1 0 1 1
value=Vcc
}
C 47000 48500 1 0 1 output-2.sym
{
T 46100 48700 5 10 0 0 0 6 1
net=Tip:1
T 46800 49200 5 10 0 0 0 6 1
device=none
T 46100 48600 5 10 1 1 0 7 1
value=Tip
}
C 59400 53400 1 0 0 input-2.sym
{
T 59400 53600 5 10 0 0 0 0 1
net=Tip:1
T 60000 54100 5 10 0 0 0 0 1
device=none
T 59900 53500 5 10 1 1 0 7 1
value=Tip
}
C 61200 52300 1 0 0 ground.sym
C 61300 53500 1 270 0 resistor-1.sym
{
T 61700 53200 5 10 0 0 270 0 1
device=RESISTOR
T 61000 52900 5 10 1 1 0 0 1
refdes=R3
T 61500 52900 5 10 1 1 0 0 1
value=10k
T 61300 53500 5 10 0 1 0 0 1
footprint=0805
}
N 60800 53500 61900 53500 4
C 61300 54400 1 270 0 resistor-1.sym
{
T 61700 54100 5 10 0 0 270 0 1
device=RESISTOR
T 61000 53800 5 10 1 1 0 0 1
refdes=R4
T 61500 53800 5 10 1 1 0 0 1
value=10k
T 61300 54400 5 10 0 1 0 0 1
footprint=0805
}
C 61500 55800 1 90 1 input-2.sym
{
T 61300 55800 5 10 0 0 90 6 1
net=Vcc:1
T 60800 55200 5 10 0 0 90 6 1
device=none
T 61900 54900 5 10 1 1 180 1 1
value=Vcc
}
C 61900 53300 1 0 0 capacitor-1.sym
{
T 62100 54000 5 10 0 0 0 0 1
device=CAPACITOR
T 62100 53800 5 10 1 1 0 0 1
refdes=C2
T 62100 54200 5 10 0 0 0 0 1
symversion=0.1
T 62500 53800 5 10 1 1 0 0 1
value=100uF
T 61900 53300 5 10 0 1 0 0 1
footprint=0805
}
C 64900 53000 1 0 1 connector3-1.sym
{
T 63100 53900 5 10 0 0 0 6 1
device=CONNECTOR_3
T 64900 54100 5 10 1 1 0 6 1
refdes=CONN3
}
N 63200 53500 62800 53500 4
C 62900 53400 1 270 0 ground.sym
C 51900 51100 1 0 0 resistor-1.sym
{
T 52200 51500 5 10 0 0 0 0 1
device=RESISTOR
T 52200 51500 5 10 1 1 180 0 1
refdes=R5
T 52700 51500 5 10 1 1 180 0 1
value=330
T 51900 51100 5 10 0 1 0 0 1
footprint=0805
}
N 52800 51200 53200 51200 4
C 51600 51000 1 270 1 ground.sym
C 47000 48300 1 0 1 output-2.sym
{
T 46100 48500 5 10 0 0 0 6 1
net=Indicator:1
T 46800 49000 5 10 0 0 0 6 1
device=none
T 46100 48400 5 10 1 1 0 7 1
value=Indicator
}
C 55500 51100 1 0 1 input-2.sym
{
T 55500 51300 5 10 0 0 0 6 1
net=Indicator:1
T 54900 51800 5 10 0 0 0 6 1
device=none
T 55000 51200 5 10 1 1 0 1 1
value=Indicator
}
C 57100 46500 1 0 0 LY091WG15.sym
{
T 57400 46500 5 10 1 1 0 0 1
footprint=LY091WG15
T 58500 49200 5 10 1 1 0 0 1
refdes=DISP1
}
C 59300 48300 1 0 0 capacitor-1.sym
{
T 59500 49000 5 10 0 0 0 0 1
device=CAPACITOR
T 59500 48800 5 10 1 1 0 0 1
refdes=C3
T 59500 49200 5 10 0 0 0 0 1
symversion=0.1
T 59900 48800 5 10 1 1 0 0 1
value=1uF
T 59300 48300 5 10 0 1 0 0 1
footprint=0805
}
C 59300 49200 1 0 0 capacitor-1.sym
{
T 59500 49900 5 10 0 0 0 0 1
device=CAPACITOR
T 59500 49700 5 10 1 1 0 0 1
refdes=C4
T 59500 50100 5 10 0 0 0 0 1
symversion=0.1
T 59900 49700 5 10 1 1 0 0 1
value=1uF
T 59300 49200 5 10 0 1 0 0 1
footprint=0805
}
N 59300 48500 59000 48500 4
N 59000 48300 59400 48300 4
N 59400 48300 59400 48000 4
N 59400 48000 60200 48000 4
N 60200 48000 60200 48500 4
N 59000 48700 59300 48700 4
N 59300 48700 59300 49100 4
N 59300 49100 60200 49100 4
N 60200 49100 60200 49400 4
N 59300 49400 59000 49400 4
N 59000 49400 59000 48900 4
C 64400 48400 1 0 1 resistor-1.sym
{
T 64100 48800 5 10 0 0 0 6 1
device=RESISTOR
T 64100 48800 5 10 1 1 180 6 1
refdes=R6
T 63600 48800 5 10 1 1 180 6 1
value=10K
T 64400 48400 5 10 0 1 0 0 1
footprint=0805
}
C 62800 50400 1 270 0 input-2.sym
{
T 63000 50400 5 10 0 0 90 8 1
net=Vcc:1
T 63500 49800 5 10 0 0 90 8 1
device=none
T 62400 49600 5 10 1 1 180 7 1
value=Vcc
}
C 65800 48400 1 0 1 input-2.sym
{
T 65800 48600 5 10 0 0 0 6 1
net=Disp_on:1
T 65200 49100 5 10 0 0 0 6 1
device=none
T 65300 48500 5 10 1 1 0 1 1
value=Disp_on
}
C 47000 45800 1 0 1 output-2.sym
{
T 46100 46000 5 10 0 0 0 6 1
net=Disp_on:1
T 46800 46500 5 10 0 0 0 6 1
device=none
T 46100 45900 5 10 1 1 0 7 1
value=Disp_on
}
C 62500 47000 1 90 0 capacitor-1.sym
{
T 61800 47200 5 10 0 0 90 0 1
device=CAPACITOR
T 62200 47700 5 10 1 1 180 0 1
refdes=C5
T 61600 47200 5 10 0 0 90 0 1
symversion=0.1
T 62800 47300 5 10 1 1 180 0 1
value=1uF
T 62500 47000 5 10 0 1 0 0 1
footprint=0805
}
C 61300 47700 1 270 0 capacitor-1.sym
{
T 62000 47500 5 10 0 0 270 0 1
device=CAPACITOR
T 61200 47400 5 10 1 1 0 0 1
refdes=C6
T 62200 47500 5 10 0 0 270 0 1
symversion=0.1
T 61600 47000 5 10 1 1 0 0 1
value=1uF
T 61300 47700 5 10 0 1 0 0 1
footprint=0805
}
N 59000 47900 62900 47900 4
N 62900 48000 62900 47900 4
C 62500 46700 1 0 1 ground.sym
C 56900 47100 1 270 1 ground.sym
N 59000 47700 61500 47700 4
N 61500 47700 61500 47900 4
C 61700 46500 1 0 1 ground.sym
C 55800 48800 1 0 0 input-2.sym
{
T 55800 49000 5 10 0 0 0 0 1
net=Sck:1
T 56400 49500 5 10 0 0 0 0 1
device=none
T 56300 48900 5 10 1 1 0 7 1
value=Sck
}
C 55800 48600 1 0 0 input-2.sym
{
T 55800 48800 5 10 0 0 0 0 1
net=Mosi:1
T 56400 49300 5 10 0 0 0 0 1
device=none
T 56300 48700 5 10 1 1 0 7 1
value=Mosi
}
C 55800 48000 1 0 0 input-2.sym
{
T 55800 48200 5 10 0 0 0 0 1
net=Miso:1
T 56400 48700 5 10 0 0 0 0 1
device=none
T 56300 48100 5 10 1 1 0 7 1
value=Miso
}
C 47000 45400 1 0 1 output-2.sym
{
T 46100 45600 5 10 0 0 0 6 1
net=CS:1
T 46800 46100 5 10 0 0 0 6 1
device=none
T 46100 45500 5 10 1 1 0 7 1
value=CS
}
C 55800 48400 1 0 0 input-2.sym
{
T 55800 48600 5 10 0 0 0 0 1
net=CS:1
T 56400 49100 5 10 0 0 0 0 1
device=none
T 56300 48500 5 10 1 1 0 7 1
value=CS
}
C 47000 45600 1 0 1 output-2.sym
{
T 46100 45800 5 10 0 0 0 6 1
net=Disp_reset:1
T 46800 46300 5 10 0 0 0 6 1
device=none
T 46100 45700 5 10 1 1 0 7 1
value=Disp_reset
}
C 55800 48200 1 0 0 input-2.sym
{
T 55800 48400 5 10 0 0 0 0 1
net=Disp_reset:1
T 56400 48900 5 10 0 0 0 0 1
device=none
T 56300 48300 5 10 1 1 0 7 1
value=Disp_reset
}
C 58900 45600 1 270 1 resistor-1.sym
{
T 59300 45900 5 10 0 0 270 6 1
device=RESISTOR
T 58600 46300 5 10 1 1 180 6 1
refdes=R7
T 59100 45900 5 10 1 1 180 6 1
value=390K
T 58900 45600 5 10 0 1 0 0 1
footprint=0805
}
N 59000 46500 59000 47100 4
C 59200 45300 1 0 1 ground.sym
C 60600 46500 1 270 0 capacitor-1.sym
{
T 61300 46300 5 10 0 0 270 0 1
device=CAPACITOR
T 60500 46200 5 10 1 1 0 0 1
refdes=C7
T 61500 46300 5 10 0 0 270 0 1
symversion=0.1
T 60900 45800 5 10 1 1 0 0 1
value=2.2uF
T 60600 46500 5 10 0 1 0 0 1
footprint=0805
}
C 59700 46500 1 270 0 capacitor-1.sym
{
T 60400 46300 5 10 0 0 270 0 1
device=CAPACITOR
T 59600 46200 5 10 1 1 0 0 1
refdes=C8
T 60600 46300 5 10 0 0 270 0 1
symversion=0.1
T 60000 45800 5 10 1 1 0 0 1
value=4.7uF
T 59700 46500 5 10 0 1 0 0 1
footprint=0805
}
C 61000 45300 1 0 1 ground.sym
C 60100 45300 1 0 1 ground.sym
N 59000 47500 60800 47500 4
N 60800 47500 60800 46500 4
N 59000 47300 59900 47300 4
N 59900 47300 59900 46500 4
C 61200 55900 1 0 0 ground.sym
C 61300 57100 1 270 0 resistor-1.sym
{
T 61700 56800 5 10 0 0 270 0 1
device=RESISTOR
T 61000 56500 5 10 1 1 0 0 1
refdes=R8
T 61500 56500 5 10 1 1 0 0 1
value=10k
T 61300 57100 5 10 0 1 0 0 1
footprint=0805
}
N 60800 57100 62100 57100 4
C 61300 58000 1 270 0 resistor-1.sym
{
T 61700 57700 5 10 0 0 270 0 1
device=RESISTOR
T 61000 57400 5 10 1 1 0 0 1
refdes=R9
T 61500 57400 5 10 1 1 0 0 1
value=10k
T 61300 58000 5 10 0 1 0 0 1
footprint=0805
}
C 61500 59400 1 90 1 input-2.sym
{
T 61300 59400 5 10 0 0 90 6 1
net=Vcc:1
T 60800 58800 5 10 0 0 90 6 1
device=none
T 61900 58500 5 10 1 1 180 1 1
value=Vcc
}
C 59400 57000 1 0 0 input-2.sym
{
T 59400 57200 5 10 0 0 0 0 1
net=Reset:1
T 60000 57700 5 10 0 0 0 0 1
device=none
T 59900 57100 5 10 1 1 0 7 1
value=Reset
}
C 63000 57300 1 180 0 capacitor-2.sym
{
T 62800 56600 5 10 0 0 180 0 1
device=POLARIZED_CAPACITOR
T 62400 57400 5 10 1 1 180 0 1
refdes=C9
T 62800 56400 5 10 0 0 180 0 1
symversion=0.1
T 62700 57200 5 10 1 1 0 0 1
value=330uF
}
N 63200 53800 63200 57100 4
N 63200 57100 63000 57100 4
C 42900 42800 1 0 0 title-A2.sym
C 63500 49000 1 180 0 pnp-3.sym
{
T 62600 48500 5 10 0 0 180 0 1
device=PNP_TRANSISTOR
T 62600 48500 5 10 1 1 180 0 1
refdes=Q1
T 60900 49400 5 10 0 1 0 0 1
footprint=SOT23
}
