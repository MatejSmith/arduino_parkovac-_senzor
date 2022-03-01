//Parkovací senzor, Matej Kováč, 3.AI
int buzPin = 2;
int trigPin = 0;
int echoPin = 1;
int greenPin = 3;
int yellowPin = 4;
int redPin = 5;
float speed = 0.0347;
float dist;
float pingTime;
int buzNear = 20;
int buzHigh = 50;
int buzMid  =130;
int buzFar = 200;
int delayFar = 500;


void setup() {
  pinMode(buzPin,OUTPUT);
  pinMode(trigPin,OUTPUT);    
  pinMode(echoPin,INPUT);
  pinMode(redPin,OUTPUT);
  pinMode(yellowPin,OUTPUT);
  pinMode(greenPin,OUTPUT);

}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pingTime = pulseIn(echoPin,HIGH);
  dist = (speed*pingTime*0.5);
  
  if(dist<=10.0){
    digitalWrite(buzPin,HIGH);
    digitalWrite(redPin, HIGH);
    delay(buzNear);
    digitalWrite(buzPin,LOW);
    digitalWrite(redPin,LOW);
    delay(buzNear);
  }  
  else if(dist<=30.0 && dist>10.0)
  {
    digitalWrite(buzPin,HIGH);
    digitalWrite(yellowPin, HIGH);
    delay(buzHigh);
    digitalWrite(buzPin,LOW);
    digitalWrite(yellowPin, LOW);
    delay(buzHigh);
  }
  else if((dist>30.0) && (dist<60.0))
  {
    digitalWrite(buzPin,HIGH);
    digitalWrite(greenPin, HIGH);
    delay(buzMid);
    digitalWrite(buzPin,LOW);
    digitalWrite(greenPin,LOW);
    delay(buzMid);
  }
   else if(dist>=60.0 && dist<120.0)
  {
    digitalWrite(buzPin,HIGH);
    delay(buzFar);
    digitalWrite(buzPin,LOW);
    delay(delayFar);
  }
  
}
