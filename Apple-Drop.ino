/*
  Apple_Drop.pde by Lauryn Tachino
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

struct Enemy
{
  int x;
  int y;
};

Enemy e1 = {2,7};
Enemy e2 = {6,11};
Enemy e3 = {4,13};
Enemy enemies[3] = {e1,e2,e3};
int xapple = random(8);
int yapple = 9;
int xbasket = 3;
int ybasket = 1;
int binary = 0;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
  
}


void loop()                     // run over and over again
{
  drawEnemies(); 
  drawApple();
  drawBasket();
  updateEnemies();
  for (int i = 0; i < 3; i++)
  {
    if (ReadPx(enemies[i].x,enemies[i].y) == Violet)
    {
      Tone_Start(20000,50);
      binary = binary / 2;
    }
  }
  updateApple();
  updateBasket();
  // Has apple been eaten?
  if (ReadPx(xapple,yapple) == Violet)
  {
    Tone_Start(11100,50);  // Play sound if apple is eaten
    binary = binary * 2 + 1;  // set aux leds
    if (binary > 255)       // restart if all LEDs are filled
    {
      binary = 0;
    }
  }
  SetAuxLEDs(binary);   // Show aux leds
  DisplaySlate();
  delay(280);
  ClearSlate();
  
}

void updateEnemies()
{
  for (int i = 0; i < 3; i++)
  {
    enemies[i].y--;        // enemies move down one space
    if(enemies[i].y < 0)   // if enemy goes off screen
    spawn(i);              // spawn enemy
  }
}

void spawn(int index)
{
  // Set y to 7
  int y = 7;
  //Generate a random x
  int x;
  do
  {
   x = random(8);         // set x to random value
  }
  while(checkDupe(x,7) == true ||   // check y=7 row
       checkDupe(x,6) == true ||    // check y=6 row
       checkDupe(x,5) == true);     // check y=5 row
  enemies[index].x = x;
  enemies[index].y = 7;
}


boolean checkDupe(int x, int y)
{
  for(int i = 0; i < 3; i++)
  {
    if(x == enemies[i].x)
    {
      if(y == enemies[i].y)
      return true;
    }
  }
  return false;
}

void drawEnemies()
{
  for(int i = 0; i < 3; i++)
  {
    if (enemies[i].y < 8)      // if the value id less than 8
    {
      DrawPx(enemies[i].x,enemies[i].y,White); // draw white dot
    }
    
  }
}

void updateApple()
{
  for (int i = 0; i < 1; i++)
  {
    yapple = yapple - 1;     // apple moves down one space
    
    // Corrects for out of bounds
    if (yapple < 0)
    {
      yapple = 7;        // sets y to 7

      do
      {
       xapple = random(8);         // set x to random value
      }
      while(checkDupe(xapple,7) == true ||   // checks (xapple,7) for any dots
           checkDupe(xapple,6) == true ||    // check (xapple,6) for any dots
           checkDupe(xapple,5) == true);     // check (xapple,5) for any dots
    }
  }
}

void drawApple()
{
  if (yapple < 8)  // if y value is less than 8
  {
    DrawPx(xapple,yapple,Red);   // draws apple
  }
}


void updateBasket()
{
  CheckButtonsPress();
  CheckButtonsDown();
  if (Button_Left)   // if left button pressed
  {
    xbasket = xbasket - 1;  // move one space to left
    // no wrap if basket is at edge of screen
    if (xbasket < 0)
    {
      xbasket = 0;  
    }
  }

  if (Button_Right)  // if right button pressed
  {
    xbasket = xbasket + 1;   // move one space to right
    // no wrap if basket is at edge of screen
    if (xbasket > 7)
    {
      xbasket = 7;
    }
  }
}

void drawBasket()
{
  DrawPx(xbasket,ybasket,Violet);   // draw violet dot
}

