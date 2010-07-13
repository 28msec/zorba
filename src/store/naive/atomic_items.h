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

#include <zorba/config.h>
#include <vector>

#include "store/api/item.h"
#include "store/naive/store_defs.h"
#ifndef ZORBA_NO_FULL_TEXT
#include "store/naive/naive_ft_token_iterator.h"
#endif /* ZORBA_NO_FULL_TEXT */

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"
#include "zorbatypes/datetime.h"
#include "zorbautils/tokenizer.h"

#include "zorbaerrors/errors.h"


namespace zorba
{

namespace simplestore
{

class AtomicItemTokenizer;


/*****************************************************************************

 *****************************************************************************/

class AtomicItem : public store::Item
{
#ifdef ZORBA_FOR_ONE_THREAD_ONLY
public:
  AtomicItem() : store::Item() { }

#else

protected:
  SYNC_CODE(RCLock  theRCLock;)

public:
  AtomicItem() : store::Item() { SYNC_CODE(theRCLockPtr = &theRCLock;) }
#endif

  ~AtomicItem() {}

  bool isNode() const   { return false; }
  bool isAtomic() const { return true; }
  bool isPul() const    { return false; }
  bool isTuple() const  { return false; }
  bool isError() const  { return false; }
  bool isFunction() const { return false; }

  store::Item_t getAtomizationValue() const;

  virtual SchemaTypeCode getTypeCode() const = 0;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  void castToLong(store::Item_t& result) const;

  void coerceToDouble(store::Item_t& result, bool force, bool& lossy) const;
};


typedef rchandle<AtomicItem> AtomicItem_t;


/*******************************************************************************
  class UserTypedAtomicItem
********************************************************************************/
class UserTypedAtomicItemImpl : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  AtomicItem_t   theBaseItem;
  store::Item_t  theTypeName;

protected:
  UserTypedAtomicItemImpl(
        store::Item_t& baseItem,
        store::Item_t& typeName)
  {
    theBaseItem.transfer(baseItem);
    theTypeName.transfer(typeName);
  }

  UserTypedAtomicItemImpl() {}

public:
  store::Item* getBaseItem() const { return theBaseItem.getp(); }

  SchemaTypeCode getTypeCode() const { return theBaseItem->getTypeCode(); }

  store::Item* getType() const { return theTypeName.getp(); }

  uint32_t hash(long timezone = 0, const XQPCollator* collation = 0) const
  {
    return theBaseItem->hash(timezone, collation);
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    if (other->getBaseItem() == NULL)
      return theBaseItem->equals(other, timezone, collation);
    else
      return theBaseItem->equals(other->getBaseItem(), timezone, collation);
  }

