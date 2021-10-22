const char* ssid = "****";
const char* password = "****";

String html_data[] = { "<!DOCTYPE html>\
<html>\
<title>ESP32 Environment Monitor</title>\
<style type=\"text/css\">\
body{\
font-family: Sans-Serif;color:#444;\
}\
</style>\
<body>\
<h1>ESP32 Environment Monitor v0.x</h1>\
<h2>Temperature: ", "*C Humidity: ", "%</h2><script>\
setTimeout(function(){\
window.location.reload(1);\
}, 3000);\
</script>\
</body>\
</html>"
};

const int html_data_length = 3;
