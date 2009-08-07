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
#ifndef ZORBA_CASTING_H
#define ZORBA_CASTING_H

#include "common/shared_types.h"
#include "types/root_typemanager.h"

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
                            xqpStringStore_t& strval,
                            store::ItemFactory*, 
                            namespace_context *nsCtx,
                            const ErrorInfo& aErrorInfo
                        );
  typedef bool (*DownCastFunc)(
                            store::Item_t&,
                            const store::Item*, 
                            RootTypeManager& aTS,
                            TypeConstants::atomic_type_code_t aTargetAtomicType,
                            store::ItemFactory*,
                            const ErrorInfo& aErrorInfo
                        ); 
private:
  static const int          theMapping[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];
  static const CastFunc     theCastMatrix[23][23];
  static const DownCastFunc theDownCastMatrix[23];

  GenericCast() {}
    
public:
  ~GenericCast() {}
			
  static GenericCast* instance();

public:
  
  /**
   * Executes the string casting of the passed string to an item of the passed
   * target type.
   */
  static bool castToAtomic (
        store::Item_t& result,
        xqpStringStore_t& aStr, 
        const XQType* aTargetType,
        namespace_context* aNCtx = 0);
  /**
   * Executes the casting of the passed item. If the passed item has the same
   * type or a subtype of the passed targetType, the passed item is directly
   * returned.
   */
  static bool castToAtomic (
        store::Item_t& result,
        store::Item_t& aItem, 
        const XQType* aTargetType,
        const TypeManager& tm, 
        namespace_context* aNCtx = 0);

  static bool castToSimple (
        xqpStringStore_t& aStr, 
        const xqtref_t& aTargetType,
        std::vector<store::Item_t>& aResultList);

  /**
   * Casts the passed string to xs:QName if possible.
   */
  static bool castToQName(
        store::Item_t& result,
        xqpStringStore_t& aStr,
        namespace_context* aNCtx = 0);

  bool castableToNCName(const xqpStringStore* str) const;

  bool castableToNormalizedString(const xqpStringStore* str) const;

  bool castableToToken(const xqpStringStore* str) const;

  bool castableToLanguage(const xqpStringStore* str) const;

  static bool castableToNMToken(const xqpStringStore* str);

  static bool castableToName(const xqpStringStore* str);

  /**
   * Checks if the passed item would be castable to the passed target type.
   * @param aItem
   * @param aTargetType
   * @return true if castable, else false
   */
  static bool isCastable(
        const store::Item_t& aItem,
        const XQType* aTargetType,
        const TypeManager& tm); 

  /**
   * Checks if the passed string is castable to the passed target type.
   * @param aStr
   * @param aTargetType
   * @return true if castable, else false
   */
  static bool isCastable(xqpStringStore_t& aStr, const XQType* aTargetType);

  /**
   * Promotes the passed item to the passed target type.
   * @param aItem
   * @param aTargetType
   * @return 0 if promotion is not possible else promoted item
   *         if the item type is a subtype of the target type, then
   *         the passed item is returned
   */
  static bool promote(
        store::Item_t& result,
        store::Item_t& aItem,
        const XQType* aTargetType,
        const TypeManager& tm);
};

} /* namespace zorba */

#endif	/* ZORBA_CASTING_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
