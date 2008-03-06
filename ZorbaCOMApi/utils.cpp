
#include "stdafx.h"
#include "utils.h"

char* getUtf8String( BSTR bstr )
{
  int    utf8Len;
  char   *utf8string = NULL;

  if(!bstr)
  {
    utf8string = new char[1];
    utf8string[0] = 0;
    return utf8string;
  }

  if(sizeof(bstr[0]) > 1)
  {
    //compute necesary space
    if(!(utf8Len=WideCharToMultiByte(CP_UTF8, 0,
                      bstr, -1,//aQueryStringLen,
                      NULL, 0,
                      NULL, NULL)))
    {
      return NULL;
    }
    
    utf8string = new char[utf8Len];

    //convert from 16 bits to UTF8
    if(!WideCharToMultiByte(CP_UTF8, 0,
                      bstr, -1,//aQueryStringLen,
                      utf8string, utf8Len,
                      NULL, NULL))
    {
      delete[] utf8string;
      return NULL;
    }
  }
  else
  {
    utf8Len = SysStringLen(bstr);
    utf8string = new char[utf8Len+1];
    utf8string[0] = 0;
    memcpy(utf8string,  bstr, utf8Len+1);
  }

  return utf8string;
}
