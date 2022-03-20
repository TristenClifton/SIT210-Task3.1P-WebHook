// This #include statement was automatically added by the Particle IDE.
#include <ThingSpeak.h>

#include "Grove_Temperature_And_Humidity_Sensor.h"
#define APIKEY "HNJZ2J071TJQ03NG"
DHT dht(D2);

int led2 = D0;
int led1 = D6;
int led3 = D7;

void setup() {

    pinMode(led1, OUTPUT);    
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);

    dht.begin();

}

void loop() {  
    
    digitalWrite(led1, HIGH);

    float data;
    data = dht.getTempCelcius();
  
    String temp = "";
    temp.concat((int)data);

    Particle.publish("temprature", temp, PRIVATE);

    delay(1000);
    digitalWrite(led1, LOW);

    delay(29000);   

 
}