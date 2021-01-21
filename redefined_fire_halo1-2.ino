const int tempPin = 0;
int TransistorPin = 9;
int LM35Value=0;
int maxC=47;
int Mspeed;
float temp;

void setup() 
{
     pinMode (tempPin,INPUT);
     pinMode (TransistorPin,OUTPUT);
     Serial.begin(9600);
}

void loop() 
{
    int temp= ((5.0*analogRead(tempPin))*100.0)/1024.0;
  	const int alarm = 11;
  	int cTemp = (5.0/9) * (temp - 32);
    Serial.print(cTemp);
    Serial.println(" degree C");
 	delay(500);
  
  if (cTemp>=maxC) 
  {
    Mspeed =cTemp*1,75;
	analogWrite (TransistorPin,Mspeed);
    Serial.print("DANGER: GROUNDFIRE WARNING ");
    tone(alarm, 2000);
  }
  else
  {
    Serial.print("Temperature is OKAY ");
    noTone(11);
  }
}