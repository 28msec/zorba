
#ifndef ZORBA_BINARY_PLAN_ITERATOR_SERIALIZATION
#define ZORBA_BINARY_PLAN_ITERATOR_SERIALIZATION

#include <string>
#include <list>
#include <vector>
#include <assert.h>
#include <iostream>
#include <typeinfo>
#include <string.h>

#include <zorba/error.h>
#include "zorbamisc/config/platform.h"
#include <time.h>
//#include "util/hashmap.h"

namespace zorba{
class XQPCollator;

  namespace serialization{

#define   BACKWARD_COMPATIBLE     true
#define   ZORBA_VERSION_0_9_5     0x000905

class SerializeBaseClass;
class Archiver;


struct ClassVersion 
{
  int             class_version;
  unsigned long   zorba_version;
  bool            is_backward_compatible;
};


class class_deserializer
{
public:
  virtual ~class_deserializer() 
  {
  //  std::cout << "~class_deserializer" << std::endl;
  }

  virtual SerializeBaseClass* create_new(Archiver &ar) = 0;
  virtual void cast_ptr(SerializeBaseClass* ptr, void **class_ptr) = 0;
};


#define SERIALIZABLE_CLASS(class_name) \
SERIALIZABLE_CLASS_PREFIX(class_name) \
static const struct ::zorba::serialization::ClassVersion class_versions[]; \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, new class_name(ar))\
static class_factory<class_name>   g_class_factory;

#define SERIALIZABLE_ABSTRACT_CLASS(class_name) \
SERIALIZABLE_CLASS_PREFIX(class_name) \
  static const struct ::zorba::serialization::ClassVersion class_versions[]; \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, NULL)\
static class_factory<class_name>   g_class_factory;

#define SERIALIZABLE_TEMPLATE_CLASS(class_name) \
SERIALIZABLE_CLASS_PREFIX(class_name) \
static const struct ::zorba::serialization::ClassVersion *class_versions; \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, new class_name(ar))

#define SERIALIZABLE_TEMPLATE_ABSTRACT_CLASS(class_name) \
SERIALIZABLE_CLASS_PREFIX(class_name) \
static const struct ::zorba::serialization::ClassVersion *class_versions; \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, NULL)

