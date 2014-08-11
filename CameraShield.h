/*

  Project:       1Sheeld Library 
  File:          CameraShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef CameraShield_h
#define CameraShield_h

//Output Functions ID's
#define REAR_CAPTURE 	0x01
#define SET_FLASH 		0x02
#define CAM_OFF				0x00
#define CAM_ON    			0x01
#define AUTO  			0x02
#define FRONT_CAPTURE 	0x03
#define SET_QUALITY 	0x04
#define LOW_QUALITY 	0x01
#define MID_QUALITY 	0x02
#define HIG_QUALITY 	0x03

class CameraShieldClass
{
public:
	//Setters 
	void frontCapture();
	void rearCapture ();
	void setFlash(byte );
	void setQuality(byte);

private:
	
};

//Extern Object
extern CameraShieldClass Camera;
#endif 