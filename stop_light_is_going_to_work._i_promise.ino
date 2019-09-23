#include <Servo.h>

 
//programming a stop light\\


int NSred = 12;
int NSyellow = 11;
int NSgreen = 10;
int NSbutton = 9;
int NSturn = 8;

int EWred = 7;
int EWyellow = 6;
int EWgreen = 5;
int EWbutton = 4;
int EWturn = 3;

int sound = 13;

//int turndown = 2;

Servo turndown;
int angle = 0;


void setup() {
  // put your setup code here, to run once:

pinMode(NSred, OUTPUT);
pinMode(NSyellow, OUTPUT);
pinMode(NSgreen, OUTPUT);
pinMode(NSbutton, INPUT);
pinMode(NSturn, OUTPUT);

pinMode(EWred, OUTPUT);
pinMode(EWyellow, OUTPUT);
pinMode(EWgreen, OUTPUT);
pinMode(EWbutton, INPUT);
pinMode(EWturn, OUTPUT);

pinMode(sound, OUTPUT);

//pinMode(turndown, OUTPUT);

turndown.attach(2);
turndown.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(NSred, LOW);
digitalWrite(NSyellow, LOW);
digitalWrite(EWyellow, LOW);
digitalWrite(EWgreen, LOW);
digitalWrite(NSgreen, HIGH);
digitalWrite(EWred, HIGH);
tone(sound, 330);
for(angle = 0; angle < 90; angle += 1) {
turndown.write(angle);
delay(15);
}
noTone(sound);
delay(5000);

digitalWrite(NSgreen, LOW);
digitalWrite(NSyellow, HIGH);
delay(2000);

digitalWrite(NSyellow, LOW);
digitalWrite(NSred, HIGH);
digitalWrite(EWred, LOW);
digitalWrite(EWgreen, HIGH);
turndown.write(0);
delay(5000);

digitalWrite(EWgreen, LOW);
digitalWrite(EWyellow, HIGH);
delay(2000);

digitalWrite(EWyellow, LOW);
digitalWrite(EWred, HIGH);
delay(1000);



if (digitalRead(NSbutton) == LOW) {

digitalWrite(NSturn, HIGH);
delay(3000);

digitalWrite(NSturn, LOW);

}


if (digitalRead(EWbutton) == LOW) {

digitalWrite(EWturn, HIGH);
delay(3000);

digitalWrite(EWturn, LOW);

}

}
