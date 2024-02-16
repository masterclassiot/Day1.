#include <DHT.h>

#define DHTPIN 2     // Define the pin to which DHT22 is connected
#define DHTTYPE DHT22 // Define the type of DHT sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(2000); // Delay for 2 seconds between readings

  float temperature = dht.readTemperature(); // Read temperature in Celsius
  float humidity = dht.readHumidity();       // Read humidity

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\t");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
