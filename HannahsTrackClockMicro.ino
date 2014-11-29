/*Hannah's Clock to keep of when each track is on break
Derek Chapman 5-11-14  
V1 finished 7/6/14
Note that the TimeAlarms is in 24 hour mode
*/

#include <Wire.h>
#include <DS1307RTC.h>
#include <TimeAlarms.h>
#include <Time.h>

//char track_on_break = 'a';
char schedule_A = 'a';
char schedule_B = 'a';
char schedule_C = 'a';

//LED Pins
int blue = 11;
int green = 10;
int red = 9;
int yellow = 6;
int elective1 = 5;
int elective2 = 13;

int RTCaddress = 0x68;

void setup()
{
  //turn on RGB LED + elective LEDs
  pinMode(red, OUTPUT);  pinMode(green, OUTPUT);  
  pinMode(blue, OUTPUT); pinMode(yellow, OUTPUT); 
  pinMode(elective1, OUTPUT);  pinMode(elective2, OUTPUT);
  
  //start the RTC + flash led red in case the RTC is no good
  start_testRTC();
  
  //run set schedules every time it reboots to setup the schedules 
  //also syncs duino and does light show to confirm success
  setSchedules();
  
  //setup various alarms
  setupalarms();
}

void loop()
{
  Alarm.delay(500);
}

void start_testRTC()
{
  Wire.begin();

  //flash led red in case the RTC is no good
  if(RTC.get() == 0)
    {
      for(int f = 0; f < 15; f++)
        {
          digitalWrite(red, HIGH);
          delay(500);
          digitalWrite(red,LOW);
          delay(500);
        }
    }
}

void setupalarms()
{
  //daily alarm for each elective block start and end
  Alarm.alarmRepeat(8, 20, 0, SAE1S);         //schedule A elective 1 start
  Alarm.alarmRepeat(9, 7, 0, leds_off);          //schedule A elective 1 ends
  Alarm.alarmRepeat(9, 9, 0, SAE2S);         //schedule A elective 2 start
  Alarm.alarmRepeat(9, 54, 0, leds_off);          //schedule A elective 2 ends
  
  Alarm.alarmRepeat(10, 11, 0, SBE1S);         //schedule B elective 1 start
  Alarm.alarmRepeat(10, 56, 0, leds_off);          //schedule B elective 1 ends
  Alarm.alarmRepeat(10, 58, 0, SBE2S);         //schedule B elective 2 start
  Alarm.alarmRepeat(11, 43, 0, leds_off);          //schedule B elective 2 ends
  
  Alarm.alarmRepeat(13, 03, 0, SCE1S);         //schedule C elective 1 start
  Alarm.alarmRepeat(13, 48, 0, leds_off);          //schedule C elective 1 ends
  Alarm.alarmRepeat(13, 50, 0, SCE2S);         //schedule C elective 2 start
  Alarm.alarmRepeat(14, 35, 0, leds_off);          //schedule C elective 2 ends
  
  //daily alarm to set schedules
  Alarm.alarmRepeat(3,0,0, setSchedules);
}
