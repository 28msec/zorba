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
#ifndef ZORBA_BINARY_SERIALIZATION_ARCHIVER_CONSTS
#define ZORBA_BINARY_SERIALIZATION_ARCHIVER_CONSTS

namespace zorba
{

namespace serialization
{

#define FIELD_IS_SIMPLE   true
#define FIELD_IS_CLASS    true


/*******************************************************************************

  ARCHIVE_FIELD_NORMAL:
  ---------------------
  A field of kind NORMAL or PTR acts as the root of a tree of fields representing
  the serialization of a concrete obj. If the kind is PTR, then the obj was 
  serialized when a pointer to it was encountered. In this case, during 
  deserialization, the archiver will allocate the obj on the heap and fill-in
  its data members. If the kind is NORMAL, then the obj was serialized when the 
  objitself was encountered (e.g., the object was an embedded data member of 
  another obj, or was residing on the program stack). In this case, during 
  deserialization, the object exists already (in an uninitialized state) and a
  reference to it is given to the archiver, which will fill-in the obj's data.

  ARCHIVE_FIELD_PTR:
  ------------------
  See comment for ARCHIVE_FIELD_NORMAL.

  ARCHIVE_FIELD_REFERENCING:
  --------------------------
  A field A that references another field B (of kind NORMAL or PTR), where both
  A and B represent the "same" object. 

  ARCHIVE_FIELD_BASECLASS:
  ------------------------
  A field representing a "partial" class object: If an obj O belongs to a 
  concrete class C and C is a subclass of a base class B, then a field of 
  BASECLASS kind is created to represent the serialization of the data members
  of B. This field is placed as the 1st child of the NORMAL or PTR field that 
  represents the serialization of O, and the children of the BASECALSS field
  represent the serializations of B's data members. If B itself is a subclass
  of another class A, then the 1st child of the B BASECLASS field is another
  BASECLASS field representing class A, etc.

  ARCHIVE_FIELD_NULL:
  -------------------
  A field representing a NULL pointer.

********************************************************************************/
enum ArchiveFieldKind
{
  ARCHIVE_FIELD_NORMAL,
  ARCHIVE_FIELD_PTR,
  ARCHIVE_FIELD_NULL,
  ARCHIVE_FIELD_BASECLASS,
  ARCHIVE_FIELD_REFERENCING
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
enum TypeCode
{
  TYPE_UNKNOWN = 0,

  TYPE_INT64,
  TYPE_UINT64,
  TYPE_INT32,
  TYPE_UINT32,
  TYPE_INT16,
  TYPE_UINT16,
  TYPE_CHAR,
  TYPE_UCHAR,
  TYPE_FLOAT,
  TYPE_DOUBLE,
  TYPE_BOOL,

  TYPE_STD_STRING,
  TYPE_ZSTRING,

  TYPE_MAX
};


/*******************************************************************************

********************************************************************************/
typedef union
{
  const char    * cstrv;
  int64_t         int64v;
  uint64_t        uint64v;
  int32_t         int32v;
  uint32_t        uint32v;  
  int16_t         int16v;
  uint16_t        uint16v;
  char            charv;
  unsigned char   ucharv;
  bool            boolv;
} SimpleValue;
  

}
}
#endif
/* vim:set et sw=2 ts=2: */
