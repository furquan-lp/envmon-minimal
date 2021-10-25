#include <WiFi.h>
#include <WebServer.h>
#include "sensors.h"
#include "envmon.h"

WebServer server(80);

// HTML & CSS
String HTML = String(html_data[0]);

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
    Serial.println("\nWiFi connected successfully");
    Serial.print("Got IP: ");
    Serial.println(WiFi.localIP());

    handle_Strings();
    delay(100);
    server.on("/", handle_root);
    server.begin();
    Serial.println("HTTP server started");
    delay(100); 
}

void loop() {
    digitalWrite(ONBOARD_LED, HIGH);
    handle_Strings();
    delay(100);
    digitalWrite(ONBOARD_LED, LOW);
    server.handleClient();
    delay(2000);
}

// Handle root url (/)
void handle_root() {
    server.send(200, "text/html", HTML);
}

// ** Also handles sensor data
void handle_Strings() {
    String str1 = html_data[0];
    str1.concat(get_temp());
    str1.concat(html_data[1]);
    str1.concat(get_humid());
    str1.concat(html_data[2]);
    HTML = String(str1);
}
