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

%feature("director") ZorbaStream;

%{  // start Implementation

#include "ZorbaStream.h"
#include <cassert>
#include <iostream>
#include <ios>

void ZorbaStream::fillStreamCallback()
{
  // Local fill buffer
  int len = 10;
  int *buffer = (int*) malloc(sizeof(int)*(len));
  int* p=buffer;
  for (int i=0; i<(len); i++, *p++ = i+40)
    ;
  setStream(buffer, len);
  return;
}

void ZorbaStream::setStream(int *aStream, int aLen)
{
  if (aLen > 0)
    memcpy(buffer, aStream, aLen*sizeof(int));
  len = aLen;
  return;
}

int * ZorbaStream::getStream()
{
  return buffer;
}

int ZorbaStream::getLen()
{
  return len;
}

void ZorbaStream::write( const char * str, size_t len )
{
  return;
}

%}  // end   Implementation


%include "ZorbaStream.h"