#ifndef ENVMON_H
#define ENVMON_H
#include "CLCD_I2C.h"

#define LED_PIN 13
#define HTTP_PORT 80

const char* ssid = "****";
const char* password = "****";
const char* mdns_url = "esp32env";
const char* html_data = "<!DOCTYPE html>\
<html>\
<title>ESP32 Environment Monitor</title>\
<style type=\"text/css\">\
body{\
font-family: Sans-Serif;color:#444;\
}\
.esp32data {\
background-color: #FFFFCC\
}\
</style>\
<body>\
<div class=\"esp32data\">\
<h1>ESP32 Environment Monitor v0.x</h1>\
<h2>Temperature: %.2f&deg;C Humidity: %.2f&#37;</h2>\
<h4>Up since %02d:%02d:%02d</h4></div>\
<p style=\"font-family:serif\">Last updated: 2021-10-27 Copyright (C) 2021 Syed Furquan Ahmad</p>\
<script>\
setTimeout(function(){\
window.location.reload(1);\
}, 3000);\
</script>\
<br>\
</body>\
</html>";

WebServer server(HTTP_PORT);
CharacterLCD clcd(0x27, 16, 2);

void handle_root(void);
#endif
