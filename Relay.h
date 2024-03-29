/**
 * @author Prateek Sahay
 * @date 2/11/21
 */

class Relay
{
public:
    /**
     * Plug positive pin of relay into a digital pin and negative
     * pin into ground.
     */
    Relay(int pin) : _pin(pin)
    {
        pinMode(_pin, OUTPUT);
    };

    /**
     * Returns position 0-1
     */
    void on()
    {
        digitalWrite(_pin, HIGH);
    }

    void off()
    {
        digitalWrite(_pin, LOW);
    }

private:
    int _pin;
};
