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
public:
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
     * Initialize sensor
     *
     * @return true if success, false if failed
     */
    virtual bool initialize() =0;

    /**
     * Get current light level
     *
     * @return humidity in %
     */
    virtual uint8_t getLightLevel()=0;
};

#endif /* ILIGHTSENSOR_H_ */
