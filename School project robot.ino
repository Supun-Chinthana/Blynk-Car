#include<BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPLQHq-2iSl"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define auth "***********************************"



const char* ssid = "Dialog 4G";
const char* pass = "***********";
int in1 = 16;
int in2 = 5;
int in3 = 0;
int in4 = 2;
int trigPin = 14;
int echoPin = 12;

int get_distance(int trigPin , int echoPin) 
{
  long duration;
  int distance;
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  while(true)
  {
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    return distance;
    }
}



int forwa;
int rot_r;
int rot_l;
const int s_pin = 13;
int mode;




void setup() {
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  
  // put your setup code here, to run once:

}
void l(int in1,int in3)
{
  digitalWrite(in1,1);
  digitalWrite(in3,0);

}
void r(int in1,int in2)
{
  digitalWrite(in1,0);
  digitalWrite(in3,1);  
}
void n(int in1,int in3)
{
  digitalWrite(in1,0);
  digitalWrite(in3,0);
}
BLYNK_WRITE(V7)
{
  int r = param.asInt();
  digitalWrite(in1,r);
  
}

BLYNK_WRITE(V1)
{
  int l= param.asInt();
  digitalWrite(in3,l);
  
}





  
  // put your setup code here, to run once:



void loop() {
  Blynk.run();

  


  // put your main code here, to run repeatedly:

}
