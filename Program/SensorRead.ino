class SensorRead
{
  private:
    int distFwd;
    int distLeft;
    int distRight;

  public:
    SensorRead(int fwd, int left, int right)
    {
      distFwd = fwd;
      distLeft = left;
      distRight = right;
    }

    int Fwd()
    {
      return distFwd;
    }

    int Left()
    {
      return distLeft;
    }

    int Right()
    {
      return distRight;
    }
};
