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

#ifndef ZORBA_STORE_ATOMIC_ITEMS_H
#define ZORBA_STORE_ATOMIC_ITEMS_H

#include <cassert>
#include <iostream>
#include <vector>
#include <cstring>

#include <zorba/config.h>
#include <zorba/streams.h>
#ifndef ZORBA_NO_FULL_TEXT
#include <zorba/tokenizer.h>
#endif /* ZORBA_NO_FULL_TEXT */

#include "store/api/item.h"
#include "store/api/item_handle.h"
#include <zorba/store_consts.h>
#include "store_defs.h"
#include "shared_types.h"
#include "tree_id.h"

#ifndef ZORBA_NO_FULL_TEXT
#include "naive_ft_token_iterator.h"
#endif /* ZORBA_NO_FULL_TEXT */

#include "zorbatypes/datetime.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/float.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/schema_types.h"

#include "diagnostics/xquery_diagnostics.h"
#include "ordpath.h"


namespace zorba
{

namespace simplestore
{


enum AnyUriTypeCode
{
  NON_SPECIALIZED_ANY_URI,
  STRUCTURAL_INFORMATION_ANY_URI
};

class AtomicItemTokenizerCallback;

class QNameItem;
typedef store::ItemHandle<QNameItem> QNameItem_t;


/******************************************************************************

*******************************************************************************/

class AtomicItem : public store::Item
{
protected:
  SYNC_CODE(mutable RCLock  theRCLock;)

public:
  AtomicItem(store::SchemaTypeCode t) : store::Item(ATOMIC)
  {
    theUnion.itemKind |= (t << 4);
  }

  virtual ~AtomicItem() {}

  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  virtual AnyUriTypeCode getAnyUriTypeCode() const;

  bool castToLong(store::Item_t& result) const;

  void coerceToDouble(store::Item_t& result, bool force, bool& lossy) const;
};


/*******************************************************************************
  class UserTypedAtomicItem
********************************************************************************/
class UserTypedAtomicItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  AtomicItem_t   theBaseItem;
  store::Item_t  theTypeName;

protected:
  UserTypedAtomicItem(store::Item_t& baseItem, store::Item_t& typeName)
    :
    AtomicItem(baseItem->getTypeCode())
  {
    theBaseItem.transfer(baseItem);
    theTypeName.transfer(typeName);
  }

public:
  size_t alloc_size() const;
  size_t dynamic_size() const;

  store::Item* getBaseItem() const;

  store::Item* getType() const { return theTypeName.getp(); }

  uint32_t hash(long tz = 0, const XQPCollator* c = 0) const
  {
    return theBaseItem->hash(tz, c);
  }

  bool equals(const store::Item* i, long tz = 0, const XQPCollator* c = 0) const
  {
    if (i->getBaseItem() == NULL)
      return theBaseItem->equals(i, tz, c);
    else
      return theBaseItem->equals(i->getBaseItem(), tz, c);
  }

  long compare(const store::Item* i, long tz = 0, const XQPCollator* c = 0) const
  {
    if (i->getBaseItem() == NULL)
      return theBaseItem->compare(i, tz, c);
    else
      return theBaseItem->compare(i->getBaseItem(), tz, c);
  }

  bool getEBV() const { return theBaseItem->getEBV(); }

  zstring getStringValue() const { return theBaseItem->getStringValue(); }

  void getStringValue2(zstring& val) const { theBaseItem->getStringValue2(val); }

  void appendStringValue(zstring& buf) const { theBaseItem->appendStringValue(buf); }

  const zstring& getString() const { return theBaseItem->getString(); }
  
  bool isEncoded() const { return theBaseItem->isEncoded(); }

  const char* getBase64BinaryValue(size_t& s) const
  {
    return theBaseItem->getBase64BinaryValue(s);
  }

  char const* getHexBinaryValue(size_t& s) const
  {
    return theBaseItem->getHexBinaryValue(s);
  }

  bool getBooleanValue() const { return theBaseItem->getBooleanValue(); }

  xs_double getDoubleValue() const { return theBaseItem->getDoubleValue(); }

  xs_float getFloatValue() const { return theBaseItem->getFloatValue(); }

  xs_decimal getDecimalValue() const { return theBaseItem->getDecimalValue(); }

  xs_integer getIntegerValue() const { return theBaseItem->getIntegerValue(); }

  xs_nonNegativeInteger getUnsignedIntegerValue() const { return theBaseItem->getUnsignedIntegerValue(); }

  xs_long getLongValue() const { return theBaseItem->getLongValue(); }

  xs_int getIntValue() const { return theBaseItem->getIntValue(); }

  xs_short getShortValue() const { return theBaseItem->getShortValue(); }

  xs_byte getByteValue() const { return theBaseItem->getByteValue(); }

  xs_unsignedLong getUnsignedLongValue() const { return theBaseItem->getUnsignedLongValue(); }

  xs_unsignedInt getUnsignedIntValue() const { return theBaseItem->getUnsignedIntValue(); }

  xs_unsignedShort getUnsignedShortValue() const { return theBaseItem->getUnsignedShortValue(); }

  xs_unsignedByte getUnsignedByteValue() const { return theBaseItem->getUnsignedByteValue(); }

  bool isNaN() const { return theBaseItem->isNaN(); }

  bool isPosOrNegInf() const { return theBaseItem->isPosOrNegInf(); }

  const xs_dateTime& getDateTimeValue() const
  {
    return theBaseItem->getDateTimeValue();
  }

  const xs_date& getDateValue() const
  {
    return theBaseItem->getDateValue();
  }

  const xs_time& getTimeValue() const
  {
    return theBaseItem->getTimeValue();
  }

  const xs_gYearMonth& getGYearMonthValue() const
  {
    return theBaseItem->getGYearMonthValue();
  }

  const xs_gYear& getGYearValue() const
  {
    return theBaseItem->getGYearValue();
  }

