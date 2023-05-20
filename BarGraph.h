#pragma once

#include <Adafruit_LEDBackpack.h>

/**
 * Draws a bar graph using Adafruit 24-LED bar graph to display a value 0-1. If
 * value is below lowThresh, the bar is drawn in red LEDs. If value is above
 * highThresh, the bar is drawn in green LEDs, else yellow.
 */
class BarGraph
{
public:
    /**
     * Constructor
     */
    BarGraph(float lowThresh, float highThresh) : _lowThresh(lowThresh), _highThresh(highThresh)
    {
        _bar = Adafruit_24bargraph();
    }

    void begin()
    {
        _bar.begin(0x70);  // pass in the address
    }

    /**
     * Takes a value from 0-1 and draws corresponding bar graph. E.g. 0.5 draws
     * a bar of 12 LEDs, 1 draws 24 LEDS.
     */
    void draw(float value)
    {
        value = value < 0 ? 0 : value;
        value = value > 1 ? 1 : value;
        int numLeds = floor(value * 24);
        int color = LED_YELLOW;
        if (value < _lowThresh)
        {
            color = LED_RED;
        }
        else if (value > _highThresh)
        {
            color = LED_GREEN;
        }

        // Turn off all LEDs
        for (int i=0; i<24; i++)
        {
            _bar.setBar(i, LED_OFF);
        }
        for (int i=0; i<numLeds; i++)
        {
            _bar.setBar(i, color);
        }
        _bar.writeDisplay();
    }

private:
    Adafruit_24bargraph _bar;
    float _lowThresh;
    float _highThresh;
};
