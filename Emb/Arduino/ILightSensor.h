/*
 * ILightSensor.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef ILIGHTSENSOR_H_
#define ILIGHTSENSOR_H_

#include <Arduino.h>

/**
 * Interface for light sensors
 */
class ILightSensor {
    /**
     * Constructor
     */
    ILightSensor() {
    }


    /**
     * Deconstructor
     */
    virtual ~ILightSensor() {
    }

    /**
     * Get current light level
     */
    virtual uint8_t getLightLevel()=0;
};

#endif /* ILIGHTSENSOR_H_ */
