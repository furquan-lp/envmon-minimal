# environment-monitor
ESP32 IoT device to monitor environment data and upload it to a webserver

![](screenshot.png)

## Features:
* [Written in JavaScript](fs/init.js)
* Runs on Mongoose OS (https://mongoose-os.com/mos.html) IoT platform
* Uses multiple sensors to measure temperature, humidity and [air quality coefficient](https://components101.com/sites/default/files/inline-images/MQ135-Sensitvity-Characteri.png) (pollution)
* Upload to a webserver accessible through the Internet

## Disadvantages:
* Slow build time due to limitations of Mongoose OS

## How to build:
* Clone the repository
* Run Mongoose os
```
  $ mos
```
* Build the firmware
```
  /environment-monitor mos build
```
* Flash the firmware
```
 /environment-monitor mos flash
```
* Reboot the device using `Ctrl`+`u`

* Connect to your local WiFi to enable networking
```
 mos wifi [network name] [password]
```

Work in progress
