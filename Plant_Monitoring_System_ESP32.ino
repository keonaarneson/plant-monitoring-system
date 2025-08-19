#include <DHT.h>

DHT dht(33, DHT11); //sets the pin, sets the DHT model

const int dry = 2500;

void setup() {
  Serial.begin(9600); //set baud rate

  dht.begin();

  pinMode(19, OUTPUT);
}

void loop() {
  delay(2000); //delay for 2 seconds

  float hum = dht.readHumidity(); //reads humidity with DHT11
  float tempF = dht.readTemperature(true); //reads temperature(°F) with DHT11
  float tempC = dht.readTemperature(); //reads temperature(°C) with DHT11
  float mois = analogRead(25); //reads a moisture value with Moistuer Sensor V2
  
  if (mois <= dry) {
    digitalWrite(19, LOW);
    Serial.println("Not Watering");
  } else {
    digitalWrite(19, HIGH);
    Serial.println("Pumping Water");
  }

  Serial.print("Humidity: "); //Prints Humidity line
  Serial.print(hum);
  Serial.println("%");

  Serial.print("Temperature: "); //Prints temperature line
  Serial.print(tempF);
  Serial.print("°F");
  Serial.print(" / ");
  Serial.print(tempC);
  Serial.println("°C");

  Serial.print("Moisture Value: ");
  Serial.println(mois);
}
