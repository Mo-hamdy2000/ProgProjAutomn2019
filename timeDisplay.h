#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <conio.h>
int flag=0;
typedef struct
{
    int hour;
    int minutes;
    int seconds;
}Time;

void printTime(Time t)
{
    printf("%d:%d:%d\n",t.hour,t.minutes,t.seconds);
}
///this function return the start time of the start of the play
///to be used in the function that print the difference between:
///that time and the current now
Time startTime()
{
    Time startT;
    time_t currentTime;
    time(&currentTime);
    struct tm *myTime = localtime(&currentTime);
    startT.hour = myTime ->tm_hour;
    startT.minutes = myTime->tm_min;
    startT.seconds = myTime ->tm_sec;
    return startT;
}

void timeFromStartToNow(Time startT)
{
    Time t,current;
    time_t currentTime;
    time(&currentTime);
    struct tm *myTime = localtime(&currentTime);
    t.hour = myTime ->tm_hour;
    t.minutes = myTime->tm_min ;
    t.seconds = myTime ->tm_sec ;
    if(t.seconds>=startT.seconds)
    {
        current.seconds=t.seconds-startT.seconds;
        if(t.minutes>=startT.minutes)
        {
            current.minutes=t.minutes-startT.minutes;
            if(t.hour>=startT.hour)
            {
                current.hour=t.hour-startT.hour;
            }
            else
            {
                t.hour+=24;
                current.hour=t.hour-startT.hour;
            }
        }
        else
        {
            t.minutes+=60;
            t.hour--;
            current.minutes=t.minutes-startT.minutes;
            if(t.hour>=startT.hour)
            {
                current.hour=t.hour-startT.hour;
            }
            else
            {
                t.hour+=24;
                current.hour=t.hour-startT.hour;
            }
        }
    }
    else
    {
        t.seconds+=60;
        t.minutes--;
        current.seconds=t.seconds-startT.seconds;
        if(t.minutes>=startT.minutes)
        {
            current.minutes=t.minutes-startT.minutes;
            if(t.hour>=startT.hour)
            {
                current.hour=t.hour-startT.hour;
            }
            else
            {
                t.hour+=24;
                current.hour=t.hour-startT.hour;
            }
        }
        else
        {
            t.minutes+=60;
            t.hour--;
            current.minutes=t.minutes-startT.minutes;
            if(t.hour>=startT.hour)
            {
                current.hour=t.hour-startT.hour;
            }
            else
            {
                t.hour+=24;
                current.hour=t.hour-startT.hour;
            }
        }
    }
    printTime(current);
}

void incTimer(Time start)
{
    while(!kbhit())
    {

        timeFromStartToNow(start);
        printf("press enter before entering the two points ");
        Sleep(60000);
        system("cls");
    }
    ///here is the place of the function of program progress
}

int main()
{
    Time start=startTime();
    while(1)
    {
        incTimer(start);
    }
    return 0;
}
