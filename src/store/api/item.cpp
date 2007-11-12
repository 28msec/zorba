/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

#include "item.h"

#include "errors/errors.h"
#include "errors/Error.h"
#include "util/hashfun.h"
#include "runtime/core/item_iterator.h"

namespace xqp
{
  Item::~Item() {}

  /* begin class Item */
  void Item::showError() const
  {
    ZorbaErrorAlerts::error_alert (
        error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
        error_messages::SYSTEM_ERROR,
        NULL
    );
  }

  xqp_string Item::show() const
  {
    return  std::string ( typeid ( *this ).name() ) + ": 'show' not implemented!";
  }

  qnamekey_t Item::createQNameKey ( xqp_string _namespace, xqp_string prefix, xqp_string localName )
  {
    return hashfun::h64 ( prefix,hashfun::h64 ( localName,hashfun::h64 ( _namespace ) ) );
  }
  /* end class Item */

  /* begin class AtomicItem */
  AtomicItem::~AtomicItem() {}
  bool AtomicItem::isNode() const
  {
    return false;
  }
  bool AtomicItem::isAtomic() const
  {
    return true;
  }

Iterator_t AtomicItem::getTypedValue() const
{
  PlanIter_t planIter = new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), this->getAtomizationValue() );
  return new PlanIterWrapper ( planIter );
}
/* end class AtomicItem */


/*******************************************************************************

********************************************************************************/
NodeItem::NodeItem(const Item_t& aParent) : theParent(&*aParent)
{
}


NodeItem::NodeItem() : theParent(0)
{
}


NodeItem::~NodeItem()
{
}


bool NodeItem::isNode() const
{
  return true;
}


bool NodeItem::isAtomic() const
{
  return false;
}


Item_t NodeItem::getEBV() const
{
  return zorba::getItemFactory()->createBoolean ( true );
}

uint32_t NodeItem::hash() const
{
  Assert(0);
  return 0;
}

bool NodeItem::equals ( Item_t item ) const
{
  ZorbaErrorAlerts::error_alert (
        error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
        error_messages::SYSTEM_ERROR,
        NULL,
        true,
        "Equal function for node items not implemented!"
    );
  return false;
}


TypeCode NodeItem::getType() const
{
  return xs_anyType;
}


Item_t NodeItem::getParent() const
{
  return theParent;
}

xqp_string NodeItem::getBaseURI() const
{
  return theParent ? theParent->getBaseURI() : "";
}

xqp_string NodeItem::getDocumentURI() const
{
  return theParent ? theParent->getDocumentURI() : "";
}

}
