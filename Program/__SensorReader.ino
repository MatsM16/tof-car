/*
 * Handles reading and enterpreting of sonsor components
*/
class SensorReader
{
  private:
    DistSensor* dist_fwd;
    DistSensor* dist_left;
    DistSensor* dist_right;

    void setMinDistance(int dist)
    {
      dist_fwd->setMinDist(dist);
      dist_left->setMinDist(dist);
      dist_right->setMinDist(dist);
    }

    void setMaxDistance(int dist)
    {
      dist_fwd->setMaxDist(dist);
      dist_left->setMaxDist(dist);
      dist_right->setMaxDist(dist);
    }

  public:
    SensorReader(Config* cfg)
    {
      if (cfg != NULL)
      {
        dist_fwd   = new DistSensor(0, 0);
        dist_left  = new DistSensor(0, 0);
        dist_right = new DistSensor(0, 0);

        setMinDistance(0);
        setMaxDistance(100);
      }
      else
      {
        dist_fwd = new DistSensor(
          cfg->GetInt("PIN_SENSOR_DIST_FWD_IN", 0),
          cfg->GetInt("PIN_SENSOR_DIST_FWD_OUT", 0));
          
        dist_left = new DistSensor(
          cfg->GetInt("PIN_SENSOR_DIST_LEFT_IN", 0),
          cfg->GetInt("PIN_SENSOR_DIST_LEFT_OUT", 0));
          
        dist_right = new DistSensor(
          cfg->GetInt("PIN_SENSOR_DIST_RIGHT_IN", 0),
          cfg->GetInt("PIN_SENSOR_DIST_RIGHT_OUT", 0));

        setMinDistance(cfg->GetInt("SENSOR_DIST_MIN", 0));
        setMaxDistance(cfg->GetInt("SENSOR_DIST_MAX", 100));
      }
    }
  
    SensorRead* Read()
    {
      return new SensorRead(
        dist_fwd->Read(),
        dist_left->Read(),
        dist_right->Read());
    }

    void Dispose()
    {
      delete dist_fwd;
      delete dist_left;
      delete dist_right;
    }
};
