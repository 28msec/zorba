/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: xml_store.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author:  Paul Pedersen
 *
 */

#ifndef XQP_XML_STORE_H
#define XQP_XML_STORE_H

#include "storage_manager.h"
#include "../datamodel.h"

namespace xqp {
  
 
class child_iterator
{
protected:
  storage_manager& store;
  loc curr;

public:
  item& operator*() const;
  item* operator->() const;
  item& operator[](uint32_t);
    
  child_iterator& operator++();
  child_iterator operator++(int);
  
  child_iterator& operator--();
  child_iterator operator--(int);
  
public:
  child_iterator(storage_manager&,nodeid);
  ~child_iterator();
  
};


class attr_iterator
{
protected:
  storage_manager& store;

public:
  item& operator*() const;
  item* operator->() const;
  item& operator[](uint32_t);
    
  attr_iterator& operator++();
  attr_iterator operator++(int);
  
  attr_iterator& operator--();
  attr_iterator operator--(int);
  
public:
  attr_iterator(storage_manager&,nodeid);
  ~attr_iterator();
  
};


class text_iterator
{
protected:
  storage_manager& store;

public:
  item& operator*() const;
  item* operator->() const;
  item& operator[](uint32_t);
    
  text_iterator& operator++();
  text_iterator operator++(int);
  
  text_iterator& operator--();
  text_iterator operator--(int);
  
public:
  text_iterator(storage_manager&,nodeid);
  ~attr_iterator();
  
};


class ns_iterator
{
protected:
  storage_manager& store;

public:
  item& operator*() const;
  item* operator->() const;
  item& operator[](uint32_t);
    
  ns_iterator& operator++();
  ns_iterator operator++(int);
  
  ns_iterator& operator--();
  ns_iterator operator--(int);
  
public:
  ns_iterator(storage_manager&,nodeid);
  ~attr_iterator();
  
};



class xml_store
{
protected:
  storage_manager& mgr;
  
public:
  item_iterator children(nodeid);
  item_iterator attributes(nodeid);
  item_iterator namespace_bindings(nodeid);
  item_iterator parent(nodeid);
  std::string string_value(nodeid);

};


} /* namespace xqp */
#endif  /* XQP_XML_STORE_H */

