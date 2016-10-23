#include "Arduino.h"

//**********************EDIT BETWEEN LINES****************************************************************************

int vrange[2] = {54 , 154}; //1 is highest angle, 0 is lowest
int hrange[2] = {50 , 130}; //130 is right most shot, 50 is left most //66 is left table. 112 is right table
int freqrange[2] = {15,150};
float topspeed=1500; //microseconds to write to the top motor
float bottomspeed = 1500; //for bottom motor
int motorbottom = 1000;
int motortop = 2000;
#define movementIncrement 2
//**********************************************************************************************************************

volatile int ballFed = 0;
int debugcounter = 0;
unsigned long delaytime = 0;
unsigned long oneminute = 60000;

#define hpin 9 //servo pins
#define vpin 10
#define tmpin 7
#define bmpin 8
#define feedpin 12

#define RECV_PIN 13 //IR pin

#define feedSensorPin 19
#define feedInt 4

#define spinfeed 0
#define stopfeed 112
#define timeout 10000

int vertstate = 90;//vertical movement spot
int horizstate = 90; // horizontal movement spot
boolean hup = true; //used to determine which way for horizontal servo to go in sweeps
boolean feedgo = false; //tells the feeder to start
int freq = freqrange[0]; //frequency of the feeder
int movementTimer = 5;
float temp; //used to average the motor's speed
int moveemup=90; //used for agitation
boolean mov = true; //used for agitation direction
boolean hrand = false; //random movement in manual mode
boolean hsweep = false; //sweep of horizontal servo in random mode

boolean manual = false; //programs. only 1 at a time.
boolean multiprogram = false;
boolean program = false;
boolean progmenu = false;
boolean multiprogmenu = false;
boolean beginprogram = false;
boolean beginmultiprogram = false;

int ballfreqtop = 9999;
int ballfreqbot = 0;
int ballfreq = 9999; //ball frequency timer numbers
boolean ffreq = true;

int q = 0; //counter when complete to reset and begin a program again
int lastShot = -1; //keeps track of the indexed number for the last shot to ensure that feedgo is turned on only once

//display variables
int locationselect = 0; //picks which button is highlighted on the display
const int mainmenu[2] = {0,1}; //sets max and min values for the main menu button select
const int programmenu[2] = {0,7};
const int programstart[2] = {0,1};
#define selspintype 0 //for program menu
#define selvelocity 1
#define selspinamount 2
#define selfreq 4
#define selnumofballs 5
#define moveon 6
#define back 7
#define selsequence 3
int displayy = 0;
int progrow = 0; //defines which program row is displayed and picked

 unsigned long now = 0;
 unsigned long lastselecshot = 0;
 unsigned long lastprog = 0;
 unsigned long lastfeed = 0;
 unsigned long lastagitate = 0;
 unsigned long lasthsweep = 0;
 unsigned long lasthrand = 0;
 unsigned long lastfeedprog = 0;

 unsigned long manualdisplay = 0;
