# Dynamic Window Filter (DWFilter)  [![arduino-library-badge](https://www.ardu-badge.com/badge/Dynamic%20Window%20Filter.svg?)](https://www.ardu-badge.com/Dynamic%20Window%20Filter)

"Dynamic Window Filter" is an **Innovative Method** with an **Ultra-Lightweight** library for filtering and smoothing Slow-Rate incoming data (*from slow sensors, etc.*) without **time lag** and **delay**.
It is best used with slow sensors like **Temperature, Humidity, etc.** (e.g. <ins>MAX6675</ins> for Thermocouple reading); and uses a very small number of **clock cycles** due to its **simple, yet practical** function.

It also suppresses unwanted **direction changes** in the input data, making it ready for sensitive measurements like <ins>**PID Systems**</ins> *(as the **D term** is very sensitive to sudden changes)*

**There are a few examples below for further clarification:**


## How It Works :
This method uses a **Window Size** specified by user, to create a window of that size. When new data is received, if it falls within the window range, the window remains unchanged, and the output value is set to the midpoint of the window. Otherwise, the window shifts up or down accordingly.
> The Window Size should be chosen based on **how much your data scatters**. It is best to select a size **slightly larger** than the noise range.

Here is an example of appropriate Window Size selection:
![Screenshot (327)](https://github.com/user-attachments/assets/35326bae-d10e-4c69-9f86-7090400dcd15)

## How it Improves measurements like PID:
As you know, When using a common temperature sensor (like <ins>MAX6675</ins>) new data is available only every **250ms** and it often has a significant scatter. This prevents typical averaging methods from being effective due to time lags and slow responses.
For smooth PID Control, a stable input is essential. and this method helps you to eliminate noises and even increase accuracy of your data.

***In the image below, you can see raw sensor readings, which still fluctuate even when using a moving average. The filtered data, however, moves consistently in a single direction, making measurements like PID much more reliable:***
![Screenshot (700)](https://github.com/user-attachments/assets/7b8fa1b4-ed46-4338-a460-00bbd4ee7227)

**__This Makes your D Term in PID to work correctly; and not taking derivate on false movements (that makes PID unstable).__**

the result of correctly tuned PID with PWFilter, **even with a low-res thermocouple reader** like MAX6675 will be something like this:
![Screenshot (67f)](https://github.com/user-attachments/assets/03e7ab2d-6058-4120-9d7c-04bc3792c394)
> *In the end, we achieved stable precision down to **one decimal place** with that sensor too!* Feel free to use it in your project—just be sure to select the right window size.

