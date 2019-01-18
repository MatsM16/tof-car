ICarController* controller;

void setup()
{
  //
  // Card initialization
  //
  Serial.begin(9600);
  SD.begin(4);
  
  //
  // Load current configuration from disc
  //
  
  Config* cfg = NULL; 
  //cgf = new Config(ReadFile("config.txt"));
  
  //
  // Initialize car components
  //
  Car* car = new Car(cfg);
  SensorReader* reader = new SensorReader(cfg);

  String mode = cfg->Get("MODE", "DEFAULT");

  if (cfg != NULL && mode == "DEBUG")
    controller = new DebugController();
  else
    controller = new SensorController();

  controller->Init(cfg, reader, car);

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
