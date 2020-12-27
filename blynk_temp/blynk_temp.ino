#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleDHT.h>

char auth[] = "Kx4TY2cEvtfT31okRgN3pU0a2zOc0n9j";
//char auth[] = "Lqc7i1CiMPfGmjeGZP9Ng-XlXNm9p6hW";


char ssid[] = "satyam";
char pass[] = "98765432";

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600
//ESP8266 wifi(&Serial);

const int pinDHT11 = 2;
//const int pinDHT11 = 2
SimpleDHT11 dht11;

//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX

void setup()
{
  Serial.begin(ESP8266_BAUD);
  delay(10);
  //Set ESP8266 baud rate
  //EspSerial.begin(ESP8266_BAUD);
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
    Blynk.email("satyamozar@gmail.com", "ALERT","check your home!!!, fire ALERT!");
    Blynk.notify("Fire ALERT!!!");
  }
}

void loop()
{
  sendSensor();
  Blynk.run();
}
