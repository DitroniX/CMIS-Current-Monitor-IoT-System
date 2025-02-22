/*
  Dave Williams, DitroniX 2019-2023 (ditronix.net)
  CMIS-1 Current Monitor IoT Sensors v1.0
  Features include ESP32 MODBUS EEPROM CT Clamp Multi-Current Sensors Voltage OLED
  PCA v1.2211-105 - Test Code Firmware v1 - 18th January 2023

  Simplified Board Bring Up Test - CT Clamp (Output sent to Serial Print)
  
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
#include <EmonLib.h> // https://github.com/openenergymonitor/EmonLib
#include <driver/adc.h>

// ****************  VARIABLES / DEFINES / STATIC ****************

// Constants
const int LoopDelay = 1; // Loop Delay in Seconds

// Variables
double Irms;

// **************** OUTPUTS ****************
#define LED_Red 2 // Red LED
#define LED_Green 4 // Green LED

// **************** INPUTS ****************
#define CT_IN 35 //GPIO 35 (Analog ADC 1 CH7)

// Force EmonLib to use 1bit ADC resolution
#define ADC_BITS    12
#define ADC_COUNTS  (1<<ADC_BITS)
#define Home_Voltage 249.0
#define emonTxV3  //Force the library to use 3v3 as supply voltage

// EnergyMonitor Instance.
EnergyMonitor emon1;

void setup() {

  // Stabalise
  delay(250);

  // Initialise UART:
  Serial.begin(115200, SERIAL_8N1);  //115200
  while (!Serial);
  Serial.println("");

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
}

void loop() {

  // Calculate Irms only, adjust as needed
  double Amps = emon1.calcIrms(1676); //5588, adjust as needed

  // Calculate Watts (Power)
  double Watts = Amps * Home_Voltage;

  // Optional to Filter out the noise, adjust as needed
  if (Amps > 0.20) {
    // Update the display
    Serial.print((int)Watts);
    Serial.print(" W ");
    Serial.print(Amps);
    Serial.println(" A");

    Serial.println("\n- - - - - - - - - - - - - - - - - - - -");

    // Flash LED
    digitalWrite(LED_Green, LOW);
    delay(50);
    digitalWrite(LED_Green, HIGH);
  }

  // Heatbeat LED
  digitalWrite(LED_Red, LOW);
  delay(50);
  digitalWrite(LED_Red, HIGH);

  // Loop Delay
  delay(LoopDelay * 1000);

}
