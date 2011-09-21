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
#pragma once
#include <iostream>
#include <list>

namespace zorba { namespace debugclient {

template<typename T>
class LockFreeProducer
{
public:
  virtual bool produce(const T& aValue) = 0;
};

template <typename T>
class LockFreeConsumer {
public:
  virtual bool consume(T& result) = 0;
};
template<typename T>
class LockFreeQueue : public LockFreeConsumer<T>, public LockFreeProducer<T>
{
public:
  LockFreeQueue();
  bool produce(const T& value);
  bool consume(T& result);
private:
  std::list<T> theList;
  typename std::list<T>::iterator theFirst;
  typename std::list<T>::iterator theDivider;
  typename std::list<T>::iterator theLast;
};

template<typename T>
LockFreeQueue<T>::LockFreeQueue()
{
  theList.push_back(T());
  theFirst = theDivider = theLast = theList.begin();
}

template<typename T>
bool LockFreeQueue<T>::produce(T const &value)
{
  typename std::list<T>::iterator lLastInc = theLast;
  ++lLastInc;
  lLastInc = theList.insert(lLastInc, value);
  theLast = lLastInc;
  while (theFirst != theDivider) {
    ++theFirst;
    typename std::list<T>::iterator lFirstDec = theFirst;
    --lFirstDec;
    theList.erase(lFirstDec);
  }
  return true;
}

template<typename T>
bool LockFreeQueue<T>::consume(T &result)
{
  if (theDivider != theLast) {
    typename std::list<T>::iterator lDividerInc = theDivider;
    ++lDividerInc;
    result = *(lDividerInc);
    theDivider = lDividerInc;
    return true;
  }
  return false;
}
}} // namespace zorba::debugclient
