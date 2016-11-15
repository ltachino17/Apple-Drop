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

Enemy e1 = {0,0};
Enemy e2 = {0,0};
Enemy e3 = {0,0};
Enemy enemies[3] = {e1,e2,e3};

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

void loop()                     // run over and over again
{
  drawEnemies();
  updateEnemies();
  DisplaySlate();
  delay(600);
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
   x = random(8);
  }
  while(checkDupe(x,7) == true ||
       checkDupe(x,6) == true ||
       checkDupe(x,5) == true);
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
    DrawPx(enemies[i].x,enemies[i].y,White);
  }
}

