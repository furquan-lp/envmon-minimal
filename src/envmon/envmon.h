#ifndef ENVMON_H
#define ENVMON_H

#define LED_PIN 13
#define HTTP_PORT 80

const char* ssid = "****";
const char* password = "****";
const char* mdns_url = "esp32env";
const char* data_str = "%.2f %.2f %02d %02d %02d";

WebServer server(HTTP_PORT);

void read_html_css(void);
void handle_root(void);
#endif
