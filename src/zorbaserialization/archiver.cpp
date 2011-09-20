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


/////////////////////////////////////////
//////////////////////////////////////////////////////

archive_field::archive_field(const char *type, bool is_simple, bool is_class,
              const void *value, const void *assoc_ptr,
              int version, enum ArchiveFieldTreat  field_treat,
              archive_field *refered,
              int only_for_eval,
              ENUM_ALLOW_DELAY allow_delay,
              unsigned int level)
{
  this->type = strdup(type);
  this->type_str_pos_in_pool = 0;//initialy is the number of references to this field
  this->is_simple = is_simple;
  this->is_class = is_class;
  if(value)
  {
    this->value = strdup((char*)value);
  }
  else
    this->value = NULL;
  this->assoc_ptr = assoc_ptr;
  this->version = version;
  this->field_treat = field_treat;
  this->referencing = refered ? refered->id : 0;

  next = NULL;
  first_child = NULL;
  last_child = NULL;
  parent = NULL;
  this->refered = refered;

  this->only_for_eval = only_for_eval;
  this->allow_delay2 = allow_delay;

  this->level = level;
#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  bytes_saved = 0;
  objects_saved = 0;
#endif
}

archive_field::~archive_field()
{
  free(type);
  if(value)
    free((void*)value);
  archive_field *temp1;
  archive_field *temp2;
  temp1 = first_child;
  while(temp1)
  {
    temp2 = temp1->next;
    delete temp1;
    temp1 = temp2;
  }
}

/////////////////////////////////////////
//////////////////////////////////////////////////////

Archiver::Archiver(bool is_serializing_out, bool internal_archive)
  : serializing_out(is_serializing_out),
    serialize_base_class(false),
    all_reference_list(0),
    archive_version(g_zorba_classes_version),
    out_fields(0),
    current_compound_field(0),
    simple_hashout_fields(0),
    hash_out_fields(0),
    nr_ids(0),
    current_class_version(0),
    read_optional(false),
    is_temp_field(0),
    //is_temp_field_one_level(false),
    current_level(0),
    internal_archive(internal_archive),
    theUserCallback(0),
    compiler_cb(0),
    dont_allow_delay_for_plan_sctx(false)
{

  if(is_serializing_out)
  {
    //create the top most field
    out_fields = new archive_field("", false, false, NULL, NULL, 0, ARCHIVE_FIELD_NORMAL, NULL, false, ALLOW_DELAY, 0);
    current_compound_field = out_fields;
  }

  if (!internal_archive)
  {
    Archiver *har = ClassSerializer::getInstance()->harcoded_objects_archive;
    nr_ids = har->get_nr_ids();
  }

  if(is_serializing_out)
  {
    simple_hashout_fields = new HashMap<SIMPLE_HASHOUT_FIELD, archive_field*,
                                        SimpleHashoutFieldCompare>(1000, false);
    hash_out_fields = new hash64map<archive_field*>(10000, 0.6f);
  }


  this->only_for_eval = 0;
  this->serialize_everything = false;
  loading_hardcoded_objects = false;
  allow_delay2 = ALLOW_DELAY;
}

Archiver::~Archiver()
{
  delete out_fields;
  delete []all_reference_list;
  delete simple_hashout_fields;
  delete hash_out_fields;

  std::list<fwd_ref>::iterator    it;
  for(it = fwd_reference_list.begin(); it != fwd_reference_list.end(); it++)
  {
    if((*it).class_name)
      free((*it).class_name);
  }

  std::vector<archive_field*>::const_iterator orphan_it;
  for(orphan_it = orphan_fields.begin(); orphan_it != orphan_fields.end(); orphan_it++)
  {
    delete (*orphan_it);
  }
}


void Archiver::create_archive(const char *archive_name,
                            const char *archive_info,
                            int archive_version)
{
  this->archive_name = strdup(archive_name);
  this->archive_info = strdup(archive_info);
  this->archive_version = archive_version;
}

