#include <Arduino.h>

#include "HwConfig.h"

void setup() {
    Serial.begin(115200);
    wifiOperation = new CWifiOperations();
    dhtSensor = new CDHT11Sensor(DHT_PIN);
    soilSensor = new CSoilHumidityMeter(SOIL_ADC_PIN,SOIL_POWER_PIN);
    lightSensor =new CLightSensor(LIGHT_ADC_PIN,LIGHT_POWER_PIN);4
    enviromentSensor = new CEnviromentSensing(lightSensor,dhtSensor,dhtSensor,soilSensor);
    wifiOperation->selectWifi();
    Serial.println("Setup done");

}

void loop() {

    if (!wifiOperation->isConnected()) {
        wifiOperation->reconnect();
    }

    enviromentSensor->getTemperature();

    delay(5000);
    if (!wifiOperation->isConnected()) {
        wifiOperation->disconnect();
    }

    // Wait a bit before scanning again
    delay(5000);
}

