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

#ifndef API_ZORBA_BUFFER_H
#define API_ZORBA_BUFFER_H

#include <streambuf>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "ZorbaBuffer.h"


class ZorbaBuffer :
  public std::streambuf
{
public:
  ZorbaBuffer(ZorbaStream &aStreamWrapper): bBegin(0), bEnd(0), bCurrent(0), buffer(0), streamWrapper(&aStreamWrapper) {};

  // HELPER
  // Function to return EOF character from other languages
  static int getEOF();

  // INPUT
  // Get character in the case of underflow
  int underflow();
  // Get character in the case of underflow and advance get pointer
  int uflow();
  // Put character back in the case of backup underflow
  int pbackfail(int ch);
  // Get number of characters available in the sequence
  std::streamsize showmanyc();

  // OUTPUT
  // Write sequence of characters <Inherited>
  virtual std::streamsize xsputn ( const char * str, std::streamsize len );
  // Write character in the case of overflow
  virtual int overflow ( int c = EOF );
  
  
  

private:
  void checkBuffer();
  // Copy contructor and assignment not allowed
  ZorbaBuffer(const ZorbaBuffer &);
  ZorbaBuffer &operator= (const ZorbaBuffer &);

  //BUFFER
  int * buffer;
  int * bBegin;
  int * bEnd;
  int * bCurrent;
  ZorbaStream *streamWrapper;

  char * cBuffer;
};

#endif