  long compare(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const
  {
    if (other->getBaseItem() == NULL)
      return theBaseItem->compare(other, timezone, collation);
    else
      return theBaseItem->compare(other->getBaseItem(), timezone, collation);
  }

  store::Item_t getEBV() const { return theBaseItem->getEBV(); }

  xqpStringStore_t getStringValue() const { return theBaseItem->getStringValue(); }

  void getStringValue(xqpStringStore_t& strval) const 
  {
    theBaseItem->getStringValue(strval);
  }

  void getStringValue(std::string& buf) const { theBaseItem->getStringValue(buf); }

  xqpStringStore* getString() const { return theBaseItem->getString(); }

  xqp_base64Binary getBase64BinaryValue() const { return theBaseItem->getBase64BinaryValue(); }

  xqp_hexBinary getHexBinaryValue() const { return theBaseItem->getHexBinaryValue(); }

  bool getBooleanValue() const { return theBaseItem->getBooleanValue(); }

  xqp_double getDoubleValue() const { return theBaseItem->getDoubleValue(); }

  xqp_float getFloatValue() const { return theBaseItem->getFloatValue(); }

  xqp_decimal getDecimalValue() const { return theBaseItem->getDecimalValue(); }

  xqp_integer getIntegerValue() const { return theBaseItem->getIntegerValue(); }

  xqp_uinteger getUnsignedIntegerValue() const { return theBaseItem->getUnsignedIntegerValue(); }

  xqp_long getLongValue() const { return theBaseItem->getLongValue(); }

  xqp_int getIntValue() const { return theBaseItem->getIntValue(); }

  xqp_short getShortValue() const { return theBaseItem->getShortValue(); }

  xqp_byte getByteValue() const { return theBaseItem->getByteValue(); }

  xqp_ulong getUnsignedLongValue() const { return theBaseItem->getUnsignedLongValue(); }

  xqp_uint getUnsignedIntValue() const { return theBaseItem->getUnsignedIntValue(); }

  xqp_ushort getUnsignedShortValue() const { return theBaseItem->getUnsignedShortValue(); }

  xqp_ubyte getUnsignedByteValue() const { return theBaseItem->getUnsignedByteValue(); }

  bool isNaN() const { return theBaseItem->isNaN(); }

  bool isPosOrNegInf() const { return theBaseItem->isPosOrNegInf(); }

  const xqp_dateTime& getDateTimeValue() const 
  {
    return theBaseItem->getDateTimeValue(); 
  }

  const xqp_date& getDateValue() const 
  {
    return theBaseItem->getDateValue(); 
  }

  const xqp_time& getTimeValue() const 
  {
    return theBaseItem->getTimeValue(); 
  }

  const xqp_gYearMonth& getGYearMonthValue() const 
  {
    return theBaseItem->getGYearMonthValue(); 
  }

  const xqp_gYear& getGYearValue() const 
  {
    return theBaseItem->getGYearValue(); 
  }

  const xqp_gMonth& getGMonthValue() const 
  {
    return theBaseItem->getGMonthValue(); 
  }

  const xqp_gMonthDay& getGMonthDayValue() const 
  {
    return theBaseItem->getGMonthDayValue(); 
  }

  const xqp_gDay& getGDayValue() const 
  {
    return theBaseItem->getGDayValue(); 
  }

  const xqp_duration& getDurationValue() const 
  {
    return theBaseItem->getDurationValue(); 
  }

  const xqp_dayTimeDuration& getDayTimeDurationValue() const 
  {
    return theBaseItem->getDayTimeDurationValue(); 
  }

  const xqp_yearMonthDuration& getYearMonthDurationValue() const
  {
    return theBaseItem->getYearMonthDurationValue();
  }

  std::vector<xqp_string> getStringVectorValue() const 
  {
    return theBaseItem->getStringVectorValue();
  }

  xqp_string show() const { return theBaseItem->show(); }
};


/*******************************************************************************
  class UntypedAtomicItem
********************************************************************************/
class UntypedAtomicItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xqpStringStore_t theValue;

protected:
  UntypedAtomicItem(xqpStringStore_t& value) { theValue.transfer(value); }

  UntypedAtomicItem() {}

public:
  void castToUri(store::Item_t& result) const;

  void castToString(store::Item_t& result) const;

  void castToDateTime(store::Item_t& result) const;

  void castToDate(store::Item_t& result) const;

  void castToTime(store::Item_t& result) const;

  void castToGYear(store::Item_t& result) const;

  void castToGYearMonth(store::Item_t& result) const;

  void castToGMonthDay(store::Item_t& result) const;

  void castToGMonth(store::Item_t& result) const;

  void castToGDay(store::Item_t& result) const;

  void castToDuration(store::Item_t& result) const;

  void castToDouble(store::Item_t& result) const;

  void castToDecimal(store::Item_t& result) const;

  void castToInteger(store::Item_t& result) const;

  void castToHexBinary(store::Item_t& result) const;

  void castToBase64Binary(store::Item_t& result) const;

  void castToBoolean(store::Item_t& result) const;

  SchemaTypeCode getTypeCode() const { return XS_UNTYPED_ATOMIC; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue->byteEqual(other->getString());
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const { return theValue; }
  xqpStringStore* getStringValueP() const { return theValue.getp(); }
  void getStringValue(xqpStringStore_t& strval) const { strval = theValue; }
  void getStringValue(std::string& buf) const { buf += theValue->str(); }

  xqpStringStore* getString() const { return theValue.getp(); }

  xqp_string show() const;
};


/*******************************************************************************
  class QNameItem
********************************************************************************/
class QNameItem : public AtomicItem
{
  friend class QNamePool;

protected:
  static xqpStringStore_t theEmptyPrefix;

