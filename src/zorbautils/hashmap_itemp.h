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
#ifndef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP
#define ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP

#include "zorbautils/hashfun.h"
#include "zorbautils/hashmap.h"

#include "store/api/item.h"

namespace zorba 
{ 


/*********************as**********************************************************

  A hash-based map container mappin item pointers to values of type V. Equality
  is based on the Item::equals() method.

********************************************************************************/
template <class V>
class ItemPointerHashMap
{
public:

  class CompareFunction
  {
  protected:
    long               theTimeZone;
    const XQPCollator* theCollation;

  public:
    CompareFunction(long tmz, const XQPCollator* collation) 
      :
      theTimeZone(tmz),
      theCollation(collation)
    {
    }

    bool equal(const store::Item* t1, const store::Item* t2)
    {
      return t1->equals(t2, theTimeZone, theCollation);
    }

    uint32_t hash(const store::Item* t)
    {
      return t->hash(theTimeZone, theCollation);
    }

    long  get_timezone() {return theTimeZone;}
    const XQPCollator*    get_collation() {return theCollation;}
  };

  typedef typename HashMap<const store::Item*, V, CompareFunction>::iterator iterator;

private:
  HashMap<const store::Item*, V, CompareFunction>  theMap;

public:
  ItemPointerHashMap(
        long timezone,
        const XQPCollator* collation,
        ulong size,
        bool sync) 
    :
    theMap(CompareFunction(timezone, collation), size, sync)
  {
  }

  iterator begin() { return theMap.begin(); }

  iterator end() { return theMap.end(); }

  bool empty() const { return theMap.empty(); }

  void clear() { theMap.clear(); }

  bool get(const store::Item* key, V& value) { return theMap.get(key, value); }

  bool find(const store::Item* key) { return theMap.find(key); }

  bool insert(const store::Item* key, V& value) { return theMap.insert(key, value); }

  bool update(const store::Item* key, V& value) { return theMap.update(key, value); }

  bool remove(const store::Item* key) { return theMap.remove(key); }


  //helpers for serialization
  ulong object_count() {return theMap.object_count();}
  long  get_timezone() {return theMap.get_compare_function().get_timezone();}
  const XQPCollator*    get_collation() {return theMap.get_compare_function().get_collation();}
  ulong get_size()  {return theMap.capacity();}
  bool  get_sync()   {return theMap.has_sync();}
};


namespace serialization
{

template<class T>
void operator&(Archiver &ar, ItemPointerHashMap<T>* &obj)
{
  if(ar.is_serializing_out())
  {
    if((obj == NULL))
    {
      ar.add_compound_field("NULL", 
                            1 ,//class_version
                            !FIELD_IS_CLASS, "NULL", 
                            NULL,//(SerializeBaseClass*)obj, 
                            ARCHIVE_FIELD_IS_NULL);
      return;
    }
    bool is_ref;
    is_ref = ar.add_compound_field("ItemPointerHashMap<T>*", 0, !FIELD_IS_CLASS, "", obj, ARCHIVE_FIELD_IS_PTR);
    if(!is_ref)
    {
      typename ItemPointerHashMap<T>::iterator   obj_it;
      ar.set_is_temp_field(true);
      ulong obj_count = obj->object_count();
      ar & obj_count;
      long timezone = obj->get_timezone();
      ar & timezone;
      XQPCollator* collation = (XQPCollator*)obj->get_collation();
      ar & collation;
      ulong size = obj->get_size();
      ar & size;
      bool sync = obj->get_sync();
      ar & sync;
      ar.set_is_temp_field(false);
      for(obj_it = obj->begin(); obj_it != obj->end(); ++obj_it)
      {
        store::Item *key_item = (store::Item *)(*obj_it).first;
        ar.dont_allow_delay();
        ar.set_is_temp_field(true);
        ar & key_item;
        ar.set_is_temp_field(false);
        ar.dont_allow_delay();
        ar.set_is_temp_field_one_level(true);
        T t_value = (T)(*obj_it).second;
        ar & t_value;
        ar.set_is_temp_field_one_level(false);
      }
      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    int   version;
    bool  is_simple;
    bool  is_class;
    enum  ArchiveFieldTreat field_treat;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_nonclass_field(retval, type, "ItemPointerHashMap<T>*", is_simple, is_class, field_treat, (ArchiveFieldTreat)-1, id);
    if(field_treat == ARCHIVE_FIELD_IS_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    void *new_obj;
    if(field_treat == ARCHIVE_FIELD_IS_PTR)
    {

      ar.set_is_temp_field(true);
      ulong obj_count, i;
      ar & obj_count;
      long timezone;
      ar & timezone;
      XQPCollator* collation;
      ar & collation;
      ulong size;
      ar & size;
      bool sync;
      ar & sync;
      ar.set_is_temp_field(false);
      obj = new ItemPointerHashMap<T>(timezone, collation, size, sync);
      ar.register_reference(id, field_treat, obj);
      for(i=0;i<obj_count;i++)
      {
        store::Item *key_item;
        ar.set_is_temp_field(true);
        ar & key_item;
        ar.set_is_temp_field(false);
        T t_value;
        ar.set_is_temp_field_one_level(true);
        ar & t_value;
        ar.set_is_temp_field_one_level(false);

        obj->insert(key_item, t_value);
      }

      ar.read_end_current_level();
    }
    else if((new_obj = ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
    {
      obj = (ItemPointerHashMap<T>*)new_obj;
      if(!obj)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }
    else
      ar.register_delay_reference((void**)&obj, !FIELD_IS_CLASS, "ItemPointerHashMap<T>*", referencing);

  }
}
}//end namespace serialization

} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
