#include <SD.h>

void InitFileReader()
{
  //
  // Not implemented
  //
}

String ReadFile (char file[])
{
  File fileStream = SD.open(file);

  String content = String("");
  
  for (int i = 0; i < fileStream.available(); i++)
  {
    content += fileStream.read();
  }

  fileStream.flush();
  fileStream.close();

  return content;
}