//return true if field is not referencing
bool Archiver::add_simple_field(const char *type,
                            const char *value,
                            const void *orig_ptr,
                            enum ArchiveFieldTreat field_treat
                            )
{
  current_level++;
  archive_field  *new_field;
  archive_field  *ref_field = NULL;
  bool      exch_fields = false;
  //int id = 0;
  if(!orig_ptr)
  {
    field_treat = ARCHIVE_FIELD_IS_NULL;
  }
  else if((field_treat != ARCHIVE_FIELD_IS_BASECLASS) && orig_ptr &&
    !get_is_temp_field() && (!get_is_temp_field_one_level() || ((field_treat == ARCHIVE_FIELD_IS_PTR) && !get_is_temp_field_also_for_ptr())))
    ref_field = check_nonclass_pointer(type, orig_ptr);
  if(ref_field)
  {
    if(get_is_temp_field_one_level() && (field_treat == ARCHIVE_FIELD_IS_PTR) && (allow_delay2 == ALLOW_DELAY))
      allow_delay2 = DONT_ALLOW_DELAY;
    if(field_treat == ARCHIVE_FIELD_NORMAL)
    {
      //special case
      //move the prev field into this one
      exch_fields = true;
    }
    field_treat = ARCHIVE_FIELD_IS_REFERENCING;
    value = NULL;
    orig_ptr = NULL;
  }


  new_field = new archive_field(type, true, false, value, orig_ptr, 0, field_treat, ref_field, get_serialize_only_for_eval(), allow_delay2, current_level);
  allow_delay2 = ALLOW_DELAY;
  if(!ref_field && (field_treat != ARCHIVE_FIELD_IS_BASECLASS) && orig_ptr &&
    !get_is_temp_field() && (!get_is_temp_field_one_level() || ((field_treat == ARCHIVE_FIELD_IS_PTR) && !get_is_temp_field_also_for_ptr())))
  {
    SIMPLE_HASHOUT_FIELD  f(type, orig_ptr);
    simple_hashout_fields->insert(f, new_field);
  }
  if(!exch_fields)
  {
    new_field->parent = current_compound_field;
    new_field->id = ++nr_ids;
    new_field->order = new_field->id;
    if(current_compound_field->last_child)
      current_compound_field->last_child->next = new_field;
    else
      current_compound_field->first_child = new_field;
    current_compound_field->last_child = new_field;
  }
  else
  {
    exchange_fields(new_field, ref_field);
  }
  current_level--;
  return ref_field != NULL;
}

void Archiver::replace_field(archive_field  *new_field, archive_field  *ref_field)
{
  archive_field  *ref_field_parent = ref_field->parent;
  archive_field  *ref_field_prev = ref_field_parent->first_child;
  if(ref_field_prev == ref_field)//is first child
  {
    ref_field_parent->first_child = new_field;
    new_field->next = ref_field->next;
  }
  else
  {
    while(ref_field_prev->next != ref_field)
      ref_field_prev = ref_field_prev->next;
    ref_field_prev->next = new_field;
    new_field->next = ref_field->next;
  }
  new_field->parent = ref_field_parent;
  if(ref_field_parent->last_child == ref_field)
    ref_field_parent->last_child = new_field;
  new_field->order = ref_field->order;
}

void Archiver::exchange_fields(archive_field  *new_field, archive_field  *ref_field)
{
  new_field->field_treat = ARCHIVE_FIELD_IS_REFERENCING;
  ref_field->field_treat = ARCHIVE_FIELD_NORMAL;
//  new_field->id = ref_field->id;
//  ref_field->id = ++nr_ids;
  new_field->id = ++nr_ids;
  new_field->referencing = ref_field->id;

  replace_field(new_field, ref_field);

  ref_field->parent = current_compound_field;
  if(current_compound_field->last_child)
    current_compound_field->last_child->next = ref_field;
  else
    current_compound_field->first_child = ref_field;
  ref_field->next = NULL;
  current_compound_field->last_child = ref_field;
  ref_field->order = nr_ids;

  new_field->allow_delay2 = ref_field->allow_delay2;
}

