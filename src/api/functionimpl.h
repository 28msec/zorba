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
#ifndef ZORBA_FUNCTION_IMPL_H
#define ZORBA_FUNCTION_IMPL_H

#include <zorba/function.h>

namespace zorba {

class function;
class ErrorHandler;


class FunctionImpl : public Function
{
protected:
  function     * theFunction;
  ErrorHandler * theErrorHandler;

 public:
  virtual ~FunctionImpl() {}

  FunctionImpl(function* aFunction, ErrorHandler* aErrorHandler) 
    :
    theFunction(aFunction),
    theErrorHandler(aErrorHandler)
  {
  }

  virtual bool isUpdating() const;

  virtual bool isPrivate() const;

  virtual bool isDeterministic() const;

  virtual bool isSequential() const;

  virtual bool requiresDynamicContext() const;

  virtual Item getFunctionName() const;

  virtual size_t getArity() const;

  bool isVariadic() const;
};

} /* namespace zorba */
#endif

