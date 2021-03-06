/*
 * A handler for obtaining data from a config string.
*/
class Config
{
  private:
    String src;

  public:
    Config(String src)
    {
      this->src = src;
    }

    String Get(String property, String def)
    {
      int propertyIndex = src.lastIndexOf(property);

      if (propertyIndex < 0)
        return def;

      int valueStart = propertyIndex + property.length() + 1;
      int valueEnd = src.indexOf("\n", valueStart);

      if (valueEnd < 0)
        return def;

      return src.substring(valueStart, valueEnd + 1);
    }

    int GetInt(String property, int def)
    {
      String val = Get(property, "NOT_FOUND");

      if (val == "NOT_FOUND")
        return def;

      return val.toInt();
    }

    bool GetBool(String property, bool def)
    {
      String val = Get(property, "NOT_FOUND");

      if (val == "NOT_FOUND")
        return def;

      if (val == "TRUE" || val == "1")
        return true;
      else
        return false;
    }

    int* GetIntArray(String property)
    {
      String val = Get(property, "NOT_FOUND");

      if (val == "NOT_FOUND")
        return NULL;

      int commaCount = 0;
      for (int i = 0; i < val.length(); i++)
        if (val[i] == ',')
          commaCount++;

      String arr[commaCount];
      String builder = "";
      int numberIndex = 0;
      for (int i = 0; i < val.length(); i++)
      {
        if (val[i] != ',')
          builder += val[i];
        else
        {
          
        }
      }
    }
};
