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
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "stringiterator_streambuf.h"

using namespace std;
namespace zorba{

StringIteratorStreamBuf::StringIteratorStreamBuf()
{
  current_buffer = 0;
  last_buffer = 0;
  begin_offset = 0;
  is_eof = false;
}

//get next buffer
int StringIteratorStreamBuf::underflow()
{
  if(is_eof)
    return EOF;
  begin_offset += buffer[current_buffer].length();
  current_buffer = 1 - current_buffer;
  if(last_buffer != current_buffer)
  {
    buffer[current_buffer].resize(0);
    last_buffer = current_buffer;
    if(!next(buffer[current_buffer]))
    {
      //current_buffer = 1 - current_buffer;
      buffer[current_buffer].resize(0);
      is_eof = true;
      return EOF;
    }
  }
  char *buffstr = (char*)buffer[current_buffer].c_str();
  setg(buffstr, buffstr, buffstr+buffer[current_buffer].length());
  return *buffstr;
}

//unget char, some special cases
int StringIteratorStreamBuf::pbackfail ( int c )
{
  if(eback() != gptr())
  {
    setg(eback(), gptr()-1, egptr());
    if(c != EOF)
      *gptr() = (char)c;
    return 1;
  }

  //else have to rewind to previous buffer
  if(last_buffer != current_buffer)
    return EOF;
  if(buffer[1-last_buffer].length() == 0)
    return EOF;
  current_buffer = 1 - current_buffer;

  begin_offset -= buffer[current_buffer].length();
  char *buffstr = (char*)buffer[current_buffer].c_str();
  setg(buffstr, buffstr+buffer[current_buffer].length()-1, buffstr+buffer[current_buffer].length());
  if(c != EOF)
    *gptr() = (char)c;
  return 1;
}

//set a new position
//if going too much back, restart the iterator
streampos StringIteratorStreamBuf::seekoff ( streamoff off, ios_base::seekdir way, ios_base::openmode which )
{
  if(!(which & ios_base::in))
    return -1;

  streampos targetpos;
  if(way == ios_base::end)
  {
    if(off > 0)
      return -1;
    while(underflow() != EOF);
    streampos maxpos = begin_offset + (streamoff)buffer[current_buffer].length();
    targetpos = maxpos + off;
  }
  else if(way == ios_base::cur)
  {
    targetpos = begin_offset + (streamoff)(gptr() - eback()) + off;
  }
  else if(way == ios_base::beg)
  {
    if(off < 0)
      return -1;
    targetpos = off;
  }
  else
    return -1;
  return seekpos(targetpos, ios_base::in);
}

//set a new position
//if going too much back, restart the iterator
streampos StringIteratorStreamBuf::seekpos ( streampos sp, ios_base::openmode which )
{
  if(!(which & ios_base::in))
    return -1;

  if(sp < begin_offset)
  {
    setg(eback(), eback(), egptr());
    pbackfail(EOF);
    if(sp < begin_offset)
    {
      //restart the iterator
      if(!reset())
        return -1;
      buffer[0].resize(0);
      buffer[1].resize(0);
      current_buffer = last_buffer = 0;
      begin_offset = 0;
      is_eof = false;
      setg(NULL, NULL, NULL);
    }
  }
  while(sp >= (begin_offset+(streamoff)buffer[current_buffer].length()))
  {
    if(underflow() == EOF)
    {
      if(sp == (begin_offset+(streamoff)buffer[current_buffer].length()))
        break;
      return -1;
    }
  }

  setg(eback(), eback() + (streamoff)(sp - begin_offset), egptr());
  return sp;
}

}