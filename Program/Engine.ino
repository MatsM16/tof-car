/*
 * An object-oriented abstraction of a motor
*/
class Engine
{
  private:
    int pin;
    byte maxPower;

  public:
    Engine(int pin)
    {
      this->pin = pin;
      pinMode(pin, OUTPUT);

      maxPower = 255;
    }

    void SetMaxPower(byte power)
    {
      maxPower = power;
    }

    void SetPower(byte power)
    {
      power = min(power, maxPower);
      
      analogWrite(pin, power);
    }
};
