int trigPin=13;
int echoPin=11;
float pingTime; // time for ping to hot target and return
float speedOfSound;//we will calc te speed of sound
float distance;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // turn on serial port
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
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
  distance=calculateDistance(trigPin,echoPin);
  Serial.println((String)"The distance of travel is: "+distance+" miles per hour");

// play or pause the video

  if(distance>20 && distance<=30)
  {
    Serial.println("Play/Pause");
    delay(500);
  }

// rewind or forward the video
  
if (distance>=10 && distance<=20)
{
  delay(100); //Hand Hold Time
  distance=calculateDistance(trigPin,echoPin);
  //distL =dist;
  if (distance>=10 && distance<=20)
  {
    Serial.println("Short key Locked");
    while(distance>=10 && distance<=20)
    {
      distance=calculateDistance(trigPin,echoPin);
    //  distL =dist;
      if (distance<15) //Hand pushed in 
      {Serial.println ((String)"Rewind, distance: "+distance); delay (300);}
      if (distance>15) //Hand pulled out
      {Serial.println ((String)"Forward, distance: "+distance); delay (300);}
    }
  }
}

//increase or decrease the volume of the video

if (distance>30 && distance<=40)
{
  delay(100); //Hand Hold Time
  distance=calculateDistance(trigPin,echoPin)
  ;
  //distL =dist;
  if (distance>30 && distance<=40)
  {
    Serial.println("Volume Locked");
    while(distance>30 && distance<=40)
    {
      distance=calculateDistance(trigPin,echoPin);
    //  distL =dist;
      if (distance<35) //Hand pushed in 
      {Serial.println ((String)"Increase, distance: "+distance); delay (300);}
      if (distance>35) //Hand pulled out
      {Serial.println ((String)"Decrease, distance: "+distance); delay (300);}
    }
  }
}

delay(200);     
}
