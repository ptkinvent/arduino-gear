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
};