  const xs_gMonth& getGMonthValue() const
  {
    return theBaseItem->getGMonthValue();
  }

  const xs_gMonthDay& getGMonthDayValue() const
  {
    return theBaseItem->getGMonthDayValue();
  }

  const xs_gDay& getGDayValue() const
  {
    return theBaseItem->getGDayValue();
  }

  const xs_duration& getDurationValue() const
  {
    return theBaseItem->getDurationValue();
  }

  const xs_dayTimeDuration& getDayTimeDurationValue() const
  {
    return theBaseItem->getDayTimeDurationValue();
  }

  const xs_yearMonthDuration& getYearMonthDurationValue() const
  {
    return theBaseItem->getYearMonthDurationValue();
  }

  zstring show() const { return "UserTypedAtomicItem [" + theBaseItem->show() + "]"; }
};


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
class UntypedAtomicItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  zstring theValue;

protected:
  UntypedAtomicItem(store::SchemaTypeCode t, zstring& value)
    :
    AtomicItem(t)
  {
    theValue.take(value);
  }

  UntypedAtomicItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  bool castToUri(store::Item_t& result) const;

  bool castToString(store::Item_t& result) const;

  bool castToDateTime(store::Item_t& result) const;

  bool castToDate(store::Item_t& result) const;

  bool castToTime(store::Item_t& result) const;

  bool castToGYear(store::Item_t& result) const;

  bool castToGYearMonth(store::Item_t& result) const;

  bool castToGMonthDay(store::Item_t& result) const;

  bool castToGMonth(store::Item_t& result) const;

  bool castToGDay(store::Item_t& result) const;

  bool castToDuration(store::Item_t& result) const;

  bool castToDouble(store::Item_t& result) const;

  bool castToDecimal(store::Item_t& result) const;

  bool castToInteger(store::Item_t& result) const;

  bool castToHexBinary(store::Item_t& result) const;

  bool castToBase64Binary(store::Item_t& result) const;

  bool castToBoolean(store::Item_t& result) const;

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  size_t alloc_size() const;
  size_t dynamic_size() const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const;

  long compare(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const;

  bool getEBV() const;

  zstring getStringValue() const { return theValue; }

  void getStringValue2(zstring& val) const { val = theValue; }

  void appendStringValue(zstring& buf) const { buf += theValue; }

  const zstring& getString() const { return theValue; }

  zstring show() const;
};


/*******************************************************************************
  Instances of this class can be classified into two categories:
  - QNames in the pool. There can be only one QName in the pool with a given
    namespace, prefix and local name.
  - QNames that are not in the pool. The user owns them and is responsible
    for their destruction (which can be realized with reference-counting
    pointers). The ternary constructors construct such QNames.
  
  Normalized QNames are QNames without a prefix and that are in the pool. There
  is only one normalized QName with a given namespace and local name, so that
  direct pointer comparison can be used to compare them.
  
  Each QName points to its associated normalized QName (same namespace and 
  prefix) which provides an efficient way of comparing two QNames.

  Pointer comparison on normalized QNames is equivalent to using the equals() 
  method. For example, a pointer to the normalized QName can be used as a key.

  A newly constructed instance of this class can be initialized as a normalized
  QName (always in the pool), as an unnormalized QName in the pool or as an
  unnormalized QName not in the pool. It can also be invalidated and initialized
  again.
*******************************************************************************/
class QNameItem : public AtomicItem
{
  // The QName pool is the only class authorized to edit namespace/prefix/local
  // name.
  friend class QNamePool;

private:
  zstring           theNamespace;
  zstring           thePrefix;
  zstring           theLocal;

  // Points to the corresponding normalized QName in the pool (pool owns this
  // pointer).
  const QNameItem * theNormalizedQName;
  
  bool              theIsInPool;

  // Used by the pool for managing the cache.
  uint16_t          thePosition;
  uint16_t          theNextFree;
  uint16_t          thePrevFree;

public:
  virtual ~QNameItem() {}

  size_t alloc_size() const;
  size_t dynamic_size() const;

  // zorba::store::Item interface.

  bool equals(const store::Item* i, long tz = 0, const XQPCollator* c = 0) const;

  uint32_t hash(long tz = 0, const XQPCollator* c = 0) const;

  store::Item* getType() const;
    
  bool getEBV() const;
    
  const zstring& getLocalName() const { return theLocal; }
  
  const zstring& getNamespace() const { return theNamespace; }

  const zstring& getPrefix() const { return thePrefix; }
    
  zstring getStringValue() const;
  
  void getStringValue2(zstring& val) const;
  
  void appendStringValue(zstring& buf) const;

  
  // Class-specific extensions.

  const QNameItem* getNormalized() const { return theNormalizedQName; }
  
  const zstring& getLocalName2() const { return theLocal; }
  
  const zstring& getNamespace2() const { return theNamespace; }

  const zstring& getPrefix2() const { return thePrefix; }

  bool isBaseUri() const;
  
  bool isIdQName() const;

  zstring show() const;

protected:
  QNameItem(store::SchemaTypeCode t = store::XS_QNAME) 
    :
    AtomicItem(t),
    theNormalizedQName(NULL),
    theIsInPool(true),
    thePosition(0),
    theNextFree(0),
    thePrevFree(0)
  {
  }
  
  // These two constructors are for building QName items outside
  // of the pool (they point back to the normalized QName in the pool).
  // Zorba does not use them, but extensions to the simple store may.
  QNameItem(
      store::SchemaTypeCode t,
      const char* ns,
      const char* prefix,
      const char* local);

  QNameItem(
      store::SchemaTypeCode t,
      const zstring& ns,
      const zstring& prefix,
      const zstring& local);

  void free();

  bool isValid() const 
  {
    assert(theNormalizedQName == NULL || 
           (theNormalizedQName->isNormalized() &&
            theNamespace == theNormalizedQName->theNamespace &&
            theLocal == theNormalizedQName->theLocal));

    return theNormalizedQName != NULL;
  }

