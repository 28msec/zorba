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

#include "zorbaserialization/serialization_engine.h"

#include "types/typeimpl.h"
#include "types/root_typemanager.h"

#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
//#include "store/api/tuples.h"

#include "zorbatypes/datetime.h"
#include "zorbatypes/collation_manager.h"

#include "functions/function.h"

#include "context/context.h"

#include <zorba/store_consts.h>

namespace zorba{
  namespace serialization{


class store_item_class_factory : public ::zorba::serialization::class_deserializer
{ 
public:
  store_item_class_factory()
  {
    /*register this class into plan serializer*/  
    ::zorba::serialization::ClassSerializer::getInstance()->register_class_factory("store::Item*", this);
  }
  virtual ::zorba::serialization::SerializeBaseClass *create_new(::zorba::serialization::Archiver &ar)
  {
    return NULL;
  }
  virtual void cast_ptr(::zorba::serialization::SerializeBaseClass* ptr, void **class_ptr)
  {
    *class_ptr = (void*)dynamic_cast<store::Item*>(ptr);
  }

};
store_item_class_factory    g_store_item_class_factory;

class xqpcollator_class_factory : public ::zorba::serialization::class_deserializer
{ 
public:
  xqpcollator_class_factory()
  {
    /*register this class into plan serializer*/  
    ::zorba::serialization::ClassSerializer::getInstance()->register_class_factory("XQPCollator*", this);
  }
  virtual ::zorba::serialization::SerializeBaseClass *create_new(::zorba::serialization::Archiver &ar)
  {
    return NULL;
  }
  virtual void cast_ptr(::zorba::serialization::SerializeBaseClass* ptr, void **class_ptr)
  {
    *class_ptr = (void*)dynamic_cast<XQPCollator*>(ptr);
  }

};
xqpcollator_class_factory    g_xqpcollator_class_factory;



/*
void operator&(Archiver &ar, XQType *&obj)
#define T XQType
{
  if(ar.is_serializing_out())
  {
    if(obj == NULL)
    {
      ar.add_compound_field("NULL", 
                            1 ,//class_version
                            FIELD_IS_CLASS, "NULL", 
                            NULL,//(SerializeBaseClass*)obj, 
                            ARCHIVE_FIELD_IS_NULL);
      return;
    }
    //char  strtemp[20];
    //sprintf(strtemp, "%d", 0);
    bool is_ref;
    
    is_ref = ar.add_compound_field(ar.is_serialize_base_class() ? obj->T::get_class_name_str() : obj->get_class_name_str(), 
                                    ar.is_serialize_base_class() ? T::class_versions[T::class_versions_count-1].class_version : obj->get_classversion(obj->get_version_count()-1).class_version , 
                                    FIELD_IS_CLASS, "0",//strtemp, 
                                    (SerializeBaseClass*)obj, 
                                    ar.is_serialize_base_class() ? ARCHIVE_FIELD_IS_BASECLASS : ARCHIVE_FIELD_IS_PTR);
    if(!is_ref)
    {
      if(!ar.is_serialize_base_class())
      {
        obj->serialize_internal(ar);
      }
      else
      {
        obj->T::serialize_internal(ar);
      }
      ar.add_end_compound_field();
    }
  }
  else
  {
    int prev_class_version = ar.get_class_version();
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
    ar.check_class_field(retval, "", "", is_simple, is_class, field_treat, (ArchiveFieldTreat)-1, id);
    if(field_treat == ARCHIVE_FIELD_IS_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    ar.set_class_version(version);



    if(ar.is_serialize_base_class())
    {
      if(strcmp(type, T::get_class_name_str_static()))
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
      if(field_treat != ARCHIVE_FIELD_IS_BASECLASS)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }
    else
    {
      if((field_treat != ARCHIVE_FIELD_IS_PTR) && (field_treat != ARCHIVE_FIELD_IS_REFERENCING))
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }

    SerializeBaseClass  *new_obj = NULL;
    if(field_treat == ARCHIVE_FIELD_IS_PTR)
    {
      class_deserializer  *cls_factory;
      cls_factory = g_class_serializer->get_class_factory(type);
      if(cls_factory == NULL)
      {
         ZORBA_SER_ERROR_DESC_OSS(SRL0003_UNRECOGNIZED_CLASS_FIELD, type);
      }
      new_obj = cls_factory->create_new(ar);
      obj = dynamic_cast<T*>(new_obj);
      if(!obj)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }

      //check the version
      int v;
      if(version > obj->get_classversion(obj->get_version_count()-1).class_version)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0005_CLASS_VERSION_IS_TOO_NEW, "Class version for " << obj->get_class_name_str() << " is " << version  << "while the version supported is " << obj->get_classversion(obj->get_version_count()-1).class_version);
      }
      for(v = obj->get_version_count()-1; v >= 0; v--)
      {
        const ClassVersion  &ver = obj->get_classversion(v);
        if(version == ver.class_version)
          break;//supported version
        else if((version < ver.class_version) && !ver.is_backward_compatible)
        {
          int oldv;
          for(oldv = v; oldv >= 0; oldv--)
          {
            if(version == obj->get_classversion(oldv).class_version)
              break;
          }
          if(oldv < 0)
            oldv = 0;
          
          ZORBA_SER_ERROR_DESC_OSS(SRL0006_CLASS_VERSION_IS_TOO_OLD, 
                          "Class version for " << obj->get_class_name_str() << " is " << version 
                          << " while the minimal supported version is " << ver.class_version 
                          << ". Use Zorba 0x" << std::hex << obj->get_classversion(oldv).zorba_version << "instead.");
        }
                
      }


      new_obj->serialize_internal(ar);
      ar.read_end_current_level();

      //check if XQType is hardcoded in TypeManager
      if(obj->get_isBuiltin())
      {
        RootTypeManager *root_type_mng = &GENV_TYPESYSTEM;
        switch(obj->type_kind())
        {
        case XQType::ATOMIC_TYPE_KIND:  // Atomic builtin type
          {
            AtomicXQType  *atomic;
            atomic = dynamic_cast<AtomicXQType*>(obj);
            assert(atomic);
            obj = (XQType*)root_type_mng->create_atomic_type(atomic->get_type_code(), atomic->get_quantifier()).getp();
            delete atomic;
          }break;
        case XQType::NODE_TYPE_KIND:
          {
            NodeXQType  *node;
            node = dynamic_cast<NodeXQType*>(obj);
            assert(node);


#define LINK_NODE_ITEM_XQTYPE(basename, suffix)                              \
  switch(obj->get_quantifier())                                         \
  {                                                                     \
  case TypeConstants::QUANT_ONE:                                        \
    delete obj;                                                         \
    obj = (XQType*)root_type_mng->basename##suffix##TYPE_ONE.getp();           \
    break;                                                              \
  case TypeConstants::QUANT_QUESTION:                                   \
    delete obj;                                                         \
    obj = (XQType*)root_type_mng->basename##suffix##TYPE_QUESTION.getp();      \
    break;                                                              \
  case TypeConstants::QUANT_STAR:                                       \
    delete obj;                                                         \
    obj = (XQType*)root_type_mng->basename##suffix##TYPE_STAR.getp();          \
    break;                                                              \
  case TypeConstants::QUANT_PLUS:                                       \
    delete obj;                                                         \
    obj = (XQType*)root_type_mng->basename##suffix##TYPE_PLUS.getp();          \
    break;                                                              \
  default:                                                              \
    break;                                                              \
  }

#define LINK_NODE(basename)                                                             \
  {                                                                                     \
    xqtref_t  content_type = node->get_content_type();                                  \
    switch(content_type->type_kind())                                                   \
    {                                                                                   \
    case XQType::ANY_TYPE_KIND : LINK_NODE_ITEM_XQTYPE(basename,_);break;               \
    case XQType::UNTYPED_KIND : LINK_NODE_ITEM_XQTYPE(basename,_UNTYPED_CONT_);break;   \
    }                                                                                   \
  }

            switch(node->get_nodetest()->get_node_kind())
            {
              case zorba::store::StoreConsts::anyNode:
                LINK_NODE(ANY_NODE)
                break;
              case zorba::store::StoreConsts::elementNode:
                LINK_NODE(ELEMENT)
                break;
              case zorba::store::StoreConsts::attributeNode:
                LINK_NODE(ATTRIBUTE)
                break;
              case zorba::store::StoreConsts::piNode:
                LINK_NODE(PI)
                break;
              case zorba::store::StoreConsts::textNode:
                LINK_NODE(TEXT)
                break;
              case zorba::store::StoreConsts::commentNode:
                LINK_NODE(COMMENT)
                break;
              case zorba::store::StoreConsts::documentNode:
                LINK_NODE(DOCUMENT)
                break;
            }
          }break;
        case XQType::ANY_TYPE_KIND:
          delete obj;
          obj = (XQType*)root_type_mng->ANY_TYPE.getp();
          break;
        case XQType::ITEM_KIND:
          LINK_NODE_ITEM_XQTYPE(ITEM, _)
          break;
        case XQType::ANY_SIMPLE_TYPE_KIND:
          delete obj;
          obj = (XQType*)root_type_mng->ANY_SIMPLE_TYPE.getp();
          break;
        case XQType::UNTYPED_KIND:
          delete obj;
          obj = (XQType*)root_type_mng->UNTYPED_TYPE.getp();
          break;
        case XQType::EMPTY_KIND:
          delete obj;
          obj = (XQType*)root_type_mng->EMPTY_TYPE.getp();
          break;
        case XQType::NONE_KIND:
          delete obj;
          obj = (XQType*)root_type_mng->NONE_TYPE.getp();
          break;
        default:
          //unknown, unreachable
          break;//just leave it as is
        }
#undef LINK_NODE_XQTYPE
      }
      new_obj = dynamic_cast<SerializeBaseClass*>(obj);
      ar.register_reference(id, field_treat, new_obj);
    }
    else if(field_treat == ARCHIVE_FIELD_IS_BASECLASS)
    {
      //check the version
      int v;
      if(version > obj->T::get_classversion(obj->T::get_version_count()-1).class_version)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0005_CLASS_VERSION_IS_TOO_NEW, "Class version for " << obj->T::get_class_name_str() << " is " << version  << "while the version supported is " << obj->T::get_classversion(obj->T::get_version_count()-1).class_version);
      }
      for(v = obj->T::get_version_count()-1; v >= 0; v--)
      {
        if(version == obj->T::get_classversion(v).class_version)
          break;//supported version
        else if((version < obj->T::get_classversion(v).class_version) && !obj->T::get_classversion(v).is_backward_compatible)
        {
          int oldv;
          for(oldv = v; oldv >= 0; oldv--)
          {
            if(version == obj->T::get_classversion(oldv).class_version)
              break;
          }
          if(oldv < 0)
            oldv = 0;
          
          ZORBA_SER_ERROR_DESC_OSS(SRL0006_CLASS_VERSION_IS_TOO_OLD, 
                          "Class version for " << obj->T::get_class_name_str() << " is " << version 
                          << " while the minimal supported version is " << obj->T::get_classversion(v).class_version 
                          << ". Use Zorba 0x" << std::hex << obj->T::get_classversion(oldv).zorba_version << "instead.");
        }
                
      }

      obj->T::serialize_internal(ar);
      ar.read_end_current_level();
    }
    else if((new_obj = (SerializeBaseClass*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
    {
      obj = dynamic_cast<T*>(new_obj);
      if(!obj)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }
    else
      ar.register_delay_reference((void**)&obj, FIELD_IS_CLASS, obj->T::get_class_name_str(), referencing);
    ar.set_class_version(prev_class_version);
  }
}
#undef T
*/
void operator&(Archiver &ar, const XQType *&obj)
{
  XQType *obj2 = (XQType*)obj;
  ar.dont_allow_delay();
  operator&(ar, obj2);
  if(!ar.is_serializing_out())
    obj = (const XQType*)obj2;
}

void operator&(Archiver &ar, XQPCollator *&obj)
{
  if(ar.is_serializing_out())
  {
    if(obj == NULL)
    {
      ar.add_simple_field("XQPCollator*", 
                            "NULL", 
                            NULL,//(SerializeBaseClass*)obj, 
                            ARCHIVE_FIELD_IS_NULL);
      return;
    }

    ar.add_simple_field("XQPCollator*", obj->getURI().c_str(), obj, ARCHIVE_FIELD_IS_PTR);
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
    ar.check_simple_field(retval, type, "XQPCollator*", is_simple, field_treat, ARCHIVE_FIELD_IS_PTR, id);
    if(field_treat == ARCHIVE_FIELD_IS_NULL)
    {
      obj = NULL;
      return;
    }

    if(!value.empty())
      obj = CollationFactory::createCollator(value);
    else
      obj = CollationFactory::createCollator();


    ar.register_reference(id, field_treat, &obj);
  }
}

#ifndef ZORBA_NO_BIGNUMBERS
void operator&(Archiver &ar, MAPM &obj)
{
  if(ar.is_serializing_out())
  {
    int nr_digits = obj.significant_digits();
    char *lBuffer = (char*)malloc(nr_digits + 20);
    obj.toString(lBuffer, nr_digits);//ZORBA_FLOAT_POINT_PRECISION);
    if(strchr(lBuffer, '.'))
    {//save only necessary decimals
      char *e_ptr = strrchr(lBuffer, 'E');
      char *tail = e_ptr ? e_ptr-1 : lBuffer+strlen(lBuffer)-1;
      while(*tail == '0')
        tail--;
      if(*tail == '.')
        tail++;
      if(e_ptr)
      {
        int i;
        for(i=0;e_ptr[i];i++)
          tail[i+1] = e_ptr[i];
        tail[i+1] = 0;
      }
      else
        tail[1] = 0;
    }

    ar.add_simple_field("MAPM", lBuffer, &obj, ARCHIVE_FIELD_NORMAL);
    free(lBuffer);
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
    ar.check_simple_field(retval, type, "MAPM", is_simple, field_treat, ARCHIVE_FIELD_NORMAL, id);

    obj = value.c_str();

    ar.register_reference(id, field_treat, &obj);
  }
}
#endif


void iterator_to_vector(store::Iterator_t iter, std::vector<store::Item_t> &items)
{
  store::Item_t  i;
  iter->open();
  while(iter->next(i))
  {
    items.push_back(i);
  }
  iter->close();
}

void serialize_node_tree(Archiver &ar, store::Item *&obj, bool all_tree);

void serialize_my_children(Archiver &ar, store::Iterator_t iter)
{
  if(ar.is_serializing_out())
  {
    std::vector<store::Item_t>  childs;
    iterator_to_vector(iter, childs);
    std::vector<store::Item_t>::iterator  child_it;
    int child_count = childs.size();
    ar & child_count;
//    ar.set_is_temp_field(false);
    for(child_it = childs.begin(); child_it != childs.end(); child_it++)
    {
      store::Item*  p = (*child_it).getp();
    //  ar.set_is_temp_field_one_level(true);
      ar.dont_allow_delay(SERIALIZE_NOW);
      //ar & p;
      serialize_node_tree(ar, p, false);
    }
  }
  else
  {
    int child_count;
    ar & child_count;
//    ar.set_is_temp_field(false);
    for(int i=0;i<child_count;i++)
    {
      store::Item*  p = NULL; 
      //ar & p;//should be automatically added to DocumentNode or ElementNode
      serialize_node_tree(ar, p, false);
    }
  }
//  ar.set_is_temp_field(true);
}

void serialize_my_children2(Archiver &ar, store::Iterator_t iter)
{
  serialize_my_children(ar, iter);
}

#define SERIALIZE_FIELD(type, var, get_func)\
      type var;                             \
      if(ar.is_serializing_out())           \
        var = obj->get_func;                \
      ar.dont_allow_delay();                \
      ar & var;

#define SERIALIZE_REF_FIELD(type, var, get_func)  \
      type var##_in;                              \
      if(ar.is_serializing_out())                 \
      {                                           \
        const type &var = obj->get_func;          \
        var##_in = var;                           \
      }                                           \
      ar.dont_allow_delay();                      \
      ar & var##_in;                              \

#define  SERIALIZE_PARENT                         \
      store::Item* parent = NULL;                 \
      if(ar.is_serializing_out())                 \
        parent = obj->getParent();                \
      ar.dont_allow_delay();                      \
      serialize_node_tree(ar, parent, false);

#define FINALIZE_SERIALIZE(create_func, func_params)    \
      if(!ar.is_serializing_out())                      \
      {                                                 \
        store::Item_t result;                           \
        GENV_ITEMFACTORY->create_func func_params;      \
        obj = result.getp();                            \
        if(obj)                                         \
          obj->addReference(obj->getSharedRefCounter() SYNC_PARAM2(obj->getRCLock()));     \
        ar.set_is_temp_field(false);                    \
        ar.register_reference(id, ARCHIVE_FIELD_IS_PTR, obj);                \
        ar.set_is_temp_field(true);                    \
      }                                                 

#define COMPARE_NAME_OF_TYPE_STRING(str)\
      name_of_type->byteEqual(str, sizeof(str)-1)


void operator&(Archiver &ar, store::Item* &obj)
{
  bool is_ref = false;
  int  is_node = 0;
  int  is_atomic = 0;
  int  is_pul = 0;
  int  is_tuple = 0;
  int  is_error = 0;
  
  int   id;
  enum  ArchiveFieldTreat field_treat;
  int   referencing;

  if(ar.is_serializing_out())
  {
    if(obj == NULL)
    {
      ar.add_compound_field("store::Item*", 
                            1 ,//class_version
                            FIELD_IS_CLASS, "NULL", 
                            NULL,//(SerializeBaseClass*)obj, 
                            ARCHIVE_FIELD_IS_NULL);
      return;
    }
    char  strtemp[100];
    is_node = obj->isNode();
    is_atomic = obj->isAtomic();
    is_pul = obj->isPul();
    is_tuple = obj->isTuple();
    is_error = obj->isError();
    assert(is_node || is_atomic || is_pul || is_tuple || is_error);
    sprintf(strtemp, "n%da%dp%dt%de%d",
                    is_node, is_atomic, is_pul, is_tuple, is_error);
    if(is_node)
      ar.set_is_temp_field(true);
    is_ref = ar.add_compound_field("store::Item*", 0, FIELD_IS_CLASS, strtemp, obj, ARCHIVE_FIELD_IS_PTR);
    if(is_node)
      ar.set_is_temp_field(false);

  }
  else
  {
    char  *type;
    std::string value;
    int   version;
    bool  is_simple;
    bool  is_class;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_class_field(retval, type, "store::Item*", is_simple, is_class, field_treat, (enum  ArchiveFieldTreat)-1, id);
    if(field_treat == ARCHIVE_FIELD_IS_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    //ar.register_reference(id, &obj);
    if((field_treat != ARCHIVE_FIELD_IS_PTR) && (field_treat != ARCHIVE_FIELD_IS_REFERENCING))
    {
      ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
    }
    is_ref = (field_treat == ARCHIVE_FIELD_IS_REFERENCING);
    if(!is_ref)
    {
      sscanf(value.c_str(), "n%da%dp%dt%de%d",
                    &is_node, &is_atomic, &is_pul, &is_tuple, &is_error);
    }
  }



  if(!is_ref)
  {
    ar.set_is_temp_field(true);
    ar.set_is_temp_field_one_level(true);
    if(is_atomic)
    {
      store::Item_t type;
      xqpStringStore *name_of_type = NULL;
      bool is_qname;
      if(ar.is_serializing_out())
      {
        type = obj->getType();
        name_of_type = type->getLocalName();
        xqpStringStore *ns =type->getNamespace();
        is_qname = (name_of_type->byteEqual("QName", sizeof("QName")-1) && 
                    ns->byteEqual("http://www.w3.org/2001/XMLSchema", sizeof("http://www.w3.org/2001/XMLSchema")-1));
      }
      ar & is_qname;
      if(!is_qname)
      {
        ar.dont_allow_delay();
        ar & type;//save qname of type
        ///check for User Typed Atomic Item
        store::Item*    baseItem;
        if(ar.is_serializing_out())         
          baseItem = (store::Item*)obj->getBaseItem();            
        ar.set_is_temp_field(false);
        ar.dont_allow_delay();
        ar & baseItem;
        ar.set_is_temp_field(true);
        if(baseItem)
        {
          store::Item_t baseItem_rc(baseItem);
          FINALIZE_SERIALIZE(createUserTypedAtomicItem, (result, baseItem_rc, type));
          goto EndAtomicItem;
        }
      }
      else if(!ar.is_serializing_out())
        GENV_ITEMFACTORY->createQName(type, "http://www.w3.org/2001/XMLSchema", "xs", "QName");
      

      if(!ar.is_serializing_out())
        name_of_type = type->getLocalName();


      if(COMPARE_NAME_OF_TYPE_STRING("untyped"))
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, *name_of_type);
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("untypedAtomic"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createUntypedAtomic, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("anyType"))
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, *name_of_type);
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("anySimpleType"))
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, *name_of_type);
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("anyAtomicType"))
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, *name_of_type);
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("string"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createString, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("normalizedString"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createNormalizedString, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("language"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createLanguage, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("token"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createToken, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("NMTOKEN"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createNMTOKEN, (result, value));
      } 
      else if(COMPARE_NAME_OF_TYPE_STRING("anyURI"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createAnyURI, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("Name"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createName, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("NCName"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createNCName, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("QName"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, ns, getNamespace());
        SERIALIZE_FIELD(xqpStringStore_t, prefix, getPrefix());
        SERIALIZE_FIELD(xqpStringStore_t, local, getLocalName());
        FINALIZE_SERIALIZE(createQName, (result, ns, prefix, local));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("notation"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createNOTATION, (result, value));
      }
         
      else if(COMPARE_NAME_OF_TYPE_STRING("ID"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createID, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("IDREF"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createIDREF, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("ENTITY"))
      {
        SERIALIZE_FIELD(xqpStringStore_t, value, getStringValue());
        FINALIZE_SERIALIZE(createENTITY, (result, value));
      }
         
      else if(COMPARE_NAME_OF_TYPE_STRING("dateTime"))
      {
        SERIALIZE_REF_FIELD(xqp_dateTime, value, getDateTimeValue());
        FINALIZE_SERIALIZE(createDateTime, (result, &value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("date"))
      {
        SERIALIZE_REF_FIELD(xqp_date, value, getDateValue());
        FINALIZE_SERIALIZE(createDate, (result, &value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("time"))
      {
        SERIALIZE_REF_FIELD(xqp_time, value, getTimeValue());
        FINALIZE_SERIALIZE(createTime, (result, &value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("duration"))
      {
        SERIALIZE_REF_FIELD(xqp_duration, value, getDurationValue());
        FINALIZE_SERIALIZE(createDuration, (result, &value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("dayTimeDuration"))
      {
        SERIALIZE_REF_FIELD(xqp_dayTimeDuration, value, getDayTimeDurationValue());
        FINALIZE_SERIALIZE(createDayTimeDuration, (result, &value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("yearMonthDuration"))
      {
        SERIALIZE_REF_FIELD(xqp_yearMonthDuration, value, getYearMonthDurationValue());
        FINALIZE_SERIALIZE(createYearMonthDuration, (result, &value_in));
      }
         
      else if(COMPARE_NAME_OF_TYPE_STRING("float"))
      {
        SERIALIZE_FIELD(xqp_float, value, getFloatValue());
        FINALIZE_SERIALIZE(createFloat, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("double"))
      {
        SERIALIZE_FIELD(xqp_double, value, getDoubleValue());
        FINALIZE_SERIALIZE(createDouble, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("decimal"))
      {
        SERIALIZE_FIELD(xqp_decimal, value, getDecimalValue());
        FINALIZE_SERIALIZE(createDecimal, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("integer"))
      {
        SERIALIZE_FIELD(xqp_integer, value, getIntegerValue());
        FINALIZE_SERIALIZE(createInteger, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("nonPositiveInteger"))
      {
        SERIALIZE_FIELD(xqp_integer, value, getIntegerValue());
        FINALIZE_SERIALIZE(createNonPositiveInteger, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("nonNegativeInteger"))
      {
        SERIALIZE_FIELD(xqp_uinteger, value, getUnsignedIntegerValue());
        FINALIZE_SERIALIZE(createNonNegativeInteger, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("negativeInteger"))
      {
        SERIALIZE_FIELD(xqp_integer, value, getIntegerValue());
        FINALIZE_SERIALIZE(createNegativeInteger, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("positiveInteger"))
      {
        SERIALIZE_FIELD(xqp_uinteger, value, getUnsignedIntegerValue());
        FINALIZE_SERIALIZE(createPositiveInteger, (result, value));
      }
         
      else if(COMPARE_NAME_OF_TYPE_STRING("long"))
      {
        SERIALIZE_FIELD(xqp_long, value, getLongValue());
        FINALIZE_SERIALIZE(createLong, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("int"))
      {
        SERIALIZE_FIELD(xqp_int, value, getIntValue());
        FINALIZE_SERIALIZE(createInt, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("short"))
      {
        SERIALIZE_FIELD(xqp_short, value, getShortValue());
        FINALIZE_SERIALIZE(createShort, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("byte"))
      {
        SERIALIZE_FIELD(xqp_byte, value, getByteValue());
        FINALIZE_SERIALIZE(createByte, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("unsignedLong"))
      {
        SERIALIZE_FIELD(xqp_ulong, value, getUnsignedLongValue());
        FINALIZE_SERIALIZE(createUnsignedLong, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("unsignedInt"))
      {
        SERIALIZE_FIELD(xqp_uint, value, getUnsignedIntValue());
        FINALIZE_SERIALIZE(createUnsignedInt, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("unsignedShort"))
      {
        SERIALIZE_FIELD(xqp_ushort, value, getUnsignedShortValue());
        FINALIZE_SERIALIZE(createUnsignedShort, (result, value));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("unsignedByte"))
      {
        SERIALIZE_FIELD(xqp_ubyte, value, getUnsignedByteValue());
        FINALIZE_SERIALIZE(createUnsignedByte, (result, value));
      }
         
      else if(COMPARE_NAME_OF_TYPE_STRING("gYearMonth"))
      {
        SERIALIZE_REF_FIELD(xqp_gYearMonth, value, getGYearMonthValue());
        FINALIZE_SERIALIZE(createGYearMonth, (result, &value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("gYear"))
      {
        SERIALIZE_REF_FIELD(xqp_gYear, value, getGYearValue());
        FINALIZE_SERIALIZE(createGYear, (result, &value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("gMonthDay"))
      {
        SERIALIZE_REF_FIELD(xqp_gMonthDay, value, getGMonthDayValue());
        FINALIZE_SERIALIZE(createGMonthDay, (result, &value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("gDay"))
      {
        SERIALIZE_REF_FIELD(xqp_gDay, value, getGDayValue());
        FINALIZE_SERIALIZE(createGDay, (result, &value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("gMonth"))
      {
        SERIALIZE_REF_FIELD(xqp_gMonth, value, getGMonthValue());
        FINALIZE_SERIALIZE(createGMonth, (result, &value_in));
      }
         
      else if(COMPARE_NAME_OF_TYPE_STRING("base64Binary"))
      {
        SERIALIZE_REF_FIELD(xqp_base64Binary, value, getBase64BinaryValue());
        FINALIZE_SERIALIZE(createBase64Binary, (result, value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("hexBinary"))
      {
        SERIALIZE_REF_FIELD(xqp_hexBinary, value, getHexBinaryValue());
        FINALIZE_SERIALIZE(createHexBinary, (result, value_in));
      }
      else if(COMPARE_NAME_OF_TYPE_STRING("boolean"))
      {
        SERIALIZE_FIELD(bool, value, getBooleanValue());
        FINALIZE_SERIALIZE(createBoolean, (result, value));
      }
      else
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, *name_of_type);
      }
EndAtomicItem:;
    }
    else if(is_node)
    {
      serialize_node_tree(ar, obj, true);
    }
    else if(is_pul)
    {
      ZORBA_SER_ERROR_DESC_OSS(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, "Pul");
    }
    else if(is_error)
    {
      SERIALIZE_FIELD(error::ZorbaError*, value, getError());
      FINALIZE_SERIALIZE(createError, (result, value));
    }
#if 0
    else if(is_tuple)
    {
      SERIALIZE_REF_FIELD(std::vector<zorba::store::TupleField>, tuple_fields, getTupleFields());
      FINALIZE_SERIALIZE(createTuple, (result, tuple_fields_in));
    }
#endif
    else
    {
      ZORBA_SER_ERROR_DESC_OSS(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, "Not atomic, node, tuple, pul or error");
    }

    ar.set_is_temp_field(false);
    ar.set_is_temp_field_one_level(false);
  }

  if(ar.is_serializing_out())
  {
    if(!is_ref)
      ar.add_end_compound_field();
  }
  else
  {
    if(!is_ref)
    {
      if(!is_node)
        ar.register_item(obj);
      ar.read_end_current_level();
    }
    else
    {
      SerializeBaseClass  *new_obj = NULL;
      if((new_obj = (SerializeBaseClass*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
      {
        obj = dynamic_cast<store::Item*>(new_obj);
        if(!obj)
        {
          ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
        }
      }
      else if(!ar.get_is_temp_field() && !ar.get_is_temp_field_one_level())
        ar.register_delay_reference((void**)&obj, FIELD_IS_CLASS, "store::Item*", referencing);
      else
        obj = NULL;
    }
  }

}

void serialize_node_tree(Archiver &ar, store::Item *&obj, bool all_tree)
{
  //only for node items
  //serialize first whole tree and then the item (will surely be a reference)
  if(all_tree)
  {
    store::Item *parent = NULL;
    if(ar.is_serializing_out())
    {
      parent = obj->getParent();
      if(parent)
      {
        while(parent->getParent())
          parent = parent->getParent();
      }
      if(!parent)
      {
        parent = obj;
      }
    }
    serialize_node_tree(ar, parent, false);
  }
  ar.set_is_temp_field(false);
  int   id;
  enum  ArchiveFieldTreat field_treat;
  int   referencing;
  bool is_ref;
  if(ar.is_serializing_out())
  {
    is_ref = ar.add_compound_field("store::Item*", 0, FIELD_IS_CLASS, "", obj, ARCHIVE_FIELD_IS_PTR);
  }
  else
  {
    char  *type;
    std::string value;
    int   version;
    bool  is_simple;
    bool  is_class;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &version, &is_simple, &is_class, &field_treat, &referencing);
    if(!retval && ar.get_read_optional_field())
      return;
    ar.check_class_field(retval, type, "store::Item*", is_simple, is_class, field_treat, (enum  ArchiveFieldTreat)-1, id);
    if(field_treat == ARCHIVE_FIELD_IS_NULL)
    {
      obj = NULL;//unreachable
      ar.read_end_current_level();
      ar.set_is_temp_field(true);
      return;
    }
    //ar.register_reference(id, &obj);
    if((field_treat != ARCHIVE_FIELD_IS_PTR) && (field_treat != ARCHIVE_FIELD_IS_REFERENCING))
    {
      ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
    }
    is_ref = (field_treat == ARCHIVE_FIELD_IS_REFERENCING);
  }
  ar.set_is_temp_field(true);

  if(!is_ref)
  {
    store::StoreConsts::NodeKind   nodekind = store::StoreConsts::anyNode;
    if(ar.is_serializing_out())
      nodekind = obj->getNodeKind();
    SERIALIZE_ENUM(store::StoreConsts::NodeKind, nodekind);
    switch(nodekind)
    {
    case store::StoreConsts::anyNode:
      ZORBA_SER_ERROR_DESC_OSS(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, "anyNode");
    case store::StoreConsts::documentNode:
    {
      SERIALIZE_FIELD(xqpStringStore_t, baseUri, getBaseURI());
      SERIALIZE_FIELD(xqpStringStore_t, docUri, getDocumentURI());
      FINALIZE_SERIALIZE(createDocumentNode, (result, baseUri, docUri));
      serialize_my_children(ar, obj->getChildren());
    }break;
    case store::StoreConsts::elementNode:
    {
      SERIALIZE_PARENT;
      //pos = -1
      SERIALIZE_FIELD(store::Item_t, nodename, getNodeName());
      SERIALIZE_FIELD(store::Item_t, name_of_type, getType());
      SERIALIZE_FIELD(bool, isInSubstGroup, isInSubstitutionGroup());
      bool  haveTypedValue = false;
      bool  haveEmptyValue = true;
      if(ar.is_serializing_out())
      {
        //workaround
      //  store::simplestore::ElementNode *elem_node = dynamic_cast<store::simplestore::ElementNode*>(obj);
      //  haveTypedValue = elem_node->haveTypedValue();
      //  haveEmptyValue = elem_node->haveEmptyValue();
        if(!name_of_type->getNamespace()->byteEqual("http://www.w3.org/2001/XMLSchema") ||
            !name_of_type->getLocalName()->byteEqual("untyped"))
          haveTypedValue = true;
      }
      ar & haveTypedValue;
      ar & haveEmptyValue;
      store::NsBindings ns_bindings;
      if(ar.is_serializing_out())
        obj->getNamespaceBindings(ns_bindings, store::StoreConsts::ONLY_LOCAL_NAMESPACES);
      ar & ns_bindings;
      SERIALIZE_FIELD(xqpStringStore_t, baseUri, getBaseURI());
      FINALIZE_SERIALIZE(createElementNode, (result, parent, -1, nodename, name_of_type, haveTypedValue, haveEmptyValue, ns_bindings, baseUri, isInSubstGroup));

      serialize_my_children2(ar, obj->getAttributes());

      serialize_my_children(ar, obj->getChildren());
    }break;
    case store::StoreConsts::attributeNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(store::Item_t, nodename, getNodeName());
      SERIALIZE_FIELD(store::Item_t, name_of_type, getType());
      store::Item_t val;
      store::Iterator_t val_it;
      if(ar.is_serializing_out())
        obj->getTypedValue(val, val_it);
      ar & val;
      std::vector<store::Item_t> val_vector;
      if(val == NULL)
      {
        iterator_to_vector(val_it, val_vector);
      }
      ar & val_vector;
      if(val != NULL)
      {
        FINALIZE_SERIALIZE(createAttributeNode, (result, parent, -1, nodename, name_of_type, val));
      }
      else
      {
        FINALIZE_SERIALIZE(createAttributeNode, (result, parent, -1, nodename, name_of_type, val_vector));
      }
    }break;
    case store::StoreConsts::textNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(xqpStringStore_t, content, getStringValue());
      FINALIZE_SERIALIZE(createTextNode, (result, parent, -1, content));
    }break;
    case store::StoreConsts::piNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(xqpStringStore_t, target, getTarget());
      SERIALIZE_FIELD(xqpStringStore_t, content, getStringValue());
      SERIALIZE_FIELD(xqpStringStore_t, baseUri, getBaseURI());
      FINALIZE_SERIALIZE(createPiNode, (result, parent, -1, target, content, baseUri));
    }break;
    case store::StoreConsts::commentNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(xqpStringStore_t, content, getStringValue());
      FINALIZE_SERIALIZE(createCommentNode, (result, parent, -1, content));
    }break;
    default:
      ZORBA_SER_ERROR_DESC_OSS(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, "unknown");
    }
  }//end is_ref

  if(ar.is_serializing_out())
  {
    if(!is_ref)
      ar.add_end_compound_field();
  }
  else
  {
    if(!is_ref)
    {
      ar.register_item(obj);
      ar.read_end_current_level();
    }
    else
    {
      SerializeBaseClass  *new_obj = NULL;
      if((new_obj = (SerializeBaseClass*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
      {
        obj = dynamic_cast<store::Item*>(new_obj);
        if(!obj)
        {
          ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
        }
      }
      else if(!ar.get_is_temp_field() && !ar.get_is_temp_field_one_level())
        ar.register_delay_reference((void**)&obj, FIELD_IS_CLASS, "store::Item*", referencing);
      else
        obj = NULL;
    }
  }

}

void operator&(Archiver &ar, std::map<int, rchandle<function> > *&obj)
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
    is_ref = ar.add_compound_field("context::ArityFMap*", 0, !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_IS_PTR);
    if(!is_ref)
    {
      ar.set_is_temp_field_one_level(true);
      int s = (int)obj->size();
      ar & s;
      context::ArityFMap::iterator  it;
      function *f;
      int i1;
      for(it=obj->begin(); it != obj->end(); it++)
      {
        i1 = (*it).first;
        ar & i1;
        f = (*it).second.getp();
        ar.dont_allow_delay();
        SERIALIZE_FUNCTION(f);
      }
      ar.set_is_temp_field_one_level(false);
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
    ar.check_nonclass_field(retval, type, "context::ArityFMap*", is_simple, is_class, field_treat, ARCHIVE_FIELD_IS_PTR, id);
    if(field_treat == ARCHIVE_FIELD_IS_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    void *new_obj;
    if(field_treat == ARCHIVE_FIELD_IS_PTR)
    {
      obj = new context::ArityFMap;
      ar.register_reference(id, field_treat, obj);

      ar.set_is_temp_field_one_level(true);
      int s;
      ar & s;
      context::ArityFMap::iterator  it;
      //std::pair<int, rchandle<function>>   p;
      int a1;
      function *a2;
      for(int i=0;i<s;i++)
      {
        ar & a1;
        SERIALIZE_FUNCTION(a2);
        obj->insert(std::pair<int, rchandle<function> >(a1, a2));
      }
      ar.set_is_temp_field_one_level(false);
      ar.read_end_current_level();
    }
    else if((new_obj = ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
    {
      obj = (context::ArityFMap*)new_obj;
      if(!obj)
      {
        ZORBA_SER_ERROR_DESC_OSS(SRL0002_INCOMPATIBLE_INPUT_FIELD, id);
      }
    }
    else
      ar.register_delay_reference((void**)&obj, !FIELD_IS_CLASS, "context::ArityFMap*", referencing);
  }
}

void operator&(Archiver &ar, zorba::store::TempSeq *obj)
{
  ZORBA_SER_ERROR_DESC_OSS(SRL0010_ITEM_TYPE_NOT_SERIALIZABLE, "TempSeq");
}

}}
