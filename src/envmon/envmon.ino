#include <WiFi.h>
#include <WebServer.h>
#include "sensors.h"
#include "envmon.h"

WebServer server(80);

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
    digitalWrite(ONBOARD_LED, HIGH);
    delay(100);
    server.handleClient();
    digitalWrite(ONBOARD_LED, LOW);
    delay(2800);
}

// Update the sensors data in the HTML and handle the root url (/)
void handle_root() {
    char html[strlen(html_data) + 16];
    snprintf(html, sizeof(html), html_data, get_temp(), get_humid());
    server.send(200, "text/html", html);
}
