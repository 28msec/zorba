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
#include "stdafx.h"

#include "capi/csequence.h"

#include <cassert>
#include <string.h>

#include <zorba/zorba.h>
#include <zorba/diagnostic_list.h>
#include <zorba/iterator.h>
#include <zorba/store_consts.h>
#include <zorbamisc/ns_consts.h>
#include <zorbatypes/numconversions.h>

#include "error.h"

using namespace zorba;

#define SEQ_TRY CAPI_TRY(CSequence,seq)
#define SEQ_CATCH CAPI_CATCH

namespace zorbac {

/**
 * Utility class to turn an ItemSequence into an Iterator.
 * Performs no memory-management on the ItemSequence it
 * holds!
 */
class ItemSequenceWrapper : public Iterator
{
public:
  ItemSequenceWrapper(ItemSequence* items)
    :
  theItems(items),
  theIterator(items->getIterator())
  {
  }
  
  virtual ~ItemSequenceWrapper()
  {
  //  delete theIterator;
  }

  virtual void open() {theIterator->open();}

  virtual void close() {theIterator->close();}
  
  virtual bool next(Item& item)
  {
    return theIterator->next(item);
  }

  bool isOpen() const { return theIterator->isOpen(); }

protected:
  ItemSequence *theItems;
  Iterator_t theIterator;
};


/**
 * Subclass of ItemSequenceWrapper which will delete the
 * ItemSequence it holds when it is destroyed.
 */
class FreeingItemSequenceWrapper : public ItemSequenceWrapper
{
public:
  FreeingItemSequenceWrapper(ItemSequence* items)
    :
    ItemSequenceWrapper(items)
  {
  }

