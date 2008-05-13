/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or  implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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
