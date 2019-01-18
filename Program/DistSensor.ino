/*
 * An object-oriented abstraction of the ultrasonic distance sensors
*/
class DistSensor
{
  private:
    int pinIn;
    int pinOut;

    int clampMin;
    int clampMax;

  public:
    DistSensor(int pin_in, int pin_out)
    {
      pinIn = pin_in;
      pinOut = pin_out;

      pinMode(pinIn, INPUT);
      pinMode(pinOut, OUTPUT);

      clampMin = 0;
      clampMax = 100;
    }

    void setMinDist(int dist)
    {
      clampMin = dist;
    }

    void setMaxDist(int dist)
    {
      clampMax = dist;
    }

    int Read()
    {
        digitalWrite(pinOut, LOW);
        delayMicroseconds(2);
        digitalWrite(pinOut, HIGH);
        delayMicroseconds(10);
        digitalWrite(pinOut, LOW);

        int val = pulseIn(pinIn, HIGH) * .0343 / 2;

        if (val < clampMin)
          return clampMin;
        
        if (val > clampMax)
          return clampMax;

        return val;
    }
};