  xqpStringStore_t    theNamespace;
  xqpStringStore_t    thePrefix;

  union
  {
    xqpStringStore  * theLocal;
    QNameItem       * theNormQN;
  }                   theUnion;

  uint16_t            thePosition;
  uint16_t            theNextFree;
  uint16_t            thePrevFree;

protected:
  QNameItem() 
    :
    thePosition(0),
    theNextFree(0),
    thePrevFree(0) 
  {
    theUnion.theLocal = NULL;
  }
  
  void free();

  bool isValid() const { return theUnion.theLocal != NULL; }

  bool isInCache() const { return thePosition != 0; }

  bool isOverflow() const { return thePosition == 0; }

  bool isNormalized() const { return thePrefix->empty(); }

  QNameItem* detachNormalized() 
  {
    assert(!isNormalized());
    QNameItem* qn = theUnion.theNormQN;
    theUnion.theNormQN = NULL;
    return qn;
  }

  void setNormalized(QNameItem* qn);  

  void unsetNormalized();

  void setLocal(xqpStringStore* local);

  void unsetLocal();

public:
  virtual ~QNameItem();

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* item,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return (getNormalized() == static_cast<const QNameItem*>(item)->getNormalized());
  }

  xqpStringStore* getNamespace() const { return theNamespace.getp(); }

  xqpStringStore* getPrefix() const    { return thePrefix.getp(); }

  xqpStringStore* getLocalName() const { return getNormalized()->theUnion.theLocal; }

  SchemaTypeCode getTypeCode() const { return XS_QNAME; }

  store::Item* getType() const;

  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  bool isIdQName() const;

  bool isBaseUri() const;

  QNameItem* getNormalized() const
  {
    return (isNormalized() ?
            const_cast<QNameItem*>(this) :
            theUnion.theNormQN);
  }

  xqp_string show() const;
};


/*******************************************************************************
  class AnyUriItem
********************************************************************************/
class AnyUriItemImpl : public AtomicItem
{
protected:
  xqpStringStore_t theValue;

protected:
  // make sure that only created by the factory
  friend class BasicItemFactory;
  AnyUriItemImpl(xqpStringStore_t& value) { theValue.transfer(value); }

  AnyUriItemImpl() {}

public:
  SchemaTypeCode getTypeCode() const { return XS_ANY_URI; }

  store::Item* getType( ) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* item,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return item->getString()->byteEqual(theValue.getp());
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    xqpStringStore* otherStr = other->getString();
    return theValue->byteCompare(otherStr->c_str(), otherStr->bytes());
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const { return theValue.getp(); }
  xqpStringStore* getStringValueP() const  { return theValue.getp(); }
  void getStringValue(xqpStringStore_t& strval) const { strval = theValue; }
  void getStringValue(std::string& buf) const { buf += theValue->str(); }

  xqpStringStore* getString() const { return theValue.getp(); }

  xqp_string show() const;
};


/******************************************************************************
  class StringItem
 *****************************************************************************/

class StringItemNaive : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItemTokenizer;

protected:
  xqpStringStore_t theValue;

protected:
  StringItemNaive(xqpStringStore_t& value) { theValue.transfer(value); }

  StringItemNaive() {}

public:

  virtual SchemaTypeCode getTypeCode() const { return XS_STRING; }

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

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const { return theValue; }
  xqpStringStore* getStringValueP() const { return theValue.getp(); }
  void getStringValue(xqpStringStore_t& strval) const { strval = theValue; }
  void getStringValue(std::string& buf) const { buf += theValue->str(); }

  xqpStringStore* getString() const { return theValue.getp(); }

  virtual xqp_string show() const;

#ifndef ZORBA_NO_FULL_TEXT
  FTTokenIterator_t
  getDocumentTokens( locale::iso639_1::type = locale::iso639_1::unknown ) const;