bool Archiver::add_compound_field(const char *type,
                              int version,
                              bool is_class,
                              const void *info,
                              const void *ptr,//for classes, pointer to SerializeBaseClass
                              enum ArchiveFieldTreat field_treat
                              )
{
  current_level++;
  archive_field  *new_field;
  archive_field  *ref_field = NULL;
  bool      exch_fields = false;
  //int id = 0;
  if(!ptr)
  {
    field_treat = ARCHIVE_FIELD_IS_NULL;
    current_level--;
  }
  else if((field_treat != ARCHIVE_FIELD_IS_BASECLASS) && ptr &&
    !get_is_temp_field() && (!get_is_temp_field_one_level() || ((field_treat == ARCHIVE_FIELD_IS_PTR) && !get_is_temp_field_also_for_ptr())))
  {
    if(!is_class)
      ref_field = check_nonclass_pointer(type, ptr);
    else
      ref_field = check_class_pointer((SerializeBaseClass*)ptr);
  }
  if(ref_field)
  {
    if(get_is_temp_field_one_level() && (field_treat == ARCHIVE_FIELD_IS_PTR) && (allow_delay2 == ALLOW_DELAY))
      allow_delay2 = DONT_ALLOW_DELAY;
    if(field_treat == ARCHIVE_FIELD_NORMAL)
    {
      //special case
      //move the prev field into this one
      exch_fields = true;
    }
    field_treat = ARCHIVE_FIELD_IS_REFERENCING;
    ptr = NULL;
  }

  new_field = new archive_field(type, false, is_class, info, ptr, version, field_treat, ref_field, get_serialize_only_for_eval(), allow_delay2, current_level);
  allow_delay2 = ALLOW_DELAY;
  if(!ref_field && (field_treat != ARCHIVE_FIELD_IS_BASECLASS) && ptr &&
      !get_is_temp_field() && (!get_is_temp_field_one_level() || ((field_treat == ARCHIVE_FIELD_IS_PTR) && !get_is_temp_field_also_for_ptr())))
  {
    if(!is_class)
    {
      SIMPLE_HASHOUT_FIELD  f(type, ptr);
      simple_hashout_fields->insert(f, new_field);
    }
    else
    {
      hash_out_fields->put((uint64_t)ptr, new_field);
    }
  }
  if(!exch_fields)
  {
    new_field->parent = current_compound_field;
    new_field->id = ++nr_ids;
    new_field->order = new_field->id;
    if(current_compound_field->last_child)
      current_compound_field->last_child->next = new_field;
    else
      current_compound_field->first_child = new_field;
    current_compound_field->last_child = new_field;
    if(!ref_field && ptr)
      current_compound_field = new_field;
  }
  else
  {
    exchange_fields(new_field, ref_field);
  }
  if(ref_field)
    current_level--;
  return ref_field != NULL;
}

void Archiver::add_end_compound_field()
{
  current_compound_field = current_compound_field->parent;
  current_level--;
}

void Archiver::set_class_type(const char *class_name)
{
  free(current_compound_field->type);
  current_compound_field->type = strdup(class_name);
}

