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
#ifndef ZORBA_BINARY_SERIALIZATION_ARCHIVER_FIELD
#define ZORBA_BINARY_SERIALIZATION_ARCHIVER_FIELD

#include "zorbaserialization/plan_settings.h"
#include "zorbaserialization/archiver_consts.h"

#include "store/api/shared_types.h"

namespace zorba
{

namespace serialization
{

class SerializeBaseClass;

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
  For example, an std::vector<> is a compound, non-class obj.

  theKind:
  --------
  The kind of the field. See ArchiveFieldKind enum above.

  theTypeName:
  ------------

  theTypeNamePosInPool:
  ---------------------
  The position of theTypeName string within the string pool. The string pool
  is created after the fields tree has been fully built and just before we
  start actually writting stuff out to "disk". theTypeName string is copied
  into the string pool only if theKind is PTR and theIsClass is true.

  theValue:
  ---------

  theValuePosInPool:
  ------------------
  The position of theValue string within the string pool. The string pool
  is created after the fields tree has been fully built and just before we
  start actually writting stuff out to "disk". theValue string is copied
  into the string pool only if theKind is PTR or NORMAL.

  thePtr :
  --------
  Pointer to the obj represented by this field. NULL for FIELD_REFERENCING and
  FIELD_NULL fields.

  theReferredField:
  -----------------

  referencing:
  ------------

  theOrder:
  ---------
  Order in the tree. Not initialized by constructor.

  theLevel:
  ---------
  The level of this field, i.e., the nuber of fields in the path from this
  field to the root. The root is at level 0.

  theNextSibling:
  ---------------
  The right sibling of this field (if any).

  theFirstChild:
  --------------
  The 1st child of this field (if any).

  theLastChild:
  -------------
  The last child of this field (if any).

  theParent:
  ----------
  The parent field in the fields tree.

  theOnlyForEval:
  ---------------

  theAllowDelay2:
  ---------------

  theBytesSaved:
  --------------

  theObjectsSaved:
  ----------------

  The following data members are serialized:

  1. theTypeName  : only if theKind is PTR and theIsClass is true.
  2. theValue     : except if theKind is REFERENCING or NULL
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

  ArchiveFieldKind             theKind;

  TypeCode                     theType;
  char                       * theTypeName;
  csize                        theTypeNamePosInPool;

  SimpleValue                  theValue;
  csize                        theValuePosInPool;

  union
  {
    const SerializeBaseClass * assoc_class_ptr;
    const void               * assoc_ptr;
  };

  archive_field              * theReferredField;
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
      const void* ptr,
      enum ArchiveFieldKind kind,
      archive_field* refered,
      int only_for_eval,
      ENUM_ALLOW_DELAY allow_delay,
      unsigned int level);

  archive_field(
      TypeCode type,
      SimpleValue value,
      const void* ptr,
      ArchiveFieldKind kind,
      int only_for_eval,
      ENUM_ALLOW_DELAY allow_delay,
      unsigned int level);

  ~archive_field();
};



}
}
#endif
/* vim:set et sw=2 ts=2: */
