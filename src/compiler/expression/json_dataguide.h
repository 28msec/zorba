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
#pragma once
#ifndef ZORBA_COMPILER_JSON_DATAGUIDE
#define ZORBA_COMPILER_JSON_DATAGUIDE

#include "zorbautils/string_util.h"
#include "store/api/item.h"
#include "functions/function_consts.h"


namespace zorba
{

class expr;  
  

/******************************************************************************
  
*******************************************************************************/
class dataguide_node
{
public:
  bool is_star;
  
  std::vector<store::Item_t> keys;
  
  std::vector<dataguide_node> values;
  
  
public:  
  dataguide_node() : is_star(false) { }
  
  dataguide_node(store::Item* key);
    
  // returns the newly created node
  dataguide_node* add(store::Item* key); 
  
  void add_to_leaves(store::Item* key);
  
  void set_star();
  
  void set_star_on_leaves();
  
  void do_union(const dataguide_node *other);
  
  // returns the child dataguide node associated with the given key, or NULL if there is none
  dataguide_node* get(store::Item* key);
  
  // Will build a clone of the "other" dataguide_node into "this"
  // Will return the newly constructed dataguide_node* that will become "current"
  // dataguide_node* clone(dataguide_node* other, dataguide_node* current);
  
  dataguide_node* clone(dataguide_node* other);
  
  store::Item_t get_as_json();

  zstring toString();
};


/******************************************************************************
  The JSON dataguide control block
*******************************************************************************/
class dataguide_cb : public SimpleRCObject
{
friend class JsonDataguide;

public:
  typedef std::map<expr*, dataguide_node> map_type;
  
protected:  
  std::map<expr*,dataguide_node> theDataguideMap;
  
  
public:
  dataguide_cb();
    
  dataguide_node* add_source(expr* e);
  
  void add_object(store::Item* object_name);
  
  void add_to_leaves(store::Item* object_name);
  
  void set_star_on_leaves();
  
  void set_star_on_roots();
      
  void do_union(const dataguide_cb* other);
  
  void do_union(expr *other);
  
  dataguide_cb_t clone();
  
  bool is_empty(expr *e);                                             
  
  store::Item_t get_as_json(expr *e);  
  
  zstring toString();  
  
public:

  static bool func_uses_dataguide(FunctionConsts::FunctionKind kind);
};


}

#endif  // ZORBA_COMPILER_JSON_DATAGUIDE

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