  bool isInCache() const { return thePosition != 0; }

  bool isOverflow() const { return thePosition == 0; }

  bool isNormalized() const 
  {
    assert(theNormalizedQName != this || thePrefix.empty());
    assert(!theIsInPool || theNormalizedQName == this || !thePrefix.empty());

    return theNormalizedQName == this;
  }

  void initializeAsNormalizedQName(const zstring& ns, const zstring& local)
  {
    assert(!isValid());

    theNormalizedQName = this;
    theNamespace = ns;
    thePrefix.clear();
    theLocal = local;

    assert(isNormalized());
    assert(isValid());
  }
  
  void initializeAsUnnormalizedQName(
      const QNameItem* normalizedQName,
      const zstring& prefix)
  {
    assert(!isValid());

    theNormalizedQName = normalizedQName;
    theNormalizedQName->addReference();
    theNamespace = theNormalizedQName->theNamespace;
    thePrefix = prefix;
    theLocal = theNormalizedQName->theLocal;

    assert(!isNormalized());
    assert(isValid());
  }

  void initializeAsQNameNotInPool(
      const zstring& ns,
      const zstring& pre,
      const zstring& local);
  
  void invalidate(bool asynchronous, QNameItem** aNormalizationVictim)
  {
    assert(isValid());

    if (!isNormalized())
    {
      if (asynchronous)
      {
        // caller must later remove reference to returned aNormalizationVictim.
        *aNormalizationVictim = const_cast<QNameItem*>(theNormalizedQName);
      }
      else
      {
        QNameItem* lNormalized = const_cast<QNameItem*>(theNormalizedQName);
        lNormalized->removeReference();
      }
    }

    theNormalizedQName = NULL;

    assert(!isValid());
  }
};


/*******************************************************************************
  class NotationItem
********************************************************************************/
class NotationItem : public AtomicItem
{
protected:
  QNameItem_t       theQName;

protected:
  friend class BasicItemFactory;

  NotationItem(
     store::SchemaTypeCode t,
      const zstring& nameSpace,
      const zstring& prefix,
      const zstring& localName);

  NotationItem(store::SchemaTypeCode t, store::Item* qname);

public:
  virtual ~NotationItem();

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
      const store::Item* item,
      long timezone = 0,
      const XQPCollator* aCollation = 0) const;

  size_t alloc_size() const;
  size_t dynamic_size() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  const zstring& getNamespace() const { return theQName->getNamespace(); }

  const zstring& getPrefix() const { return theQName->getPrefix(); }

  const zstring& getLocalName() const { return theQName->getLocalName(); }

  zstring show() const;
};


/*******************************************************************************
  class AnyUriItem
********************************************************************************/
class AnyUriItem : public AtomicItem
{
  friend class BasicItemFactory;

protected:
  zstring theValue;

protected:
  AnyUriItem(store::SchemaTypeCode t, zstring& value)
    : 
    AtomicItem(t)
  {
    theValue.take(value);
  }

  AnyUriItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  virtual AnyUriTypeCode getAnyUriTypeCode() const
  {
    return NON_SPECIALIZED_ANY_URI;
  }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* item,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return item->getString() == theValue;
  }

  size_t alloc_size() const;
  size_t dynamic_size() const;

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue.compare(other->getString());
  }

  bool getEBV() const;

  zstring getStringValue() const { return theValue; }

  void getStringValue2(zstring& val) const { val = theValue; }

  void appendStringValue(zstring& buf) const { buf += theValue; }

  const zstring& getString() const { return theValue; }

  zstring show() const;

  virtual bool
  isAncestor(const store::Item_t&) const;

  virtual bool
  isFollowingSibling(const store::Item_t&) const;

  virtual bool
  isFollowing(const store::Item_t&) const;

  virtual bool
  isInSubtreeOf(const store::Item_t&) const;

  virtual bool
  isDescendant(const store::Item_t&) const;

  virtual bool
  isPrecedingSibling(const store::Item_t&) const;

  virtual bool
  isPreceding(const store::Item_t&) const;

  virtual bool
  isChild(const store::Item_t&) const;

  virtual bool
  isAttribute(const store::Item_t&) const;

  virtual bool
  isParent(const store::Item_t&) const;

  virtual bool
  isPrecedingInDocumentOrder(const store::Item_t&) const;

  virtual bool
  isFollowingInDocumentOrder(const store::Item_t&) const;

  virtual store::Item_t
  getLevel() const;

  virtual bool
  isAttributeRef() const;

  virtual bool
  isCommentRef() const;

  virtual bool
  isDocumentRef() const;

  virtual bool
  isElementRef() const;

  virtual bool
  isProcessingInstructionRef() const;

  virtual bool
  isTextRef() const;

  virtual bool
  isSibling(const store::Item_t&) const;

  virtual bool
  inSameTree(const store::Item_t&) const;

  virtual bool
  inCollection() const;

  virtual bool
  inSameCollection(const store::Item_t&) const;
};


/*******************************************************************************
  class StructuralAnyUriItem
********************************************************************************/
class StructuralAnyUriItem : public AtomicItem
{
protected:
  ulong                        theCollectionId;
  TreeId                       theTreeId;
  store::StoreConsts::NodeKind theNodeKind;
  OrdPath                      theOrdPath;
   
  // The value is computed lazily when needed.
  // The empty string is used if it has not been computed yet.
  mutable zstring              theEncodedValue;

public:
  size_t alloc_size() const;
  size_t dynamic_size() const;

  virtual AnyUriTypeCode getAnyUriTypeCode() const 
  {
    return STRUCTURAL_INFORMATION_ANY_URI;
  }
  
  store::Item* getType() const;

  uint32_t hash(long tz = 0, const XQPCollator* c = 0) const;

