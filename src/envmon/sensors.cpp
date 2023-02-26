#include "sensors.h"

DHT dht = DHT(DHT_PIN, DHTType);

void init_DHT() { dht.begin(); }

float get_humid() { return dht.readHumidity(); }

float get_temp() { return dht.readTemperature(); }
