#include <zorba/item.h>
#include <zorba/zorbastring.h>
#include <zorba/exception.h>
#include <zorba/default_error_handler.h>
#include "api/serialization/serializer.h"
#include "errors/error_manager.h"
#include "errors/errors.h"
#include "util/rchandle.h"
#include "api/zorbaimpl.h"
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
  } catch (std::exception& e) { \
    throw SystemException(ZorbaError::XQP0019_INTERNAL_ERROR, e.what()); \
  } catch (...) { \
    throw SystemException(ZorbaError::XQP0019_INTERNAL_ERROR, "Internal error"); \
  } 


Item Item::getAtomizationValue() const
{
  return &*m_item->getAtomizationValue();
}

String Item::getStringValue() const
{
  return m_item->getStringValue().getp();
}

void Item::serialize(std::ostream& os) const
{
  try {
    error::ErrorManager lErrorManger;
    serializer lSerializer(&lErrorManger);
    lSerializer.set_parameter("omit-xml-declaration", "yes");
    m_item->serializeXML(lSerializer, os);
  } catch (::zorba::error::ZorbaError& e) {
    DefaultErrorHandler lErrorHandler;
    ZorbaImpl::notifyError(&lErrorHandler, e);
  } catch (std::exception& e) {
    DefaultErrorHandler lErrorHandler;
    ZorbaImpl::notifyError(&lErrorHandler, e.what());
  } catch (...) {
    DefaultErrorHandler lErrorHandler;
    ZorbaImpl::notifyError(&lErrorHandler, "Internal error");
  }
}

Item Item::getEBV() const
{
  ITEM_TRY
    return &*m_item->getEBV();
  ITEM_CATCH
  return Item();
}

bool Item::isNode() const
{
  ITEM_TRY
    return m_item->isNode();
  ITEM_CATCH
  return false;
}

bool Item::isAtomic() const
{
  ITEM_TRY
    return m_item->isAtomic();
  ITEM_CATCH
  return false;
}

bool Item::isNull() const
{
  ITEM_TRY
    return m_item == NULL;
  ITEM_CATCH
  return false;
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
    return m_item->getPrefix();
  ITEM_CATCH
  return "";
}

String Item::getLocalName() const
{
  ITEM_TRY
    return m_item->getLocalName();
  ITEM_CATCH
  return "";
}

String Item::getNamespace() const
{
  ITEM_TRY
    return m_item->getNamespace();
  ITEM_CATCH
  return "";
}

/** Numeric Items */

bool Item::isNaN() const
{
  ITEM_TRY
    return m_item->isNaN();
  ITEM_CATCH
  return false;
}

// @return true, if containing numbers represents -INF or +INF
bool Item::isPosOrNegInf() const
{
  ITEM_TRY
    return m_item->isPosOrNegInf();
  ITEM_CATCH
  return false;
}

/** Boolean Items */
bool
Item::getBooleanValue() const
{
  ITEM_TRY
    return m_item->getBooleanValue();
  ITEM_CATCH
  return false;
}

}