  FTTokenIterator_t
  getQueryTokens( locale::iso639_1::type = locale::iso639_1::unknown,
                  bool wildcards = false ) const;
#endif /* ZORBA_NO_FULL_TEXT */
};


#ifndef ZORBA_NO_FULL_TEXT
/**
 * An <code>AtomicItemTokenizer</code> is-a Tokenizer::Callback TODO
 */
class AtomicItemTokenizer : public Tokenizer::Callback 
{
public:
  typedef NaiveFTTokenIterator::FTTokens FTTokens;

  AtomicItemTokenizer( Tokenizer &tokenizer, locale::iso639_1::type lang,
                       FTTokens &tokens ) :
    tokenizer_( tokenizer ),
    tokens_( tokens ),
    lang_( lang )
  {
  }

  void operator()( char const *utf8_s, int utf8_len,
                   int token_no, int sent_no, int para_no, void* = 0 );

  void tokenize( char const *utf8_s, int len ) {
    tokenizer_.tokenize( utf8_s, len, lang_, *this );
  }

private:
  Tokenizer &tokenizer_;
  FTTokens &tokens_;
  locale::iso639_1::type const lang_;
};
#endif /* ZORBA_NO_FULL_TEXT */


/*******************************************************************************
  class NormalizedStringItemImpl
********************************************************************************/
class NormalizedStringItemImpl : public StringItemNaive
{
  friend class BasicItemFactory;

protected:
  NormalizedStringItemImpl(xqpStringStore_t& value) : StringItemNaive(value) {}

public:
  virtual SchemaTypeCode getTypeCode() const { return XS_NORMALIZED_STRING; }

  virtual store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class TokenItemImpl
********************************************************************************/
class TokenItemImpl : public NormalizedStringItemImpl
{
  friend class BasicItemFactory;

public:
  TokenItemImpl(xqpStringStore_t& value) : NormalizedStringItemImpl(value) {}

  virtual SchemaTypeCode getTypeCode() const { return XS_TOKEN; }

  virtual store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class NMTOKENItemImpl
********************************************************************************/
class NMTOKENItemImpl : public TokenItemImpl
{
  friend class BasicItemFactory;

protected:
  NMTOKENItemImpl(xqpStringStore_t& value) : TokenItemImpl(value) {}

public:
  virtual SchemaTypeCode getTypeCode() const { return XS_NMTOKEN; }

  virtual store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class LanguageItem
********************************************************************************/
class LanguageItemImpl : public TokenItemImpl
{
  friend class BasicItemFactory;

protected:
  LanguageItemImpl(xqpStringStore_t& value) : TokenItemImpl(value) {}

public:
  virtual SchemaTypeCode getTypeCode() const { return XS_LANGUAGE; }

  virtual store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class NameItem
********************************************************************************/
class NameItemImpl : public TokenItemImpl
{
  friend class BasicItemFactory;

protected:
  NameItemImpl(xqpStringStore_t& value) : TokenItemImpl(value) {}

public:
  virtual SchemaTypeCode getTypeCode() const { return XS_NAME; }

  virtual store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class NCNameItem
********************************************************************************/
class NCNameItemImpl : public NameItemImpl
{
  friend class BasicItemFactory;

protected:
  NCNameItemImpl(xqpStringStore_t& value) : NameItemImpl(value) {}

public:
  virtual SchemaTypeCode getTypeCode() const { return XS_NCNAME; }

  virtual store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class IDItem
********************************************************************************/
class IDItemImpl : public NCNameItemImpl
{
  friend class BasicItemFactory;

protected:
  IDItemImpl(xqpStringStore_t& value) : NCNameItemImpl(value) { }

public:
  SchemaTypeCode getTypeCode() const { return XS_ID; }

  store::Item* getType() const;

  virtual xqp_string show() const;
};

/*******************************************************************************
  class IDREFItem
********************************************************************************/
class IDREFItemImpl : public NCNameItemImpl
{
  friend class BasicItemFactory;

protected:
  IDREFItemImpl(xqpStringStore_t& value) : NCNameItemImpl(value) { }

public:
  SchemaTypeCode getTypeCode() const { return XS_IDREF; }

