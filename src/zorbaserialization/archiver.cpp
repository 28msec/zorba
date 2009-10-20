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

#include "zorbaserialization/archiver.h"
#include "zorbaerrors/error_manager.h"
#include <zorba/error.h>
#include "zorbaserialization/mem_archiver.h"

#include "store/api/item.h"

namespace zorba{
  namespace serialization{

    #define   ARCHIVER_LATEST_VERSION   0x3 //current latest version


/////////////////////////////////////////
//////////////////////////////////////////////////////

archive_field::archive_field(const char *type, bool is_simple, bool is_class, 
              const void *value, const void *assoc_ptr,
              int version, enum ArchiveFieldTreat  field_treat,
              archive_field *refered,
              int only_for_eval,
              bool allow_delay)
{
  this->type = strdup(type);
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
  this->allow_delay = allow_delay;
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
    archive_version(ARCHIVER_LATEST_VERSION),
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
    compiler_cb(0)
{

  if(is_serializing_out)
  {
    //create the top most field
    out_fields = new archive_field("", false, false, NULL, NULL, 0, ARCHIVE_FIELD_NORMAL, NULL, false, true);
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
  this->is_xquery_with_eval = false;
  loading_hardcoded_objects = false;
  allow_delay = true;
}

Archiver::~Archiver()
{
  delete out_fields; 
  delete all_reference_list;
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
  archive_field  *new_field;
  archive_field  *ref_field = NULL;
  bool      exch_fields = false;
  //int id = 0;
  if(!orig_ptr)
    field_treat = ARCHIVE_FIELD_IS_NULL;
  else if((field_treat != ARCHIVE_FIELD_IS_BASECLASS) && orig_ptr && !get_is_temp_field())
    ref_field = check_nonclass_pointer(type, orig_ptr);
  if(ref_field)
  {
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


  new_field = new archive_field(type, true, false, value, orig_ptr, 0, field_treat, ref_field, get_serialize_only_for_eval(), allow_delay);
  allow_delay = true;
  if(!ref_field && (field_treat != ARCHIVE_FIELD_IS_BASECLASS) && orig_ptr && !get_is_temp_field() && !get_is_temp_field_one_level())
  {
    SIMPLE_HASHOUT_FIELD  f(type, orig_ptr);
    simple_hashout_fields->insert(f, new_field);
  }
  if(!exch_fields)
  {
    new_field->parent = current_compound_field;
    new_field->id = ++nr_ids;
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
//  if(get_is_temp_field_one_level())
//    set_is_temp_field_one_level(false);
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
}

bool Archiver::add_compound_field(const char *type, 
                              int version, 
                              bool is_class,
                              const void *info,
                              const void *ptr,//for classes, pointer to SerializeBaseClass
                              enum ArchiveFieldTreat field_treat
                              )
{
  archive_field  *new_field;
  archive_field  *ref_field = NULL;
  bool      exch_fields = false;
  //int id = 0;
  if(!ptr)
    field_treat = ARCHIVE_FIELD_IS_NULL;
  else if((field_treat != ARCHIVE_FIELD_IS_BASECLASS) && ptr && !get_is_temp_field())
  {
    if(!is_class)
      ref_field = check_nonclass_pointer(type, ptr);
    else
      ref_field = check_class_pointer((SerializeBaseClass*)ptr);
  }
  if(ref_field)
  {
    if(field_treat == ARCHIVE_FIELD_NORMAL)
    {
      //special case
      //move the prev field into this one
      exch_fields = true;
    }
    field_treat = ARCHIVE_FIELD_IS_REFERENCING;
    ptr = NULL;
  }

  new_field = new archive_field(type, false, is_class, info, ptr, version, field_treat, ref_field, get_serialize_only_for_eval(), allow_delay);
  allow_delay = true;
  if(!ref_field && (field_treat != ARCHIVE_FIELD_IS_BASECLASS) && ptr && !get_is_temp_field() && !get_is_temp_field_one_level())
  {
    if(!is_class)
    {
      SIMPLE_HASHOUT_FIELD  f(type, ptr);
      simple_hashout_fields->insert(f, new_field);
    }
    else
      hash_out_fields->put((uint64_t)ptr, new_field);
  }
  if(!exch_fields)
  {
    new_field->parent = current_compound_field;
    new_field->id = ++nr_ids;
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
//  if(get_is_temp_field_one_level())
//    set_is_temp_field_one_level(false);
  return ref_field != NULL;
}

void Archiver::add_end_compound_field()
{
  current_compound_field = current_compound_field->parent;
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
    ZORBA_ERROR(SRL0001_INEXISTENT_INPUT_FIELD);
  }
  if(!is_simple)
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
  if(field_treat == ARCHIVE_FIELD_IS_NULL)
    return;
  if(strcmp(type, required_type))
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
  if((required_field_treat != (enum ArchiveFieldTreat)-1) && (field_treat != required_field_treat))
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
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
    ZORBA_ERROR(SRL0001_INEXISTENT_INPUT_FIELD);
  }
  if(is_simple || is_class)
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
  if(field_treat == ARCHIVE_FIELD_IS_NULL)
    return;
  if(strcmp(type, required_type))
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
  if((required_field_treat != (enum ArchiveFieldTreat)-1) && (field_treat != required_field_treat))
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
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
    ZORBA_ERROR(SRL0001_INEXISTENT_INPUT_FIELD);
  }
  if(is_simple || !is_class)
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
  if(field_treat == ARCHIVE_FIELD_IS_NULL)
    return;
  if(strcmp(type, required_type))
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
  if((required_field_treat != (enum ArchiveFieldTreat)-1) && (field_treat != required_field_treat))
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
}

void Archiver::register_reference(int id, enum ArchiveFieldTreat field_treat, const void *ptr)
{
  if(get_is_temp_field() && (field_treat != ARCHIVE_FIELD_IS_PTR))
    return;

//  struct field_ptr_vs_id    fid;
//  fid.field_id = id;
//  fid.assoc_ptr = ptr;
//  all_reference_list->push_back(fid);
  all_reference_list->put((uint32_t)id, (void*)ptr);

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
  fwd_reference_list.push_back(fid);
}

void Archiver::reconf_last_delayed_rcobject(void **last_obj, void **new_last_obj)
{
  if(fwd_reference_list.size() > 0)
  {
    struct fwd_ref    &fid = fwd_reference_list.back();
    if(fid.ptr == last_obj)
    {
      //fid.add_ref_to_rcobject = false;
      fid.ptr = new_last_obj;
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
/*
  std::list<field_ptr_vs_id>::iterator    all_it;
  for(all_it=all_reference_list->begin(); all_it != all_reference_list->end(); all_it++)
  {
    if((*all_it).field_id == refid)
      return (*all_it).assoc_ptr;
  }
  return NULL;
*/
  if(internal_archive && !all_reference_list)
  {
    //construct all_reference_list
    root_tag_is_read();
    register_pointers_internal(out_fields);
  }
  void *assoc_ptr = NULL;
  if(!all_reference_list->get((uint32_t)refid, assoc_ptr))
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
       ZORBA_ERROR_DESC_OSS(SRL0004_UNRESOLVED_FIELD_REFERENCE, (*it).referencing);
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
         ZORBA_ERROR_DESC_OSS(SRL0003_UNRECOGNIZED_CLASS_FIELD, (*it).class_name);
      }
      cls_factory->cast_ptr((SerializeBaseClass*)ptr, (*it).ptr);

      SimpleRCObject* rcobj1;
      store::Item* rcobj2;
      xqpStringStore* rcobj3;

      if((rcobj1 = dynamic_cast<SimpleRCObject*>((SerializeBaseClass*)ptr)) != NULL)
      {
        RCHelper::addReference(rcobj1); //this can lead to memory leaks
      }
      else if ((rcobj2 = dynamic_cast<store::Item*>((SerializeBaseClass*)ptr)) != NULL)
      {
        RCHelper::addReference(rcobj2); //this can lead to memory leaks
      }
      else if ((rcobj3 = dynamic_cast<xqpStringStore*>((SerializeBaseClass*)ptr)) != NULL)
      {
        RCHelper::addReference(rcobj3); //this can lead to memory leaks
      }
      else
      {
        ZORBA_FATAL(0, (*it).class_name);
      }
    }
  }

  //decrement RC on Items
  std::vector<store::Item*>::iterator item_it;
  for(item_it = registered_items.begin(); item_it != registered_items.end(); item_it++)
  {
    (*item_it)->removeReference((*item_it)->getSharedRefCounter() SYNC_PARAM2((*item_it)->getRCLock()));
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
  if(archive_version != ARCHIVER_LATEST_VERSION)
  {
    ZORBA_SER_ERROR_DESC_OSS(SRL0012_INCOMPATIBLE_ARCHIVE_VERSION, "Archive version is " << archive_version << " but expected " << ARCHIVER_LATEST_VERSION);
  }
  all_reference_list = new hash32map<void*>(nr_ids*2, 0.6f);
}

int Archiver::get_nr_ids()
{
  return nr_ids;
}

void Archiver::prepare_serialize_out()
{
  if(!xquery_with_eval())
  {
    check_compound_fields(out_fields);
  }
  check_allowed_delays(out_fields);
}

archive_field* Archiver::replace_with_null(archive_field *current_field)
{
  if(current_field->parent)
  {
    archive_field   *null_field = new archive_field("NULL", 
                                                    current_field->is_simple, 
                                                    current_field->is_class, "", NULL, 0, 
                                                    ARCHIVE_FIELD_IS_NULL, NULL, false, true);
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
        child->refered->only_for_eval &&
        (child->refered->field_treat != ARCHIVE_FIELD_NORMAL))
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
    replace_with_null(refering_field->refered);
    //get that archive_field
    replace_field(refering_field->refered, refering_field);
    archive_field *temp_field = refering_field->refered;
    delete refering_field;
    refering_field = temp_field;
    //search in orphan list
    std::vector<archive_field*>::iterator orphan_it;
    for(orphan_it = orphan_fields.begin(); orphan_it != orphan_fields.end(); orphan_it++)
    {
      if((*orphan_it) == refering_field)
      {
        orphan_fields.erase(orphan_it);
        break;
      }
    }
    clean_only_for_eval(refering_field, refering_field->only_for_eval);
  }
  check_compound_fields2(parent_field);
}

void Archiver::check_compound_fields2(archive_field   *parent_field)
{
  archive_field   *current_field = parent_field->first_child;
  while(current_field)
  {
    if(current_field->only_for_eval && (current_field->field_treat != ARCHIVE_FIELD_NORMAL))
    {
      //don't save it, replace it with NULL if possible
      archive_field *null_field = replace_with_null(current_field);

      orphan_fields.push_back(current_field);
      current_field = null_field;
    }
  /*  else if((current_field->field_treat == ARCHIVE_FIELD_IS_REFERENCING) &&
            current_field->refered->only_for_eval &&
            (current_field->refered->field_treat != ARCHIVE_FIELD_NORMAL))
    {
      archive_field *null_field = replace_with_null(current_field->refered);
      //get that archive_field
      replace_field(current_field->refered, current_field);
      archive_field *temp_field = current_field->refered;
      delete current_field;
      current_field = temp_field;
      //search in orphan list
      std::vector<archive_field*>::iterator orphan_it;
      for(orphan_it = orphan_fields.begin(); orphan_it != orphan_fields.end(); orphan_it++)
      {
        if((*orphan_it) == current_field)
        {
          orphan_fields.erase(orphan_it);
          break;
        }
      }
      clean_only_for_eval(current_field, current_field->only_for_eval);
    }
  */
    if(!current_field->is_simple)
      check_compound_fields2(current_field);
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

void Archiver::check_allowed_delays(archive_field *parent_field)
{
  //check all fields with dont_allow_delay and see if they are delayed
  //exchange field with the reference then
  
  archive_field   *child;
  child = parent_field->first_child;
  while(child)
  {
    if(!child->allow_delay && (child->field_treat == ARCHIVE_FIELD_IS_REFERENCING) &&
       check_order(out_fields, child, child->refered) < 1)
    {
      if((child->refered->field_treat == ARCHIVE_FIELD_NORMAL))// ||
        //!child->refered->allow_delay)
      {
        //impossible to solve situation
        //need to change the serialization order somewhere
        assert(false);
      }
      //exchange fields
      archive_field *child_prev = get_prev(child);
      archive_field *refered_prev = get_prev(child->refered);
      archive_field *refered_parent = child->refered->parent;
      archive_field *child_next = child->next;
      archive_field *refered_next = child->refered->next;
      //move refered
      if(child_prev)
        child_prev = child->refered;
      else
        parent_field->first_child = child->refered;
      child->refered->next = child_next;
      if(!child_next)
        parent_field->last_child = child->refered;
      child->refered->parent = parent_field;
      //move child
      if(refered_prev)
        refered_prev = child;
      else
        refered_parent->first_child = child;
      child->next = refered_next;
      if(!refered_next)
        refered_parent->last_child = child;
      child->parent = refered_parent;

      child->allow_delay = child->refered->allow_delay;
      child->refered->allow_delay = true;
      child = child->refered;
    }
    check_allowed_delays(child);
    child = child->next;
  }

}

}}
