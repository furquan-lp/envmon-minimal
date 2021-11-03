#ifndef ENVMON_H
#define ENVMON_H
#include "CLCD_I2C.h"

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
CharacterLCD clcd(0x27, 16, 2);

void read_html_css(void);
void show_err_lcd(const char* line1, const char* line2);
void handle_root(void);
#endif
