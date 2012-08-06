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

#ifndef API_ZORBA_IO_STREAM_H
#define API_ZORBA_IO_STREAM_H

#include <streambuf>
#include <cstdio>
#include <cstdlib>
#include <vector>

class ZorbaIOStream
{
public:
  ZorbaIOStream() {};

  //STREAM TO ZORBA
  virtual void fillStreamCallback();
  void setStream(const char aStream[], size_t aLen, int aBufferLength);
  void setStream(const char * aStream, size_t aLen);
  char * getStream();
  int getLen();
  
  //STREAM FROM ZORBA
  virtual void write(const char * aStream, size_t aLen);
  
private:
  //FOR STREAM TO ZORBA
  char buffer[ZORBA_STREAM_BUFFER_SIZE];
  int len;

  // Copy contructor and assignment not allowed
  ZorbaIOStream (const ZorbaIOStream &);
  ZorbaIOStream &operator= (const ZorbaIOStream &);

};

#endif
