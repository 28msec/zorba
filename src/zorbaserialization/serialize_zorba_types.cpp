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

#include <zorba/error.h>
#include <zorba/diagnostic_list.h>
#include <zorba/internal/qname.h>
#include <zorba/item.h>
#include <zorba/user_exception.h>

#include "zorbaserialization/serialize_zorba_types.h"
#include "zorbaserialization/serialize_template_types.h"

#include "types/typeimpl.h"
#include "types/root_typemanager.h"

#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/item_handle.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"

#include "zorbamisc/ns_consts.h"

#include "zorbatypes/datetime.h"
#include "zorbatypes/collation_manager.h"
#include "zorbatypes/integer.h"

#include "functions/function.h"
#include "runtime/function_item/function_item.h"

#include "context/static_context.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"
#include "util/string_util.h"

#include <zorba/store_consts.h>

namespace zorba
{
namespace serialization
{


/*******************************************************************************

********************************************************************************/
class store_item_class_factory : public ::zorba::serialization::ClassDeserializer
{ 
public:
  store_item_class_factory()
  {
    ::zorba::serialization::ClassSerializer::getInstance()->
    register_class_factory("store::Item*", this);
  }

  virtual ::zorba::serialization::SerializeBaseClass* create_new(
      ::zorba::serialization::Archiver& ar)
  {
    return NULL;
  }

  virtual void cast_ptr(::zorba::serialization::SerializeBaseClass* ptr, void** class_ptr)
  {
    *class_ptr = (void*)dynamic_cast<store::Item*>(ptr);
  }

};


store_item_class_factory g_store_item_class_factory;


/*******************************************************************************

********************************************************************************/
class xqpcollator_class_factory : public ::zorba::serialization::ClassDeserializer
{ 
public:
  xqpcollator_class_factory()
  {
    ::zorba::serialization::ClassSerializer::getInstance()->
    register_class_factory("XQPCollator*", this);
  }

  virtual ::zorba::serialization::SerializeBaseClass* create_new(
      ::zorba::serialization::Archiver& ar)
  {
    return NULL;
  }

