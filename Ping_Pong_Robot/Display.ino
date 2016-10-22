void Display()
{
   if(manual)
   {
    if(!feedgo)
     {

        tellymate.cursorto(10,3);
        tellymate.printlarge(topspeed);
        tellymate.cursorto(10,5);
        tellymate.printlarge(bottomspeed);
        tellymate.cursorto(11,7);
        tellymate.printlarge(horizstate);
        if(horizstate<100)
        {
          tellymate.cursorto(13,7);
          tellymate.printlarge(" ");
        }
        tellymate.cursorto(9,9);
        tellymate.printlarge(vertstate);
        if(vertstate<100)
        {
          tellymate.cursorto(11,9);
          tellymate.printlarge(" ");
        }
        tellymate.cursorto(10,11);
        tellymate.printlarge(freq);
        if(freq<10)
        {
          tellymate.cursorto(11,11);
          tellymate.printlarge(" ");
        }
     }
   }
/*    else if(multiprogram)
    {
      progrow = constrain(progrow,0,TotalPrograms-1);
      //tellymate.print(progname[progrow]);
    }
    else if(multiprogmenu)
    {
    }          */
    else if(program) {
      if(beginprogram)
      {
        tellymate.cursorto(26,17);
        tellymate.print("----------");
        tellymate.cursorto(6,19);
        tellymate.printlarge(counter);
      }
      else
      {
        tellymate.cursorto(6,19);
        tellymate.printlarge(counter);
        if(locationselect ==0)
        {
          tellymate.cursorto(26,17);
          tellymate.print("----------");
          tellymate.cursorto(28,21);
          tellymate.print("        ");
        }
        else if(locationselect ==1)
        {
          tellymate.cursorto(28,21);
          tellymate.print("--------");
          tellymate.cursorto(26,17);
          tellymate.print("          ");
        }
      }
    }
    else if(progmenu)
    {
      if(setspintype == 0) setspin = 0;
      tellymate.cursorto(8,3);
      tellymate.printlarge(spintypename[setspintype]);
      tellymate.cursorto(6,7);
      tellymate.printlarge(setspeed+1);
      tellymate.cursorto(17,7);
      tellymate.printlarge(setspin+1);
      tellymate.cursorto(9,11);
      tellymate.printlarge(sequencename[setsequence]);
      tellymate.cursorto(10,15);
      tellymate.printlarge(freq);
      if(freq<100) {
        tellymate.cursorto(12,15);
        tellymate.printlarge(" ");
      }
      if(numofballs<10 && numofballs != 0)
      {
        tellymate.cursorto(6,19);
        tellymate.printlarge(numofballs);
        tellymate.cursorto(7,19);
        tellymate.printlarge("  ");
      }
      else if(numofballs == 0)
      {
        tellymate.cursorto(6,19);
        tellymate.printlarge("All");
      }
      else
      {
        tellymate.cursorto(6,19);
        tellymate.printlarge(numofballs);
      }

      tellymate.cursorto(16,5);
      tellymate.print("                        ");
      tellymate.cursorto(12,9);
      tellymate.print("  ");
      tellymate.cursorto(34,9);
      tellymate.print("  ");
      tellymate.cursorto(18,13);
      tellymate.print("          ");
      tellymate.cursorto(20,17);
      tellymate.print("    ");
      tellymate.cursorto(12,21);
      tellymate.print("     ");
      tellymate.cursorto(28,21);
      tellymate.print("        ");
      tellymate.cursorto(28,17);
      tellymate.print("          ");

      if(locationselect == 0)
      {
        tellymate.cursorto(16,5);
        tellymate.print("----------------");
      }
      else if(locationselect ==1)
      {
        tellymate.cursorto(12,9);
        tellymate.print("--");
      }
      else if(locationselect ==2)
      {
        tellymate.cursorto(34,9);
        tellymate.print("--");
      }
      else if(locationselect ==3)
      {
        tellymate.cursorto(18,13);
        tellymate.print("---------");
      }
      else if(locationselect ==4)
      {
        tellymate.cursorto(20,17);
        tellymate.print("----");
      }
      else if(locationselect ==5)
      {
        tellymate.cursorto(12,21);
        tellymate.print("----");
      }
      else if(locationselect ==6)
      {
        tellymate.cursorto(28,17);
        tellymate.print("--------");
      }
      else if(locationselect ==7)
      {
        tellymate.cursorto(28,21);
        tellymate.print("--------");
      }
    }
    else {
      tellymate.cursorto(5,5);
      tellymate.printlarge("MAIN MENU");
      tellymate.cursorto(6,10);
      tellymate.print("Shot");
      tellymate.cursorto(0,11);
      tellymate.printlarge("SELECTION");

      tellymate.cursorto(23,10);
      tellymate.print("Advanced");
      tellymate.cursorto(11,11);
      tellymate.printlarge("PROGRAM");
      if(locationselect == 0)
      {
          tellymate.cursorto(0,13);
          tellymate.print("------------------");
          tellymate.cursorto(22,13);
          tellymate.print("                          ");
      }
      else if(locationselect ==1)
      {
        tellymate.cursorto(22,13);
        tellymate.print("--------------");
        tellymate.cursorto(0,13);
        tellymate.print("                  ");
      }
      tellymate.cursorto(9,16);
      tellymate.println("Ok button -> Select.");
      tellymate.cursorto(5,17);
      tellymate.println("Vol+ and Vol- -> Change Selection");
      tellymate.cursorto(7,18);
      tellymate.println("CH+ and CH- -> Change Values");
    }
}

