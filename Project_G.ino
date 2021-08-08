#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include "DHT.h"

#define DHTTYPE DHT11
#define DHTPIN D3
#define valve1 D1
#define valve2 D2
//#define flamePin D4
//#define buzzer D5
#define RaindropSensor D0
#define RainLed D6 
#define moisturePin A0


char ssid[] = "Ranga";
char wifiPassword[] = "9480282010";

 
char username[] = "7a203260-f3a3-11e9-84bb-8f71124cfdfb";
char password[] = "eadd436cf23d25093c463c77a1b6f17fc5b5b672";
char clientID[] = "9990db40-f833-11eb-b767-3f1a8f1211ba";

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
  //pinMode(flamePin,INPUT);
  pinMode(motor,OUTPUT);
  pinMode(valve1,OUTPUT);
  pinMode(valve2,OUTPUT);
//  pinMode(buzzer,OUTPUT);
  pinMode(RaindropSensor,INPUT);
  pinMode(RainLed,OUTPUT);

  digitalWrite(motor,HIGH);
//  digitalWrite(buzzer,HIGH);  
  
}

void loop() {
  Cayenne.loop();
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   moisturePercentage = ( 100.00 - ( (analogRead(moisturePin) / 1023.00) * 100.00 ))+10;
   
   //DETECT THE RAIN
   bool DetectRain=digitalRead(RaindropSensor);
   if(DetectRain==HIGH){
    digitalWrite(RainLed,HIGH);
   }
   else{
    digitalWrite(RainLed,LOW);
   }
   
   
   /*Flame=digitalRead(flamePin);

   //Checking whether there is flame source or not
   if(Flame==HIGH){
    FlameValue=5;//random value for mapping high
    digitalWrite(buzzer,HIGH);
   }
   else if (Flame==LOW){
    FlameValue=8;
    digitalWrite(buzzer,LOW);} */


    //checing SoilMoisture percent
    if(moisturePercentage>=45)
   {digitalWrite(valve1,HIGH);
   digitalWrite(valve2,HIGH);
   }
   else
   {digitalWrite(valve1,HIGH);
   digitalWrite(valve2,HIGH);
}
    
    
    
    
    // Writing in Cayenne Dashboard
   Cayenne.celsiusWrite(1, t);
   Cayenne.virtualWrite(2,h,TYPE_RELATIVE_HUMIDITY,UNIT_PERCENT);
   Cayenne.virtualWrite(3,moisturePercentage);
   Cayenne.virtualWrite(6,FlameValue);
   }
 
 
 //getting data from iot dashboard 

CAYENNE_IN(0){
digitalWrite(motor,!getValue.asInt());
}


 
