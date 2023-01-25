/*
  Dave Williams, DitroniX 2019-2023 (ditronix.net)
  CMIS-1 Current Monitor IoT Sensors v1.0
  Features include ESP32 MODBUS EEPROM CT Clamp Multi-Current Sensors Voltage OLED
  PCA v1.2211-105 - Test Code Firmware v1 - 18th January 2023

  Simplified Board Bring Up Test - CT Clamp (Output sent to the OLED Display)
  
  Remember!
  Set the BOARD to ESP32, 'WEMOS D1 MINI ESP32' DEV Module (or similar).
  You may set the BAUD rate to 921600 to speed up flashing.
  The SDK does NOT need external power to flash.  It will take Power from the USB 5V.
  
  Note: In the default state, upon first power up and during reset, the Green LED may be partially lit. Once programmed and the GPIO defined, the Green LED will go off after power up.

  This test code is OPEN SOURCE and formatted for easier viewing.  Although is is not intended for real world use, it may be freely used, or modified as needed.
  It is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

  Further information, details and examples can be found on our website wiki pages ditronix.net/wiki and github.com/DitroniX
*/

// Libraries
#include <EmonLib.h>  // https://github.com/openenergymonitor/EmonLib
#include <driver/adc.h>
#include <GyverOLED.h>

// ****************  VARIABLES / DEFINES / STATIC ****************

// Constants
const int LoopDelay = 1;  // Loop Delay in Seconds

// Variables
double Irms;

// **************** OUTPUTS ****************
#define LED_Red 2    // Red LED
#define LED_Green 4  // Green LED

// **************** INPUTS ****************
#define CT_IN 35  //GPIO 35 (Analog ADC 1 CH7)

// Force EmonLib to use 1bit ADC resolution
#define ADC_BITS 12
#define ADC_COUNTS (1 << ADC_BITS)
#define Home_Voltage 249.0
#define emonTxV3  //Force the library to use 3v3 as supply voltage

// EnergyMonitor Instance.
EnergyMonitor emon1;

// OLED Instance. You will need to select your OLED Display. 
// Uncomment/Comment as needed.
GyverOLED<SSD1306_128x32, OLED_BUFFER> oled;  // 0.6" OLED
//GyverOLED<SSD1306_128x32, OLED_NO_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
//GyverOLED<SSH1106_128x64> oled;

void setup() {

  // Stabalise
  delay(250);

  // Initialize UART:
  Serial.begin(115200, SERIAL_8N1);  //115200
  while (!Serial)
    ;

  // LEDs
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Green, OUTPUT);

  // LEDs Default Off State
  digitalWrite(LED_Red, HIGH);
  digitalWrite(LED_Green, HIGH);

  adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);
  analogReadResolution(ADC_BITS);

  // Initialize emon library (30 = calibration number, adjust as needed)
  emon1.current(CT_IN, 23.50);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(18, 0);
  oled.setScale(5);
  oled.print("CMIS");
  oled.update();
  delay(2000);
}

// Draw Battery
void drawBattery(byte percent) {
  oled.drawByte(0b00111100);
  oled.drawByte(0b00111100);
  oled.drawByte(0b11111111);
  for (byte i = 0; i < 100 / 8; i++) {
    if (i < (100 - percent) / 8) oled.drawByte(0b10000001);
    else oled.drawByte(0b11111111);
  }
  oled.drawByte(0b11111111);
}

void loop() {

  // Calculate Irms only, adjust as needed
  double Amps = emon1.calcIrms(1676);  //5588, adjust as needed
  Serial.print(Amps);
  Serial.println(" A");


  // Calculate Watts (Power)
  double Watts = Amps * Home_Voltage;
  Serial.print(Watts);
  Serial.println(" W");

  // May be useful to filter out below preset wattage

  oled.clear();
  oled.setScale(3);
  oled.setCursor(0, 0);
  oled.print(int(Watts));
  oled.println(" W");
  drawBattery(Watts / 10);
  oled.update();

  // Heatbeat LED
  digitalWrite(LED_Red, LOW);
  delay(50);
  digitalWrite(LED_Red, HIGH);

  // Loop Delay
  delay(LoopDelay * 1000);
}
