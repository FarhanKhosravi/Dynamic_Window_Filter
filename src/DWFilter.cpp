/************************************

 ----- Dynamic Window Filter for Arduino / version 1.0.2 / May 2025 -----
 -----      By Farhan Khosravi / Licensed under the MIT License     -----


 * This is a Super-Simple, Fast and Lighweight Filter for smoothing data of
   Slow-Response Sensors like Temperature, Humidity, etc.
 * perfectly suitable for Arduino, ESP32/ESP8266, STM32 and every ArduinoIDE
   Compatible boards/uCs.
 * will be available on Arduino Library Manager.

 * Find more info on GitHub:
   https://github.com/FarhanKhosravi/Dynamic_Window_Filter

************************************/


#include "DWFilter.h"


DWFilter::DWFilter(double windowSize) : windowSize(windowSize), upperBand(0), lowerBand(0) {}


double DWFilter::filter(double input) {

    if (input > upperBand)
    {
        upperBand = input;
        lowerBand = upperBand - windowSize;
    }
    else if (input < lowerBand)
    {
        lowerBand = input;
        upperBand = lowerBand + windowSize;
    }

    return (upperBand + lowerBand) / 2;
}


double DWFilter::getUpperBand() const {
    return upperBand;
}

double DWFilter::getLowerBand() const {
    return lowerBand;
}

double DWFilter::getWindowSize() const {
    return windowSize;
}

void DWFilter::setWindowSize(double size) {
    this->windowSize = size;
}

void DWFilter::resetFilter() {
    upperBand = 0;
    lowerBand = 0;
}

