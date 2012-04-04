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


#define   BACKWARD_COMPATIBLE     true
#define   ZORBA_VERSION_1_5_0     0x010500

extern const unsigned long g_zorba_classes_version;


/*******************************************************************************

********************************************************************************/
struct ClassVersion
{
  int             class_version;
  unsigned long   zorba_version;
  bool            is_backward_compatible;
};


/*******************************************************************************
  Derive all classes that need to be serialized from this base class
********************************************************************************/
class ZORBA_DLL_PUBLIC SerializeBaseClass
{
public:
  virtual ~SerializeBaseClass() {}

  virtual void serialize_internal(Archiver& ar) = 0;

  virtual const ClassVersion& get_classversion(int v) const = 0;

  virtual int get_version_count() const = 0;
};


/*******************************************************************************
  Every serializable class C has a nested member class D that is a subclass of
  class_deserializer. Furthermore, every serializable class has a static data
  member of type D, whose initilization (via its default constructor) causes
  class C to be registered in the global ClassSerializer instance.
********************************************************************************/
class class_deserializer
{
public:
  virtual ~class_deserializer()
  {
  //  std::cout << "~class_deserializer" << std::endl;
  }

  virtual SerializeBaseClass* create_new(Archiver& ar) = 0;

  virtual void cast_ptr(SerializeBaseClass* ptr, void** class_ptr) = 0;
};



/*******************************************************************************
  stateless class, multithreading safe

  class_names:
  ------------
  For each serializable class C, this vector stores the name of C and a pointer
  to the static class_deserializer obj associated with C. The vector is populated
  "automatically", during the instantiation of each static class_deserializer obj
  associated with each serializable class. The constructor of each such obj places 
  an entry into the vector.  

  class_names_count:
  ------------------

  class_factories:
  ----------------

  harcoded_objects_archive:
  -------------------------

********************************************************************************/
class ClassSerializer
{
  friend class Archiver;

private:
  std::vector<std::pair<const char*, class_deserializer*> >  class_names;
  int                                                        class_names_count;
  ClassFactoriesMap                                        * class_factories;

  MemArchiver              * harcoded_objects_archive;

public:
  clock_t   t0;
  clock_t   t1;

public:
  static ClassSerializer* getInstance();

public:
  ClassSerializer();

  ~ClassSerializer();

  void register_class_factory(const char *, class_deserializer *);

  class_deserializer* get_class_factory(const char *classname);

  Archiver* getArchiverForHardcodedObjects();

  void destroyArchiverForHardcodedObjects();//called at shutdown

  clock_t get_registration_time() { return t1-t0;}
};


/*******************************************************************************

********************************************************************************/
#define SERIALIZABLE_CLASS(class_name)                                  \
SERIALIZABLE_CLASS_PREFIX(class_name)                                   \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, new class_name(ar))         \
static const char                             * class_name_str;         \
static const int                                class_versions_count;   \
static const struct serialization::ClassVersion class_versions[];       \
static class_factory<class_name>                g_class_factory;


#define SERIALIZABLE_ABSTRACT_CLASS(class_name)                         \
SERIALIZABLE_CLASS_PREFIX(class_name)                                   \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, NULL)                       \
static const char  * class_name_str;                                    \
static const int     class_versions_count;                              \
static const struct  serialization::ClassVersion class_versions[];      \
static class_factory<class_name> g_class_factory;


#define SERIALIZABLE_TEMPLATE_CLASS(class_name)                         \
SERIALIZABLE_CLASS_PREFIX(class_name)                                   \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, new class_name(ar))         \
static const char                               * class_name_str;       \
static const int                                  class_versions_count; \
static const struct serialization::ClassVersion * class_versions;


#define SERIALIZABLE_TEMPLATE_ABSTRACT_CLASS(class_name)                \
SERIALIZABLE_CLASS_PREFIX(class_name)                                   \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, NULL)                       \
static const char                               * class_name_str;       \
static const int                                  class_versions_count; \
static const struct serialization::ClassVersion * class_versions;


/*******************************************************************************

********************************************************************************/
#define SERIALIZABLE_CLASS_PREFIX(class_name)                             \
virtual void serialize_internal(::zorba::serialization::Archiver& ar)     \
{                                                                         \
  CHECK_CLASS_NAME(class_name);                                           \
                                                                          \
  if (ar.is_serialize_base_class())                                       \
    ar.set_serialize_base_class(false);                                   \
  class_name::serialize(ar);                                              \
}                                                                         \
                                                                          \
virtual const serialization::ClassVersion& get_classversion(int v) const  \
{                                                                         \
  return class_versions[v];                                               \
}                                                                         \
                                                                          \
virtual int get_version_count() const                                     \
{                                                                         \
  return class_versions_count;                                            \
}                                                                         \
                                                                          \
virtual const char* get_class_name_str() const { return class_name_str; } \
                                                                          \
static const char* get_class_name_str_static() { return class_name_str; }


