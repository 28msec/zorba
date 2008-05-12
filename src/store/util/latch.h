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
#ifndef ZORBA_STORE_LATCH_H
#define ZORBA_STORE_LATCH_H

#include "common/common.h"

#ifdef WIN32
#include "util/rwlock.h"
#endif

namespace zorba { namespace store {

#ifndef ZORBA_FOR_ONE_THREAD_ONLY

/*******************************************************************************

********************************************************************************/
class Latch
{
public:

  enum Mode { READ, WRITE };

protected:

#ifdef HAVE_PTHREAD_H
  pthread_rwlock_t  theLatch;
#elif WIN32
  rwlock  theLatch;
  bool    rlocked;
  bool    wlocked;
#endif

public:
  Latch();

  ~Latch();
    
  void rlock();
  void wlock();

  void unlock();

 private:
  Latch(const Latch &);
  void operator=(const Latch &);
};


/*******************************************************************************

********************************************************************************/
class AutoLatch
{
private:
  Latch & theLatch;

public:
  AutoLatch(Latch& l, Latch::Mode m) : theLatch(l)
  {
    if (m == Latch::READ)
      theLatch.rlock();
    else
      theLatch.wlock();
  }
    
  ~AutoLatch()
  {
    theLatch.unlock();
  }
};

#else
class Latch
{
  void rlock() {}
  void wlock() {}

  void unlock() {}
};
class AutoLatch
{
};
#endif // ZORBA_FOR_ONE_THREAD_ONLY

} // namespace store
} // namespace zorba


#endif
