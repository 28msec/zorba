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

#include "zorbamisc/config/platform.h"


namespace zorba { 

#ifndef ZORBA_FOR_ONE_THREAD_ONLY

/*******************************************************************************

********************************************************************************/

#ifdef ZORBA_HAVE_PTHREAD_H

class Latch
{
public:
  enum Mode { READ, WRITE };

protected:
  pthread_rwlock_t  theLatch;

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

#elif defined WIN32

#define LATCH_VALID   0xfab
#define LATCH_INVALID 0xbad


class Latch
{
public:
  enum Mode { READ, WRITE };

protected:
  HANDLE  mutex;
  HANDLE  cond_read;
  HANDLE  cond_write;

	int     valid;      // set when valid
	int     r_active;   // count readers active
	int     w_active;   // boolean writers active
	int     r_wait;     // count readers waiting
	int     w_wait;     // count writers waiting

  bool    rlocked;
  bool    wlocked;

public:
  Latch();

  ~Latch();
    
  void rlock();
  void wlock();

  void unlock();

protected:

	int destroy();

	/**
	**                                                             
	** Lock a read/write lock for read access.
	*/
	int readlock();

	/**
	**                                                             
	** Try to lock a read/write lock for read access, but
	** don't block if unavailable.
	*/
	int readtrylock();

	/**
	**                                                             
	** Unlock a read/write lock from read access.
	*/
	int readunlock();

	/**
	**                                                             
	** Lock a read/write lock for write access.
	*/
	int writelock();

	/**
	**                                                             
	** Try to lock a read/write lock for write access, but
	** don't block if unavailable.
	*/
	int writetrylock();

	/**
	**                                                             
	** Unlock a read/write lock from write access.
	*/
	int writeunlock();

  int lock_mutex();
  int unlock_mutex();
  int signal_cond_read();
  int broadcast_cond_read();
  int wait_cond_read();
  int signal_cond_write();
  int broadcast_cond_write();
  int wait_cond_write();

private:
  Latch(const Latch &);
  void operator=(const Latch &);
};

#else
  #error Unsupported thread system
#endif


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


#else // ZORBA_FOR_ONE_THREAD_ONLY

class Latch
{
public:
  void rlock() {}
  void wlock() {}

  void unlock() {}
};


class AutoLatch
{
};
#endif // ZORBA_FOR_ONE_THREAD_ONLY


} // namespace zorba


#endif
