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
#ifndef ZORBA_SCHEMA_VALIDATE
#define ZORBA_SCHEMA_VALIDATE

#ifndef ZORBA_NO_XMLSCHEMA


#include "common/shared_types.h"

#include "compiler/parser/parse_constants.h"

#include "store/api/item.h"


namespace zorba
{
class QueryLoc;
class static_context;
class TypeManager;
class EventSchemaValidator;


class Validator
{
 public:
  static bool effectiveValidationValue (
        store::Item_t& result,
        const store::Item_t& sourceNode,
        const store::Item_t& typeName,
        TypeManager* typeManager,
        ParseConstants::validation_mode_t validationMode,
        static_context* sctx,
        const QueryLoc& loc); 

  static void processTextValue (
        static_context* sctx,
        TypeManager* typeManager, 
        store::NsBindings& bindings,
        const store::Item_t& typeQName,
        zstring& textValue, 
        std::vector<store::Item_t>& resultList);

private:
  static bool realValidationValue (
        store::Item_t& result,
        const store::Item_t& sourceNode,
        const store::Item_t& typeName,
        TypeManager* typeManager,
        ParseConstants::validation_mode_t validationMode,
        static_context* sctx,
        const QueryLoc& loc);

  static void processChildren (
        static_context* sctx,
        TypeManager* typeManager,
        EventSchemaValidator& schemaValidator,
        store::Item* parent,
        store::Iterator_t children);

  static store::Item_t processElement (
        static_context* sctx,
        TypeManager* typeManager, 
        EventSchemaValidator& schemaValidator,
        store::Item* parent,
        const store::Item_t& element);
  
  static void validateAttributes (
        EventSchemaValidator& schemaValidator,
        store::Iterator_t attributes);

  static void processAttributes(
        static_context* sctx,
        TypeManager* typeManager,
        EventSchemaValidator& schemaValidator,
        store::Item* parent,
        store::Iterator_t attributes);

  static void processNamespaces (
        EventSchemaValidator& schemaValidator,
        const store::Item_t& item);
};

} // namespace zorba


#endif // ZORBA_NO_XMLSCHEMA

#endif /*ZORBA_SCHEMA_UTILS_H_*/

/*
 * Local variables:
 * mode: c++
 * End:
 */