void BeginProgramDisplay()
{
  tellymate.cursorto(13,15);
  tellymate.printlarge("PAUSE");
  tellymate.cursorto(14,19);
  tellymate.printlarge("    ");
}

void ProgramDisplay()
{
  tellymate.clearscreen();
  tellymate.cursorto(6,0);
  tellymate.printlarge("PROGRAM");
  tellymate.cursorto(3,3);
  tellymate.printlarge("Spin:");
  tellymate.cursorto(0,7);
  tellymate.printlarge("Speed:");
  tellymate.cursorto(12,7);
  tellymate.printlarge("Spin:");
  tellymate.cursorto(0,11);
  tellymate.printlarge("Sequence:");
  tellymate.cursorto(0,15);
  tellymate.printlarge("Frequency:");
  tellymate.cursorto(0,19);
  tellymate.printlarge("Balls:");
  tellymate.cursorto(13,15);
  tellymate.printlarge("START");
  tellymate.cursorto(14,19);
  tellymate.printlarge("BACK");
  tellymate.cursorto(8,3);
  tellymate.printlarge(spintypename[setspintype]);
  tellymate.cursorto(6,7);
  tellymate.printlarge(setspeed+1);
  tellymate.cursorto(17,7);
  tellymate.printlarge(setspin+1);
  tellymate.cursorto(9,11);
  tellymate.printlarge(sequencename[setsequence]);
  tellymate.cursorto(10,15);
  tellymate.printlarge(freq);
  if(freq<100) {
    tellymate.cursorto(12,15);
    tellymate.printlarge(" ");
  }
  if(numofballs == 0)
  {
    tellymate.cursorto(9,19);
    tellymate.printlarge("/");
    tellymate.cursorto(10,19);
    tellymate.printlarge("All");
  }
  else
  {
    tellymate.cursorto(8,19);
    tellymate.printlarge("/");
    tellymate.cursorto(9,19);
    tellymate.printlarge(numofballs);
  }
}

void ProgMenuDisplay()
{
  tellymate.clearscreen();
  tellymate.cursorto(5,0);
  tellymate.printlarge("SELECTION");
  tellymate.cursorto(3,3);
  tellymate.printlarge("Spin:");
  tellymate.cursorto(0,7);
  tellymate.printlarge("Speed:");
  tellymate.cursorto(12,7);
  tellymate.printlarge("Spin:");
  tellymate.cursorto(0,11);
  tellymate.printlarge("Sequence:");
  tellymate.cursorto(0,15);
  tellymate.printlarge("Frequency:");
  tellymate.cursorto(0,19);
  tellymate.printlarge("Balls:");
  tellymate.cursorto(14,15);
  tellymate.printlarge("DONE");
  tellymate.cursorto(14,19);
  tellymate.printlarge("BACK");
}

void ManualDisplay()
{
  tellymate.clearscreen();
  tellymate.cursorto(0,0);
  tellymate.printlarge("Manual");
  tellymate.cursorto(0,3);
  tellymate.printlarge("Top Motor:");
  tellymate.cursorto(10,3);
  tellymate.printlarge(topspeed);
  tellymate.cursorto(0,5);
  tellymate.printlarge("Bot Motor:");
  tellymate.cursorto(10,5);
  tellymate.printlarge(bottomspeed);
  tellymate.cursorto(0,7);
  tellymate.printlarge("Horizontal:");
  tellymate.cursorto(11,7);
  tellymate.printlarge(horizstate);
  if(horizstate<100)
  {
    tellymate.cursorto(13,7);
    tellymate.printlarge(" ");
  }
  tellymate.cursorto(0,9);
  tellymate.printlarge("Vertical:");
  tellymate.cursorto(9,9);
  tellymate.printlarge(vertstate);
  if(vertstate<100)
  {
    tellymate.cursorto(11,9);
    tellymate.printlarge(" ");
  }
  tellymate.cursorto(0,11);
  tellymate.printlarge("Frequency:");
  tellymate.cursorto(10,11);
  tellymate.printlarge(freq);
  if(freq<10)
  {
    tellymate.cursorto(11,11);
    tellymate.printlarge(" ");
  }
  else if(freq>99)
  {
    tellymate.cursorto(11,12);
    tellymate.printlarge(" ");
  }
}

