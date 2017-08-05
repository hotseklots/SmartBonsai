#include <Arduino.h>

#include "HwConfig.h"

void setup() {
    Serial.begin(115200);
    wifiOperation = new CWifiOperations();
    dhtSensor = new CDHT11Sensor(DHT_PIN);
    soilSensor = new CSoilHumidityMeter(SOIL_ADC_PIN,SOIL_POWER_PIN);
    wifiOperation->selectWifi();
    Serial.println("Setup done");

}

void loop() {

    if (!wifiOperation->isConnected()) {
        wifiOperation->reconnect();
    }

    delay(5000);
    if (!wifiOperation->isConnected()) {
        wifiOperation->disconnect();
    }

    // Wait a bit before scanning again
    delay(5000);
}

