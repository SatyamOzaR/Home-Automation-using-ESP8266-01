// author:- SatyamOzaR
//Note:- This is for ESP8266-01 in Standalone mode

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleDHT.h>

char auth[] = "auth";

char ssid[] = "wifi-name";
char pass[] = "password";

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

const int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup()
{
  Serial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(auth, ssid, pass);
}

void sendSensor()
{
  // start working...
  Serial.println("============^^^^^^^==========^^^^^^^^^==========");
  Serial.println("Sample DHT11...");

  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err); delay(1000);
    return;
  }
  // for debug purposes.
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" H");
  // DHT11 sampling rate is 1HZ.
  delay(1000);
  Blynk.virtualWrite(V6, temperature);
  Blynk.virtualWrite(V5, humidity);
  if ((int)temperature > 25){
    Blynk.email("email-id", "subject","message");
    Blynk.notify("Fire ALERT!!!");
  }
}

void loop()
{
  sendSensor();
  Blynk.run();
}
