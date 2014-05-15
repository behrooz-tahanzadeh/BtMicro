/*
***********************************************************
	BtMicro Package
	BtStepper.h - Arduino Stepper Controller
	
	Developed by Behrooz Tahanzadeh (http://b-tz.com)
	
	Copyright 2014 License: GNU GPL v3 http://www.gnu.org/licenses/gpl-3.0.html
	Project home: https://github.com/behrooz-tahanzadeh/BtMicro
	
***********************************************************
*/

#ifndef BtStepper_h
#define BtStepper_h

class BtStepper
{
  public:
	
		BtStepper(int p1, int p2);
		BtStepper(int p1, int p2, int p3, int p4);

		BtStepper& operator++();
		BtStepper operator++(int);

		BtStepper& operator--();
		BtStepper operator--(int);
	
		bool reverse;
		int stepDelay;
	
	private:

		int pin1;
		int pin2;
		int pin3;
		int pin4;
		int pinCount;
		int stepNumber;
		int steps[4][4];
		
		void step();
		void init();
};

#endif