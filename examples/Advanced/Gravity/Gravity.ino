/*

Gravity Shield Example

This example shows an application on 1Sheeld's gravity shield.

By using this example, you can send a notification to your
smartphone when you roll it three times left.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define a counter. */
int counter = 0 ;
/* Define a boolean flag. */
boolean isRolled = true;
/* A name for the LED on pin 13. */
int ledPin = 13;

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED as output. */
  pinMode(ledPin,OUTPUT);
}

void loop() 
{
  if (Serial.available())OneSheeld.processInput();
  /* Always check if the smartphone has been rolled on its X-axis. */
  if(GravitySensor.getX() > 9)
  {
    /* Check if is has been rolled. */
    if(isRolled)
    {
      /* Increment the counter. */
      counter++;
      /* Reset the flag. */
      isRolled = false;  
    }
  }
  else 
  {
    /* Set the flag. */
    isRolled = true;
  }

  /*Check if is has been rolled 3 times. */
  if (counter == 3)
  {
    /* Send a notification. */
    Notification.notifyPhone("SmartPhone has been rolled three times.");
    /* Turn on the LED. */
    digitalWrite(ledPin,HIGH);
    /* Wait half a second. */
    delay(500);
    /* Reset the Counter. */
    counter = 0;
  }
  else
  {
    /* Turn off the LED. */
    digitalWrite(ledPin,LOW);
  }
  
  
}
