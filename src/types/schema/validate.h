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
#ifndef ZORBA_SCHEMA_VALIDATE
#define ZORBA_SCHEMA_VALIDATE

#ifndef ZORBA_NO_XMLSCHEMA


#include "common/shared_types.h"

#include "compiler/parser/parse_constants.h"

#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/root_typemanager.h"
#include "system/globalenv.h"
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
  static bool effectiveValidationValue(
        store::Item_t& result,
        const store::Item_t& sourceNode,
        const store::Item_t& typeName,
        TypeManager* typeManager,
        ParseConstants::validation_mode_t validationMode,
        const static_context* sctx,
        const QueryLoc& loc); 

  static void processTextValue(
        const static_context* sctx,
        TypeManager* typeManager, 
        store::NsBindings& bindings,
        const store::Item_t& typeQName,
        zstring& textValue, 
        std::vector<store::Item_t>& resultList,
        const QueryLoc& loc);
  
  /**
   - haveValue : True if the element has a typed value.
   The only case when an element node N does not have a typed value is when the type
   of N is a complex type with element-only content. So, this flag is a function 
   of the element's type only; not of the actual content of an element instance.
   */
  static bool typeHasValue(xqtref_t t)
  {
    return (t->content_kind() == XQType::MIXED_CONTENT_KIND ||
            t->content_kind() == XQType::SIMPLE_CONTENT_KIND ||
            t->content_kind() == XQType::EMPTY_CONTENT_KIND);
  }
  
  /**
   - haveTypedValue : True if the element has a non-empty typed value and the type of that
   value is something other than untypedAtomic. This can happen only if the type of the
   element node is a simple type or a complex type with simple content (i.e., the element
   has no sub-elements). Again this flag is a function of the element's type only; not of
   the actual content of an element instance.
   */
  static bool typeHasTypedValue(
      const TypeManager* tm, 
      const xqtref_t& t,
      const QueryLoc& loc)
  {
    return (t->content_kind() == XQType::SIMPLE_CONTENT_KIND &&
            !TypeOps::is_equal(tm, *t, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE, loc));
  }
  
  /**
   - haveEmptyValue : True if the typed value of the element is the empty sequence.
   This can happen only if "the element has a complex type with empty content"
   (quote from the spec). This flag also is a function of the element's type only.
   */
  static bool typeHasEmptyValue(xqtref_t t)
  {
    return t->content_kind() == XQType::EMPTY_CONTENT_KIND;
  }

private:
  static bool realValidationValue(
        store::Item_t& result,
        const store::Item_t& sourceNode,
        const store::Item_t& typeName,
        TypeManager* typeManager,
        ParseConstants::validation_mode_t validationMode,
        const static_context* sctx,
        const QueryLoc& loc);

  static void processChildren(
        const static_context* sctx,
        TypeManager* typeManager,
        EventSchemaValidator& schemaValidator,
        store::Item* parent,
        store::Iterator_t children,
        const QueryLoc& loc);

  static store::Item_t processElement(
        const static_context* sctx,
        TypeManager* typeManager, 
        EventSchemaValidator& schemaValidator,
        store::Item* parent,
        const store::Item_t& element,
        const QueryLoc& loc);
  
  static void validateAttributes(
        EventSchemaValidator& schemaValidator,
        store::Iterator_t attributes);

  static void processAttributes(
        const static_context* sctx,
        TypeManager* typeManager,
        EventSchemaValidator& schemaValidator,
        store::Item* parent,
        store::Iterator_t attributes,
        const QueryLoc& loc);

  static void processNamespaces(
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
/* vim:set et sw=2 ts=2: */
