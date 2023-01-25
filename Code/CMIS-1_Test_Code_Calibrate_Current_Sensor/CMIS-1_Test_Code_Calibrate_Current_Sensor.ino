/*
  Dave Williams, DitroniX 2019-2023 (ditronix.net)
  CMIS-1 Current Monitor IoT Sensors v1.0
  Features include ESP32 MODBUS EEPROM CT Clamp Multi-Current Sensors Voltage OLED
  PCA v1.2211-105 - Test Code Firmware v1 - 18th January 2023

  Simplified Board Bring Up Test - DC Current Sensor Calibrate
  
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
const int LoopDelay = 1;  // Loop Delay in Seconds

// Variables
float SensorRatioFactor = 0.0132;  // ACS758-100B A 20mV/A is the factor @ 5V
//float SensorRatioFactor = 0.0238;// ACS758-50B 60mV/A is the factor @ 5V
float ADCFactorVoltage = 3.3 / 4095.0;  // 0.0008058
float SensorZeroVoltage;
float SensorVoltage;
float SensorCalculatedCurrent;
int CurrentSensor;

// **************** INPUTS ****************
#define Current_1 35  //GPIO 35 (Analog ADC1_CH7)
#define Current_2 32  //GPIO 32 (Analog ADC1_CH4)
#define Current_3 33  //GPIO 33 (Analog ADC1_CH5)
#define Current_4 27  //GPIO 27 (Analog ADC2_CH7)

// **************** OUTPUTS ****************
#define LED_Red 2    // Red LED
#define LED_Green 4  // Green LED

void setup() {
  // Stabalise
  delay(250);

  // Initialise UART:
  Serial.begin(115200, SERIAL_8N1);  //115200
  while (!Serial)
    ;
  Serial.println("");

  //  Configures the specified LED GPIO as outputs
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Green, OUTPUT);

  // LED Default Off State
  digitalWrite(LED_Red, HIGH);
  digitalWrite(LED_Green, HIGH);

  // Setup Current Sensor Channel
  CurrentSensor = Current_4;  // Change channel as needed
}

void loop() {

  // Test Procedure
  // 1 Run this code with 0A flowing.
  // 2 Note 'Average SensorZeroVoltage' and update the SensorZeroVoltage variable below - Keep info for future use.
  // 3 Retest under current.

  // Raw ADC Output
  Serial.print("ADC Raw: ");
  Serial.print(analogRead(CurrentSensor));

  // Calculating SensorZeroVoltage @  0A
  SensorZeroVoltage = ADCFactorVoltage * analogRead(CurrentSensor);  // Read the voltage from sensor
  Serial.print("\tZero Current Voltage: ");
  Serial.print(SensorZeroVoltage);
  SensorZeroVoltage = 1.48;  // Place Average Zero Voltage Here (from SensorZero @ 0A)

  // Calculate SensorVoltage Reading
  SensorVoltage = ADCFactorVoltage * analogRead(CurrentSensor);
  SensorVoltage = SensorVoltage - SensorZeroVoltage;
  Serial.print("\tV: ");
  Serial.print(SensorVoltage, 3);

  // Calculate Sensor Current Based on Calculation
  SensorCalculatedCurrent = SensorVoltage / SensorRatioFactor;
  Serial.print("\tI: ");
  Serial.print(SensorCalculatedCurrent, 2);
  Serial.print("A");

  if (SensorCalculatedCurrent < -110 || SensorCalculatedCurrent > 110) Serial.print(" *ERROR: Possible Current Sensor Missing or Fault");

  Serial.println("");

  // Heatbeat LED
  digitalWrite(LED_Red, LOW);
  delay(50);
  digitalWrite(LED_Red, HIGH);

  // Loop Delay
  delay(LoopDelay * 1000);
}
