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
#ifndef ZORBA_RUNTIME_APPLY_UPDATES
#define ZORBA_RUNTIME_APPLY_UPDATES

#include "runtime/base/unarybase.h"


namespace zorba 
{

/*******************************************************************************

********************************************************************************/
UNARY_ITER(ApplyIterator);

void
apply_updates(
      CompilerCB* ccb,
      dynamic_context* gdctx,
      static_context* sctx,
      store::PUL* pul,
      const QueryLoc& loc);



}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
