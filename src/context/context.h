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
#ifndef ZORBA_CONTEXT_H
#define ZORBA_CONTEXT_H

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"

#define ZORBA_HASHMAP_WITH_SERIALIZATION
#include "util/hashmap.h"
#undef ZORBA_HASHMAP_WITH_SERIALIZATION

namespace zorba {

  class expr; class var_expr;
  class function;
	class XQType;
  class ExternalModule;
  class ValueIndex;


/*******************************************************************************
  Note: methods that are not defined here are defined in static_context.cpp
********************************************************************************/
class ZORBA_DLL_PUBLIC context : public SimpleRCObject
{
public:
  // Used for mapping (function name, arity) to function object. The function
  // name is used first to probe the keymap, and the arity is used to probe
  // the ArityFMap that is returned by the 1st probe.
  typedef std::map<int, rchandle<function> > ArityFMap;
protected:

  enum ctx_value_type 
    {
      CTX_EXPR, CTX_FUNCTION, CTX_ARITY, CTX_INT, CTX_BOOL, CTX_XQTYPE, CTX_MODULE
    };

public:
  struct ctx_value_t : public ::zorba::serialization::SerializeBaseClass
  {
    enum ctx_value_type type;
    union { 
      expr             * exprValue;
      function         * functionValue;
      ArityFMap        * fmapValue; 
      int                intValue;
      bool               boolValue;
		  const XQType     * typeValue; ///do manual ref counting on this
      ExternalModule   * module; // module with external functions registered by the user
    };

  public:
    SERIALIZABLE_CLASS(ctx_value_t)
    SERIALIZABLE_CLASS_CONSTRUCTOR(ctx_value_t)
    void
    serialize_module(serialization::Archiver &ar,
                     ExternalModule*& aModule);

    void serialize(::zorba::serialization::Archiver &ar);
    ctx_value_t(enum ctx_value_type type = (enum ctx_value_type)-1) {this->type = type;}
    virtual ~ctx_value_t() {}
  };

  typedef xqp_string (* str_param_t) ();
  
protected:
	context              * parent;
	serializable_hashmap<ctx_value_t>   keymap;     // maps strings to ctx_values
	serializable_hashmap<xqp_string>    str_keymap; // maps strings to strings
  checked_vector<std::string>         module_paths; // sequence of locations

  xqpString                      default_function_namespace_internal;

public:
  SERIALIZABLE_CLASS(context)
  context(::zorba::serialization::Archiver &ar) : SimpleRCObject(ar), keymap(ar), str_keymap(ar) {}
  void serialize(::zorba::serialization::Archiver &ar)
  {
    //serialize_baseclass(ar, (SimpleRCObject*)this);
    if(ar.is_serializing_out())
    {
      ar.set_is_temp_field(true);
      bool  parent_is_root = check_parent_is_root();//(
      ar & parent_is_root;
      ar.set_is_temp_field(false);
      if(!parent_is_root)
      {
        ar & parent;
      }
      else
      {
      //  context *fooctx = NULL;
      //  ar & fooctx;
      }
    }
    else
    {
      //in serialization
      ar.set_is_temp_field(true);
      bool  parent_is_root;
      ar & parent_is_root;
      ar.set_is_temp_field(false);
      if(parent_is_root)
      {
        set_parent_as_root();
      }
      else
        ar & parent;
      if(parent)
        parent->addReference(parent->getSharedRefCounter() SYNC_PARAM2(parent->getRCLock()));
    }
    ar & keymap;
    ar & str_keymap;
    ar & module_paths;
    ar & default_function_namespace_internal;
  }
public:
  context (context *_parent = NULL) : parent (_parent) {}

	context *get_parent() const { return parent; }

  void
  set_module_paths(const std::vector<std::string>& aModulePaths);

  void
  get_module_paths(std::vector<std::string>& aModulePaths) const;

  void
  get_full_module_paths(std::vector<std::string>& aFullModulePaths) const;

  xqp_string default_function_namespace() const;
	void set_default_function_namespace(xqp_string);

protected:
  bool lookup_once (xqp_string key, xqp_string& val) const
  { 
    return str_keymap.get (key, val); 
  }

  bool lookup_once2 (const char *key1, xqp_string key2, xqp_string& val) const
  {
    return str_keymap.get2 (key1, key2, val); 
  }

  bool lookup_once (xqp_string key, ctx_value_t &val) const
  {
    return keymap.get (key, val); 
  }

  bool lookup_once2 (const char *key1, xqp_string key2, ctx_value_t& val) const
  {
    return keymap.get2 (key1, key2, val); 
  }

	template<class V> bool context_value(xqp_string key, V &val) const
	{
		if (lookup_once (key, val))
      return true;
    else
      return parent == NULL ? false : parent->context_value (key, val);
	}

	template<class V> bool context_value2(const char *key1, xqp_string key2, V& val) const
	{
		if (lookup_once2 (key1, key2, val))
      return true;
    else
      return parent == NULL ? false : parent->context_value2 (key1, key2, val);
	}

  expr* lookup_expr (xqp_string key) const 
  {
    ctx_value_t val(CTX_EXPR);
    return context_value (key, val) ? val.exprValue : NULL;
  }

  expr* lookup_expr2 (const char *key1, xqp_string key2) const 
  {
    ctx_value_t val(CTX_EXPR);
    return context_value2 (key1, key2, val) ? val.exprValue : NULL;
  }

  function* lookup_func (xqp_string key) const 
  {
    ctx_value_t val(CTX_FUNCTION);
    return (context_value (key, val)) ? val.functionValue : NULL;
  }

  function* lookup_func2 (xqp_string key1, xqp_string key2) const 
  {
    ctx_value_t val(CTX_FUNCTION);
    return (context_value2 (key1.c_str(), key2, val)) ? val.functionValue : NULL;
  }

  ArityFMap* lookup_fmap (xqp_string key) const 
  {
    ctx_value_t val(CTX_ARITY);
    return (context_value (key, val)) ? val.fmapValue : NULL;
  }

  function* lookup_fmap_func (xqp_string key, int arity) const;

  void bind_str(xqp_string key, xqp_string v, XQUERY_ERROR err = XQP0019_INTERNAL_ERROR);

  void bind_str2(
        const char *key1,
        xqp_string key2,
        xqp_string v,
        XQUERY_ERROR err = XQP0019_INTERNAL_ERROR);

  bool bind_expr (xqp_string key, expr *e);

  bool bind_expr2 (const char *key1, xqp_string key2, expr *e);

  bool bind_func (xqp_string key, function *f);

  bool bind_func2 (const char *key1, xqp_string key2, function *f);

  bool bind_module(xqp_string uri, ExternalModule* m);

protected:
  //serialization helpers
  bool check_parent_is_root();
  void set_parent_as_root();

};


}	/* namespace zorba */

#endif /*	ZORBA_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
