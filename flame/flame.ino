#define flamepin 6
#define out 7
#define RainDrop 8
int Flame=HIGH;
int i;
void setup() {
  pinMode(flamepin,INPUT);
  pinMode(out,OUTPUT);
  pinMode(RainDrop,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  Flame=digitalRead(flamepin);
  int Rain=digitalRead(RainDrop);
  if(Flame==LOW)
  {digitalWrite(out,HIGH);}
  else
  {digitalWrite(out,LOW);}
  blink(Rain);
 }

 int blink(int n)
 {
  if(n==1)
  {digitalWrite(LED_BUILTIN,LOW);
   delay(200);}
   else{
   digitalWrite(LED_BUILTIN,HIGH);}
 }