#define SERIALIZABLE_CLASS_NO_FACTORY(class_name) \
virtual void serialize_internal(::zorba::serialization::Archiver &ar)\
{\
  /*CHECK_CLASS_NAME(class_name)*/                \
  if(ar.is_serialize_base_class())                \
    ar.set_serialize_base_class(false);           \
  class_name::serialize(ar);                      \
}\
virtual const ::zorba::serialization::ClassVersion &get_classversion(int v) const \
{\
  /*extern const ::zorba::serialization::ClassVersion g_##class_name##_versions[]; workaround stupid gcc bug*/\
  return g_##class_name##_class_versions[v];\
}\
virtual int get_version_count() const \
{\
  /*extern const int g_##class_name##_class_versions_count; workaround stupid gcc bug*/\
  return g_##class_name##_class_versions_count;\
}\
virtual const char *get_class_name_str() {return #class_name;}\
static const char *get_class_name_str_static() {return #class_name;}




#define SERIALIZABLE_CLASS_PREFIX(class_name) \
virtual void serialize_internal(::zorba::serialization::Archiver &ar)\
{\
  CHECK_CLASS_NAME(class_name)                    \
  /*if(ar.is_serializing_out())*/                 \
    /*ar.set_class_type(typeid(this).name()+6);*/ \
  if(ar.is_serialize_base_class())                \
    ar.set_serialize_base_class(false);           \
  class_name::serialize(ar);                      \
}\
virtual const ::zorba::serialization::ClassVersion &get_classversion(int v) const {return class_versions[v];}\
virtual int get_version_count() const {return class_versions_count;}\
static const int class_versions_count;\
static const char *class_name_str;\
virtual const char *get_class_name_str() {return class_name_str;}\
static const char *get_class_name_str_static() {return class_name_str;}


#define SERIALIZABLE_CLASS_FACTORY_DECL(class_name, creator) \
template<class T> \
class class_factory : public ::zorba::serialization::class_deserializer\
{ \
public:\
  class_factory()\
  {\
    /*register this class into plan serializer*/  \
    ::zorba::serialization::ClassSerializer::getInstance()->register_class_factory(T::get_class_name_str_static(), this);\
  }\
  virtual ::zorba::serialization::SerializeBaseClass *create_new(::zorba::serialization::Archiver &ar)\
  {\
    return creator;\
  }\
  virtual void cast_ptr(::zorba::serialization::SerializeBaseClass* ptr, void **class_ptr)\
  {\
    *class_ptr = (void*)dynamic_cast<T*>(ptr);\
  }\
\
};
//static class_factory<class_name>*/   g_class_factory;

////////////////////
//////////////////////define the class versions

#define SERIALIZABLE_CLASS_VERSIONS(class_name) \
  class_name::class_factory<class_name>   class_name::g_class_factory;\
  const char *class_name::class_name_str = #class_name;\
  const ::zorba::serialization::ClassVersion class_name::class_versions[] = {{ 1, ZORBA_VERSION_0_9_5, !BACKWARD_COMPATIBLE}



#define CLASS_VERSION(class_version, zorba_version, compatibility, description) \
  ,{class_version, zorba_version, compatibility}



#define END_SERIALIZABLE_CLASS_VERSIONS(class_name) \
};\
const int class_name::class_versions_count = sizeof(class_name::class_versions)/sizeof(struct ::zorba::serialization::ClassVersion);


////////////////////
//////////////////////define the template class versions

#define SERIALIZABLE_TEMPLATE_VERSIONS(template_name) \
  extern const ::zorba::serialization::ClassVersion g_##template_name##_class_versions[] = {{ 1, ZORBA_VERSION_0_9_5, !BACKWARD_COMPATIBLE}

//add CLASS_VERSION here

#define END_SERIALIZABLE_TEMPLATE_VERSIONS(template_name) \
  };\
  extern const int g_##template_name##_class_versions_count = sizeof(g_##template_name##_class_versions)/sizeof(struct ::zorba::serialization::ClassVersion);


///////////////////
/////////////////////define the versions dependency from template instance to template versions

#define SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(template_name, instance_name, index) \
  instance_name::class_factory<instance_name>  g_class_factory_##template_name##_##index;\
  template<> const ::zorba::serialization::ClassVersion *instance_name::class_versions = g_##template_name##_class_versions;\
  template<> const int instance_name::class_versions_count = g_##template_name##_class_versions_count;\
  template<> const char *instance_name::class_name_str = #instance_name;

#define SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(template_name, instance_name, second_T, index) \
  instance_name,second_T::class_factory<instance_name,second_T>   g_class_factory_##template_name##_##index;\
  template<> const ::zorba::serialization::ClassVersion *instance_name,second_T::class_versions = g_##template_name##_class_versions;\
  template<> const int instance_name,second_T::class_versions_count = g_##template_name##_class_versions_count;\
  template<> const char *instance_name,second_T::class_name_str = #instance_name "," #second_T;

//no need to add CLASS_VERSION and END_SERIALIZABLE_CLASS_VERSIONS


#define   SERIALIZABLE_CLASS_CONSTRUCTOR(class_name) \
  class_name(::zorba::serialization::Archiver &ar) : ::zorba::serialization::SerializeBaseClass()\
  {\
  }

#define   SERIALIZABLE_CLASS_CONSTRUCTOR2(class_name, base_class) \
  class_name(::zorba::serialization::Archiver &ar) : base_class(ar)\
  {\
  }

#define   SERIALIZABLE_CLASS_CONSTRUCTOR2T(class_name, base_class, templ2) \
  class_name(::zorba::serialization::Archiver &ar) : base_class , templ2(ar)\
  {\
  }

#define   SERIALIZABLE_CLASS_CONSTRUCTOR3T(class_name, base_class, templ2, templ3) \
  class_name(::zorba::serialization::Archiver &ar) : base_class , templ2, templ3(ar)\
  {\
  }

#define   SERIALIZABLE_CLASS_CONSTRUCTOR3(class_name, base_class1, base_class2) \
  class_name(::zorba::serialization::Archiver &ar) : base_class1(ar), base_class2(ar)\
  {\
  }


#ifndef NDEBUG
#define   CHECK_CLASS_NAME(class_name)\
if(ar.is_serializing_out() && !ar.is_serialize_base_class())    \
{                                                               \
  assert(strstr(typeid(*this).name(), #class_name));            \
}
/*
  const char  *this_name = get_class_name_str_static();         \
  const char  *classname_ptr = this_name;                       \
  int   namelen = (int)strlen(this_name);                       \
  if(classname_ptr[namelen-1] == '>')                           \
  {                                                             \
    while(*classname_ptr)                                         \
    {                                                             \
      if((classname_ptr[0] == ':') && (classname_ptr[1] == ':'))  \
        this_name = classname_ptr + 2;                            \
      else if(classname_ptr[0] == '<')                            \
        break;                                                    \
      classname_ptr++;                                            \
    }                                                             \
  }                                                               \
  else                                                            \
  {                                                               \
    classname_ptr += namelen-1;                                   \
    while(namelen)                                                \
    {                                                              \
      if((classname_ptr[0] == ':') && (classname_ptr[-1] == ':'))  \
      {                                                            \
        this_name = classname_ptr + 1;                            \
        break;                                                    \
      }                                                           \
      namelen--;classname_ptr--;                                  \
    }                                                             \
  }                                                               \
  assert(!strncmp(this_name, #class_name, sizeof(#class_name)-1) &&       \
        ((this_name[sizeof(#class_name)-1] == '<') || (this_name[sizeof(#class_name)-1] == 0)));\
}
*/
#else
#define   CHECK_CLASS_NAME(class_name)
#endif



//derive all classes that need to be serialized from this base class
//that is: iterators, store items, static context and so on
class ZORBA_DLL_PUBLIC SerializeBaseClass
{
public:
  virtual ~SerializeBaseClass() {}
  virtual void serialize_internal(Archiver &ar) = 0;
  virtual const ClassVersion &get_classversion(int v) const = 0;
  virtual int get_version_count() const = 0;

};

class Archiver;
class MemArchiver;
class ClassFactoriesMap;
//stateless class, multithreading safe
class ClassSerializer
{
  friend class Archiver;
//  char  *class_name_pool;
//  int   class_name_pool_size;
//  int   class_name_pool_filled;
//  struct registered_factory
//  {
//    //char  class_name[50];
//    int cls_name_off;
//    class_deserializer  *class_factory;
//  };
//  std::list<struct registered_factory>    class_factories;
  std::vector<std::pair<const char *, class_deserializer*> >   class_names;
  int                                                         class_names_count;
  ClassFactoriesMap    *class_factories;


  //std::vector<const SerializeBaseClass*>  preregistered_hardcoded_class_obj;
  //std::vector<const void*>  preregistered_hardcoded_nonclass_obj;
  MemArchiver              *harcoded_objects_archive;
public:
  ClassSerializer();
  ~ClassSerializer();

  void register_class_factory(const char *, class_deserializer *);
  class_deserializer *get_class_factory(const char *classname);

  Archiver* getArchiverForHardcodedObjects();
  void destroyArchiverForHardcodedObjects();//called at shutdown

  static ClassSerializer* getInstance();
  //static void deleteInstance();

public:
  //debug
  clock_t   t0, t1;
  clock_t get_registration_time() { return t1-t0;}
  //end debug
};
extern ClassSerializer  *g_class_serializer;
/*
class ClassSerializerDestroyer
{
public:
  ~ClassSerializerDestroyer() {delete g_class_serializer;g_class_serializer=NULL;}

  int activate() {return 141;}
};
*/

///Public class serialization functions


  void operator&(Archiver &ar, int &obj);

  void operator&(Archiver &ar, uint32_t &obj);

  void operator&(Archiver &ar, long &obj);

  void operator&(Archiver &ar, long long &obj);

  void operator&(Archiver &ar, unsigned long long &obj);

  void operator&(Archiver &ar, short &obj);

  void operator&(Archiver &ar, unsigned short &obj);

  void operator&(Archiver &ar, char &obj);

  void operator&(Archiver &ar, unsigned char &obj);

  void operator&(Archiver &ar, float &obj);

  void operator&(Archiver &ar, double &obj);

  void operator&(Archiver &ar, bool &obj);

  void operator&(Archiver &ar, std::string &obj);
  
  void operator&(Archiver &ar, char* &obj);//like char *p=strdup("io");

//  template<class T>
//  void operator&(Archiver &ar, std::list<T> &obj);
//
//  template<class T>
//  void operator&(Archiver &ar, std::vector<T> &obj);
//
//  template<class T>
//  void operator&(Archiver &ar, T &obj);
//
//  template<class T>
//  void operator&(Archiver &ar, T *&obj);


  void serialize_array(Archiver &ar, unsigned char *obj, int len);//like char p[20]

#define  SERIALIZE_ENUM(enum_type, obj)\
        {\
          ar.set_is_temp_field(true);\
          int int_enum = (int)obj;\
          ar & int_enum;\
          if(!ar.is_serializing_out())\
            obj = (enum_type)int_enum;\
          ar.set_is_temp_field(false);\
        }
/*
#define  SERIALIZE_OPTIONAL_FIELD(obj)\
          if(ar.is_serializing_out())\
            ar & obj;\
          else\
            read_optional_field(ar, obj);
*/

#define  SERIALIZE_FUNCTION(f)                      \
  {                                                 \
    bool is_uf = false;                             \
    user_function *uf = NULL;                       \
    try{                                            \
      if(ar.is_serializing_out())                   \
      {                                             \
        uf = dynamic_cast<user_function*>(f);       \
        if(uf)                                      \
          is_uf = true;                             \
      }                                             \
    }catch(...)                                     \
    {                                               \
    }                                               \
    ar.set_is_temp_field(true);                     \
    ar & is_uf;                                     \
    ar.set_is_temp_field(false);                    \
    if(is_uf)                                       \
    {                                               \
      ar & f;                                       \
    }                                               \
    else if(!ar.is_serializing_out())               \
      f = NULL;                                     \
  }

  void report_error(   XQUERY_ERROR        aErrorCode,
                      const std::string&   aDesc, 
                      const std::string&   aFileName,
                      int                 aLineNumber);

}}//end namespace serialization
#endif
