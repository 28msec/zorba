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
#ifndef ZORBA_BINARY_PLAN_ITERATOR_SERIALIZATION
#define ZORBA_BINARY_PLAN_ITERATOR_SERIALIZATION

#include <time.h>

#include "zorbamisc/config/platform.h"

#include <string>
#include <list>
#include <vector>
#include <assert.h>
#include <iostream>
#include <typeinfo>
#include <string.h>



namespace zorba
{

class XQPCollator;

namespace serialization
{

class SerializeBaseClass;
class Archiver;
class MemArchiver;
class ClassFactoriesMap;
class ClassDeserializer;


/*******************************************************************************
  The classes and macros defined in this file provide a generic infrastructure
  for making an arbitrary c++ class serializable. This infrastructure is provided
  for convenience; not every c++ type has to adopt this inftrasture.
********************************************************************************/


/*******************************************************************************
  There is only one global instance of this class.

  theClassFactories:
  ------------------
  This map associates the name of a class C with a pointer to the ClassDeserializer
  obj associated with C (if any such obj actually exists). The map is populated
  "automatically", during the instantiation of each ClassDeserializer obj; the 
  constructor of each such obj places an entry into the map.  

  harcoded_objects_archive:
  -------------------------

********************************************************************************/
class ClassSerializer
{
  friend class Archiver;

public:
  static const unsigned long g_zorba_classes_version;

private:
  ClassFactoriesMap   * theClassFactories;

  MemArchiver         * harcoded_objects_archive;

public:
  clock_t   t0;
  clock_t   t1;

public:
  static ClassSerializer* getInstance();

public:
  ClassSerializer();

  ~ClassSerializer();

  void register_class_factory(const char* className, ClassDeserializer* d);

  ClassDeserializer* get_class_factory(const char* classname);

  Archiver* getArchiverForHardcodedObjects();

  void destroyArchiverForHardcodedObjects();

  clock_t get_registration_time() { return t1 - t0; }
};


/*******************************************************************************
  A class that may be used as the base for other c++ classes that need to be 
  serialized.
********************************************************************************/
class ZORBA_DLL_PUBLIC SerializeBaseClass
{
public:
  virtual ~SerializeBaseClass() {}

  virtual void serialize_internal(Archiver& ar) = 0;
};


/*******************************************************************************
  Every serializable class C has a nested member class D that is a subclass of
  ClassDeserializer. Furthermore, every serializable class has a static data
  member of type D, whose initilization (via its default constructor) causes
  class C to be registered in the global ClassSerializer instance.
********************************************************************************/
class ClassDeserializer
{
public:
  virtual ~ClassDeserializer()
  {
  }

  virtual SerializeBaseClass* create_new(Archiver& ar) = 0;

