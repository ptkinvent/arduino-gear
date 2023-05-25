/**
 * @author Prateek Sahay
 * @date 7/19/21
 */

#include "AbstractAnalogSensor.h"


class MoistureSensor : public AbstractAnalogSensor
{
public:
    /**
     * Plug moisture sensor into an analog pin of Grove shield.
     */
    MoistureSensor(int pin) : AbstractAnalogSensor(pin) {};

    /**
     * Returns sensed value 0-1
     */
    virtual float sense()
    {
        // Invert the signal since this is more intuitive. E.g. 0 is low
        // moisture and 1 is high moisture.
        return 1 - AbstractAnalogSensor::sense();
    };
};