/*******************************************************************************

********************************************************************************/
#define SERIALIZABLE_CLASS_FACTORY_DECL(class_name, creator)            \
template<class T_serialized_class>                                      \
class class_factory : public ::zorba::serialization::class_deserializer \
{                                                                       \
public:                                                                 \
  class_factory()                                                       \
  {                                                                     \
    /*register this class into plan serializer*/                        \
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
  if(ar.is_serialize_base_class())                                      \
    ar.set_serialize_base_class(false);                                 \
                                                                        \
  class_name::serialize(ar);                                            \
}                                                                       \
                                                                        \
virtual const serialization::ClassVersion& get_classversion(int v) const \
{                                                                       \
  return g_##class_name##_class_versions[v];                            \
}                                                                       \
                                                                        \
virtual int get_version_count() const                                   \
{                                                                       \
  return g_##class_name##_class_versions_count;                         \
}                                                                       \
                                                                        \
virtual const char* get_class_name_str() const {return #class_name;}    \
                                                                        \
static const char* get_class_name_str_static() {return #class_name;}



/*******************************************************************************
  Init the serialization-related static members of a non-template serializable
  class.
********************************************************************************/

//
// Static members of non-template classes
//
#define SERIALIZABLE_CLASS_VERSIONS(class_name)                         \
                                                                        \
const char* class_name::class_name_str = #class_name;                   \
                                                                        \
class_name::class_factory<class_name> class_name::g_class_factory;      \
                                                                        \
const serialization::ClassVersion class_name::class_versions[] =        \
{{ 1, ZORBA_VERSION_1_5_0, !BACKWARD_COMPATIBLE}


#define CLASS_VERSION(class_version, zorba_version, compatibility, description) \
  ,{class_version, zorba_version, compatibility}


#define END_SERIALIZABLE_CLASS_VERSIONS(class_name)                     \
  };                                                                    \
  const int class_name::class_versions_count =                          \
  sizeof(class_name::class_versions)/sizeof(struct serialization::ClassVersion);


//
// Define the "versions" and "versions count" static data members of the template class 
//
#define SERIALIZABLE_TEMPLATE_VERSIONS(template_name)                   \
extern const ::zorba::serialization::ClassVersion g_##template_name##_class_versions[] = \
{{ 1, ZORBA_VERSION_1_5_0, !BACKWARD_COMPATIBLE}

//add CLASS_VERSION here

#define END_SERIALIZABLE_TEMPLATE_VERSIONS(template_name)   \
};                                                          \
extern const int g_##template_name##_class_versions_count = \
sizeof(g_##template_name##_class_versions)/sizeof(struct ::zorba::serialization::ClassVersion);


//
// Define the versions dependency from template instance to template versions
// Example:
//
// SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(
//     serializable_ItemPointerHashMap, 
//     serializable_ItemPointerHashMap<StaticallyKnownCollection_t>,
//     1)
//
#define SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(template_name, instance_name, index)    \
                                                                                        \
instance_name::class_factory<instance_name>  g_class_factory_##template_name##_##index; \
                                                                                        \
template<> const ::zorba::serialization::ClassVersion* instance_name::class_versions =  \
g_##template_name##_class_versions;                                                     \
                                                                                        \
template<> const int instance_name::class_versions_count =                              \
g_##template_name##_class_versions_count;                                               \
                                                                                        \
template<> const char* instance_name::class_name_str = #instance_name;

//
//  If the template class has more than one template params, e.g. Foo<T1, T2>,
//  then we need this macro because we cannot pass Foo<T1, T2> as the instance_name
//  param of the SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS macro. This is because
//  the "," inside Foo<T1, T2> will make it appear as two params.
//  Example:
//
// SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(
//     serializable_HashEntry, 
//     serializable_HashEntry<store::Item*, 
//     StaticallyKnownCollection_t>,
//     1)
//
#define SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(template_name, instance_name, second_T, index) \
instance_name,second_T::class_factory<instance_name,second_T> g_class_factory_##template_name##_##index; \
\
template<> const ::zorba::serialization::ClassVersion *instance_name, second_T::class_versions = g_##template_name##_class_versions; \
\
template<> const int instance_name,second_T::class_versions_count = \
g_##template_name##_class_versions_count; \
\
template<> const char *instance_name,second_T::class_name_str = #instance_name "," #second_T;


#define SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS3(template_name, instance_name, second_T, third_T, index) \
  instance_name,second_T,third_T::class_factory<instance_name,second_T,third_T>   g_class_factory_##template_name##_##index;\
  template<> const ::zorba::serialization::ClassVersion *instance_name,second_T,third_T::class_versions = g_##template_name##_class_versions;\
  template<> const int instance_name,second_T,third_T::class_versions_count = g_##template_name##_class_versions_count;\
  template<> const char *instance_name,second_T,third_T::class_name_str = #instance_name "," #second_T "," #third_T;

//no need to add CLASS_VERSION and END_SERIALIZABLE_CLASS_VERSIONS


/*******************************************************************************

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
class_name(::zorba::serialization::Archiver& ar)                      \
  :                                                                   \
  base_class1(ar),                                                    \
  base_class2(ar)                                                     \
{                                                                     \
}

#define SERIALIZABLE_CLASS_CONSTRUCTOR2T(class_name, base_class, templ2) \
class_name(::zorba::serialization::Archiver& ar)                      \
  :                                                                   \
  base_class , templ2(ar)                                             \
{                                                                     \
}

#define SERIALIZABLE_CLASS_CONSTRUCTOR3T(class_name, base_class, templ2, templ3) \
class_name(::zorba::serialization::Archiver& ar)                      \
  :                                                                   \
  base_class ,                                                        \
  templ2,                                                             \
  templ3(ar)                                                          \
{                                                                     \
}



#ifndef NDEBUG
#define CHECK_CLASS_NAME(class_name)\
if(ar.is_serializing_out() && !ar.is_serialize_base_class())    \
{                                                               \
  assert(strstr(typeid(*this).name(), #class_name));            \
}
#else
#define CHECK_CLASS_NAME(class_name)
#endif


#define  SERIALIZE_FUNCTION(f)    ar & f;


} // namespace serialization
} // namespace zorba

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
