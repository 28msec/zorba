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

#include <zorba/item.h>
#include <zorba/zorba_string.h>
#include <zorba/zorba_exception.h>
#include <zorba/diagnostic_handler.h>

#include "zorbautils/lock.h"
#include "diagnostics/xquery_diagnostics.h"

#include "system/globalenv.h"

#include "api/zorbaimpl.h"
#include "api/serialization/serializer.h"
#include "api/storeiteratorimpl.h"
#include "api/iterator_singleton.h"
#include "api/unmarshaller.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/iterator.h"
#include "store/api/collection.h"


namespace zorba {

#define ITEM_TRY try {

#define ITEM_CATCH \
  } catch (ZorbaException const & /* e */) { \
    throw; \
  } catch (std::exception const &e) { \
    throw ZORBA_EXCEPTION(zerr::ZXQP0003_INTERNAL_ERROR, ERROR_PARAMS(e.what())); \
  } catch (...) { \
    throw ZORBA_EXCEPTION(zerr::ZXQP0003_INTERNAL_ERROR); \
  }


Item::Item(const store::Item* other)
  :
  m_item(const_cast<store::Item*>(other))
{
  if (!isNull())
  {
    m_item->addReference();
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
  if (!isNull())
  {
    m_item->addReference();
  }
}


Item::~Item()
{
  close();
}


void
Item::close()
{
  if (!isNull())
  {
    m_item->removeReference();
    m_item = NULL;
  }
}


const Item& Item::operator =(const Item& rhs)
{
  if (m_item != rhs.m_item)
  {
    close();
    m_item = rhs.m_item;
    if (!isNull())
    {
      m_item->addReference();
    }
  }
  return *this;
}


const Item& Item::operator =(const store::Item* rhs)
{
  if (m_item != rhs)
  {
    close();
    m_item = const_cast<store::Item*>(rhs);
    if (!isNull())
    {
      m_item->addReference();
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


bool
Item::isNull() const
{
  ITEM_TRY
    return m_item == NULL;
  ITEM_CATCH
  return false;
}

store::SchemaTypeCode
Item::getTypeCode() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getTypeCode();

  ITEM_CATCH
    return store::XS_ANY_ATOMIC;
}

Item Item::getType() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return &*m_item->getType();

  ITEM_CATCH
  return Item();
}

#ifdef ZORBA_WITH_JSON

bool
Item::isJSONItem() const
{
  ITEM_TRY
    return m_item->isJSONItem();
  ITEM_CATCH
  return false;
}

#endif /* ZORBA_WITH_JSON */

Iterator_t Item::getAtomizationValue() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    store::Item_t typedVal;
    store::Iterator_t typedIter;

    m_item->getTypedValue(typedVal, typedIter);

    if (typedIter == NULL)
    {
      return new API_SingletonIterator(typedVal, NULL);
    }
    else
    {
      return new StoreIteratorImpl(typedIter, NULL);
    }

  ITEM_CATCH
  return NULL;
}


String Item::getStringValue() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getStringValue().str();

  ITEM_CATCH
  return String((const char*)0);
}

int32_t Item::getIntValue() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getIntValue();

  ITEM_CATCH
  return 0;
}

uint32_t Item::getUnsignedIntValue() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getUnsignedIntValue();

  ITEM_CATCH
  return 0;
}

double Item::getDoubleValue() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getDoubleValue().getNumber();

  ITEM_CATCH
  return 0;
}


xs_long Item::getLongValue() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getLongValue();

  ITEM_CATCH
  return 0;

}


Item Item::getEBV() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    bool value = m_item->getEBV();

    store::Item_t result;
    GENV_ITEMFACTORY->createBoolean(result, value);

    return result.getp();

  ITEM_CATCH
  return Item();
}


/** QName Item */
String Item::getPrefix() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getPrefix().str();

  ITEM_CATCH
  return "";
}


String Item::getLocalName() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getLocalName().str();

  ITEM_CATCH
  return "";
}


String Item::getNamespace() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getNamespace().str();

  ITEM_CATCH
  return "";
}

/** Numeric Items */

bool Item::isNaN() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->isNaN();

  ITEM_CATCH
  return false;
}


// @return true, if containing numbers represents -INF or +INF
bool Item::isPosOrNegInf() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->isPosOrNegInf();

  ITEM_CATCH
  return false;
}


