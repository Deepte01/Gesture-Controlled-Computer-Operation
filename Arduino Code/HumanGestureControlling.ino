//pin numbers for left Ultrasonic Sensor
int leftTrigPin=13;
int leftEchoPin=11;

//pin numbers for right Ultrasonic Sensor
int rightTrigPin=3;
int rightEchoPin=5;

//Variables for calculating the distance between the Ultrasonic sensor and hand
float pingTime; // time for ping to hot target and return
float speedOfSound;//we will calc te speed of sound
float lDistance;
float rDistance;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // turn on serial port
pinMode(leftTrigPin,OUTPUT);
pinMode(leftEchoPin,INPUT);
pinMode(rightTrigPin,OUTPUT);
pinMode(rightEchoPin,INPUT);
}

int calculateDistance(int trigger,int echo)
{
 digitalWrite(trigger,LOW);
delayMicroseconds(2000); // pause to let signal settle
digitalWrite(trigger,HIGH); 
delayMicroseconds(10); //pause for 10 micro seconds
digitalWrite(trigger,LOW);// finish pulse by bringing it low
pingTime=pulseIn(echo,HIGH); // measure the ping travel time at receiver in micro secs 

int dist= pingTime*0.034/2;
/*if(dist>60)
{
  dist=60;
}  */
return dist;
}

void loop() {
  // put your main code here, to run repeatedly:
  lDistance=calculateDistance(leftTrigPin,leftEchoPin);
  Serial.println((String)"The lDistance of travel is: "+lDistance+" miles per hour");

  // play or pause the video

  if(lDistance>2 && lDistance<=6)
  {
    Serial.println("Play/Pause");
    delay(500);
  }

// rewind or forward the video
  
if (lDistance>6 && lDistance<=15)
{
  delay(100); //Hand Hold Time
  lDistance=calculateDistance(leftTrigPin,leftEchoPin);
  //distL =dist;
  if (lDistance>6 && lDistance<=15)
  {
    Serial.println("Short key Locked");
    while(lDistance>6 && lDistance<=15)
    {
      lDistance=calculateDistance(leftTrigPin,leftEchoPin);
    //  distL =dist;
      if (lDistance<=10) //Hand pushed in 
      {Serial.println ((String)"Rewind, lDistance: "+lDistance); delay (300);}
      if (lDistance>10) //Hand pulled out
      {Serial.println ((String)"Forward, lDistance: "+lDistance); delay (300);}
    }
  }
}

//increase or decrease the volume of the video

if (lDistance>15 && lDistance<=25)
{
  delay(100); //Hand Hold Time
  lDistance=calculateDistance(leftTrigPin,leftEchoPin)
  ;
  //distL =dist;
  if (lDistance>15 && lDistance<=25)
  {
    Serial.println("Volume Locked");
    while(lDistance>15 && lDistance<=25)
    {
      lDistance=calculateDistance(leftTrigPin,leftEchoPin);
    //  distL =dist;
      if (lDistance<=20) //Hand pushed in 
      {Serial.print
    ((String)"Increase, lDistance: "+lDistance); delay (300);}
      if (lDistance>20) //Hand pulled out
      {Serial.println ((String)"Decrease, lDistance: "+lDistance); delay (300);}
    }
  }
}

if (lDistance>25 && lDistance<=35)
{
  delay(100); //Hand Hold Time
  lDistance=calculateDistance(leftTrigPin,leftEchoPin);
  //distL =dist;
  if (lDistance>25 && lDistance<=35)
  {
    //Serial.println("Page Up");
    while(lDistance>25 && lDistance<=35)
    {
      lDistance=calculateDistance(leftTrigPin,leftEchoPin);
    //  distL =dist;
      if (lDistance<=30) //Hand pushed in 
      {Serial.println ((String)"pagedown, lDistance: "+lDistance); delay (300);}
      if (lDistance>30) //Hand pulled out
      {Serial.println ((String)"pageup, lDistance: "+lDistance); delay (300);}
    }
  }
}
delayMicroseconds(2);
rDistance=calculateDistance(rightTrigPin,rightEchoPin);
  Serial.println((String)"The rDistance of travel is: "+rDistance+" miles per hour");

if(rDistance>2 && rDistance<8)
{
  delay(100); //Hand Hold Time
  rDistance=calculateDistance(rightTrigPin,rightEchoPin);
  Serial.println ((String)"rDistance: "+rDistance);
    if (rDistance>2 && rDistance<=8)
  {
    Serial.println("RecordVideo");
    delay(500);
    }
  }
delay(200);     
}
