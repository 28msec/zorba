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

#ifndef API_STREAM_WRAPPER_BASE_H
#define API_STREAM_WRAPPER_BASE_H

#include <streambuf>
#include <cstdio>
#include <cstdlib>
#include <vector>


class StreamWrapperBase :
  public std::streambuf
{
public:
  StreamWrapperBase(const char *str) : begin_(str), end_(begin_ + std::strlen(str)), current_(begin_) {};
  StreamWrapperBase(): begin_(0), end_(0), current_(0) {};

  static int getEOF();
  
  // Get character in the case of underflow
  virtual int underflow();
  // Get character in the case of underflow and advance get pointer
  virtual int uflow();
  // Put character back in the case of backup underflow
  virtual int pbackfail(int ch);
  // Get number of characters available in the sequence
  virtual std::streamsize showmanyc();
  
private:

  // Copy contructor and assignment not allowed
  StreamWrapperBase(const StreamWrapperBase &);
  StreamWrapperBase &operator= (const StreamWrapperBase &);

  const char * const begin_;
  const char * const end_;
  const char * current_;
};

#endif
