/*
 * A simple controller outputting sensor readouts and 
*/
class DebugController : public ICarController
{
  private:
    SensorReader* sensors;
    Car* car;

    int debug_delaySecconds;
    byte debug_minPower;
    byte debug_maxPower;
    int debug_minAngle;
    int debug_maxAngle;

    void Delay()
    {
      delay(1000 * debug_delaySecconds);
    }

  public:
    void Init(Config* cfg, SensorReader* sensors, Car* car)
    {
      this->sensors = sensors;
      this->car = car;

      if (cfg != NULL)
      {
        debug_delaySecconds = cfg->GetInt("DEBUG_DELAY_SECCONDS", 5);
        
        debug_minPower = (byte)cfg->GetInt("DEBUG_POWER_MIN", 0);
        debug_maxPower = (byte)cfg->GetInt("DEBUG_POWER_MAX", 255);
        
        debug_minAngle = cfg->GetInt("DEBUG_ANGLE_MIN", -90);
        debug_maxAngle = cfg->GetInt("DEBUG_ANGLE_MAX", 90);
      }
      else
      {
        debug_delaySecconds = 5;
        
        debug_minPower = 0;
        debug_maxPower = 255;
        
        debug_minAngle = -90;
        debug_maxAngle = 90;
      }
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

      car->Update(debug_minPower, debug_minAngle);
      Delay();
      car->Update(debug_maxPower, debug_maxAngle);
      Delay();
    }

    void Dispose()
    {
      sensors->Dispose();
      car->Dispose();

      delete sensors;
      delete car;
    }
    
};
