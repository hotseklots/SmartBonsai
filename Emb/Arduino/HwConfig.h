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

#include "DHT11Sensor.h"
CDHT11Sensor* dhtSensor;
static const uint8_t DHT_PIN = 5;



#endif /* HWCONFIG_H_ */
