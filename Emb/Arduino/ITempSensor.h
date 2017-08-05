/*
 * ITempSensor.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef ITEMPSENSOR_H_
#define ITEMPSENSOR_H_

/**
 * Interface for temperature sensors
 */
class ITempSensor {
    /**
     * Constructor
     */
    ITempSensor() {
    }

    /**
     * Destructor
     */
    virtual ~ITempSensor() {
    }

    /**
     * Initialize sensor
     */
    virtual bool initialize() =0;

    /**
     * Get current temperature
     */
    virtual uint16_t getTemperature() =0;
};

#endif /* ITEMPSENSOR_H_ */
