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
#pragma once
#ifndef ZORBA_BINARY_SERIALIZATION_ARCHIVER
#define ZORBA_BINARY_SERIALIZATION_ARCHIVER

#include "util/hashmap32.h"
#include <stack>

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/plan_settings.h"

namespace zorba
{

namespace store
{
class Item;
}


class CompilerCB;
class SerializationCallback;

template <class T, class V, class C> class HashMap;
 
namespace serialization
{

#define   FIELD_IS_SIMPLE      true
#define   FIELD_IS_CLASS       true

/*
  Archiver is working with fields. One archive contains a sequence of fields.
  They can be simple fields or combo fields.

  Simple fields: have values of simple types.
  Combo fields: contain a sequence of fields. Are like list, vector, class etc.
  
  Each field has a unique id.

  Special field is a field that points to a previous field. This is to resolve
  serialization of pointers to the same object.
*/

class ClassSerializer;


/*******************************************************************************

  ARCHIVE_FIELD_IS_REFERENCING :
  ------------------------------
  A field A that references another field B, where both A and B represent the
  "same" object.

  ARCHIVE_FIELD_IS_BASECLASS :
  ----------------------------
  A field representing a "partial" class object: If an obj O belong to a class C
  and C is a subclass of a base class B, then a field of ARCHIVE_FIELD_IS_BASECLASS
  kind is created to represent the serialization of the data members of B.

  ARCHIVE_FIELD_IS_PTR :
  ----------------------

  ARCHIVE_FIELD_IS_NULL :
  -----------------------
  A field representing a NULL pointer.

  ARCHIVE_FIELD_NORMAL :
  ----------------------

********************************************************************************/
enum ArchiveFieldKind
{
  ARCHIVE_FIELD_NORMAL,
  ARCHIVE_FIELD_IS_PTR,
  ARCHIVE_FIELD_IS_NULL,
  ARCHIVE_FIELD_IS_BASECLASS,
  ARCHIVE_FIELD_IS_REFERENCING
};


/*******************************************************************************

********************************************************************************/
enum ENUM_ALLOW_DELAY  
{
  ALLOW_DELAY,
  DONT_ALLOW_DELAY,
  SERIALIZE_NOW
};


/*******************************************************************************

********************************************************************************/
struct fwd_ref
{
  int referencing;
  void **ptr;
  bool is_class;
  //bool add_ref_to_rcobject;
  char *class_name;
  bool to_add_ref;
};


/*******************************************************************************
  theId :
  -------
  The unique id of the field. Not initialized by constructor.

  theIsSimple:
  ------------
  Whether this field represents a "simple" obj or a "compound" obj. 

  theIsClass:
  -----------
  Whether this field represents a class obj or not. Class objs are always 
  considered as "compound", so if theIsClass is true, theIsSimple is false. 
  However, the reverse is not true: a non-class obj may be simple or compound.

  theClassVersion:
  ----------------
  If this field represents a class obj, the class version of that obj.

  theKind:
  --------
  The kind of the field. See ArchiveFieldKind enum above.

  theTypeName:
  ------------

  theTypeNamePosInPool:
  ---------------------

  theValue:
  ---------
  For simple fields

  theValuePosInPool:
  ------------------
  Not initialized by constructor.

  thePtr :
  --------
  Pointer to the obj represented by this field. NULL if this field is referencing
  another field that represents the same obj.

  theReferredField:
  -----------------

  referencing:
  ------------

  theOrder:
  ---------
  Order in the tree. Not initialized by constructor.

  theLevel:
  ---------
  The level of this field, i.e., the nuber of fields in the paths from this
  field to the root. The root is at level 0.

  theNextSibling:
  ---------------

  theFirstChild:
  --------------

  theLastChild:
  -------------

  theParent:
  ----------

  theOnlyForEval:
  ---------------

  theAllowDelay2:
  ---------------

  theBytesSaved:
  --------------

  theObjectsSaved:
  ----------------

  The following data members are serialized:

  1. theTypeName  : only if theKind is PTR
  2. theValue     : except if theKind is REFERENCING
  3. theReferedId : only if theKind is REFERENCING
  4. theKind
  5. theId
********************************************************************************/
class archive_field
{
public:
  unsigned int                 theId;

