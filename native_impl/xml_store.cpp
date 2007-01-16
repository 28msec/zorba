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
//	child_iterator
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
  nodeid _id)
:
  store(_store),
  id(_id)
{
}

child_iterator::~child_iterator()
{
}



///////////////////////////////
//	attr_iterator
///////////////////////////////

item& attr_iterator::operator*() const
{
}
  
item* attr_iterator::operator->() const
{
}
  
item& attr_iterator::operator[](uint32_t)
{
}
    
attr_iterator& attr_iterator::operator++()
{
}
  
attr_iterator attr_iterator::operator++(int)
{
}
  
attr_iterator& attr_iterator::operator--()
{
}
  
attr_iterator attr_iterator::operator--(int)
{
}
  
attr_iterator::attr_iterator(
  storage_manager& _store,
  nodeid _id)
:
  store(_store),
  id(_id)
{
}

attr_iterator::~attr_iterator()
{
}



///////////////////////////////
//	text_iterator
///////////////////////////////

item& text_iterator::operator*() const
{
}
  
item* text_iterator::operator->() const
{
}
  
item& text_iterator::operator[](uint32_t)
{
}
    
text_iterator& text_iterator::operator++()
{
}
  
text_iterator text_iterator::operator++(int)
{
}
  
text_iterator& text_iterator::operator--()
{
}
  
text_iterator text_iterator::operator--(int)
{
}
  
text_iterator::text_iterator(
  storage_manager& _store,
  nodeid _id)
:
  store(_store),
  id(_id)
{
}

text_iterator::~text_iterator()
{
}



///////////////////////////////
//	ns_iterator
///////////////////////////////

item& ns_iterator::operator*() const
{
}
  
item* ns_iterator::operator->() const
{
}
  
item& ns_iterator::operator[](uint32_t)
{
}
    
ns_iterator& ns_iterator::operator++()
{
}
  
ns_iterator ns_iterator::operator++(int)
{
}
  
ns_iterator& ns_iterator::operator--()
{
}
  
ns_iterator ns_iterator::operator--(int)
{
}
  
ns_iterator::ns_iterator(
  storage_manager& _store,
  nodeid _id)
:
  store(_store),
  id(_id)
{
}

ns_iterator::~ns_iterator()
{
}



///////////////////////////////
//	xml_store
///////////////////////////////

item_iterator xml_store::children(nodeid id)
{
}


item_iterator xml_store::attributes(nodeid id)
{
}

item_iterator xml_store::namespace_bindings(nodeid id)
{
}

item_iterator xml_store::parent(nodeid id)
{
}

string xml_store::string_value(nodeid)
{
}



}	/* namespace xqp */
