/*
 * HwConfig.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef HWCONFIG_H_
#define HWCONFIG_H_

#include "WifiOperations.h"
CWifiOperations* wifiOperation;

#include "EnviromentSensing.h"
CEnviromentSensing* enviromentSensor;

#include "DHT11Sensor.h"
CDHT11Sensor* dhtSensor;
static const uint8_t DHT_PIN = 5;

#include "SoilHumidityMeter.h"
CSoilHumidityMeter* soilSensor;
static const uint8_t SOIL_ADC_PIN = A0; // conflict but only one ADC availible so needs to be resolved
static const uint8_t SOIL_POWER_PIN = 4; //dummy

#include "LightSensor.h"
CLightSensor* lightSensor;
static const uint8_t LIGHT_ADC_PIN = A0; // conflict but only one ADC availible so needs to be resolved
static const uint8_t LIGHT_POWER_PIN = 14; //dummy

#include "WateringSystem.h"
CWateringSystem* waterSystem;
static const uint8_t SERVO_PIN = 12; //dummy
static const int16_t DRY_PERCENTAGE = 20;
static const int16_t WATER_ANGLE = 180;
static const int16_t NO_WATER_ANGLE = 0;

#endif /* HWCONFIG_H_ */
