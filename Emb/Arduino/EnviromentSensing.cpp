/*
 * EnviromentSensing.cpp
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */
#include "EnviromentSensing.h"

CEnviromentSensing::CEnviromentSensing(ILightSensor& lightSensor,
        ITempSensor& tempSensor, IHumiditySensor& airHumidity,
        IHumiditySensor& soilHumidity) :
        m_lightSensor(lightSensor), m_tempSensor(tempSensor), m_airHumidity(
                airHumidity), m_soilHumidity(soilHumidity) {
    m_lightSensor.initialize();
    m_tempSensor.initialize();
    m_airHumidity.initialize();
    m_soilHumidity.initialize();
}

uint8_t CEnviromentSensing::getAirHumidity() {
    return m_airHumidity.getHumidity();
}

int16_t CEnviromentSensing::getTemperature() {
    return m_tempSensor.getTemperature();
}

uint16_t CEnviromentSensing::getSoilHumidity() {
    return m_soilHumidity.getHumidity();
}

uint16_t CEnviromentSensing::getLightLevel() {
    return m_lightSensor.getLightLevel();
}
