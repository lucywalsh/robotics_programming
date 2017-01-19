#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "abdrive.h"
#include "simpletools.h"

int driveForward(int left_wheel, int right_wheel);
int square(float distance_in_mm);
int circle();
int drawString(const char *Word);
int drawLetter(char Letter);

int main(void){

  drawString("K");
  return 0;
  }

int driveForward(int left_wheel, int right_wheel){
  drive_goto(left_wheel, right_wheel);
  return 0;
}

int square(float distance_in_mm){
  drive_speed(100,100);
  int ticks = fabs(distance_in_mm/3.25);
  drive_goto(ticks,ticks);
  drive_goto(0,52);//left turn
  drive_goto(ticks,ticks);
  drive_goto(0,52);//left turn
  drive_goto(ticks,ticks);
  drive_goto(0,52);//left turn
  drive_goto(ticks,ticks);

  return 0;
}

int circle(){
  drive_goto(105,-105);
  return 0;
}

int drawString(const char *Word){
  int len = strlen(Word);
  for(int i =0; i<len; i++){
    drawLetter(Word[i]);
  }
  return 0;
}

int drawLetter(char Letter){
  //height of letters: 75 ticks = 23 mm ?
  //gaps between letters: 50 ticks
  //size of 'spokes' in letters : 40 ticks
  
  switch(Letter){
  case 'A' :
    //drive_goto();
    //drive_goto();
    break;
  case 'E':
    drive_goto(-25,25);//left turn
    drive_goto(75,75);
    drive_goto(25,-25);//right turn
    drive_goto(40,40);
    drive_goto(-40,-40);
    drive_goto(25,-25);//right turn
    drive_goto(35,35);
    drive_goto(-25,25);//left turn
    drive_goto(40,40);
    drive_goto(-40,-40);
    drive_goto(25,-25);//right turn
    drive_goto(40,40);
    drive_goto(-25,25);//right turn
    drive_goto(40,40);
    break;
  case 'F':
    //drive_goto();
    break;
  case 'H':
    drive_goto(-25,25);//left turn
    drive_goto(75,75);
    drive_goto(-30,-30);
    drive_goto(25,-25);//right turn
    drive_goto(40,40);
    drive_goto(-25,25);//left turn
    drive_goto(40,40);
    drive_goto(-75,-75);
    drive_goto(25,-25);//right turn
    break;
  case 'I':
    drive_goto(-25,25);//left turn
    drive_goto(75,75);
    drive_goto(-75,-75);
    drive_goto(25,-25);//right turn
    break;
  case 'K':
    drive_goto(-25,25);//left turn
    drive_goto(75,75);
    drive_goto(-30,-30);
    drive_goto(12,-12);//right turn
    drive_goto(30,30);
    drive_goto(-20,-20);
    drive_goto(25,-25);//right turn
    drive_goto(45,45);
    drive_goto(-12,12);//left turn
    break;
  case 'L':
    drive_goto(-25,25);//left turn
    drive_goto(75,75);
    drive_goto(-75,-75);
    drive_goto(25, -25);//right turn
    drive_goto(50,50);
    break;
  default:
    break;
  }
  drive_goto(50,50);
  return 0;
}
