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
#include <list>
#include "common/common.h"
#include "zorbatypes/rchandle.h"
#pragma once
#ifndef ZORBA_REF_COUNTED_STD_LIST
#define ZORBA_REF_COUNTED_STD_LIST

namespace zorba
{

template <typename T>
class rclist : public RCObject, public std::list<T>
{
  SYNC_CODE(mutable RCLock  lock;)
public:
  long* getSharedRefCounter() const { return NULL; }
  SYNC_CODE(RCLock* getRCLock() const { return &lock; });
};

}//end namespace zorba

#endif