  bool equals(const store::Item* i, long tz = 0, const XQPCollator* c = 0) const;

  long compare(const Item* i, long tz = 0, const XQPCollator* c = 0) const;

  // A structural URI is never empty.
  bool getEBV() const { return true; }

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  const zstring& getString() const
  {
    if (theEncodedValue == "")
    {
      encode();
    }
    return theEncodedValue;
  }

  zstring show() const;

  bool
  isAncestor(const store::Item_t&) const;

  bool
  isFollowingSibling(const store::Item_t&) const;

  bool
  isFollowing(const store::Item_t&) const;

  bool
  isInSubtreeOf(const store::Item_t&) const;

  bool
  isDescendant(const store::Item_t&) const;

  bool
  isPrecedingSibling(const store::Item_t&) const;

  bool
  isPreceding(const store::Item_t&) const;

  bool
  isChild(const store::Item_t&) const;

  bool
  isAttribute(const store::Item_t&) const;

  bool
  isParent(const store::Item_t&) const;

  bool
  isPrecedingInDocumentOrder(const store::Item_t&) const;

  bool
  isFollowingInDocumentOrder(const store::Item_t&) const;

  store::Item_t
  getLevel() const;

  bool
  isAttributeRef() const;

  bool
  isCommentRef() const;

  bool
  isDocumentRef() const;

  bool
  isElementRef() const;

  bool
  isProcessingInstructionRef() const;

  bool
  isTextRef() const;

  bool
  isSibling(const store::Item_t&) const;

  bool
  inSameTree(const store::Item_t&) const;

  bool
  inCollection() const;

  bool
  inSameCollection(const store::Item_t&) const;
  
private:
  // Forces computation of the value.
  void encode() const;
 
protected:
  friend class BasicItemFactory;

  StructuralAnyUriItem(store::SchemaTypeCode t, zstring& value);

  StructuralAnyUriItem(
      store::SchemaTypeCode t,
      ulong collectionId,
      const TreeId& treeId,
      store::StoreConsts::NodeKind nodeKind,
      const OrdPath& ordPath);

  StructuralAnyUriItem() 
    :
    AtomicItem(store::XS_ANY_URI),
    theEncodedValue("")
  {
  }
};


/*******************************************************************************
  class StringItem
********************************************************************************/
class StringItem : public AtomicItem
{
  friend class BasicItemFactory;
#ifndef ZORBA_NO_FULL_TEXT
  friend class AtomicItemTokenizerCallback;
#endif /* ZORBA_NO_FULL_TEXT */

protected:
  zstring theValue;

protected:
  StringItem(store::SchemaTypeCode t, zstring& value)
    :
    AtomicItem(t)
  {
    theValue.take(value);
  }

  StringItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  size_t alloc_size() const;
  size_t dynamic_size() const;

  virtual store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item*,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const;

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const;

  bool getEBV() const;

  zstring getStringValue() const { return theValue; }

  void getStringValue2(zstring& val) const { val = theValue; }

  void appendStringValue(zstring& buf) const { buf += theValue; }

  const zstring& getString() const { return theValue; }

  virtual zstring show() const;

#ifndef ZORBA_NO_FULL_TEXT
  FTTokenIterator_t getTokens(
      TokenizerProvider const&,
      Tokenizer::State&,
      locale::iso639_1::type,
      bool = false ) const;
#endif /* ZORBA_NO_FULL_TEXT */
};


/*******************************************************************************
  class StreamableStringItem
********************************************************************************/
class StreamableStringItem : public StringItem
{
  friend class BasicItemFactory;

protected:
  std::istream * theIstream;

  bool theIsMaterialized;
  bool theIsConsumed;
  bool theIsSeekable;

  StreamReleaser theStreamReleaser;

  store::Item_t theStreamableDependent;

public:
  bool equals(
      store::Item const*,
      long timezone = 0,
      const XQPCollator* collator = 0 ) const;

  long compare( 
      Item const* other,
      long timezone = 0,
      const XQPCollator* collator = 0) const;

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& result) const;

  void appendStringValue(zstring& buf) const;

  const zstring& getString() const;

  uint32_t hash(long timezone = 0, const XQPCollator* collator = 0) const;

  zstring show() const;

  bool isStreamable() const;

  bool isSeekable() const;

  void ensureSeekable();

  std::istream& getStream();

  StreamReleaser getStreamReleaser();

  void setStreamReleaser(StreamReleaser aReleaser);

  virtual ~StreamableStringItem()
  {
    if (theStreamReleaser)
    {
      theStreamReleaser(theIstream);
    }
  }

  size_t alloc_size() const;
  size_t dynamic_size() const;

protected:
  StreamableStringItem(
      store::SchemaTypeCode t,
      std::istream& aStream,
      StreamReleaser streamReleaser,
      bool seekable = false);

  StreamableStringItem(
      store::SchemaTypeCode t,
      store::Item_t& streamableDependent);

  void materialize() const;

private:
  static void streamReleaser(std::istream* aStream) { delete aStream;}

};


/*******************************************************************************
  class NormalizedStringItem
********************************************************************************/
class NormalizedStringItem : public StringItem
{
  friend class BasicItemFactory;

protected:
  NormalizedStringItem(store::SchemaTypeCode t, zstring& v) : StringItem(t, v) {}

public:
  virtual store::Item* getType() const;

  virtual zstring show() const;
};


/*******************************************************************************
  class TokenItem
********************************************************************************/
class TokenItem : public NormalizedStringItem
{
  friend class BasicItemFactory;

public:
  TokenItem(store::SchemaTypeCode t, zstring& v) : NormalizedStringItem(t, v) {}

  virtual store::Item* getType() const;

  virtual zstring show() const;
};


