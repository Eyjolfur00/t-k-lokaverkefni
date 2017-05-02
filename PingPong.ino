const int TrigPin = 2;//Trig attach to pin2
const int EchoPin = 3;//Echo attach to pin3
float cm; // fjöldi cm sem mældir eru
int statep = 0;
int pera1 = 4;
int joystick = 1;
int stickR = 0;
int Rot = 0;
int Hnappur = 13;
int stickH = LOW;
int stickHlast = LOW;
int state = 0;
int Rotary = 0;
int Rtel = 0;
#include <Servo.h> //using the servo library
Servo myservo; // create an servo object



void setup()
{
   Serial.begin(9600); //Sets the data rate in bits per second (baud) for serial data transmission
   //set the below pins as OUTPUT
   pinMode(TrigPin,OUTPUT);
   pinMode(EchoPin,INPUT);
   pinMode(pera1,OUTPUT);
   myservo.attach(9);
   pinMode(Hnappur,INPUT_PULLUP);
}

void loop () {
  stickR = analogRead(joystick);
  Rot=stickR;
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  stickH=digitalRead(Hnappur);
  stickHlast = stickH;
  
  
  cm = pulseIn(EchoPin,HIGH)/58.0;  
  cm = (int(cm * 100.0))/100.0;

  if (stickHlast = LOW){
    if(stickH = HIGH){
      state++;
      state=state%2;
      Rtel=map(stickR, 0, 1023, 0, 180);
    }
  }



  if(state=0){
    Rot=stickR;
    Rot = map(Rot, 0, 1023, 0, 180);
  }
  if(state=1){
    Rotary = abs((Rtel%360)-180);
    Rot = Rotary;
    Rtel++;
    Rtel = Rtel%360;
    }


  
  if(cm < 0)
  {
    cm = 0;
  }
  statep = 0;
  if(cm < 20 and cm > 0){
    statep = 1;
  }
  myservo.write(Rot); 
  digitalWrite(pera1,statep);
  Serial.print("Controlstick: ");
  Serial.print(stickR);
  Serial.print(" , cm: ");
  Serial.print(cm);
  Serial.print(" , Hnappur: ");
  Serial.print(stickH);
  Serial.print(" , LastHnappur: ");
  Serial.println(stickHlast);
}
