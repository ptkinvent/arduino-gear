/**
 * @author Prateek Sahay
 * @date 7/26/21
 */

#pragma once


class AbstractAnalogSensor
{
public:
    /**
     * Delete default constructor
     */
    AbstractAnalogSensor() = delete;

    /**
     * Constructor
     */
    AbstractAnalogSensor(int pin) : _pin(pin) {};

    /**
     * Returns sensed value 0-1
     */
    virtual float sense()
    {
        int val = analogRead(_pin);
        float ratio = (float) val / 1024.0;
        return ratio;
    };

protected:
    int _pin;
};
