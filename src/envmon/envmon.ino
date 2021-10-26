#include <WiFi.h>
#include <WebServer.h>
#include "sensors.h"
#include "envmon.h"

WebServer server(80);

uint16_t uptime_s = 0;
uint8_t uptime_m = 0;

void setup() {
    init_DHT();
    pinMode(ONBOARD_LED, OUTPUT);
    
    Serial.begin(115200);
    Serial.println("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    delay(100);
    server.on("/", handle_root);
    server.begin();
    Serial.println("HTTP server started");
    delay(100); 
}

void loop() {
    if (uptime_s >= 59) {
        uptime_s = 0;
        uptime_m++;
    }
    digitalWrite(ONBOARD_LED, HIGH);
    delay(100);
    server.handleClient();
    digitalWrite(ONBOARD_LED, LOW);
    delay(2800);
    uptime_s += 3;
}

// Update the sensors data in the HTML and handle the root url (/)
void handle_root() {
    char html[strlen(html_data) + 32];
    snprintf(html, sizeof(html), html_data, get_temp(), get_humid(), uptime_m, uptime_s);
    server.send(200, "text/html", html);
}
