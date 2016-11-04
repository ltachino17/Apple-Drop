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

int xGreendot = random(8);
int yGreendot = 7;
int xVioletdot = random(8);
int yVioletdot = 7;
int direction = 180;
int timer = 0;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  drawGreendot();      // draw green dot
  updateGreendot();   // update the dot's movement
  
  DisplaySlate();
  delay(600);
  ClearSlate();

  //Increment the timer
  timer++;
  if(timer > 10)
  {
    timer = 0;
  }
  drawVioletdot();
  updateVioletdot();
  DisplaySlate();
}


void updateGreendot()       // Update green dot movement
{
  // Moves green dot down 1 space 
  if (direction == 180)
  {
    yGreendot = yGreendot - 1; 

    if (yGreendot < 0)    // If dot goes below y=0
    {
      yGreendot = 7;      // Set y=7
      xGreendot = random(8);   // Set to random x
    }
 
  }
}

void drawGreendot()
{
  DrawPx(xGreendot,yGreendot,Green);  // Draws a dot at random x, y=7
}


void updateVioletdot()    // Update violet dot movement
{
  if (direction == 180)
  {
    yVioletdot = yVioletdot - 1;  

    if (yVioletdot < 0)
    {
      yVioletdot = 7;
      xVioletdot = random(8);
    }
  }
  
}

void drawVioletdot()
{
  DrawPx(xVioletdot,yVioletdot,Violet);  // Draws violet dot random x, y=7
}

