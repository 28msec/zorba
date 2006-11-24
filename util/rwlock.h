/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: rwlock.h,v 1.1 2006/10/09 07:08:02 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.  All Rights Reserved.
 *
 */

#ifndef XQP_RWLOCK_H
#define XQP_RWLOCK_H

#include <pthread.h>
#include <errno.h>

/*_____________________________________________________________________
|                                                                      |
|  Read/write locks
|  with read preferrence.
|
|  Reference: "Programming with POSIX Threads",
|  David Butenhof, Addison-Wesley [1997], Section 7.1.2.
|______________________________________________________________________|*/

namespace xqp {

/*____________________________________________________
|                                                     |
|  Read/write lock static initializer
|_____________________________________________________|*/
#define RWL_INITIALIZER \
	{	PTHREAD_MUTEX_INITIALIZER,	\
		PTHREAD_COND_INITIALIZER, 	\
		PTHREAD_COND_INITIALIZER,		\
		RWLOCK_VALID,								\
		0, 0, 0, 0 }

#define RWLOCK_VALID		0xfab
#define RWLOCK_INVALID	0xbad

/*____________________________________________________
|                                                     |
|  Struct describing a read/write lock.
|_____________________________________________________|*/
class rwlock
{
protected:
	pthread_mutex_t		mutex;
	pthread_cond_t		read;				// wait for read
	pthread_cond_t		write;			// wait for write
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
	/*_____________________________________________________________
	|                                                              |
	|  Handle cleanup when the read/write lock condition
	|  variable wait is cancelled.
	|______________________________________________________________|*/
	static void read_cleanup(void* arg);
	static void write_cleanup(void* arg);

public:
	/*_____________________________________________________________
	|                                                              |
	|  Lock a read/write lock for read access.
	|______________________________________________________________|*/
	int readlock();

	/*_____________________________________________________________
	|                                                              |
	|  Try to lock a read/write lock for read access, but
	|  don't block if unavailable.
	|______________________________________________________________|*/
	int readtrylock();

	/*_____________________________________________________________
	|                                                              |
	|  Unlock a read/write lock from read access.
	|______________________________________________________________|*/
	int readunlock();

	/*_____________________________________________________________
	|                                                              |
	|  Lock a read/write lock for write access.
	|______________________________________________________________|*/
	int writelock();

	/*_____________________________________________________________
	|                                                              |
	|  Try to lock a read/write lock for write access, but
	|  don't block if unavailable.
	|______________________________________________________________|*/
	int writetrylock();

	/*_____________________________________________________________
	|                                                              |
	|  Unlock a read/write lock from write access.
	|______________________________________________________________|*/
	int writeunlock();

};
		

}	/* namespace xqp */
#endif	/* XQP_RWLOCK_H */
