#include <BtStepper.h>

BtStepper motor(4,5,6,7);

void setup()
{
  
}
void loop() 
{
  for(int i=0; i<400; i++)
  {
      motor++;
      
      delay(10);
  }
}
