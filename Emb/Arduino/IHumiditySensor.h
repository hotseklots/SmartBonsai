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
public:
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
     *
     * @return true if success, false if failed
     */
    virtual bool initialize() =0;

    /**
     * Get current humidity
     *
     * @return humidity in %
     */
    virtual uint8_t getHumidity() =0;
};

#endif /* IHUMIDITYSENSOR_H_ */
