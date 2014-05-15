#include <BtStepper.h>

BtStepper motor(4,5,6,7);

void setup()
{
  //change it to false/true if you want to change rotation direction
  motor.reverse = true;

  Serial.begin(9600); 
	
	//wait until serial port open
  while (!Serial);
}
void loop() 
{
  if(Serial.available())
  {
    int steps = Serial.parseInt();

    for(int i=0; i<abs(steps); i++)
    {
      if(steps<0)
        motor--;
      else
        motor++;

      //change delay time to get various stepper speeds
      delay(5);
    }
  }
}