archive_field* Archiver::check_nonclass_pointer(const char *type, const void *ptr)
{
  if(!ptr)
    return NULL;

  //return check_nonclass_pointer_internal(ptr, out_fields);
  archive_field *duplicate_field = NULL;
  //hash_out_fields->get((uint64_t)ptr, duplicate_field);
  SIMPLE_HASHOUT_FIELD  f(type, ptr);
  simple_hashout_fields->get(f, duplicate_field);
  if(!duplicate_field)
  {
    Archiver *har = ::zorba::serialization::ClassSerializer::getInstance()->getArchiverForHardcodedObjects();
    if(har != this)
      duplicate_field = har->check_nonclass_pointer(type, ptr);
  }
  return duplicate_field;
}
/*
archive_field* Archiver::check_nonclass_pointer_internal(const void *ptr, archive_field *fields)
{
  archive_field *child;
  child = fields->first_child;
  while(child)
  {
    if(child->is_simple || !child->is_class)
      if(child->assoc_ptr == ptr)
        return child;
    if(!child->is_simple)
    {
      archive_field* ref_field = check_nonclass_pointer_internal(ptr, child);
      if(ref_field)
        return ref_field;
    }
    child = child->next;
  }
  return 0;
}
*/
archive_field* Archiver::check_class_pointer(const SerializeBaseClass *ptr)
{
  if(!ptr)
    return NULL;
  //return check_class_pointer_internal(ptr, out_fields);
  archive_field *duplicate_field = NULL;
  hash_out_fields->get((uint64_t)ptr, duplicate_field);
  if(!duplicate_field)
  {
    Archiver *har = ::zorba::serialization::ClassSerializer::getInstance()->getArchiverForHardcodedObjects();
    if(har != this)
      duplicate_field = har->check_class_pointer(ptr);
  }
  return duplicate_field;
}
/*
archive_field* Archiver::check_class_pointer_internal(const SerializeBaseClass *ptr, archive_field *fields)
{

  archive_field *child;
  child = fields->first_child;
  while(child)
  {
    if(child->is_class)
      if(child->assoc_class_ptr == ptr)
        return child;
    if(!child->is_simple)
    {
      archive_field* ref_field = check_class_pointer_internal(ptr, child);
      if(ref_field)
        return ref_field;
    }
    child = child->next;
  }
  return 0;
}
*/

bool Archiver::read_next_field( char **type,
                              std::string *value,
                              int *id,
                              int *version,
                              bool *is_simple,
                              bool *is_class,
                              enum ArchiveFieldTreat *field_treat,
                              int *referencing)
{
  bool retval = read_next_field_impl(type, value, id, version, is_simple, is_class, field_treat, referencing);
  if(retval && !*is_simple && (*field_treat != ARCHIVE_FIELD_IS_REFERENCING))
    current_level++;
  return retval;
}

void Archiver::read_end_current_level()
{
  current_level--;
  read_end_current_level_impl();
}


void Archiver::check_simple_field(bool retval,
                                  const char *type,
                                  const char *required_type,
                                  bool is_simple,
                                  enum ArchiveFieldTreat  field_treat,
                                  enum ArchiveFieldTreat  required_field_treat,
                                  int id)
{
  if(!retval)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0001_NONEXISTENT_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
#ifndef NDEBUG
  if(!is_simple)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
#endif
  if(field_treat == ARCHIVE_FIELD_IS_NULL)
    return;
#ifndef NDEBUG
  if(strcmp(type, required_type))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
#endif
  if((required_field_treat != (enum ArchiveFieldTreat)-1) && (field_treat != required_field_treat))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
}

void Archiver::check_nonclass_field(bool retval,
                                  const char *type,
                                  const char *required_type,
                                  bool is_simple,
                                  bool is_class,
                                  enum ArchiveFieldTreat  field_treat,
                                  enum ArchiveFieldTreat  required_field_treat,
                                  int id)
{
  if(!retval)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0001_NONEXISTENT_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
#ifndef NDEBUG
  if(is_simple || is_class)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
#endif
  if(field_treat == ARCHIVE_FIELD_IS_NULL)
    return;
#ifndef NDEBUG
  if(strcmp(type, required_type))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
#endif
  if((required_field_treat != (enum ArchiveFieldTreat)-1) && (field_treat != required_field_treat))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
}

void Archiver::check_class_field(bool retval,
                                  const char *type,
                                  const char *required_type,
                                  bool is_simple,
                                  bool is_class,
                                  enum ArchiveFieldTreat  field_treat,
                                  enum ArchiveFieldTreat  required_field_treat,
                                  int id)
{
  if(!retval)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0001_NONEXISTENT_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
#ifndef NDEBUG
  if(is_simple || !is_class)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
#endif
  if(field_treat == ARCHIVE_FIELD_IS_NULL)
    return;
#ifndef NDEBUG
  if(strcmp(type, required_type))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
#endif
  if((required_field_treat != (enum ArchiveFieldTreat)-1) && (field_treat != required_field_treat))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
    );
  }
}

