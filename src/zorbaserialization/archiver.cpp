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
#include "stdafx.h"

#include <zorba/error.h>
#include <zorba/diagnostic_list.h>

#include "functions/function.h"
#include "store/api/item.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbautils/hashmap.h"

#include "archiver.h"
#include "class_serializer.h"
#include "mem_archiver.h"


namespace zorba
{

namespace serialization
{


/*******************************************************************************

********************************************************************************/
archive_field::archive_field(
    const char* type,
    bool is_simple,
    bool is_class,
    const void* value,
    const void* assoc_ptr,
    int version,
    enum ArchiveFieldKind  kind,
    archive_field* refered,
    int only_for_eval,
    ENUM_ALLOW_DELAY allow_delay,
    unsigned int level)
{
  theKind = kind;

  theIsSimple = is_simple;
  theIsClass = is_class;

  theClassVersion = version;

  theTypeName = strdup(type);
  theTypeNamePosInPool = 0;//initialy is the number of references to this field

  if (value)
    theValue = strdup((char*)value);
  else
    theValue = NULL;

  this->assoc_ptr = assoc_ptr;

  theReferredField = refered;

  this->referencing = refered ? refered->theId : 0;

  theLevel = level;

  theNextSibling = NULL;
  theFirstChild = NULL;
  theLastChild = NULL;
  theParent = NULL;

  theOnlyForEval = only_for_eval;

  theAllowDelay2 = allow_delay;

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  theBytesSaved = 0;
  theObjectsSaved = 0;
#endif
}


/*******************************************************************************

********************************************************************************/
archive_field::~archive_field()
{
  free(theTypeName);

  if (theValue)
    free((void*)theValue);

  archive_field* temp1 = theFirstChild;
  archive_field* temp2;

  while(temp1)
  {
    temp2 = temp1->theNextSibling;
    delete temp1;
    temp1 = temp2;
  }
}


/*******************************************************************************

********************************************************************************/
Archiver::Archiver(bool is_serializing_out, bool internal_archive)
  :
  theSerializingOut(is_serializing_out),
  serialize_base_class(false),
  all_reference_list(0),
  theArchiveVersion(g_zorba_classes_version),
  theRootField(0),
  current_compound_field(0),
  theSimpleFieldsMap(0),
  hash_out_fields(0),
  nr_ids(0),
  current_class_version(0),
  read_optional(false),
  theIsTempField(0),
  theCurrentLevel(0),
  internal_archive(internal_archive),
  theOnlyForEval(0),
  theSerializeEverything(false),
  loading_hardcoded_objects(false),
  theAllowDelay2(ALLOW_DELAY),
  theUserCallback(0),
  dont_allow_delay_for_plan_sctx(false)
{
  if (theSerializingOut)
  {
    //create the top most field
    theRootField = new archive_field("",
                                     false, // is_simple
                                     false, // is_class
                                     NULL,  // value
                                     NULL,  // assoc_ptr
                                     0,     // version
                                     ARCHIVE_FIELD_NORMAL,
                                     NULL,  // referred
                                     false, // only for eval
                                     ALLOW_DELAY,
                                     0);    // level

    current_compound_field = theRootField;

    theSimpleFieldsMap = new HashMap<SIMPLE_HASHOUT_FIELD, archive_field*,
                                        SimpleHashoutFieldCompare>(1000, false);
    hash_out_fields = new hash64map<archive_field*>(10000, 0.6f);
  }

  if (!internal_archive)
  {
    Archiver* har = ClassSerializer::getInstance()->harcoded_objects_archive;
    nr_ids = har->get_nr_ids();
  }
}


/*******************************************************************************

********************************************************************************/
Archiver::~Archiver()
{
  delete theRootField;
  delete [] all_reference_list;
  delete theSimpleFieldsMap;
  delete hash_out_fields;

  std::list<fwd_ref>::iterator it;
  for (it = fwd_reference_list.begin(); it != fwd_reference_list.end(); ++it)
  {
    if ((*it).class_name)
      free((*it).class_name);
  }

  std::vector<archive_field*>::const_iterator orphan_it;
  for (orphan_it = orphan_fields.begin(); orphan_it != orphan_fields.end(); ++orphan_it)
  {
    delete (*orphan_it);
  }
}


/*******************************************************************************
  Return the left sibling of a given field (NULL if there is no left sibling).
********************************************************************************/
archive_field* Archiver::get_prev(archive_field* field)
{
  archive_field* temp;
  temp = field->theParent->theFirstChild;

  if (temp == field)
    return NULL;

  while (temp)
  {
    if (temp->theNextSibling == field)
      return temp;

    temp = temp->theNextSibling;
  }

  assert(false);
  return NULL;
}


/*******************************************************************************
  Check whether there exists already a field for the nonclass object at the given
  memory address.
********************************************************************************/
archive_field* Archiver::lookup_nonclass_field(const char* type, const void* ptr)
{
  if (!ptr)
    return NULL;

  archive_field* duplicate_field = NULL;

  SIMPLE_HASHOUT_FIELD f(type, ptr);

  theSimpleFieldsMap->get(f, duplicate_field);

  if (!duplicate_field)
  {
    Archiver* har = ::zorba::serialization::ClassSerializer::getInstance()->
    getArchiverForHardcodedObjects();

    if (har != this)
      duplicate_field = har->lookup_nonclass_field(type, ptr);
  }

  return duplicate_field;
}


/*******************************************************************************
  Create a "simple" field (ARCHIVE_FIELD_PTR, or ARCHIVE_FIELD_NUL, or
  ARCHIVE_FIELD_NORMAL).

  @param type : The type of the object to serialize.
  @param value : The value of the object to serialize, if it is not a pointer).
  @param ptr : Pointer to the object being serialized (may be NULL)
  @param fieldKind : The kind of the field (if ptr is NULL, then the fieldKind is
         set unconditionally to ARCHIVE_FIELD_NUL).

  Return true if field is not referencing
********************************************************************************/
bool Archiver::add_simple_field(
    const char* type,
    const char* value,
    const void* ptr,
    enum ArchiveFieldKind fieldKind)
{
  archive_field* new_field;
  archive_field* ref_field = NULL;
  bool exch_fields = false;

