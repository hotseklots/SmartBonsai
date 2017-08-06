/*
 * WateringSystem.h
 *
 *  Created on: 5 aug. 2017
 *      Author: marcel
 */

#ifndef WATERINGSYSTEM_H_
#define WATERINGSYSTEM_H_
#include <Arduino.h>
#include "servo.h"
/**
 * Controls the watering system
 */
class CWateringSystem {
public:
    /**
     * Constructor
     *
     * @param percentage below which the soil is dry and water is needed
     * @param servoPin where the servo is attached
     * @param waterAngle angle at which water is given
     * @param noWaterAngle angle at which no water is given
     */
    CWateringSystem(uint8_t dryPercent, uint8_t servoPin, int16_t waterAngle,
            int16_t noWaterAngle);

    /**
     * Checks if water is needed and gives or stops giving water
     * @param humidity of the soil
     */
    void checkWater(uint8_t humidity);

private:
    uint8_t m_dryPercentage; //!< percentage from which the soil is considered dry
    uint8_t m_servoPin; //!< Pin where the servo is attached
    int16_t m_waterAngle; //!< Angle at which water is given
    int16_t m_noWaterAngle; //!<  Angle at which no water is given
    Servo m_servo; //!< Servo of the watering system

    CWateringSystem(); // Intentionally Undefined

    /**
     * Check if watering is needed
     * @param humidity of the soil
     * @return true if needed false otherwise
     */
    bool checkWaterNeeded(uint8_t humidity);

    /**
     * Enabled water giving
     */
    void giveWater();

    /**
     * Stop giving water
     */
    void stopGivingWater();

};

#endif /* WATERINGSYSTEM_H_ */