/** Boolean Items */
bool
Item::getBooleanValue() const
{
  ITEM_TRY

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getBooleanValue();

  ITEM_CATCH
  return false;
}

/** Node Items */
Iterator_t
Item::getChildren() const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    // TODO, we should have an error handler here
    return new StoreIteratorImpl(m_item->getChildren(), 0);

  ITEM_CATCH
  return NULL;
}

Iterator_t
Item::getAttributes() const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    // TODO, we should have an error handler here
    return new StoreIteratorImpl(m_item->getAttributes(), 0);

  ITEM_CATCH
  return NULL;
}

void
Item::getNamespaceBindings(NsBindings& aBindings,
                           store::StoreConsts::NsScoping aNsScoping) const
{
  ITEM_TRY
      SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

      store::NsBindings lStoreBindings;
      m_item->getNamespaceBindings(lStoreBindings, aNsScoping);
      aBindings.reserve(aBindings.size() + lStoreBindings.size());

      store::NsBindings::iterator ite = lStoreBindings.begin();
      store::NsBindings::iterator end = lStoreBindings.end();
      for (; ite != end; ++ite) {
        zstring& prefix = ite->first;
        zstring& nsuri = ite->second;
        aBindings.push_back(
            std::pair<String, String>(
              Unmarshaller::newString(prefix),
              Unmarshaller::newString(nsuri))
          );
      }

  ITEM_CATCH
}

Item
Item::getParent() const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)
    return &*m_item->getParent();
  ITEM_CATCH
  return Item();
}

bool
Item::getNodeName(Item& aNodeName) const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    store::Item* lNodeName = m_item->getNodeName();

    aNodeName = lNodeName;
    return true;

  ITEM_CATCH
  return false;
}

int
Item::getNodeKind() const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getNodeKind();
  ITEM_CATCH
  return -1;
}

#ifdef ZORBA_WITH_JSON

store::StoreConsts::JSONItemKind
Item::getJSONItemKind() const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getJSONItemKind();
  ITEM_CATCH
  return store::StoreConsts::jsonItem;
}

Iterator_t
Item::getArrayMembers() const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    // TODO, we should have an error handler here
    return new StoreIteratorImpl(m_item->getMembers(), nullptr);

  ITEM_CATCH
  return NULL;
}

Item
Item::getObjectValue(String aName) const
{
  zstring& lName = Unmarshaller::getInternalString(aName);
  store::Item_t lIndex;
  if (!GENV_ITEMFACTORY->createString(lIndex, lName)) {
    // QQQ probably should throw exception here
    return Item();
  }
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ););
  store::Item_t lPair = m_item->getPair(lIndex);
  if (lPair.isNull()) {
    return Item();
  }
  return &*lPair->getValue();
  ITEM_CATCH
  return Item();
}

Item
Item::getArrayMember(uint32_t aIndex) const
{
  store::Item_t lIndex;
  if (!GENV_ITEMFACTORY->createInteger(lIndex, Integer(aIndex))) {
    // QQQ probably should throw exception here
    return Item();
  }
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)
      return &*m_item->getMember(lIndex);
  ITEM_CATCH
  return Item();
}

#endif /* ZORBA_WITH_JSON */

bool
Item::isStreamable() const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->isStreamable();
  ITEM_CATCH
  return false;
}

bool
Item::isSeekable() const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->isSeekable();
  ITEM_CATCH
  return false;
}

std::istream&
Item::getStream()
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getStream();
  ITEM_CATCH
  // TODO: throw exception
}

bool
Item::isEncoded() const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->isEncoded();
  ITEM_CATCH
  // TODO: throw exception
}

const char*
Item::getBase64BinaryValue(size_t& s) const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    return m_item->getBase64BinaryValue(s);
  ITEM_CATCH
  // TODO: throw exception
}


Item
Item::getCollectionName() const
{
  ITEM_TRY
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    if (!m_item->isNode()) {
      return 0;
    }
    const store::Collection* lColl = m_item->getCollection();
    if (lColl) {
      return lColl->getName();
    } else {
      return 0;
    }
  ITEM_CATCH
  return 0;
}
} // namespace zorba
/* vim:set et sw=2 ts=2: */