  assert(fieldKind != ARCHIVE_FIELD_BASECLASS);
  assert(fieldKind != ARCHIVE_FIELD_REFERENCING);

  theCurrentLevel++;

  if (!ptr)
  {
    fieldKind = ARCHIVE_FIELD_NULL;
  }
  else
  {
    assert(fieldKind == ARCHIVE_FIELD_NORMAL || fieldKind == ARCHIVE_FIELD_PTR);

    if (!get_is_temp_field() &&
        (!get_is_temp_field_one_level() ||
         (fieldKind == ARCHIVE_FIELD_PTR && !get_is_temp_field_also_for_ptr())))
    {
      ref_field = lookup_nonclass_field(type, ptr);
    }
  }

  if (ref_field)
  {
    // If we are trying to register the actual obj (i.e. fieldKind == FIELD_NORMAL)
    // and there is already a field for the same obj, then the pre-existing field
    // must be a PTR or REFERENCING field.
    assert(fieldKind != ARCHIVE_FIELD_NORMAL ||
           ref_field->theKind == ARCHIVE_FIELD_PTR ||
           ref_field->theKind == ARCHIVE_FIELD_REFERENCING);

    if (get_is_temp_field_one_level() &&
        fieldKind == ARCHIVE_FIELD_PTR &&
        theAllowDelay2 == ALLOW_DELAY)
    {
      theAllowDelay2 = DONT_ALLOW_DELAY;
    }

    if (fieldKind == ARCHIVE_FIELD_NORMAL)
    {
      // special case: we registered a pointer to the obj before the obj itself
      // and now we try to register the obj itself.
      exch_fields = true;
    }

    fieldKind = ARCHIVE_FIELD_REFERENCING;
    value = NULL;
    ptr = NULL;
  }

  new_field = new archive_field(type,
                                true,       // is_simple
                                false,      // is_class
                                value,
                                ptr,
                                0,          // version
                                fieldKind,
                                ref_field,
                                get_serialize_only_for_eval(),
                                theAllowDelay2,
                                theCurrentLevel);

  theAllowDelay2 = ALLOW_DELAY;

  if (!ref_field &&
      ptr &&
      !get_is_temp_field() &&
      (!get_is_temp_field_one_level() ||
       (fieldKind == ARCHIVE_FIELD_PTR && !get_is_temp_field_also_for_ptr())))
  {
    assert(fieldKind == ARCHIVE_FIELD_NORMAL || fieldKind == ARCHIVE_FIELD_PTR);

    SIMPLE_HASHOUT_FIELD f(type, ptr);
    theSimpleFieldsMap->insert(f, new_field);
  }

