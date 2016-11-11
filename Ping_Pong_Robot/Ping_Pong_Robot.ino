/*
Ping Pong robot controlled by tv remote.

TV buttons

1 = manual mode

MANUAL MODE
Power - all systems off
CH + and CH - = vertical movement
VOL+ and VOL - = horizontal movement
OK = starts the feeder.
Menu = increase frequency
info.display = decrease frequency
TV/VCR = increase motor speed
last = decrease motor speed
sleep = motors stop
1 = increase topmotor
2 = decrease topmotor
3 = dead ball
4 = increase topmotor
5 = decrease topmotor
*/
#include "IRremote.h"
#include "Arduino.h"
#include "IRremote.h"
#include "Servo.h"

#include "Config.h"
#include "Programs.h"
#include "Shots.h"
#include "Tellymate.h"

Tellymate tellymate (57600);

Servo vertical;
Servo horizontal;
Servo topmotor;
Servo bottommotor;

IRrecv irrecv(RECV_PIN);
decode_results results;

unsigned long now = 0;
unsigned long lastselecshot = 0;
unsigned long lastprog = 0;
unsigned long lastfeed = 0;
unsigned long lastagitate = 0;
unsigned long lasthsweep = 0;
unsigned long lasthrand = 0;
unsigned long lastfeedprog = 0;
unsigned long manualdisplay = 0;

void setup()
{
  Initialize();
}

void loop() 
{
  IRrecieve(); //recieve program
  now = millis();
  if(manual)
  {

  }
  else if(program)
  {
    if(beginprogram) Program();
  }


  WriteLocations(); //writes to the servos
  Display(); //determines mode and writes the display
  //end of void loop ***************************************************************************************************************
}


void ballFeed()
{
  ballFed = true;

}


void WriteLocations()
{ //basic movement
  horizontal.write(horizstate);
  vertical.write(vertstate);

  topspeed = constrain(topspeed, motorbottom, motortop);
  bottomspeed = constrain(bottomspeed, motorbottom, motortop);

  topmotor.writeMicroseconds(topspeed);
  bottommotor.writeMicroseconds(bottomspeed);
}
//===========================================================================================================================================

