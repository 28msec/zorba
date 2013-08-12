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
#ifndef ZORBA_FUNCTION_LIBRARY_H
#define ZORBA_FUNCTION_LIBRARY_H

#include "functions/function_consts.h"


namespace zorba 
{

class static_context;
class function;


class BuiltinFunctionLibrary 
{
  friend class GlobalEnvironment;

public:
  function  ** theFunctions;

public:
  BuiltinFunctionLibrary();

  ~BuiltinFunctionLibrary();

  void populate(static_context* sctx);

  function* getFunction(FunctionConsts::FunctionKind kind)
  {
    return theFunctions[kind];
  }

  void addFunction(FunctionConsts::FunctionKind kind, function* f)
  {
    theFunctions[kind] = f;
  }
};



#define BUILTIN_FUNC(func_code) \
GENV_FUNC_LIB->getFunction(FunctionConsts::func_code)


}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
