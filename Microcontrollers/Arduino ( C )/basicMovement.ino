#include <Servo.h>
#include <NewPing.h>

int RIN1 = 7;
int RIN2 = 6;
int LIN3 = 5;
int LIN4 = 4;
int trigger = 9;
int echo = 10;

int distance = 0, duration = 0;

int MAX_DISTANCE = 200;

NewPing sonar(trigger, echo, MAX_DISTANCE);
Servo SM;

void setup() {

  pinMode(RIN1, OUTPUT);
  pinMode(RIN2, OUTPUT);
  pinMode(LIN3, OUTPUT);
  pinMode(LIN4, OUTPUT);
  
  Serial.begin(9600);
  
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
  SM.attach(8);
  SM.write(155);
}

void loop() {
    if(Serial.available()>0){
      char data = Serial.read();
      stopCar();
      switch(data){
      case 'F':
        delay(1000);
        moveForward();
        break;
      case 'S':
        delay(1000);
        stopCar();
        break;
      case 'L':
        delay(1000);
        leftTurn();
        break;
      case 'R':
        delay(1000);
        rightTurn();
        break;
      case 'B':
        delay(1000);
        moveBackwards();
        break;
      case 'M':
        delay(1000);
        manouver();
        break;
      case 'N':
        lookRight();
        delay(1000);
        lookLeft();
        break;
      case 'V':
        delay(1000);
        velo();
        break;
      default: manouver();
        break;
      }
    }
}

int lookRight(){
  SM.write(90);
  delay(400);
  distance = readPing();
  delay(400);
  SM.write(155);
  return distance;
}
int lookLeft(){
  SM.write(180);
  delay(400);
  distance = readPing();
  delay(400);
  SM.write(155);
  return distance;
}
int readPing(){
  int cm = sonar.ping_cm();
  if(cm==0){
    cm=250;
  }
  return cm;  
}
void moveForward(){
  digitalWrite(RIN1, HIGH);
  digitalWrite(RIN2, LOW);
  digitalWrite(LIN3, HIGH);
  digitalWrite(LIN4, LOW);
}
void moveBackwards(){
  digitalWrite(RIN1, LOW);
  digitalWrite(RIN2, HIGH);
  digitalWrite(LIN3, LOW);
  digitalWrite(LIN4, HIGH);
}
void stopCar(){
  digitalWrite(RIN1, LOW);
  digitalWrite(RIN2, LOW);
  digitalWrite(LIN3, LOW);
  digitalWrite(LIN4, LOW);
}
void leftTurn(){
  digitalWrite(RIN1, LOW);
  digitalWrite(RIN2, HIGH);
  digitalWrite(LIN3, HIGH);
  digitalWrite(LIN4, LOW);
  delay(1000);
  moveForward();
}
void rightTurn(){
  digitalWrite(RIN1, HIGH);
  digitalWrite(RIN2, LOW);
  digitalWrite(LIN3, LOW);
  digitalWrite(LIN4, HIGH);
  delay(1000);
  moveForward();
}
int checkDistance(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(4);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  duration = pulseIn(echo,HIGH);
  distance = (duration *10 / 292) / 2;
  delay(50);
  return distance;
}

void advance(){
  distance = checkDistance();
  if(distance <= 35){
    moveForward();
    distance = checkDistance();
    delay(50);
  }else{
    moveBackwards();
    delay(50);
  }
}

void velo(){   
  int distanceL = 0, distanceR = 0;
  distance = checkDistance();
  advance();
  if(distance > 10){
    moveForward();
    distance = checkDistance();
    delay(50);
  }else{
    stopCar();
    delay(1000);
    distance = checkDistance();
    if(distance > 10){
      distanceR = lookRight();
      distanceL = lookLeft();
      delay(1000);
      if(distanceR >= distanceL){
          lookRight();
          delay(1000);
          rightTurn();
          delay(1000);
          stopCar();
      }else{
          lookLeft();
          delay(1000);
          leftTurn();
          delay(1000);
          stopCar();
      }
    }else{
        moveBackwards();
        delay(1000);
        distance = checkDistance();
        delay(1000);
        stopCar();
     }
   }
}

void manouver(){
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(200);
  if(distance > 10){
      moveForward();
      delay(100);
  }else{
      stopCar();
      delay(100);
      moveBackwards();
      delay(400);
      stopCar();
      delay(300);
      distanceRight = lookRight();
      delay(300);
      distanceLeft = lookLeft();
      delay(300);
      if(distanceRight >= distanceLeft){
             rightTurn();
             stopCar();
      }else{
             leftTurn();
             stopCar();
      }         
  }
  distance = checkDistance();
  delay(100);
}
