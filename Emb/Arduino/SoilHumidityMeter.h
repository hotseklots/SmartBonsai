/*
 * SoilHumidityMeter.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef SOILHUMIDITYMETER_H_
#define SOILHUMIDITYMETER_H_

#include <Arduino.h>
#include "IHumiditySensor.h"

/**
 * Measures the humidity of soil
 */
class CSoilHumidityMeter:IHumiditySensor
{
public:
    /**
     * Constructor
     * @param adcPin at which the adc is located
     * @param powerPin at which the power of the soil sensor is located
     */
    CSoilHumidityMeter(uint8_t adcPin, uint8_t powerPin);

    /**
     * Initialize sensor
     *
     * @return true if success, false if failed
     */
    virtual bool initialize();

    /**
     * Get current humidity
     *
     * @return humidity in %
     */
    virtual uint8_t getHumidity();


private:
    const uint8_t m_adcPin; //!< Pin at which the ADC of the soil sensor is attached
    const uint8_t m_powerPin; //!< Pin at which the power pin is located

    CSoilHumidityMeter(); //intentional undefined

};



#endif /* SOILHUMIDITYMETER_H_ */
