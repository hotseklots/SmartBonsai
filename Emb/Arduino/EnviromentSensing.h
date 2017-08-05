/*
 * EnviromentSensing.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef ENVIROMENTSENSING_H_
#define ENVIROMENTSENSING_H_

#include <Arduino.h>
#include "IHumiditySensor.h"
#include "ITempSensor.h"
#include "ILightSensor.h"

/**
 * Contains the sensors of the system
 */
class CEnviromentSensing {
public:
    /**
     * Constructor
     *
     * @param lightsensor of the system
     * @param temp sensor of the system
     * @param air humidity sensor of the system
     * @param soil humidity sensor of the system
     */
    CEnviromentSensing(ILightSensor& lightSensor, ITempSensor& tempSensor,
            IHumiditySensor& airHumidity, IHumiditySensor& soilHumidity);

    /**
     * Get humidity of the air in %
     * @return humidity in %
     */
    uint8_t getAirHumidity();

    /**
     * Get temperature in tenthes of degrees C
     * @return temperature in tenthes of degrees C
     */
    int16_t getTemperature();

    /**
     * Get humidity of the soil in %
     * @return humidity in %
     */
    uint16_t getSoilHumidity();

    /**
     * Get light level in %
     * @return the light in %
     */
    uint16_t getLightLevel();

private:
    ILightSensor& m_lightSensor; //!< light sensor
    ITempSensor& m_tempSensor; //!< temperature sensor
    IHumiditySensor& m_airHumidity; //!< air humidity sensor
    IHumiditySensor& m_soilHumidity; //!< soil humidity sensor

    CEnviromentSensing(); // Intentional undefined

};

#endif /* ENVIROMENTSENSING_H_ */
