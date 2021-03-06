
/*
  Tellymate.h - Arduino Library for using the Tellymate Shield
  Created by goldfish yo! 
  Copyright (c) 2009, goldfish yo!
  
  Portions based on Tellymate demo code and specifications
  Created and Copyright (c) 2009, Nigel Batten.
  http://www.batsocks.co.uk/
  


Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:


	1.	Redistributions of source code must retain the above copyright
		notice, this list of conditions and the following disclaimer.
	2.	Redistributions in binary form must reproduce the above copyright
		notice, this list of conditions and the following disclaimer in the
		documentation and/or other materials provided with the distribution.


THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT HOLDER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.


===============================================


TellyMate Serial to Video adapter
=================================
	38x25 character display
	PAL or NTSC composite video output
	Up to 57k6 serial data.
	Autobauding option.
	VT52 escape codes.
	H19 escape codes.
	Double-height / Double-width text.
	Code Page 437 graphics
	White text on black background
*/


#include "Tellymate.h"

#include "Arduino.h"


#define CHAR_ESC "\x1B"
#define CHAR_DLE "\x10"
#define CHAR_CR "\x0D"
#define CHAR_LF "\x0A"

#if SerialPortUsed == 3
#define SerialPort Serial3
#endif

#if SerialPortUsed == 2
#define SerialPort Serial2
#endif

#if SerialPortUsed == 1
#define SerialPort Serial1
#endif

#if SerialPortUsed == 0
#define SerialPort Serial
#endif

#ifndef SerialPort
#define SerialPort Serial
#endif

Tellymate::Tellymate( long serialRate )
{
  _serialRate = serialRate;
  _xloc = 0;
  _yloc = 0;
}


void Tellymate::init()
{
  SerialPort.begin( _serialRate );
  delay(50);
  SerialPort.write( CHAR_ESC "E");
  _xloc = 0;
  _yloc = 0;
  cursoroff();
  //diagnostic();
  //fontdoublewidth( 18 );
  //cursorto( 0, 18 );
  //Serial3.println( "Tellymate lib" );
  //Serial3.print( "ver 0.01" );
  //delay( 4000 );
  clearscreen();
}


void Tellymate::diagnostic()
{
  SerialPort.print( CHAR_ESC "Q");
  delay( 20 ); // tellymate users guide recommends at least 2ms delay
}


void Tellymate::clearscreen()
{ // <ESC>E
  SerialPort.print( CHAR_ESC "E" ); 
  _xloc = 0;
  _yloc = 0;
}


void Tellymate::cursoron()
{ // <ESC>e 
  SerialPort.print( CHAR_ESC "e" );
}


void Tellymate::cursoroff()
{ // <ESC>f 
  SerialPort.print( CHAR_ESC "f" );
}


void Tellymate::cursorto( uint8_t xloc , uint8_t yloc )
{ // <ESC>Yrc
  SerialPort.write( CHAR_ESC "Y" ) ;
  SerialPort.write((unsigned char)(32 + yloc)) ;
  SerialPort.write((unsigned char)(32 + xloc)) ;
  _xloc = xloc;
  _yloc = yloc;
}


void Tellymate::cursorup( int moves )
{
  _yloc = _yloc - moves;
  if( _yloc < 0 ){
      _yloc = 0;
  }
  cursorto( _xloc, _yloc);
}


void Tellymate::cursordown( int moves )
{
  _yloc = _yloc + moves;
  if( _yloc > 24 ){
      _yloc = 24;
  }
  cursorto( _xloc, _yloc);
}


void Tellymate::cursorright( int moves )
{
  _xloc = _xloc + moves;
  if( _xloc > 37 ){
      _xloc = 37;
  }
  cursorto( _xloc, _yloc);
}


void Tellymate::cursorleft( int moves )
{
  _xloc = _xloc - moves;
  if( _xloc < 0 ){
      _xloc = 0;
  }
  cursorto( _xloc, _yloc);
}


void Tellymate::cursorhome()
{
  SerialPort.write( CHAR_ESC "H" );
  _xloc = 0;
  _yloc = 0;
}


void Tellymate::newline()
{
  SerialPort.write( CHAR_CR CHAR_LF );
}


void Tellymate::blockcursor( bool value )
{
  if( value ){
    SerialPort.write( CHAR_ESC "x4" );
  }
  else{
    SerialPort.write( CHAR_ESC "y4" );
  }
}


void Tellymate::lineoverflow( bool value )
{
  if( value ){
    SerialPort.write( CHAR_ESC "v" );
  }
  else{
    SerialPort.write( CHAR_ESC "w" );
  }
}