/*******************************************************************************
  class NMTOKENItem
********************************************************************************/
class NMTOKENItem : public TokenItem
{
  friend class BasicItemFactory;

protected:
  NMTOKENItem(store::SchemaTypeCode t, zstring& v) : TokenItem(t, v) {}

public:
  virtual store::Item* getType() const;

  virtual zstring show() const;
};


/*******************************************************************************
  class LanguageItem
********************************************************************************/
class LanguageItem : public TokenItem
{
  friend class BasicItemFactory;

protected:
  LanguageItem(store::SchemaTypeCode t, zstring& v) : TokenItem(t, v) { }

public:
  virtual store::Item* getType() const;

  virtual zstring show() const;
};


/*******************************************************************************
  class NameItem
********************************************************************************/
class NameItem : public TokenItem
{
  friend class BasicItemFactory;

protected:
  NameItem(store::SchemaTypeCode t, zstring& v) : TokenItem(t, v) { }

public:
  virtual store::Item* getType() const;

  virtual zstring show() const;
};


/*******************************************************************************
  class NCNameItem
********************************************************************************/
class NCNameItem : public NameItem
{
  friend class BasicItemFactory;

protected:
  NCNameItem(store::SchemaTypeCode t, zstring& v) : NameItem(t, v) { }

public:
  virtual store::Item* getType() const;

  virtual zstring show() const;
};


/*******************************************************************************
  class IDItem
********************************************************************************/
class IDItem : public NCNameItem
{
  friend class BasicItemFactory;

protected:
  IDItem(store::SchemaTypeCode t, zstring& v) : NCNameItem(t, v) { }

public:
  store::Item* getType() const;

  virtual zstring show() const;
};

/*******************************************************************************
  class IDREFItem
********************************************************************************/
class IDREFItem : public NCNameItem
{
  friend class BasicItemFactory;

protected:
  IDREFItem(store::SchemaTypeCode t, zstring& v) : NCNameItem(t, v) { }

public:
  store::Item* getType() const;

  virtual zstring show() const;
};

/*******************************************************************************
  class ENTITYItem
********************************************************************************/
class ENTITYItem : public NCNameItem
{
  friend class BasicItemFactory;

protected:
  ENTITYItem(store::SchemaTypeCode t, zstring& v) : NCNameItem(t, v) { }

public:
  store::Item* getType() const;

  virtual zstring show() const;
};


/*******************************************************************************
  class DateTimeItem
********************************************************************************/
class DateTimeItem : public AtomicItem
{
  friend class BasicItemFactory;

protected:
  DateTime theValue;

protected:
  DateTimeItem(store::SchemaTypeCode t, const DateTime* v) 
    :
    AtomicItem(t),
    theValue(*v)
  {
  }

  DateTimeItem(store::SchemaTypeCode t) : AtomicItem(t) { }

public:
  const xs_dateTime& getDateTimeValue() const { return theValue; }

  const xs_date& getDateValue() const { return theValue; }

  const xs_time& getTimeValue() const { return theValue; }

  const xs_gYearMonth& getGYearMonthValue() const { return theValue; }

  const xs_gYear& getGYearValue() const { return theValue; }

  const xs_gMonth& getGMonthValue() const { return theValue; }

  const xs_gMonthDay& getGMonthDayValue() const { return theValue; }

  const xs_gDay& getGDayValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
      const store::Item*,
      long timezone = 0,
      const XQPCollator* collation = 0) const;

  long compare(
      const Item* other,
      long timezone = 0,
      const XQPCollator* collation = 0) const;

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;
};


/*******************************************************************************
  class DurationItem
********************************************************************************/
class DurationItem : public AtomicItem
{
  friend class BasicItemFactory;

protected:
  Duration theValue;

protected:
  DurationItem(store::SchemaTypeCode t, const xs_duration* v)
    :
    AtomicItem(t),
    theValue(*v)
  {
  }

  DurationItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  const xs_duration& getDurationValue() const;

  const xs_dayTimeDuration& getDayTimeDurationValue() const;

  const xs_yearMonthDuration& getYearMonthDurationValue() const;

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue.hash();
  }

  bool equals(const store::Item* i, long tz = 0, const XQPCollator* c = 0) const
  {
    return theValue == i->getDurationValue();
  }

  long compare(const Item* i, long tz = 0, const XQPCollator* c = 0) const
  {
    return theValue.compare(i->getDurationValue());
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;
};


/*******************************************************************************
  class DoubleItem
********************************************************************************/
class DoubleItem : public AtomicItem
{
  friend class BasicItemFactory;

protected:
	xs_double theValue;

protected:
	DoubleItem(store::SchemaTypeCode t, const xs_double& v)
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  DoubleItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
	xs_double getDoubleValue() const { return theValue; }

  bool isNaN() const;

  bool isPosOrNegInf() const;

	store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue == other->getDoubleValue();
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    if (theValue.isNaN() || other->getDoubleValue().isNaN())
      throw ZORBA_EXCEPTION(zerr::ZSTR0041_NAN_COMPARISON);

    return theValue.compare(other->getDoubleValue());
  }

	bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;
};


/*******************************************************************************
  class FloatItem
********************************************************************************/
class FloatItem : public AtomicItem
{
  friend class BasicItemFactory;

protected:
  xs_float theValue;

protected:
  FloatItem(store::SchemaTypeCode t, const xs_float& v) 
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  FloatItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  xs_float getFloatValue() const { return theValue; }

  xs_double getDoubleValue() const { return xs_double(theValue); }

  bool isNaN() const;

  bool isPosOrNegInf() const;

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return getDoubleValue() == other->getDoubleValue();
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    if (theValue.isNaN() || other->getFloatValue().isNaN())
      throw ZORBA_EXCEPTION( zerr::ZSTR0041_NAN_COMPARISON );

    return getDoubleValue().compare(other->getDoubleValue());
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;
};


