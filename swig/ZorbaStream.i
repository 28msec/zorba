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

void ZorbaStream::checkBuffer()
{
  if (buffer==0)
  {
    bufferWrapper->fillBufferCallback();
    if (bufferWrapper->getLen() > 0) {
      bBegin = bCurrent = buffer = bufferWrapper->getBuffer();
      bEnd = bBegin + bufferWrapper->getLen();
    }
  } else if (bCurrent == bEnd)
  {
    if (bufferWrapper->getLen()==1024)
    {
      bufferWrapper->fillBufferCallback();
      if (bufferWrapper->getLen() > 0) {
        bBegin = bCurrent = buffer = bufferWrapper->getBuffer();
        bEnd = bBegin + bufferWrapper->getLen();
      }
    }
  }
  
}
int ZorbaStream::getEOF()
{
  return traits_type::eof();
}

int ZorbaStream::underflow()
{
    checkBuffer();
    if ((bCurrent == bEnd) || (buffer==0))
        return traits_type::eof();
    return traits_type::to_int_type(*bCurrent);
}

int ZorbaStream::uflow()
{
    checkBuffer();
    if ((bCurrent == bEnd) || (buffer==0))
        return traits_type::eof();
    return traits_type::to_int_type(*bCurrent++);
}

int ZorbaStream::pbackfail(int ch)
{
    checkBuffer();
    if (bCurrent == bBegin || (ch != traits_type::eof() && ch != bCurrent[-1]) || (buffer==0))
        return traits_type::eof();

    return traits_type::to_int_type(*--bCurrent);
}

std::streamsize ZorbaStream::showmanyc()
{
    checkBuffer();
    return bEnd - bCurrent;
}


%}  // end   Implementation

%include "ZorbaStream.h"