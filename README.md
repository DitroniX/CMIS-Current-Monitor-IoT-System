## CMIS (Current Monitor IoT System) SDK

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


## **Further Information**

Additional information, and other technical details on this project, maybe found in the related repository pages.

**Repository Folders**

 - **Code** *(Code examples for Arduino  IDE and PlatformIO)*
 -  **Datasheets and Information** *(Component Datasheets, Schematics, Board Layouts, Photos, Technical Documentation)*
 - **Certification** *(Related Repository Project or Part, Certification Information)*

**Repository Tabs**

 - **Wiki** *(Related Repository Wiki pages and Technical User Information)*
 - **Discussions** *(Related Repository User Discussion Forum)*
 - **Issues** *(Related Repository Technical Issues and Fixes)*

***

We value our Customers, Users of our designs and STEM Communities, all over the World . Should you have any other questions, or feedback to share to others, please feel free to:

* Visit the related [Project](https://github.com/DitroniX?tab=repositories) *plus the related* **Discussions** and **Wiki** Pages.  See tab in each separate repository.
* **Project Community Information** can be found at https://www.hackster.io/DitroniX
* [DitroniX.net Website - Contact Us](https://ditronix.net/contact/)
* **Twitter**: [https://twitter.com/DitroniX](https://twitter.com/DitroniX)
* [Supporting the STEM Projects - BuyMeACoffee](https://www.buymeacoffee.com/DitroniX)
*  **LinkedIN**: [https://www.linkedin.com/in/g8puo/](https://www.linkedin.com/in/g8puo/)

***Dave Williams, Maidstone, UK.***

Electronics Engineer | Software Developer | R&D Support | RF Engineering | Product Certification and Testing | STEM Ambassador

## STEM

**Supporting [STEM Learning](https://www.stem.org.uk/)**

Life is one long exciting learning curve, help others by setting the seed to knowledge.

![DitroniX Supporting STEM](https://hackster.imgix.net/uploads/attachments/1606838/stem_ambassador_-_100_volunteer_badge_edxfxlrfbc1_bjdqharfoe1_xbqi2KUcri.png?auto=compress%2Cformat&w=540&fit=max)
