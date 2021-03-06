EESchema Schematic File Version 4
LIBS:ecovapo2018-cache
EELAYER 26 0
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
$Comp
L arduino:Arduino_Mega2560_Shield XA1
U 1 1 5B9EB8B8
P 3300 3800
F 0 "XA1" H 3300 1420 60  0000 C CNN
F 1 "Arduino_Mega2560_Shield" H 3300 1314 60  0000 C CNN
F 2 "Arduino:Arduino_Mega2560_Shield" H 4000 6550 60  0001 C CNN
F 3 "https://store.arduino.cc/arduino-mega-2560-rev3" H 4000 6550 60  0001 C CNN
	1    3300 3800
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 M1
U 1 1 5B9EE836
P 6100 1700
F 0 "M1" H 6180 1742 50  0000 L CNN
F 1 "Conn_01x03" H 6180 1651 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 6100 1700 50  0001 C CNN
F 3 "~" H 6100 1700 50  0001 C CNN
	1    6100 1700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 M2
U 1 1 5B9EE938
P 6100 2150
F 0 "M2" H 6180 2192 50  0000 L CNN
F 1 "Conn_01x03" H 6180 2101 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 6100 2150 50  0001 C CNN
F 3 "~" H 6100 2150 50  0001 C CNN
	1    6100 2150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 S1
U 1 1 5B9EE995
P 6100 2600
F 0 "S1" H 6180 2642 50  0000 L CNN
F 1 "Conn_01x03" H 6180 2551 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 6100 2600 50  0001 C CNN
F 3 "~" H 6100 2600 50  0001 C CNN
	1    6100 2600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 S2
U 1 1 5B9EE9E9
P 6100 3050
F 0 "S2" H 6180 3092 50  0000 L CNN
F 1 "Conn_01x03" H 6180 3001 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 6100 3050 50  0001 C CNN
F 3 "~" H 6100 3050 50  0001 C CNN
	1    6100 3050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 S3
U 1 1 5B9EEA51
P 6100 3500
F 0 "S3" H 6180 3542 50  0000 L CNN
F 1 "Conn_01x03" H 6180 3451 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 6100 3500 50  0001 C CNN
F 3 "~" H 6100 3500 50  0001 C CNN
	1    6100 3500
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 S4
U 1 1 5B9EEB87
P 6100 3950
F 0 "S4" H 6180 3992 50  0000 L CNN
F 1 "Conn_01x03" H 6180 3901 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 6100 3950 50  0001 C CNN
F 3 "~" H 6100 3950 50  0001 C CNN
	1    6100 3950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 S5
U 1 1 5B9EEC30
P 6100 4400
F 0 "S5" H 6180 4442 50  0000 L CNN
F 1 "Conn_01x03" H 6180 4351 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 6100 4400 50  0001 C CNN
F 3 "~" H 6100 4400 50  0001 C CNN
	1    6100 4400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 S6
U 1 1 5B9EEC9A
P 6100 4850
F 0 "S6" H 6180 4892 50  0000 L CNN
F 1 "Conn_01x03" H 6180 4801 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x03_P2.00mm_Vertical" H 6100 4850 50  0001 C CNN
F 3 "~" H 6100 4850 50  0001 C CNN
	1    6100 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 1800 5700 1800
Wire Wire Line
	5700 1800 5700 2250
Wire Wire Line
	5700 4950 5900 4950
Wire Wire Line
	5900 2250 5700 2250
Connection ~ 5700 2250
Wire Wire Line
	5700 2250 5700 2700
Wire Wire Line
	5900 2700 5700 2700
Connection ~ 5700 2700
Wire Wire Line
	5700 2700 5700 3150
Wire Wire Line
	5900 3150 5700 3150
Connection ~ 5700 3150
Wire Wire Line
	5700 3150 5700 3600
Wire Wire Line
	5900 3600 5700 3600
Connection ~ 5700 3600
Wire Wire Line
	5700 3600 5700 4050
Wire Wire Line
	5900 4050 5700 4050
Connection ~ 5700 4050
Wire Wire Line
	5700 4050 5700 4500
Wire Wire Line
	5900 4500 5700 4500
Connection ~ 5700 4500
Wire Wire Line
	5700 4500 5700 4950
$Comp
L power:GND #PWR0101
U 1 1 5B9EF548
P 5700 5250
F 0 "#PWR0101" H 5700 5000 50  0001 C CNN
F 1 "GND" H 5705 5077 50  0000 C CNN
F 2 "" H 5700 5250 50  0001 C CNN
F 3 "" H 5700 5250 50  0001 C CNN
	1    5700 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 5250 5700 4950
Connection ~ 5700 4950
Wire Wire Line
	5900 2150 5500 2150
Wire Wire Line
	5500 2150 5500 1700
Wire Wire Line
	5500 1700 5900 1700
Wire Wire Line
	5900 2600 5500 2600
Wire Wire Line
	5500 2600 5500 2150