void Archiver::register_reference(int id, enum ArchiveFieldTreat field_treat, const void *ptr)
{
  if(get_is_temp_field())// && (field_treat != ARCHIVE_FIELD_IS_PTR))
    return;
  if(get_is_temp_field_one_level() && ((field_treat != ARCHIVE_FIELD_IS_PTR) || get_is_temp_field_also_for_ptr()))
    return;

//  all_reference_list->put((uint32_t)id, (void*)ptr);
  all_reference_list[id] = (void*)ptr;

}
void Archiver::register_item(store::Item* i)
{
  if(i)
    registered_items.push_back(i);
}

void Archiver::register_delay_reference(void **ptr,
                                        bool is_class,
                                        const char *class_name,
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

void Archiver::reconf_last_delayed_rcobject(void **last_obj, void **new_last_obj, bool to_add_ref)
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

void Archiver::register_pointers_internal(archive_field *fields)
{
  archive_field *child;
  child = fields->first_child;
  while(child)
  {
    register_reference(child->id, child->field_treat, child->assoc_ptr);
    if(!child->is_simple)
    {
      register_pointers_internal(child);
    }
    child = child->next;
  }
}

void *Archiver::get_reference_value(int refid)
{
  if(internal_archive && !all_reference_list)
  {
    //construct all_reference_list
    root_tag_is_read();
    register_pointers_internal(out_fields);
  }
  void *assoc_ptr = NULL;
  //if(!all_reference_list->get((uint32_t)refid, assoc_ptr))
  if(!(assoc_ptr=all_reference_list[refid]))
  {
    Archiver *har = ::zorba::serialization::ClassSerializer::getInstance()->getArchiverForHardcodedObjects();
    if(har != this)
      assoc_ptr = har->get_reference_value(refid);
  }
  return assoc_ptr;
}

void Archiver::finalize_input_serialization()
{
  std::list<fwd_ref>::iterator    it;
  void  *ptr;
  for(it = fwd_reference_list.begin(); it != fwd_reference_list.end(); it++)
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

int Archiver::get_class_version()
{
  return current_class_version;
}

void Archiver::set_class_version(int new_class_version)
{
  current_class_version = new_class_version;
}

void Archiver::root_tag_is_read()
{
  if(archive_version != g_zorba_classes_version)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZCSE0012_INCOMPATIBLE_ARCHIVE_VERSION,
      ERROR_PARAMS( archive_version, g_zorba_classes_version )
    );
  }
  //all_reference_list = new hash32map<void*>(nr_ids*2, 0.6f);
  all_reference_list = new void*[nr_ids+1];
  memset(all_reference_list, 0, sizeof(void*)*(nr_ids+1));
}

int Archiver::get_nr_ids()
{
  return nr_ids;
}

void Archiver::prepare_serialize_out()
{
  if(!is_serialize_everything())
  {
    check_compound_fields(out_fields);
  }
  while(check_allowed_delays(out_fields))
  {}

}

archive_field* Archiver::replace_with_null(archive_field *current_field)
{
  if(current_field->parent)
  {
    archive_field   *null_field = new archive_field("NULL",
                                                    current_field->is_simple,
                                                    current_field->is_class, "", NULL, 0,
                                                    ARCHIVE_FIELD_IS_NULL, NULL, false, ALLOW_DELAY, current_field->level);
    null_field->id = ++nr_ids;
    replace_field(null_field, current_field);
    current_field->parent = NULL;
    current_field->next = NULL;

    return null_field;
  }
  //otherwise it is orphan
  return NULL;
}

int Archiver::compute_field_depth(archive_field *field)
{
  archive_field *temp;
  int i=0;
  temp = field->parent;
  while(temp)
  {
    temp = temp->parent;
    i++;
  }
  return i;
}

