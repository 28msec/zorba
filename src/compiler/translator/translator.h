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
#ifndef ZORBA_COMPILER_TRANSLATOR
#define ZORBA_COMPILER_TRANSLATOR


#include "common/shared_types.h"

namespace zorba
{

expr* translate (const parsenode& ast, CompilerCB* ccb);


// Publicly avialable translation and normalization services, used currently
// by the higher order functions at runtime.
class Translator 
{
public:
  // Given a QName and the arity of a function, it will generate a function 
  // item expression that can be used in dynamic function calls to invoke 
  // the requested function. If the errIfContextDependent is set to true,
  // then the returned function item will invoke error(FOFL0001) if the 
  // requested function is context dependent.
  static expr* translate_literal_function(store::Item_t& qname, unsigned int arity, CompilerCB* ccb, const QueryLoc& loc, bool errIfContextDependent);
  
};

}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
