#ifndef ENVMON_H
#define ENVMON_H

#define LED_PIN 13
#define HTTP_PORT 8888

const char* ssid = "****";
const char* password = "****";
const char* mdns_url = "envmon";
const char* data_str = "[{\"backend\":{\"name\":\"envmon-minimal\",\"version\":\"1.31J\"},\"envdata\":{\"temp\":\"%.2f\",\"humidity\":\"%.2f\"},\"uptime\":{\"hours\":\"%02d\",\"minutes\":\"%02d\",\"seconds\":\"%02d\"}}]";

WebServer server(HTTP_PORT);

void read_html_css(void);
void handle_root(void);
#endif
