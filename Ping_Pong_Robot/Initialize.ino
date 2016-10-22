void Initialize()
{
  pinMode(23, OUTPUT);
  digitalWrite(23, LOW);
  
  tellymate.init();
  tellymate.cursorto(2,7);
  tellymate.printlarge("Ping Pong Robot");
  irrecv.enableIRIn(); // Start the receiver
  vertical.attach(vpin);
  horizontal.attach(hpin);
  topmotor.attach(tmpin); //both motors are on timer 2
  bottommotor.attach(bmpin);

  pinMode(feedpin, OUTPUT);
  digitalWrite(feedpin, LOW);

  pinMode(feedSensorPin, INPUT);
  digitalWrite(feedSensorPin, HIGH);
  attachInterrupt(4, ballFeed, RISING);

  //delay(2000);
  tellymate.cursorto(6,12);
  tellymate.printlarge("Arming");
  topmotor.writeMicroseconds(topspeed);
  bottommotor.writeMicroseconds(bottomspeed);
  tellymate.box(6,17,26,3);
  tellymate.cursorto(7,18);
  for(int w = 0; w < 24; w++)
  {
    tellymate.pootchar(7+w,18,160);
    delay(20);
    tellymate.pootchar(7+w,18,161);
    delay(20);
    tellymate.pootchar(7+w,18,162);
    delay(20);
    tellymate.pootchar(7+w,18,163);
    delay(20);
    tellymate.pootchar(7+w,18,164);
    delay(20);
    tellymate.pootchar(7+w,18,165);
    delay(20);
    tellymate.pootchar(7+w,18,166);;
    delay(20);
    tellymate.pootchar(7+w,18,167);
    delay(20);
  }
  tellymate.clearscreen();
  tellymate.fontdoublewidth(2);
  tellymate.cursorto(3,2);
  tellymate.printlarge("Systems Test");
  tellymate.box(3,11,26,3);
  tellymate.box(32,5,3,16);
  tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],4,27)),12,167);
  tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6)),167);
  while(horizstate <hrange[1]) {
    horizstate++;
    horizontal.write(horizstate);
    delay(10);
    tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],4,27)),12,167);
    if(int(map(horizstate,hrange[0],hrange[1],4,27)) !=4) tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],4,27))-1,12,32);
    if(int(map(horizstate,hrange[0],hrange[1],4,27)) !=27) tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],4,27))+1,12,32);
  }
  while(vertstate <vrange[1]){
    vertstate++;
    vertical.write(vertstate);
    delay(10);
    tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6)),167);
    if(int(map(vertstate,vrange[0],vrange[1],19,6)) != 6) tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6))-1,32);
    if(int(map(vertstate,vrange[0],vrange[1],19,6)) != 19)tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6))+1,32);
  }
  while(horizstate > hrange[0]){
    horizstate--;
    horizontal.write(horizstate);
    delay(10);
    tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],4,27)),12,167);
    if(int(map(horizstate,hrange[0],hrange[1],4,27)) !=4) tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],4,27))-1,12,32);
    if(int(map(horizstate,hrange[0],hrange[1],4,27)) !=27) tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],4,27))+1,12,32);
  }
  while(vertstate > vrange[0]){
    vertstate--;
    vertical.write(vertstate);
    delay(10);
    tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6)),167);
    if(int(map(vertstate,vrange[0],vrange[1],19,6)) != 6) tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6))-1,32);
    if(int(map(vertstate,vrange[0],vrange[1],19,6)) != 19) tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6))+1,32);
  }
  while(vertstate !=90 || horizstate !=92){
    if(vertstate <90) vertstate++;
    if(horizstate <92) horizstate++;
    horizontal.write(horizstate);
    vertical.write(vertstate);
    delay(10);
    tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6)),167);
    if(int(map(vertstate,vrange[0],vrange[1],19,6)) != 6) tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6))-1,32);
    if(int(map(vertstate,vrange[0],vrange[1],19,6)) != 19)tellymate.pootchar(33,int(map(vertstate,vrange[0],vrange[1],19,6))+1,32);
    tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],4,27)),12,167);
    if(int(map(horizstate,hrange[0],hrange[1],4,27)) !=4) tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],4,27))-1,12,32);
    if(int(map(horizstate,hrange[0],hrange[1],4,27)) !=27) tellymate.pootchar(int(map(horizstate,hrange[0],hrange[1],4,27))+1,12,32);
  }
  tellymate.clearscreen();
}

