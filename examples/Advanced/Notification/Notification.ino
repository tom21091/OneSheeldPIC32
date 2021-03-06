/*

Notification Shield Example

This example shows an application on 1Sheeld's notification shield.

By using this example, you can send a notification to
your smartphone if the temperature of the room exceeds
a certain value.

*/

/* Inlcude 1Sheeld library. */
#include <OneSheeld.h>

/* Define a boolean flag. */
boolean isPhoneNotified = false;

void setup()
{
	/* Start communication. */
	OneSheeld.begin();
}

void loop()
{
  if (Serial.available())OneSheeld.processInput();
	/* Always get the temperature. */
	if(TemperatureSensor.getValue() > 25)
	{
		/* Check if the phone has been notified once. */
		if(!isPhoneNotified)
		{
			/* Notify the phone. */
			Notification.notifyPhone("Temperature increased!");
			/* Set the flag. */
			isPhoneNotified = true;
		}
		
	}
	else
	{
		/* Reset the flag. */
		isPhoneNotified = false;
	}
}
