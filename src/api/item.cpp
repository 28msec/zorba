#include <zorba/item.h>
#include <zorba/zorbastring.h>
#include <zorba/exception.h>
#include "errors/errors.h"
#include "util/rchandle.h"
#include "store/api/item.h"

namespace zorba {

Item::Item(store::Item *other)
  : m_item(other)
{
  if (!isNull()) {
    RCHelper::addReference(m_item);
  }
}

Item::Item()
  : m_item(NULL) { }


Item::Item(const Item& other)
  : m_item(other.m_item)
{
  if (!isNull()) {
    RCHelper::addReference(m_item);
  }
}

Item::~Item()
{
  close();
}

const Item& Item::operator =(const Item& rhs)
{
  if (m_item != rhs.m_item) {
    close();
    m_item = rhs.m_item;
    if (!isNull()) {
      RCHelper::addReference(m_item);
    }
  }
  return *this;
}

const Item& Item::operator =(store::Item *rhs)
{
  if (m_item != rhs) {
    close();
    m_item = rhs;
    if (!isNull()) {
      RCHelper::addReference(m_item);
    }
  }
  return *this;
}

Item Item::getType() const
{
  return &*m_item->getType();
}

#define ITEM_TRY try {
#define ITEM_CATCH } catch (::zorba::error::ZorbaError &e) {  \
  throw SystemException(e.theErrorCode, String(e.theDescription.theStrStore)); \
  }


Item Item::getAtomizationValue() const
{
  return &*m_item->getAtomizationValue();
}

String Item::getStringValue() const
{
  return m_item->getStringValue().getp();
}

Item Item::getEBV() const
{
  return &*m_item->getEBV();
}

bool Item::isNode() const
{
  return m_item->isNode();
}

bool Item::isAtomic() const
{
  return m_item->isAtomic();
}

bool Item::isNull() const
{
  return m_item == NULL;
}

void
Item::close()
{
  if (!isNull()) {
    RCHelper::removeReference(m_item);
  }
}

/** QName Item */
String Item::getPrefix() const
{
  ITEM_TRY
    return m_item->getPrefix().theStrStore.getp();
  ITEM_CATCH
}

String Item::getLocalName() const
{
  ITEM_TRY
    return m_item->getLocalName().theStrStore.getp();
  ITEM_CATCH
}

String Item::getNamespace() const
{
  ITEM_TRY
    return m_item->getNamespace().theStrStore.getp();
  ITEM_CATCH
}

/** Numeric Items */

bool Item::isNaN() const
{
  ITEM_TRY
    return m_item->isNaN();
  ITEM_CATCH
}

// @return true, if containing numbers represents -INF or +INF
bool Item::isPosOrNegInf() const
{
  ITEM_TRY
    return m_item->isPosOrNegInf();
  ITEM_CATCH
}

/** Boolean Items */
bool
Item::getBooleanValue() const
{
  ITEM_TRY
    return m_item->getBooleanValue();
  ITEM_CATCH
}

}
