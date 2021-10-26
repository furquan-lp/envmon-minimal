#include <WiFi.h>
#include <WebServer.h>
#include "sensors.h"
#include "envmon.h"

WebServer server(80);

String HTML = "";
String sensors_data[] = { "unavailable", "unavailable" };

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

    update_html();
    delay(100);
    server.on("/", handle_root);
    server.begin();
    Serial.println("HTTP server started");
    delay(100); 
}

void loop() {
    digitalWrite(ONBOARD_LED, HIGH);
    update_sensors_data();
    update_html();
    delay(100);
    digitalWrite(ONBOARD_LED, LOW);
    server.handleClient();
    delay(2800);
}

// Handle root url (/)
void handle_root() {
    server.send(200, "text/html", HTML);
}

void update_sensors_data() {
    sensors_data[0] = String(get_temp());
    sensors_data[1] = String(get_humid());
}

void update_html() {
    HTML = String(html_data);
    for (uint8_t i = 0; i < 2; i++) {
        String datstr = String(DATA_STR);
        datstr.concat(i);
        HTML.replace(datstr, sensors_data[i]);
    }
}