  virtual void cast_ptr(::zorba::serialization::SerializeBaseClass* ptr, void** class_ptr)
  {
    *class_ptr = (void*)dynamic_cast<XQPCollator*>(ptr);
  }
};

xqpcollator_class_factory g_xqpcollator_class_factory;


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, const XQType*& obj)
{
  XQType* obj2 = (XQType*)obj;

  ar.dont_allow_delay();

  operator&(ar, obj2);

  if (!ar.is_serializing_out())
    obj = (const XQType*)obj2;
}


#ifdef ZORBA_WITH_BIG_INTEGER
void operator&(serialization::Archiver& ar, IntegerImpl& obj)
#else
template<typename IntType>
void operator&(serialization::Archiver& ar, IntegerImpl<IntType>& obj)
#endif /* ZORBA_WITH_BIG_INTEGER */
{
  ar & obj.value_;
}
#ifndef ZORBA_WITH_BIG_INTEGER
template void operator&(serialization::Archiver&, IntegerImpl<long long>&);
template void operator&(serialization::Archiver&, IntegerImpl<unsigned long long>&);
#endif /* ZORBA_WITH_BIG_INTEGER */

/*******************************************************************************

********************************************************************************/
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


/*******************************************************************************

********************************************************************************/
void serialize_my_children(Archiver &ar, store::Iterator_t iter)
{
  if(ar.is_serializing_out())
  {
    std::vector<store::Item_t>  childs;
    iterator_to_vector(iter, childs);
    std::vector<store::Item_t>::iterator  child_it;
    int child_count = (int)childs.size();
    ar & child_count;

    for(child_it = childs.begin(); child_it != childs.end(); child_it++)
    {
      store::Item*  p = (*child_it).getp();

      ar.dont_allow_delay(SERIALIZE_NOW);
      //ar & p;
      serialize_node_tree(ar, p, false);
    }
  }
  else
  {
    int child_count;
    ar & child_count;

    for(int i=0;i<child_count;i++)
    {
      store::Item*  p = NULL; 
      //ar & p;//should be automatically added to DocumentNode or ElementNode
      serialize_node_tree(ar, p, false);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void serialize_my_children2(Archiver &ar, store::Iterator_t iter)
{
  serialize_my_children(ar, iter);
}

#define SERIALIZE_FIELD(type, var, get_func)\
  type var;                                 \
  if(ar.is_serializing_out())               \
    var = obj->get_func;                    \
  ar.dont_allow_delay();                    \
  ar & var;

#define SERIALIZE_FIELD2(type, var, get_func)\
  type var;                                  \
  if(ar.is_serializing_out())                \
    obj->get_func(var);                      \
  ar.dont_allow_delay();                     \
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

#define FINALIZE_SERIALIZE(create_func, func_params)                    \
  if (!ar.is_serializing_out())                                         \
  {                                                                     \
    store::Item_t result;                                               \
    GENV_ITEMFACTORY->create_func func_params;                          \
    obj = result.getp();                                                \
    if(obj)                                                             \
      obj->addReference();                                              \
    ar.set_is_temp_field(false);                                        \
    ar.register_reference(id, ARCHIVE_FIELD_PTR, obj);                  \
    ar.set_is_temp_field(true);                                         \
  }      


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, store::Item*& obj)
{
  bool is_ref = false;
  int  is_node = 0;
  int  is_atomic = 0;
  int  is_pul = 0;
  int  is_error = 0;
  int  is_function = 0;
  
  int   id;
  enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
  int   referencing;

  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field("store::Item*", 
                            FIELD_IS_CLASS,
                            "NULL", 
                            NULL,
                            ARCHIVE_FIELD_NULL);
      return;
    }

    char  strtemp[100];
    is_node = obj->isNode();
    is_atomic = obj->isAtomic();
    is_pul = obj->isPul();
    is_error = obj->isError();
    is_function = obj->isFunction();

    assert(is_node || is_atomic || is_pul || is_error || is_function);

    sprintf(strtemp, "n%da%dp%de%df%d",
                    is_node, is_atomic, is_pul, is_error, is_function);

    if (is_node || is_function)
      ar.set_is_temp_field(true);

    is_ref = ar.add_compound_field("store::Item*",
                                   FIELD_IS_CLASS,
                                   strtemp,
                                   obj,
                                   ARCHIVE_FIELD_PTR);

    if (is_node || is_function)
      ar.set_is_temp_field(false);
  }
  else
  {
    char* type;
    std::string value;
    bool  is_simple = false;
    bool  is_class = true;
    bool  retval;

    retval = ar.read_next_field(&type, &value, &id,
                                &is_simple, &is_class, &field_treat, &referencing);

    ar.check_class_field(retval, type, "store::Item*",
                         is_simple, is_class, field_treat, (enum  ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }

    if ((field_treat != ARCHIVE_FIELD_PTR) && (field_treat != ARCHIVE_FIELD_REFERENCING))
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
    }

    is_ref = (field_treat == ARCHIVE_FIELD_REFERENCING);

    if (!is_ref)
    {
      sscanf(value.c_str(), "n%da%dp%de%df%d",
                    &is_node, &is_atomic, &is_pul, &is_error, &is_function);
    }
  }

  if (!is_ref)
  {
    ar.set_is_temp_field(true);
    ar.set_is_temp_field_one_level(true);

    if (is_atomic)
    {
      store::Item_t type;
      zstring name_of_type;
      bool is_qname;

      if (ar.is_serializing_out())
      {
        type = obj->getType();
        name_of_type = type->getLocalName();
        const zstring& ns =type->getNamespace();
        is_qname = (name_of_type == "QName" && ns == XML_SCHEMA_NS);
      }

      ar & is_qname;

      if (!is_qname)
      {
        ar.dont_allow_delay();
        ar & type;//save qname of type

        ar.set_is_temp_field(false);
        ar.dont_allow_delay();

        ///check for User Typed Atomic Item
        store::Item* baseItem;
        if(ar.is_serializing_out())       
          baseItem = (store::Item*)obj->getBaseItem();            

        ar & baseItem;
        ar.set_is_temp_field(true);
        if(baseItem)
        {
          store::Item_t baseItem_rc(baseItem);
          FINALIZE_SERIALIZE(createUserTypedAtomicItem, (result, baseItem_rc, type));
          goto EndAtomicItem;
        }
      }
      else if (!ar.is_serializing_out())
      {
        GENV_ITEMFACTORY->createQName(type, XML_SCHEMA_NS, XML_SCHEMA_PREFIX, "QName");
      }

      if(!ar.is_serializing_out())
        name_of_type = type->getLocalName();

      if (name_of_type == "untyped")
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
        ERROR_PARAMS(name_of_type));
      }
      else if(name_of_type == "untypedAtomic")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createUntypedAtomic, (result, value));
      }
      else if(name_of_type == "anyType")
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
        ERROR_PARAMS(name_of_type));
      }
      else if(name_of_type == "anySimpleType")
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
          ERROR_PARAMS( name_of_type )
        );
      }
      else if(name_of_type == "anyAtomicType")
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
          ERROR_PARAMS( name_of_type )
        );
      }
      else if(name_of_type == "string")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createString, (result, value));
      }
      else if(name_of_type == "normalizedString")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createNormalizedString, (result, value));
      }
      else if(name_of_type == "language")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createLanguage, (result, value));
      }
      else if(name_of_type == "token")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createToken, (result, value));
      }
      else if(name_of_type == "NMTOKEN")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createNMTOKEN, (result, value));
      } 
      else if(name_of_type == "anyURI")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createAnyURI, (result, value));
      }
      else if(name_of_type == "Name")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createName, (result, value));
      }
      else if(name_of_type == "NCName")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createNCName, (result, value));
      }
      else if(name_of_type == "QName")
      {
        SERIALIZE_FIELD(zstring, ns, getNamespace());
        SERIALIZE_FIELD(zstring, prefix, getPrefix());
        SERIALIZE_FIELD(zstring, local, getLocalName());
        FINALIZE_SERIALIZE(createQName, (result, ns, prefix, local));
      }
      else if(name_of_type == "NOTATION")
      {
        SERIALIZE_FIELD(zstring, ns, getNamespace());
        SERIALIZE_FIELD(zstring, prefix, getPrefix());
        SERIALIZE_FIELD(zstring, local, getLocalName());
        FINALIZE_SERIALIZE(createNOTATION, (result, ns, prefix, local));
      }
      else if(name_of_type == "ID")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createID, (result, value));
      }
      else if(name_of_type == "IDREF")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createIDREF, (result, value));
      }
      else if(name_of_type == "ENTITY")
      {
        SERIALIZE_FIELD(zstring, value, getStringValue());
        FINALIZE_SERIALIZE(createENTITY, (result, value));
      }
      else if(name_of_type == "dateTime")
      {
        SERIALIZE_REF_FIELD(xs_dateTime, value, getDateTimeValue());
        FINALIZE_SERIALIZE(createDateTime, (result, &value_in));
      }
      else if(name_of_type == "date")
      {
        SERIALIZE_REF_FIELD(xs_date, value, getDateValue());
        FINALIZE_SERIALIZE(createDate, (result, &value_in));
      }
      else if(name_of_type == "time")
      {
        SERIALIZE_REF_FIELD(xs_time, value, getTimeValue());
        FINALIZE_SERIALIZE(createTime, (result, &value_in));
      }
      else if(name_of_type == "duration")
      {
        SERIALIZE_REF_FIELD(xs_duration, value, getDurationValue());
        FINALIZE_SERIALIZE(createDuration, (result, &value_in));
      }
      else if(name_of_type == "dayTimeDuration")
      {
        SERIALIZE_REF_FIELD(xs_dayTimeDuration, value, getDayTimeDurationValue());
        FINALIZE_SERIALIZE(createDayTimeDuration, (result, &value_in));
      }
      else if(name_of_type == "yearMonthDuration")
      {
        SERIALIZE_REF_FIELD(xs_yearMonthDuration, value, getYearMonthDurationValue());
        FINALIZE_SERIALIZE(createYearMonthDuration, (result, &value_in));
      }
         
      else if(name_of_type == "float")
      {
        SERIALIZE_FIELD(xs_float, value, getFloatValue());
        FINALIZE_SERIALIZE(createFloat, (result, value));
      }
      else if(name_of_type == "double")
      {
        SERIALIZE_FIELD(xs_double, value, getDoubleValue());
        FINALIZE_SERIALIZE(createDouble, (result, value));
      }
      else if(name_of_type == "decimal")
      {
        SERIALIZE_FIELD(xs_decimal, value, getDecimalValue());
        FINALIZE_SERIALIZE(createDecimal, (result, value));
      }
      else if(name_of_type == "integer")
      {
        SERIALIZE_FIELD(xs_integer, value, getIntegerValue());
        FINALIZE_SERIALIZE(createInteger, (result, value));
      }
      else if(name_of_type == "nonPositiveInteger")
      {
        SERIALIZE_FIELD(xs_integer, value, getIntegerValue());
        FINALIZE_SERIALIZE(createNonPositiveInteger, (result, value));
      }
      else if(name_of_type == "nonNegativeInteger")
      {
        SERIALIZE_FIELD(xs_nonNegativeInteger, value, getUnsignedIntegerValue());
        FINALIZE_SERIALIZE(createNonNegativeInteger, (result, value));
      }
      else if(name_of_type == "negativeInteger")
      {
        SERIALIZE_FIELD(xs_integer, value, getIntegerValue());
        FINALIZE_SERIALIZE(createNegativeInteger, (result, value));
      }
      else if(name_of_type == "positiveInteger")
      {
        SERIALIZE_FIELD(xs_positiveInteger, value, getUnsignedIntegerValue());
        FINALIZE_SERIALIZE(createPositiveInteger, (result, value));
      }
         
      else if(name_of_type == "long")
      {
        SERIALIZE_FIELD(xs_long, value, getLongValue());
        FINALIZE_SERIALIZE(createLong, (result, value));
      }
      else if(name_of_type == "int")
      {
        SERIALIZE_FIELD(xs_int, value, getIntValue());
        FINALIZE_SERIALIZE(createInt, (result, value));
      }
      else if(name_of_type == "short")
      {
        SERIALIZE_FIELD(xs_short, value, getShortValue());
        FINALIZE_SERIALIZE(createShort, (result, value));
      }
      else if(name_of_type == "byte")
      {
        SERIALIZE_FIELD(xs_byte, value, getByteValue());
        FINALIZE_SERIALIZE(createByte, (result, value));
      }
      else if(name_of_type == "unsignedLong")
      {
        SERIALIZE_FIELD(xs_unsignedLong, value, getUnsignedLongValue());
        FINALIZE_SERIALIZE(createUnsignedLong, (result, value));
      }
      else if(name_of_type == "unsignedInt")
      {
        SERIALIZE_FIELD(xs_unsignedInt, value, getUnsignedIntValue());
        FINALIZE_SERIALIZE(createUnsignedInt, (result, value));
      }
      else if(name_of_type == "unsignedShort")
      {
        SERIALIZE_FIELD(xs_unsignedShort, value, getUnsignedShortValue());
        FINALIZE_SERIALIZE(createUnsignedShort, (result, value));
      }
      else if(name_of_type == "unsignedByte")
      {
        SERIALIZE_FIELD(xs_unsignedByte, value, getUnsignedByteValue());
        FINALIZE_SERIALIZE(createUnsignedByte, (result, value));
      }
         
      else if(name_of_type == "gYearMonth")
      {
        SERIALIZE_REF_FIELD(xs_gYearMonth, value, getGYearMonthValue());
        FINALIZE_SERIALIZE(createGYearMonth, (result, &value_in));
      }
      else if(name_of_type == "gYear")
      {
        SERIALIZE_REF_FIELD(xs_gYear, value, getGYearValue());
        FINALIZE_SERIALIZE(createGYear, (result, &value_in));
      }
      else if(name_of_type == "gMonthDay")
      {
        SERIALIZE_REF_FIELD(xs_gMonthDay, value, getGMonthDayValue());
        FINALIZE_SERIALIZE(createGMonthDay, (result, &value_in));
      }
      else if(name_of_type == "gDay")
      {
        SERIALIZE_REF_FIELD(xs_gDay, value, getGDayValue());
        FINALIZE_SERIALIZE(createGDay, (result, &value_in));
      }
      else if(name_of_type == "gMonth")
      {
        SERIALIZE_REF_FIELD(xs_gMonth, value, getGMonthValue());
        FINALIZE_SERIALIZE(createGMonth, (result, &value_in));
      }
         
      else if(name_of_type == "base64Binary")
      {
        if (ar.is_serializing_out())
        {
          size_t s;
          const char* c = obj->getBase64BinaryValue(s);
          if (obj->isEncoded())
          {
            Base64 tmp;
            Base64::parseString(c, s, tmp);
            ar.dont_allow_delay();
            ar & tmp;
          }
          else
          {
            Base64 tmp((const unsigned char*)c, s);
            ar.dont_allow_delay();
            ar & tmp;
          }
        }
        else
        {
          ar.dont_allow_delay();
          Base64 tmp;
          ar & tmp;
          FINALIZE_SERIALIZE(createBase64Binary, (result, tmp));
        }
      }
      else if(name_of_type == "hexBinary")
      {
        SERIALIZE_REF_FIELD(xs_hexBinary, value, getHexBinaryValue());
        FINALIZE_SERIALIZE(createHexBinary, (result, value_in));
      }
      else if(name_of_type == "boolean")
      {
        SERIALIZE_FIELD(bool, value, getBooleanValue());
        FINALIZE_SERIALIZE(createBoolean, (result, value));
      }
      else
      {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
          ERROR_PARAMS( name_of_type )
        );
      }
