/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

#include "store/api/item.h"

#include "errors/errors.h"
#include "errors/Error.h"
#include "runtime/core/item_iterator.h"
#include "api/serialization/serializer.h"

namespace xqp
{
  Item::~Item() {}

  /* begin class Item */
  void Item::showError() const
  {
    ZorbaErrorAlerts::error_alert (
        error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
        error_messages::SYSTEM_ERROR,
        NULL
    );
  }

  xqp_string Item::show() const
  {
    return  std::string ( typeid ( *this ).name() ) + ": 'show' not implemented!";
  }
  /* end class Item */

	void Item::serializeXML( ostream& os )
	{
		serializer *ser;
		ser = zorba::getZorbaForCurrentThread()->getItemSerializer();

		ser->serialize(this, os);
	}


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
  PlanIter_t planIter = new SingletonIterator(zorba::getZorbaForCurrentThread()->GetCurrentLocation(), this->getAtomizationValue());
  return new PlanWrapper ( planIter );
}
/* end class AtomicItem */

}
