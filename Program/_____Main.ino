SensorController* controller;

void setup()
{
  //
  // Load current configuration from disc
  //
  
  Config* cfg = NULL; //new Config(ReadFile("config.txt"));

  //
  // Initialize car components
  //
  Car* car = new Car(cfg);
  SensorReader* reader = new SensorReader(cfg);

  controller = new SensorController(cfg, reader, car);

  //
  // Initialization cleanup
  //
  delete cfg;
}

void loop()
{
  //
  // Let the car controller handle car updates.
  // This is because the controller could be switched
  //
  controller->Update();
}

void cleanup()
{
  controller->Dispose();
  delete controller;
}
