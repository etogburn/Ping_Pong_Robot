void VolPlus() //===============================================================================================
{
  if(progmenu)
  {
    if(locationselect < programmenu[1]) locationselect++;
  }
  else if(program)
  {
    if(locationselect < programstart[1]) locationselect++;
  }
  else
  {
    if(locationselect < mainmenu[1]) locationselect++;
  }
  delay(50);
}

void VolMinus() //=============================================================================================
{
  if(progmenu)
  {
    if(locationselect > programmenu[0]) locationselect--;
  }
  else if(program)
  {
    if(locationselect > programstart[0]) locationselect--;
  }
  else
  {
    if(locationselect > mainmenu[0]) locationselect--;
  }
  delay(50);
}

void ChPlus() //===============================================================================================
{
  if(progmenu)
  {
    if(locationselect == selspintype && setspintype < spintype-1) setspintype++;
    else if(locationselect == selvelocity && setspeed < velocity-1) setspeed++;
    else if(locationselect == selspinamount && setspin < spinamount-1)
    {
      if(setspintype != 0) setspin++;
    }
    else if(locationselect == selfreq && freq < freqrange[1]) freq+=5;
    else if(locationselect == selsequence && setsequence < numofsequences) setsequence++;
    else if(locationselect == selnumofballs && numofballs<99) numofballs++;
  }
  delay(50);
}

void ChMinus() //===============================================================================================
{
  if(progmenu)
  {
    if(locationselect == selspintype && setspintype > 0) setspintype--;
    else if(locationselect == selvelocity && setspeed > 0) setspeed--;
    else if(locationselect == selspinamount && setspin > 0)
    {
      if(setspintype != 0) setspin--;
    }
    else if(locationselect == selsequence && setsequence > 0) setsequence--;
    else if(locationselect == selfreq && freq > freqrange[0]) freq-=5;
    else if(locationselect == selnumofballs && numofballs > 0) numofballs--;
  }
  delay(50);
}

void OkButton() //==============================================================================================
{
  if(progmenu)
  {
    if(locationselect == moveon)
    {
      program= true;
      progmenu = false;
      delaytime = oneminute/freq - oneminute/freqrange[1];
      if(setsequence != numofsequences)
      {
        for(int w = 0; w < persequence; w++){
          currentsequence[w] = sequences[setsequence][w];
          if(sequences[setsequence][w] == END) break;
        }
      }
      else
      {
        for(int w = 0; w < persequence; w++)
        {
          int xx = random(0,numoflocations);
          currentsequence[w] = places[xx];
        };
      }
      PrepareProgram();
      ProgramDisplay();
      locationselect = 0;
    }
    else if(locationselect == back)
    {
      tellymate.clearscreen();
      progmenu = false;
      locationselect = 0;
    }
  }
  else if(program)
  {
    if(beginprogram)
    {
      beginprogram = false;
      digitalWrite(feedpin, LOW);
      ProgramDisplay();
    }
    else
    {
      if(locationselect == 0)
      {
        BeginProgramDisplay();
        beginprogram = true;
        locationselect = 0;
      }
      else if(locationselect == 1)
      {
        program = false;
        for(int a = 0; a <persequence; a++)
        {
          currentsequence[a] = END;
        }
        progmenu = true;
        q = 0;
        lastShot = -1;
        locationselect = 0;
        counter =0;
        ProgMenuDisplay();
        topspeed = 1500;
        bottomspeed = 1500;
      }
    }
    feedgo = false;
  }
  else
  {
    if(locationselect == 0)
    {
      progmenu = true;
      locationselect = 0;
      ProgMenuDisplay();
    }
    else if(locationselect == 1)
    {
      //multiprogmenu = true;
      locationselect = 1;
    }
  }
  delay(50);
}
