class Car
{
  private:
    //
    // Components
    //
    Engine* engine;
    Steering* steering;

  public:
    Car(Config* cfg)
    {
      if (cfg != NULL)
      {
        engine = new Engine(0);
        steering = new Steering(0);
      }
      else
      {
        engine = new Engine(cfg->GetInt("PIN_ENGINE", 0));
        steering = new Steering(cfg->GetInt("PIN_STEERING", 0));
      }
    }

    void Update(int angle, byte power)
    {
      engine->SetPower(power);
      steering->SetAngle(angle);
    }

    void Dispose()
    {
      delete engine;
      delete steering;
    }
};