  if (!exch_fields)
  {
    new_field->theId = ++nr_ids;
    new_field->theOrder = new_field->theId;

    new_field->theParent = current_compound_field;

    if (current_compound_field->theLastChild)
      current_compound_field->theLastChild->theNextSibling = new_field;
    else
      current_compound_field->theFirstChild = new_field;

    current_compound_field->theLastChild = new_field;
  }
  else
  {
    exchange_fields(new_field, ref_field);
  }

  theCurrentLevel--;

  return ref_field != NULL;
}


/*******************************************************************************
  Place new_field in the position occupied by ref_field, and disconnect 
  ref_field from the tree.
********************************************************************************/
void Archiver::replace_field(archive_field* new_field, archive_field* ref_field)
{
  archive_field* ref_field_parent = ref_field->theParent;
  archive_field* ref_field_prev = ref_field_parent->theFirstChild;

  if (ref_field_prev == ref_field)//is first child
  {
    ref_field_parent->theFirstChild = new_field;
    new_field->theNextSibling = ref_field->theNextSibling;
  }
  else
  {
    while (ref_field_prev->theNextSibling != ref_field)
      ref_field_prev = ref_field_prev->theNextSibling;

    ref_field_prev->theNextSibling = new_field;
    new_field->theNextSibling = ref_field->theNextSibling;
  }

  new_field->theParent = ref_field_parent;

  if (ref_field_parent->theLastChild == ref_field)
    ref_field_parent->theLastChild = new_field;

  new_field->theOrder = ref_field->theOrder;
}


/*******************************************************************************

********************************************************************************/
void Archiver::exchange_fields(archive_field* new_field, archive_field* ref_field)
{
  ref_field->theKind = ARCHIVE_FIELD_NORMAL;

  new_field->theKind = ARCHIVE_FIELD_REFERENCING;
  new_field->theId = ++nr_ids;
  new_field->referencing = ref_field->theId;
  new_field->theAllowDelay2 = ref_field->theAllowDelay2;

  replace_field(new_field, ref_field);

  ref_field->theParent = current_compound_field;

  if(current_compound_field->theLastChild)
    current_compound_field->theLastChild->theNextSibling = ref_field;
  else
    current_compound_field->theFirstChild = ref_field;

  ref_field->theNextSibling = NULL;
  current_compound_field->theLastChild = ref_field;

  ref_field->theOrder = nr_ids;
}


/*******************************************************************************

********************************************************************************/
bool Archiver::add_compound_field(
    const char* type,
    int version,
    bool is_class,
    const void* info,
    const void* ptr,//for classes, pointer to SerializeBaseClass
    enum ArchiveFieldKind fieldKind)
{
  archive_field* new_field;
  archive_field* ref_field = NULL;
  bool exch_fields = false;

  theCurrentLevel++;

  if (!ptr)
  {
    fieldKind = ARCHIVE_FIELD_NULL;
    theCurrentLevel--;
  }
  else if (fieldKind != ARCHIVE_FIELD_BASECLASS &&
           ptr &&
           !get_is_temp_field() &&
           (!get_is_temp_field_one_level() ||
            (fieldKind == ARCHIVE_FIELD_PTR && !get_is_temp_field_also_for_ptr())))
  {
    if (!is_class)
      ref_field = lookup_nonclass_field(type, ptr);
    else
      ref_field = lookup_class_field((SerializeBaseClass*)ptr);
  }

  if (ref_field)
  {
    assert(fieldKind != ARCHIVE_FIELD_NORMAL ||
           ref_field->theKind != ARCHIVE_FIELD_NORMAL);

    if (get_is_temp_field_one_level() && 
        fieldKind == ARCHIVE_FIELD_PTR &&
        theAllowDelay2 == ALLOW_DELAY)
    {
      theAllowDelay2 = DONT_ALLOW_DELAY;
    }

    if (fieldKind == ARCHIVE_FIELD_NORMAL)
    {
      //special case
      //move the prev field into this one
      exch_fields = true;
    }

    fieldKind = ARCHIVE_FIELD_REFERENCING;

    ptr = NULL;
  }

