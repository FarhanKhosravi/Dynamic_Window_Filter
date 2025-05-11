# Dynamic Window Filter (DWFilter)   [![arduino-library-badge](https://www.ardu-badge.com/badge/Dynamic%20Window%20Filter.svg?)](https://www.ardu-badge.com/Dynamic%20Window%20Filter)
"Dynamic Window Filter" is an <ins>**Innovatiove Method**</ins> with an **Ultra-Lightweight** library for filtering and smoothing Slow-Rate incoming data (*from slow sensors, etc.*) without **time lag** and **delay**.
It has the best usage with slow sensors like **Temperature, Humidity, etc.** (i.g. <ins>MAX6675</ins> For Thermocouple reading); and uses very low amount of **clock cycles** due to it's **simple, but <ins>practical**</ins> function.

It also suppresses unwanted **direction changes** in the input data, making it ready for sensitive measurements like <ins>**PID Systems**</ins> *(as the **D term** is very sensitive to sudden changes)*

**there's few examples below for more declaration:**


## How It Works :
This method uses a **Window Size** specified by user, and creates a window with that size. then receives new data and if it was within the window range, the window stays remain and your value will be the middle point of the window. elsewhere it will move downside/upside accordingly.
> The Window Size must be selected according to **how much your data scatters**. best to select the size by *a bit more* than noise range.

Here is an example of appropriate Window Size selection:
![Screenshot (327)](https://github.com/user-attachments/assets/35326bae-d10e-4c69-9f86-7090400dcd15)

## How it Improves measurements like PID:
As you know, if you use a common temperature sensor (like <ins>MAX6675</ins>) you can only read new data every **250ms** and with a big scattering range. this prevents us to use typical averagings due to time lags and slow responses.
If you want a smooth PID Control, you need a stable input. and this method helps you to eliminate noises and even increase accuracy of your data.

***in the picture below, you can see sensor readings that even with using a moving average, it tolerants a lot. and the filtered data that moves only in one direction and makes measurements like PID a lot better:***
![Screenshot (700)](https://github.com/user-attachments/assets/7b8fa1b4-ed46-4338-a460-00bbd4ee7227)

**__This Makes your D Term in PID to work correctly; and not taking derivate on false movements (that makes PID unstable).__**

the result of correctly tuned PID with PWFilter, **even with a low-res thermocouple reader** like MAX6675 will be something like this:
![Screenshot (67f)](https://github.com/user-attachments/assets/03e7ab2d-6058-4120-9d7c-04bc3792c394)
> *At the end, we even got a stable resolution of **one decimal point** from that sensor too!* feel free to use it on your project, just making sure that you've selected right window size.

