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
#include "stdafx.h"

#include "timeout.h"

#include "runtime/base/plan_iterator.h"

#ifdef WIN32
#include <Windows.h>
#define sleep(n) Sleep(1000*n)
#else
#include <sys/time.h>
#include <limits.h>
#endif

namespace zorba 
{

StateWrapper::StateWrapper( PlanState& aState )
  :
  theState(aState)
{
}


void StateWrapper::doBreak()
{
  theState.theHasToQuit = true;
}


Timeout::Timeout(unsigned long aTimeout, const StateWrapper& aWrapper)
  :
  theTimeout(aTimeout),
  theWrapper(aWrapper)
{
}


void Timeout::run()
{
  suspend(1000*theTimeout);

  theWrapper.doBreak();
}


void Timeout::finish()
{
}


} //namespace zorba
/* vim:set et sw=2 ts=2: */