  bool                         theIsSimple;
  bool                         theIsClass;
  unsigned int                 theClassVersion;

  enum ArchiveFieldKind        theKind;

  char                       * theTypeName;
  unsigned int                 theTypeNamePosInPool;

  const char                 * theValue;
  unsigned int                 theValuePosInPool;

  union
  {
    const SerializeBaseClass * assoc_class_ptr;
    const void               * assoc_ptr;
  };

  class archive_field        * theReferredField;
  unsigned int                 referencing;

  unsigned int                 theOrder;

  unsigned int                 theLevel;

  class archive_field        * theNextSibling;
  class archive_field        * theFirstChild;
  class archive_field        * theLastChild;
  class archive_field        * theParent;

  int                          theOnlyForEval;

  ENUM_ALLOW_DELAY             theAllowDelay2;

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  unsigned int                 theBytesSaved;
  unsigned int                 theObjectsSaved;
#endif

public:
  archive_field(
      const char* type,
      bool is_simple,
      bool is_class, 
      const void* value,
      const void* assoc_ptr,
      int version, 
      enum ArchiveFieldKind  field_treat,
      archive_field* refered,
      int only_for_eval,
      ENUM_ALLOW_DELAY allow_delay,
      unsigned int level);

  ~archive_field();
};


/*******************************************************************************

  theSerializingOut :
  -------------------
  Whether the archiver is used to serialize or deserialize a plan.

  theRootField :
  --------------
  The root of the fields tree.

  theCCB :
  --------
  to workaround user defined function compile-at-runtime.

********************************************************************************/
class Archiver
{
  friend class ClassSerializer;

  struct SIMPLE_HASHOUT_FIELD
  {
    std::string   type;
    const void   * ptr;

    SIMPLE_HASHOUT_FIELD() {}

    SIMPLE_HASHOUT_FIELD(const char* typestr, const void* ptrptr)
    {
      type = typestr;
      if(type[type.length()-1] == '*')
        type.resize(type.length()-1);
      ptr = ptrptr;

    }
  };

  class SimpleHashoutFieldCompare
  {
  public: 
    uint32_t hash(const SIMPLE_HASHOUT_FIELD& f) const
    {
      uint32_t  h = 0;
      h = hashfun::h32(f.type);
      h = hashfun::h32((void*)&f.ptr, sizeof(void*), h);
      return h;
    }
    bool equal(const SIMPLE_HASHOUT_FIELD& f1, const SIMPLE_HASHOUT_FIELD& f2) const
    {
      if((f1.ptr == f2.ptr) && (f1.type == f2.type))
        return true;
      else
        return false;
    }
  };

  typedef HashMap<SIMPLE_HASHOUT_FIELD, 
                  archive_field*,
                  SimpleHashoutFieldCompare> SimpleFieldMap;

protected:
  bool                          theSerializingOut;

  int                           serialize_base_class;

  void                       ** all_reference_list;
  
  std::list<struct fwd_ref>     fwd_reference_list;

  std::string                   theArchiveName;
  std::string                   theArchiveInfo;
  unsigned long                 theArchiveVersion;

  archive_field               * theRootField;

  archive_field               * current_compound_field;

  SimpleFieldMap              * simple_hashout_fields;//for simple types

  hash64map<archive_field*>   * hash_out_fields;//key is ptr, value is archive_field*, for non-simple types
  std::vector<archive_field*>   orphan_fields;

  int                           nr_ids;

  int                           current_class_version;

  bool                          read_optional;

  int                           theIsTempField;

  unsigned int                  theCurrentLevel;

  std::stack< std::pair<unsigned int, bool> >   limit_temp_level_stack;

  bool                          internal_archive;

