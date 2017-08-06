/*
 * LightSensor.cpp
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#include "LightSensor.h"

CLightSensor::CLightSensor(uint8_t adcPin, uint8_t powerPin) :
        m_adcPin(adcPin), m_powerPin(powerPin) {
}

bool CLightSensor::initialize() {
}

uint8_t CLightSensor::getLightLevel() {
    uint16_t sensorValue;
    pinMode(m_powerPin, OUTPUT); //come from high impedant
    digitalWrite(m_powerPin, HIGH);
    sensorValue = analogRead(m_adcPin);
    digitalWrite(m_powerPin, LOW);
    pinMode(m_powerPin, INPUT); //go back to high impedant

    return ((sensorValue * 100) / 1024);
}
