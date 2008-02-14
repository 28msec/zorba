/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: rwlock.h,v 1.1 2006/10/09 07:08:02 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *	Author: Paul Pedersen
 *
 */

#ifndef XQP_RWLOCK_H
#define XQP_RWLOCK_H

#include "zorba/config/config.h"

#ifdef WIN32
  #include <windows.h>
#elif defined ZORBA_USE_PTHREAD_LIBRARY
  #include <pthread.h>
#else
  #error Unsupported thread system
#endif

#ifndef _WIN32_WCE
# include <errno.h>
#endif

/*_____________________________________________________________________
| 
|  Read/write locks with read preferrence.
|
|  Reference: "Programming with POSIX Threads",
|  David Butenhof, Addison-Wesley [1997], Section 7.1.2.
|______________________________________________________________________*/

namespace xqp {

/*
**                                                    
** Read/write lock static initializer
*/
#ifdef WIN32
#elif defined ZORBA_USE_PTHREAD_LIBRARY
#define RWL_INITIALIZER \
	{	PTHREAD_MUTEX_INITIALIZER,	\
		PTHREAD_COND_INITIALIZER, 	\
		PTHREAD_COND_INITIALIZER,		\
		RWLOCK_VALID,								\
		0, 0, 0, 0 }
#else
  #error Unsupported thread system
#endif

#define RWLOCK_VALID		0xfab
#define RWLOCK_INVALID	0xbad


class rwlock
{
protected:
#ifdef WIN32
  HANDLE    mutex;
  HANDLE    cond_read;
  HANDLE    cond_write;
#elif defined ZORBA_USE_PTHREAD_LIBRARY
	pthread_mutex_t		mutex;
	pthread_cond_t		read;				// wait for read
	pthread_cond_t		write;			// wait for write
#else
  #error Unsupported thread system
#endif
	int								valid;			// set when valid
	int								r_active;		// count readers active
	int								w_active;		// boolean writers active
	int 							r_wait;			// count readers waiting
	int								w_wait;			// count writers waiting

public:
	rwlock();
	~rwlock();
	int destroy();

public:
	/**
	**                                                             
	** Handle cleanup when the read/write lock condition
	** variable wait is cancelled.
	*/
	static void read_cleanup(void* arg);
	static void write_cleanup(void* arg);

public:
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


private:
  
  int lock_mutex();
  int unlock_mutex();
  int signal_cond_read();
  int broadcast_cond_read();
  int wait_cond_read();
  int signal_cond_write();
  int broadcast_cond_write();
  int wait_cond_write();
//  void cleanup_push_read();
//  void cleanup_pop();
//  void cleanup_push_write();

};
		

}	/* namespace xqp */
#endif	/* XQP_RWLOCK_H */
