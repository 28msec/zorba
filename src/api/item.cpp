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
#include <zorba/item.h>
#include <zorba/zorbastring.h>
#include <zorba/exception.h>
#include <zorba/default_error_handler.h>

#include "zorbautils/lock.h"
#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/errors.h"

#include "system/globalenv.h"

#include "api/zorbaimpl.h"
#include "api/serialization/serializer.h"

#include "store/api/item.h"
#include "store/api/store.h"


namespace zorba {

#define ITEM_TRY try {
#define ITEM_CATCH } catch ( ::zorba::error::ZorbaError & e) {  \
  throw SystemException(e.theErrorCode, String(e.theDescription.theStrStore), "", 0); \
  } catch (std::exception& e) { \
    throw SystemException(XQP0019_INTERNAL_ERROR, e.what(), "", 0); \
  } catch (...) { \
    throw SystemException(XQP0019_INTERNAL_ERROR, "Internal error", "", 0); \
  } 


Item::Item(store::Item *other)
  :
  m_item(other)
{
  if (!isNull()) {
    RCHelper::addReference(m_item);
  }
}


Item::Item()
  :
  m_item(NULL)
{
}


Item::Item(const Item& other)
  :
  m_item(other.m_item)
{
  if (!isNull()) {
    RCHelper::addReference(m_item);
  }
}


Item::~Item()
{
  close();
}


void
Item::close()
{
  if (!isNull()) {
    RCHelper::removeReference(m_item);
    m_item = NULL;
  }
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


bool 
Item::isNode() const
{
  ITEM_TRY
    return m_item->isNode();
  ITEM_CATCH
  return false;
}


bool 
Item::isAtomic() const
{
  ITEM_TRY
    return m_item->isAtomic();
  ITEM_CATCH
  return false;
}

#if 0
bool
Item::isNumeric() const
{
  ITEM_TRY
    return m_item->isNumeric();
  ITEM_CATCH
  return false;
}
#endif

bool 
Item::isNull() const
{
  ITEM_TRY
    return m_item == NULL;
  ITEM_CATCH
  return false;
}


Item Item::getType() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return &*m_item->getType();

  ITEM_CATCH
  return Item();
}


Item Item::getAtomizationValue() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return &*m_item->getAtomizationValue();

  ITEM_CATCH
  return Item();
}


String Item::getStringValue() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getStringValue().getp();

  ITEM_CATCH
  return String((const char*)0);
}


void Item::serialize(std::ostream& os) const
{
  SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

  try 
  {
    error::ErrorManager lErrorManger;
    serializer lSerializer(&lErrorManger);
    lSerializer.set_parameter("omit-xml-declaration", "yes");
    lSerializer.serialize(m_item, os);
  }
  catch (::zorba::error::ZorbaError& e) 
  {
    DefaultErrorHandler lErrorHandler;
    ZorbaImpl::notifyError(&lErrorHandler, e);
  }
  catch (std::exception& e) 
  {
    DefaultErrorHandler lErrorHandler;
    ZorbaImpl::notifyError(&lErrorHandler, e.what());
  }
  catch (...) 
  {
    DefaultErrorHandler lErrorHandler;
    ZorbaImpl::notifyError(&lErrorHandler, "Internal error");
  }
}


Item Item::getEBV() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return &*m_item->getEBV();

  ITEM_CATCH
  return Item();
}


/** QName Item */
String Item::getPrefix() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getPrefix();

  ITEM_CATCH
  return "";
}


String Item::getLocalName() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getLocalName();

  ITEM_CATCH
  return "";
}


String Item::getNamespace() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getNamespace();

  ITEM_CATCH
  return "";
}

/** Numeric Items */

bool Item::isNaN() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->isNaN();

  ITEM_CATCH
  return false;
}


// @return true, if containing numbers represents -INF or +INF
bool Item::isPosOrNegInf() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->isPosOrNegInf();

  ITEM_CATCH
  return false;
}


/** Boolean Items */
bool
Item::getBooleanValue() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getBooleanValue();

  ITEM_CATCH
  return false;
}

}
