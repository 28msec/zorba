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

#include <cassert>
#include <stack>

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/plan_settings.h"
#include "zorbaserialization/archiver_consts.h"

#include "zorbatypes/zstring.h"

#include "zorbautils/hashfun.h"

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

class archive_field;
class ClassSerializer;


/*******************************************************************************

  Archiver is working with fields. During serialization, an intermediate tree of
  fields is constructed in memory to represent all the objects that need to be 
  serialized. Then, the fields are written to disk in depth-first order, creating 
  an archive. During deserialization, the fields in the archive are read and the
  associated objects recreated directly in memory, without going through the
  intermediate representation of the fields-tree.

  Notice that in the context of the serializer, an "object" is defined as any 
  address in memory that contains information to be serialized. For example,
  it can be a C++ class object, an std::vector<> or a C++ integer. The object
  can be heap-allocated, or on the stack.

  Fileds can be "simple" or "compound". Simple fields represent values of simple
  types; they always appear as leaves in the fields-tree. Compound fields represent
  C++-class objects and other structured types like vectors, maps, etc. They
  typically contain subtrees of other fields.
  
  Each field has a unique id.

********************************************************************************/


/*******************************************************************************

  theArchiveName:
  ---------------

  theArchiveInfo:
  ---------------

  theArchiveVersion:
  ------------------

  theSerializingOut :
  -------------------
  Whether the archiver is used to serialize or deserialize a plan.

  theSerializeBaseClass:
  ----------------------
  If true, then we are in the process of (de)serializing a class obj O, and the
  next bunch of data members to serialize belong to an internal class in the
  class hierarchy. These data members will form a fields subtree, rooted at a 
  field of kind BASECLASS, within the bigger subtree of obj O. This data member
  is required in order for the function operator&(Archiver& ar, T*& obj) to know
  which serialize_internal() method to invoke.

  theIsTempField:
  ---------------
  If > 0, then the next obj to (de)serialize should not be registered or looked
  up in any of the fields registries. This is the case when, for example, we are
  seriazing an obj that resides on the program stack.

  theFieldCounter:
  ----------------
  The number of fields generated so far (during serialization). It is used to
  generated field ids. It is written to "disk" and used, during deserializrion
  to allocate the correct size for the all_references_list.

  theRootField :
  --------------
  The root of the fields tree.

  theCurrentCompoundField:
  ------------------------
  The compound field under which the next field to be created will be placed. 

  theCurrentLevel:
  ----------------
  The tree level of the most recently added field

********************************************************************************/
class Archiver
{
  friend class ClassSerializer;

  class FieldCompare
  {
  public: 
    uint32_t hash(const void* f) const
    {
      return hashfun::h32((void*)&f, sizeof(void*));
    }

    bool equal(const void* f1, const void* f2) const
    {
      return (f1 == f2);
    }
  };

  typedef HashMap<const void*, archive_field*, FieldCompare> FieldMap;

protected:
  zstring                       theArchiveName;

  zstring                       theArchiveInfo;

  unsigned long                 theArchiveVersion;

  bool                          theSerializingOut;

  int                           theSerializeBaseClass;

  int                           theIsTempField;
  
  std::stack<unsigned int>      limit_temp_level_stack;


  CompilerCB                  * theCompilerCB;

  int                           theFieldCounter;

  archive_field               * theRootField;

  archive_field               * theCurrentCompoundField;

  unsigned int                  theCurrentLevel;

  FieldMap                    * theNonClassFieldsMap;

  FieldMap                    * theClassFieldsMap;


  void                       ** all_reference_list;


  std::vector<archive_field*>   orphan_fields;

  bool                          internal_archive;

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

  void set_ccb(CompilerCB* ccb) { theCompilerCB = ccb; }

  CompilerCB* get_ccb() const { return theCompilerCB; }

  bool is_serializing_out() { return theSerializingOut; }

  void set_loading_hardcoded_objects(bool v) { loading_hardcoded_objects = v; }

  bool is_loading_hardcoded_objects() { return loading_hardcoded_objects; }

  SerializationCallback* getUserCallback() const { return theUserCallback; }

  void setUserCallback(SerializationCallback* cb) { theUserCallback = cb; }

  //
  // Methods used during serialization only
  //

  void add_simple_temp_field(TypeCode type, const void* ptr);

  bool add_simple_ptr_field(TypeCode type, const void* ptr);

  bool add_compound_field( 
      TypeCode type,
      bool is_class,
      const void* ptr,
      ArchiveFieldKind kind);

  void add_end_compound_field();

  bool is_serialize_everything() { return theSerializeEverything; }

  void set_serialize_everything() { theSerializeEverything = true; }

  //
  // Methods used during de-serialization only
  //
  void read_next_compound_field( 
      bool is_class,
      ArchiveFieldKind& field_kind,
      TypeCode& type, 
      int& id,
      int& referencing);

  void read_next_simple_temp_field(TypeCode type, void* obj);

  void read_next_simple_ptr_field(TypeCode type, void** obj);

  void read_end_current_level();

  void check_nonclass_field(
      ArchiveFieldKind field_kind,
      ArchiveFieldKind required_field_kind,
      int id);

  void check_class_field(
      TypeCode type,
      TypeCode required_type, 
      ArchiveFieldKind field_kind,
      ArchiveFieldKind required_field_kind,
      int id);

  void register_reference(int id, ArchiveFieldKind field_kind, const void* ptr);

  void* get_reference_value(int refid);

  void finalize_input_serialization();

  //
  // Methods used during both serialization and deserialization.
  //
  void set_serialize_base_class(bool s)
  {
    if (s)
      theSerializeBaseClass++;
    else
      theSerializeBaseClass--;

    assert(theSerializeBaseClass >= 0);
    assert(theSerializeBaseClass <= 1);
  }

  bool is_serialize_base_class() { return theSerializeBaseClass > 0; }

  void set_is_temp_field(bool is_temp)
  {
    if (is_temp)
      theIsTempField++;
    else
      theIsTempField--;

    assert(theIsTempField >= 0);
  }

  bool get_is_temp_field() { return (theIsTempField > 0); }

 void set_is_temp_field_one_level(bool is_temp)
  {
    if (is_temp)
      limit_temp_level_stack.push(theCurrentLevel + 1);
    else
      limit_temp_level_stack.pop();
  }

  bool get_is_temp_field_one_level();

protected:

  //
  // Methods used during serialization only
  //

  archive_field* lookup_non_class_field(const void* ptr);

  archive_field* lookup_class_field(const void* ptr);

  void prepare_serialize_out();

  archive_field* get_prev(archive_field* field);

  void replace_field(archive_field* new_field, archive_field* ref_field);

  void register_pointers_internal(archive_field* fields);

  bool check_allowed_delays(archive_field* parent_field);

  int check_order(archive_field* field1, archive_field* field2);

  void exchange_mature_fields(archive_field* field1, archive_field* field2);

  virtual void serialize_out() = 0;

  //
  // Methods used during de-serialization only
  //

  void root_tag_is_read();

  virtual void read_next_compound_field_impl(
      bool is_class,
      ArchiveFieldKind& field_kind,
      TypeCode& type,
      int& id, 
      int& referencing) = 0;

  virtual void read_next_simple_temp_field_impl(TypeCode type, void* obj) = 0;

  virtual void read_next_simple_ptr_field_impl(TypeCode type, void** obj) = 0;

  virtual void read_end_current_level_impl() = 0;

public:
  void register_item(store::Item* i);

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
