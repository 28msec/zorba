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

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/archiver.h"
#include "zorbaserialization/mem_archiver.h"

#include "diagnostics/xquery_diagnostics.h"

#include "zorbautils/hashmap.h"

namespace zorba
{

namespace serialization
{


/*******************************************************************************

********************************************************************************/
class ClassFactoriesCompare
{
public: 
  uint32_t hash(const char * s1) const
  {
    uint32_t  h = 0;
    h = hashfun::h32(s1, FNV_32_INIT);
    return h;
  }
  bool equal(const char * s1, const char * s2) const
  {
    if((s1 == s2) || !strcmp(s1, s2))
      return true;
    else
      return false;
  }
};


/*******************************************************************************

********************************************************************************/
class ClassFactoriesMap : public zorba::HashMap<const char *, class_deserializer  *, ClassFactoriesCompare>
{
public:
  ClassFactoriesMap(ulong sz = 1024) :
      zorba::HashMap<const char *, class_deserializer  *, ClassFactoriesCompare>(sz, false) {}
};


//////////////////////////////////////////////
///////////////////////////////////////////Global serialization Operators

/*******************************************************************************

********************************************************************************/
ClassSerializer::ClassSerializer() : class_names(1000), class_names_count(0)
{
/*
  class_name_pool_size = 10000;
  class_name_pool = (char*)malloc(class_name_pool_size);
  class_name_pool_filled = 0;
*/
  class_factories = NULL;//new ClassFactoriesMap;
  t0 = clock();
//  g_class_serializer_destroyer.activate();

  harcoded_objects_archive = NULL;
  harcoded_objects_archive = new MemArchiver(true, true);//simulate serialize out
}


/*******************************************************************************

********************************************************************************/
ClassSerializer::~ClassSerializer()
{
/*
  free(class_name_pool);
*/
  delete class_factories;
  delete harcoded_objects_archive;
}


/*******************************************************************************

********************************************************************************/
ClassSerializer* ClassSerializer::getInstance()
{
  static ClassSerializer theInstance;
  return &theInstance;
}


/*******************************************************************************

********************************************************************************/
void ClassSerializer::register_class_factory(
    const char *class_name,
    class_deserializer *class_factory)
{
/*+
#ifndef NDEBUG
  //check for class name duplicates
  if(get_class_factory(class_name))
  {
    assert(false);
  }
#endif
*/
/*  int name_size = strlen(class_name);
  if((name_size + class_name_pool_filled + 1) > class_name_pool_size)
  {
    class_name_pool_size += 10000;
    class_name_pool = (char*)realloc(class_name_pool, class_name_pool_size);
  }
//  std::cout << "register class factory " << class_name << std::endl;
  class_factories->resize(class_factories->size()+1);
  ClassSerializer::registered_factory  &r = class_factories->back();
  //strcpy(r.class_name, class_name);
  strcpy(class_name_pool + class_name_pool_filled, class_name);
  r.cls_name_off = class_name_pool_filled;
  class_name_pool_filled += name_size + 1;
  r.class_factory = class_factory;
*/

  if(class_factories)
  {
    class_factories->insert(class_name, class_factory);
  }
  else
  {
    class_names[class_names_count++] = std::pair<const char *, class_deserializer*>(class_name, class_factory);
  }
//  printf("register class_factory %s\n", class_name);
  t1 = clock();
}


/*******************************************************************************

********************************************************************************/
class_deserializer *ClassSerializer::get_class_factory(const char *classname)
{
/*
  std::list<struct registered_factory>::iterator  it;
  for(it = class_factories->begin(); it != class_factories->end(); it++)
  {
    if(!strcmp(class_name_pool + (*it).cls_name_off, classname))
      return (*it).class_factory;
  }
  return NULL;
*/
  if(class_factories == NULL)
  {
    class_factories = new ClassFactoriesMap;
    int i;
    std::vector<std::pair<const char *, class_deserializer*> >::iterator cls_it = class_names.begin();
    for(i=0;i<class_names_count;i++, cls_it++)
    {
      class_factories->insert((*cls_it).first, (*cls_it).second);
    }
  }
  class_deserializer  *cls_factory = NULL;
  class_factories->get(classname, cls_factory);
  return cls_factory;
}


/*******************************************************************************

********************************************************************************/
Archiver* ClassSerializer::getArchiverForHardcodedObjects()
{
  return harcoded_objects_archive;
}


/*******************************************************************************

********************************************************************************/
void ClassSerializer::destroyArchiverForHardcodedObjects()
{
  delete harcoded_objects_archive;
  harcoded_objects_archive = NULL;
  harcoded_objects_archive = new MemArchiver(true, true);//simulate serialize out
}


} // namespace serialization
} // namespace zorba
/* vim:set et sw=2 ts=2: */
