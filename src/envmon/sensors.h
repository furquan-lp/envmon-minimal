#include <DHT_U.h>
#include <DHT.h>

#define DHT_PIN 4
#define DHTType DHT22
#define MQ_PIN 5

int mq_read(void);
int get_ppm(void);
int get_adjusted_ppm(int, int);

float get_humid(void);
float get_temp(void);
