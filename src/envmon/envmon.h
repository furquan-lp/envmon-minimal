#ifndef ENVMON_H
#define ENVMON_H
#include "CLCD_I2C.h"

#define LED_PIN 13
#define HTTP_PORT 80

const char* ssid = "****";
const char* password = "****";
const char* mdns_url = "esp32env";
char html_data[1000];
char css_data[500];

WebServer server(HTTP_PORT);
CharacterLCD clcd(0x27, 16, 2);

void read_html_css(void);
void handle_root(void);
#endif