/*******************************************************************************
  class DecimalItem

                               decimal
                                  |
                                  |
                               integer
                                  |
              ------------------------------------------
              |                   |                    |
       nonPositiveInteger  nonNegativeInteger         long
              |                   |                    |
              |            -----------------          int
        negativeInteger    |               |           |
                           |               |         short
                     positiveInteger   unsignedLong    |
                                           |         byte
                                       unsignedInt
                                           |
                                       unsingedShort
                                           |
                                       unsingedByte

********************************************************************************/
class DecimalItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class IndexConditionImpl;
  friend class AtomicItem;

protected:
  xs_decimal theValue;

protected:
  DecimalItem(store::SchemaTypeCode t, const xs_decimal& v)
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  DecimalItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  size_t alloc_size() const;
  size_t dynamic_size() const;

  xs_decimal getDecimalValue() const;

  xs_integer getIntegerValue() const;

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0 ,
        const XQPCollator* aCollation = 0) const;

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const;

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  bool isNaN() const;

  zstring show() const;
};


///////////////////////////////////////////////////////////////////////////////

template<class ValueType>
class IntegerItemImpl : public AtomicItem {
  friend class BasicItemFactory;
  friend class IndexConditionImpl;
  friend class AtomicItem;

protected:
  typedef ValueType value_type;
  value_type theValue;

protected:
  IntegerItemImpl( store::SchemaTypeCode t, value_type const &v ) :
    AtomicItem( t ),
    theValue( v )
  {
  }

  IntegerItemImpl( store::SchemaTypeCode t ) : AtomicItem( t ) { }

public:
  size_t alloc_size() const;
  size_t dynamic_size() const;

  void appendStringValue( zstring &buf ) const;
  xs_decimal getDecimalValue() const;
  xs_integer getIntegerValue() const;
  xs_long getLongValue() const;
  store::Item* getType() const;
  xs_nonNegativeInteger getUnsignedIntegerValue() const;
  xs_unsignedInt getUnsignedIntValue() const;

  long compare( const Item* other, long timezone = 0,
                const XQPCollator* aCollation = 0) const;

  bool equals( const store::Item* other, long timezone = 0,
               const XQPCollator* aCollation = 0) const;

  bool getEBV() const;
  zstring getStringValue() const;
  void getStringValue2( zstring &val ) const;
  uint32_t hash( long timezone = 0, const XQPCollator* aCollation = 0 ) const;
  zstring show() const;
};

typedef IntegerItemImpl<xs_integer>             IntegerItem;
typedef IntegerItemImpl<xs_negativeInteger>     NegativeIntegerItem;
typedef IntegerItemImpl<xs_nonNegativeInteger>  NonNegativeIntegerItem;
typedef IntegerItemImpl<xs_nonPositiveInteger>  NonPositiveIntegerItem;
typedef IntegerItemImpl<xs_positiveInteger>     PositiveIntegerItem;


/*******************************************************************************
  class LongItem
********************************************************************************/
class LongItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xs_long theValue;

protected:
  LongItem(store::SchemaTypeCode t, xs_long v)
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  LongItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  xs_decimal getDecimalValue() const;

  xs_integer getIntegerValue() const;

  xs_long getLongValue() const { return theValue; }

  xs_nonNegativeInteger getUnsignedIntegerValue() const;

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return static_cast<uint32_t>(theValue);
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getLongValue();
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    try
    {
      return (theValue < other->getLongValue() ?
              -1 :
              (theValue == other->getLongValue() ? 0 : 1));
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  bool isNaN() const { return false; }

  zstring show() const;
};


/*******************************************************************************
  class IntItem
********************************************************************************/
class IntItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xs_int theValue;

protected:
  IntItem(store::SchemaTypeCode t, xs_int v)
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  IntItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  bool isNaN() const { return false; }

  xs_decimal getDecimalValue() const;

  xs_integer getIntegerValue() const;

  xs_long getLongValue() const { return static_cast<xs_long>(theValue); }

  xs_int getIntValue() const { return theValue; }

  store::Item* getType( ) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return static_cast<uint32_t>(theValue);
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getLongValue();
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    try
    {
      return (theValue < other->getLongValue() ?
              -1 :
              (theValue == other->getLongValue() ? 0 : 1));
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;
};


/*******************************************************************************
  class ShortItem
********************************************************************************/
class ShortItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xs_short theValue;

protected:
  ShortItem(store::SchemaTypeCode t, xs_short v)
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  ShortItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  xs_decimal getDecimalValue() const;

  xs_integer getIntegerValue() const;

  xs_long getLongValue() const { return static_cast<xs_long>(theValue); }

  xs_int getIntValue() const { return static_cast<xs_int>(theValue); }

  xs_short getShortValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return static_cast<uint32_t>(theValue);
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getLongValue();
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    try
    {
      return (theValue < other->getLongValue() ?
              -1 :
              (theValue == other->getLongValue() ? 0 : 1));
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;

  bool isNaN() const { return false; }
};


/*******************************************************************************
  class ByteItem
********************************************************************************/
class ByteItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xs_byte theValue;

protected:
  ByteItem(store::SchemaTypeCode t, xs_byte v) 
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  ByteItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  xs_decimal getDecimalValue() const;

  xs_integer getIntegerValue() const;

  xs_long getLongValue() const { return static_cast<xs_long>(theValue); }

  xs_int getIntValue() const { return static_cast<xs_int>(theValue); }

  xs_short getShortValue() const { return static_cast<xs_short>(theValue); }

  xs_byte getByteValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue;
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getLongValue();
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    try
    {
      return (theValue < other->getLongValue() ?
              -1 :
              (theValue == other->getLongValue() ? 0 : 1));
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  bool isNaN() const { return false; }

  zstring show() const;
};


/*******************************************************************************
  class UnsignedLongItem
********************************************************************************/
class UnsignedLongItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xs_unsignedLong theValue;

