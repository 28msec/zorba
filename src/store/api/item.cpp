/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

#include "store/api/item.h"

#include "errors/error_factory.h"

#include "system/zorba_engine.h"

#include "runtime/core/item_iterator.h"
#include "api/serialization/serializer.h"
#include "system/globalenv.h"
#include "types/typesystem.h"

namespace xqp
{

bool Item::isNumeric() const {
  TypeSystem::xqtref_t type = GENV_TYPESYSTEM.create_type(getType(), TypeSystem::QUANT_ONE);
  return GENV_TYPESYSTEM.is_numeric(*type);
}


xqp_string Item::show() const
{
  return  std::string ( typeid ( *this ).name() ) + ": 'show' not implemented!";
}
  /* end class Item */


void Item::serializeXML( ostream& os )
{
  serializer *ser;
  ser = ZORBA_FOR_CURRENT_THREAD()->getItemSerializer();
  
  ser->serialize(this, os);
}


/* begin class AtomicItem */
Item_t AtomicItem::getAtomizationValue() const
{
  Item* lItem = const_cast<AtomicItem *>(this);
  return lItem;
}


Iterator_t AtomicItem::getTypedValue() const
{
  PlanIter_t planIter = new SingletonIterator(ZORBA_FOR_CURRENT_THREAD()->GetCurrentLocation(), this->getAtomizationValue());
  return new PlanWrapper ( planIter );
}
/* end class AtomicItem */

}