  store::Item* getType() const;

  virtual xqp_string show() const;
};

/*******************************************************************************
  class ENTITYItemImpl
********************************************************************************/
class ENTITYItemImpl : public NCNameItemImpl
{
  friend class BasicItemFactory;

protected:
  ENTITYItemImpl(xqpStringStore_t& value) : NCNameItemImpl(value) { }

public:
  SchemaTypeCode getTypeCode() const { return XS_ENTITY; }

  store::Item* getType() const;

  virtual xqp_string show() const;
};


/*******************************************************************************
  class DateTimeItem
********************************************************************************/
class DateTimeItemNaive : public AtomicItem
{
  friend class BasicItemFactory;

protected:
  DateTime theValue;

protected:
  DateTimeItemNaive(const DateTime* aValue) : theValue(*aValue) { };
  
public:
  const xqp_dateTime& getDateTimeValue() const { return theValue; }

  const xqp_date& getDateValue() const { return theValue; }

  const xqp_time& getTimeValue() const { return theValue; }

  const xqp_gYearMonth& getGYearMonthValue() const { return theValue; }

  const xqp_gYear& getGYearValue() const { return theValue; }

  const xqp_gMonth& getGMonthValue() const { return theValue; }

  const xqp_gMonthDay& getGMonthDayValue() const { return theValue; }

  const xqp_gDay& getGDayValue() const { return theValue; }
  
  SchemaTypeCode getTypeCode() const;

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item*,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const;

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const;

  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;

protected:
  DateTimeItemNaive() { };
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
  DurationItem(const xqp_duration* aValue) : theValue(*aValue) { };

  DurationItem() {}

public:
  const xqp_duration& getDurationValue() const;

  const xqp_dayTimeDuration& getDayTimeDurationValue() const;

  const xqp_yearMonthDuration& getYearMonthDurationValue() const;

  SchemaTypeCode getTypeCode() const;

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue.hash();
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue == other->getDurationValue();
  }


  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue.compare(other->getDurationValue());
  }

  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class DoubleItemNaive
********************************************************************************/
class DoubleItemNaive : public AtomicItem
{
  friend class BasicItemFactory;

protected:
	xqp_double theValue;

protected:
	DoubleItemNaive(const xqp_double& aValue) : theValue( aValue ) {}

  DoubleItemNaive() {}

public:
	xqp_double getDoubleValue() const { return theValue; }
	
  bool isNaN() const;
  bool isPosOrNegInf() const;

  SchemaTypeCode getTypeCode() const { return XS_DOUBLE; }

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
      return 2;

    return theValue.compare(other->getDoubleValue());
  }

	store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};
	

/*******************************************************************************
  class FloatItemNaive
********************************************************************************/
class FloatItemNaive : public AtomicItem
{
  friend class BasicItemFactory;

protected:
  xqp_float theValue;

protected:
  FloatItemNaive(const xqp_float& aValue) : theValue ( aValue ) {}

  FloatItemNaive() {}

public:
  xqp_float getFloatValue() const { return theValue; }

  xqp_double getDoubleValue() const { return FloatCommons::parseFloat(theValue); }
	
  bool isNaN() const;

  bool isPosOrNegInf() const;

  SchemaTypeCode getTypeCode() const { return XS_FLOAT; }

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
      return 2;

    return getDoubleValue().compare(other->getDoubleValue());
  }

  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class DecimalItemNaive

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
  friend class IndexBoxConditionImpl;
  friend class AtomicItem;

protected:
  xqp_decimal theValue;

  DecimalItem(const xqp_decimal& aValue) : theValue(aValue) {}

  DecimalItem() {}

public:
  xqp_decimal getDecimalValue() const { return theValue; }

  SchemaTypeCode getTypeCode() const { return XS_DECIMAL; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue.hash();
  }

  bool equals(
        const store::Item* other,
        long timezone = 0 ,
        const XQPCollator* aCollation = 0) const
  {
    return theValue == other->getDecimalValue();
  }

  long compare(
        const Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    return theValue.compare(other->getDecimalValue());
  }

  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  bool isNaN() const;

