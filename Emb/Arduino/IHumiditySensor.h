/*
 * IAirHumiditySensor.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef IHUMIDITYSENSOR_H_
#define IHUMIDITYSENSOR_H_

/**
 * Interface for humidity sensors
 */
class IHumiditySensor {
    /**
     * Constructor
     */
    IHumiditySensor() {
    }

    /**
     * Deconstructor
     */
    virtual ~IHumiditySensor() {
    }

    /**
     * Initialize sensor
     */
    virtual bool initialize() =0;

    /**
     * Get current humidity
     */
    virtual uint8_t getHumidity() =0;
};

#endif /* IHUMIDITYSENSOR_H_ */
