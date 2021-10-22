#ifndef ENVMON_H
#define ENVMON_H

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
Copyright (C) 2021 Syed Furquan Ahmad\
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
#endif
