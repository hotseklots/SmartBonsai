/*
 * DHT11.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef DHT11SENSOR_H_
#define DHT11SENSOR_H_
#include <Arduino.h>
#include "IHumiditySensor.h"
#include "ITempSensor.h"
#include "DHT.h"

/**
 * Controls the DHT11 sensor
 */
class CDHT11Sensor: public IHumiditySensor, public ITempSensor {
public:
    /**
     * Constructor
     */
    CDHT11Sensor(uint8_t pin);

    /**
     * Initialize sensor
     *
     * @return true if success, false if failed
     */
    virtual bool initialize();

    /**
     * Get current temperature
     *
     * @return temperature in tenthes of degrees C
     */
    virtual int16_t getTemperature();

    /**
     * Get current humidity
     *
     * @return humidity in %
     */
    virtual uint8_t getHumidity();
private:
    DHT m_dht; //!< DHT11 sensor object

    CDHT11Sensor(); //intentional undefined

};

#endif /* DHT11SENSOR_H_ */
