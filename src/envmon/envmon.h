#ifndef ENVMON_H
#define ENVMON_H

#define LED_PIN 13
#define HTTP_PORT 80

const char* ssid = "****";
const char* password = "****";
const char* mdns_url = "esp32env";
const char* data_str = "[{\"backend\":\"envmon-minimal\",\"version\":\"1.3J\",\"temp\":\"%.2f\",\"humidity\":\"%.2f\",\"hours\":\"%02d\",\"minutes\":\"%02d\",\"seconds\":\"%02d\"}]";

WebServer server(HTTP_PORT);

void read_html_css(void);
void handle_root(void);
#endif
