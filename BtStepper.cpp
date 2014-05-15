#include "Arduino.h"
#include "BtStepper.h"


BtStepper::BtStepper(int p1, int p2)
{
	init();
	
	pin1 = p1;
	pin2 = p2;

	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);

	pin3 = 0;
	pin4 = 0;

	pinCount = 2;
}




BtStepper::BtStepper(int p1, int p2, int p3, int p4)
{
	init();

	pin1 = p1;
	pin2 = p2;
	pin3 = p3;
	pin4 = p4;

	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);
	pinMode(pin3, OUTPUT);
	pinMode(pin4, OUTPUT);

	pinCount = 4;
}




void BtStepper::init()
{
	reverse = false;

	steps[0][0] = HIGH;
	steps[0][1] = LOW;
	steps[0][2] = HIGH;
	steps[0][3] = LOW;
	
	steps[1][0] = LOW;
	steps[1][1] = HIGH;
	steps[1][2] = HIGH;
	steps[1][3] = LOW;
	
	steps[2][0] = LOW;
	steps[2][1] = HIGH;
	steps[2][2] = LOW;
	steps[2][3] = HIGH;
	
	steps[3][0] = HIGH;
	steps[3][1] = LOW;
	steps[3][2] = LOW;
	steps[3][3] = HIGH;
	
	stepNumber = 0;
}




BtStepper& BtStepper::operator++()
{
	if(!reverse)
		stepNumber++;
	else
		stepNumber--;
	
	step();
	
	return *this;
}




BtStepper BtStepper::operator++(int)
{
	BtStepper tmp(*this);
  operator++();
  return tmp;
}



BtStepper& BtStepper::operator--()
{
	if(!reverse)
		stepNumber--;
	else
		stepNumber++;
	
	step();
	
	return *this;
}




BtStepper BtStepper::operator--(int)
{
	BtStepper tmp(*this);
  operator--();
  return tmp;
}




void BtStepper::step()
{
	int s = stepNumber%4;
	
	if(s<0)
		s += 4;

	if (pinCount == 2)
	{
		digitalWrite(pin1, steps[s][1]);
		digitalWrite(pin2, steps[s][2]);
	}
	else if (pinCount == 4)
	{
		digitalWrite(pin1, steps[s][0]);
		digitalWrite(pin2, steps[s][1]);
		digitalWrite(pin3, steps[s][2]);
		digitalWrite(pin4, steps[s][3]);
	}
}