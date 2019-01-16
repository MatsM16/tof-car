class Engine
{
  private:
    int pin;

  public:
    Engine(int pin)
    {
      this->pin = pin;
      pinMode(pin, OUTPUT);
    }

    void SetPower(byte power)
    {
      analogWrite(pin, power);
    }
};
