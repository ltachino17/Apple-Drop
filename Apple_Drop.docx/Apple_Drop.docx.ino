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

int xgreendot = random(8);
int ygreendot = 7;
int direction = 180;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  drawgreendot();      // draw green dot
  updategreendot();   // update the dot's movement
  DisplaySlate();
  delay(500);
  
  ClearSlate();
}


void updategreendot()
{
  // Moves apple down
  if (direction == 180)
  {
    ygreendot = ygreendot - 1;

    if (ygreendot < 0)    // If dot goes below y=0
    {
      ygreendot = 7;      // Set y=7
      xgreendot = random(8);   // Set to random x
    }
 
  }
}

void drawgreendot()
{
  DrawPx(xgreendot,ygreendot,Green);  // Draws a dot at random x, y=7
}

