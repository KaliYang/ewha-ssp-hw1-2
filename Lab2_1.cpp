// Do not remove the include below
#include "Lab2_1.h"
#define FRONT_LED_PIN 10
#define REAR_LED_PIN 9
#define DUTY_CYCLE	20//20ms

boolean done = true;

void PWM_Write(int pin, int on_time, int on_time_perc)
{
	int on_time = DUTY_CYCLE*on_time_perc/100.0;
	int off_time = DUTY_CYCLE - on_time;

	digitalWrtie(pin, HIGH);
	delay(on_time);

	digitalWrtie(pin, LOW);
	delay(off_time);
}

void myAnalogWrite(int pin, int percent, int time)
{
	int num_loops = time/DUTY_CYCLE;
	int i;
	for(i=0;i<num_loops;i++)
	{
		PWM_Write(pin, percent);
	}
}

//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	pinMode(REAR_LED_PIN,OUTPUT);
}

void loop()
{
	if (done == false){
		int value = 100;
		int value_interval = 5;
		//(value/value_interval) = number of steps =20
		int total_time = 10000;

		int time_per_step = total_time/(value/value_interval);

		while(value>0)
		{
			myAnalogWrite(REAR_LED_PIN, value, time_per_step);
			value-=value_interval;
		}

		done = true;
	}
	else
		digitalWrtie(REAR_LED_PIN,LOW);


}


