#ifndef ENVMON_H
#define ENVMON_H

#define ONBOARD_LED 2
#define DATA_STR "DATA"

const char* ssid = "****";
const char* password = "****";

PROGMEM String html_data = "<!DOCTYPE html>\
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
<h2>Temperature: DATA0&deg;C Humidity: DATA1%</h2></div>\
<p style=\"font-family:serif\">Copyright (C) 2021 Syed Furquan Ahmad</p>\
<script>\
setTimeout(function(){\
window.location.reload(1);\
}, 3000);\
</script>\
<br>\
</body>\
</html>";

void handle_root(void);
void update_sensors_data(void);
void update_html(void);
#endif
