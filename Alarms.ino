void SAE1S()
{
  int day = weekday();    //gets day of the week
  
  if(day != 4 && day != 7 && day != 1)   //runs if its not wednesday or weekend
    {
      switch_em(schedule_A, 1);
    }
}

void SAE2S()
{
  int day = weekday();    //gets day of the week
  
  if(day != 4 && day != 7 && day != 1)   //runs if its not wednesday or weekend
    {
      switch_em(schedule_A, 2);
    }
}

void SBE1S()
{
  int day = weekday();    //gets day of the week
  
  if(day != 4 && day != 7 && day != 1)   //runs if its not wednesday or weekend
    {
      switch_em(schedule_B, 1);
    }
}

void SBE2S()
{
  int day = weekday();    //gets day of the week
  
  if(day != 4 && day != 7 && day != 1)   //runs if its not wednesday or weekend
    {
      switch_em(schedule_B, 2);
    }
}

void SCE1S()
{
  int day = weekday();    //gets day of the week
  
  if(day != 4 && day != 7 && day != 1)   //runs if its not wednesday or weekend
    {
      switch_em(schedule_C, 1);
    }
}

void SCE2S()
{
  int day = weekday();    //gets day of the week
  
  if(day != 4 && day != 7 && day != 1)   //runs if its not wednesday or weekend
    {
      switch_em(schedule_C, 2);
    }
}

void switch_em(char s, int e)
{
   switch(s)         //turns on RGB to whatever color schedule has been passed
      {
        case 'r':
          analogWrite(red, 255);
          break;
        case 'g':
          analogWrite(green, 255);
          break;
        case 'y':
          analogWrite(yellow, 255);
          break;
        case 'b':
          analogWrite(blue, 255);
          break;
      }
  if(e == 1)               //turns on however many lights have been passed
    {analogWrite(elective1, 150);}
    else if(e == 2)
      {analogWrite(elective1, 150);  analogWrite(elective2, 150);}
}
  
void leds_off()
{
  //turn off the RGB + elective lights
  analogWrite(red, 0); analogWrite(blue, 0); analogWrite(green, 0);
  analogWrite(yellow, 0);
  analogWrite(elective1, 0);
  analogWrite(elective2, 0);
}
