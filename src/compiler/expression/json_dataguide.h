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
  The node of a dataguide tree.

  is_star:
  --------
  Set to true if all the key/value pairs of an object need to retrieved from
  the JSON store. This includes all child objects.

  keys:
  values:
  -------
  Key=value pairs of the dataguide. If key X is contained in the keys vector,
  then the corresponding object must be retrieved from the store. The values
  is either:
    -- another list of key/value pairs denoting child objects that must be
       retreived
    -- star: all child objects beyond this point must be retrieved.
    -- empty: no projection information. All child nodes will be retrieved if
       the list remains empty at the end of the analysis.
*******************************************************************************/
class dataguide_node
{
public:
  bool is_star;

  bool propagates_to_output;
  
  std::vector<store::Item_t> keys;
  
  std::vector<dataguide_node> values;
  
  
public:  
  dataguide_node(bool propagates = true) : is_star(false), propagates_to_output(propagates) { }
  
  void add_to_leaves(store::Item* key, bool propagates);
  
  void add_to_leaves(const dataguide_node* other, bool propagates);
  
  void set_star_on_leaves();
  
  void do_union(const dataguide_node* other);
  
  // returns the child dataguide node associated with the given key, or NULL if there is none
  dataguide_node* get(store::Item* key);
    
  // recursively constructs "this" to be a clone of the other dataguide
  void clone(const dataguide_node* other);
  
  store::Item_t get_as_json();

  zstring toString();
};


/******************************************************************************
  The JSON dataguide control block

  theDataguideMap:
  ----------------
  A mapping of expressions (keys) to dataguide trees that contain the projection
  information. Each key in the map is a source expression which currently
  include JSON database collection retrieval functions (db:collection) and
  JSON parse function.
  In a UDF, all formal parameters are added to the sources set in order to
  allow projection information to be "added" to the expressions that invoke
  the UDF.
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
  
  void add_to_leaves(store::Item* object_name, bool propagates);
  
  void add_to_leaves(dataguide_node* other, bool propagates);
  
  void set_star_on_leaves();
  
  void set_star_on_roots();
      
  void do_union(const dataguide_cb* other);
  
  void do_union(expr *other);
  
  dataguide_cb_t clone();
  
  dataguide_node* get_dataguide_for_source(expr* e);
  
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
