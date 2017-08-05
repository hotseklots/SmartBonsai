#include <Arduino.h>
#include "ESP8266WiFi.h"
#include "WifiOperations.h"

CWifiOperations* wifiOperation;

void setup() {
    Serial.begin(115200);
    wifiOperation = new CWifiOperations();

    wifiOperation->selectWifi();
    Serial.println("Setup done");

}

void loop() {

    if (!wifiOperation->isConnected()) {
        wifiOperation->reconnect();
    }



    WiFi.disconnect();

    // Wait a bit before scanning again
    delay(5000);
}

