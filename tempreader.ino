// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>


#define DHTPIN 3     // connected to pin D3
#define DHTTYPE DHT11		// DHT 11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Subscribe to the integration response event
  Particle.subscribe("hook-response/temp", myHandler, MY_DEVICES);
  Particle.subscribe("hook-response/humidity", myHandler, MY_DEVICES);
}

void myHandler(const char *event, const char *data) {
  // Handle the integration response
}

void loop() {

// Read temperature as Celsius and Humidity
  float t = dht.getTempCelcius();
  float h = dht.getHumidity();
  
  String temp = String(t);
  String humidity = String(h);

  Particle.publish("temp", temp, PRIVATE);
  Particle.publish("humidity", humidity, PRIVATE);

  delay(30000);

}