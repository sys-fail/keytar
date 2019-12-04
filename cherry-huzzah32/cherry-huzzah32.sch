EESchema Schematic File Version 4
LIBS:cherry-huzzah32-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	650  1000 700  1000
Wire Wire Line
	650  2500 700  2500
Wire Wire Line
	650  2500 650  2000
Wire Wire Line
	650  2000 700  2000
Connection ~ 650  2000
Wire Wire Line
	650  2000 650  1500
Wire Wire Line
	650  1500 700  1500
Connection ~ 650  1500
Wire Wire Line
	650  1500 650  1000
Wire Wire Line
	650  2500 650  3000
Connection ~ 650  2500
Wire Wire Line
	1100 1000 1150 1000
Wire Wire Line
	1700 1000 1750 1000
Wire Wire Line
	2300 1000 2350 1000
Wire Wire Line
	2950 1000 2950 1150
Wire Wire Line
	2350 1000 2350 1150
Wire Wire Line
	1750 1000 1750 1150
Wire Wire Line
	1150 1000 1150 1150
Wire Wire Line
	1100 1500 1150 1500
Wire Wire Line
	1700 1500 1750 1500
Wire Wire Line
	2300 1500 2350 1500
Wire Wire Line
	2900 1500 2950 1500
Connection ~ 2950 1650
Wire Wire Line
	2950 1500 2950 1650
Wire Wire Line
	2350 1500 2350 1650
Wire Wire Line
	1150 1500 1150 1650
Wire Wire Line
	1100 2000 1150 2000
Wire Wire Line
	1700 2000 1750 2000
Wire Wire Line
	2300 2000 2350 2000
Wire Wire Line
	2900 2000 2950 2000
Wire Wire Line
	2950 2000 2950 2150
Wire Wire Line
	1750 2000 1750 2150
Wire Wire Line
	1150 2000 1150 2150
Wire Wire Line
	1100 2500 1150 2500
Wire Wire Line
	1700 2500 1750 2500
Wire Wire Line
	2300 2500 2350 2500
Wire Wire Line
	2900 2500 2950 2500
Wire Wire Line
	2950 2500 2950 2650
Wire Wire Line
	1750 2500 1750 2650
Wire Wire Line
	1250 1000 1300 1000
Wire Wire Line
	1250 2500 1300 2500
Wire Wire Line
	1250 2000 1300 2000
Connection ~ 1250 2000
Wire Wire Line
	1250 1500 1300 1500
Connection ~ 1250 1500
Wire Wire Line
	1850 1000 1900 1000
Wire Wire Line
	1850 2500 1900 2500
Wire Wire Line
	1850 2000 1900 2000
Wire Wire Line
	1850 1500 1900 1500
Wire Wire Line
	2450 1000 2500 1000
Wire Wire Line
	2450 2500 2500 2500
Wire Wire Line
	2450 2000 2500 2000
Wire Wire Line
	2450 1500 2500 1500
Connection ~ 2450 2500
Text Notes 700  2950 0    50   ~ 0
27
Text Notes 1300 2950 0    50   ~ 0
33\n
Text Notes 1900 2950 0    50   ~ 0
15
Text Notes 3000 1100 0    50   ~ 0
26
Text Notes 3000 1600 0    50   ~ 0
25
Text Notes 3000 2100 0    50   ~ 0
4
Text Notes 3000 2600 0    50   ~ 0
21
Wire Wire Line
	2950 1150 3600 1150
Wire Wire Line
	2950 1650 3600 1650
Wire Wire Line
	2950 2150 3600 2150
Wire Wire Line
	2950 2650 3600 2650
Text Label 3150 1150 0    50   ~ 0
MR1
Text Label 3150 1650 0    50   ~ 0
MR2
Text Label 3150 2150 0    50   ~ 0
MR3
Text Label 3150 2650 0    50   ~ 0
MR4
Wire Wire Line
	650  3000 1050 3000
Wire Wire Line
	1650 3000 1250 3000
