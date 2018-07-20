#include <Arduino.h>
#include "DHT.h"
#include "cred.h"

DHT dht11;

void setup()
{
    Serial.begin(9600);
    Serial.println();
    Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
    Serial.println("SSID:");
    Serial.println(SSID);

    dht11.setup(2); // data pin 2
}

void loop()
{
    delay(dht11.getMinimumSamplingPeriod());

    float humidity = dht11.getHumidity();
    float temperature = dht11.getTemperature();

    Serial.print(dht11.getStatusString());
    Serial.print("\t");
    Serial.print(humidity, 1);
    Serial.print("\t\t");
    Serial.print(temperature, 1);
    Serial.print("\t\t");
    Serial.println(dht11.toFahrenheit(temperature), 1);
}