int Archiver::get_only_for_eval(archive_field *field)
{
  if(field->only_for_eval)
    return field->only_for_eval;
  archive_field *child;
  for(child = field->first_child; child; child = child->next)
  {
    if(child->only_for_eval)
      return child->only_for_eval;
  }
  return 0;
}

archive_field* Archiver::find_top_most_eval_only_field(archive_field *parent_field)
{
  int ref_depth = -1;
  archive_field *refering_field = NULL;
  archive_field *child;
  child = parent_field->first_child;
  while(child)
  {
    if(child->only_for_eval)
    {
    }
    else if((child->field_treat == ARCHIVE_FIELD_IS_REFERENCING) &&
        get_only_for_eval(child->refered))
    {
      int new_depth = compute_field_depth(child->refered);
      if(!refering_field || (ref_depth > new_depth))
      {
        ref_depth = new_depth;
        refering_field = child;
      }
    }
    else if(!child->is_simple && !child->refered)
    {
      archive_field *new_refering = find_top_most_eval_only_field(child);
      if(new_refering)
      {
        int new_depth = compute_field_depth(new_refering->refered);
        if(!refering_field || (ref_depth > new_depth))
        {
          ref_depth = new_depth;
          refering_field = new_refering;
        }
      }
    }
    child = child->next;
  }
  return refering_field;
}

void Archiver::exchange_mature_fields(archive_field *field1, archive_field *field2)
{
  archive_field *field1_prev = get_prev(field1);
  archive_field *field1_next = field1->next;
  archive_field *field1_parent = field1->parent;
  archive_field *field2_prev = get_prev(field2);
  archive_field *field2_parent = field2->parent;
  archive_field *field2_next = field2->next;
  //move field2
  if(field1_prev)
    field1_prev->next = field2;
  else
    field1_parent->first_child = field2;
  field2->next = field1_next;
  if(!field1_next)
    field1_parent->last_child = field2;
  field2->parent = field1_parent;
  //move field1
  if(field2_prev)
    field2_prev->next = field1;
  else
    field2_parent->first_child = field1;
  field1->next = field2_next;
  if(!field2_next)
    field2_parent->last_child = field1;
  field1->parent = field2_parent;

  ENUM_ALLOW_DELAY temp_delay = field1->allow_delay2;
  field1->allow_delay2 = field2->allow_delay2;
  field2->allow_delay2 = temp_delay;

  unsigned int  temp_order;
  temp_order = field1->order;
  field1->order = field2->order;
  field2->order = temp_order;
}

void Archiver::check_compound_fields(archive_field *parent_field)
{
  //resolve all references first
  //iterate: find the reference to the top most eval_only field and resolve it
  archive_field *refering_field;
  while(1)
  {
    refering_field = find_top_most_eval_only_field(parent_field);
    if(!refering_field)
      break;

    if((refering_field->refered->allow_delay2 != ALLOW_DELAY) ||
      (refering_field->refered->field_treat == ARCHIVE_FIELD_NORMAL) ||
      !refering_field->refered->only_for_eval)
    {
      //must preserve this serialization
      archive_field *temp_field = refering_field->refered->parent;
      while(temp_field)
      {
        temp_field->only_for_eval = 0;
        temp_field = temp_field->parent;
      }
    }
    else
    {
      exchange_mature_fields(refering_field, refering_field->refered);
      refering_field->only_for_eval = refering_field->refered->only_for_eval;
    }
    clean_only_for_eval(refering_field->refered, get_only_for_eval(refering_field->refered));
  }
  while(check_only_for_eval_nondelay_referencing(parent_field))
  {}
  replace_only_for_eval_with_null(parent_field);
}

