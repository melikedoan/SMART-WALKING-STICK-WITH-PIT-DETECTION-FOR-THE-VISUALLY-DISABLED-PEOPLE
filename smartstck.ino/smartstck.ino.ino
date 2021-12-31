/*  Project Name   : Smart Stick for Blind People
 *  Revision Date  :31.12.2021
 *  Author         :Melike DOĞAN
 
 //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Purpose        : When the HCSR04 detects certain values, the buzzer will sound to prevent the user from falling into the pit.
 
 /---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    System Input   :HC-SR04
    System Output  :Buzzer

    
 //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    System Work    :The buzzer is set to go off when the HCSR04 detects certain values.

    
 */
 

#define echoPin 6               // Echo pindefined as INPUT.
#define trigPin 7               // Trigger pin defined as OUTPUT.
#define buzzerPin 12            // Buzzer pin defined as OUTPUT.

int maximumRange = 100;         // The reason why the maximum distance is specified as 100 is that the sensor works well up to this distance.
int minimumRange = 30;          // Minimum range set to 30



void setup() {
  pinMode(trigPin, OUTPUT);     
  pinMode(echoPin, INPUT);      
  pinMode(buzzerPin, OUTPUT);   

}

void loop() {

  int value = distance(maximumRange, minimumRange);    //Distance was set as specified and buzzer beeping adjusted as specified.
  melody(value*20);

}

int distance(int maxrange, int minrange)
{
  long duration, distance;

  digitalWrite(trigPin,LOW);                          
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);

  if(distance >= maxrange || distance <= minrange)    
  return 0;
  return distance;
}

int melody(int dly)
{
  tone(buzzerPin, 450);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
  
}
