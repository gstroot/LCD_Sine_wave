/*
  LiquidCrystal Library - Sine wave magic

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Moving sine" to the first line of the LCD and
 on the second line shows a moving sine wave created by block characters.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
   * ends to +5V and ground
   * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 4 Jul 2016
 by Greg Stroot
 modified 4 Jul 2016
 by Greg Stroot

 This example code is in the public domain.
https://github.com/gstroot/Arduino-LCD-sine-wave


 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2,3,4,5,6,7);

//Create Sine Characters - limited to 8
int modulonum=8;
// Since there are 5 pixels in each character we need to modulo shift the characters
// to see a sine wave
int pixelperchar=5;

byte p1[8] = {
0b00110,
0b01000,
0b00001,
0b10000,
0b10000,
0b00000,
0b00000,
0b00000,
};

byte p2[8] = {
0b01100,
0b10000,
0b00010,
0b00000,
0b00000,
0b00001,
0b00000,
0b00000,
};

byte p3[8] = {
0b11000,
0b00000,
0b00100,
0b00000,
0b00000,
0b00010,
0b00000,
0b00001,
};

byte p4[8] = {
0b10000,
0b00000,
0b01000,
0b00000,
0b00000,
0b00100,
0b00000,
0b00011,
};

byte p5[8] = {
0b00000,
0b00000,
0b10000,
0b00000,
0b00000,
0b01000,
0b00001,
0b00110,
};

byte p6[8] = {
0b00000,
0b00000,
0b00000,
0b00001,
0b00001,
0b10000,
0b00010,
0b01100,
};

byte p7[8] = {
0b00000,
0b00001,
0b00000,
0b00010,
0b00010,
0b00000,
0b00100,
0b11000,
};

byte p8[8] = {
0b00001,
0b00010,
0b00000,
0b00100,
0b00100,
0b00000,
0b01000,
0b10000,
};



void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
//make sine characters
lcd.createChar(0, p1);
lcd.createChar(1, p2);
lcd.createChar(2, p3);
lcd.createChar(3, p4);
lcd.createChar(4, p5);
lcd.createChar(5, p6);
lcd.createChar(6, p7);
lcd.createChar(7, p8);



  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("Moving sine");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("             ");
  lcd.setCursor(0,0);
  lcd.print("Pixels ");
  lcd.print(pixelperchar);
  lcd.setCursor(10,0);
  lcd.print("Mod ");
  lcd.print(modulonum);
}


void loop() {
//Move cursor to line 2
//iterate each timeslot
for (int j = 0; j<modulonum; j++)
{
  //Iterate lines
  for (int i = 0; i<16; i++)
  {
  lcd.setCursor(i,1);
  lcd.write((i)*pixelperchar%modulonum+j);

  }
    delay(200);
}

}


