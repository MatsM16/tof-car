class DistSensor
{
  private:
    int pinOut;
    int pinIn;
    
  public:
    DistSensor(int in, int out)
    {
      pinIn = in;
      pinOut = out;

        pinMode(pinIn, INPUT);
        pinMode(pinOut, OUTPUT);
    }

    Read()
    {
        digitalWrite(pinOut, LOW);
        delayMicroseconds(2);
        digitalWrite(pinOut, HIGH);
        delayMicroseconds(10);
        digitalWrite(pinOut, LOW);

        int val = pulseIn(pinIn, HIGH) * .0343 / 2;

        if (val < 0)
          val = 0;
        if (val > 100)
          val = 100;

        return val;
    }
};