bool Archiver::check_only_for_eval_nondelay_referencing(archive_field   *parent_field)
{
  archive_field   *current_field = parent_field->first_child;
  while(current_field)
  {
    if(current_field->only_for_eval && (current_field->field_treat != ARCHIVE_FIELD_NORMAL))
    {
      if((current_field->field_treat == ARCHIVE_FIELD_IS_REFERENCING) &&
        (current_field->allow_delay2 != ALLOW_DELAY) &&
        (!current_field->refered->only_for_eval))
      {
        //exchange fields
      //  exchange_mature_fields(current_field, current_field->refered);
      //  current_field->only_for_eval = false;

        //must preserve this serialization
        archive_field *temp_field = current_field->parent;
        while(temp_field)
        {
          temp_field->only_for_eval = 0;
          temp_field = temp_field->parent;
        }
        clean_only_for_eval(current_field, current_field->only_for_eval);
        return true;
      }
    }

    if(!current_field->is_simple)
    {
      if(check_only_for_eval_nondelay_referencing(current_field))
        return true;
    }
    current_field = current_field->next;
  }
  return false;
}

void Archiver::replace_only_for_eval_with_null(archive_field   *parent_field)
{
  archive_field   *current_field = parent_field->first_child;
  while(current_field)
  {
    if(current_field->only_for_eval &&
      (current_field->field_treat != ARCHIVE_FIELD_NORMAL) &&
      (current_field->field_treat != ARCHIVE_FIELD_IS_BASECLASS))
    {
    //don't save it, replace it with NULL if possible
      archive_field *null_field = replace_with_null(current_field);

      orphan_fields.push_back(current_field);
      current_field = null_field;
    }

    if(!current_field->is_simple)
    {
      replace_only_for_eval_with_null(current_field);
    }
    current_field = current_field->next;
  }
}

void Archiver::clean_only_for_eval(archive_field *field, int substract_value)
{
  if(field->only_for_eval >= substract_value)
    field->only_for_eval -= substract_value;
  else
    field->only_for_eval = 0;
  if(!field->is_simple)
  {
    archive_field   *child = field->first_child;
    while(child)
    {
      clean_only_for_eval(child, substract_value);
      child = child->next;
    }
  }
}
/*
  return 0 if not found
  return -1 if field1 is before field2
  return 1  if field1 is after field2
*/
int Archiver::check_order(archive_field *parent_field,
                           archive_field *field1,
                           archive_field *field2)
{

  if(field1->order < field2->order)
    return -1;
  else if(field1->order == field2->order)
    return 0;
  else
    return 1;
/*
  archive_field *child;
  int check_ret;
  child = parent_field->first_child;
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
    child = child->next;
  }
  return 0;
*/
}

archive_field* Archiver::get_prev(archive_field* field)
{
  archive_field *temp;
  temp = field->parent->first_child;
  if(temp == field)
    return NULL;
  while(temp)
  {
    if(temp->next == field)
      return temp;
    temp = temp->next;
  }
  assert(false);//unreachable
  return NULL;
}

bool Archiver::check_allowed_delays(archive_field *parent_field)
{
  //check all fields with dont_allow_delay and see if they are delayed
  //exchange field with the reference then
  archive_field   *child;
  child = parent_field->first_child;
  while(child)
  {
    if((child->field_treat == ARCHIVE_FIELD_IS_REFERENCING) &&
       (((child->allow_delay2 == DONT_ALLOW_DELAY) && (check_order(out_fields, child, child->refered) < 1) && (child->allow_delay2 == DONT_ALLOW_DELAY)) ||
       (child->allow_delay2 == SERIALIZE_NOW)))
    {
      if(child->allow_delay2 == SERIALIZE_NOW)
      {
      }
      if((child->refered->field_treat == ARCHIVE_FIELD_NORMAL) ||
        (child->refered->allow_delay2 == SERIALIZE_NOW))
      {
        //impossible to solve situation
        //need to change the serialization order somewhere
        throw ZORBA_EXCEPTION(zerr::ZCSE0014_INFINITE_CIRCULAR_DEPENDENCIES);
      }
      //exchange fields
      exchange_mature_fields(child, child->refered);

    //  child->refered->allow_delay2 = ALLOW_DELAY;
      child = child->refered;

      return true;
    }
    if(check_allowed_delays(child))
      return true;
    child = child->next;
  }

  return false;
}

} // namsspace serialization
} // namespace zorba
/* vim:set et sw=2 ts=2: */
