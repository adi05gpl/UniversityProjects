int pin = 8;
int obs;
int citire=0;
int obstacol=0;
 
 
void setup() {
  pinMode(pin, INPUT);
  Serial.begin(9600);
}
 
void loop() {
  obs = digitalRead(pin);
 
  if (obs == LOW){
    obstacol=obstacol+1;
    }
    citire=citire+1;
  if (citire==8)
  {
    if(obstacol>4)
       Serial.print("Exista un obstacol ");
 
  else
      Serial.print("Nu exista un obstacol ");
  obstacol=0;
  citire=0;
  delay(500);
  }
}

