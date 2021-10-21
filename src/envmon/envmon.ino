#include <WiFi.h>
#include <WebServer.h>

int count = 0;
const char* ssid = "****";
const char* password = "****";

WebServer server(8888);

String html1 = "<!DOCTYPE html>\
<html>\
<body>\
<h1>ESP32 Web Server</h1>\
<h1>Count: ";
String html2 = "</h1>\
</body>\
</html>";
// HTML & CSS
String HTML = String(html1);

void setup() {
	Serial.begin(115200);
	Serial.println("Try Connecting to ");
	Serial.println(ssid);

	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED) {
		delay(1000);
		Serial.print(".");
	}
	Serial.println("");
	Serial.println("WiFi connected successfully");
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
	handle_Strings();
	delay(100);
	server.handleClient();
	delay(1000);
	count++;
}

// Handle root url (/)
void handle_root() {
	server.send(200, "text/html", HTML);
}

void handle_Strings() {
	String str1 = html1;
	String str2 = html2;
	str1.concat(count);
	str1.concat(html2);
	HTML = String(str1);
}
