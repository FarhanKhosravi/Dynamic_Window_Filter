/***********************************************************
 -------------- Dynamic Window Filter Example --------------
 ------ By Farhan Khosravi | http://farhankhosravi.ir ------

 * This simple example is for showing up how to use this minimal
 Library to make your Slow-Rate data more smooth.

 * In here we used random() function to simulate a slow responding
 sensor like "MAX6675" and a slight increment in the temprature.

 * As you'll see in the Serial Plotter, The sensor data is 
 scattered and noisy, but "Filtered Data" is smooth and it 
 only moves on the True direction.

 * This is an important factor in systems like PID, as the D term
 is very sensitive to wrong direction changes. Change and use the
 functions as you need.

 ***********************************************************/



#include <DWFilter.h>  // Including the library



// Make Window Size smaller/bigger if data scatter is less/more
// (For MAX6675 the optimal WindowSize is ~0.6 | suggested to use a simple moving average before DWFilter for better results)
#define WindowSize 5

// Initialize Filter with the given Window Size
DWFilter myFilter(WindowSize);



float n = 0;           // Value for heat increment simulation


void setup() {
  // Begin Serial for the plotter
  Serial.begin(9600);
}


void loop() {

  n += 0.1;     // Slight temperature increment in every loop

  // Generating random data in the range of 5 (=> +-2.5) to simulate sensor scattered data
  float data = random(n, n + 5);

  // Showing results in the Plotter
  Serial.print("Data:");
  Serial.print(data);
  Serial.print("\t");
  Serial.print("FilteredData:");
  Serial.print(myFilter.filter(data));     // filter() function receives your data, returning the filtered value
  Serial.print("\t");

  // Here we show upper & lower boundaries for better illustration - helps you find the best Window Size
  Serial.print("UpperBand:");
  Serial.print(myFilter.getUpperBand());
  Serial.print("\t");
  Serial.print("LowerBand:");
  Serial.println(myFilter.getLowerBand());

  delay(100); // Simulating slow sensor sendings
}
