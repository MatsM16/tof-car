#include <Servo.h>

class Steering
{
  private:
    int pin;
    Servo servo;

  public:
    Steering(int pin)
    {
      this->pin = pin;
      servo.attach(pin);
    }

    void SetAngle(int angle)
    {
      angle += 90;
      
      if (angle > 180)
        angle = 180;

      if (angle < 0)
        angle = 0;

      servo.write(angle);
    }
};
