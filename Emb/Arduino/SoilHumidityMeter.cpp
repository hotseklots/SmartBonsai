/*
 * SoilHumidityMeter.cpp
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#include "SoilHumidityMeter.h"

CSoilHumidityMeter::CSoilHumidityMeter(uint8_t adcPin, uint8_t powerPin) :
        m_adcPin(adcPin), m_powerPin(powerPin) {
}

bool CSoilHumidityMeter::initialize() {
    pinMode(m_powerPin, OUTPUT);
}

uint8_t CSoilHumidityMeter::getHumidity() {
    uint16_t sensorValue;
    digitalWrite(m_powerPin, HIGH);
    sensorValue = analogRead(m_adcPin);
    digitalWrite(m_powerPin, LOW);

    return ((sensorValue * 100) / 1024);
}