  virtual ~FreeingItemSequenceWrapper()
  {
    delete theItems;
  }
};


CSequence::CSequence(Iterator_t iter, XQC_ErrorHandler* handler)
  :
  theIterator(iter),
  theIsOpen(false),
  theErrorHandler(handler)
{
  init_xqc();
}


/**
 * Create a CSequence around an ItemSequence.
 * @param free_when_done If true, the ItemSequence will be deleted
 * when the CSequence is deleted. If false, the ItemSequence will
 * never be deleted; client code must arrange to free it at an
 * appropriate time.
 */
CSequence::CSequence(
    ItemSequence* items,
    bool free_when_done,
    XQC_ErrorHandler* handler)
  :
  theIsOpen(false),
  theErrorHandler(handler)
{
  theIterator = Iterator_t(free_when_done ?
                           new FreeingItemSequenceWrapper(items) :
                           new ItemSequenceWrapper(items));
  init_xqc();
}


CSequence::~CSequence()
{
  if (theIterator.get() && theIsOpen) {
    theIterator.get()->close();
  }
}


void CSequence::init_xqc()
{
  memset(&theXQCSeq, 0, sizeof (XQC_Sequence));
  theXQCSeq.next = CSequence::next;
  theXQCSeq.item_type = CSequence::item_type;
  theXQCSeq.type_name = CSequence::type_name;
  theXQCSeq.string_value = CSequence::string_value;
  theXQCSeq.integer_value = CSequence::integer_value;
  theXQCSeq.double_value = CSequence::double_value;
  theXQCSeq.node_name = CSequence::node_name;
  theXQCSeq.get_interface = CSequence::get_interface;
  theXQCSeq.free = CSequence::free;
}


Iterator_t
CSequence::getCPPIterator()
{
  return theIterator;
}


Item
CSequence::getCPPItem()
{
  return theItem;
}


XQC_Sequence*
CSequence::getXQC()
{
  return &theXQCSeq;
}


CSequence*
CSequence::get(const XQC_Sequence* xqc)
{
  return (CSequence*)
    (((char*)xqc) - CLASS_OFFSET(CSequence, theXQCSeq));
}


XQC_Error
CSequence::next(XQC_Sequence* seq)
{
  SEQ_TRY 
  {
    me->theStrings.clear();
  
    Iterator_t lIter = me->getCPPIterator();

    if (!me->theIsOpen)
    {
      lIter->open();
      me->theIsOpen = true;
    }

    if ( ! lIter->next(me->theItem) ) {
      return XQC_END_OF_SEQUENCE;
    }
  }
  SEQ_CATCH;
}


XQC_Error
CSequence::item_type(const XQC_Sequence* seq, XQC_ItemType* type)
{
  SEQ_TRY {
    Item lItem = me->theItem;
    if (lItem.isNull()) {
      return XQC_NO_CURRENT_ITEM;
    }
    
    XQC_ItemType lRetval;
    if (lItem.isNode()) {
      switch (lItem.getNodeKind()) {
      case store::StoreConsts::documentNode:
        lRetval = XQC_DOCUMENT_TYPE;
        break;
      case store::StoreConsts::elementNode:
        lRetval = XQC_ELEMENT_TYPE;
        break;
      case store::StoreConsts::attributeNode:
        lRetval = XQC_ATTRIBUTE_TYPE;
        break;
      case store::StoreConsts::textNode:
        lRetval = XQC_TEXT_TYPE;
        break;
      case store::StoreConsts::piNode:
        lRetval = XQC_PROCESSING_INSTRUCTION_TYPE;
        break;
      case store::StoreConsts::commentNode:
        lRetval = XQC_NAMESPACE_TYPE;
        break;
      default:
        return XQC_INTERNAL_ERROR;
      }
    }
    else /* not isNode() */ {
      Item lType = lItem.getType();
      zorba::String lUri = lType.getNamespace();
      if (lUri != XML_SCHEMA_NS) {
        // We can only identify non-derived atomic types
        return XQC_INTERNAL_ERROR;
      }
      zorba::String lName = lType.getLocalName();
      if (lName == "anySimpleType") {
        lRetval = XQC_ANY_SIMPLE_TYPE;
      }
      else if (lName == "anyURI") {
        lRetval = XQC_ANY_URI_TYPE;
      }
      else if (lName == "anyURI") {
        lRetval = XQC_ANY_URI_TYPE;
      }
      else if (lName == "base64Binary") {
        lRetval = XQC_BASE_64_BINARY_TYPE;
      }
      else if (lName == "boolean") {
        lRetval = XQC_BOOLEAN_TYPE;
      }
      else if (lName == "date") {
        lRetval = XQC_DATE_TYPE;
      }
      else if (lName == "dateTime") {
        lRetval = XQC_DATE_TIME_TYPE;
      }
      else if (lName == "dayTimeDuration") {
        lRetval = XQC_DAY_TIME_DURATION_TYPE;
      }
      // All these built-in types derive from decimal
      else if ( (lName == "decimal") || (lName == "integer") ||
                (lName == "int") || (lName == "long") || (lName == "short") ||
                (lName == "byte") || (lName == "nonNegativeInteger") ||
                (lName == "negativeInteger") || (lName == "nonPositiveInteger") ||
                (lName == "positiveInteger") || (lName == "unsignedLong") ||
                (lName == "unsignedInt") || (lName == "unsignedShort") ||
                (lName == "unsignedByte") ) {         
        lRetval = XQC_DECIMAL_TYPE;
      }
      else if (lName == "double") {
        lRetval = XQC_DOUBLE_TYPE;
      }
      else if (lName == "duration") {
        lRetval = XQC_DURATION_TYPE;
      }
      else if (lName == "float") {
        lRetval = XQC_FLOAT_TYPE;
      }
      else if (lName == "gDay") {
        lRetval = XQC_G_DAY_TYPE;
      }
      else if (lName == "gMonth") {
        lRetval = XQC_G_MONTH_TYPE;
      }
      else if (lName == "gMonthDay") {
        lRetval = XQC_G_MONTH_DAY_TYPE;
      }
      else if (lName == "gYear") {
        lRetval = XQC_G_YEAR_TYPE;
      }
      else if (lName == "gYearMonth") {
        lRetval = XQC_G_YEAR_MONTH_TYPE;
      }
      else if (lName == "hexBinary") {
        lRetval = XQC_HEX_BINARY_TYPE;
      }
      else if (lName == "NOTATION") {
        lRetval = XQC_NOTATION_TYPE;
      }
      else if (lName == "QName") {
        lRetval = XQC_QNAME_TYPE;
      }
      // All these types are derived from xs:string
      else if ( (lName == "string") || (lName == "normalizedString") ||
                (lName == "token") || (lName == "language") ||
                (lName == "Name") || (lName == "NCName") ||
                (lName == "ENTITY") || (lName == "ENTITIES") ||
                (lName == "ID") || (lName == "IDREF") || (lName == "IDREF") ||
                (lName == "NMTOKEN") || (lName == "NMTOKENS") ) {
        lRetval = XQC_STRING_TYPE;
      }
      else if (lName == "time") {
        lRetval = XQC_TIME_TYPE;
      }
      else if (lName == "untypedAtomic") {
        lRetval = XQC_UNTYPED_ATOMIC_TYPE;
      }
      else if (lName == "yearMonthDuragion") {
        lRetval = XQC_YEAR_MONTH_DURATION_TYPE;
      }
      else {
        // Anything else, there's no XQC_ItemType for.
        return XQC_INTERNAL_ERROR;
      }
      
      (*type) = lRetval;
    }
  }
  SEQ_CATCH;
}


XQC_Error
CSequence::type_name(const XQC_Sequence* seq, const char** uri, const char** name)
{
  SEQ_TRY {
    Item lItem = me->theItem.getType();
    zorba::String lUri = lItem.getNamespace();
    me->theStrings.push_back(lUri);
    zorba::String lLocal = lItem.getLocalName();
    me->theStrings.push_back(lLocal);
    (*uri) = lUri.c_str();
    (*name) = lLocal.c_str();
  }
  SEQ_CATCH;
}


XQC_Error
CSequence::string_value(const XQC_Sequence* seq, const char** value)
{
  SEQ_TRY {
    if (me->theItem.isNull()) {
      return XQC_NO_CURRENT_ITEM;
    }
    zorba::String lString = me->theItem.getStringValue();
    me->theStrings.push_back(lString);
    (*value) = lString.c_str();
  }
  SEQ_CATCH;
}
  
  
XQC_Error
CSequence::integer_value(const XQC_Sequence* seq, int* value)
{
  SEQ_TRY {
    if (me->theItem.isNull()) {
      return XQC_NO_CURRENT_ITEM;
    }
    try {
      (*value) = static_cast<int> (me->theItem.getIntValue());
    }
    catch (ZorbaException const &qe) {
      // TODO test case for this conversion
      // The store API only supports getIntValue() for xs:int and
      // derivative types. For other types, we attempt to convert
      // the string value to an int manually.
      if (qe.diagnostic() == zerr::ZSTR0040_TYPE_ERROR) {
        // Note: The return value of getStringValue() is a
        // reference-counted object. The return value of c_str() is
        // a pointer to internals of this reference-counted
        // object. Thus, it is critical that we keep the
        // lStringValue reference alive until we are done with the
        // const char*, or else the const char* will point to
        // de-allocated memory.
        String lStringValue = me->theItem.getStringValue();
        try {
          xs_int const intvalue = ztd::aton<xs_int>(lStringValue.c_str());
          *value = static_cast<int>(intvalue);
        }
        catch ( std::exception const& ) {
          return XQC_TYPE_ERROR;
        }
      }
      else {
        throw;
      }
    }
  }
  SEQ_CATCH;
}


XQC_Error
CSequence::double_value(const XQC_Sequence* seq, double* value)
{
  SEQ_TRY {
    if (me->theItem.isNull()) {
      return XQC_NO_CURRENT_ITEM;
    }
    try {
      (*value) = static_cast<double>(me->theItem.getDoubleValue());
    }
    catch (ZorbaException const &qe) {
      // TODO test case for this conversion
      // The store API only supports getDoubleValue() for xs:double
      // and derivative types. For other types, we attempt to
      // convert the string value to a double manually.
      if (qe.diagnostic() == zerr::ZSTR0040_TYPE_ERROR) {
        // Note: The return value of getStringValue() is a
        // reference-counted object. The return value of c_str() is
        // a pointer to internals of this reference-counted
        // object. Thus, it is critical that we keep the
        // lStringValue reference alive until we are done with the
        // const char*, or else the const char* will point to
        // de-allocated memory.
        try {
          String const lStringValue = me->theItem.getStringValue();
          xs_double const doublevalue( lStringValue.c_str() );
          (*value) = static_cast<double> (doublevalue.getNumber());
        }
        catch ( std::exception const& ) {
          return XQC_TYPE_ERROR;
        }
      }
      else {
        throw;
      }
    }
  }
  SEQ_CATCH;
}
  
  
XQC_Error
CSequence::node_name(const XQC_Sequence* seq, const char** uri, const char** name)
{
  SEQ_TRY {
    Item lItem = me->theItem;
    if (lItem.isNull()) {
      return XQC_NO_CURRENT_ITEM;
    }
    if ( ! lItem.isNode() ) {
      return XQC_NOT_NODE;
    }
    std::auto_ptr<Item> lNodeName(new Item());
    if ( ! lItem.getNodeName(*lNodeName) ) {
      return XQC_INTERNAL_ERROR;
    }
    zorba::String lUri = lNodeName->getNamespace();
    me->theStrings.push_back(lUri);
    zorba::String lName = lNodeName->getLocalName();
    me->theStrings.push_back(lName);
    (*uri) = lUri.c_str();
    (*name) = lName.c_str();
  }
  SEQ_CATCH;
}

  
void *
CSequence::get_interface(const XQC_Sequence* impl, const char *name)
{
  // No custom interfaces
  return NULL;
}


void
CSequence::free(XQC_Sequence* seq)
{
  try {
    CSequence* me = CSequence::get(seq);
    delete me;
  } catch (ZorbaException const&) {
    assert(false);
  } catch (...) {
    assert(false);
  }
}
  
} /* namespace zorbac */
/* vim:set et sw=2 ts=2: */
