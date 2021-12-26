#ifndef ENVMON_H
#define ENVMON_H

#define LED_PIN 13
#define HTTP_PORT 80
#define HTML_DATA_BUF 1000
#define CSS_DATA_BUF 500

const char* ssid = "****";
const char* password = "****";
const char* mdns_url = "esp32env";
char html_data[HTML_DATA_BUF];
char css_data[CSS_DATA_BUF];

WebServer server(HTTP_PORT);

void read_html_css(void);
void handle_root(void);
#endif
