#define flamepin 6
#define out 7
#define RainDrop 8
int Flame=HIGH;
void setup() {
  pinMode(flamepin,INPUT);
  pinMode(out,OUTPUT);
  pinMode(RainDrop,INPUT);
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  Flame=digitalRead(flamepin);
  if(Flame==LOW)
  {digitalWrite(out,HIGH);}
  //digitalWrite(valve,LOW);}
  else
  {digitalWrite(out,LOW);
  //digitalWrite(valve,HIGH);
  }

}
