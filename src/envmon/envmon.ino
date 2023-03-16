#include <ESPmDNS.h>
#include <WebServer.h>
#include <WiFi.h>

#include "envmon.h"
#include "sensors.h"

void setup() {
    init_DHT();
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
    Serial.setDebugOutput(true);

    IPAddress static_IP(192, 168, 107, 101);
    IPAddress gateway(192, 168, 107, 162);
    IPAddress subnet(255, 255, 255, 0);
    IPAddress primary_DNS(1, 1, 1, 1);
    IPAddress secondary_DNS(8, 8, 8, 8);
    if (WiFi.config(static_IP, gateway, subnet, primary_DNS, secondary_DNS) ==
        false) {
        Serial.println("Configuration failed.");
    }

    Serial.printf("Connecting to %s\n", ssid);
    WiFi.begin(ssid, password);
    uint8_t n = 0;
    while (WiFi.status() != WL_CONNECTED) {
        if (n >= 10) {
            Serial.println("Restarting...");
            delay(1000);
            ESP.restart();
            return;
        }
        delay(1000);
        Serial.print(".");
        n++;
    }
    Serial.println("\nWiFi connected.");
    Serial.printf("IP Address: %s:%d\n", WiFi.localIP().toString().c_str(),
                  HTTP_PORT);

    if (MDNS.begin(mdns_url)) {
        Serial.printf("MDNS responder started at: http://%s.local:%d/\n",
                      mdns_url, HTTP_PORT);
    } else {
        Serial.println("Error setting up MDNS responder!");
    }

    delay(100);
    server.enableCORS();
    server.on("/", handle_root);
    server.begin();
    Serial.println("HTTP server started");
    delay(100);
    MDNS.addService("http", "tcp", HTTP_PORT);
}

void loop() {
    delay(100);
    server.handleClient();
}

void handle_root() {
    digitalWrite(LED_PIN, HIGH);
    uint16_t uptime_s = millis() / 1000;
    uint8_t uptime_m = uptime_s / 60;
    uint8_t uptime_h = uptime_m / 60;
    char server_str[strlen(data_str) + 64];
    snprintf(server_str, sizeof(server_str), data_str, get_temp(), get_humid(),
             get_ppm(), uptime_h, uptime_m % 60, uptime_s % 60);
    server.send(200, "application/json", server_str);
    digitalWrite(LED_PIN, LOW);
}