Text Label 850  3000 0    50   ~ 0
MC1
Text Label 1450 3000 0    50   ~ 0
MC2
Text Label 2050 3000 0    50   ~ 0
MC3
Text Label 2700 3000 0    50   ~ 0
MC4
$Comp
L adafruit_featherwing:adafruit_feather_huzzah32 U1
U 1 1 5DCE1375
P 7350 1400
F 0 "U1" H 7600 2065 50  0000 C CNN
F 1 "adafruit_feather_huzzah32" H 7600 1974 50  0000 C CNN
F 2 "cherry-huzzah32:Adafruit_Feather_HUZZAH32" H 7350 1400 50  0001 C CNN
F 3 "https://learn.adafruit.com/adafruit-huzzah32-esp32-feather/downloads" H 7350 1400 50  0001 C CNN
	1    7350 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 1600 6500 1600
Wire Wire Line
	6500 1700 6950 1700
Wire Wire Line
	8250 1900 8650 1900
Wire Wire Line
	8650 2000 8250 2000
Wire Wire Line
	8650 2100 8250 2100
Wire Wire Line
	8650 2200 8250 2200
Wire Wire Line
	6950 1800 6500 1800
Wire Wire Line
	6950 1900 6500 1900
Wire Wire Line
	6950 2000 6500 2000
Text Label 6550 1600 0    50   ~ 0
MR1
Text Label 6550 1700 0    50   ~ 0
MR2
Text Label 6550 1800 0    50   ~ 0
MR3
Text Label 6550 1900 0    50   ~ 0
MR4
Text Label 8400 1900 0    50   ~ 0
MC1
Text Label 8400 2000 0    50   ~ 0
MC2
Text Label 8400 2100 0    50   ~ 0
MC3
Text Label 8400 2200 0    50   ~ 0
MC4
Text Label 6550 2000 0    50   ~ 0
SCK
Text Label 6550 2100 0    50   ~ 0
MOSI
Wire Wire Line
	6950 2100 6500 2100
Wire Wire Line
	6950 1300 6350 1300
Wire Wire Line
	6350 1300 6350 1350
$Comp
L power:GND #PWR02
U 1 1 5DD004D2
P 6350 1350
F 0 "#PWR02" H 6350 1100 50  0001 C CNN
F 1 "GND" H 6355 1177 50  0000 C CNN
F 2 "" H 6350 1350 50  0001 C CNN
F 3 "" H 6350 1350 50  0001 C CNN
	1    6350 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 1100 6350 1100
Wire Wire Line
	6350 1100 6350 1050
$Comp
L power:+3.3V #PWR01
U 1 1 5DD05FDF
P 6350 1050
F 0 "#PWR01" H 6350 900 50  0001 C CNN
F 1 "+3.3V" H 6365 1223 50  0000 C CNN
F 2 "" H 6350 1050 50  0001 C CNN
F 3 "" H 6350 1050 50  0001 C CNN
	1    6350 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 2200 6500 2200
Wire Wire Line
	6500 2300 6950 2300
Wire Wire Line
	6500 2400 6950 2400
$Comp
L Connector_Generic:Conn_01x07 J1
U 1 1 5DD173D7
P 4850 2350
F 0 "J1" H 4800 1950 50  0000 L CNN
F 1 "Conn_01x07" H 4450 1850 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 4850 2350 50  0001 C CNN
F 3 "~" H 4850 2350 50  0001 C CNN
	1    4850 2350
	-1   0    0    1   
$EndComp
Text Notes 4700 2700 2    50   ~ 0
GND\n
Text Notes 4700 2600 2    50   ~ 0
VCC
Text Notes 4700 2500 2    50   ~ 0
D0
Text Notes 4700 2400 2    50   ~ 0
D1\n
Text Notes 4700 2300 2    50   ~ 0
Reset AL
Text Notes 4700 2200 2    50   ~ 0
Data/Command
Text Notes 4700 2100 2    50   ~ 0
Chip Select AL
$Comp
L power:GND #PWR05
U 1 1 5DD2C2E9
P 5900 2650
F 0 "#PWR05" H 5900 2400 50  0001 C CNN
F 1 "GND" V 5905 2522 50  0000 R CNN
F 2 "" H 5900 2650 50  0001 C CNN
F 3 "" H 5900 2650 50  0001 C CNN
	1    5900 2650
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR03
U 1 1 5DD2BABB
P 5900 2250
F 0 "#PWR03" H 5900 2100 50  0001 C CNN
F 1 "+3.3V" V 5915 2378 50  0000 L CNN
F 2 "" H 5900 2250 50  0001 C CNN
F 3 "" H 5900 2250 50  0001 C CNN
	1    5900 2250
	0    1    1    0   