  virtual void cast_ptr(SerializeBaseClass* ptr, void** class_ptr) = 0;
};


/*******************************************************************************

********************************************************************************/
#define SERIALIZABLE_CLASS_FACTORY_DECL(class_name, creator)            \
template<class T_serialized_class>                                      \
class class_factory : public ::zorba::serialization::ClassDeserializer  \
{                                                                       \
public:                                                                 \
  class_factory()                                                       \
  {                                                                     \
    serialization::ClassSerializer::getInstance()->                     \
    register_class_factory(T_serialized_class::get_class_name_str_static(), this); \
  }                                                                     \
                                                                        \
  virtual serialization::SerializeBaseClass* create_new(serialization::Archiver& ar) \
  {                                                                     \
    return creator;                                                     \
  }                                                                     \
                                                                        \
  virtual void cast_ptr(serialization::SerializeBaseClass* ptr, void** class_ptr)\
  {                                                                     \
    *class_ptr = (void*)dynamic_cast<T_serialized_class*>(ptr);         \
  }                                                                     \
};


/*******************************************************************************

********************************************************************************/
#define SERIALIZABLE_CLASS_NO_FACTORY(class_name)                       \
virtual void serialize_internal(::zorba::serialization::Archiver& ar)   \
{                                                                       \
  /*CHECK_CLASS_NAME(class_name)*/                                      \
  if (ar.is_serialize_base_class())                                     \
    ar.set_serialize_base_class(false);                                 \
                                                                        \
  class_name::serialize(ar);                                            \
}                                                                       \
                                                                        \
virtual const char* get_class_name_str() const { return #class_name; }  \
                                                                        \
static const char* get_class_name_str_static() { return #class_name; }


/*******************************************************************************

********************************************************************************/
#define SERIALIZABLE_CLASS(class_name)                                    \
SERIALIZABLE_CLASS_PREFIX(class_name)                                     \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, new class_name(ar))           \
static class_factory<class_name>  g_class_factory;


#define SERIALIZABLE_ABSTRACT_CLASS(class_name)                           \
SERIALIZABLE_CLASS_PREFIX(class_name)                                     \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, NULL)                         \
static class_factory<class_name>  g_class_factory;


#define SERIALIZABLE_CLASS_PREFIX(class_name)                             \
virtual void serialize_internal(::zorba::serialization::Archiver& ar)     \
{                                                                         \
  CHECK_CLASS_NAME(class_name);                                           \
                                                                          \
  if (ar.is_serialize_base_class())                                       \
    ar.set_serialize_base_class(false);                                   \
                                                                          \
  class_name::serialize(ar);                                              \
}                                                                         \
                                                                          \
virtual const char* get_class_name_str() const { return #class_name; }    \
                                                                          \
static const char* get_class_name_str_static() { return #class_name; }


#define SERIALIZABLE_CLASS_VERSIONS(class_name)                           \
class_name::class_factory<class_name> class_name::g_class_factory;


/*******************************************************************************

********************************************************************************/
#define SERIALIZABLE_TEMPLATE_CLASS(class_name)                         \
SERIALIZABLE_TEMPLATE_CLASS_PREFIX(class_name)                          \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, new class_name(ar))         \
static const char                * class_name_str;


#define SERIALIZABLE_TEMPLATE_ABSTRACT_CLASS(class_name)                \
SERIALIZABLE_TEMPLATE_CLASS_PREFIX(class_name)                          \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, NULL)                       \
static const char                * class_name_str;


#define SERIALIZABLE_TEMPLATE_CLASS_PREFIX(class_name)                    \
virtual void serialize_internal(::zorba::serialization::Archiver& ar)     \
{                                                                         \
  CHECK_CLASS_NAME(class_name);                                           \
                                                                          \
  if (ar.is_serialize_base_class())                                       \
    ar.set_serialize_base_class(false);                                   \
                                                                          \
  class_name::serialize(ar);                                              \
}                                                                         \
                                                                          \
virtual const char* get_class_name_str() const { return class_name_str; } \
                                                                          \
static const char* get_class_name_str_static() { return class_name_str; }


//
// Static members of template classes with one template param.
//
// The "index" param of the macro is used as a unique id for each specific
// instantiation of the template class.
//
// Example:
//
// SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(
//     serializable_ItemPointerHashMap, 
//     serializable_ItemPointerHashMap<StaticallyKnownCollection_t>,
//     1)
//
#define SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(template_name, instance_name, index)   \
                                                                                       \
instance_name::class_factory<instance_name> g_class_factory_##template_name##_##index; \
                                                                                       \
template<> const char* instance_name::class_name_str = #instance_name;

//
//  If the template class has more than one template params, e.g. Foo<T1, T2>,
//  then we need this macro because we cannot pass Foo<T1, T2> as the instance_name
//  param of the SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS macro. This is because
//  the "," inside Foo<T1, T2> will make it appear as two params.
//
//  Example:
//
// SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(
//     serializable_HashEntry, 
//     serializable_HashEntry<store::Item*, 
//     StaticallyKnownCollection_t>,
//     1)
//
#define SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(template_name, instance_name, second_T, index) \
instance_name, second_T::class_factory<instance_name,second_T>   \
g_class_factory_##template_name##_##index;                       \
                                                                 \
template<> const char* instance_name, second_T::class_name_str = \
#instance_name "," #second_T;


#define SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(template_name, instance_name, second_T, third_T, index) \
instance_name, second_T, third_T::class_factory<instance_name,second_T,third_T> \
g_class_factory_##template_name##_##index;                                      \
                                                                                \
template<> const char* instance_name, second_T, third_T::class_name_str =       \
#instance_name "," #second_T "," #third_T;


/*******************************************************************************
  Constructors to be used during deserialization
********************************************************************************/

#define SERIALIZABLE_CLASS_CONSTRUCTOR(class_name) \
class_name(::zorba::serialization::Archiver& ar)   \
  :                                                \
  ::zorba::serialization::SerializeBaseClass()     \
{                                                  \
}

#define SERIALIZABLE_CLASS_CONSTRUCTOR2(class_name, base_class) \
class_name(::zorba::serialization::Archiver& ar)                \
  :                                                             \
  base_class(ar)                                                \
{                                                               \
}

#define SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM1(class_name, base_class, param1) \
class_name(::zorba::serialization::Archiver& ar)                \
  :                                                             \
  base_class(ar),                                               \
  param1(NULL)                                                  \
{                                                               \
}

#define SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM2(class_name, base_class, param1, param2) \
class_name(::zorba::serialization::Archiver& ar)                \
  :                                                             \
  base_class(ar),                                               \
  param1(NULL),                                                 \
  param2(NULL)                                                  \
{                                                               \
}

#define SERIALIZABLE_CLASS_CONSTRUCTOR2_NULL_PARAM3(class_name, base_class, param1, param2, param3) \
class_name(::zorba::serialization::Archiver& ar)                \
  :                                                             \
  base_class(ar),                                               \
  param1(NULL),                                                 \
  param2(NULL),                                                 \
  param3(NULL)                                                  \
{                                                               \
}

#define SERIALIZABLE_CLASS_CONSTRUCTOR3(class_name, base_class1, base_class2) \
class_name(::zorba::serialization::Archiver& ar)                              \
  :                                                                           \
  base_class1(ar),                                                            \
  base_class2(ar)                                                             \
{                                                                             \
}

//
// Example:
//
// SERIALIZABLE_CLASS_CONSTRUCTOR2T(SequentialIterator,
// NaryBaseIterator<SequentialIterator, PlanIteratorState>);
//
#define SERIALIZABLE_CLASS_CONSTRUCTOR2T(class_name, base_class, templ2) \
class_name(::zorba::serialization::Archiver& ar)                         \
  :                                                                      \
  base_class , templ2(ar)                                                \
{                                                                        \
}


//
// Example:
//
// SERIALIZABLE_CLASS_CONSTRUCTOR3T(SpecificNumArithIterator,
// BinaryBaseIterator<SpecificNumArithIterator<Operation, Type>, PlanIteratorState>);
//
#define SERIALIZABLE_CLASS_CONSTRUCTOR3T(class_name, base_class, templ2, templ3) \
class_name(::zorba::serialization::Archiver& ar)                                 \
  :                                                                              \
  base_class , templ2, templ3(ar)                                                \
{                                                                                \
}


/*******************************************************************************

********************************************************************************/
#ifndef NDEBUG
#define CHECK_CLASS_NAME(class_name)\
if (ar.is_serializing_out() && !ar.is_serialize_base_class())             \
{                                                                         \
  assert(::strcmp(typeid(*this).name(), typeid(class_name).name()) == 0); \
}
#else
#define CHECK_CLASS_NAME(class_name)
#endif


} // namespace serialization
} // namespace zorba

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