void Tellymate::printchar( unsigned char char2print )
{
  SerialPort.write( CHAR_DLE );
  SerialPort.write( char2print );
}


void Tellymate::pootchar( int xloc, int yloc, unsigned char char2print )
{
  cursorto( xloc, yloc );
  SerialPort.write( CHAR_DLE );
  SerialPort.write( char2print );
}


void Tellymate::print( char pstring[])
{
  SerialPort.write( pstring );
}

void Tellymate::print( int verticalArrayLoc)
{
  SerialPort.write( verticalArrayLoc );
}

void Tellymate::println( char pstring[])
{
  SerialPort.println( pstring );
}

void Tellymate::printtall( char pstring[])
{
    cursorto( _xloc, _yloc );
    SerialPort.write( CHAR_ESC "_2");
    SerialPort.write(pstring);
    cursorto( _xloc, _yloc +1 );
    SerialPort.write( CHAR_ESC "_3");
    SerialPort.write(pstring);
}

void Tellymate::printlarge( char pstring[])
{
    cursorto( _xloc, _yloc );
    SerialPort.write( CHAR_ESC "_4");
    SerialPort.write(pstring);
    cursorto( _xloc, _yloc +1 );
    SerialPort.write( CHAR_ESC "_5");
    SerialPort.write(pstring);
}

void Tellymate::printlarge( int verticalArrayLoc)
{
    cursorto( _xloc, _yloc );
    SerialPort.write( CHAR_ESC "_4");
    SerialPort.print(verticalArrayLoc);
    cursorto( _xloc, _yloc +1 );
    SerialPort.write( CHAR_ESC "_5");
    SerialPort.print(verticalArrayLoc);
}

void Tellymate::fontdoubleheight( int row )
{
  if( row == -1 ){
    for( int i = 0; i < 25; i += 2 ){
      cursorto( 0, i );
      SerialPort.write( CHAR_ESC "_2");
      cursorto( 0, i+1 );
      SerialPort.write( CHAR_ESC "_3");
    }
  }
  else{
    cursorto( 0, row );
    SerialPort.write( CHAR_ESC "_2");
    cursorto( 0, row+1 );
    SerialPort.write( CHAR_ESC "_3");
  }
}


void Tellymate::fontdoublewidth( int row )
{
  if( row == -1 ){
    for( int i = 0; i < 25; i++ ){
      cursorto( 0, i );
      SerialPort.write( CHAR_ESC "_1");
    }
  }
  else{
    cursorto( 0, row );
    SerialPort.write( CHAR_ESC "_1");
  }
}


void Tellymate::fontlarge( int row )
{
  if( row == -1 ){
    for( int i = 0; i < 25; i += 2 ){
      cursorto( 0, i );
      SerialPort.write( CHAR_ESC "_4");
      cursorto( 0, i+1 );
      SerialPort.write( CHAR_ESC "_5");
    }
  }
  else{
    cursorto( 0, row );
    SerialPort.write( CHAR_ESC "_4");
    cursorto( 0, row+1 );
    SerialPort.write( CHAR_ESC "_5");
  }
}




void Tellymate::fontnormal( int row )
{
  if( row == -1 ){
    for( int i = 0; i < 25; i++ ){
      cursorto( 0, i );
      SerialPort.write( CHAR_ESC "_0");
    }
  }
  else{
    cursorto( 0, row );
    SerialPort.write( CHAR_ESC "_0");
  }
}


void Tellymate::fill( int startx, int starty, int width, int height, unsigned char fillchar )
{
  int xend = startx + width;
  if( xend > MAX_X ){
    xend = MAX_X;
  }
  int yend = starty + height;
  if( yend > MAX_Y ){
    yend = MAX_Y;
  }
  for( int xloc = startx; xloc < xend; xloc++ ){
    for( int yloc = starty; yloc < yend; yloc++ ){
      cursorto( xloc, yloc );
      printchar( fillchar );
    }
  } 
}


void Tellymate::box( int startx, int starty, int width, int height )
{
  cursorto( startx, starty );
  printchar( 130 );
  int xspace = width - 2;
  int yspace = height - 2;
  for( int i = 0; i < xspace; i++ )
  {
    cursorright(1);
    printchar( 133 );
  }
  cursorright(1);
  printchar( 135 );
  for( int i = 0; i < yspace; i++ )
  {
    cursordown(1);
    printchar( 129 );
  }
  cursordown(1);
  printchar( 132 );
  for( int i = 0; i < xspace; i++ )
  {
    cursorleft(1);
    printchar( 133 );
  }
  cursorleft(1);
  printchar( 128 );
  for( int i = 0; i < yspace; i++ )
  {
    cursorup(1);
    printchar( 129 );
  }
}