$EndComp
Text Label 5550 2150 0    50   ~ 0
MISO
Text Label 6550 2200 0    50   ~ 0
MISO
Text Label 6550 2300 0    50   ~ 0
RX
Text Label 6550 2400 0    50   ~ 0
TX
$Comp
L power:+3.3V #PWR04
U 1 1 5DDB19FB
P 5900 2550
F 0 "#PWR04" H 5900 2400 50  0001 C CNN
F 1 "+3.3V" V 5915 2678 50  0000 L CNN
F 2 "" H 5900 2550 50  0001 C CNN
F 3 "" H 5900 2550 50  0001 C CNN
	1    5900 2550
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_2_Bridged JP7
U 1 1 5DDB219B
P 5350 2050
F 0 "JP7" H 5100 2100 50  0000 C CNN
F 1 "SolderJumper_2_Bridged" H 5350 2164 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged2Bar_RoundedPad1.0x1.5mm" H 5350 2050 50  0001 C CNN
F 3 "~" H 5350 2050 50  0001 C CNN
	1    5350 2050
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Bridged JP6
U 1 1 5DDB28EE
P 5350 2150
F 0 "JP6" H 5100 2200 50  0000 C CNN
F 1 "SolderJumper_2_Bridged" H 5350 2264 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged2Bar_RoundedPad1.0x1.5mm" H 5350 2150 50  0001 C CNN
F 3 "~" H 5350 2150 50  0001 C CNN
	1    5350 2150
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Bridged JP5
U 1 1 5DDB299E
P 5350 2250
F 0 "JP5" H 5100 2300 50  0000 C CNN
F 1 "SolderJumper_2_Bridged" H 5350 2364 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged2Bar_RoundedPad1.0x1.5mm" H 5350 2250 50  0001 C CNN
F 3 "~" H 5350 2250 50  0001 C CNN
	1    5350 2250
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Bridged JP4
U 1 1 5DDB2A2D
P 5350 2350
F 0 "JP4" H 5100 2400 50  0000 C CNN
F 1 "SolderJumper_2_Bridged" H 5350 2464 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged2Bar_RoundedPad1.0x1.5mm" H 5350 2350 50  0001 C CNN
F 3 "~" H 5350 2350 50  0001 C CNN
	1    5350 2350
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Bridged JP3
U 1 1 5DDB2ABC
P 5350 2450
F 0 "JP3" H 5100 2500 50  0000 C CNN
F 1 "SolderJumper_2_Bridged" H 5350 2564 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged2Bar_RoundedPad1.0x1.5mm" H 5350 2450 50  0001 C CNN
F 3 "~" H 5350 2450 50  0001 C CNN
	1    5350 2450
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Bridged JP2
U 1 1 5DDB2B4B
P 5350 2550
F 0 "JP2" H 5100 2600 50  0000 C CNN
F 1 "SolderJumper_2_Bridged" H 5350 2664 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged2Bar_RoundedPad1.0x1.5mm" H 5350 2550 50  0001 C CNN
F 3 "~" H 5350 2550 50  0001 C CNN
	1    5350 2550
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Bridged JP1
U 1 1 5DDB2BDA
P 5350 2650
F 0 "JP1" H 5100 2700 50  0000 C CNN
F 1 "SolderJumper_2_Bridged" H 5350 2764 50  0001 C CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Bridged2Bar_RoundedPad1.0x1.5mm" H 5350 2650 50  0001 C CNN
F 3 "~" H 5350 2650 50  0001 C CNN
	1    5350 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2650 5200 2650
Wire Wire Line
	5050 2550 5200 2550
Wire Wire Line
	5200 2450 5050 2450
Wire Wire Line
	5050 2350 5200 2350
Wire Wire Line
	5200 2250 5050 2250
Wire Wire Line
	5050 2150 5200 2150
Wire Wire Line
	5200 2050 5050 2050
