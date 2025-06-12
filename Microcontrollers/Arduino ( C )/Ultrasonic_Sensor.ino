
int trigger = 3;
int ecou = 2;e:\Fisierele mele\Faculta Adi\Informatica + Inteligenta Artificiala\Faculta files\De pe GoogleDRIVE\An 1\Semestru 1\Semestru 1\Arduino\arduino\ceas_a\ceas_a_Bogdan.ino
int dist;
long durat;
void setup() {
 Serial.begin(9600); 
 pinMode(trigger,OUTPUT);
 pinMode(ecou,INPUT);
}

void loop() {
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 
 
 durat = pulseIn(ecou,HIGH);e:\Fisierele mele\Faculta Adi\Informatica + Inteligenta Artificiala\Faculta files\De pe GoogleDRIVE\An 1\Semestru 1\Semestru 1\Arduino\arduino\ceas_b\ceas_b_Bogdan.ino
 dist= durat*0.034/2;
  Serial.print("Distanta!");
 Serial.println(dist);
}

