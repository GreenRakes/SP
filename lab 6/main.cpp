#include "mbed.h"
#include "BME280.h"

BME280 sensor(I2C_SDA, I2C_SCL);

DigitalOut oled1(LED1);
DigitalOut oled(D7);

InterruptIn ibutton1(BUTTON1);
Ticker toggle_led_ticker;
static auto sleep_time = 1000ms;

char buf[2];

int main()
{
while (true)
{

printf("%d degC, %d hPa, %d %%\n", (int)sensor.getTemperature(), (int)sensor.getPressure(), (int)sensor.getHumidity());

if (((int)sensor.getTemperature()>=30) && ((int)sensor.getHumidity()<=30))
{
oled1 =1;
ThisThread::sleep_for(200ms);
oled1 =0;
ThisThread::sleep_for(200ms);
}
else
{
if (((int)sensor.getTemperature()>=30) && ((int)sensor.getHumidity()>=30))
{
oled =1;
ThisThread::sleep_for(200ms);
oled =0;
ThisThread::sleep_for(200ms);
}
else
{
if (((int)sensor.getTemperature()<30) && ((int)sensor.getHumidity()<30))
{
oled = 0;
oled1 =1;
}
}

}

ThisThread::sleep_for(1000ms);

}
}