EndAtomicItem:;
    }
    else if (is_node)
    {
      serialize_node_tree(ar, obj, true);
    }
    else if (is_pul)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
      ERROR_PARAMS("Pul"));
    }
    else if (is_error)
    {
      ZORBA_ASSERT(false);
      SERIALIZE_FIELD(ZorbaException*, value, getError());
      FINALIZE_SERIALIZE(createError, (result, value));
    }
    else if (is_function)
    {
      FunctionItem* fitem = NULL;
      if (ar.is_serializing_out())
      {
        fitem = dynamic_cast<FunctionItem*>(obj);
      }

      ar.dont_allow_delay();
      ar.set_is_temp_field(false);                    

      ar & fitem;

      if (!ar.is_serializing_out())
      {
        assert(fitem);
        obj = fitem;
        if (obj)                                         
          obj->addReference();     

        ar.register_reference(id, ARCHIVE_FIELD_PTR, obj);                
      }

      ar.set_is_temp_field(true);    
    }
    else
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
      ERROR_PARAMS("[Unknown item type]"));
    }

    ar.set_is_temp_field(false);
    ar.set_is_temp_field_one_level(false);
  }

  if (ar.is_serializing_out())
  {
    if (!is_ref)
      ar.add_end_compound_field();
  }
  else
  {
    if (!is_ref)
    {
      if (!is_node)
        ar.register_item(obj);

      ar.read_end_current_level();
    }
    else
    {
      store::Item  *new_obj = NULL;
      if ((new_obj = (store::Item*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_REFERENCING
      {
        obj = dynamic_cast<store::Item*>(new_obj);
        if (!obj)
        {
          throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, 
          ERROR_PARAMS(id));
        }
      }
      else if (!ar.get_is_temp_field() && !ar.get_is_temp_field_one_level())
      {
        ZORBA_ASSERT(false);
      }
      else
      {
        obj = NULL;
      }
    }
  }

}


/*******************************************************************************

********************************************************************************/
void serialize_node_tree(Archiver& ar, store::Item*& obj, bool all_tree)
{
  //only for node items
  //serialize first whole tree and then the item (will surely be a reference)
  if(all_tree)
  {
    store::Item *parent = NULL;
    if(ar.is_serializing_out())
    {
      if(obj != NULL)
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
  enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
  int   referencing;
  bool is_ref;

  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field("NULL", 
                            !FIELD_IS_CLASS,
                            "NULL", 
                            NULL,
                            ARCHIVE_FIELD_NULL);

      ar.set_is_temp_field(true);
      return;
    }

    is_ref = ar.add_compound_field("store::Item*",
                                   FIELD_IS_CLASS,
                                   "", 
                                   obj, 
                                   ARCHIVE_FIELD_PTR);
  }
  else
  {
    char* type;
    std::string value;
    bool  is_simple = false;
    bool  is_class = true;

    bool  retval = ar.read_next_field(&type, &value, &id,
                                      &is_simple, &is_class, &field_treat,
                                      &referencing);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      ar.set_is_temp_field(true);
      return;
    }
    ar.check_class_field(retval, type, "store::Item*", is_simple, is_class, field_treat, (enum  ArchiveFieldKind)-1, id);
    //ar.register_reference(id, &obj);
    if((field_treat != ARCHIVE_FIELD_PTR) && (field_treat != ARCHIVE_FIELD_REFERENCING))
    {
      throw ZORBA_EXCEPTION(
        zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
      );
    }
    is_ref = (field_treat == ARCHIVE_FIELD_REFERENCING);
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
      throw ZORBA_EXCEPTION(
        zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE, ERROR_PARAMS( "anyNode" )
      );
    case store::StoreConsts::documentNode:
    {
      SERIALIZE_FIELD2(zstring, baseUri, getBaseURI);
      SERIALIZE_FIELD2(zstring, docUri, getDocumentURI);
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
        if(!ZSTREQ(name_of_type->getNamespace(), XML_SCHEMA_NS) ||
           !ZSTREQ(name_of_type->getLocalName(), "untyped"))
          haveTypedValue = true;
      }
      ar & haveTypedValue;
      ar & haveEmptyValue;
      store::NsBindings ns_bindings;
      if(ar.is_serializing_out())
        obj->getNamespaceBindings(ns_bindings, store::StoreConsts::ONLY_LOCAL_NAMESPACES);
      ar & ns_bindings;
      SERIALIZE_FIELD2(zstring, baseUri, getBaseURI);
      FINALIZE_SERIALIZE(createElementNode, (result, parent, nodename, name_of_type, haveTypedValue, haveEmptyValue, ns_bindings, baseUri, isInSubstGroup));

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
        FINALIZE_SERIALIZE(createAttributeNode, (result, parent, nodename, name_of_type, val));
      }
      else
      {
        FINALIZE_SERIALIZE(createAttributeNode, (result, parent, nodename, name_of_type, val_vector));
      }
    }break;
    case store::StoreConsts::textNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(zstring, content, getStringValue());
      FINALIZE_SERIALIZE(createTextNode, (result, parent, content));
    }break;
    case store::StoreConsts::piNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(zstring, target, getTarget());
      SERIALIZE_FIELD(zstring, content, getStringValue());
      SERIALIZE_FIELD2(zstring, baseUri, getBaseURI);
      FINALIZE_SERIALIZE(createPiNode, (result, parent, target, content, baseUri));
    }break;
    case store::StoreConsts::commentNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(zstring, content, getStringValue());
      FINALIZE_SERIALIZE(createCommentNode, (result, parent, content));
    }break;
    default:
      throw ZORBA_EXCEPTION(
        zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE, ERROR_PARAMS( "unknown" )
      );
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
      store::Item  *new_obj = NULL;
      if((new_obj = (store::Item*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_REFERENCING
      {
        obj = dynamic_cast<store::Item*>(new_obj);
        if(!obj)
        {
          throw ZORBA_EXCEPTION(
            zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS( id )
          );
        }
      }
      else if(!ar.get_is_temp_field() && !ar.get_is_temp_field_one_level())
      {
        ZORBA_ASSERT(false);
      }
      else
        obj = NULL;
    }
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, zorba::store::TempSeq* obj)
{
  throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
  ERROR_PARAMS("TempSeq"));
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, const Diagnostic*& obj)
{
  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field("NULL", 
                            !FIELD_IS_CLASS,
                            "NULL", 
                            NULL,
                            ARCHIVE_FIELD_NULL);
      return;
    }

    bool is_ref;
    assert(!ar.is_serialize_base_class());
    Diagnostic* diagnostic = const_cast<Diagnostic*>(obj);
    UserError* user_err = dynamic_cast<UserError*>(diagnostic);
    XQueryErrorCode* xquery_err = dynamic_cast<XQueryErrorCode*>(diagnostic);
    ZorbaErrorCode* zorba_err = dynamic_cast<ZorbaErrorCode*>(diagnostic);
    char err_type[20];
    sprintf(err_type, "u%dx%dz%d", 
            user_err != NULL ? 1 : 0,
            xquery_err != NULL ? 1 : 0,
            zorba_err != NULL ? 1 : 0);

    is_ref = ar.add_compound_field("Diagnostic*", 
                                   !FIELD_IS_CLASS,
                                   err_type, 
                                   obj, 
                                   ARCHIVE_FIELD_PTR);
    if (!is_ref)
    {
      if (user_err)
      {
        ar & user_err->qname_;
      }
      else
      {
        ar.set_is_temp_field(true);
        const diagnostic::QName   &errqn = obj->qname();
        char*   strtemp = (char*)errqn.localname();
        ar & strtemp;
        ar.set_is_temp_field(false);
      }

      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);

    ar.check_nonclass_field(retval, type, "Diagnostic*", is_simple, is_class, field_treat, (ArchiveFieldKind)-1, id);
    if(field_treat == ARCHIVE_FIELD_NULL)
    {
      assert(!ar.is_serialize_base_class());
      obj = NULL;
      ar.read_end_current_level();
      return;
    }
    if(field_treat == ARCHIVE_FIELD_PTR)
    {
      int is_user, is_xquery, is_zorba;
      sscanf(value.c_str(), "u%dx%dz%d", &is_user, &is_xquery, &is_zorba);
      if(is_user)
      {
        UserError *user_error = new UserError(ar);
        ar & user_error->qname_;
        obj = user_error;
      }
      else if(is_xquery || is_zorba)
      {
        ar.set_is_temp_field(true);
        char*   local;
        ar & local;
        ar.set_is_temp_field(false);
        obj = internal::SystemDiagnosticBase::find(local);
        free(local);
        ZORBA_ASSERT(obj);
      }
      else
      {
        ZORBA_ASSERT(false);//unreachable, maybe a new Error class has been added
      }
      ar.register_reference(id, field_treat, obj);
      ar.read_end_current_level();
    }
    else if((obj = (Diagnostic*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
    {
    }
    else
    {
      ZORBA_ASSERT(false);
    }
  }

}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, ZorbaException*& obj)
{
  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field("NULL", 
                            !FIELD_IS_CLASS,
                            "NULL", 
                            NULL,
                            ARCHIVE_FIELD_NULL);
      return;
    }

    assert(!ar.is_serialize_base_class());

    UserException* user_ex = dynamic_cast<UserException*>(obj);
    XQueryException* xquery_ex = dynamic_cast<XQueryException*>(obj);
    char ex_type[20];
    sprintf(ex_type, "u%dx%d", 
            user_ex != NULL ? 1 : 0,
            xquery_ex != NULL ? 1 : 0);

    bool is_ref = ar.add_compound_field("ZorbaException*", 
                                        !FIELD_IS_CLASS,
                                        ex_type,
                                        obj, 
                                        ARCHIVE_FIELD_PTR);
    if (!is_ref)
    {
      ar & obj->diagnostic_;
      ar & obj->raise_file_;
      ar & obj->raise_line_;
      ar & obj->message_;

      if (xquery_ex)
      {
        ar & xquery_ex->source_loc_;
        ar & xquery_ex->query_trace_;
      }

      if (user_ex)
      {
        ar & user_ex->error_object_;
      }

      ar.add_end_compound_field();
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);

    ar.check_nonclass_field(retval, type, "ZorbaException*", is_simple, is_class, field_treat, (ArchiveFieldKind)-1, id);
    if(field_treat == ARCHIVE_FIELD_NULL)
    {
      assert(!ar.is_serialize_base_class());
      obj = NULL;
      ar.read_end_current_level();
      return;
    }

    if (field_treat == ARCHIVE_FIELD_PTR)
    {
      int is_user, is_xquery;
      sscanf(value.c_str(), "u%dx%d", &is_user, &is_xquery);
      UserException* user_ex = NULL;
      XQueryException* xquery_ex = NULL;

      if (is_user)
      {
        user_ex = new UserException(ar);
        xquery_ex = user_ex;
        obj = user_ex;
      }
      else if(is_xquery)
      {
        xquery_ex = new XQueryException(ar);
        obj = xquery_ex;
      }
      else
        obj = new ZorbaException(ar);

      ar & obj->diagnostic_;
      ar & obj->raise_file_;
      ar & obj->raise_line_;
      ar & obj->message_;

      if(xquery_ex)
      {
        ar & xquery_ex->source_loc_;
        ar & xquery_ex->query_trace_;
      }
      if(user_ex)
      {
        ar & user_ex->error_object_;
      }

      ar.register_reference(id, field_treat, obj);
      ar.read_end_current_level();
    }
    else if((obj = (ZorbaException*)ar.get_reference_value(referencing)))// ARCHIVE_FIELD_IS_REFERENCING
    {
    }
    else
    {
      ZORBA_ASSERT(false);
    }
  }

}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, zorba::internal::diagnostic::location& obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("internal::diagnostic::location", !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      ar & obj.file_;
      ar & obj.line_;
      ar & obj.column_;
      ar & obj.line_end_;
      ar & obj.column_end_;
      ar.add_end_compound_field();
    }
    else
    {
      assert(false);
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);

    ar.check_nonclass_field(retval, type, "internal::diagnostic::location", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);

    ar & obj.file_;
    ar & obj.line_;
    ar & obj.column_;
    ar & obj.line_end_;
    ar & obj.column_end_;
    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, zorba::Item& obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("zorba::Item", !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      ar & obj.m_item;
      ar.add_end_compound_field();
    }
    else
    {
      assert(false);
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);

    ar.check_nonclass_field(retval, type, "zorba::Item", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);

    ar & obj.m_item;
    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, zorba::XQueryStackTrace& obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("XQueryStackTrace", !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      ar & obj.trace_;
      ar.add_end_compound_field();
    }
    else
    {
      assert(false);
    }
  }
  else
  {
    char  *type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);

    ar.check_nonclass_field(retval, type, "XQueryStackTrace", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);

    ar & obj.trace_;
    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, zorba::XQueryStackTrace::Entry& obj)
{
  if(ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field("XQueryStackTrace::Entry", !FIELD_IS_CLASS, "", &obj, ARCHIVE_FIELD_NORMAL);
    if(!is_ref)
    {
      ar & obj.getFnNameRef();
      ar & obj.getFnArityRef();
      ar & obj.getFileNameRef();
      ar & obj.getLineRef();
      ar & obj.getColumnRef();
      ar & obj.getLineEndRef();
      ar & obj.getColumnEndRef();
      ar.add_end_compound_field();
    }
    else
    {
      assert(false);
    }
  }
  else
  {
    char* type;
    std::string value;
    int   id;
    bool  is_simple = false;
    bool  is_class = false;
    enum  ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int   referencing;
    bool  retval;
    retval = ar.read_next_field(&type, &value, &id, &is_simple, &is_class, &field_treat, &referencing);

    ar.check_nonclass_field(retval, type, "XQueryStackTrace::Entry", is_simple, is_class, field_treat, ARCHIVE_FIELD_NORMAL, id);

    ar & obj.getFnNameRef();
    ar & obj.getFnArityRef();
    ar & obj.getFileNameRef();
    ar & obj.getLineRef();
    ar & obj.getColumnRef();
    ar & obj.getLineEndRef();
    ar & obj.getColumnEndRef();
    ar.read_end_current_level();
  }
}


}
} // namespace zorba
/* vim:set et sw=2 ts=2: */
