
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include "DHT.h"

#define DHTTYPE DHT11
#define DHTPIN D3
#define valve1 D1
#define valve2 D2


#define moisturePin A0


char ssid[] = "Keerthi";
 
char wifiPassword[] = "12345678";

 
char username[] = "f6895170-c916-11eb-a2e4-b32ea624e442";
char password[] = "5461705d5593d7c76fb3ca09349df28091897ab7";
char clientID[] = "5bef1b80-c9c1-11eb-883c-638d8ce4c23d";

unsigned long lastMillis = 0;
int motor=D8;
//int Flame=HIGH;
float moisturePercentage;
DHT dht(DHTPIN, DHTTYPE);
//int FlameValue=0;


void setup() {
 Serial.begin(9600);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  dht.begin();
  
  pinMode(motor,OUTPUT);
  pinMode(valve1,OUTPUT);
  pinMode(valve2,OUTPUT);
  digitalWrite(motor,HIGH);
 
  
}

void loop() {
  Cayenne.loop();
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   moisturePercentage = ( 100.00 - ( (analogRead(moisturePin) / 1023.00) * 100.00 ));


    //checing SoilMoisture percent
    if(moisturePercentage>=45)
   {digitalWrite(valve1,HIGH);
   digitalWrite(valve2,HIGH);
   }
   else
   {digitalWrite(valve1,LOW);
   digitalWrite(valve2,LOW);
}
    // Writing in Cayenne Dashboard
   Cayenne.celsiusWrite(1, t);
   Cayenne.virtualWrite(2,h,TYPE_RELATIVE_HUMIDITY,UNIT_PERCENT);
   Cayenne.virtualWrite(3,moisturePercentage);
   }
 
 
 //getting data from iot dashboard 

CAYENNE_IN(0){
digitalWrite(motor,!getValue.asInt());
}


 
