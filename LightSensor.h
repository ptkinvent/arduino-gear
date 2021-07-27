/**
 * @author Prateek Sahay
 * @date 2/28/21
 */

#include "AbstractAnalogSensor.h"


class LightSensor : public AbstractAnalogSensor
{
public:
    /**
     * Plug potentiometer into an analog pin of Grove shield.
     */
    LightSensor(int pin) : AbstractAnalogSensor(pin) {};
};