Text Label 5550 2450 0    50   ~ 0
SCK
Text Label 5550 2350 0    50   ~ 0
MOSI
Wire Wire Line
	5500 2350 5900 2350
Wire Wire Line
	5500 2150 5900 2150
Wire Wire Line
	8250 2300 8650 2300
Text Label 8400 2300 0    50   ~ 0
CS_SSD
Text Label 5550 2050 0    50   ~ 0
CS_SSD
Wire Wire Line
	5900 2250 5500 2250
Wire Wire Line
	5500 2550 5900 2550
Wire Wire Line
	5900 2650 5500 2650
Wire Wire Line
	5500 2050 5900 2050
Wire Wire Line
	5500 2450 5900 2450
$Comp
L Switch:SW_Push SW1
U 1 1 5DE39CFE
P 900 1000
F 0 "SW1" H 900 1285 50  0000 C CNN
F 1 "SW_Push" H 900 1194 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 900 1200 50  0001 C CNN
F 3 "~" H 900 1200 50  0001 C CNN
	1    900  1000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 5DE45A99
P 900 1500
F 0 "SW5" H 900 1785 50  0000 C CNN
F 1 "SW_Push" H 900 1694 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 900 1700 50  0001 C CNN
F 3 "~" H 900 1700 50  0001 C CNN
	1    900  1500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW9
U 1 1 5DE46A20
P 900 2000
F 0 "SW9" H 900 2285 50  0000 C CNN
F 1 "SW_Push" H 900 2194 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 900 2200 50  0001 C CNN
F 3 "~" H 900 2200 50  0001 C CNN
	1    900  2000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW13
U 1 1 5DE47134
P 900 2500
F 0 "SW13" H 900 2785 50  0000 C CNN
F 1 "SW_Push" H 900 2694 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 900 2700 50  0001 C CNN
F 3 "~" H 900 2700 50  0001 C CNN
	1    900  2500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5DE6D0DF
P 1500 1000
F 0 "SW2" H 1500 1285 50  0000 C CNN
F 1 "SW_Push" H 1500 1194 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 1500 1200 50  0001 C CNN
F 3 "~" H 1500 1200 50  0001 C CNN
	1    1500 1000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5DE6D82C
P 2100 1000
F 0 "SW3" H 2100 1285 50  0000 C CNN
F 1 "SW_Push" H 2100 1194 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 2100 1200 50  0001 C CNN
F 3 "~" H 2100 1200 50  0001 C CNN
	1    2100 1000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 5DE6E01B
P 2700 1000
F 0 "SW4" H 2700 1285 50  0000 C CNN
F 1 "SW_Push" H 2700 1194 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 2700 1200 50  0001 C CNN
F 3 "~" H 2700 1200 50  0001 C CNN
	1    2700 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 1000 2950 1000
$Comp
L Switch:SW_Push SW6
U 1 1 5DE88786
P 1500 1500
F 0 "SW6" H 1500 1785 50  0000 C CNN
F 1 "SW_Push" H 1500 1694 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 1500 1700 50  0001 C CNN
F 3 "~" H 1500 1700 50  0001 C CNN
	1    1500 1500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW7
U 1 1 5DE8878C
P 2100 1500
F 0 "SW7" H 2100 1785 50  0000 C CNN
F 1 "SW_Push" H 2100 1694 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 2100 1700 50  0001 C CNN
F 3 "~" H 2100 1700 50  0001 C CNN
	1    2100 1500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW8
U 1 1 5DE88792
P 2700 1500
F 0 "SW8" H 2700 1785 50  0000 C CNN
F 1 "SW_Push" H 2700 1694 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 2700 1700 50  0001 C CNN
F 3 "~" H 2700 1700 50  0001 C CNN
	1    2700 1500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW10
U 1 1 5DE8D8C2
P 1500 2000
F 0 "SW10" H 1500 2285 50  0000 C CNN
F 1 "SW_Push" H 1500 2194 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 1500 2200 50  0001 C CNN
F 3 "~" H 1500 2200 50  0001 C CNN
	1    1500 2000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW11
U 1 1 5DE8D8C8
P 2100 2000
F 0 "SW11" H 2100 2285 50  0000 C CNN
F 1 "SW_Push" H 2100 2194 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 2100 2200 50  0001 C CNN
F 3 "~" H 2100 2200 50  0001 C CNN
	1    2100 2000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW12
