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
#ifndef ZORBA_NONPURE_STATELESS_EXTERNAL_FUNCTION_H
#define ZORBA_NONPURE_STATELESS_EXTERNAL_FUNCTION_H

#include <zorba/config.h>
#include <vector>
#include <zorba/api_shared_types.h> 

#include <zorba/stateless_function.h>

namespace zorba 
{

class ZORBA_DLL_PUBLIC NonePureStatelessExternalFunction :
public StatelessExternalFunction
{
 public:
  virtual ~NonePureStatelessExternalFunction() {}

  virtual String
  getURI() const = 0;

  virtual String
  getLocalName() const = 0;

  virtual ItemSequence_t
  evaluate(const Arguments_t&,
           const StaticContext*,
           const DynamicContext*) const = 0;
  
  virtual bool
  isContextual() const { return true; }
};


} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
