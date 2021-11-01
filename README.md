# ![](icon.png) environment-monitor
ESP32 IoT device to monitor environment data and upload it to a webserver

![](https://img.shields.io/github/v/release/furquan-lp/environment-monitor?include_prereleases&style=flat-square) ![](https://img.shields.io/github/release-date/furquan-lp/environment-monitor?style=flat-square) ![](https://img.shields.io/github/license/furquan-lp/environment-monitor?style=flat-square)

![](screenshot.gif)

The Web Server serves a hardcoded HTML page that is updated with the data
using snprintf(). The webpage is reloaded every three seconds using simple
JavaScript code so the sensor data being displayed remains updated.

![](device.gif)

## Features:
* Uses [Arduino-ESP32 by Espressif](https://github.com/espressif/arduino-esp32)
* Programmed in C/C++ and HTML/CSS
* Web Server available on LAN

## Limitations:
* Connections to the server are limited by the WiFi connection

## How to build:
The easiest way to build the project and upload it to an ESP32 board would be
using the [Arduino IDE](https://www.arduino.cc/en/software/).
* Get the [Arduino-ESP32 core](https://github.com/espressif/arduino-esp32)
* Download the Adafruit Unified Sensor library along with the Adafruit DHT22
library from the Library Manager
* Build and upload the code

## To Do:
* Add a library for MQ135
* Add an LCD screen to display the connected IP address for better visibility
