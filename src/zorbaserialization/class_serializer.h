
#ifndef ZORBA_BINARY_PLAN_ITERATOR_SERIALIZATION
#define ZORBA_BINARY_PLAN_ITERATOR_SERIALIZATION

#include <string>
#include <list>
#include <vector>
#include <assert.h>
#include <iostream>


namespace zorba{

  namespace serialization{

#define   BACKWARD_COMPATIBLE     true
#define   ZORBA_VERSION_0_9_5     0x000905

class SerializeBaseClass;
class Archiver;

struct ClassVersion 
{
  unsigned long   class_version;
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
static const struct zorba::serialization::ClassVersion class_versions[]; \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, new class_name(ar))

#define SERIALIZABLE_ABSTRACT_CLASS(class_name) \
SERIALIZABLE_CLASS_PREFIX(class_name) \
static const struct zorba::serialization::ClassVersion class_versions[]; \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, NULL)

#define SERIALIZABLE_TEMPLATE_CLASS(class_name) \
SERIALIZABLE_CLASS_PREFIX(class_name) \
static const struct zorba::serialization::ClassVersion *class_versions; \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, new class_name(ar))

#define SERIALIZABLE_TEMPLATE_ABSTRACT_CLASS(class_name) \
SERIALIZABLE_CLASS_PREFIX(class_name) \
static const struct zorba::serialization::ClassVersion *class_versions; \
SERIALIZABLE_CLASS_FACTORY_DECL(class_name, NULL)



#define SERIALIZABLE_CLASS_PREFIX(class_name) \
virtual void serialize_internal(zorba::serialization::Archiver &ar)\
{\
  CHECK_CLASS_NAME(class_name) \
  /*if(ar.is_serializing_out())*/ \
    /*ar.set_class_type(typeid(this).name()+6);*/ \
  class_name::serialize(ar);\
}\
virtual const zorba::serialization::ClassVersion &get_classversion(int v) {return class_versions[v];}\
virtual int get_version_count() {return class_versions_count;}\
static const int class_versions_count;


#define SERIALIZABLE_CLASS_FACTORY_DECL(class_name, creator) \
template<class T> \
class class_factory : public zorba::serialization::class_deserializer\
{ \
public:\
  class_factory()\
  {\
    /*register this class into plan serializer*/  \
    zorba::serialization::ClassSerializer::getInstance()->register_class_factory(typeid(T).name()+6, this);\
  }\
  virtual zorba::serialization::SerializeBaseClass *create_new(zorba::serialization::Archiver &ar)\
  {\
    return creator;\
  }\
  virtual void cast_ptr(zorba::serialization::SerializeBaseClass* ptr, void **class_ptr)\
  {\
    *class_ptr = (void*)dynamic_cast<class_name*>(ptr);\
  }\
\
};\
static class_factory<class_name>   g_class_factory;

////////////////////
//////////////////////define the class versions

#define SERIALIZABLE_CLASS_VERSIONS(class_name) \
  class_name::class_factory<class_name>   class_name::g_class_factory;\
  const zorba::serialization::ClassVersion class_name::class_versions[] = {{ 1, ZORBA_VERSION_0_9_5, BACKWARD_COMPATIBLE}



#define CLASS_VERSION(class_version, zorba_version, compatibility, description) \
  ,{class_version, zorba_version, compatibility}



#define END_SERIALIZABLE_CLASS_VERSIONS(class_name) \
};\
const int class_name::class_versions_count = sizeof(class_name::class_versions)/sizeof(struct zorba::serialization::ClassVersion);


////////////////////
//////////////////////define the template class versions

#define SERIALIZABLE_TEMPLATE_VERSIONS(template_name) \
  const zorba::serialization::ClassVersion g_##template_name##_class_versions[] = {{ 1, ZORBA_VERSION_0_9_5, BACKWARD_COMPATIBLE}

//add CLASS_VERSION here

#define END_SERIALIZABLE_TEMPLATE_VERSIONS(template_name) \
  };\
  const int g_##template_name##_class_versions_count = sizeof(g_##template_name##_class_versions)/sizeof(struct zorba::serialization::ClassVersion);


///////////////////
/////////////////////define the versions dependency from template instance to template versions

#define SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(template_name, instance_name) \
  instance_name::class_factory<instance_name>   instance_name::g_class_factory;\
  const zorba::serialization::ClassVersion *instance_name::class_versions = g_##template_name##_class_versions;\
  const int instance_name::class_versions_count = g_##template_name##_class_versions_count;

//no need to add CLASS_VERSION and END_SERIALIZABLE_CLASS_VERSIONS


#define   SERIALIZABLE_CLASS_CONSTRUCTOR(class_name) \
  class_name(zorba::serialization::Archiver &ar)\
  {\
  }

#define   SERIALIZABLE_CLASS_CONSTRUCTOR2(class_name, base_class) \
  class_name(zorba::serialization::Archiver &ar) : base_class(ar)\
  {\
  }

#define   SERIALIZABLE_CLASS_CONSTRUCTOR3(class_name, base_class1, base_class2) \
  class_name(zorba::serialization::Archiver &ar) : base_class1(ar), base_class2(ar)\
  {\
  }


#define   CHECK_CLASS_NAME(class_name)\
if(ar.is_serializing_out() && !ar.is_serialize_base_class())\
{\
  const char  *this_name = typeid(*this).name()+6; \
  assert(!strcmp(this_name, #class_name) || \
        (!strncmp(this_name, #class_name, sizeof(#class_name)-1) && (this_name[sizeof(#class_name)-1] == '<')));\
}




//derive all classes that need to be serialized from this base class
//that is: iterators, store items, static context and so on
class SerializeBaseClass
{
public:
  virtual void serialize_internal(Archiver &ar) = 0;
  virtual const ClassVersion &get_classversion(int v) = 0;
  virtual int get_version_count() = 0;

};



//stateless class, multithreading safe
class ClassSerializer
{
  char  *class_name_pool;
  int   class_name_pool_size;
  int   class_name_pool_filled;
  struct registered_factory
  {
    //char  class_name[50];
    int cls_name_off;
    class_deserializer  *class_factory;
  };
  std::list<struct registered_factory>    class_factories;
public:
  ClassSerializer();
  ~ClassSerializer();

  void register_class_factory(const char *, class_deserializer *);
  class_deserializer *get_class_factory(const char *classname);


  static ClassSerializer* getInstance();
  static void deleteInstance();

};

extern ClassSerializer  *g_class_serializer;
///Public class serialization functions


  void operator&(Archiver &ar, int &obj);

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


  void serialize_charvector(Archiver &ar, char* &obj);//like char p[20]

//  template<class T>
//  void serialize_baseclass(Archiver &ar, T *obj);

}}//end namespace serialization
#endif