protected:
  UnsignedLongItem(store::SchemaTypeCode t, xs_unsignedLong v)
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  UnsignedLongItem(store::SchemaTypeCode t) : AtomicItem(t) {}

 public:
  bool isNaN() const { return false; }

  xs_decimal getDecimalValue() const;

  xs_integer getIntegerValue() const;

  xs_nonNegativeInteger getUnsignedIntegerValue() const;

  xs_unsignedLong getUnsignedLongValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return static_cast<uint32_t>(theValue);
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getUnsignedLongValue();
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue() == other->getDecimalValue();
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    try
    {
      return (theValue < other->getUnsignedLongValue() ?
              -1 :
              (theValue == other->getUnsignedLongValue() ? 0 : 1));
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;
};


/*******************************************************************************
  class UnsignedIntItem
********************************************************************************/
class UnsignedIntItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xs_unsignedInt theValue;

protected:
  UnsignedIntItem(store::SchemaTypeCode t, xs_unsignedInt v)
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  UnsignedIntItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  bool isNaN() const { return false; }

  xs_decimal getDecimalValue() const;

  xs_integer getIntegerValue() const;

  xs_nonNegativeInteger getUnsignedIntegerValue() const;

  xs_long getLongValue() const { return static_cast<xs_long>(theValue); }

  xs_unsignedLong getUnsignedLongValue() const { return static_cast<xs_unsignedLong>(theValue); }

  xs_unsignedInt getUnsignedIntValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue;
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0 ) const
  {
    try
    {
      return theValue == other->getUnsignedLongValue();
    }
    catch (ZorbaException const&)
    {
      try
      {
        return getLongValue() == other->getLongValue();
      }
      catch (ZorbaException const&)
      {
        return getDecimalValue() == other->getDecimalValue();
      }
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    try
    {
      return (theValue < other->getUnsignedLongValue() ?
              -1 :
              (theValue == other->getUnsignedLongValue() ? 0 : 1));
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;
};


/*******************************************************************************
  class UnsignedShortItem
********************************************************************************/
class UnsignedShortItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xs_unsignedShort theValue;

protected:
  UnsignedShortItem(store::SchemaTypeCode t, xs_unsignedShort v)
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  UnsignedShortItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  xs_decimal getDecimalValue() const;

  xs_integer getIntegerValue() const;

  xs_nonNegativeInteger getUnsignedIntegerValue() const;

  xs_long getLongValue() const { return static_cast<xs_long>(theValue); }

  xs_unsignedLong getUnsignedLongValue() const { return static_cast<xs_unsignedLong>(theValue); }

  xs_unsignedInt getUnsignedIntValue() const { return static_cast<xs_unsignedInt>(theValue); }

  xs_unsignedShort getUnsignedShortValue() const { return theValue; }

  bool isNaN() const { return false; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return static_cast<uint32_t>(theValue);
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0 ) const
  {
    try
    {
      return theValue == other->getUnsignedLongValue();
    }
    catch (ZorbaException const&)
    {
      try
      {
        return getLongValue() == other->getLongValue();
      }
      catch (ZorbaException const&)
      {
        return getDecimalValue() == other->getDecimalValue();
      }
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    try
    {
      return (theValue < other->getUnsignedLongValue() ?
              -1 :
              (theValue == other->getUnsignedLongValue() ? 0 : 1));
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;
};


/*******************************************************************************
  class UnsignedByteItem
********************************************************************************/
class UnsignedByteItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xs_unsignedByte theValue;

protected:
  UnsignedByteItem(store::SchemaTypeCode t, xs_unsignedByte v)
    :
    AtomicItem(t),
    theValue(v)
  {}

  UnsignedByteItem(store::SchemaTypeCode t) 
    :
    AtomicItem(t),
    theValue(0)
  {}

public:
  xs_decimal getDecimalValue() const;

  xs_integer getIntegerValue() const;

  xs_nonNegativeInteger getUnsignedIntegerValue() const;

  xs_long getLongValue() const { return static_cast<xs_long>(theValue); }

  xs_unsignedLong getUnsignedLongValue() const { return static_cast<xs_unsignedLong>(theValue); }

  xs_unsignedInt getUnsignedIntValue() const { return static_cast<xs_unsignedInt>(theValue); }

  xs_unsignedShort getUnsignedShortValue() const { return static_cast<xs_unsignedShort>(theValue); }

  xs_unsignedByte getUnsignedByteValue() const { return theValue; }

  bool isNaN() const { return false; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return static_cast<uint32_t>(theValue);
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0 ) const
  {
    try
    {
      return theValue == other->getUnsignedLongValue();
    }
    catch (ZorbaException const&)
    {
      try
      {
        return getLongValue() == other->getLongValue();
      }
      catch (ZorbaException const&)
      {
        return getDecimalValue() == other->getDecimalValue();
      }
    }
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    try
    {
      return (theValue < other->getUnsignedLongValue() ?
              -1 :
              (theValue == other->getUnsignedLongValue() ? 0 : 1));
    }
    catch (ZorbaException const&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;
};


/*******************************************************************************
  class BooleanItem
********************************************************************************/
class BooleanItem : public AtomicItem
{
 friend class BasicItemFactory;

protected:
  xs_boolean theValue;

protected:
  BooleanItem(store::SchemaTypeCode t, xs_boolean v)
    :
    AtomicItem(t),
    theValue(v)
  {
  }

  BooleanItem(store::SchemaTypeCode t) : AtomicItem(t) {}

public:
  xs_boolean getBooleanValue() const { return theValue; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return other->getBooleanValue() == theValue;
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return (theValue == other->getBooleanValue() ?
            0 :
            (theValue == false ? -1 : 1));
  }

  bool getEBV() const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;
};


/*******************************************************************************
  class Base64BinaryItem
********************************************************************************/
class Base64BinaryItem : public AtomicItem
{
  friend class BasicItemFactory;

protected:
  std::vector<char> theValue;
  bool              theIsEncoded;

protected:
  Base64BinaryItem( store::SchemaTypeCode t, bool aIsEncoded ) :
    AtomicItem(t),
    theIsEncoded(aIsEncoded)
  {
  }

  Base64BinaryItem( store::SchemaTypeCode t, char const *data,
                    size_t size, bool aIsEncoded = true ) :
    AtomicItem(t),
    theIsEncoded(aIsEncoded)
  {
    theValue.reserve( size );
    theValue.insert( theValue.begin(), data, data + size );
  }

public:
  size_t alloc_size() const;
  size_t dynamic_size() const;

  char const* getBase64BinaryValue( size_t &data ) const;

  store::Item* getType() const;

  bool isEncoded() const { return theIsEncoded; }

  uint32_t hash( long timezone = 0, XQPCollator const* = 0 ) const;

  bool equals( store::Item const *other, long timezone = 0,
               XQPCollator const* = 0 ) const;

  zstring getStringValue() const;

  void getStringValue2( zstring& val ) const;

  void appendStringValue( zstring &buf ) const;

  zstring show() const;
};


/*******************************************************************************
  class StreamableBase64BinaryItem
********************************************************************************/
class StreamableBase64BinaryItem : public Base64BinaryItem
{
  friend class BasicItemFactory;

protected:
  std::istream * theIstream;

  bool           theIsMaterialized;
  bool           theIsConsumed;
  bool           theIsSeekable;

  StreamReleaser theStreamReleaser;

protected:
  StreamableBase64BinaryItem(
      store::SchemaTypeCode t,
      std::istream& aStream,
      StreamReleaser streamReleaser,
      bool seekable = false,
      bool is_encoded = false)
    :
    Base64BinaryItem(t, is_encoded),
    theIstream(&aStream),
    theIsMaterialized(false),
    theIsConsumed(false),
    theIsSeekable(seekable),
    theStreamReleaser(streamReleaser)
  {
  }

  void materialize() const;

public:
  virtual ~StreamableBase64BinaryItem()
  {
    if (theStreamReleaser) 
    {
      theStreamReleaser(theIstream);
    }
  }

  bool isStreamable() const;

  bool isSeekable() const;

  void ensureSeekable();

  std::istream& getStream();

  StreamReleaser getStreamReleaser();

  void setStreamReleaser(StreamReleaser aReleaser);

  const char* getBase64BinaryValue(size_t&) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(store::Item const *, long timezone = 0,
    XQPCollator const* = 0) const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  zstring show() const;

private:
  static void streamReleaser(std::istream* aStream) { delete aStream;}
};


/*******************************************************************************
  class HexBinaryItem
********************************************************************************/
class HexBinaryItem : public AtomicItem
{
  friend class BasicItemFactory;

protected:
  std::vector<char> theValue;
  bool              theIsEncoded;

protected:
  HexBinaryItem(store::SchemaTypeCode t, bool aIsEncoded) :
    AtomicItem(t),
    theIsEncoded(aIsEncoded)
  {
  }

  HexBinaryItem( store::SchemaTypeCode t, char const *data, size_t size,
                 bool encoded = true );

public:
  size_t alloc_size() const;
  size_t dynamic_size() const;

  char const* getHexBinaryValue( size_t &size ) const;

  store::Item* getType() const;

  bool isEncoded() const { return theIsEncoded; }

  uint32_t hash( long timezone = 0, XQPCollator const* = 0 ) const;

  bool equals( store::Item const *other, long timezone = 0,
               XQPCollator const* = 0) const;

  zstring getStringValue() const;

  void getStringValue2( zstring &val ) const;

  void appendStringValue( zstring &buf ) const;

  zstring show() const;
};


/*******************************************************************************
  class ErrorItem

  An ErrorItem obj stores a pointer to a ZorbaError obj. The ZorbaError obj is
  not created by the store, but once a pointer to it is set inside an ErrorItem
  obj, the ErrorItem obj assumes ownership of the ZorbaError. The getError()
  method returns the zorbaError pointer, but if the caller needs to access the
  ZobaError obj beyond the lifetime of the ErrorItem, they must make a deep
  copy of it.

  This design is due to the fact that ZorbaError class is visible to the store
  lib, but subclasses of ZorbaError (like ZorbaUserError) may not be visible,
  so ErrorItem cannot do much with an error obj other than storing a pointer
  to it (and calling the virtual free() method on that pointer when the
  ErrorItem gets destroyed).
********************************************************************************/
class ErrorItem : public AtomicItem
{
  friend class BasicItemFactory;

protected:
  ZorbaException * theError;

protected:
  ErrorItem(ZorbaException* error) 
    :
    AtomicItem(store::XS_LAST),
    theError(error) 
  {
    theUnion.itemKind = ERROR_;
  }

public:
  virtual ~ErrorItem();

  size_t alloc_size() const;
  size_t dynamic_size() const;

  ZorbaException* getError() const { return theError; }

  zstring show() const;

protected:
  // Disable copy
  ErrorItem(const ErrorItem& other);
  ErrorItem& operator=(const ErrorItem& other);
};


#ifndef ZORBA_NO_FULL_TEXT
/**
 * An %AtomicItemTokenizerCallback is-a Tokenizer::Callback for tokenizing
 * atomic items.
 */
class AtomicItemTokenizerCallback : public Tokenizer::Callback
{
public:
  typedef FTTokenStore::container_type container_type;

  AtomicItemTokenizerCallback( container_type &tokens );

  // inherited
  void token( char const *utf8_s, size_type utf8_len, locale::iso639_1::type,
              size_type token_no, size_type sent_no, size_type para_no,
              Item const* );

private:
  container_type &tokens_;
};
#endif /* ZORBA_NO_FULL_TEXT */


} // namespace simplestore
} // namespace zorba
#endif /* ZORBA_STORE_ATOMIC_ITEMS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
