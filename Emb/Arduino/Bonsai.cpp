#include <Arduino.h>

#include "HwConfig.h"

void setup() {
    Serial.begin(115200);
    wifiOperation = new CWifiOperations();
    dhtSensor = new CDHT11Sensor(DHT_PIN);
    soilSensor = new CSoilHumidityMeter(SOIL_ADC_PIN, SOIL_POWER_PIN);
    lightSensor = new CLightSensor(LIGHT_ADC_PIN, LIGHT_POWER_PIN);
    enviromentSensor = new CEnviromentSensing(*lightSensor, *dhtSensor,
            *dhtSensor, *soilSensor);
    waterSystem = new CWateringSystem(DRY_PERCENTAGE, SERVO_PIN, WATER_ANGLE,
            NO_WATER_ANGLE);
    wifiOperation->selectWifi();
    Serial.println("Setup done");
}

void loop() {

    waterSystem->checkWater(enviromentSensor->getSoilHumidity());

    if (!wifiOperation->isConnected()) {
        wifiOperation->reconnect();
    }

    delay(100);

    if (wifiOperation->isConnected()) {
        wifiOperation->disconnect();
    }

    // Wait a bit before scanning again
    delay(5000);
}