  new_field = new archive_field(type,
                                false,
                                is_class,
                                info,
                                ptr,
                                version,
                                fieldKind,
                                ref_field,
                                get_serialize_only_for_eval(), 
                                theAllowDelay2,
                                theCurrentLevel);
  theAllowDelay2 = ALLOW_DELAY;

  if (!ref_field &&
      fieldKind != ARCHIVE_FIELD_BASECLASS &&
      ptr &&
      !get_is_temp_field() &&
      (!get_is_temp_field_one_level() ||
       (fieldKind == ARCHIVE_FIELD_PTR && !get_is_temp_field_also_for_ptr())))
  {
    if (!is_class)
    {
      SIMPLE_HASHOUT_FIELD  f(type, ptr);
      theSimpleFieldsMap->insert(f, new_field);
    }
    else
    {
      hash_out_fields->put((uint64_t)ptr, new_field);
    }
  }

  if (!exch_fields)
  {
    new_field->theParent = current_compound_field;
    new_field->theId = ++nr_ids;
    new_field->theOrder = new_field->theId;
    if(current_compound_field->theLastChild)
      current_compound_field->theLastChild->theNextSibling = new_field;
    else
      current_compound_field->theFirstChild = new_field;
    current_compound_field->theLastChild = new_field;
    if(!ref_field && ptr)
      current_compound_field = new_field;
  }
  else
  {
    exchange_fields(new_field, ref_field);
  }

  if (ref_field)
    theCurrentLevel--;

  return ref_field != NULL;
}


/*******************************************************************************

********************************************************************************/
void Archiver::add_end_compound_field()
{
  current_compound_field = current_compound_field->theParent;
  theCurrentLevel--;
}


/*******************************************************************************

********************************************************************************/
void Archiver::set_class_type(const char* class_name)
{
  free(current_compound_field->theTypeName);
  current_compound_field->theTypeName = strdup(class_name);
}


/*******************************************************************************

********************************************************************************/
archive_field* Archiver::lookup_class_field(const SerializeBaseClass* ptr)
{
  if(!ptr)
    return NULL;

  archive_field* duplicate_field = NULL;

  hash_out_fields->get((uint64_t)ptr, duplicate_field);

  if(!duplicate_field)
  {
    Archiver* har = ::zorba::serialization::ClassSerializer::getInstance()->
    getArchiverForHardcodedObjects();

    if (har != this)
      duplicate_field = har->lookup_class_field(ptr);
  }

  return duplicate_field;
}


/*******************************************************************************

********************************************************************************/
bool Archiver::read_next_field(
    char** type,
    std::string* value,
    int* id,
    int* version,
    bool* is_simple,
    bool* is_class,
    enum ArchiveFieldKind* fieldKind,
    int* referencing)
{
  bool retval = read_next_field_impl(type, value, id, version, is_simple, is_class, fieldKind, referencing);
  if(retval && !*is_simple && (*fieldKind != ARCHIVE_FIELD_REFERENCING))
    theCurrentLevel++;
  return retval;
}


/*******************************************************************************

********************************************************************************/
void Archiver::read_end_current_level()
{
  theCurrentLevel--;
  read_end_current_level_impl();
}


/*******************************************************************************

********************************************************************************/
void Archiver::check_simple_field(
    bool retval,
    const char* type,
    const char* required_type,
    bool is_simple,
    enum ArchiveFieldKind field_treat,
    enum ArchiveFieldKind required_field_treat,
    int id)
{
  if (!retval)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0001_NONEXISTENT_INPUT_FIELD, ERROR_PARAMS(id));
  }

#ifndef NDEBUG
  if (!is_simple)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
#endif

  if(field_treat == ARCHIVE_FIELD_NULL)
    return;

#ifndef NDEBUG
  if (strcmp(type, required_type))
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
#endif

  if ((required_field_treat != (enum ArchiveFieldKind)-1) &&
      field_treat != required_field_treat)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
}


/*******************************************************************************

********************************************************************************/
void Archiver::check_nonclass_field(
    bool retval,
    const char* type,
    const char* required_type,
    bool is_simple,
    bool is_class,
    enum ArchiveFieldKind field_treat,
    enum ArchiveFieldKind required_field_treat,
    int id)
{
  if (!retval)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0001_NONEXISTENT_INPUT_FIELD, ERROR_PARAMS(id));
  }

#ifndef NDEBUG
  if (is_simple || is_class)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
#endif

  if (field_treat == ARCHIVE_FIELD_NULL)
    return;

