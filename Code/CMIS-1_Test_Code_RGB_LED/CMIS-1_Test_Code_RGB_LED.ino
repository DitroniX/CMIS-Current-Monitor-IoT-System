/*
  Dave Williams, DitroniX 2019-2023 (ditronix.net)
  CMIS-1 Current Monitor IoT Sensors v1.0
  Features include ESP32 MODBUS EEPROM CT Clamp Multi-Current Sensors Voltage OLED
  PCA v1.2211-105 - Test Code Firmware v1 - 18th January 2023
  .
  Simplified Board Bring Up Test - RGB LED
  .
  Remember!
  Set the BOARD to ESP32, 'WEMOS D1 MINI ESP32' DEV Module (or similar).
  You may set the BAUD rate to 921600 to speed up flashing.
  The SDK does NOT need external power to flash.  It will take Power from the USB 5V.
  
  Note: In the default state, upon first power up and during reset, the Green LED may be partially lit. Once programmed and the GPIO defined, the Green LED will go off after power up.

  This test code is OPEN SOURCE and formatted for easier viewing.  Although is is not intended for real world use, it may be freely used, or modified as needed.
  It is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

  Further information, details and examples can be found on our website wiki pages ditronix.net/wiki and github.com/DitroniX
*/

// ****************  VARIABLES / DEFINES / STATIC ****************

// Constants
const int LoopDelay = 1; // Loop Delay in Seconds

// **************** OUTPUTS ****************
#define LED_Red 2 // Red LED
#define LED_Green 4 // Green LED
#define LED_Blue 15 // Blue LED

// **************** INPUTS ****************

void setup() {

  // Stabalise
  delay(250);

  //  Configures the specified LED GPIO as outputs
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Green, OUTPUT);
  pinMode(LED_Blue, OUTPUT);

  // LEDs Default Off State
  digitalWrite(LED_Red, HIGH);
  digitalWrite(LED_Green, HIGH);
  digitalWrite(LED_Blue, HIGH);
}

void loop() {

  // Test RGB LEDs

  // Red
  digitalWrite(LED_Red, LOW);
  
  // Loop Delay
  delay(LoopDelay * 1000);
  
  digitalWrite(LED_Red, HIGH);
  delay(100);

  // Green
  digitalWrite(LED_Green, LOW);
  
  // Loop Delay
  delay(LoopDelay * 1000);
  
  digitalWrite(LED_Green, HIGH);
  delay(100);

  // Blue
  digitalWrite(LED_Blue, LOW);

  // Loop Delay
  delay(LoopDelay * 1000);
  
  digitalWrite(LED_Blue, HIGH);
  delay(100);

  // White
  digitalWrite(LED_Red, LOW);
  digitalWrite(LED_Green, LOW);
  digitalWrite(LED_Blue, LOW);
  
  // Loop Delay
  delay(LoopDelay * 1000);
  
  digitalWrite(LED_Red, HIGH);
  digitalWrite(LED_Green, HIGH);
  digitalWrite(LED_Blue, HIGH);

  // Loop Delay
  delay(LoopDelay * 1000);

}
