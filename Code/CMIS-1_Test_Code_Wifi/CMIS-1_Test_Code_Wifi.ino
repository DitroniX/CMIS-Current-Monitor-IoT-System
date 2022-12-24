/*/*
  Dave Williams, DitroniX 2019-2022 (ditronix.net)
  CMIS-1 Current Monitor IoT Sensors v1.0
  Features include ESP32, LDO5V, LDO3V3, MODBUS, EEPROM, CT Clamp, AC/DC Multi-Current Sensors, Voltage Sensor, NTC, D1 Flashing Compatible
  PCA 1.2211-105 - Test Code Firmware v1 - 2nd September 2022
  
  Simplified Board Bring Up Test - Wifi Scan

  Remember!
  - Set the BOARD to ESP32, 'WEMOS D1 MINI ESP32' DEV Module (or similar).
  - You may set the BAUD rate to 921600 to speed up flashing.
  - The SDK does NOT need external power to flash.  It will take Power from the USB 5V.
  
  Note: In the default state, upon first power up and during reset, the Green LED may be partially lit. Once programmed and the GPIO defined, the Green LED will go off after power up.

  This test code is OPEN SOURCE and formatted for easier viewing.  Although is is not intended for real world use, it may be freely used, or modified as needed.
  It is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

  Further information, details and examples can be found on our website wiki pages ditronix.net/wiki and github.com/DitroniX
*/

#include <WiFi.h>

WiFiClient client; // Initialize the client library

void setup() {

  // Stabalise
  delay(250);

  // Initialize UART:
  Serial.begin(115200, SERIAL_8N1);  //115200
  while (!Serial);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {

  Serial.println("ESP32 WiFi MAC \t " + WiFi.macAddress());
  Serial.println("Scanning for Access Points or Routers.  Please wait....");
  delay(100);

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.print("Scan Complete.  ");
  if (n == 0) {
    Serial.println("No Access Points or Routers Found.");
  } else {
    Serial.print(n);
    Serial.println(" Access Points or Routers Found.");
    Serial.println("");

    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": \t");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(100);
    }
  }
  Serial.println("");
}
