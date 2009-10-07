/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#ifndef ZORBA_DYNAMIC_CONTEXT_H
#define ZORBA_DYNAMIC_CONTEXT_H

#include "util/hashmap.h"
#include "zorbautils/hashmap_itemp.h"

#include "common/shared_types.h"

#include "store/api/shared_types.h"


namespace zorba {


template <class V> class ItemPointerHashMap;


/*******************************************************************************
  The dynamic context stores the following info:

  - The current date and time, i.e the date and time when the dynamic context
    was created. 
  - The current time in mili-secs.
  - The local timezone (obtained from the machine where zorba is running)
  - The default collection uri (the one to use when fn:collection is invoked
    with no argument)
  - The context item for the whole query, if any.
  - The position of the context item, if any.
  - A hasmap mapping the name of each prolog or block-local variable to its
    current value, which is either a single item or a temp sequence.
  - A map mapping the uri of each index to the store object representing the
    index (store::Index_t)
********************************************************************************/
class dynamic_context
{
  friend class ZorbaDebugIterator;

protected:

  struct dctx_value_t 
  {
    typedef enum 
    {
      no_val,
      var_item_val,
      var_temp_seq_val,
    } val_type_t;

    union
    {
      store::Item*     var_item;
      store::TempSeq*  var_temp_seq;
    }           val;

    val_type_t  type;
    bool        in_progress;
  };

  typedef hashmap<dctx_value_t> ValueMap;

  typedef ItemPointerHashMap<store::Index_t> IndexMap;

protected:
  static bool                  static_init;

protected:
  dynamic_context            * theParent;

  store::Item_t                current_date_time_item;
  store::Item_t                current_time_millis;
  long                         theTimezone;
  store::Item_t                default_collection_uri;

  store::Item_t                ctxt_item;
  unsigned long                ctxt_position;
  //+context size is determined by fn:last() at runtime

  ValueMap                     keymap;

  IndexMap                   * theAvailableIndices;

public:
  static std::string var_key(const void* var);

  static xqp_string expand_varname(static_context* sctx, xqpString& qname);

  static void init();

public:
  dynamic_context(dynamic_context* parent = NULL);

  ~dynamic_context();

  store::Item_t get_default_collection();

  void set_default_collection(const store::Item_t& default_collection_uri);

  void set_current_date_time(const store::Item_t&);

  store::Item_t get_current_date_time();

  store::Item_t get_current_time_millis();

  void set_implicit_timezone(long tzone_seconds);

  long get_implicit_timezone();

  store::Item_t context_item() const;

  unsigned long context_position();

  xqtref_t context_item_type() const;

  void set_context_item_type(xqtref_t );

  void set_context_item(const store::Item_t&, unsigned long position);

  void declare_variable(const std::string& varname);

  void set_variable(const std::string& varname, store::Item_t& var_item);

  void set_variable(const std::string& varname, store::Iterator_t& var_iterator);

  void add_variable(const std::string& varname, store::Item_t& var_item);

  void add_variable(const std::string& varname, store::Iterator_t& var_iterator);

  bool get_variable(
        const store::Item_t& varname,
        store::Item_t& var_item,
        store::Iterator_t& var_iter);

  store::Index* getIndex(const store::Item* qname) const;

  void bindIndex(
        const store::Item* qname,
        store::Index_t& index);

  void unbindIndex(const store::Item* qname);

protected:
  bool lookup_once(const std::string& key, dctx_value_t& val) const 
  {
    return keymap.get(key, val); 
  }

  bool context_value(const std::string& key, dctx_value_t& val) const 
  {
    if (lookup_once(key, val)) 
    {
      return true;
    }
    return theParent == NULL ? false : theParent->context_value(key, val);
  }

  bool context_value(const std::string& key, dctx_value_t& val, ValueMap **map) 
  {
    if (lookup_once (key, val)) 
    {
      if (map != NULL) *map = &keymap;
      return true;
    }
    return theParent == NULL ? false : theParent->context_value(key, val, map);
  }

  void destroy_dctx_value(dctx_value_t *);

  bool lookup_var_value(
        const std::string& key,
        store::Item_t& var_item,
        store::Iterator_t& var_iter);
};


} /* namespace zorba */
#endif /* ZORBA_DYNAMIC_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
