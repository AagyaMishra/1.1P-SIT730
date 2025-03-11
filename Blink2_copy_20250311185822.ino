#include <DHT.h>

#define DHTPIN 2     // Pin where the data pin of the sensor is connected
#define DHTTYPE DHT11   // DHT 11 (or DHT22 for more accuracy)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
  
  delay(2000); // Wait 2 seconds before reading again
}

