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
#include <iostream>
#include "zorbautils/thread.h"

namespace zorba {

#ifdef ZORBA_HAVE_PTHREAD_H
Thread::Thread( void *aFunction(void *anArgs), void *anArg )
#else
Thread::Thread( DWORD ( WINAPI *aFunction ) ( void *anArg ), void *anArg )
#endif
{
#ifdef ZORBA_HAVE_PTHREAD_H
    pthread_mutex_init( &theMutex, 0 );
    pthread_cond_init( &theCV, 0 );
    if ( pthread_create( &theThread, 0, aFunction, anArg ) != 0 )
#else
    if ( (theThread = CreateThread( 0, 0, aFunction, anArg, 0, 0 ) ) == 0 )
#endif
    {
      //TODO: zorba error
    }
}
    
Thread::~Thread()    
{
#ifdef ZORBA_HAVE_PTHREAD_H
  pthread_cancel( theThread );
  pthread_mutex_destroy( &theMutex );
  pthread_cond_destroy( &theCV );
#else
  CloseHandle( theThread );
#endif
}

void Thread::suspend()
{
#ifdef ZORBA_HAVE_PTHREAD_H
  pthread_mutex_lock( &theMutex );
  pthread_cond_wait( &theCV, &theMutex ); 
  pthread_mutex_unlock( &theMutex );
#else
	SuspendThread( theThread );
#endif	
}

void Thread::resume()
{
#ifdef ZORBA_HAVE_PTHREAD_H
  pthread_mutex_lock( &theMutex );
  pthread_cond_signal( &theCV );
  pthread_mutex_unlock( &theMutex );
#else
  ResumeThread( theThread );
#endif
}

void Thread::join()
{
#ifdef ZORBA_HAVE_PTHREAD_H
  pthread_join( theThread, 0 );
#else
  WaitForSingleObject( theThread, INFINITE );
#endif
}
}//end of namespace

