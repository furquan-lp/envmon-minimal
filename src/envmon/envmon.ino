#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "sensors.h"
#include "envmon.h"

void setup() {
    init_DHT();
    pinMode(LED_PIN, OUTPUT);
    
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

    if (MDNS.begin(mdns_url)) {
        Serial.print("MDNS responder started at: http://");
        Serial.print(mdns_url);
        Serial.println(".local/");
    }

    delay(100);
    server.on("/", handle_root);
    server.begin();
    Serial.println("HTTP server started");
    delay(100); 
}

void loop() {
    delay(100);
    server.handleClient();
}

// Update the sensors data in the HTML and handle the root url (/)
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
