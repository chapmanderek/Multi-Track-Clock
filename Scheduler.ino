void setSchedules()
{  
  //sync arduino to RTC then get month and date 
  setduino();
  int day_now = day();
  int month_now = month();
  
  //set each schedule to its respective track
  switch(month_now)
  {
    case 1:
    if(day_now < 28)
      {
        schedule_A = 'r';
        schedule_B = 'y';
        schedule_C = 'b';
      }
     else
       {
        schedule_A = 'g';
        schedule_B = 'y';
        schedule_C = 'b';
       }
    break;

    case 2:
    if(day_now < 18)
      {
        schedule_A = 'g';
        schedule_B = 'y';
        schedule_C = 'b';
      }
     else
       {
        schedule_A = 'g';
        schedule_B = 'y';
        schedule_C = 'r';
       }
     break;
     
    case 3:
    if(day_now < 9 || day_now == 9)
      {
        schedule_A = 'g';
        schedule_B = 'y';
        schedule_C = 'r';
      }
     else if(day_now > 9 && day_now < 31)
       {
        schedule_A = 'g';
        schedule_B = 'b';
        schedule_C = 'r';
       }
     else if(day_now == 31)
       {
        schedule_A = 'y';
        schedule_B = 'b';
        schedule_C = 'r';
       }
     break;

    case 4:
    if(day_now < 22)
      {
        schedule_A = 'y';
        schedule_B = 'b';
        schedule_C = 'r';
      }
     else
       {
        schedule_A = 'y';
        schedule_B = 'b';
        schedule_C = 'g';
       }
     break;

    case 5:
    if(day_now <  13)
      {
        schedule_A = 'y';
        schedule_B = 'b';
        schedule_C = 'g';
      }
     else
       {
        schedule_A = 'y';
        schedule_B = 'r';
        schedule_C = 'g';
       }
     break;
     
    case 6:
    if(day_now < 4)
      {
        schedule_A = 'y';
        schedule_B = 'r';
        schedule_C = 'g';
      }
     else
       {
        schedule_A = 'b';
        schedule_B = 'r';
        schedule_C = 'g';
       }
     break;

    case 7:
    if(day_now <  28)
      {
        schedule_A = 'y';
        schedule_B = 'b';
        schedule_C = 'r';
      }
     else
       {
        schedule_A = 'y';
        schedule_B = 'b';
        schedule_C = 'g';
       }
     break;
 
    case 8:
    if(day_now < 17)
      {
        schedule_A = 'y';
        schedule_B = 'b';
        schedule_C = 'g';
      }
     else
       {
        schedule_A = 'y';
        schedule_B = 'r';
        schedule_C = 'g';
       }
     break;

    case 9:
    if(day_now < 7)
      {
        schedule_A = 'y';
        schedule_B = 'r';
        schedule_C = 'g';
      }
     else if(day_now > 7 && day_now < 26)
       {
        schedule_A = 'b';
        schedule_B = 'r';
        schedule_C = 'g';
       }
     else if(day_now > 26 || day_now == 26)
       {
        schedule_A = 'b';
        schedule_B = 'r';
        schedule_C = 'y';
       }
     break;

    case 10:
    if(day_now < 16)
      {
        schedule_A = 'b';
        schedule_B = 'r';
        schedule_C = 'y';
      }
     else
       {
        schedule_A = 'b';
        schedule_B = 'g';
        schedule_C = 'y';
       }
     break;
     
    case 11:
    if(day_now  < 7)
      {
        schedule_A = 'b';
        schedule_B = 'g';
        schedule_C = 'y';
      }
     else
       {
        schedule_A = 'r';
        schedule_B = 'g';
        schedule_C = 'y';
       }
     break;

    case 12:
    if(day_now == 1)
      {
        schedule_A = 'r';
        schedule_B = 'g';
        schedule_C = 'y';
      }
     else
       {
        schedule_A = 'r';
        schedule_B = 'g';
        schedule_C = 'b';
       }
     break;     
  }
}

void setduino()
{
  time_t t = RTC.get(); 
  if(t != 0)
    {
      setTime(t);
      rainbow();
    }
}

void rainbow()
{
  int tdelay = 250;

  analogWrite(yellow, 125);
  delay(tdelay);
  analogWrite(yellow, 0);
  delay(tdelay); 
  
  analogWrite(red, 125);
  delay(tdelay);
  analogWrite(red, 0);
  delay(tdelay);
  
  analogWrite(green, 125);
  delay(tdelay);
  analogWrite(green, 0);
  delay(tdelay);
 
  analogWrite(blue, 125);
  delay(tdelay);
  analogWrite(blue, 0);
  delay(tdelay);
  
  analogWrite(elective1, 125);
  delay(tdelay);
  
  analogWrite(elective2, 125);
  delay(tdelay);
  
  analogWrite(elective1, 0);
  delay(tdelay);
  
  analogWrite(elective2, 0);
  delay(tdelay);  
}
