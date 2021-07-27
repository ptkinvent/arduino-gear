/**
 * @author Prateek Sahay
 * @date 2/2/21
 */

#include "AbstractAnalogSensor.h"


class RotationSensor : public AbstractAnalogSensor
{
public:
    enum Direction
    {
        INCREMENT_CW,
        INCREMENT_CCW
    };

    /**
     * Plug potentiometer into an analog pin of Grove shield.
     */
    RotationSensor(int pin, Direction dir) : AbstractAnalogSensor(pin), _dir(dir) {};

    /**
     * Returns position 0-1
     */
    float sense() override
    {
        float ratio = AbstractAnalogSensor::sense();
        return (_dir == INCREMENT_CCW) ? ratio : 1 - ratio;
    };

private:
    Direction _dir;
};