Connection ~ 5500 2150
Wire Wire Line
	5900 3050 5500 3050
Wire Wire Line
	5500 3050 5500 2600
Connection ~ 5500 2600
Wire Wire Line
	5900 3500 5500 3500
Wire Wire Line
	5500 3500 5500 3050
Connection ~ 5500 3050
Wire Wire Line
	5900 3950 5500 3950
Wire Wire Line
	5500 3950 5500 3500
Connection ~ 5500 3500
Wire Wire Line
	5900 4400 5500 4400
Wire Wire Line
	5500 4400 5500 3950
Connection ~ 5500 3950
Wire Wire Line
	5900 4850 5500 4850
Wire Wire Line
	5500 4850 5500 4400
Connection ~ 5500 4400
Wire Wire Line
	2000 5950 1750 5950
Wire Wire Line
	1750 5950 1750 6750
Wire Wire Line
	1750 6750 5500 6750
Wire Wire Line
	5500 6750 5500 4850
Connection ~ 5500 4850
Wire Wire Line
	2000 5050 1600 5050
Wire Wire Line
	1600 5050 1600 6550
Wire Wire Line
	1600 6550 5300 6550
Wire Wire Line
	5300 6550 5300 4950
Wire Wire Line
	5300 4950 5700 4950
Wire Wire Line
	5900 1600 5050 1600
Wire Wire Line
	5050 1600 5050 1650
Wire Wire Line
	5050 1650 4600 1650
Wire Wire Line
	5900 2050 5350 2050
Wire Wire Line
	5350 2050 5350 1750
Wire Wire Line
	5350 1750 4600 1750
Wire Wire Line
	5900 2500 5250 2500
Wire Wire Line
	5250 2500 5250 1850
Wire Wire Line
	5250 1850 4600 1850
Wire Wire Line
	5900 2950 5150 2950
Wire Wire Line
	5150 2950 5150 1950
Wire Wire Line
	5150 1950 4600 1950
Wire Wire Line
	5900 3400 5050 3400
Wire Wire Line
	5050 3400 5050 2050
Wire Wire Line
	5050 2050 4600 2050
Wire Wire Line
	5900 3850 4950 3850
Wire Wire Line
	4950 3850 4950 2150
Wire Wire Line
	4950 2150 4600 2150
Wire Wire Line
	5900 4300 4850 4300
Wire Wire Line
	4850 4300 4850 2250
Wire Wire Line
	4850 2250 4600 2250
Wire Wire Line
	5900 4750 4750 4750
Wire Wire Line
	4750 4750 4750 2350
Wire Wire Line
	4750 2350 4600 2350
$Comp
L Connector_Generic:Conn_01x02 Serial_1
U 1 1 5B9F8DDF
P 1250 1750
F 0 "Serial_1" H 1170 1425 50  0000 C CNN
F 1 "Conn_01x02" H 1170 1516 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 1250 1750 50  0001 C CNN
F 3 "~" H 1250 1750 50  0001 C CNN
	1    1250 1750
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 Serial_2
U 1 1 5B9F8F0F
P 1250 2200
F 0 "Serial_2" H 1170 1875 50  0000 C CNN
F 1 "Conn_01x02" H 1170 1966 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x02_P2.00mm_Vertical" H 1250 2200 50  0001 C CNN
F 3 "~" H 1250 2200 50  0001 C CNN
	1    1250 2200
	-1   0    0    1   
$EndComp
Wire Wire Line
	1450 1650 2000 1650
Wire Wire Line
	1450 1750 2000 1750
Wire Wire Line
	2000 1850 1600 1850
Wire Wire Line
	1600 1850 1600 2100
Wire Wire Line
	1600 2100 1450 2100
Wire Wire Line
	2000 1950 1650 1950
Wire Wire Line
	1650 1950 1650 2200
Wire Wire Line
	1650 2200 1450 2200
$Comp
L Connector_Generic:Conn_01x08 MPU6050
U 1 1 5B9FF5A8
P 1200 3050
F 0 "MPU6050" H 1120 2425 50  0000 C CNN
F 1 "Conn_01x08" H 1120 2516 50  0000 C CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x08_P2.00mm_Vertical" H 1200 3050 50  0001 C CNN
F 3 "~" H 1200 3050 50  0001 C CNN
	1    1200 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	1900 2850 1400 2850
Wire Wire Line
	1850 2950 1400 2950
Wire Wire Line
	1400 2750 1600 2750
Wire Wire Line
	1600 2750 1600 5050
Connection ~ 1600 5050
Wire Wire Line
	1400 2650 1700 2650
Wire Wire Line
	1700 2650 1700 5650
Wire Wire Line
	1700 5650 2000 5650
Wire Wire Line
	1850 2950 1850 2450
Wire Wire Line
	1850 2450 2000 2450
Wire Wire Line
	2000 2550 1900 2550
Wire Wire Line
	1900 2550 1900 2850
$EndSCHEMATC
