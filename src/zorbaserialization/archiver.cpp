
#include "zorbaserialization/archiver.h"
#include "zorbaerrors/error_manager.h"
#include <zorba/error.h>
#include "zorbaserialization/mem_archiver.h"

#include "store/api/item.h"

namespace zorba{
  namespace serialization{

/////////////////////////////////////////
//////////////////////////////////////////////////////

archive_field::archive_field(const char *type, bool is_simple, bool is_class, 
              const void *value, const void *assoc_ptr,
              int version, enum ArchiveFieldTreat  field_treat,
              int referencing)
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
  this->referencing = referencing;

  next = NULL;
  first_child = NULL;
  last_child = NULL;
  parent = NULL;
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
{
  this->serializing_out = is_serializing_out;
  //this->ser = ser;

  this->serialize_base_class = false;
  archive_version = ARCHIVER_LATEST_VERSION;

  out_fields = NULL;
  current_compound_field = NULL;
  if(is_serializing_out)
  {
    //create the top most field
    out_fields = new archive_field("", false, false, NULL, NULL, 0, ARCHIVE_FIELD_NORMAL, 0);
    current_compound_field = out_fields;
  }

  if(internal_archive)
    nr_ids = 0;
  else
  {
    Archiver *har = ::zorba::serialization::ClassSerializer::getInstance()->harcoded_objects_archive;
    nr_ids = har->get_nr_ids();
  }
  current_class_version = 0;
  read_optional = false;
  is_temp_field = 0;
  this->internal_archive = internal_archive;

  all_reference_list = NULL;//(??30000, 0.6f)//, hash_out_fields(20000, 0.6f)
  if(is_serializing_out)
  {
    simple_hashout_fields = new HashMap<SIMPLE_HASHOUT_FIELD, archive_field*, SimpleHashoutFieldCompare>(1000, false);
    hash_out_fields = new hash64map<archive_field*>(10000, 0.6f);
  }
  else
  {
    simple_hashout_fields = NULL;
    hash_out_fields = NULL;
  }

  compiler_cb = NULL;
}

Archiver::~Archiver()
{
  delete out_fields; 
  delete all_reference_list;
  delete simple_hashout_fields;
  delete hash_out_fields;
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


  new_field = new archive_field(type, true, false, value, orig_ptr, 0, field_treat, ref_field ? ref_field->id : 0);
  if(!ref_field && (field_treat != ARCHIVE_FIELD_IS_BASECLASS) && orig_ptr && !get_is_temp_field())
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
  return ref_field != NULL;
}

void Archiver::exchange_fields(archive_field  *new_field, archive_field  *ref_field)
{
  new_field->field_treat = ARCHIVE_FIELD_IS_REFERENCING;
  ref_field->field_treat = ARCHIVE_FIELD_NORMAL;
  new_field->id = ref_field->id;
  ref_field->id = ++nr_ids;
  new_field->referencing = ref_field->id;
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
  new_field->parent = ref_field->parent;
  ref_field->parent = current_compound_field;
  if(current_compound_field->last_child == ref_field)
    current_compound_field->last_child = new_field;
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

  new_field = new archive_field(type, false, is_class, info, ptr, version, field_treat, ref_field ? ref_field->id : 0);
  if(!ref_field && (field_treat != ARCHIVE_FIELD_IS_BASECLASS) && ptr && !get_is_temp_field())
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
      RCObject *rcobj = dynamic_cast<RCObject*>((SerializeBaseClass*)ptr);
      if(rcobj)
        RCHelper::addReference(rcobj);//this can lead to memory leaks
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
  all_reference_list = new hash32map<void*>(nr_ids*2, 0.6f);
}

int Archiver::get_nr_ids()
{
  return nr_ids;
}

}}