#ifndef NDEBUG
  if (strcmp(type, required_type))
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
#endif

  if ((required_field_treat != (enum ArchiveFieldKind)-1) &&
      field_treat != required_field_treat)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
}


/*******************************************************************************

********************************************************************************/
void Archiver::check_class_field(
    bool retval,
    const char* type,
    const char* required_type,
    bool is_simple,
    bool is_class,
    enum ArchiveFieldKind field_treat,
    enum ArchiveFieldKind required_field_treat,
    int id)
{
  if (!retval)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0001_NONEXISTENT_INPUT_FIELD, ERROR_PARAMS(id));
  }

#ifndef NDEBUG
  if (is_simple || !is_class)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
#endif

  if (field_treat == ARCHIVE_FIELD_NULL)
    return;

#ifndef NDEBUG
  if (strcmp(type, required_type))
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
#endif

  if ((required_field_treat != (enum ArchiveFieldKind)-1) && 
     field_treat != required_field_treat)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
}


/*******************************************************************************

********************************************************************************/
void Archiver::register_reference(
    int id,
    enum ArchiveFieldKind field_treat,
    const void* ptr)
{
  if(get_is_temp_field())// && (field_treat != ARCHIVE_FIELD_PTR))
    return;
  if(get_is_temp_field_one_level() && ((field_treat != ARCHIVE_FIELD_PTR) || get_is_temp_field_also_for_ptr()))
    return;

//  all_reference_list->put((uint32_t)id, (void*)ptr);
  all_reference_list[id] = (void*)ptr;

}


/*******************************************************************************

********************************************************************************/
void Archiver::register_item(store::Item* i)
{
  if(i)
    registered_items.push_back(i);
}


/*******************************************************************************

********************************************************************************/
void Archiver::register_delay_reference(
    void** ptr,
    bool is_class,
    const char* class_name,
    int referencing)
{
  struct fwd_ref    fid;
  fid.referencing = referencing;
  fid.is_class = is_class;
  fid.ptr = ptr;
  *ptr = NULL;
  //fid.add_ref_to_rcobject = true;
  if(class_name)
    fid.class_name = strdup(class_name);
  else
    fid.class_name = NULL;
  fid.to_add_ref = false;
  fwd_reference_list.push_back(fid);
}


/*******************************************************************************

********************************************************************************/
void Archiver::reconf_last_delayed_rcobject(
    void** last_obj,
    void** new_last_obj,
    bool to_add_ref)
{
  if(fwd_reference_list.size() > 0)
  {
    struct fwd_ref    &fid = fwd_reference_list.back();
    if(fid.ptr == last_obj)
    {
      //fid.add_ref_to_rcobject = false;
      fid.ptr = new_last_obj;
      fid.to_add_ref = to_add_ref;
    }
  }
}


/*******************************************************************************

********************************************************************************/
void Archiver::register_pointers_internal(archive_field* fields)
{
  archive_field* child;
  child = fields->theFirstChild;
  while(child)
  {
    register_reference(child->theId, child->theKind, child->assoc_ptr);
    if(!child->theIsSimple)
    {
      register_pointers_internal(child);
    }
    child = child->theNextSibling;
  }
}


/*******************************************************************************

********************************************************************************/
void* Archiver::get_reference_value(int refid)
{
  if(internal_archive && !all_reference_list)
  {
    //construct all_reference_list
    root_tag_is_read();
    register_pointers_internal(theRootField);
  }

  void* assoc_ptr = NULL;
  //if(!all_reference_list->get((uint32_t)refid, assoc_ptr))
  if(!(assoc_ptr = all_reference_list[refid]))
  {
    Archiver* har = ::zorba::serialization::ClassSerializer::getInstance()->getArchiverForHardcodedObjects();
    if(har != this)
      assoc_ptr = har->get_reference_value(refid);
  }
  return assoc_ptr;
}


