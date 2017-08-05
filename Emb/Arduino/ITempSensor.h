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
public:
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
     *
     * @return true if success, false if failed
     */
    virtual bool initialize() =0;

    /**
     * Get current temperature
     *
     * @return temperature in tenthes of degrees C
     */
    virtual int16_t getTemperature() =0;
};

#endif /* ITEMPSENSOR_H_ */