U 1 1 5DE8D8CE
P 2700 2000
F 0 "SW12" H 2700 2285 50  0000 C CNN
F 1 "SW_Push" H 2700 2194 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 2700 2200 50  0001 C CNN
F 3 "~" H 2700 2200 50  0001 C CNN
	1    2700 2000
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW14
U 1 1 5DE92A98
P 1500 2500
F 0 "SW14" H 1500 2785 50  0000 C CNN
F 1 "SW_Push" H 1500 2694 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 1500 2700 50  0001 C CNN
F 3 "~" H 1500 2700 50  0001 C CNN
	1    1500 2500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW15
U 1 1 5DE92A9E
P 2100 2500
F 0 "SW15" H 2100 2785 50  0000 C CNN
F 1 "SW_Push" H 2100 2694 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 2100 2700 50  0001 C CNN
F 3 "~" H 2100 2700 50  0001 C CNN
	1    2100 2500
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW16
U 1 1 5DE92AA4
P 2700 2500
F 0 "SW16" H 2700 2785 50  0000 C CNN
F 1 "SW_Push" H 2700 2694 50  0000 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 2700 2700 50  0001 C CNN
F 3 "~" H 2700 2700 50  0001 C CNN
	1    2700 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 1500 1250 2000
Wire Wire Line
	1150 1650 1750 1650
Connection ~ 2350 1650
Wire Wire Line
	2350 1650 2950 1650
Wire Wire Line
	1750 1500 1750 1650
Connection ~ 1750 1650
Wire Wire Line
	1750 1650 2350 1650
Wire Wire Line
	2450 1500 2450 2000
Connection ~ 2450 1500
Wire Wire Line
	1850 2000 1850 2500
Wire Wire Line
	1250 2000 1250 2500
Wire Wire Line
	2450 2000 2450 2500
Connection ~ 2450 2000
Wire Wire Line
	2450 2500 2450 3000
Wire Wire Line
	1250 2500 1250 3000
Connection ~ 1250 2500
Wire Wire Line
	1850 2500 1850 3000
Wire Wire Line
	1850 3000 2250 3000
Connection ~ 1850 2500
Wire Wire Line
	1850 2000 1850 1500
Connection ~ 1850 2000
Connection ~ 1850 1500
Wire Wire Line
	1250 1000 1250 1500
Wire Wire Line
	1850 1000 1850 1500
Wire Wire Line
	2450 1000 2450 1500
Wire Wire Line
	2950 1150 2350 1150
Connection ~ 2950 1150
Wire Wire Line
	2350 1150 1750 1150
Connection ~ 2350 1150
Wire Wire Line
	1150 1150 1750 1150
Connection ~ 1750 1150
Wire Wire Line
	1150 2150 1750 2150
Wire Wire Line
	2350 2000 2350 2150
Wire Wire Line
	2350 2150 1750 2150
Connection ~ 1750 2150
Wire Wire Line
	2350 2150 2950 2150
Connection ~ 2350 2150
Connection ~ 2950 2150
Wire Wire Line
	1150 2500 1150 2650
Wire Wire Line
	1150 2650 1750 2650
Connection ~ 2950 2650
Connection ~ 1750 2650
Wire Wire Line
	1750 2650 2350 2650
Wire Wire Line
	2350 2500 2350 2650
Connection ~ 2350 2650
Wire Wire Line
	2350 2650 2950 2650
Text Notes 2500 2950 0    50   ~ 0
32
Wire Wire Line
	2450 3000 2900 3000
Text Notes 1250 3200 0    50   ~ 0
Columns are either output or tristated
Text Notes 3850 2200 1    50   ~ 0
Rows are inputs
NoConn ~ 8250 1400
NoConn ~ 8250 1500
NoConn ~ 8250 1600
NoConn ~ 8250 1700
NoConn ~ 8250 1800
NoConn ~ 8250 2400
NoConn ~ 8250 2500
NoConn ~ 6950 2500
NoConn ~ 6950 1500
NoConn ~ 6950 1400
NoConn ~ 6950 1000
$EndSCHEMATC
