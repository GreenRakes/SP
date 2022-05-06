#include "mbed.h"

DigitalOut oled1(LED1);
DigitalOut oled(D7);
InterruptIn ibutton1(BUTTON1);

int i=0;
static auto sleep_time = 100ms;

Ticker toggle_led_ticker;

void led_ticker()
{
oled1 = !oled1;
}
void pressed()
{
if (i<3)
i++;
else
i=0;
}

int main()
{

ibutton1.rise(&pressed);

while (true)
{
if (i==0)
{
oled = 0;
oled1 =1;
ThisThread::sleep_for(1000ms);
oled1 =0;
ThisThread::sleep_for(1000ms);
}
if (i==1)
{
oled1 =1;
ThisThread::sleep_for(200ms);
oled1 =0;
ThisThread::sleep_for(200ms);
}
if (i==2)
{
oled1 =0 ;
oled =1;
ThisThread::sleep_for(1000ms);
oled =0;
ThisThread::sleep_for(1000ms);
}
if (i==3)
{
oled = 1;
ThisThread::sleep_for(200ms);
oled = 0;
ThisThread::sleep_for(200ms);
}

}

}
