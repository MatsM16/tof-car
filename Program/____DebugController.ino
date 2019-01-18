/*
 * A simple controller outputting sensor readouts and 
*/
class DebugController : public ICarController
{
  private:
    SensorReader* sensors;
    Car* car;

  public:
    void Init(Config* cfg, SensorReader* sensors, Car* car)
    {
      this->sensors = sensors;
      this->car = car;
    }

    void Update()
    {
      SensorRead* readout = sensors->Read();

      if (Serial)
      {
        Serial.write(String(
          String("\nSensor [FORWARD]: " + readout->Fwd()) + 
          String("\nSensor [LEFT]: " + readout->Left()) + 
          String("\nSensor [RIGHT]: " + readout->Right())).c_str());
      }
      
      delete readout;

      car->Update(0, -90);

      delay(1000 * 5);

      car->Update(255, 90);

      delay(1000 * 5);
    }

    void Dispose()
    {
      sensors->Dispose();
      car->Dispose();

      delete sensors;
      delete car;
    }
    
};
