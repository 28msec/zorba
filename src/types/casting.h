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

#include "store/api/xs_type_codes.h"


namespace zorba
{
	
/**
 * Class which implements casting of items.
 */
struct ErrorInfo;

class GenericCast
{

  typedef bool (*CastFunc)(
                            store::Item_t&,
                            const store::Item*,
                            zstring& strval,
                            store::ItemFactory*, 
                            namespace_context *nsCtx,
                            const ErrorInfo& aErrorInfo);

  typedef bool (*DownCastFunc)(
                            store::Item_t&,
                            const store::Item*, 
                            store::SchemaTypeCode aTargetAtomicType,
                            store::ItemFactory*,
                            const ErrorInfo& aErrorInfo);
 
private:
  static const int          theMapping[store::XS_LAST];
  static const CastFunc     theCastMatrix[24][24];
  static const DownCastFunc theDownCastMatrix[24];

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
        const TypeManager* tm,
        const QueryLoc& loc);

  static bool promote(
        store::Item_t& result,
        store::Item_t& item,
        store::SchemaTypeCode targetType,
        const TypeManager* tm,
        const QueryLoc& loc);

  /**
   * Executes the string casting of the passed string to an item of the passed
   * target type.
   */
  static bool castToAtomic(
        store::Item_t& result,
        zstring& aStr, 
        const XQType* aTargetType,
        const TypeManager* tm,
        namespace_context* aNCtx,
        const QueryLoc& loc);
  /**
   * Executes the casting of the passed item. If the passed item has the same
   * type or a subtype of the passed targetType, the passed item is directly
   * returned.
   */
  static bool castToAtomic(
        store::Item_t& result,
        store::Item_t& item, 
        const XQType* targetType,
        const TypeManager* tm, 
        namespace_context* nameCtx,
        const QueryLoc& loc);

  /**
   * Executes the casting of the passed item. If the passed item has the same
   * type or a subtype of the passed targetType, the passed item is directly
   * returned.
   */
  static bool castToAtomic(
        store::Item_t& result,
        store::Item_t& item, 
        store::SchemaTypeCode targetType,
        const TypeManager* tm, 
        namespace_context* nameCtx,
        const QueryLoc& loc);

  static bool castToSimple(
        zstring& aStr, 
        const xqtref_t& aTargetType,
        std::vector<store::Item_t>& aResultList,
        const TypeManager* tm,
        const QueryLoc& loc);

  static bool castToQName(
        store::Item_t& result,
        const store::Item_t& item,
        namespace_context* aNCtx,
        bool attrName,
        const TypeManager* tm,
        const QueryLoc& loc);

  static bool castableToNCName(const zstring& str);

  static bool castableToNormalizedString(const zstring& str);

  static bool castableToToken(const zstring& str);

  static bool castableToLanguage(const zstring& str);

  static bool castableToNMToken(const zstring& str);

  static bool castableToName(const zstring& str);

  /**
   * Checks if the passed item would be castable to the passed target type.
   * @param aItem
   * @param aTargetType
   * @return true if castable, else false
   */
  static bool isCastable(
        const store::Item_t& aItem,
        const XQType* aTargetType,
        const TypeManager* tm); 

  /**
   * Checks if the passed string is castable to the passed target type.
   * @param aStr
   * @param aTargetType
   * @return true if castable, else false
   */
  static bool isCastable(
        const zstring& aStr,
        const XQType* aTargetType,
        const TypeManager* tm);
};

} /* namespace zorba */

#endif	/* ZORBA_CASTING_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
