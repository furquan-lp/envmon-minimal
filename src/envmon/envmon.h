#ifndef ENVMON_H
#define ENVMON_H

#define ONBOARD_LED 2

const char* ssid = "****";
const char* password = "****";
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
<h4>Up since %d:%d</h4></div>\
<p style=\"font-family:serif\">Last updated: 2021-10-26 Copyright (C) 2021 Syed Furquan Ahmad</p>\
<script>\
setTimeout(function(){\
window.location.reload(1);\
}, 3000);\
</script>\
<br>\
</body>\
</html>";

WebServer server(80);

void handle_root(void);
#endif
