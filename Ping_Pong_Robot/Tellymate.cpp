
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


Tellymate::Tellymate( long serialRate )
{
  _serialRate = serialRate;
  _xloc = 0;
  _yloc = 0;
}


void Tellymate::init()
{
  Serial3.begin( _serialRate );
  delay(50);
  Serial3.write( CHAR_ESC "E");
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
  Serial3.print( CHAR_ESC "Q");
  delay( 20 ); // tellymate users guide recommends at least 2ms delay
}


void Tellymate::clearscreen()
{ // <ESC>E
  Serial3.print( CHAR_ESC "E" ); 
  _xloc = 0;
  _yloc = 0;
}


void Tellymate::cursoron()
{ // <ESC>e 
  Serial3.print( CHAR_ESC "e" );
}


void Tellymate::cursoroff()
{ // <ESC>f 
  Serial3.print( CHAR_ESC "f" );
}


void Tellymate::cursorto( uint8_t xloc , uint8_t yloc )
{ // <ESC>Yrc
  Serial3.write( CHAR_ESC "Y" ) ;
  Serial3.write((unsigned char)(32 + yloc)) ;
  Serial3.write((unsigned char)(32 + xloc)) ;
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
  Serial3.write( CHAR_ESC "H" );
  _xloc = 0;
  _yloc = 0;
}


void Tellymate::newline()
{
  Serial3.write( CHAR_CR CHAR_LF );
}


void Tellymate::blockcursor( bool value )
{
  if( value ){
    Serial3.write( CHAR_ESC "x4" );
  }
  else{
    Serial3.write( CHAR_ESC "y4" );
  }
}


void Tellymate::lineoverflow( bool value )
{
  if( value ){
    Serial3.write( CHAR_ESC "v" );
  }
  else{
    Serial3.write( CHAR_ESC "w" );
  }
}


void Tellymate::printchar( unsigned char char2print )
{
  Serial3.write( CHAR_DLE );
  Serial3.write( char2print );
}


void Tellymate::pootchar( int xloc, int yloc, unsigned char char2print )
{
  cursorto( xloc, yloc );
  Serial3.write( CHAR_DLE );
  Serial3.write( char2print );
}


void Tellymate::print( char pstring[])
{
  Serial3.write( pstring );
}

void Tellymate::print( int var)
{
  Serial3.write( var );
}

void Tellymate::println( char pstring[])
{
  Serial3.println( pstring );
}

void Tellymate::printtall( char pstring[])
{
    cursorto( _xloc, _yloc );
    Serial3.write( CHAR_ESC "_2");
    Serial3.write(pstring);
    cursorto( _xloc, _yloc +1 );
    Serial3.write( CHAR_ESC "_3");
    Serial3.write(pstring);
}

void Tellymate::printlarge( char pstring[])
{
    cursorto( _xloc, _yloc );
    Serial3.write( CHAR_ESC "_4");
    Serial3.write(pstring);
    cursorto( _xloc, _yloc +1 );
    Serial3.write( CHAR_ESC "_5");
    Serial3.write(pstring);
}

void Tellymate::printlarge( int var)
{
    cursorto( _xloc, _yloc );
    Serial3.write( CHAR_ESC "_4");
    Serial3.print(var);
    cursorto( _xloc, _yloc +1 );
    Serial3.write( CHAR_ESC "_5");
    Serial3.print(var);
}

void Tellymate::fontdoubleheight( int row )
{
  if( row == -1 ){
    for( int i = 0; i < 25; i += 2 ){
      cursorto( 0, i );
      Serial3.write( CHAR_ESC "_2");
      cursorto( 0, i+1 );
      Serial3.write( CHAR_ESC "_3");
    }
  }
  else{
    cursorto( 0, row );
    Serial3.write( CHAR_ESC "_2");
    cursorto( 0, row+1 );
    Serial3.write( CHAR_ESC "_3");
  }
}


void Tellymate::fontdoublewidth( int row )
{
  if( row == -1 ){
    for( int i = 0; i < 25; i++ ){
      cursorto( 0, i );
      Serial3.write( CHAR_ESC "_1");
    }
  }
  else{
    cursorto( 0, row );
    Serial3.write( CHAR_ESC "_1");
  }
}


void Tellymate::fontlarge( int row )
{
  if( row == -1 ){
    for( int i = 0; i < 25; i += 2 ){
      cursorto( 0, i );
      Serial3.write( CHAR_ESC "_4");
      cursorto( 0, i+1 );
      Serial3.write( CHAR_ESC "_5");
    }
  }
  else{
    cursorto( 0, row );
    Serial3.write( CHAR_ESC "_4");
    cursorto( 0, row+1 );
    Serial3.write( CHAR_ESC "_5");
  }
}




void Tellymate::fontnormal( int row )
{
  if( row == -1 ){
    for( int i = 0; i < 25; i++ ){
      cursorto( 0, i );
      Serial3.write( CHAR_ESC "_0");
    }
  }
  else{
    cursorto( 0, row );
    Serial3.write( CHAR_ESC "_0");
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
