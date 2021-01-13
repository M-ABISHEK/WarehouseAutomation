#include <NewPing.h> //Header Library for ultrasonic sensor
int x,y,t1=0,t2=0; //Declaring variables
unsigned int D;
NewPing sonar(12,11,10); //Initializing ultrasonic sensor, Syntax is NewPing sonar(TriggPin, EchoPin, Maxdistance);
void setup() {
 pinMode(2,INPUT); //Initializing input pin of Infrared sensor 1
 pinMode(3,INPUT); //Initializing input pin of Infrared sensor 2
 pinMode(5,OUTPUT); //Initializing output pin 1 of motor driver
 pinMode(10,OUTPUT); //Initializing output pin 3 of motor driver
 pinMode(6,OUTPUT); //Initializing output pin 2 of motor driver
 pinMode(9,OUTPUT); } //Initializing output pin 4 of motor driver
void loop()
{
 x=digitalRead(2); //Read value of Infrared sensor 1
 y=digitalRead(3); //Read value of Infrared sensor 2
if((x==1)&&(y==1)) { //If no IR sensor reads black line at any side then move forward
 D=sonar.ping_cm(); //Check reading of ultrasonic sensor in cm
 digitalWrite(5,LOW); //THE MOTOR STOPPED AND IDLE IN POSITION
 digitalWrite(10,LOW); 
 digitalWrite(6,LOW);
 digitalWrite(9,LOW);
 t1=0;
 t2=0;
 if(D!=0) { //If ultrasonic sensor reads an obstruction in the vicinity of max distance then stop robot
 digitalWrite(5,LOW); //stop motors, stop moving
 digitalWrite(10,LOW);
 digitalWrite(6,LOW);
 digitalWrite(9,LOW);
 delay(1000); }  //Delay of 1 second
 else if(D=0)
 {
 digitalWrite(5,HIGH); //STARTS TO MOVE FORWARD
 digitalWrite(10,HIGH);
 digitalWrite(6,LOW);
 digitalWrite(9,LOW);
 delay(1000); 
 }}
 else if((x==1)&&(y==0)) { //If front IR sensor reads black line then turn robot to front
 if(t1>=20) {
 digitalWrite(5,HIGH); //MAKES THE ROBOT TO MOVE FRONT
 digitalWrite(10,HIGH);
 digitalWrite(6,LOW); 
 digitalWrite(9,LOW); 
 delay(500);}
 else {
 digitalWrite(5,LOW); //makes the robot to stop
 digitalWrite(10,LOW);
 digitalWrite(6,LOW);
 digitalWrite(9,LOW);
 delay(500);
 t1+=1; } }
 else if((x==0)&&(y==1)) { //If back IR sensor reads black line then move the robot back
 if(t2>=20) {
 digitalWrite(5,LOW);
 digitalWrite(10,HIGH);
 digitalWrite(6,LOW); 
 digitalWrite(9,HIGH);
 delay(1000); }
 else {
 digitalWrite(5,LOW);
 digitalWrite(10,LOW); //STOP THE motor 
 digitalWrite(6,LOW);
 digitalWrite(9,LOW);
 delay(1000);
 t2+=1; } }
 else if((x==0)&&(y==0)) { //If the two IR sensor reads black line at both sides then the robot moves forward
 digitalWrite(5,HIGH);//ROBOT MOVE FORWARD 
 digitalWrite(10,HIGH); 
 digitalWrite(6,LOW);
 digitalWrite(9,LOW);
 delay(1000);
 t1=0;
 t2=0; } }