  int                           theOnlyForEval;

  bool                          theSerializeEverything;

  bool                          loading_hardcoded_objects;

  ENUM_ALLOW_DELAY              theAllowDelay2;

  std::vector<store::Item*>     registered_items;

  SerializationCallback       * theUserCallback;

public:
  bool                          dont_allow_delay_for_plan_sctx;

public:
  Archiver(bool is_serializing_out, bool internal_archive=false);

  virtual ~Archiver();

  SerializationCallback* getUserCallback() const { return theUserCallback; }

  void setUserCallback(SerializationCallback* aCallback) { theUserCallback = aCallback; }

  bool add_simple_field( 
      const char* type, 
      const char* value,
      const void* orig_ptr,
      enum ArchiveFieldKind field_treat);

  bool add_compound_field( 
      const char* type,
      int version,
      bool is_class,
      const void* info,
      const void* ptr,//for classes, pointer to SerializeBaseClass
      enum ArchiveFieldKind field_treat);

  void add_end_compound_field();

  void set_class_type(const char* class_name);

  //return the id of previous object if it is the same
  archive_field* check_nonclass_pointer(const char* type, const void* ptr);

  archive_field* check_class_pointer(const SerializeBaseClass* ptr);
  

  bool read_next_field( 
      char** type, 
      std::string* value,
      int* id, 
      int* version, 
      bool* is_simple, 
      bool* is_class,
      enum ArchiveFieldKind* field_treat,
      int* referencing);

  void read_end_current_level();

  virtual bool read_next_field_impl(
      char** type, 
      std::string* value,
      int* id, 
      int* version, 
      bool* is_simple, 
      bool* is_class,
      enum ArchiveFieldKind* field_treat,
      int* referencing) = 0;

  virtual void read_end_current_level_impl() = 0;


protected:

  virtual void create_archive(
      const char* archive_name, 
      const char* archive_info,
      int archive_version);

  virtual void serialize_out() = 0;

  virtual void read_archive_description(
      std::string* archive_name,
      std::string* archive_info,
      int* archive_version, 
      int* nr_ids)
  {
    *archive_name = theArchiveName;
    *archive_info = theArchiveInfo;
    *archive_version = theArchiveVersion;
    *nr_ids = this->nr_ids;
  }


protected:
  archive_field* check_nonclass_pointer_internal(
      const void* ptr,
      archive_field* fields);

  archive_field* check_class_pointer_internal(
      const SerializeBaseClass* ptr,
      archive_field* fields);

  void replace_field(archive_field* new_field, archive_field* ref_field);

  void exchange_fields(archive_field* new_field, archive_field* ref_field);

  void root_tag_is_read();

  void register_pointers_internal(archive_field* fields);

  void prepare_serialize_out();

  archive_field* replace_with_null(archive_field* current_field);

  int compute_field_depth(archive_field* field);

  int get_only_for_eval(archive_field* field);

  archive_field* find_top_most_eval_only_field(archive_field* parent_field);

  void check_compound_fields(archive_field* parent_field);

  bool check_only_for_eval_nondelay_referencing(archive_field* parent_field);

  void replace_only_for_eval_with_null(archive_field* parent_field);

  void clean_only_for_eval(archive_field* field, int substract_value);

  void exchange_mature_fields(archive_field* field1, archive_field* field2);

  archive_field* get_prev(archive_field* field);

  int check_order(
      archive_field* parent_field,
      archive_field* field1,
      archive_field* field2);

  bool check_allowed_delays(archive_field* parent_field);

public:
  void check_simple_field(
      bool retval, 
      const char* type,
      const char* required_type, 
      bool is_simple, 
      enum ArchiveFieldKind field_treat,
      enum ArchiveFieldKind required_field_treat,
      int id);

  void check_nonclass_field(
      bool retval, 
      const char* type,
      const char* required_type, 
      bool is_simple, 
      bool is_class, 
      enum ArchiveFieldKind field_treat,
      enum ArchiveFieldKind required_field_treat,
      int id);

