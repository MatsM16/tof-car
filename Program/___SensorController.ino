class SensorController
{
  private:
    SensorReader* sensors;
    Car* car;

    int steerFactorLeft;
    int steerFactorRight;

    int powerFactorFwd;
    int powerFactorLeft;
    int powerFactorRight;

  public:
    SensorController(Config* cfg, SensorReader* sensors, Car* car)
    {
      this->sensors = sensors;
      this->car = car;

      steerFactorLeft = cfg->GetInt("FACTOR_STEER_LEFT", 1);
      steerFactorRight = cfg->GetInt("FACTOR_STEER_RIGHT", 1);

      powerFactorFwd = cfg->GetInt("FACTOR_POWER_FORWARD", 1);
      powerFactorLeft = cfg->GetInt("FACTOR_POWER_LEFT", 1);
      powerFactorRight = cfg->GetInt("FACTOR_POWER_RIGHT", 1);
    }

    void Update()
    {
      SensorRead* readout = sensors->Read();

      //
      // Handle car steering and power based on sensor readouts
      //
      // FYI, current implementation is shit...
      //
      int steer = 0;
      steer += readout->Right() * steerFactorRight;
      steer -= readout->Left() * steerFactorLeft;

      byte power = 255;
      power -= readout->Right() * powerFactorRight;
      power -= readout->Left() * powerFactorLeft;
      power -= readout->Fwd() * powerFactorFwd;

      car->Update(power, steer);
      
      delete readout;
    }

    void Dispose()
    {
      sensors->Dispose();
      car->Dispose();

      delete sensors;
      delete car;
    }
    
};
