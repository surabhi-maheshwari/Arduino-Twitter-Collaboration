int trigPin = 12;    //Trig - green Jumper
int echoPin = 11;    //Echo - yellow Jumper
long duration, cm, inches;
void setup() {
 //Serial Port begin
 Serial.begin (9600);
 //Define inputs and outputs
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(7, OUTPUT);
 pinMode(6, OUTPUT);
}
void loop()
{
//int duration, distance;
 // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
 // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 delay(30000);
digitalWrite(trigPin, LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 // Read the signal from the sensor: a HIGH pulse whose
 // duration is the time (in microseconds) from the sending
 // of the ping to the reception of its echo off of an object.
 pinMode(echoPin, INPUT);
 duration = pulseIn(echoPin, HIGH);
 // convert the time into a distance
 cm = (duration/2) / 29.1;
 inches = (duration/2) / 74;
if (cm >= 200 || cm <= 0)
{ Serial.println("out of range");
}
else if (cm >=16 && cm <=30){
beepFast();
Serial.print(cm);
Serial.println(" cm");
}
else if (cm >=0 && cm <=15 ){
 beefVeryFast();
 Serial.print(cm);
Serial.println(" cm");
}
else if (cm >=31 && cm <=50) {
Serial.print(cm);
Serial.println(" cm");
beepMedium();
}
else {
beepNo();
Serial.print(cm);
Serial.println(" cm");
}
 delay(250);
}
void beefVeryFast(){
tone(8, 440, 250);
digitalWrite( 7, HIGH);
delay(50);
noTone(8);
digitalWrite(7, LOW);
delay(300);
}
void beepFast(){
tone(8, 440, 200);
digitalWrite(7, HIGH);
delay(50);
noTone(8);
digitalWrite(7, LOW);
delay(300);
}
void beepMedium(){
tone(8, 440, 200);
digitalWrite(7, HIGH);
delay(200);
noTone(8);
digitalWrite(7, LOW);
delay(300);
}
void beepNo(){
noTone(8);
digitalWrite(6, HIGH);
delay(300);
digitalWrite(6, LOW);
delay(50);
}
 

