/*
 * EnviromentSensing.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef ENVIROMENTSENSING_H_
#define ENVIROMENTSENSING_H_

#include <Arduino.h>

class CEnviromentSensing {
    CEnviromentSensing();

    /**
     * Get humidity of the air in %
     * @return humidity in %
     */
    uint8_t getAirHumidity();

    /**
     * Get temperature in tenthes of degrees C
     * @return temperature in tenthes of degrees C
     */
    uint16_t getTemperature();

    /**
     * Get humidity of the soil in %
     * @return humidity in %
     */
    uint16_t getSoilHumidithy();

    /**
     * Get light level in %
     * @return the light in %
     */
    uint16_t getLightLevel();

};

#endif /* ENVIROMENTSENSING_H_ */
