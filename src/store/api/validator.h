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
#ifndef ZORBA_STORE_API_VALIDATOR
#define ZORBA_STORE_API_VALIDATOR

#include <set>

#include "store/api/shared_types.h"


namespace zorba 
{

namespace store 
{


/***************************************************************************//**
  An abstract class that provides a callback method for the store to call in
  order to preform revalidation after applying a PUL. The query processor must
  provide a concrete implmentation of this class.
********************************************************************************/
class SchemaValidator
{
public:
  virtual ~SchemaValidator() {}

  virtual void validate(const std::set<Item*>& nodes, PUL& pul) = 0;
  
#ifndef ZORBA_NO_XMLSCHEMA
  virtual bool isPossibleSimpleContentRevalidation(store::Item *typeQName) = 0;
  
  virtual void validateSimpleContent(store::Item *typeQName, 
                             zstring newValue, 
                             std::vector<store::Item_t> &resultList) = 0;
#else
  virtual bool isPossibleSimpleContentRevalidation() { return false; }

  void validateSimpleContent(
      const xqtref_t& targetType, 
      zstring newValue, 
      std::vector<store::Item_t>& resultList)
  {
  }
#endif
};



}
}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
