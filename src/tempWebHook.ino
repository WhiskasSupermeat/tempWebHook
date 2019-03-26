#include "Adafruit_DHT.h"

// DHT parameters
#define DHTPIN 5
#define DHTTYPE DHT11

int led = D7;  // The on-board LED. The LED will light up for 3 secs
int temperature;
// int humidity;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED to show temp is being read and uploaded.
  temperature = dht.getTempCelcius();
//  humidity = dht.getHumidity();

  Particle.publish("temp", String(temperature), PRIVATE);
//  Particle.publish("humidity", String(humidity), PRIVATE);
  delay(3000); // wait 3 seconds so the LED can be seen
  digitalWrite(led, LOW);   // Turn OFF the LED to show no activity
  delay(27000);
}
