
//array indices for each location
#define var 0 //vertical
#define tmar 1 //top motor
#define bmar 2 //botom motor
#define har 3  //horizontal

#define numoflocations 5 //number of horizontal locations
#define END -1 //ends a horizontal sequence or a program

#define L 68 //Horizontal locations for sequences
#define ML 80
#define M 92
#define MR 104
#define R 114

#define numofsequences 19 //number of sequences in the sequences array
#define persequence 10 //max shots per sequence
const int places[numoflocations] = {L,ML,M,MR,R}; //locations

int counter = 0; //counts the number of balls shot
int numofballs = 0; //picks number of balls to shoot before stopping. set to 0 for continuous
int setsequence = 0; //picks the sequence from the array below
int currentsequence[persequence] = {END,END,END,END,END,END,END,END,END,END}; //creates the sequence array for the program

//================SET SEQUENCES HERE==================================================================================
const int sequences[numofsequences][persequence] =  //sequences. to create a new one use the locations above
{                                                  //and end it with END if less than 10 locations
  {M,END},
  {R,END},
  {MR,END},
  {L,END},
  {ML,END},
  {M,MR,END},
  {M,ML,END},
  {ML,MR,END},
  {M,R,END},
  {M,L,END},
  {MR,R,END},
  {ML,L,END},
  {ML,R,END},
  {MR,L,END},
  {L,R,END},
  {L,M,R,M,END},
  {L,ML,M,MR,R,END},
  {R,MR,M,ML,L,END},
  {L,ML,M,MR,R,MR,M,ML,END},
};

char* sequencename[numofsequences+1] = //name each sequence
{
  "M only           ",
  "R only           ",
  "MR only         ",
  "L only          ",
  "ML only         ",
  "M-MR            ",
  "M-ML            ",
  "ML-MR          ",
  "M-R            ",
  "M-L            ",
  "MR-R           ",
  "ML-L           ",
  "ML-R           ",
  "MR-L           ",
  "L-R            ",
  "L-M-R-M        ",
  "Sweep ->        ",
  "Sweep <-        ",
  "Sweep          ",
  "Random         ",
};
//=======================================================================================================================
#define deadball 0 //identify each type in array
#define topspin 1
#define backspin 2

#define spintype 3 //set location of each spin in the array
#define velocity 5 //5 different velocity settings
#define spinamount 5 // 5 different spin differentiations

int setspin = 0; //picks from the shot type array below for single shot programs
int setspeed = 0;
int setspintype = 0;
char* spintypename[3] = {"DeadBall", "Top Spin", "BackSpin"};

#define dead 0 //find dead spin array location

#define low 0 //define spins and velocities array location
#define medlow 1
#define med 2
#define medhigh 3
#define high 4

const int shottype[spintype][velocity][spinamount][3]  = //of format {vertical, top motor, bottom motor}
{
  { //deadball============================================================
    {//velocity 1
      {154,1558,1558},
    },
    {//velocity 2
      {94,1563,1563},
    },
    {//velocity 3
      {78,1568,1568},
    },
    {//velocity 4
      {68,1573,1573},
    },
    {//velocity 5
      {54,1578,1578},
    },
  },
  { //topspin=============================================================
    {//velocity 1
      {154,1560,1550},
      {154,1575,1535},
      {154,1583,1500},
      {154,1620,1430},
      {154,1665,1400},
    },
    {//velocity 2
      {108,1578,1556},
      {100,1599,1535},
      {100,1612,1500},
      {104,1653,1433},
      {104,1696,1410},
    },
    {//velocity 3
      {76,1595,1563},
      {76,1623,1535},
      {74,1642,1500},
      {80,1685,1435},
      {0,1728,1420},
    },
    {//velocity 4
      {54,1613,1569},
      {66,1646,1535},
      {70,1671,1500},
      {66,1718,1438},
      {68,1759,1430},
    },
    {//velocity 5
      {54,1630,1575},
      {54,1670,1535},
      {54,1700,1500},
      {54,1750,1440},
      {54,1790,1440},
    },
  },
  { //backspin ===========================================================
    {//velocity 1
      {154,1545,1565},
      {154,1535,1575},
      {154,1500,1580},
      {154,1440,1615},
      {154,1420,1640},
    },
    {//velocity 2
      {120,1549,1569},
      {120,1535,1585},
      {120,1500,1590},
      {120,1444,1620},
      {120,1415,1659},
    },
    {//velocity 3
      {100,1553,1573},
      {100,1535,1595},
      {100,1500,1600},
      {84,1448,1624},
      {84,1410,1678},
    },
    {//velocity 4
      {82,1556,1576},
      {82,1535,1605},
      {76,1500,1610},
      {76,1451,1629},
      {76,1405,1696},
    },
    {//velocity 5
      {54,1560,1580},
      {54,1535,1615},
      {54,1500,1620},
      {54,1455,1633},
      {54,1400,1715},
    },
  },
};
