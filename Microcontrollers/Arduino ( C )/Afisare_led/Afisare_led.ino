int segA = 6;
int segB = 2;
int segC = 10;
int segD = 12;
int segE = 13;
int segF = 5;
int segG = 9;
int segPt = 11;

int d1 = 7;
int d2 = 4;
int d3 = 3;
int d4 = 8;
int x,y,u,z,s,m,c=4;
int analogPin0 =0, analogPin1= 1;

void setup() {
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segPt, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  x=analogRead(analogPin0);
  y=analogRead(analogPin1);
  afisare(x);
  delay(2000);
  afisare(y);

}
void afisare( int x)
{
  digitalWrite(d1,HIGH);
  digitalWrite(d2,HIGH);
  digitalWrite(d3,HIGH);
  digitalWrite(d4,HIGH);
  u=x%10; 
  z=x/10%10;
  s=x/100%10;
  m=x/1000%10;
  digitalWrite(d4,LOW);
  sendDigit(u);
  delay(5);
  digitalWrite(d4,HIGH);
  digitalWrite(d3,LOW);
  sendDigit(z);
  delay(5);
  digitalWrite(d3,HIGH);
  digitalWrite(d2,LOW);
  sendDigit(s);
  delay(5);
  digitalWrite(d2,HIGH);
  digitalWrite(d1,LOW);
  sendDigit(m);
  delay(5);
  digitalWrite(d1,HIGH);
 }

void one()
{
digitalWrite(segA, LOW);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, LOW);
digitalWrite(segPt, LOW);

}
void two()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, LOW);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, LOW);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void three()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void four()
{
digitalWrite(segA, LOW);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void five()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, LOW);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, LOW);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void six()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, LOW);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void seven()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, LOW);
digitalWrite(segPt, LOW);

}
void eight()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void nine()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, LOW);
digitalWrite(segF, HIGH);
digitalWrite(segG, HIGH);
digitalWrite(segPt, LOW);

}
void zero()
{
digitalWrite(segA, HIGH);
digitalWrite(segB, HIGH);
digitalWrite(segC, HIGH);
digitalWrite(segD, HIGH);
digitalWrite(segE, HIGH);
digitalWrite(segF, HIGH);
digitalWrite(segG, LOW);
digitalWrite(segPt, LOW);

}

void sendDigit(int x)
{
switch(x)
{
  case 1:
    one();
    break;
  case 2:
    two();
    break;
  case 3:
    three();
    break;
  case 4:
    four();
    break;
  case 5:
    five();
    break;
  case 6:
    six();
    break;
  case 7:
    seven();
    break;
  case 8:
    eight();
    break;
  case 9:
    nine();
    break;
  default:
    zero();
    break;
}
}
