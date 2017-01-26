/*
Energy monitor application. This program receives data
from a node with n sensors and sends the data to the internet

Copyright (C) 2013 Simio Labs, created by Daniel Montero
Copyright (C) 2017 Simio Labs, modified by Daniel Montero

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <SPI.h>
#include <Ethernet.h>

EthernetClient client;
char server[] = "simiolabs.com";      // remote host site
const String apiKey = "100bdc36203b7a7183fa0b79445ebda6";
const byte NUM_FIELDS = 9;
const String fieldNames[NUM_FIELDS] = {"apparent_power", "current", "name",
                                       "node_id", "power_factor", "real_power",
                                       "sensor_id", "status", "voltage"};
String fieldData[NUM_FIELDS];

// MAC address for your Ethernet shield
byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x74, 0xFB };

char realPower[8] = { 0 };
char apparentPower[8] = { 0 };
char current[8] = { 0 };
char voltage[8] = { 0 };
char powerFactor[8] = { 0 };


void setup() {
  Serial.begin(115200);
  initEthernet(); // get IP address from router
}

// continuously reads packets, looking for ZB receive or modem status
void loop() {
  uploadData();
  delay(10000);
}

void initEthernet() {
  Serial.println("Start Ethernet");

  while (Ethernet.begin(mac) != 1) {
    Serial.println("IP error");
    delay(15000);
  }
  // print your local IP address:
  Serial.print("IP ");
  Serial.println(Ethernet.localIP());
}

void uploadData() {

}