/*******************************************************************************

********************************************************************************/
void Archiver::finalize_input_serialization()
{
  std::list<fwd_ref>::iterator it;
  void* ptr;
  for (it = fwd_reference_list.begin(); it != fwd_reference_list.end(); it++)
  {
    ptr = get_reference_value((*it).referencing);
    if(!ptr)
    {
      throw ZORBA_EXCEPTION(
        zerr::ZCSE0004_UNRESOLVED_FIELD_REFERENCE,
        ERROR_PARAMS( it->referencing )
      );
    }
    //search the list for the pointer
    if(!(*it).is_class)
    {
      *((*it).ptr) = ptr;
    }
    else
    {
      class_deserializer  *cls_factory;
      cls_factory = ClassSerializer::getInstance()->get_class_factory((*it).class_name);
      if(cls_factory == NULL)
      {
         throw ZORBA_EXCEPTION(
          zerr::ZCSE0003_UNRECOGNIZED_CLASS_FIELD,
          ERROR_PARAMS( it->class_name )
        );
      }
      cls_factory->cast_ptr((SerializeBaseClass*)ptr, (*it).ptr);

      SimpleRCObject* rcobj1;
      store::Item* rcobj2;
      //zStringStore* rcobj3;


      if(!(*it).to_add_ref)
      {
      }
      else if((rcobj1 = dynamic_cast<SimpleRCObject*>((SerializeBaseClass*)ptr)) != NULL)
      {
        RCHelper::addReference(rcobj1); //this can lead to memory leaks
      }
      else if ((rcobj2 = dynamic_cast<store::Item*>((SerializeBaseClass*)ptr)) != NULL)
      {
        rcobj2->addReference(); //this can lead to memory leaks
      }
      //else if ((rcobj3 = dynamic_cast<zStringStore*>((SerializeBaseClass*)ptr)) != NULL)
      //{
      //  RCHelper::addReference(rcobj3); //this can lead to memory leaks
      //}
      else
      {
        ZORBA_FATAL(0, (*it).class_name);
      }
    }
  }

  //decrement RC on Items
  std::vector<store::Item*>::iterator item_it;
  int j=0;
  for(item_it = registered_items.begin(); item_it != registered_items.end(); item_it++)
  {
    j++;
    if((*item_it)->isNode())
    {
      assert(*(*item_it)->getSharedRefCounter() > 1);
    }
    else
    {
      assert((*item_it)->getRefCount() > 1);
    }
    (*item_it)->removeReference();
  }
}


/*******************************************************************************

********************************************************************************/
int Archiver::get_class_version()
{
  return current_class_version;
}


/*******************************************************************************

********************************************************************************/
void Archiver::set_class_version(int new_class_version)
{
  current_class_version = new_class_version;
}


/*******************************************************************************

********************************************************************************/
void Archiver::root_tag_is_read()
{
  if (theArchiveVersion != g_zorba_classes_version)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0012_INCOMPATIBLE_ARCHIVE_VERSION,
    ERROR_PARAMS(theArchiveVersion, g_zorba_classes_version));
  }

  all_reference_list = new void*[nr_ids+1];
  memset(all_reference_list, 0, sizeof(void*)*(nr_ids+1));
}


/*******************************************************************************

********************************************************************************/
int Archiver::get_nr_ids()
{
  return nr_ids;
}


/*******************************************************************************

********************************************************************************/
void Archiver::prepare_serialize_out()
{
  if (!is_serialize_everything())
  {
    check_compound_fields(theRootField);
  }

  while(check_allowed_delays(theRootField))
  {
  }
}


/*******************************************************************************

********************************************************************************/
archive_field* Archiver::replace_with_null(archive_field* current_field)
{
  if (current_field->theParent)
  {
    archive_field* null_field = new archive_field("NULL",
                                                  current_field->theIsSimple,
                                                  current_field->theIsClass,
                                                  "",
                                                  NULL,
                                                  0,
                                                  ARCHIVE_FIELD_NULL,
                                                  NULL,
                                                  false,
                                                  ALLOW_DELAY,
                                                  current_field->theLevel);
    null_field->theId = ++nr_ids;
    replace_field(null_field, current_field);
    current_field->theParent = NULL;
    current_field->theNextSibling = NULL;

    return null_field;
  }
  //otherwise it is orphan
  return NULL;
}


/*******************************************************************************

********************************************************************************/
int Archiver::compute_field_depth(archive_field* field)
{
  archive_field *temp;
  int i=0;
  temp = field->theParent;
  while(temp)
  {
    temp = temp->theParent;
    i++;
  }
  return i;
}


/*******************************************************************************

********************************************************************************/
int Archiver::get_only_for_eval(archive_field* field)
{
  if(field->theOnlyForEval)
    return field->theOnlyForEval;
  archive_field *child;
  for(child = field->theFirstChild; child; child = child->theNextSibling)
  {
    if(child->theOnlyForEval)
      return child->theOnlyForEval;
  }
  return 0;
}


