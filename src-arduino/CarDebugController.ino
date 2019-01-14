class CarDebugController
{
  private:
    byte power;
    int angle;
  public:
    CarDebugController(byte power, int angle)
    {
      this->power = power;
      this->angle = angle;
    }

    byte readPower()
    {
      return power;
    }

    int readAngle()
    {
      return angle;
    }
};
