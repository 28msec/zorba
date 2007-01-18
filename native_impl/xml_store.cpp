
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

node& child_iterator::operator*() const
{
	return child;
}
  
node& child_iterator::operator[](uint32_t)
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
  node const& _v)
:
  store(_store),
  v(_v)
{
}

child_iterator::~child_iterator()
{
}



///////////////////////////////
//	attr_iterator
///////////////////////////////

node& attr_iterator::operator*() const
{
}
  
node& attr_iterator::operator[](uint32_t)
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
  node const& _v)
:
  store(_store),
  v(_v)
{
}

attr_iterator::~attr_iterator()
{
}



///////////////////////////////
//	text_iterator
///////////////////////////////

node& text_iterator::operator*() const
{
}
  
node& text_iterator::operator[](uint32_t)
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
  node const& _v)
:
  store(_store),
  v(_v)
{
}

text_iterator::~text_iterator()
{
}



///////////////////////////////
//	ns_iterator
///////////////////////////////

node& ns_iterator::operator*() const
{
}
  
node& ns_iterator::operator[](uint32_t)
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
  node const& _v)
:
  store(_store),
  v(_v)
{
}

ns_iterator::~ns_iterator()
{
}



///////////////////////////////
//	xml_store
///////////////////////////////

item_iterator xml_store::children(node const& v)
{
	return item_iterator();
}


item_iterator xml_store::attributes(node const& v)
{
	return item_iterator();
}

item_iterator xml_store::namespace_bindings(node const& v)
{
	return item_iterator();
}

item_iterator xml_store::parent(node const& v)
{
	return item_iterator();
}

string xml_store::string_value(node const& v)
{
	return "";
}



}	/* namespace xqp */