/*******************************************************************************

********************************************************************************/
archive_field* Archiver::find_top_most_eval_only_field(archive_field* parent_field)
{
  int ref_depth = -1;
  archive_field *refering_field = NULL;
  archive_field *child;
  child = parent_field->theFirstChild;
  while(child)
  {
    if(child->theOnlyForEval)
    {
    }
    else if((child->theKind == ARCHIVE_FIELD_REFERENCING) &&
        get_only_for_eval(child->theReferredField))
    {
      int new_depth = compute_field_depth(child->theReferredField);
      if(!refering_field || (ref_depth > new_depth))
      {
        ref_depth = new_depth;
        refering_field = child;
      }
    }
    else if(!child->theIsSimple && !child->theReferredField)
    {
      archive_field *new_refering = find_top_most_eval_only_field(child);
      if(new_refering)
      {
        int new_depth = compute_field_depth(new_refering->theReferredField);
        if(!refering_field || (ref_depth > new_depth))
        {
          ref_depth = new_depth;
          refering_field = new_refering;
        }
      }
    }
    child = child->theNextSibling;
  }
  return refering_field;
}


/*******************************************************************************

********************************************************************************/
void Archiver::exchange_mature_fields(archive_field* field1, archive_field* field2)
{
  archive_field *field1_prev = get_prev(field1);
  archive_field *field1_next = field1->theNextSibling;
  archive_field *field1_parent = field1->theParent;
  archive_field *field2_prev = get_prev(field2);
  archive_field *field2_parent = field2->theParent;
  archive_field *field2_next = field2->theNextSibling;
  //move field2
  if(field1_prev)
    field1_prev->theNextSibling = field2;
  else
    field1_parent->theFirstChild = field2;
  field2->theNextSibling = field1_next;
  if(!field1_next)
    field1_parent->theLastChild = field2;
  field2->theParent = field1_parent;
  //move field1
  if(field2_prev)
    field2_prev->theNextSibling = field1;
  else
    field2_parent->theFirstChild = field1;
  field1->theNextSibling = field2_next;
  if(!field2_next)
    field2_parent->theLastChild = field1;
  field1->theParent = field2_parent;

  ENUM_ALLOW_DELAY temp_delay = field1->theAllowDelay2;
  field1->theAllowDelay2 = field2->theAllowDelay2;
  field2->theAllowDelay2 = temp_delay;

  unsigned int  temp_order;
  temp_order = field1->theOrder;
  field1->theOrder = field2->theOrder;
  field2->theOrder = temp_order;
}


/*******************************************************************************

********************************************************************************/
void Archiver::check_compound_fields(archive_field* parent_field)
{
  //resolve all references first
  //iterate: find the reference to the top most eval_only field and resolve it
  archive_field *refering_field;
  while(1)
  {
    refering_field = find_top_most_eval_only_field(parent_field);
    if(!refering_field)
      break;

    if((refering_field->theReferredField->theAllowDelay2 != ALLOW_DELAY) ||
      (refering_field->theReferredField->theKind == ARCHIVE_FIELD_NORMAL) ||
      !refering_field->theReferredField->theOnlyForEval)
    {
      //must preserve this serialization
      archive_field *temp_field = refering_field->theReferredField->theParent;
      while(temp_field)
      {
        temp_field->theOnlyForEval = 0;
        temp_field = temp_field->theParent;
      }
    }
    else
    {
      exchange_mature_fields(refering_field, refering_field->theReferredField);
      refering_field->theOnlyForEval = refering_field->theReferredField->theOnlyForEval;
    }
    clean_only_for_eval(refering_field->theReferredField, get_only_for_eval(refering_field->theReferredField));
  }
  while(check_only_for_eval_nondelay_referencing(parent_field))
  {}
  replace_only_for_eval_with_null(parent_field);
}


