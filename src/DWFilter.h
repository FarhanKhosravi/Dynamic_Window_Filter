/*
MIT License

Copyright (c) 2025 Farhan Khosravi - http://www.farhankhosravi.ir

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/



// ---------- Dynamic Window Filter for Arduino ---------- //
/* https://github.com/FarhanKhosravi/Dynamic_Window_Filter */



#ifndef DWFilter_h
#define DWFilter_h
#include <Arduino.h>


class DWFilter {
    
private:

    double windowSize;
    double upperBand;
    double lowerBand;


public:

    // Initializes the filter with a given window size
    DWFilter(double windowSize);

    // Gets Unfiltered data & returns the filtered value
    double filter(double inputData);

    double getUpperBand() const;
    double getLowerBand() const;
    double getWindowSize() const;

    void setWindowSize(double size);   // To change the window size 
    void resetFilter();                      // Resets the filter values for sudden input change (If data source is changed, etc)
    
    
};

#endif // DWFilter_h