  void check_class_field(
      bool retval, 
      const char* type,
      const char* required_type, 
      bool is_simple, 
      bool is_class, 
      enum ArchiveFieldKind field_treat,
      enum ArchiveFieldKind required_field_treat,
      int id);

  void register_reference(
      int id, 
      enum ArchiveFieldKind field_treat,
      const void* ptr);

  void register_delay_reference(
      void** ptr,
      bool is_class,
      const char* class_name,
      int referencing);

  void reconf_last_delayed_rcobject(
      void** last_obj, 
      void** new_last_obj,
      bool to_add_ref);

  void register_item(store::Item* i);

  int get_class_version();

  void set_class_version(int new_class_version);

  //to help check class name at runtime
  void  set_serialize_base_class(bool s)
  {
    if(s)
      serialize_base_class++;
    else
      serialize_base_class--;

    assert(serialize_base_class >= 0);
    assert(serialize_base_class <= 1);
  }

  bool is_serialize_base_class()
  {
    return serialize_base_class > 0;
  }

  bool is_serializing_out()
  {
    return theSerializingOut;
  }

  void* get_reference_value(int refid);

  void finalize_input_serialization();

  void set_read_optional_field(bool activate_optional)
  {
    this->read_optional = activate_optional;
  }

  bool get_read_optional_field() { return this->read_optional; }

  void set_is_temp_field(bool is_temp)
  {
    if (is_temp)
      theIsTempField++;
    else
      theIsTempField--;

    assert(theIsTempField >= 0);
  }

  bool get_is_temp_field() { return (theIsTempField > 0); }

  void set_is_temp_field_one_level(bool is_temp, bool also_for_ptr = false)
  {
    if (is_temp)
      limit_temp_level_stack.push(std::pair<int, bool>(theCurrentLevel + 1,
                                                       also_for_ptr));
    else
      limit_temp_level_stack.pop();
  }

  bool get_is_temp_field_one_level() 
  {
    if (limit_temp_level_stack.empty())
    {
      return false;
    }
    else if (limit_temp_level_stack.top().first == theCurrentLevel)
    {
      return true;
    }
    else
    {
      unsigned int lastlevel = limit_temp_level_stack.top().first;
      archive_field* temp_field = current_compound_field;

      while (temp_field && (temp_field->theLevel >= lastlevel))
      {
        if (temp_field->theKind == ARCHIVE_FIELD_IS_PTR ||
            temp_field->theKind == ARCHIVE_FIELD_IS_REFERENCING)
           return false;

        temp_field = temp_field->theParent;
      }

      if (temp_field)
        return true;
      else
        return false;
    }
  } 

  bool get_is_temp_field_also_for_ptr() 
  {
    return (limit_temp_level_stack.top().first == theCurrentLevel &&
            limit_temp_level_stack.top().second);
  } 

  int get_nr_ids();

  bool is_serialize_everything() { return theSerializeEverything; }

  void set_serialize_everything() { theSerializeEverything = true; }

  int get_serialize_only_for_eval() { return theOnlyForEval; }

  void set_serialize_only_for_eval(bool evalonly)
  {
    if (evalonly)
      theOnlyForEval++;
    else
      theOnlyForEval--;

    assert(theOnlyForEval >= 0);
  }

  void set_loading_hardcoded_objects(bool set_hardcoded)
  {
    this->loading_hardcoded_objects = set_hardcoded;
  }

  bool is_loading_hardcoded_objects() { return loading_hardcoded_objects; }

  void dont_allow_delay(ENUM_ALLOW_DELAY d = DONT_ALLOW_DELAY)
  {
    theAllowDelay2 = d;
  }

  void reset_allow_delay() { theAllowDelay2 = ALLOW_DELAY; }

  ENUM_ALLOW_DELAY get_allow_delay() { return theAllowDelay2; }
};

  
}}
#endif
/* vim:set et sw=2 ts=2: */