/*******************************************************************************

********************************************************************************/
bool Archiver::check_only_for_eval_nondelay_referencing(archive_field* parent_field)
{
  archive_field   *current_field = parent_field->theFirstChild;
  while(current_field)
  {
    if(current_field->theOnlyForEval && (current_field->theKind != ARCHIVE_FIELD_NORMAL))
    {
      if((current_field->theKind == ARCHIVE_FIELD_REFERENCING) &&
        (current_field->theAllowDelay2 != ALLOW_DELAY) &&
        (!current_field->theReferredField->theOnlyForEval))
      {
        //exchange fields
      //  exchange_mature_fields(current_field, current_field->theReferredField);
      //  current_field->theOnlyForEval = false;

        //must preserve this serialization
        archive_field *temp_field = current_field->theParent;
        while(temp_field)
        {
          temp_field->theOnlyForEval = 0;
          temp_field = temp_field->theParent;
        }
        clean_only_for_eval(current_field, current_field->theOnlyForEval);
        return true;
      }
    }

    if(!current_field->theIsSimple)
    {
      if(check_only_for_eval_nondelay_referencing(current_field))
        return true;
    }
    current_field = current_field->theNextSibling;
  }
  return false;
}


/*******************************************************************************

********************************************************************************/
void Archiver::replace_only_for_eval_with_null(archive_field* parent_field)
{
  archive_field   *current_field = parent_field->theFirstChild;
  while(current_field)
  {
    if(current_field->theOnlyForEval &&
      (current_field->theKind != ARCHIVE_FIELD_NORMAL) &&
      (current_field->theKind != ARCHIVE_FIELD_BASECLASS))
    {
    //don't save it, replace it with NULL if possible
      archive_field *null_field = replace_with_null(current_field);

      orphan_fields.push_back(current_field);
      current_field = null_field;
    }

    if(!current_field->theIsSimple)
    {
      replace_only_for_eval_with_null(current_field);
    }
    current_field = current_field->theNextSibling;
  }
}


/*******************************************************************************

********************************************************************************/
void Archiver::clean_only_for_eval(archive_field* field, int substract_value)
{
  if(field->theOnlyForEval >= substract_value)
    field->theOnlyForEval -= substract_value;
  else
    field->theOnlyForEval = 0;
  if(!field->theIsSimple)
  {
    archive_field   *child = field->theFirstChild;
    while(child)
    {
      clean_only_for_eval(child, substract_value);
      child = child->theNextSibling;
    }
  }
}


/*******************************************************************************
  return 0 if not found
  return -1 if field1 is before field2
  return 1  if field1 is after field2
********************************************************************************/
int Archiver::check_order(
    archive_field* parent_field,
    archive_field* field1,
    archive_field* field2)
{

  if(field1->theOrder < field2->theOrder)
    return -1;
  else if(field1->theOrder == field2->theOrder)
    return 0;
  else
    return 1;
/*
  archive_field *child;
  int check_ret;
  child = parent_field->theFirstChild;
  while(child)
  {
    if(child == field1)
      return -1;
    else if(child == field2)
      return 1;
    else
    {
      check_ret = check_order(child, field1, field2);
      if(check_ret)
        return check_ret;
    }
    child = child->theNextSibling;
  }
  return 0;
*/
}


/*******************************************************************************

********************************************************************************/
bool Archiver::check_allowed_delays(archive_field* parent_field)
{
  //check all fields with dont_allow_delay and see if they are delayed
  //exchange field with the reference then
  archive_field* child;
  child = parent_field->theFirstChild;

  while (child)
  {
    if (child->theKind == ARCHIVE_FIELD_REFERENCING &&
       ((child->theAllowDelay2 == DONT_ALLOW_DELAY &&
         check_order(theRootField, child, child->theReferredField) < 1 &&
         child->theAllowDelay2 == DONT_ALLOW_DELAY) ||
        child->theAllowDelay2 == SERIALIZE_NOW))
    {
      if (child->theAllowDelay2 == SERIALIZE_NOW)
      {
      }

      if (child->theReferredField->theKind == ARCHIVE_FIELD_NORMAL ||
          child->theReferredField->theAllowDelay2 == SERIALIZE_NOW)
      {
        //impossible to solve situation
        //need to change the serialization order somewhere
        throw ZORBA_EXCEPTION(zerr::ZCSE0014_INFINITE_CIRCULAR_DEPENDENCIES);
      }
      //exchange fields
      exchange_mature_fields(child, child->theReferredField);

      //  child->theReferredField->theAllowDelay2 = ALLOW_DELAY;
      child = child->theReferredField;

      return true;
    }

    if (check_allowed_delays(child))
      return true;

    child = child->theNextSibling;
  }

  return false;
}

} // namsspace serialization
} // namespace zorba
/* vim:set et sw=2 ts=2: */