  xqp_string show() const;
};


/*******************************************************************************
  class IntegerItem
********************************************************************************/
class IntegerItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xqp_integer theValue;

protected:
  IntegerItem(const xqp_integer& aValue) : theValue ( aValue ) {}

  IntegerItem() {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const { return theValue; }

  xqp_long getLongValue() const;

  virtual SchemaTypeCode getTypeCode() const { return XS_INTEGER; }

  virtual store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const
  {
    return theValue.hash();
  }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0) const
  {
    try
    {
      return theValue == other->getIntegerValue();
    }
    catch (error::ZorbaError&)
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
      return theValue.compare(other->getIntegerValue());
    }
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  bool isNaN() const { return false; }

  virtual xqp_string show() const;
};


/*******************************************************************************
  class NonPositiveIntegerItem
********************************************************************************/
class NonPositiveIntegerItem : public IntegerItem
{
  friend class BasicItemFactory;

protected:
  NonPositiveIntegerItem(const xqp_integer& aValue) : IntegerItem(aValue) {}

  NonPositiveIntegerItem() {}
    
public:
  SchemaTypeCode getTypeCode() const { return XS_NON_POSITIVE_INTEGER; }

  store::Item* getType() const;

  xqp_string show() const;
};


/*******************************************************************************
  class NegativeIntegerItem
********************************************************************************/
class NegativeIntegerItem : public IntegerItem
{
  friend class BasicItemFactory;

protected:
  NegativeIntegerItem(const xqp_integer& aValue) : IntegerItem(aValue) {}

  NegativeIntegerItem() {}
    
public:
  SchemaTypeCode getTypeCode() const { return XS_NEGATIVE_INTEGER; }

  store::Item* getType() const;

  xqp_string show() const;
};
  

/*******************************************************************************
  class NonNegativeIntegerItem

  Note: xqp_uinteger is typedef of Integer
********************************************************************************/
class NonNegativeIntegerItem : public IntegerItem
{
  friend class BasicItemFactory;

protected:
  NonNegativeIntegerItem(const xqp_uinteger& aValue) : IntegerItem(aValue) {}

  NonNegativeIntegerItem() {}

public:
  xqp_uinteger getUnsignedIntegerValue() const { return theValue; }

  SchemaTypeCode getTypeCode() const { return XS_NON_NEGATIVE_INTEGER; }

  store::Item* getType() const;

  xqp_string show() const;
};


/*******************************************************************************
  class PositiveIntegerItem
********************************************************************************/
class PositiveIntegerItem : public  IntegerItem
{
  friend class BasicItemFactory;

protected:
  PositiveIntegerItem(const xqp_uinteger& aValue) : IntegerItem(aValue) { }

  PositiveIntegerItem() {}

public:
  xqp_uinteger getUnsignedIntegerValue() const { return theValue; }

  SchemaTypeCode getTypeCode() const { return XS_POSITIVE_INTEGER; }

  store::Item* getType() const;

  xqp_string show() const;
};


/*******************************************************************************
  class LongItemNaive
********************************************************************************/
class LongItem : public AtomicItem 
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xqp_long theValue;
  
protected:
  LongItem(xqp_long aValue) : theValue(aValue) {}

  LongItem() {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;
  
  xqp_long getLongValue() const { return theValue; }

  SchemaTypeCode getTypeCode() const { return XS_LONG; }

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
    catch (error::ZorbaError&)
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
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  bool isNaN() const { return false; }

  xqp_string show() const;
};


/*******************************************************************************
  class IntItem
********************************************************************************/
class IntItem : public AtomicItem
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  int32_t theValue;

protected:
  IntItem(xqp_int aValue) : theValue(aValue) {}

  IntItem() {}

public:
  bool isNaN() const { return false; }

  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_long getLongValue() const { return static_cast<xqp_long>(theValue); }

  int32_t getIntValue() const { return theValue; }
    
  SchemaTypeCode getTypeCode() const { return XS_INT; }

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
    catch (error::ZorbaError&)
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
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class ShortItem
********************************************************************************/  
class ShortItem : public AtomicItem 
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xqp_short theValue;

protected:
  ShortItem(xqp_short aValue)  : theValue(aValue) {}

