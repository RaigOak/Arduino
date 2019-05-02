#include <Servo.h>
Servo motor;
int pinMotor = 11;
bool condition;
void setup()
{
  condition = false;
  motor.attach(pinMotor);
}

void loop()
{
  condition = get_condition();
  if (condition)
  {
    motor.write(180);
  }
  else
  {
    motor.write(0);
  }
}

bool get_condition()
{
  return !condition
}
