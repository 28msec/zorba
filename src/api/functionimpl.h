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
class DiagnosticHandler;


class FunctionImpl : public Function
{
protected:
  function          * theFunction;
  DiagnosticHandler * theDiagnosticHandler;

 public:
  virtual ~FunctionImpl() {}

  FunctionImpl(function* aFunction, DiagnosticHandler* aDiagnosticHandler) 
    :
    theFunction(aFunction),
    theDiagnosticHandler(aDiagnosticHandler)
  {
  }

  bool isSequential() const;

  bool isUpdating() const;

  bool isPrivate() const;

  bool isDeterministic() const;

  void getAnnotations(std::vector<Annotation_t>& annotations) const;

  Item getQName() const;

  String getURI() const;

  String getLocalName() const;

  size_t getArity() const;

  bool isVariadic() const;

  bool isExternal() const;

  bool isXQuery() const;

  bool isBuiltin() const;
};

} /* namespace zorba */
#endif

/* vim:set et sw=2 ts=2: */
