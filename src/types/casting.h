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
#ifndef ZORBA_TYPES_CASTING_H
#define ZORBA_TYPES_CASTING_H

#include "common/shared_types.h"
#include "types/root_typemanager.h"

#include <zorba/store_consts.h>


namespace zorba
{
	
/**
 * Class which implements casting of items.
 */
struct ErrorInfo;

class GenericCast
{

  typedef bool (*CastFunc)(store::Item_t&,
                           const store::Item*,
                           zstring& strval,
                           store::ItemFactory*, 
                           const namespace_context* nsCtx,
                           const ErrorInfo& errorInfo,
                           bool throw_on_error);

  typedef bool (*DownCastFunc)(
                            store::Item_t&,
                            const store::Item*, 
                            store::SchemaTypeCode targetAtomicType,
                            store::ItemFactory*,
                            const ErrorInfo& errorInfo,
                            bool throw_on_error);
 
private:
  static const int          theMapping[store::XS_LAST];
  static const CastFunc     theCastMatrix[26][26];
  static const DownCastFunc theDownCastMatrix[26];

  GenericCast() {}
    
public:
  ~GenericCast() {}
			
  static GenericCast* instance();

public:
  
  /**
   * Promotes the passed item to the passed target type.
   * @param item
   * @param targetType
   * @return 0 if promotion is not possible else promoted item
   *         if the item type is a subtype of the target type, then
   *         the passed item is returned
   */
  static bool promote(
        store::Item_t& result,
        store::Item_t& item,
        const XQType* targetType,
        const namespace_context* nsCtx,
        const TypeManager* tm,
        const QueryLoc& loc);

  static bool promote(
        store::Item_t& result,
        store::Item_t& item,
        store::SchemaTypeCode targetType,
        const namespace_context* nsCtx,
        const TypeManager* tm,
        const QueryLoc& loc);

  static bool castToSimple(
        store::Item_t& item, 
        const xqtref_t& targetType,
        const namespace_context* nsCtx,
        std::vector<store::Item_t>& resultList,
        TypeManager* tm,
        const QueryLoc& loc);

  static bool castStringToAtomic(
        store::Item_t& result,
        zstring& stringValue, 
        const XQType* targetType,
        const TypeManager* tm,
        const namespace_context* nsCtx,
        const QueryLoc& loc,
        bool throw_on_error = true);

  static bool castStringToBuiltinAtomic(
        store::Item_t& result,
        zstring& stringValue, 
        const XQType* targetType,
        const TypeManager* tm,
        const namespace_context* nsCtx,
        const QueryLoc& loc,
        bool throw_on_error = true);

  static bool castToAtomic(
        store::Item_t& result,
        store::Item_t& item, 
        const XQType* targetType,
        const TypeManager* tm, 
        const namespace_context* nsCtx,
        const QueryLoc& loc,
        bool throw_on_error = true);

  static bool castToBuiltinAtomic(
        store::Item_t& result,
        store::Item_t& item, 
        store::SchemaTypeCode targetType,
        const namespace_context* nameCtx,
        const QueryLoc& loc,
        bool throw_on_error = true);

  static bool castToQName(
        store::Item_t& result,
        const store::Item_t& item,
        const namespace_context* nsCtx,
        bool attrName,
        const TypeManager* tm,
        const QueryLoc& loc);

  static bool castableToNCName(const zstring& str);

  static bool castableToNormalizedString(const zstring& str);

  static bool castableToToken(const zstring& str);

  static bool castableToLanguage(const zstring& str);

  static bool castableToNMToken(const zstring& str);

  static bool castableToName(const zstring& str);

  static bool isCastable(
      const store::Item_t& item,
      const XQType* targetType,
      TypeManager* tm,
      const namespace_context* nsCtx);

  static bool isCastable(
      const zstring& stringValue,
      const XQType* targetType,
      TypeManager* tm,
      const namespace_context* nsCtx);

  static void splitToAtomicTextValues(
    const zstring& textValue,
    std::vector<zstring>& atomicTextValues);

protected:
  static bool isCastableUserSimpleTypes(
      const zstring& textValue,
      const XQType* targetType,
      TypeManager* tm,
      const namespace_context* nsCtx);

  static bool isCastableUserAtomicTypes(
      const zstring& textValue,
      const UserDefinedXQType* targetType,
      TypeManager* tm,
      const namespace_context* nsCtx);

  static bool isCastableUserListTypes(
      const zstring& textValue,
      const UserDefinedXQType* targetType,
      TypeManager* tm,
      const namespace_context* nsCtx);

  static bool isCastableUserUnionTypes(
      const zstring& textValue,
      const UserDefinedXQType* targetType,
      TypeManager* tm,
      const namespace_context* nsCtx);
};

} /* namespace zorba */

#endif	/* ZORBA_CASTING_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
