#include <Servo.h>
Servo myservo;
int pos=0;
void setup() {
  myservo.attach(2);
}

void loop() {
   for(pos=0; pos<180; pos++){
     myservo.write(pos);
     delay(100);
   }
   for(pos=180; pos>=0; pos--){
      myservo.write(pos);
     delay(100);
   }
}
