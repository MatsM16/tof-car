#include <Servo.h>

class Car
{
  private:
    int enginePin;
    int servoPin;

    Servo steeringWheel;
  
  public:
    Car(int enginePin, int servoPin)
    {
      this->enginePin = enginePin;
      this->servoPin = servoPin;

      steeringWheel.attach(servoPin);
      pinMode(enginePin, OUTPUT);
    }

    // Power between 0 and 255
    setPower(byte power)
    {
      analogWrite(enginePin, power);
    }

    // Angle between -90deg and 90deg
    setAngle(int angle)
    {
      angle += 90;
      
      if (angle > 180)
          angle = 180;

      if (angle < 0)
          angle = 0;
      
      steeringWheel.write(angle);
    }
};

