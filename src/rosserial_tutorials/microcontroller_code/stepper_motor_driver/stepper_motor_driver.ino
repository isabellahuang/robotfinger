int dirPin =7;
int stepperPin = 8;
int anPin1 = 10;
int anPin2 = 11;
float distance = 30; // in unit mm
float rev = distance/3.0; // 3 mm per revolution
void setup() 
{
 pinMode(dirPin, OUTPUT);
 pinMode(stepperPin, OUTPUT);
  Serial.begin(9600);
 execute_one_circle();
 
}

void loop()
{

//digitalWrite(anPin1,LOW);
//digitalWrite(anPin2,LOW);
  //excute_motor();

}

void execute_one_circle() {
  digitalWrite(dirPin,HIGH);
  for (int x=0;x<rev*200;x++){
    digitalWrite(stepperPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepperPin,LOW);
    delayMicroseconds(500);
    }
  delay(1000);
  }
