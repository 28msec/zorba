/*
 * Copyright 2006-2013 The FLWOR Foundation.
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

#include "system/globalenv.h"
#include "store/api/item_factory.h"

#include "compiler/expression/expr_base.h"
#include "compiler/expression/json_dataguide.h"


namespace zorba
{
  
/*******************************************************************************
  
********************************************************************************/  
dataguide_node::dataguide_node(store::Item* key)
  :
  is_star(false)
{
  add(key);
}


dataguide_node* dataguide_node::add(store::Item* key)
{
  dataguide_node* existing = get(key);
  if (existing)
  {
    return existing;
  }
  
  keys.push_back(key);
  values.push_back(dataguide_node());
  return &values[values.size() - 1];
}


void dataguide_node::add_to_leaves(store::Item* key)
{
  if (is_star)
    return;
  
  if (keys.size() == 0) // no children == leaf
  {
    keys.push_back(key);
    values.push_back(dataguide_node());
    return;
  }
  
  for (unsigned int i=0; i != keys.size(); i++)
    values[i].add_to_leaves(key);
}


void dataguide_node::set_star()
{
  is_star = true;
  keys.clear();
  values.clear();  
}


void dataguide_node::set_star_on_leaves()
{
  if (is_star)
    return;
  
  if (keys.size() == 0)
  {
    set_star();
    return;
  }
  
  for (unsigned int i=0; i != keys.size(); i++)
    values[i].set_star_on_leaves();
}


void dataguide_node::do_union(const dataguide_node* other)
{
  if (other->is_star)
  {
    set_star();
    return;
  }
  
  for (unsigned int i=0; i<other->keys.size(); i++)
  {
    bool found = false;
    unsigned int j = 0;
    for ( ; j<keys.size(); j++)
      if (keys[j]->equals(other->keys[i]))
      {
        found = true;
        break;
      }
    
    if (found)
    {
      values[i].do_union(&other->values[j]);      
    }    
    else
    {          
      keys.push_back(other->keys[i]);
      values.push_back(dataguide_node());
      values.back().do_union(&other->values[i]);      
    }
  }    
}


dataguide_node* dataguide_node::clone(dataguide_node *other)
{
  dataguide_node* result = NULL;
  
  if (other->is_star)
  {
    set_star();
    return result;
  }
  
  for (unsigned int i=0; i<other->keys.size(); i++)
  {
    keys.push_back(other->keys[i]);
    values.push_back(dataguide_node());
    values.back().clone(&other->values[i]);
  }

  return result;
}


dataguide_node* dataguide_node::get(store::Item* key)
{
  for (unsigned int i=0; i<keys.size(); i++)
    if (keys[i]->equals(key))
      return &values[i];
  
  return NULL;
}


store::Item_t dataguide_node::get_as_json()
{ 
  std::vector<store::Item_t> vals;
  for (unsigned int i=0; i<values.size(); i++)
  {
    if (values[i].is_star)
    {
      store::Item_t star_string;
      zstring star = zstring("*");
      GENV_ITEMFACTORY->createString(star_string, star);
      vals.push_back(star_string);
    }
    else
      vals.push_back(values[i].get_as_json());
  }
    
  store::Item_t result;
  GENV_ITEMFACTORY->createJSONObject(result, keys, vals);
  
  return result;
}


zstring dataguide_node::toString()
{
  return get_as_json()->show();  
}


/*******************************************************************************

********************************************************************************/
dataguide_cb::dataguide_cb()
{
}


void dataguide_cb::add_object(store::Item* object_name)
{
  map_type::iterator i = theDataguideMap.begin();
  for ( ; i != theDataguideMap.end(); ++i)
  {
    i->second.add(object_name);
  }
}


void dataguide_cb::add_to_leaves(store::Item* object_name)
{
  // Append the given object to each leaf node
  map_type::iterator i = theDataguideMap.begin();
  for ( ; i != theDataguideMap.end(); i++)
  {
    i->second.add_to_leaves(object_name);
  }
}


void dataguide_cb::set_star_on_leaves()
{
  map_type::iterator i = theDataguideMap.begin();
  for ( ; i != theDataguideMap.end(); i++)
  {
    i->second.set_star_on_leaves();
  }
}


void dataguide_cb::set_star_on_roots()
{
  map_type::iterator i = theDataguideMap.begin();
  for ( ; i != theDataguideMap.end(); i++)
  {
    i->second.set_star();
  }
}


dataguide_node* dataguide_cb::add_source(expr* e)
{
  theDataguideMap[e] = dataguide_node();
  return &theDataguideMap[e];
}


void dataguide_cb::do_union(const dataguide_cb *other)
{
  if (this == other || other == NULL)
    return;
  
  map_type::const_iterator it = other->theDataguideMap.begin();
  for (; it != other->theDataguideMap.end(); ++it)
  {
    theDataguideMap[it->first].do_union(&it->second);    
  }  
}


void dataguide_cb::do_union(expr* other)
{
  if (other == NULL)
    return;
  
  do_union(other->get_dataguide());
}


dataguide_cb_t dataguide_cb::clone()
{
  dataguide_cb_t new_dg = new dataguide_cb();
  
  map_type::iterator it = theDataguideMap.begin();
  for (; it != theDataguideMap.end(); ++it)
  {    
    dataguide_node* new_node = new_dg->add_source(it->first);
    new_node->clone(&it->second);
  }
  
  return new_dg;
}


bool dataguide_cb::is_empty(expr* e) 
{  
  return theDataguideMap[e].keys.size() == 0 || theDataguideMap[e].is_star;
}


store::Item_t dataguide_cb::get_as_json(expr* e)
{
  if (theDataguideMap[e].is_star)
    return NULL;
  else
    return theDataguideMap[e].get_as_json();  
}


zstring dataguide_cb::toString()
{
  std::stringstream str;
  str << this;
  str << " {";
  
  map_type::iterator it = theDataguideMap.begin();
  for (; it != theDataguideMap.end(); ++it)
  {
    str << " " << it->first << ": " << it->second.toString();
  }  
  
  str << "}";
  return str.str();
}

}
/* vim:set et sw=2 ts=2: */
