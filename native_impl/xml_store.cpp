/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_store.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 */

#include "xml_store.h"

namespace xqp {

///////////////////////////////
// child_iterator
///////////////////////////////

item& child_iterator::operator*() const
{
 	 
}
  
item* child_iterator::operator->() const
{
}
  
item& child_iterator::operator[](uint32_t)
{
}
    
child_iterator& child_iterator::operator++()
{
}
  
child_iterator child_iterator::operator++(int)
{
}
  
child_iterator& child_iterator::operator--()
{
}
  
child_iterator child_iterator::operator--(int)
{
}
  
child_iterator::child_iterator(
  storage_manager& _store,
  loc _loc)
:
  store(_store),
  curr(_loc)
{
  
}

child_iterator::~child_iterator()
{
}



}
