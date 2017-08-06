/*
 * DHT11.cpp
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */
#include "DHT11Sensor.h"

CDHT11Sensor::CDHT11Sensor(uint8_t pin) :
        m_dht() {
    m_dht.setup(pin, DHT::DHT11);
}

bool CDHT11Sensor::initialize() {

}

int16_t CDHT11Sensor::getTemperature() {
    float temperature;
    temperature = m_dht.getTemperature();

    if (isnan(temperature)) {
        return 0xFFFF;
    }

    return static_cast<int16_t>(temperature * 10);
}

uint8_t CDHT11Sensor::getHumidity() {
    float humidity;
    humidity = m_dht.getHumidity();

    if (isnan(humidity)) {
        return 0xFFFF;
    }

    return static_cast<int16_t>(humidity);
}

