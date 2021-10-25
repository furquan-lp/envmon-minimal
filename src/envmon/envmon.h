#ifndef ENVMON_H
#define ENVMON_H

#define ONBOARD_LED 2

const char* ssid = "****";
const char* password = "****";

String html_data[] = { "<!DOCTYPE html>\
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
<h2>Temperature: ", "&deg;C Humidity: ", "%</h2></div>\
<p style=\"font-family:serif\">Copyright (C) 2021 Syed Furquan Ahmad</p>\
<script>\
setTimeout(function(){\
window.location.reload(1);\
}, 3000);\
</script>\
<br>\
</body>\
</html>"
};

const int html_data_length = 3;

void handle_root(void);
void update_sensor_data(void);
void handle_Strings(void);
#endif
