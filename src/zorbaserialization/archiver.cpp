
#include "zorbaserialization/archiver.h"
#include "zorbaerrors/error_manager.h"
#include <zorba/error.h>

namespace zorba{
  namespace serialization{

/////////////////////////////////////////
//////////////////////////////////////////////////////

archive_field::archive_field(const char *type, bool is_simple, bool is_class, 
              void *value, void *assoc_ptr,
              int version, enum ArchiveFieldTreat  field_treat,
              int referencing)
{
  this->type = _strdup(type);
  this->is_simple = is_simple;
  this->is_class = is_class;
  if(value)
  {
    this->value = _strdup((char*)value);
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
  if(is_simple && value)
    free(value);
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

Archiver::Archiver(bool is_serializing_out)
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

  nr_ids = 0;
  current_class_version = 0;
}

Archiver::~Archiver()
{
  if(out_fields)
    delete out_fields; 
}


void Archiver::create_archive(const char *archive_name, 
                            const char *archive_info,
                            int archive_version)
{
  this->archive_name = _strdup(archive_name);
  this->archive_info = _strdup(archive_info);
  this->archive_version = archive_version;
}

//return true if field is not referencing
bool Archiver::add_simple_field(const char *type, 
                            const char *value,
                            void *orig_ptr,
                            enum ArchiveFieldTreat field_treat
                            )
{
  archive_field  *new_field;
  archive_field  *ref_field = NULL;
  bool      exch_fields = false;
  //int id = 0;
  if(field_treat != ARCHIVE_FIELD_IS_BASECLASS)//always
    ref_field = check_nonclass_pointer(orig_ptr);
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


  new_field = new archive_field(type, true, false, (void*)value, orig_ptr, 0, field_treat, ref_field ? ref_field->id : 0);
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
  return ref_field;
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
                              void *info,
                              void *ptr,//for classes, pointer to SerializeBaseClass
                              enum ArchiveFieldTreat field_treat
                              )
{
  archive_field  *new_field;
  archive_field  *ref_field = NULL;
  bool      exch_fields = false;
  //int id = 0;
  if(field_treat != ARCHIVE_FIELD_IS_BASECLASS)
  {
    if(!is_class)
      ref_field = check_nonclass_pointer(ptr);
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
  if(!exch_fields)
  {
    new_field->parent = current_compound_field;
    new_field->id = ++nr_ids;
    if(current_compound_field->last_child)
      current_compound_field->last_child->next = new_field;
    else
      current_compound_field->first_child = new_field;
    current_compound_field->last_child = new_field;
    if(!ref_field)
      current_compound_field = new_field;
  }
  else
  {
    exchange_fields(new_field, ref_field);
  }
  return ref_field;
}

void Archiver::add_end_compound_field()
{
  current_compound_field = current_compound_field->parent;
}

void Archiver::set_class_type(const char *class_name)
{
  free(current_compound_field->type);
  current_compound_field->type = _strdup(class_name);
}

archive_field* Archiver::check_nonclass_pointer(void *ptr)
{
  if(!ptr)
    return NULL;

  return check_nonclass_pointer_internal(ptr, out_fields);
}

archive_field* Archiver::check_nonclass_pointer_internal(void *ptr, archive_field *fields)
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

archive_field* Archiver::check_class_pointer(SerializeBaseClass *ptr)
{
  if(!ptr)
    return NULL;
  return check_class_pointer_internal(ptr, out_fields);
}

archive_field* Archiver::check_class_pointer_internal(SerializeBaseClass *ptr, archive_field *fields)
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
  if(!is_simple || strcmp(type, required_type))
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
  if(field_treat != required_field_treat)
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
  if(is_simple || is_class || strcmp(type, required_type))
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
  if(field_treat != required_field_treat)
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
  if(is_simple || !is_class || strcmp(type, required_type))
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
  if(field_treat != required_field_treat)
  {
    ZORBA_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
  }
}

void Archiver::register_reference(int id, void *ptr)
{
  struct field_ptr_vs_id    fid;
  fid.field_id = id;
  fid.assoc_ptr = ptr;
  all_reference_list.push_back(fid);
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
  if(class_name)
    fid.class_name = _strdup(class_name);
  else
    fid.class_name = NULL;
  fwd_reference_list.push_back(fid);
}

void *Archiver::get_reference_value(int refid)
{
  std::list<field_ptr_vs_id>::iterator    all_it;
  for(all_it=all_reference_list.begin(); all_it != all_reference_list.end(); all_it++)
  {
    if((*all_it).field_id == refid)
      return (*all_it).assoc_ptr;
  }
  return NULL;
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
    }
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
}}
