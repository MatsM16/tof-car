const Car* car;
const DistSensor* sensor;
//const CarDebugController* controller;

void setup()
{
  Serial.begin(9600);

  car = new Car(0, 9);
  sensor = new DistSensor(3, 4);
  //controller = new CarDebugController(10, 0);
}

void loop ()
{
  int angle = map(sensor->Read(), 2, 200, -90, 90);
  Serial.println(sensor->Read());
  car->setAngle(angle);
  //car->setPower(controller->readPower());
  //car->setAngle(controller->readAngle());
}
