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

#ifndef API_BUFFER_WRAPPER_BASE_H
#define API_BUFFER_WRAPPER_BASE_H

#include <streambuf>
#include <cstdio>
#include <cstdlib>
#include <vector>

class BufferWrapperBase
{
public:
  BufferWrapperBase() {};
  
  //BUFFER
  int buffer[1024];
  int len;

  virtual void fillBufferCallback();
  void setBuffer(int *aBuffer, int aLen);

private:

  // Copy contructor and assignment not allowed
  BufferWrapperBase(const BufferWrapperBase &);
  BufferWrapperBase &operator= (const BufferWrapperBase &);

};

#endif
