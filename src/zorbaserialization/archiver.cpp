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

#include "store/api/item.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"

#include "zorbautils/hashmap.h"

#include "zorbatypes/collation_manager.h"

#include "zorbaserialization/archiver.h"
#include "zorbaserialization/archiver_field.h"
#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/mem_archiver.h"


namespace zorba
{

namespace serialization
{


/*******************************************************************************
  Constructor for simple non-pointer fields
********************************************************************************/
archive_field::archive_field(
    TypeCode type,
    const void* ptr,
    ArchiveFieldKind kind,
    int only_for_eval,
    ENUM_ALLOW_DELAY allow_delay,
    unsigned int level)
  :
  theId(0),
  theIsSimple(true),
  theIsClass(false),
  theKind(kind),
  theType(type),
  theValuePosInPool(0),
  theObjPtr(ptr),
  theReferredField(NULL),
  theLevel(level),
  theNextSibling(NULL),
  theFirstChild(NULL),
  theLastChild(NULL),
  theParent(NULL),
  theOnlyForEval(only_for_eval),
  theAllowDelay2(allow_delay)
{
  assert(theKind == ARCHIVE_FIELD_NORMAL);

  switch (type)
  {
  case TYPE_INT64:
  {
    theValue.int64v = *static_cast<const int64_t*>(ptr);
    break;
  }
  case TYPE_UINT64:
  {
    theValue.uint64v = *static_cast<const uint64_t*>(ptr);
    break;
  }
  case TYPE_INT32:
  {
    theValue.int32v = *static_cast<const int32_t*>(ptr);
    break;
  }
  case TYPE_UINT32:
  {
    theValue.uint32v = *static_cast<const uint32_t*>(ptr);
    break;
  }
  case TYPE_ENUM:
  {
    theValue.uint32v = *static_cast<const uint32_t*>(ptr);
    break;
  }
  case TYPE_INT16:
  {
    theValue.int16v = *static_cast<const int16_t*>(ptr);
    break;
  }
  case TYPE_UINT16:
  {
    theValue.uint16v = *static_cast<const uint16_t*>(ptr);
    break;
  }
  case TYPE_CHAR:
  {
    theValue.charv = *static_cast<const char*>(ptr);
    break;
  }
  case TYPE_UCHAR:
  {
    theValue.ucharv = *static_cast<const unsigned char*>(ptr);
    break;
  }
  case TYPE_BOOL:
  {
    theValue.boolv = *static_cast<const bool*>(ptr);
    break;
  }
  case TYPE_ZSTRING:
  {
    theStringValue = *static_cast<const zstring*>(ptr);
    break;
  }
  case TYPE_STD_STRING:
  {
    theStringValue = *static_cast<const std::string*>(ptr);
    break;
  }
  case TYPE_COLLATOR:
  {
    theStringValue = (static_cast<const XQPCollator*>(ptr))->getURI();
    break;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  theBytesSaved = 0;
  theObjectsSaved = 0;
#endif
}


/*******************************************************************************
  Constructor for simple or compound fields
********************************************************************************/
archive_field::archive_field(
    TypeCode type,
    bool is_simple,
    bool is_class,
    const void* ptr,
    ArchiveFieldKind kind,
    archive_field* refered,
    int only_for_eval,
    ENUM_ALLOW_DELAY allow_delay,
    unsigned int level)
  :
  theId(0),
  theIsSimple(is_simple),
  theIsClass(is_class),
  theKind(kind),
  theType(type),
  theValuePosInPool(0),
  theObjPtr(ptr),
  theReferredField(refered),
  theLevel(level),
  theNextSibling(NULL),
  theFirstChild(NULL),
  theLastChild(NULL),
  theParent(NULL),
  theOnlyForEval(only_for_eval),
  theAllowDelay2(allow_delay)
{
  assert(type != TYPE_UNKNOWN);

#ifdef ZORBA_PLAN_SERIALIZER_STATISTICS
  theBytesSaved = 0;
  theObjectsSaved = 0;
#endif
}


/*******************************************************************************

********************************************************************************/
archive_field::~archive_field()
{
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
  theArchiveVersion(ClassSerializer::g_zorba_classes_version),
  theSerializingOut(is_serializing_out),
  theSerializeBaseClass(false),
  theIsTempField(0),
  theCompilerCB(NULL),
  theFieldCounter(0),
  theRootField(0),
  theCurrentCompoundField(0),
  theCurrentLevel(0),
  theNonClassFieldsMap(0),
  theClassFieldsMap(0),
  theOnlyForEval(0),
  all_reference_list(0),
  internal_archive(internal_archive),
  theSerializeEverything(false),
  loading_hardcoded_objects(false),
  theAllowDelay2(ALLOW_DELAY),
  theUserCallback(0),
  dont_allow_delay_for_plan_sctx(false)
{
  if (theSerializingOut)
  {
    //create the top most field
    theRootField = new archive_field(TYPE_LAST,
                                     false, // is_simple
                                     false, // is_class
                                     NULL,  // ptr
                                     ARCHIVE_FIELD_NORMAL,
                                     NULL,  // referred
                                     false, // only for eval
                                     ALLOW_DELAY,
                                     0);    // level

    theCurrentCompoundField = theRootField;

    theNonClassFieldsMap = 
    new HashMap<const void*, archive_field*, FieldCompare>(1000, false);

    theClassFieldsMap = 
    new HashMap<const void*, archive_field*, FieldCompare>(1000, false);
  }

  if (!internal_archive)
  {
    Archiver* har = ClassSerializer::getInstance()->harcoded_objects_archive;
    theFieldCounter = har->theFieldCounter;
  }
}


/*******************************************************************************

********************************************************************************/
Archiver::~Archiver()
{
  delete theRootField;
  delete [] all_reference_list;
  delete theNonClassFieldsMap;
  delete theClassFieldsMap;

  std::vector<archive_field*>::const_iterator orphan_it;
  for (orphan_it = orphan_fields.begin(); orphan_it != orphan_fields.end(); ++orphan_it)
  {
    delete (*orphan_it);
  }
}


/*******************************************************************************

********************************************************************************/
bool Archiver::get_is_temp_field_one_level()
{
  if (limit_temp_level_stack.empty())
  {
    return false;
  }
  else if (limit_temp_level_stack.top() == theCurrentLevel)
  {
    return true;
  }
  else
  {
    unsigned int lastlevel = limit_temp_level_stack.top();
    archive_field* temp_field = theCurrentCompoundField;

    assert(!temp_field || temp_field->theLevel <= theCurrentLevel);
    assert(!temp_field || temp_field->theLevel >= lastlevel);
    
    while (temp_field && (temp_field->theLevel >= lastlevel))
    {
      if (temp_field->theKind == ARCHIVE_FIELD_PTR ||
          temp_field->theKind == ARCHIVE_FIELD_REFERENCING)
        return false;
      
      temp_field = temp_field->theParent;
    }
    
    if (temp_field)
      return true;
    else
      return false;
  }
} 


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Serialization only                                                        //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void Archiver::add_simple_temp_field(TypeCode type, const void* ptr)
{
  archive_field* new_field;

  ++theCurrentLevel;

  assert(ptr);

  new_field = new archive_field(type,
                                ptr,
                                ARCHIVE_FIELD_NORMAL,
                                get_serialize_only_for_eval(),
                                theAllowDelay2,
                                theCurrentLevel);

  theAllowDelay2 = ALLOW_DELAY;

  new_field->theOrder = theFieldCounter + 1;
  
  new_field->theParent = theCurrentCompoundField;

  if (theCurrentCompoundField->theLastChild)
    theCurrentCompoundField->theLastChild->theNextSibling = new_field;
  else
    theCurrentCompoundField->theFirstChild = new_field;
  
  theCurrentCompoundField->theLastChild = new_field;

  --theCurrentLevel;
}



/*******************************************************************************
  Create a "simple" field (ARCHIVE_FIELD_PTR, or ARCHIVE_FIELD_NUL, or
  ARCHIVE_FIELD_NORMAL).

  Return true if field is not referencing
********************************************************************************/
bool Archiver::add_simple_ptr_field(TypeCode type, const void* ptr)
{
  archive_field* new_field;
  archive_field* ref_field = NULL;

  ++theCurrentLevel;

  if (ptr && !get_is_temp_field())
  {
    ref_field = lookup_non_class_field(ptr);
  }

  if (ref_field)
  {
    ZORBA_ASSERT(ref_field->theKind == ARCHIVE_FIELD_PTR ||
                 ref_field->theKind == ARCHIVE_FIELD_NORMAL);

    if (get_is_temp_field_one_level() && theAllowDelay2 == ALLOW_DELAY)
    {
      theAllowDelay2 = DONT_ALLOW_DELAY;
    }

    new_field = new archive_field(type,
                                  true,       // is_simple
                                  false,      // is_class
                                  NULL,       // ptr
                                  ARCHIVE_FIELD_REFERENCING,
                                  ref_field,
                                  get_serialize_only_for_eval(),
                                  theAllowDelay2,
                                  theCurrentLevel);
  }
  else if (ptr)
  {
    new_field = new archive_field(type,
                                  ptr,
                                  ARCHIVE_FIELD_PTR,
                                  get_serialize_only_for_eval(),
                                  theAllowDelay2,
                                  theCurrentLevel);
  }
  else
  {
    new_field = new archive_field(type,
                                  true,       // is_simple
                                  false,      // is_class
                                  NULL,       // ptr
                                  ARCHIVE_FIELD_NULL,
                                  NULL,
                                  get_serialize_only_for_eval(),
                                  theAllowDelay2,
                                  theCurrentLevel);
  }

  theAllowDelay2 = ALLOW_DELAY;

  if (!ref_field && ptr && !get_is_temp_field())
  {
    theNonClassFieldsMap->insert(ptr, new_field);
  }

  if (ptr == NULL || ref_field != NULL)
  {
    new_field->theId = 0;
    new_field->theOrder = theFieldCounter + 1;
  }
  else
  {
    new_field->theId = ++theFieldCounter;
    new_field->theOrder = new_field->theId;
  }

  new_field->theParent = theCurrentCompoundField;

  if (theCurrentCompoundField->theLastChild)
    theCurrentCompoundField->theLastChild->theNextSibling = new_field;
  else
    theCurrentCompoundField->theFirstChild = new_field;
  
  theCurrentCompoundField->theLastChild = new_field;

  --theCurrentLevel;

  return ref_field != NULL;
}


/*******************************************************************************

********************************************************************************/
bool Archiver::add_compound_field(
    TypeCode type,
    bool is_class,
    const void* ptr,
    ArchiveFieldKind field_kind)
{
  archive_field* new_field;
  archive_field* ref_field = NULL;

  ++theCurrentLevel;

  if (!ptr)
  {
    field_kind = ARCHIVE_FIELD_NULL;
    --theCurrentLevel;
  }
  else if (field_kind != ARCHIVE_FIELD_BASECLASS &&
           !get_is_temp_field() &&
           (!get_is_temp_field_one_level() || field_kind == ARCHIVE_FIELD_PTR))
  {
    if (is_class)
      ref_field = lookup_class_field(ptr);
    else
      ref_field = lookup_non_class_field(ptr);
  }

  if (ref_field)
  {
    ZORBA_ASSERT(field_kind != ARCHIVE_FIELD_NORMAL);
    ZORBA_ASSERT(ref_field->theKind == ARCHIVE_FIELD_PTR ||
                 ref_field->theKind == ARCHIVE_FIELD_NORMAL);

    if (get_is_temp_field_one_level() && 
        field_kind == ARCHIVE_FIELD_PTR &&
        theAllowDelay2 == ALLOW_DELAY)
    {
      theAllowDelay2 = DONT_ALLOW_DELAY;
    }

    field_kind = ARCHIVE_FIELD_REFERENCING;
    ptr = NULL;
  }

  new_field = new archive_field(type,
                                false,     // is_simple
                                is_class,
                                ptr,
                                field_kind,
                                ref_field,
                                get_serialize_only_for_eval(), 
                                theAllowDelay2,
                                theCurrentLevel);

  theAllowDelay2 = ALLOW_DELAY;

  if (!ref_field &&
      field_kind != ARCHIVE_FIELD_BASECLASS &&
      ptr &&
      !get_is_temp_field() &&
      (!get_is_temp_field_one_level() || field_kind == ARCHIVE_FIELD_PTR))
  {
    if (is_class)
      theClassFieldsMap->insert(ptr, new_field);
    else
      theNonClassFieldsMap->insert(ptr, new_field);
  }

  new_field->theParent = theCurrentCompoundField;

  if (field_kind == ARCHIVE_FIELD_REFERENCING ||
      field_kind == ARCHIVE_FIELD_NULL ||
      field_kind == ARCHIVE_FIELD_BASECLASS)
  {
    new_field->theId = 0;
    new_field->theOrder = theFieldCounter + 1;
  }
  else
  {
    new_field->theId = ++theFieldCounter;
    new_field->theOrder = new_field->theId;
  }

  if (theCurrentCompoundField->theLastChild)
    theCurrentCompoundField->theLastChild->theNextSibling = new_field;
  else
    theCurrentCompoundField->theFirstChild = new_field;
  
  theCurrentCompoundField->theLastChild = new_field;

  if (!ref_field && ptr)
    theCurrentCompoundField = new_field;

  if (ref_field)
    --theCurrentLevel;

  return ref_field != NULL;
}


/*******************************************************************************

********************************************************************************/
void Archiver::add_end_compound_field()
{
  theCurrentCompoundField = theCurrentCompoundField->theParent;
  --theCurrentLevel;
}


/*******************************************************************************
  Check whether there exists already a field for the nonclass object at the given
  memory address.
********************************************************************************/
archive_field* Archiver::lookup_non_class_field(const void* ptr)
{
  if (!ptr)
    return NULL;

  archive_field* duplicate_field = NULL;

  theNonClassFieldsMap->get(ptr, duplicate_field);

  if (!duplicate_field)
  {
    Archiver* har = ::zorba::serialization::ClassSerializer::getInstance()->
    getArchiverForHardcodedObjects();

    if (har != this)
      duplicate_field = har->lookup_non_class_field(ptr);
  }

  return duplicate_field;
}


/*******************************************************************************
  Check whether there exists already a field for the non-simple object at the 
  given memory address.
********************************************************************************/
archive_field* Archiver::lookup_class_field(const void* ptr)
{
  if (!ptr)
    return NULL;

  archive_field* duplicate_field = NULL;

  theClassFieldsMap->get(ptr, duplicate_field);

  if (!duplicate_field)
  {
    Archiver* har = ::zorba::serialization::ClassSerializer::getInstance()->
    getArchiverForHardcodedObjects();

    if (har != this)
      duplicate_field = har->lookup_class_field(ptr);
  }

  return duplicate_field;
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
void Archiver::check_compound_fields(archive_field* parent_field)
{
  //resolve all references first
  //iterate: find the reference to the top most eval_only field and resolve it
  archive_field* refering_field;

  while (1)
  {
    refering_field = find_top_most_eval_only_field(parent_field);

    if(!refering_field)
      break;

    if((refering_field->theReferredField->theAllowDelay2 != ALLOW_DELAY) ||
      (refering_field->theReferredField->theKind == ARCHIVE_FIELD_NORMAL) ||
      !refering_field->theReferredField->theOnlyForEval)
    {
      //must preserve this serialization
      archive_field* temp_field = refering_field->theReferredField->theParent;
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

    clean_only_for_eval(refering_field->theReferredField,
                        get_only_for_eval(refering_field->theReferredField));
  }

  while (check_only_for_eval_nondelay_referencing(parent_field))
  {
  }

  replace_only_for_eval_with_null(parent_field);
}


/*******************************************************************************

********************************************************************************/
archive_field* Archiver::find_top_most_eval_only_field(archive_field* parent_field)
{
  int ref_depth = -1;
  archive_field* refering_field = NULL;

  archive_field* child = parent_field->theFirstChild;
  
  while (child)
  {
    if (child->theOnlyForEval)
    {
    }
    else if (child->theKind == ARCHIVE_FIELD_REFERENCING &&
             get_only_for_eval(child->theReferredField))
    {
      int new_depth = compute_field_depth(child->theReferredField);
      if(!refering_field || (ref_depth > new_depth))
      {
        ref_depth = new_depth;
        refering_field = child;
      }
    }
    else if (!child->theIsSimple && !child->theReferredField)
    {
      archive_field* new_refering = find_top_most_eval_only_field(child);

      if (new_refering)
      {
        int new_depth = compute_field_depth(new_refering->theReferredField);
        if (!refering_field || (ref_depth > new_depth))
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
int Archiver::compute_field_depth(archive_field* field)
{
  archive_field* temp;
  int i = 0;
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
  if (field->theOnlyForEval)
    return field->theOnlyForEval;

  archive_field* child;
  for (child = field->theFirstChild; child; child = child->theNextSibling)
  {
    if (child->theOnlyForEval)
      return child->theOnlyForEval;
  }

  return 0;
}


/*******************************************************************************

********************************************************************************/
void Archiver::clean_only_for_eval(archive_field* field, int substract_value)
{
  if (field->theOnlyForEval >= substract_value)
    field->theOnlyForEval -= substract_value;
  else
    field->theOnlyForEval = 0;

  if (!field->theIsSimple)
  {
    archive_field* child = field->theFirstChild;
    while (child)
    {
      clean_only_for_eval(child, substract_value);
      child = child->theNextSibling;
    }
  }
}


/*******************************************************************************

********************************************************************************/
bool Archiver::check_only_for_eval_nondelay_referencing(archive_field* parent_field)
{
  archive_field* current_field = parent_field->theFirstChild;

  while (current_field)
  {
    if (current_field->theOnlyForEval && current_field->theKind != ARCHIVE_FIELD_NORMAL)
    {
      if (current_field->theKind == ARCHIVE_FIELD_REFERENCING &&
          current_field->theAllowDelay2 != ALLOW_DELAY &&
          !current_field->theReferredField->theOnlyForEval)
      {
        //must preserve this serialization
        archive_field* temp_field = current_field->theParent;
        while (temp_field)
        {
          temp_field->theOnlyForEval = 0;
          temp_field = temp_field->theParent;
        }
        clean_only_for_eval(current_field, current_field->theOnlyForEval);
        return true;
      }
    }

    if (!current_field->theIsSimple)
    {
      if (check_only_for_eval_nondelay_referencing(current_field))
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
  archive_field* current_field = parent_field->theFirstChild;

  while (current_field)
  {
    if (current_field->theOnlyForEval &&
        (current_field->theKind != ARCHIVE_FIELD_NORMAL) &&
        (current_field->theKind != ARCHIVE_FIELD_BASECLASS))
    {
      //don't save it, replace it with NULL if possible
      archive_field* null_field = replace_with_null(current_field);

      orphan_fields.push_back(current_field);
      current_field = null_field;
    }

    if (!current_field->theIsSimple)
    {
      replace_only_for_eval_with_null(current_field);
    }

    current_field = current_field->theNextSibling;
  }
}


/*******************************************************************************

********************************************************************************/
archive_field* Archiver::replace_with_null(archive_field* current_field)
{
  if (current_field->theParent)
  {
    archive_field* null_field = new archive_field(TYPE_NULL,
                                                  current_field->theIsSimple,
                                                  current_field->theIsClass,
                                                  NULL,
                                                  ARCHIVE_FIELD_NULL,
                                                  NULL,
                                                  false,
                                                  ALLOW_DELAY,
                                                  current_field->theLevel);
    null_field->theId = 0;
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
bool Archiver::check_allowed_delays(archive_field* parent_field)
{
  //check all fields with dont_allow_delay and see if they are delayed
  //exchange field with the reference then
  archive_field* child = parent_field->theFirstChild;

  while (child)
  {
    if (child->theKind == ARCHIVE_FIELD_REFERENCING &&
        check_order(child, child->theReferredField) < 1)
    {
      ZORBA_ASSERT(false);
    }

    if (child->theKind == ARCHIVE_FIELD_REFERENCING &&
       ((child->theAllowDelay2 == DONT_ALLOW_DELAY &&
         check_order(child, child->theReferredField) < 1) ||
        child->theAllowDelay2 == SERIALIZE_NOW))
    {
      if (child->theReferredField->theKind == ARCHIVE_FIELD_NORMAL ||
          child->theReferredField->theAllowDelay2 == SERIALIZE_NOW)
      {
        //impossible to solve situation
        //need to change the serialization order somewhere
        throw ZORBA_EXCEPTION(zerr::ZCSE0014_INFINITE_CIRCULAR_DEPENDENCIES);
      }

      //exchange fields
      exchange_mature_fields(child, child->theReferredField);

      child = child->theReferredField;

      return true;
    }

    if (check_allowed_delays(child))
      return true;

    child = child->theNextSibling;
  }

  return false;
}


/*******************************************************************************
  return 0 if not found
  return -1 if field1 is before field2
  return 1  if field1 is after field2
********************************************************************************/
int Archiver::check_order(archive_field* field1, archive_field* field2)
{

  if (field1->theOrder < field2->theOrder)
    return -1;
  else if (field1->theOrder == field2->theOrder)
    return 0;
  else
    return 1;
}


/*******************************************************************************

********************************************************************************/
void Archiver::exchange_mature_fields(archive_field* field1, archive_field* field2)
{
  archive_field* field1_prev = get_prev(field1);
  archive_field* field1_next = field1->theNextSibling;
  archive_field* field1_parent = field1->theParent;
  archive_field* field2_prev = get_prev(field2);
  archive_field* field2_parent = field2->theParent;
  archive_field* field2_next = field2->theNextSibling;

  //move field2
  if (field1_prev)
    field1_prev->theNextSibling = field2;
  else
    field1_parent->theFirstChild = field2;

  field2->theNextSibling = field1_next;

  if (!field1_next)
    field1_parent->theLastChild = field2;

  field2->theParent = field1_parent;

  //move field1
  if (field2_prev)
    field2_prev->theNextSibling = field1;
  else
    field2_parent->theFirstChild = field1;

  field1->theNextSibling = field2_next;

  if (!field2_next)
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


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  De-Serialization only                                                     //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void Archiver::root_tag_is_read()
{
  if (theArchiveVersion != ClassSerializer::g_zorba_classes_version)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0012_INCOMPATIBLE_ARCHIVE_VERSION,
    ERROR_PARAMS(theArchiveVersion, ClassSerializer::g_zorba_classes_version));
  }

  all_reference_list = new void*[theFieldCounter+1];

  memset(all_reference_list, 0, sizeof(void*)*(theFieldCounter+1));
}


/*******************************************************************************

********************************************************************************/
void Archiver::read_next_compound_field(
    bool is_class,
    ArchiveFieldKind& field_kind,
    TypeCode& type, 
    int& id,
    int& referencing)
{
  read_next_compound_field_impl(is_class, field_kind, type, id, referencing);

  if (field_kind != ARCHIVE_FIELD_REFERENCING)
    ++theCurrentLevel;
}


/*******************************************************************************

********************************************************************************/
void Archiver::read_next_simple_ptr_field(TypeCode type, void** obj)
{
  read_next_simple_ptr_field_impl(type, obj);
}


/*******************************************************************************

********************************************************************************/
void Archiver::read_next_simple_temp_field(TypeCode type, void* obj)
{
  read_next_simple_temp_field_impl(type, obj);
}


/*******************************************************************************

********************************************************************************/
void Archiver::read_end_current_level()
{
  --theCurrentLevel;
  read_end_current_level_impl();
}


/*******************************************************************************

********************************************************************************/
void Archiver::check_nonclass_field(
    ArchiveFieldKind field_treat,
    ArchiveFieldKind required_field_treat,
    int id)
{
  if (field_treat == ARCHIVE_FIELD_NULL)
    return;

  if ((required_field_treat != (enum ArchiveFieldKind)-1) &&
      field_treat != required_field_treat)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
}


/*******************************************************************************

********************************************************************************/
void Archiver::check_class_field(
    TypeCode type,
    TypeCode required_type,
    ArchiveFieldKind field_treat,
    ArchiveFieldKind required_field_treat,
    int id)
{
  if (field_treat == ARCHIVE_FIELD_NULL)
    return;

  if ((required_field_treat != (ArchiveFieldKind)-1) && 
     field_treat != required_field_treat)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }

#ifndef NDEBUG
  if (field_treat == ARCHIVE_FIELD_PTR && type != required_type)
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
  }
#endif
}


/*******************************************************************************

********************************************************************************/
void Archiver::register_reference(int id, ArchiveFieldKind field_kind, const void* ptr)
{
  if (get_is_temp_field())
    return;

  if (get_is_temp_field_one_level() && field_kind != ARCHIVE_FIELD_PTR)
    return;

  all_reference_list[id] = (void*)ptr;
}


/*******************************************************************************

********************************************************************************/
void Archiver::register_item(store::Item* i)
{
  if (i)
    registered_items.push_back(i);
}


/*******************************************************************************

********************************************************************************/
void* Archiver::get_reference_value(int refid)
{
  if (internal_archive && !all_reference_list)
  {
    //construct all_reference_list
    root_tag_is_read();
    register_pointers_internal(theRootField);
  }

  void* assoc_ptr = NULL;

  if (!(assoc_ptr = all_reference_list[refid]))
  {
    Archiver* har = ::zorba::serialization::ClassSerializer::getInstance()->
                    getArchiverForHardcodedObjects();

    if (har != this)
      assoc_ptr = har->get_reference_value(refid);
  }

  return assoc_ptr;
}


/*******************************************************************************

********************************************************************************/
void Archiver::register_pointers_internal(archive_field* fields)
{
  archive_field* child;
  child = fields->theFirstChild;

  while (child)
  {
    register_reference(child->theId, child->theKind, child->theObjPtr);
    if (!child->theIsSimple)
    {
      register_pointers_internal(child);
    }
    child = child->theNextSibling;
  }
}


/*******************************************************************************
  Decrement RC on Items
********************************************************************************/
void Archiver::finalize_input_serialization()
{
  std::vector<store::Item*>::iterator item_it;

  for (item_it = registered_items.begin();
       item_it != registered_items.end();
       ++item_it)
  {
    if ((*item_it)->isNode())
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


} // namsspace serialization
} // namespace zorba
/* vim:set et sw=2 ts=2: */
