/**
 * @author Prateek Sahay
 * @date 7/26/21
 */

#include <CircularBuffer.h>

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
    AbstractAnalogSensor(int pin) : _pin(pin), _circularBuffer(100) {};

    /**
     * Returns sensed value 0-1
     */
    virtual float sense()
    {
        int val = analogRead(_pin);
        float ratio = (float) val / 1024.0;
        _circularBuffer.push_back(ratio);
        return _circularBuffer.getMean();
    };

protected:
    int _pin;
    CircularBuffer<float> _circularBuffer;
};
