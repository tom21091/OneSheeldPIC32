/*

SMS Shield Example

This example shows an application on 1Sheeld's SMS shield.

By using this example, you can send a SMS when the value
of the smartphone's temperature sensor exceeds a certain
limit.

*/

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define a boolean flag. */
boolean isMessageSent = false;

void setup() 
{
 /* Start communication. */
 OneSheeld.begin(); 
}

void loop() 
{
  if (Serial.available())OneSheeld.processInput();
  /* Always check if the temperature value is larger than a certain value. */
  if (TemperatureSensor.getValue() > 30)
  {
    if(!isMessageSent)
    {   
        /* Send the SMS. */ 
        SMS.send("1234567890","Room Temperature is higher than 30 degree!");
        /* Set the flag. */
        isMessageSent = true;  
    }
    
  }
  else
  {
    /* Reset the flag. */
    isMessageSent = false;
  }
}
