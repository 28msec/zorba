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

%feature("director") ZorbaIOStream;

%{  // start Implementation

#include "ZorbaIOStream.h"
#include <cassert>
#include <iostream>
#include <ios>

void ZorbaIOStream::fillStreamCallback()
{
  // Local fill buffer EXAMPLE
  int len = ZORBA_STREAM_BUFFER_SIZE;
  char *buffer = (char*) malloc(sizeof(char)*(len));
  char* p=buffer;
  for (int i=0; i<(len); i++, *p++ = 'Z')
    ;
  setStream(buffer, len);
  return;
}

void ZorbaIOStream::setStream(const char *aStream, size_t aLen, int aBufferLength)
{
  if (aBufferLength<0) aBufferLength=0;
  if (aBufferLength > 0)
    memcpy(buffer, aStream, aBufferLength*sizeof(char));
  len = aBufferLength;
  return;
}

void ZorbaIOStream::setStream(const char *BYTE, size_t aLen)
{
  if (aLen<0) aLen=0;
  if (aLen > 0)
    memcpy(buffer, BYTE, aLen*sizeof(char));
  len = aLen;
  return;
}

char * ZorbaIOStream::getStream()
{
  return buffer;
}

int ZorbaIOStream::getLen()
{
  return len;
}

void ZorbaIOStream::write(const char *BYTE, size_t aLen)
{
  return;
}

%}  // end   Implementation


%include "ZorbaIOStream.h"