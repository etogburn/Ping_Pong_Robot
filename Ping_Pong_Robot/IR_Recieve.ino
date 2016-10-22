void IRrecieve()
{
  if (irrecv.decode(&results))
  {
    //Serial.println(results.value, HEX);
    if(manual) //manual mode hidden from play
    {
      switch(results.value)
      {
        //tv mode buttons
        case 0x61A0F00F: //power button
          feedgo = false;
          break;
        case 0x61A050AF: //ch+ button
          if(vertstate < vrange[1]) vertstate += 2;
          break;
        case 0x61A0D02F: //ch- button
          if(vertstate > vrange[0]) vertstate -= 2;
          break;
        case 0x61A030CF: //vol+ button
          if(horizstate < hrange[1]) horizstate += 2;
          hrand = false;
          hsweep = false;
          break;
        case 0x61A0B04F: //vol- button
          if(horizstate > hrange[0]) horizstate -= 2;
          hrand = false;
          hsweep = false;
          break;
        case 0x61A0708F: //mute/ok button
          feedgo = true;
          break;
        case 0x61A028D7: //menu button
          if(freq > freqrange[0] ) freq -= 1;
          break;
        case 0x61A0E817: //info/display button
          if(freq < freqrange[1] ) freq += 1;
          break;
        case 0x61A048B7: //tv/vcr butto
          topspeed+=1;
          bottomspeed+=1;
          break;
        case 0x61A008F7: //last button
          topspeed-=1;
          bottomspeed-=1;
          break;
        case 0x61A0C837: //sleep button
          topspeed = (motorbottom+motortop)/2;
          bottomspeed = (motorbottom+motortop)/2;
          break;
        case 0x61A000FF: //1 button
          topspeed+=1;
          break;
        case 0x61A0807F: //2 button
          topspeed-=1;
          break;
        case 0x61A040BF: //3 button
          temp = (float(bottomspeed)+float(topspeed))/2; //deadball
          bottomspeed = int(temp);
          topspeed = int(temp);
          break;
        case 0x61A0C03F: // button 4
          bottomspeed+=1;
          break;
        case 0x61A020DF: //button 5
          bottomspeed-=1;
          break;
        case 0x61A0A05F: //button 6
          break;
        case 0x61A0609F: // button 7
          break;
        case 0x61A0E01F: //button 8
          manual = false;
          feedgo = false;
          tellymate.clearscreen();
          break;
        case 0x61A0906F://button 0
          break;
      }
    }

    else {
      switch(results.value) // ==========================================================================================================
      {//main recieve commands. individual buttons determine the mode
        //TV buttons
        case 0x61A0F00F: //power button
          break;
        case 0x61A030CF: //vol+ button
          VolPlus();
          break;
        case 0x61A0B04F: //vol- button
          VolMinus();
          break;
        case 0x61A050AF: //ch+ button
          ChPlus();
          break;
        case 0x61A0D02F: //ch- button
          ChMinus();
          break;
         case 0x61A0708F: //mute/ok button
          OkButton();
          delay(50);
          break;
        case 0x61A000FF: //1 button
          manual = true;
          ManualDisplay();
          break;
        case 0x61A0807F: //2 button
          break;
        case 0x61A040BF: //3 button
          break;
        case 0x61A0C03F: // button 4
          break;
        case 0x61A020DF: //button 5
          break;
        case 0x61A0A05F: //button 6
          break;
        case 0x61A0609F: // button 7
          break;
        case 0x61A0E01F: //button 8
          break;
        case 0x61A010EF: //button 9
          break;
        case 0x61A0906F://button 0
          break;
      }
    }
    
    irrecv.resume();
  }
}

