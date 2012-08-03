/*
 * Copyright 2006-2012 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#ifndef API_ZORBA_STREAM_H
#define API_ZORBA_STREAM_H

#include <streambuf>
#include <cstdio>
#include <cstdlib>
#include <vector>

class ZorbaStream
{
public:
  ZorbaStream() {};

  //STREAM TO ZORBA
  virtual void fillStreamCallback();
  void setStream(int *aStream, int aLen);
  int * getStream();
  int getLen();
  
  //STREAM FROM ZORBA
  virtual void write( const char * str, size_t len );
  
private:
  //FOR STREAM TO ZORBA
  int buffer[1024];
  int len;

  // Copy contructor and assignment not allowed
  ZorbaStream(const ZorbaStream &);
  ZorbaStream &operator= (const ZorbaStream &);

};

#endif
