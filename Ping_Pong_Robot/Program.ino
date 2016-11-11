void Program()
{
  topspeed = shottype[setspintype][setspeed][setspin][topMotorArrayLoc];
  bottomspeed = shottype[setspintype][setspeed][setspin][botMotorArrayLoc];
  if(now - lastprog > movementTimer)
  {
    lastprog = now;
    if(horizstate < currentsequence[currentShot])
    {
      horizstate += movementIncrement;
    }
    else if(horizstate > currentsequence[currentShot])
    {
      horizstate -= movementIncrement;
    }

    if(vertstate < shottype[setspintype][setspeed][setspin][verticalArrayLoc])
    {
      vertstate += movementIncrement;
    }
    else if(vertstate > shottype[setspintype][setspeed][setspin][verticalArrayLoc])
    {
      vertstate -= movementIncrement;
    }
  }
  
if(now-lastfeedprog > delaytime) {
  if(vertstate == shottype[setspintype][setspeed][setspin][verticalArrayLoc] && horizstate == currentsequence[currentShot])
  {
	  if (digitalRead(feedSensorPin) == LOW) {
		  currentShot++;
		  numOfBallsShot++;
		  digitalWrite(feedMotorPin, LOW);
		  lastfeedprog = millis();
	  }
	  else {
		  digitalWrite(feedMotorPin, HIGH);
		  topmotor.writeMicroseconds(topspeed);
		  bottommotor.writeMicroseconds(bottomspeed);
	  }

  }
}

//nextShot:
  now = millis();

  if(setsequence == numofsequences)
   {
     if(currentShot == 0) currentsequence[persequence-1] = places[random(0,numoflocations)];
     else currentsequence[currentShot-1] = places[random(0,numoflocations)];
   }
  if(currentsequence[currentShot] == END || currentShot > persequence-1) {
    currentShot = 0; //resets the current sequence
  }
  if(numOfBallsToShoot !=0) //null if counter is 0. plays till player stops
  {
    if(numOfBallsToShoot <= numOfBallsShot) //stops the program when counter is reached
    {
      beginprogram = false;
      ProgramDisplay();
      numOfBallsShot = 0;
      digitalWrite(feedMotorPin, LOW);
    }
  }
}
//=============================================================================================================================================
void ProgramReady()
{
  if(topspeed > shottype[setspintype][setspeed][setspin][topMotorArrayLoc]) topspeed -=5;
  else if(topspeed < shottype[setspintype][setspeed][setspin][topMotorArrayLoc]) topspeed +=5;
  if(bottomspeed > shottype[setspintype][setspeed][setspin][botMotorArrayLoc]) bottomspeed -=5;
  else if(bottomspeed < shottype[setspintype][setspeed][setspin][botMotorArrayLoc]) bottomspeed +=5;
  topmotor.writeMicroseconds(topspeed);
  bottommotor.writeMicroseconds(bottomspeed);
  if(horizstate != currentsequence[0])
  {
    if(horizstate > currentsequence[0]) horizstate -=2;
    else if(horizstate <currentsequence[0]) horizstate +=2;
    horizontal.write(horizstate);
  }
  if(vertstate != shottype[setspintype][setspeed][setspin][verticalArrayLoc])
  {
    if(vertstate > shottype[setspintype][setspeed][setspin][verticalArrayLoc]) vertstate -=2;
    else if(vertstate <shottype[setspintype][setspeed][setspin][verticalArrayLoc]) vertstate +=2;
    vertical.write(vertstate);
  }
  tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],6,29)),12,167);
  if(int(map(horizstate,hrange[0],hrange[1],6,29)) !=29) tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],6,29))-1,12,32);
  if(int(map(horizstate,hrange[0],hrange[1],6,29)) !=6) tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],6,29))+1,12,32);
  tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6)),167);
  if(int(map(vertstate,vrange[0],vrange[1],19,6)) != 6) tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6))-1,32);
  if(int(map(vertstate,vrange[0],vrange[1],19,6)) != 19)tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6))+1,32);
}

void PrepareProgram()
{
  tellymate.clearscreen();
  tellymate.cursorto(4,1);
  tellymate.printlarge("Preparing...");
  tellymate.box(5,5,26,3); //status bar box
  tellymate.box(5,11,26,3);
  tellymate.box(32,5,3,16);
  for(int w = 0; w < 24; w++)
  {
    ProgramReady();
    tellymate.pootchar(6+w,6,160);
    delay(25);
    tellymate.pootchar(6+w,6,161);
    delay(25);
    ProgramReady();
    tellymate.pootchar(6+w,6,162);
    delay(25);
    tellymate.pootchar(6+w,6,163);
    delay(25);
    ProgramReady();
    tellymate.pootchar(6+w,6,164);
    delay(25);
    tellymate.pootchar(6+w,6,165);
    delay(25);
    ProgramReady();
    tellymate.pootchar(6+w,6,166);
    delay(25);
    tellymate.pootchar(6+w,6,167);
    delay(25);
  }
  delay(100);
  topspeed = shottype[setspintype][setspeed][setspin][topMotorArrayLoc];
  bottomspeed = shottype[setspintype][setspeed][setspin][botMotorArrayLoc];
  topmotor.writeMicroseconds(topspeed);
  bottommotor.writeMicroseconds(bottomspeed);
}

