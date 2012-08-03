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

%feature("director") ZorbaBuffer;

%{  // start Implementation

#include "ZorbaBuffer.h"
#include <cassert>
#include <iostream>

void ZorbaBuffer::checkBuffer()
{
  if (buffer==0)
  {
    streamWrapper->fillStreamCallback();
    if (streamWrapper->getLen() > 0) {
      bBegin = bCurrent = buffer = streamWrapper->getStream();
      bEnd = bBegin + streamWrapper->getLen();
    }
  } else if (bCurrent == bEnd)
  {
    if (streamWrapper->getLen()==1024)
    {
      streamWrapper->fillStreamCallback();
      if (streamWrapper->getLen() > 0) {
        bBegin = bCurrent = buffer = streamWrapper->getStream();
        bEnd = bBegin + streamWrapper->getLen();
      }
    }
  }
  
}
int ZorbaBuffer::getEOF()
{
  return traits_type::eof();
}

int ZorbaBuffer::underflow()
{
  checkBuffer();
  if ((bCurrent == bEnd) || (buffer==0))
    return traits_type::eof();
  return traits_type::to_int_type(*bCurrent);
}

int ZorbaBuffer::uflow()
{
  checkBuffer();
  if ((bCurrent == bEnd) || (buffer==0))
    return traits_type::eof();
  return traits_type::to_int_type(*bCurrent++);
}

int ZorbaBuffer::pbackfail(int ch)
{
  checkBuffer();
  if (bCurrent == bBegin || (ch != traits_type::eof() && ch != bCurrent[-1]) || (buffer==0))
    return traits_type::eof();

  return traits_type::to_int_type(*--bCurrent);
}

std::streamsize ZorbaBuffer::showmanyc()
{
  checkBuffer();
  return bEnd - bCurrent;
}

std::streamsize ZorbaBuffer::xsputn ( const char * str, std::streamsize len ) {
  // Wrapping to virtual function
  streamWrapper->write(str, len);
  return len;
}

int ZorbaBuffer::overflow ( int c )
{
  streamWrapper->write((const char*)&c, 1);
  return c;
}


%}  // end   Implementation

%include "ZorbaBuffer.h"