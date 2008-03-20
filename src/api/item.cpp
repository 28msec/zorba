#include <zorba/item.h>
#include <zorba/string.h>
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
  if (!isNull()) {
    RCHelper::removeReference(m_item);
  }
}

const Item& Item::operator =(const Item& rhs)
{
  if (m_item != rhs.m_item) {
    if (!isNull()) {
      RCHelper::removeReference(m_item);
    }
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
    if (!isNull()) {
      RCHelper::removeReference(m_item);
    }
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

Item Item::getAtomizationValue() const
{
  return &*m_item->getAtomizationValue();
}

String Item::getStringValue() const
{
  return &*m_item->getStringValue().theStrStore;
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

}
