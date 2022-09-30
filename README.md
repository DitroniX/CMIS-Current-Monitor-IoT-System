**CMIS (Current Monitor IoT System) SDK**

------------

CMIS features include ESP32 MODBUS EEPROM CT Clamp Multi-Current Voltage

![Display-Type-B](https://ditronix.net/wp-content/uploads/2022/09/CMIS-1-2209-102-PCB-Populated-No-PTH-scaled.jpg?raw=true)

Specification overview:

- Espressif ESP32 WROOM
	2.4GHz Wi-Fi and Bluetooth LE MCU module, with dual core CPU
- AT24C64 EEPROM
	For storing parameters, calibration data etc.
- 4 x Isolated Bi-directional Current Sensors AC/DC Maximum ±100A
	ACS758 100A (ACS758LCB-100B-PFF-T), Hall Effect based, Linear Current Sensor
	Large Quality Terminal Blocks suitable for 20 AWG up to 6 AWG, 10mm², Rated 52A 300V
- ADC 12-bit Resolution
	Using ESP32 Internal ADCs
- CT Clamp Input
	With or without Burden Resistor
	Suitable for popular SCT013 YHDC
- On-board Temperature Sensor
	NTC (range -40ºC to +125ºC)
- USB UART
	Micro USB.   Uses the popular CH340 for ease of developing code, flashing and debugging
- OLED Display Connections
	I2C
- DC Power LED (red)
- RGB LED (firmware controlled)
- SPI and I2C Connections
- DAC Output
	with LP/HP filter options (unpopulated R/C)
- On board 3V3 and 5V LDO Voltage Regulators
	PCB 7-15V DC Input
- D1 Mini, Software Compatible
	No drivers normally needed
- PCB Size 100mm x 95mm

Remember!
- Our SDKs are WeMos D1 Mini flashing compatible
- Set the BOARD to ESP32 DEV Module (or similar).
- You can also set the BAUD rate to 921600 to speed up flashing.
- The SDK does NOT need external power to flash.  It will take Power from the USB 5V.
*You may though need to provide external DC for power up all the SDK functions.*

The purpose of our test code is to cycle through the various main functions of the board as part of bring up testing.

All test code is OPEN SOURCE and although is is not intended for real world use, it may be freely used, or modified as needed.  It is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

Further information can be found:

- **Website** https://ditronix.net/
- **WIKI**  https://ditronix.net/wiki/
- **Shop**  https://ditronix.net/shop/

Dave Williams | G8PUO | DitroniX 1981-2022 | ditronix.net
