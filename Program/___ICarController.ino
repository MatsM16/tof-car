/*
 * An abstraction of the car controller to allow for easy switching between controllers.
*/
class ICarController
{
  public:
    virtual void Init(Config* cfg, SensorReader* sensors, Car* car);
    virtual void Dispose();
    virtual void Update();
};