  ShortItem() {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_long getLongValue() const { return static_cast<xqp_long>(theValue); }

  xqp_int getIntValue() const { return static_cast<xqp_int>(theValue); }

  xqp_short getShortValue() const { return theValue; }
  
  SchemaTypeCode getTypeCode() const { return XS_SHORT; }

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
    catch (error::ZorbaError&)
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
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;

  bool isNaN() const { return false; }
};


/*******************************************************************************
  class ByteItemNaive
********************************************************************************/
class ByteItem : public AtomicItem 
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xqp_byte theValue;

protected:  
  ByteItem(xqp_byte aValue) : theValue(aValue) {}

  ByteItem() {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_long getLongValue() const { return static_cast<xqp_long>(theValue); }

  xqp_int getIntValue() const { return static_cast<xqp_int>(theValue); }

  xqp_short getShortValue() const { return static_cast<xqp_short>(theValue); }
  
  xqp_byte getByteValue() const { return theValue; }

  SchemaTypeCode getTypeCode() const { return XS_BYTE; }

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
    catch (error::ZorbaError&)
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
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  bool isNaN() const { return false; }

  xqp_string show() const;
};


/*******************************************************************************
  class UnsignedLongItem
********************************************************************************/
class UnsignedLongItem : public AtomicItem 
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xqp_ulong theValue;
  
protected:
  UnsignedLongItem(xqp_ulong aValue) : theValue(aValue) {}

  UnsignedLongItem() {}

 public:
  bool isNaN() const { return false; }

  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_uinteger getUnsignedIntegerValue() const;

  xqp_ulong getUnsignedLongValue() const { return theValue; }
  
  SchemaTypeCode getTypeCode() const { return XS_UNSIGNED_LONG; }

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
    catch (error::ZorbaError&)
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
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class UnsignedIntItem
********************************************************************************/
class UnsignedIntItem : public AtomicItem 
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xqp_uint theValue;
  
protected:
  UnsignedIntItem(xqp_uint aValue) : theValue(aValue) {}

  UnsignedIntItem() {}

public:
  bool isNaN() const { return false; }

  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_uinteger getUnsignedIntegerValue() const;

  xqp_long getLongValue() const { return static_cast<xqp_long>(theValue); }

  xqp_ulong getUnsignedLongValue() const { return static_cast<xqp_ulong>(theValue); }

  xqp_uint getUnsignedIntValue() const { return theValue; }
  
  SchemaTypeCode getTypeCode() const { return XS_UNSIGNED_INT; }

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
    catch (error::ZorbaError&)
    {
      try
      {
        return getLongValue() == other->getLongValue();
      }
      catch (error::ZorbaError&)
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
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;
 
  xqp_string show() const;
};


/*******************************************************************************
  class UnsignedShortItem
********************************************************************************/
class UnsignedShortItem : public AtomicItem 
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xqp_ushort theValue;
  
protected:
  UnsignedShortItem(xqp_ushort aValue) : theValue(aValue) {}

