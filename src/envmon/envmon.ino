#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <SPIFFS.h>
#include "sensors.h"
#include "envmon.h"

void setup() {
    init_DHT();
    pinMode(LED_PIN, OUTPUT);
    clcd.init();
    Serial.begin(115200);

    if(!SPIFFS.begin(true)){
        show_err_lcd("Filesystem Error", "Stop.");
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
    read_html_css();

    Serial.println("Connecting to ");
    Serial.println(ssid);
    clcd.clearLCD();
    clcd.printLCD("Connecting WiFi");
    WiFi.begin(ssid, password);
    clcd.selectLine(1);
    uint8_t n = 0;
    while (WiFi.status() != WL_CONNECTED) {
        if (n >= 10) {
            show_err_lcd("WiFi failed.", "Rebooting...");
            delay(1000);
            ESP.restart();
            return;
        }
        delay(1000);
        Serial.print(".");
        clcd.printLCD(".");
        n++;
    }
    clcd.clearLCD();
    Serial.println("\nWiFi connected");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    clcd.printLCD(WiFi.localIP().toString());

    if (MDNS.begin(mdns_url)) {
        Serial.print("MDNS responder started at: http://");
        Serial.print(mdns_url);
        Serial.println(".local/");
        char url[16];
        sprintf(url, "%s.local/", mdns_url);
        clcd.printAt(url, 1);
    } else {
        Serial.println("Error setting up MDNS responder!");
        clcd.printAt("MDNS.begin fail.", 1);
    }

    delay(100);
    server.on("/", handle_root);
    server.on("/style.css", []() {
        server.send(200, "text/css", css_data);
    });
    server.begin();
    Serial.println("HTTP server started");
    delay(100);
    MDNS.addService("http", "tcp", HTTP_PORT);
}

void loop() {
    delay(100);
    server.handleClient();
}

void read_html_css() {
    File html = SPIFFS.open("/index.html", "r");
    File css = SPIFFS.open("/style.css", "r");
    if (!html) {
        show_err_lcd("index.html fail", "Stop.");
        Serial.println("Failed to open index.html");
        return;
    }
    for (int i = 0; html.available() && i < HTML_DATA_BUF; i++) {
        html_data[i] = html.read();
    }
    for (int i = 0; css.available() && i < CSS_DATA_BUF; i++) {
        css_data[i] = css.read();
    }
    html.close();
    css.close();
}

void show_err_lcd(const char* line1, const char* line2) {
    clcd.clearLCD();
    clcd.printLCD(line1);
    clcd.printAt(line2, 1);
}

void handle_root() {
    digitalWrite(LED_PIN, HIGH);
    uint16_t uptime_s = millis() / 1000;
    uint8_t uptime_m = uptime_s / 60;
    uint8_t uptime_h = uptime_m / 60;
    char html[strlen(html_data) + 32];
    snprintf(html, sizeof(html), html_data, get_temp(), get_humid(), uptime_h, uptime_m % 60, uptime_s % 60);
    server.send(200, "text/html", html);
    digitalWrite(LED_PIN, LOW);
}
