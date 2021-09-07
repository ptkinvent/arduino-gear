/**
 * @author Prateek Sahay
 * @date 2/2/21
 */

#include "AbstractAnalogSensor.h"


class TemperatureSensor : public AbstractAnalogSensor
{
public:
    /**
     * Plug temperature sensor into an analog pin of Grove shield.
     */
    TemperatureSensor(int pin) : AbstractAnalogSensor(pin) {};

    /**
     * Returns temperature in Fahrenheit.
     */
    float sense() override
    {
        int val = analogRead(_pin);
        float resistance = (float)(1023-val)*10000/val;
        float temperature_c = 1/(log(resistance/10000)/B+1/298.15)-273.15;
        float temperature_f = (temperature_c*1.8)+32;
        float temperature = temperature_f;
        _circularBuffer.push_back(temperature);
        return _circularBuffer.getMean();
    }

private:
    const int B = 3975;
};