  UnsignedShortItem() {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_uinteger getUnsignedIntegerValue() const;

  xqp_long getLongValue() const { return static_cast<xqp_long>(theValue); }

  xqp_ulong getUnsignedLongValue() const { return static_cast<xqp_ulong>(theValue); }

  xqp_uint getUnsignedIntValue() const { return static_cast<xqp_uint>(theValue); }
  
  xqp_ushort getUnsignedShortValue() const { return theValue; }

  bool isNaN() const { return false; }

  SchemaTypeCode getTypeCode() const { return XS_UNSIGNED_SHORT; }

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
    catch (error::ZorbaError&)
    {
      try
      {
        return getLongValue() == other->getLongValue();
      }
      catch (error::ZorbaError&)
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
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class UnsignedByteItem
********************************************************************************/
class UnsignedByteItem : public AtomicItem 
{
  friend class BasicItemFactory;
  friend class AtomicItem;

protected:
  xqp_ubyte theValue;

protected:
  UnsignedByteItem(xqp_ubyte aValue) : theValue(aValue) {}

  UnsignedByteItem() : theValue(0) {}

public:
  xqp_decimal getDecimalValue() const;

  xqp_integer getIntegerValue() const;

  xqp_uinteger getUnsignedIntegerValue() const;

  xqp_long getLongValue() const { return static_cast<xqp_long>(theValue); }

  xqp_ulong getUnsignedLongValue() const { return static_cast<xqp_ulong>(theValue); }

  xqp_uint getUnsignedIntValue() const { return static_cast<xqp_uint>(theValue); }

  xqp_ushort getUnsignedShortValue() const { return static_cast<xqp_ushort>(theValue); }
  
  xqp_ubyte getUnsignedByteValue() const { return theValue; }

  bool isNaN() const { return false; }

  SchemaTypeCode getTypeCode() const { return XS_UNSIGNED_BYTE; }

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
    catch (error::ZorbaError&)
    {
      try
      {
        return getLongValue() == other->getLongValue();
      }
      catch (error::ZorbaError&)
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
    catch (error::ZorbaError&)
    {
      return getDecimalValue().compare(other->getDecimalValue());
    }
  }

  store::Item_t getEBV() const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class BooleanItem
********************************************************************************/
class BooleanItemNaive : public AtomicItem
{
protected:
  xqp_boolean theValue;

  // make sure that only created by the factory
  friend class BasicItemFactory;
  BooleanItemNaive(xqp_boolean aValue) : theValue(aValue) {}

  BooleanItemNaive() {}

public:
  xqp_boolean getBooleanValue() const { return theValue; }

  SchemaTypeCode getTypeCode() const { return XS_BOOLEAN; }

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

  store::Item_t getEBV( ) const;

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};
  

/*******************************************************************************
  class Base64BinaryItemNaive
********************************************************************************/
class Base64BinaryItemNaive : public AtomicItem 
{
  friend class BasicItemFactory;

protected:
  xqp_base64Binary theValue;

protected:
  Base64BinaryItemNaive(xqp_base64Binary aValue) : theValue(aValue) {}

  Base64BinaryItemNaive() {}

public:
  xqp_base64Binary getBase64BinaryValue() const { return theValue; }

  SchemaTypeCode getTypeCode() const { return XS_BASE64BINARY; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0 ) const
  {
    return theValue.equal(other->getBase64BinaryValue());
  }

  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
};


/*******************************************************************************
  class HexBinaryItemNaive
********************************************************************************/
class HexBinaryItemNaive : public AtomicItem 
{
  friend class BasicItemFactory;

protected:
  xqp_hexBinary theValue;

protected:
  HexBinaryItemNaive(xqp_hexBinary aValue) : theValue(aValue) {}

  HexBinaryItemNaive() {}

public:
  xqp_hexBinary getHexBinaryValue() const { return theValue; }

  SchemaTypeCode getTypeCode() const { return XS_HEXBINARY; }

  store::Item* getType() const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* aCollation = 0 ) const
  {
    return theValue.equal(other->getHexBinaryValue());
  }
  
  xqpStringStore_t getStringValue() const;
  void getStringValue(xqpStringStore_t& strval) const;
  void getStringValue(std::string& buf) const;

  xqp_string show() const;
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
class ErrorItemNaive : public AtomicItem 
{
  friend class BasicItemFactory;

protected:
  error::ZorbaError * theError;

protected:
  ErrorItemNaive(error::ZorbaError* error) : theError(error) {}

public:
  ~ErrorItemNaive();

  bool isError() const  { return true; }

  error::ZorbaError* getError() const { return theError; }

  SchemaTypeCode getTypeCode() const { return ZXSE_ERROR; }

  xqp_string show() const;

protected:
  // Disable copy
  ErrorItemNaive(const ErrorItemNaive& other);
  ErrorItemNaive& operator=(const ErrorItemNaive& other);
};

} // namespace simplestore
} // namespace zorba
#endif /* ZORBA_STORE_ATOMIC_ITEMS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
 /* vim:set et sw=2 ts=2: */
