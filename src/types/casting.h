/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author David Graf (david.graf@28msec.com)
 * @file types/casting.h
 *
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
class GenericCast
{
  typedef store::Item_t (*CastFunc)(store::Item*, store::ItemFactory*);
  typedef store::Item_t (*DownCastFunc)(
                            const store::Item*, 
                            TypeConstants::atomic_type_code_t aTargetAtomicType,
                            RootTypeManager& aTS,
                            store::ItemFactory*
                        ); 
private:
  static const int theMapping[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];
  static const CastFunc theCastMatrix[23][23];
  static const DownCastFunc theDownCastMatrix[23];

  GenericCast() {}
    
public:
  ~GenericCast() {}
			
  static GenericCast* instance();

public:

  /**
   * Executes the casting of the passed item. If the passed item has the same type or a subtype
   * of the passed targetType, the passed item is directly returned.
   * @param aItem 
   * @param aTargetType
   * @return resutling item
   */
  store::Item_t cast (store::Item* aItem, const xqtref_t& aTargetType) const;

  /**
   * Executes the string casting of the passed string to an item of the passed target type.
   * @param aStr 
   * @param aTargetType
   * @return resutling item
   */
  store::Item_t cast (const xqpString& aStr, const xqtref_t& aTargetType) const;

  /**
   * Casts the passed string to xs:QName if possible.
   * @param str a pointer to a heap-allocated xqpStringStore
   * @param isCast true if a cast is requested, false if this is a castable inquiry
   * @return an item if the promotion is possible, otherwise raises an error
   */
  store::Item_t castToQName(
        xqpStringStore_t aStr,
        bool isCast,
        bool isExplicit,
        namespace_context* aNCtx = 0) const;

  bool castableToNCName(const xqpStringStore* str) const;

  /**
   * Checks if the passed item would be castable to the passed target type.
   * @param aItem
   * @param aTargetType
   * @return true if castable, else false
   */
  bool isCastable( store::Item_t aItem, const xqtref_t& aTargetType ) const; 

  /**
   * Checks if the passed string is castable to the passed target type.
   * @param aStr
   * @param aTargetType
   * @return true if castable, else false
   */
  bool isCastable( const xqpString& aStr, const xqtref_t& aTargetType) const;

  /**
   * Promotes the passed item to the passed target type.
   * @param aItem
   * @param aTargetType
   * @return 0 if promotion is not possible else promoted item
   *         if the item type is a subtype of the target type, then
   *         the passed item is returned
   */
  store::Item_t promote(store::Item_t aItem, const xqtref_t& aTargetType) const;

public:
  static bool isLetter(uint32_t cp);
  static bool isBaseChar(uint32_t cp);
  static bool isIdeographic(uint32_t cp);
  static bool isDigit(uint32_t cp);
  static bool isCombiningChar(uint32_t cp);
  static bool isExtender(uint32_t cp);

private:
  /**
   * Tries to cast the passed string to an Item of the passed target type.
   * @param aString 
   * @param aTargateType
   * @return Created Item or 0 if the parsing was not possible
   */
  store::Item_t stringSimpleCast(
        const store::Item* aSourceItem,
        const xqtref_t& aSourceType,
        const xqtref_t& aTargetType) const;

  store::Item_t stringSimpleCastBuiltIn(
    const store::Item* aSourceItem,
    const xqtref_t&    aSourceType, 
    const xqtref_t& aTargetType) const;

  store::Item_t castToBoolean(
        const store::Item* aSourceItem,
        const xqtref_t& aSourceType) const;
  
}; /* class GenericCast */

} /* namespace zorba */

#endif	/* ZORBA_CASTING_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
