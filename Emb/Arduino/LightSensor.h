/*
 * LightSensor.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef LIGHTSENSOR_H_
#define LIGHTSENSOR_H_

#include <Arduino.h>
#include "ILightSensor.h"

/**
 * Measures the ambient light
 */
class CLightSensor: public ILightSensor {
public:
    /**
     * Constructor
     * @param adcPin at which the adc is located
     * @param powerPin at which the power of the light sensor is located
     */
    CLightSensor(uint8_t adcPin, uint8_t powerPin);

    /**
     * Initialize sensor
     *
     * @return true if success, false if failed
     */
    virtual bool initialize();

    /**
     * Get current light level
     *
     * @return light level in %
     */
    virtual uint8_t getLightLevel();

private:
    const uint8_t m_adcPin; //!< Pin at which the ADC of the soil sensor is attached
    const uint8_t m_powerPin; //!< Pin at which the power pin is located

    CLightSensor(); //intentional undefined

};

#endif /* LIGHTSENSOR_H_ */
