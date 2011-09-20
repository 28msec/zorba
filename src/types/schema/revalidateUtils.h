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
#ifndef ZORBA_TYPES_SCHEMA_REVALIDATION
#define ZORBA_TYPES_SCHEMA_REVALIDATION

#include <set>

#include "common/shared_types.h"

#include "store/api/validator.h"
#include "types/schema/EventSchemaValidator.h"
#include "types/schema/StrX.h"

namespace zorba
{
//bool typeHasValue(xqtref_t t);
//bool typeHasTypedValue(xqtref_t t);
//bool typeHasEmptyValue(xqtref_t t);


class QueryLoc;
class static_context;


/***************************************************************************//**
  An implementation of the abstract store::Validator class, which provides a
  callback method for the store to call in order to preform revalidation after
  applying a PUL. 
********************************************************************************/
class SchemaValidatorImpl : public store::SchemaValidator
{
protected:
  const QueryLoc & theLoc;
  static_context * theSctx;

public:
  SchemaValidatorImpl(const QueryLoc& loc, static_context* sctx) 
    :
    theLoc(loc),
    theSctx(sctx)
  {
  }

#ifndef ZORBA_NO_XMLSCHEMA
  /**
   * Validates entire documents. nodes is a set of root documents or elements.
   * An error is thrown in case of invalid content.
   */
  void validate(
      const std::set<store::Item*>& nodes,
      store::PUL& pul);
  
  bool isPossibleSimpleContentRevalidation(store::Item *typeQName);
  
  void validateSimpleContent(
      store::Item *typeQName, 
      zstring newValue, 
      std::vector<store::Item_t>& resultList);
  
#else
  void validate(
      const std::set<store::Item*>& nodes,
      store::PUL& pul) 
  {
  }

  bool isPossibleSimpleContentRevalidation(store::Item *typeQName)
  { 
    return false;
  }

  void validateSimpleContent(
      store::Item *typeQName, 
      zstring newValue, 
      std::vector<store::Item_t>& resultList)
  {
  }
#endif //ZORBA_NO_XMLSCHEMA
  
private:
#ifndef ZORBA_NO_XMLSCHEMA
  void validateAfterUpdate(
      store::Item* item, 
      zorba::store::PUL* pul,
      const QueryLoc& loc);

  void processElement(
      store::PUL* pul,
      TypeManager* typeManager,
      EventSchemaValidator& schemaValidator,
      store::Item_t element,
      const QueryLoc& loc);
  
  void validateAttributes(
      EventSchemaValidator& schemaValidator,
      store::Iterator_t attributes);
  
  void processAttributes(
      store::PUL* pul,
      namespace_context& nsCtx,
      TypeManager* typeManager,
      EventSchemaValidator& schemaValidator,
      store::Item* parent,
      store::Iterator_t attributes,
      const QueryLoc& loc);
  
  int processChildren(
      store::PUL* pul,
      namespace_context& nsCtx,
      TypeManager* typeManager,
      EventSchemaValidator& schemaValidator,
      store::Iterator_t children,
      std::vector<store::Item_t>& typedValues,
      const QueryLoc& loc);
  
  void processNamespaces(
      EventSchemaValidator& schemaValidator, 
      const store::Item *item);
  
  void processTextValue(
      store::PUL* pul,
      TypeManager* typeManager,
      namespace_context &nsCtx,
      store::Item_t typeQName,
      zstring& textValue,
      store::Item_t& originalChild,
      std::vector<store::Item_t>& resultList,
      const QueryLoc& loc);

  store::Item_t findAttributeItem(
      const store::Item *parent, 
      store::Item_t &attQName);

  bool isPossibleSimpleContentRevalImpl(xqtref_t schemaType);

#endif //ifndef ZORBA_NO_XMLSCHEMA

};


}

#endif //ifndef ZORBA_TYPES_SCHEMA_REVALIDATION

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
