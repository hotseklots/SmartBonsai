/*
 * WateringSystem.cpp
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#include "WateringSystem.h"

CWateringSystem::CWateringSystem(uint8_t dryPercent, uint8_t servoPin,
        int16_t waterAngle, int16_t noWaterAngle) :
        m_dryPercentage(dryPercent), m_servoPin(servoPin), m_waterAngle(
                waterAngle), m_noWaterAngle(noWaterAngle) {
    if (m_noWaterAngle < m_waterAngle) {
        m_servo.attach(m_servoPin, m_noWaterAngle, m_waterAngle);
    } else {
        m_servo.attach(m_servoPin, m_waterAngle, m_noWaterAngle);
    }
}

void CWateringSystem::checkWater(uint8_t humidity) {
    if (checkWaterNeeded(humidity)) {
        stopGivingWater();
    } else {
        giveWater();
    }
}

bool CWateringSystem::checkWaterNeeded(uint8_t humidity) {
    return (humidity < m_dryPercentage);
}

void CWateringSystem::giveWater() {
    if (m_servo.read() != m_waterAngle) {
        m_servo.write(m_waterAngle);
    }

}

void CWateringSystem::stopGivingWater() {
//    if (m_servo.read() != m_noWaterAngle) {
//        m_servo.write(m_noWaterAngle);
//    }
}
