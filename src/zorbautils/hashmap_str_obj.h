#ifndef ZORBA_HASHMAP_CHAR_PTR_TO_CLASS_POINTER
#define ZORBA_HASHMAP_CHAR_PTR_TO_CLASS_POINTER

#include "zorbautils/hashmap.h"
#include "zorbautils/hashfun.h"

namespace zorba{

class CompareCharPtr
{
public:
  static uint32_t hash(const char* str)
  {
    return hashfun::h32(str, 0);
  }
  static bool equal(const char*s1, const char*s2)
  {
    return !strcmp(s1, s2);
  }
};

template<class class_name>
class HashCharPtrObjPtr : public HashMap<const char *, class_name*, CompareCharPtr>
{
public:
  HashCharPtrObjPtr() : HashMap<const char *, class_name*, CompareCharPtr>(1024, true) {}
  virtual ~HashCharPtrObjPtr() {freeAll();}
  void freeAll()
  {//free all allocated FloatImpls
    typename HashMap<const char *, class_name*, CompareCharPtr>::iterator  it;
    for(it=HashMap<const char *, class_name*, CompareCharPtr>::begin(); it != HashMap<const char *, class_name*, CompareCharPtr>::end(); ++it)
    {
      delete (*it).second;
    }
  }
};

template<class class_name>
class HashCharPtrObjPtrLimited : public HashCharPtrObjPtr<class_name>
{
  //int nr_missed;
public:
  HashCharPtrObjPtrLimited() : HashCharPtrObjPtr<class_name>() {/*nr_missed=0;*/}

  bool get(const char * item, class_name*& value)
  {
    if(HashMap<const char *, class_name*, CompareCharPtr>::get(item, value))
    {
      //nr_missed = 0;
      return true;
    }
    //nr_missed++;
    if((HashMap<const char *, class_name*, CompareCharPtr>::theNumEntries >= 20*1024))// && (nr_missed > 50))
    {
      //restart hashing
      HashCharPtrObjPtr<class_name>::freeAll();
      HashMap<const char *, class_name*, CompareCharPtr>::clear();
    }
    return false;
  }

};

}

#endif
