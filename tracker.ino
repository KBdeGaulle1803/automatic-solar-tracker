#include <Servo.h>

Servo azith1, azith2,  elev;
int currpos_hor=1950;
int currpos_ver=1500;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  azith1.attach(3);
  elev.attach(4);
  azith2.attach(5);
  Serial.begin(9600);
}

void loop() {
  int v1= analogRead(A0);
  int v2= analogRead(A1);
  int v3= analogRead(A2);
  int v4= analogRead(A3);
  Serial.print(v1);
  Serial.print(',');
  Serial.print(v2);
  Serial.print(',');
  Serial.print(v3);
  Serial.print(',');
  Serial.println(v4);
  Serial.print(currpos_hor);
  Serial.print(',');
  Serial.println(currpos_ver);
  int a= (float)(((v4+v2)/2)-((v3+v1)/2));
  int a2= (abs(a)>=50)?3:(abs(a)>=35)?2:(abs(a)>=25)?1:0;
  a2*=a/abs(a); 
  currpos_hor+=a2;
  currpos_hor= constrain(currpos_hor,325,3575);
  a= (float)(((v1+v2)/2)-((v3+v4)/2));
  a2= (abs(a)>=50)?3:(abs(a)>=35)?2:(abs(a)>=25)?1:0;
  a2*=a/abs(a);
  currpos_ver-=a2;
  currpos_ver= constrain(currpos_ver,1000,2000);
  write360(currpos_hor);
  elev.writeMicroseconds(currpos_ver);
  delay(10);
}

void write360(int pos){
  int a= pos/2;
  azith1.writeMicroseconds(550+a);
  azith2.writeMicroseconds(550+pos-a);
}
