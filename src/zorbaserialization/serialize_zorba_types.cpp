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
#include <zorba/store_consts.h>

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
#include "zorbatypes/floatimpl.h"
#include "zorbatypes/binary.h"
#include "zorbatypes/decimal.h"

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
void operator&(Archiver& ar, const XQType*& obj)
{
  XQType* obj2 = (XQType*)obj;

  ar.dont_allow_delay();

  operator&(ar, obj2);

  if (!ar.is_serializing_out())
    obj = (const XQType*)obj2;
}


/*******************************************************************************

********************************************************************************/
#ifdef ZORBA_WITH_BIG_INTEGER

void operator&(serialization::Archiver& ar, IntegerImpl& obj)
{
  ar & obj.value_;
}

#else

void operator&(serialization::Archiver& ar, IntegerImpl<long long>& obj)
{
  serialize_long_long(ar, obj.get_value());
}

void operator&(serialization::Archiver& ar, IntegerImpl<unsigned long long>& obj)
{
  serialize_ulong_long(ar, obj.get_value());
}

#endif


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, Decimal& obj)
{
  ar & obj.value_;
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, DateTime& obj)
{
  SERIALIZE_ENUM(DateTime::FACET_TYPE, obj.facet);

  serialize_long(ar, obj.data[0]);
  serialize_long(ar, obj.data[1]);
  serialize_long(ar, obj.data[2]);
  serialize_long(ar, obj.data[3]);
  serialize_long(ar, obj.data[4]);
  serialize_long(ar, obj.data[5]);
  serialize_long(ar, obj.data[6]);

  ar & obj.the_time_zone;
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, Duration& obj)
{
  SERIALIZE_ENUM(Duration::FACET_TYPE, obj.facet);
  ar & obj.is_negative;

  serialize_long(ar, obj.data[0]);
  serialize_long(ar, obj.data[1]);
  serialize_long(ar, obj.data[2]);
  serialize_long(ar, obj.data[3]);
  serialize_long(ar, obj.data[4]);
  serialize_long(ar, obj.data[5]);
  serialize_long(ar, obj.data[6]);
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, TimeZone& obj)
{
  ar & static_cast<Duration&>(obj);
  ar & obj.timezone_not_set;
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, Base64& obj)
{
  ar & obj.theData;
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, Base16& obj)
{
  ar & obj.theData;
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, HashMapZStringCmp& obj)
{
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, HashMapItemPointerCmp& obj)
{
  if (ar.is_serializing_out())
  {
    int32_t tz = obj.theTimeZone;
    ar & tz;
  }
  else
  {
    int32_t tz = 0;
    ar & tz;
    obj.theTimeZone = tz;
  }

  ar & obj.theCollator;
}


/*******************************************************************************

********************************************************************************/
void iterator_to_vector(store::Iterator_t iter, std::vector<store::Item_t>& items)
{
  store::Item_t i;

  iter->open();

  while (iter->next(i))
  {
    items.push_back(i);
  }

  iter->close();
}


void serialize_atomic_item(Archiver& ar, store::Item*& obj);
void deserialize_atomic_item(Archiver& ar, store::Item*& obj, int id);
void serialize_node_tree(Archiver& ar, store::Item*& obj, bool all_tree);
void serialize_my_children(Archiver& ar, store::Iterator_t iter);
void serialize_my_children2(Archiver& ar, store::Iterator_t iter);

#ifdef ZORBA_WITH_JSON
void serialize_json_tree(Archiver &ar, store::Item *&obj);
#endif


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
void operator&(Archiver& ar, zorba::Item& obj)
{
  assert(false);

  if (ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field(TYPE_LAST,
                                   !FIELD_IS_CLASS,
                                   &obj,
                                   ARCHIVE_FIELD_NORMAL);
    if (!is_ref)
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
    TypeCode type;
    int id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int referencing;

    ar.read_next_compound_field(false, field_treat, type, id, referencing);

    ar.check_nonclass_field(field_treat, ARCHIVE_FIELD_NORMAL, id);

    ar & obj.m_item;
    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, store::Item*& obj)
{
  bool is_ref = false;
  store::Item::ItemKind kind;
  
  int id;
  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
  int referencing;

  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field(TYPE_NULL, 
                            !FIELD_IS_CLASS,
                            NULL,
                            ARCHIVE_FIELD_NULL);
      return;
    }

    kind = obj->getKind();

    if (kind == store::Item::NODE ||
        kind == store::Item::FUNCTION
#ifdef ZORBA_WITH_JSON
        || kind == store::Item::JSONIQ
#endif
        )
    {
      ar.set_is_temp_field(true);
    }

    is_ref = ar.add_compound_field(TYPE_LAST,
                                   !FIELD_IS_CLASS,
                                   obj,
                                   ARCHIVE_FIELD_PTR);

    if (kind == store::Item::NODE ||
        kind == store::Item::FUNCTION
#ifdef ZORBA_WITH_JSON
        || kind == store::Item::JSONIQ
#endif
        )
    {
      ar.set_is_temp_field(false);
    }

    if (!is_ref)
    {
      SERIALIZE_ENUM(store::Item::ItemKind, kind);

      switch (kind)
      {
      case store::Item::ATOMIC:
      {
        serialize_atomic_item(ar, obj);
        break;
      }
      case store::Item::NODE:
      {
        ar.set_is_temp_field(true);
        ar.set_is_temp_field_one_level(true);

        serialize_node_tree(ar, obj, true);

        ar.set_is_temp_field(false);
        ar.set_is_temp_field_one_level(false);

        break;
      }
#ifdef ZORBA_WITH_JSON
      case store::Item::JSON_ITEM:
      {
        ar.set_is_temp_field(true);
        ar.set_is_temp_field_one_level(true);

        serialize_json_tree(ar, obj);

        ar.set_is_temp_field(false);
        ar.set_is_temp_field_one_level(false);

        break;
      }
#endif
      case store::Item::FUNCTION:
      {
        FunctionItem* fitem = static_cast<FunctionItem*>(obj);

        ar & fitem;

        break;
      }
      case store::Item::ERROR_:
      {
        ZorbaException* val = obj->getError();
        ar & val;
        break;
      }
      case store::Item::PUL:
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
        ERROR_PARAMS("Pul"));
      }
      default:
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
        ERROR_PARAMS("[Unknown item type]"));
      }
      }

      ar.add_end_compound_field();
    }
  }
  else
  {
    TypeCode type;

    ar.read_next_compound_field(false, field_treat, type, id, referencing);

    ar.check_nonclass_field(field_treat, (ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      return;
    }

    if (field_treat != ARCHIVE_FIELD_PTR && field_treat != ARCHIVE_FIELD_REFERENCING)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
    }

    is_ref = (field_treat == ARCHIVE_FIELD_REFERENCING);

    if (!is_ref)
    {
      SERIALIZE_ENUM(store::Item::ItemKind, kind);

      switch (kind)
      {
      case store::Item::ATOMIC:
      {
        deserialize_atomic_item(ar, obj, id);
        break;
      }
      case store::Item::NODE:
      {
        ar.set_is_temp_field(true);
        ar.set_is_temp_field_one_level(true);

        serialize_node_tree(ar, obj, true);

        ar.set_is_temp_field(false);
        ar.set_is_temp_field_one_level(false);

        break;
      }
#ifdef ZORBA_WITH_JSON
      case store::Item::JSON_ITEM:
      {
        ar.set_is_temp_field(true);
        ar.set_is_temp_field_one_level(true);

        serialize_json_tree(ar, obj);

        ar.set_is_temp_field(false);
        ar.set_is_temp_field_one_level(false);

        break;
      }
#endif
      case store::Item::FUNCTION:
      {
        FunctionItem* fitem = NULL;

        ar & fitem;

        assert(fitem);

        obj = fitem;
        if (obj)                                         
          obj->addReference();     

        ar.register_reference(id, ARCHIVE_FIELD_PTR, obj);                

        break;
      }
      case store::Item::ERROR_:
      {
        ZORBA_ASSERT(false);
        ZorbaException* val;
        ar & val;

        store::Item_t result;
        GENV_ITEMFACTORY->createError(result, val);

        obj = result.getp();
        if (obj)
          obj->addReference(); 

        ar.register_reference(id, ARCHIVE_FIELD_PTR, obj);
      }
      case store::Item::PUL:
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
        ERROR_PARAMS("Pul"));
      }
      default:
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
        ERROR_PARAMS("[Unknown item type]"));
      }
      }

      if (kind != store::Item::NODE)
        ar.register_item(obj);

      ar.read_end_current_level();
    } // !is_ref
    else
    {
      store::Item* new_obj = NULL;
      if ((new_obj = (store::Item*)ar.get_reference_value(referencing)))
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
  } // de-serializing
}


/*******************************************************************************

********************************************************************************/
#define SERIALIZE_ATOMIC_ITEM(type, get_func)        \
  ar.set_is_temp_field(true);                        \
  type val = obj->get_func;                          \
  ar & val;                                          \
  ar.set_is_temp_field(false);                       \
  break;


void serialize_atomic_item(Archiver& ar, store::Item*& obj)
{
  store::Item* typeName;
  store::SchemaTypeCode typeCode;
  store::Item* baseItem = NULL;
  
  baseItem = obj->getBaseItem();
    
  if (baseItem)
  {
    typeName = obj->getType();
    typeCode = store::XS_LAST;
    
    SERIALIZE_ENUM(store::SchemaTypeCode, typeCode);
    
    ar & baseItem;
    ar & typeName;

    return;
  }

  typeCode = obj->getTypeCode();
    
  SERIALIZE_ENUM(store::SchemaTypeCode, typeCode);
 
  switch (typeCode)
  {
  case store::XS_STRING:
  case store::XS_NORMALIZED_STRING:
  case store::XS_TOKEN:
  case store::XS_LANGUAGE:
  case store::XS_NMTOKEN:
  case store::XS_NAME:
  case store::XS_NCNAME:
  case store::XS_ID:
  case store::XS_IDREF:
  case store::XS_ENTITY:
    
  case store::XS_UNTYPED_ATOMIC:
  {
    SERIALIZE_ATOMIC_ITEM(zstring, getString());
  }
  
  case store::XS_DATETIME:
  {
    SERIALIZE_ATOMIC_ITEM(xs_dateTime, getDateTimeValue());
  }
  case store::XS_DATE:
  {
    SERIALIZE_ATOMIC_ITEM(xs_date, getDateValue());
  }
  case store::XS_TIME:
  {
    SERIALIZE_ATOMIC_ITEM(xs_time, getTimeValue());
  }

  case store::XS_DURATION:
  {
    SERIALIZE_ATOMIC_ITEM(xs_duration, getDurationValue());
  }
  case store::XS_DT_DURATION:
  {
    SERIALIZE_ATOMIC_ITEM(xs_dayTimeDuration, getDayTimeDurationValue());
  }
  case store::XS_YM_DURATION: 
  {
    SERIALIZE_ATOMIC_ITEM(xs_yearMonthDuration, getYearMonthDurationValue());
  }
  
  case store::XS_FLOAT:
  {
    SERIALIZE_ATOMIC_ITEM(xs_float, getFloatValue());
  }
  case store::XS_DOUBLE:
  {
    SERIALIZE_ATOMIC_ITEM(xs_double, getDoubleValue());
  }

  case store::XS_DECIMAL:
  {
    SERIALIZE_ATOMIC_ITEM(xs_decimal, getDecimalValue());
  }
  case store::XS_INTEGER:
  {
    SERIALIZE_ATOMIC_ITEM(xs_integer, getIntegerValue());
  }
  case store::XS_NON_POSITIVE_INTEGER:
  {
    SERIALIZE_ATOMIC_ITEM(xs_integer, getIntegerValue());
  }
  case store::XS_NEGATIVE_INTEGER:
  {
    SERIALIZE_ATOMIC_ITEM(xs_integer, getIntegerValue());
  }
  case store::XS_LONG:
  {
    SERIALIZE_ATOMIC_ITEM(xs_long, getLongValue());
  }
  case store::XS_INT:
  {
    SERIALIZE_ATOMIC_ITEM(xs_int, getIntValue());
  }
  case store::XS_SHORT:
  {
    SERIALIZE_ATOMIC_ITEM(xs_short, getShortValue());
  }
  case store::XS_BYTE:
  {
    SERIALIZE_ATOMIC_ITEM(char, getByteValue());
  }
  case store::XS_NON_NEGATIVE_INTEGER:
  {
    SERIALIZE_ATOMIC_ITEM(xs_nonNegativeInteger, getUnsignedIntegerValue());
  }
  case store::XS_POSITIVE_INTEGER:
  {
    SERIALIZE_ATOMIC_ITEM(xs_positiveInteger, getUnsignedIntegerValue());
  }
  case store::XS_UNSIGNED_LONG:
  {
    SERIALIZE_ATOMIC_ITEM(xs_unsignedLong, getUnsignedLongValue());
  }
  case store::XS_UNSIGNED_INT:
  {
    SERIALIZE_ATOMIC_ITEM(xs_unsignedInt, getUnsignedIntValue());
  }
  case store::XS_UNSIGNED_SHORT:
  {
    SERIALIZE_ATOMIC_ITEM(xs_unsignedShort, getUnsignedShortValue());
  }
  case store::XS_UNSIGNED_BYTE:
  {
    SERIALIZE_ATOMIC_ITEM(xs_unsignedByte, getUnsignedByteValue());
  }

  case store::XS_GYEAR_MONTH:
  {
    SERIALIZE_ATOMIC_ITEM(xs_gYearMonth, getGYearMonthValue());
  }
  case store::XS_GYEAR:
  {
    SERIALIZE_ATOMIC_ITEM(xs_gYear, getGYearValue());
  }
  case store::XS_GMONTH_DAY:
  {
    SERIALIZE_ATOMIC_ITEM(xs_gMonthDay, getGMonthDayValue());
  }
  case store::XS_GDAY:
  {
    SERIALIZE_ATOMIC_ITEM(xs_gDay, getGDayValue());
  }
  case store::XS_GMONTH:
  {
    SERIALIZE_ATOMIC_ITEM(xs_gMonth, getGMonthValue());
  }    

  case store::XS_BOOLEAN:
  {
    SERIALIZE_ATOMIC_ITEM(bool, getBooleanValue());
  }

  case store::XS_HEXBINARY:
  {
    SERIALIZE_ATOMIC_ITEM(xs_hexBinary, getHexBinaryValue());
  }
  case store::XS_BASE64BINARY:
  {
    ar.set_is_temp_field(true);

    size_t s;
    const char* c = obj->getBase64BinaryValue(s);
    if (obj->isEncoded())
    {
      Base64 tmp;
      Base64::parseString(c, s, tmp);
      ar & tmp;
    }
    else
    {
      Base64 tmp((const unsigned char*)c, s);
      ar & tmp;
    }
    
    ar.set_is_temp_field(false);

    break;
  }
  
  case store::XS_ANY_URI:
  {
    SERIALIZE_ATOMIC_ITEM(zstring, getString());
  }
  
  case store::XS_QNAME:
  case store::XS_NOTATION:
  {
    zstring ns = obj->getNamespace();
    zstring prefix = obj->getPrefix();
    zstring local = obj->getLocalName();
    ar & ns;
    ar & prefix;
    ar & local;
    
    break;
  }
 
 #ifdef ZORBA_WITH_JSON
  case store::JDM_NULL:
  {
    break;
  }
#endif

  default:
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
    ERROR_PARAMS("unknown atomic item type"));
  }
  }
}


/*******************************************************************************

********************************************************************************/

#define DESERIALIZE_ATOMIC_ITEM(type, create_func)    \
  ar.set_is_temp_field(true);                         \
  type val;                                           \
  ar & val;                                           \
  ar.set_is_temp_field(false);                        \
                                                      \
  store::Item_t result;                               \
  GENV_ITEMFACTORY->create_func(result, val);         \
                                                      \
  obj = result.getp();                                \
  if(obj)                                             \
    obj->addReference();                              \
                                                      \
  ar.register_reference(id, ARCHIVE_FIELD_PTR, obj);  \
                                                      \
  break;


#define DESERIALIZE_ATOMIC_ITEM2(type, create_func)   \
  ar.set_is_temp_field(true);                         \
  type val;                                           \
  ar & val;                                           \
  ar.set_is_temp_field(false);                        \
                                                      \
  store::Item_t result;                               \
  GENV_ITEMFACTORY->create_func(result, &val);        \
                                                      \
  obj = result.getp();                                \
  if(obj)                                             \
    obj->addReference();                              \
                                                      \
  ar.register_reference(id, ARCHIVE_FIELD_PTR, obj);  \
                                                      \
  break;


void deserialize_atomic_item(Archiver& ar, store::Item*& obj, int id)
{
  store::Item_t typeName;
  store::SchemaTypeCode typeCode = store::XS_LAST;
  store::Item* baseItem = NULL;
  
  SERIALIZE_ENUM(store::SchemaTypeCode, typeCode);
  
  // If it's a user-defined item, deserialize the base item and the UDT qname
  if (typeCode == store::XS_LAST)
  {
    ar & baseItem;
    ar & typeName;
      
    store::Item_t result;
    store::Item_t tmp = baseItem;
    GENV_ITEMFACTORY->createUserTypedAtomicItem(result, tmp, typeName);
        
    obj = result.getp();

    obj->addReference();

    ar.register_reference(id, ARCHIVE_FIELD_PTR, obj);

    return;
  }

  switch (typeCode)
  {
  case store::XS_STRING:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createString);
  }
  case store::XS_NORMALIZED_STRING:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createNormalizedString);
  }
  case store::XS_TOKEN:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createToken);
  }
  case store::XS_LANGUAGE:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createLanguage);
  }
  case store::XS_NMTOKEN:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createNMTOKEN);
  }
  case store::XS_NAME:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createName);
  }
  case store::XS_NCNAME:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createNCName);
  }
  case store::XS_ID:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createID);
  }
  case store::XS_IDREF:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createIDREF);
  }
  case store::XS_ENTITY:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createENTITY);
  }

  case store::XS_UNTYPED_ATOMIC:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createUntypedAtomic);
  }

  case store::XS_DATETIME:
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_dateTime, createDateTime);
  }
  case store::XS_DATE:
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_date, createDate);
  }
  case store::XS_TIME:
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_time, createTime);
  }

  case store::XS_DURATION:
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_duration, createDuration);
  }
  case store::XS_DT_DURATION:
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_dayTimeDuration, createDayTimeDuration);
  }
  case store::XS_YM_DURATION: 
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_yearMonthDuration, createYearMonthDuration);
  }

  case store::XS_FLOAT:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_float, createFloat);
  }
  case store::XS_DOUBLE:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_double, createDouble);
  }

  case store::XS_DECIMAL:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_decimal, createDecimal);
  }
  case store::XS_INTEGER:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_integer, createInteger);
  }
  case store::XS_NON_POSITIVE_INTEGER:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_integer, createNonPositiveInteger);
  }
  case store::XS_NON_NEGATIVE_INTEGER:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_nonNegativeInteger, createNonNegativeInteger);
  }
  case store::XS_NEGATIVE_INTEGER:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_integer, createNegativeInteger);
  }
  case store::XS_POSITIVE_INTEGER:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_positiveInteger, createPositiveInteger);
  }
  case store::XS_LONG:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_long, createLong);
  }
  case store::XS_INT:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_int, createInt);
  }
  case store::XS_SHORT:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_short, createShort);
  }
  case store::XS_BYTE:
  {
    DESERIALIZE_ATOMIC_ITEM(char, createByte);
  }
  case store::XS_UNSIGNED_LONG:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_unsignedLong, createUnsignedLong);
  }
  case store::XS_UNSIGNED_INT:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_unsignedInt, createUnsignedInt);
  }
  case store::XS_UNSIGNED_SHORT:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_unsignedShort, createUnsignedShort);
  }
  case store::XS_UNSIGNED_BYTE:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_unsignedByte, createUnsignedByte);
  }

  case store::XS_GYEAR_MONTH:
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_gYearMonth, createGYearMonth);
  }
  case store::XS_GYEAR:
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_gYear, createGYear);
  }
  case store::XS_GMONTH_DAY:
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_gMonthDay, createGMonthDay);
  }
  case store::XS_GDAY:
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_gDay, createGDay);
  }
  case store::XS_GMONTH:
  {
    DESERIALIZE_ATOMIC_ITEM2(xs_gMonth, createGMonth);
  }

  case store::XS_BOOLEAN:
  {
    DESERIALIZE_ATOMIC_ITEM(bool, createBoolean);
  }

  case store::XS_ANY_URI:
  {
    DESERIALIZE_ATOMIC_ITEM(zstring, createAnyURI);
  }

  case store::XS_QNAME:
  {
    zstring ns;
    zstring prefix;
    zstring local;
    ar & ns;
    ar & prefix;
    ar & local;

    store::Item_t result;
    GENV_ITEMFACTORY->createQName(result, ns, prefix, local);

    obj = result.getp();
    if(obj)               
      obj->addReference();
    
    ar.register_reference(id, ARCHIVE_FIELD_PTR, obj);
                        
    break;
  }

  case store::XS_NOTATION:
  {
    zstring ns;
    zstring prefix;
    zstring local;
    ar & ns;
    ar & prefix;
    ar & local;

    store::Item_t result;
    GENV_ITEMFACTORY->createNOTATION(result, ns, prefix, local);

    obj = result.getp();
    if(obj)               
      obj->addReference();
    
    ar.register_reference(id, ARCHIVE_FIELD_PTR, obj);
                        
    break;
  }

  case store::XS_BASE64BINARY:
  {
    DESERIALIZE_ATOMIC_ITEM(Base64, createBase64Binary);
  }

  case store::XS_HEXBINARY:
  {
    DESERIALIZE_ATOMIC_ITEM(xs_hexBinary, createHexBinary);
  }

 #ifdef ZORBA_WITH_JSON
  case store::JDM_NULL:
  {
    store::Item_t lRes;
    GENV_ITEMFACTORY->createJSONNull(lRes);
    obj = lRes.getp();
    obj->addReference();

    ar.register_reference(id, ARCHIVE_FIELD_PTR, obj);

    break;
  }
#endif

  default:
  {
    throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
    ERROR_PARAMS("unknown atomic item type"));
  }
  }
}


/*******************************************************************************

********************************************************************************/
void serialize_node_tree(Archiver& ar, store::Item*& obj, bool all_tree)
{
  //only for node items
  //serialize first whole tree and then the item (will surely be a reference)
  if (all_tree)
  {
    store::Item* parent = NULL;

    if (ar.is_serializing_out())
    {
      if (obj != NULL)
        parent = obj->getParent();

      if (parent)
      {
        while(parent->getParent())
          parent = parent->getParent();
      }

      if (!parent)
      {
        parent = obj;
      }
    }

    serialize_node_tree(ar, parent, false);
  }

  ar.set_is_temp_field(false);

  int id;
  ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
  int referencing;
  bool is_ref;

  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field(TYPE_NULL, !FIELD_IS_CLASS, NULL, ARCHIVE_FIELD_NULL);

      ar.set_is_temp_field(true);
      return;
    }

    is_ref = 
    ar.add_compound_field(TYPE_LAST, !FIELD_IS_CLASS, obj, ARCHIVE_FIELD_PTR);
  }
  else
  {
    TypeCode type;

    ar.read_next_compound_field(false, field_treat, type, id, referencing);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      obj = NULL;
      ar.read_end_current_level();
      ar.set_is_temp_field(true);
      return;
    }

    ar.check_nonclass_field(field_treat, (enum  ArchiveFieldKind)-1, id);

    if ((field_treat != ARCHIVE_FIELD_PTR) && (field_treat != ARCHIVE_FIELD_REFERENCING))
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0002_INCOMPATIBLE_INPUT_FIELD, ERROR_PARAMS(id));
    }

    is_ref = (field_treat == ARCHIVE_FIELD_REFERENCING);
  }

  ar.set_is_temp_field(true);

  if (!is_ref)
  {
    store::StoreConsts::NodeKind nodekind = store::StoreConsts::anyNode;
    if (ar.is_serializing_out())
      nodekind = obj->getNodeKind();

    SERIALIZE_ENUM(store::StoreConsts::NodeKind, nodekind);

    switch (nodekind)
    {
    case store::StoreConsts::anyNode:
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
      ERROR_PARAMS("anyNode"));
    }
    case store::StoreConsts::documentNode:
    {
      SERIALIZE_FIELD2(zstring, baseUri, getBaseURI);
      SERIALIZE_FIELD2(zstring, docUri, getDocumentURI);
      FINALIZE_SERIALIZE(createDocumentNode, (result, baseUri, docUri));
      serialize_my_children(ar, obj->getChildren());
      break;
    }
    case store::StoreConsts::elementNode:
    {
      SERIALIZE_PARENT;
      //pos = -1
      SERIALIZE_FIELD(store::Item_t, nodename, getNodeName());
      SERIALIZE_FIELD(store::Item_t, name_of_type, getType());
      SERIALIZE_FIELD(bool, isInSubstGroup, isInSubstitutionGroup());
      bool  haveTypedValue = false;
      bool  haveEmptyValue = true;
      if (ar.is_serializing_out())
      {
        //workaround
      //  store::simplestore::ElementNode *elem_node = dynamic_cast<store::simplestore::ElementNode*>(obj);
      //  haveTypedValue = elem_node->haveTypedValue();
      //  haveEmptyValue = elem_node->haveEmptyValue();
        if (!ZSTREQ(name_of_type->getNamespace(), XML_SCHEMA_NS) ||
            !ZSTREQ(name_of_type->getLocalName(), "untyped"))
          haveTypedValue = true;
      }

      ar & haveTypedValue;
      ar & haveEmptyValue;
      store::NsBindings ns_bindings;

      if (ar.is_serializing_out())
        obj->getNamespaceBindings(ns_bindings, store::StoreConsts::ONLY_LOCAL_NAMESPACES);

      ar & ns_bindings;
      SERIALIZE_FIELD2(zstring, baseUri, getBaseURI);
      FINALIZE_SERIALIZE(createElementNode, (result, parent, nodename, name_of_type, haveTypedValue, haveEmptyValue, ns_bindings, baseUri, isInSubstGroup));

      serialize_my_children2(ar, obj->getAttributes());

      serialize_my_children(ar, obj->getChildren());

      break;
    }
    case store::StoreConsts::attributeNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(store::Item_t, nodename, getNodeName());
      SERIALIZE_FIELD(store::Item_t, name_of_type, getType());
      store::Item_t val;
      store::Iterator_t val_it;
      if (ar.is_serializing_out())
        obj->getTypedValue(val, val_it);
      ar & val;
      std::vector<store::Item_t> val_vector;
      if (val == NULL)
      {
        iterator_to_vector(val_it, val_vector);
      }
      ar & val_vector;
      if (val != NULL)
      {
        FINALIZE_SERIALIZE(createAttributeNode, (result, parent, nodename, name_of_type, val));
      }
      else
      {
        FINALIZE_SERIALIZE(createAttributeNode, (result, parent, nodename, name_of_type, val_vector));
      }

      break;
    }
    case store::StoreConsts::textNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(zstring, content, getStringValue());
      FINALIZE_SERIALIZE(createTextNode, (result, parent, content));

      break;
    }
    case store::StoreConsts::piNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(zstring, target, getTarget());
      SERIALIZE_FIELD(zstring, content, getStringValue());
      SERIALIZE_FIELD2(zstring, baseUri, getBaseURI);
      FINALIZE_SERIALIZE(createPiNode, (result, parent, target, content, baseUri));

      break;
    }
    case store::StoreConsts::commentNode:
    {
      SERIALIZE_PARENT;
      SERIALIZE_FIELD(zstring, content, getStringValue());
      FINALIZE_SERIALIZE(createCommentNode, (result, parent, content));

      break;
    }
    default:
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0010_ITEM_TYPE_NOT_SERIALIZABLE,
      ERROR_PARAMS("unknown"));
    }
    }
  }//end is_ref

  if (ar.is_serializing_out())
  {
    if (!is_ref)
      ar.add_end_compound_field();
  }
  else
  {
    if (!is_ref)
    {
      ar.register_item(obj);
      ar.read_end_current_level();
    }
    else
    {
      store::Item* new_obj = NULL;
      if ((new_obj = (store::Item*)ar.get_reference_value(referencing)))
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
void serialize_my_children(Archiver& ar, store::Iterator_t iter)
{
  if (ar.is_serializing_out())
  {
    std::vector<store::Item_t>  childs;
    iterator_to_vector(iter, childs);
    std::vector<store::Item_t>::iterator  child_it;
    csize child_count = childs.size();
    ar & child_count;

    for(child_it = childs.begin(); child_it != childs.end(); ++child_it)
    {
      store::Item*  p = (*child_it).getp();

      ar.dont_allow_delay(SERIALIZE_NOW);
      //ar & p;
      serialize_node_tree(ar, p, false);
    }
  }
  else
  {
    csize child_count;
    ar & child_count;

    for (csize i = 0; i < child_count; ++i)
    {
      store::Item*  p = NULL; 
      //ar & p;//should be automatically added to DocumentNode or ElementNode
      serialize_node_tree(ar, p, false);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void serialize_my_children2(Archiver& ar, store::Iterator_t iter)
{
  serialize_my_children(ar, iter);
}


#ifdef ZORBA_WITH_JSON
/*******************************************************************************

********************************************************************************/
void serialize_json_object(Archiver &ar, store::Item *&obj)
{
  xs_integer lSize = xs_integer(0);
  if (ar.is_serializing_out())
  {
    lSize = obj->getSize();
  }
  ar & lSize;

  if (ar.is_serializing_out())
  {
    store::Iterator_t lIter = obj->getPairs();
    lIter->open();
    store::Item_t lPair;
    while (lIter->next(lPair))
    {
      store::Item* lName = lPair->getName();
      store::Item* lValue = lPair->getValue();
      ar & lName;
      ar & lValue;
    }
    lIter->close();
  }
  else
  {
    csize num = to_xs_unsignedInt(lSize);
    std::vector<store::Item_t> lNames, lValues;
    lNames.reserve(num);
    lValues.reserve(num);

    store::Item* lName, *lValue;
    for (csize i = 0; i < num; ++i)
    {
      ar & lName;
      ar & lValue;
      lNames.push_back(lName);
      lValues.push_back(lValue);
    }
    store::Item_t lRes;
    GENV_ITEMFACTORY->createJSONObject(lRes, lNames, lValues); 
    obj = lRes.getp();
    obj->addReference();
  }
}


/*******************************************************************************

********************************************************************************/
void serialize_json_array(Archiver &ar, store::Item *&obj)
{
  xs_integer lSize = xs_integer(0);
  if (ar.is_serializing_out())
  {
    lSize = obj->getSize();
  }
  ar & lSize;

  if (ar.is_serializing_out())
  {
    store::Iterator_t lIter = obj->getMembers();
    lIter->open();
    store::Item_t lMember;
    while (lIter->next(lMember))
    {
      store::Item* lTmp = lMember.getp();
      ar & lTmp;
    }
    lIter->close();
  }
  else
  {
    csize num = to_xs_unsignedInt(lSize);
    std::vector<store::Item_t> lValues;
    lValues.reserve(num);

    store::Item* lValue;
    for (csize i = 0; i < num; ++i)
    {
      ar & lValue;
      lValues.push_back(lValue);
    }
    store::Item_t lRes;
    GENV_ITEMFACTORY->createJSONArray(lRes, lValues); 
    obj = lRes.getp();
    obj->addReference();
  }
}


/*******************************************************************************

********************************************************************************/
void serialize_json_tree(Archiver &ar, store::Item *&obj)
{
  store::StoreConsts::JSONItemKind lKind = store::StoreConsts::jsonItem;
  if (ar.is_serializing_out())
  {
    lKind = obj->getJSONItemKind();
  }
  SERIALIZE_ENUM(store::StoreConsts::JSONItemKind, lKind);

  switch (lKind)
  {
  case store::StoreConsts::jsonObject:
    serialize_json_object(ar, obj);
    break;
  case store::StoreConsts::jsonArray:
    serialize_json_array(ar, obj);
    break;
  default: assert(false);
  }
}
#endif // ZORBA_WITH_JSON


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, QueryLoc& obj)
{
  ar & obj.theFilename;
  ar & obj.theLineBegin;
  ar & obj.theColumnBegin;
  ar & obj.theLineEnd;
  ar & obj.theColumnEnd;
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, const Diagnostic*& obj)
{
  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field(TYPE_NULL, !FIELD_IS_CLASS, NULL, ARCHIVE_FIELD_NULL);
      return;
    }

    bool is_ref;
    assert(!ar.is_serialize_base_class());
    Diagnostic* diagnostic = const_cast<Diagnostic*>(obj);
    UserError* user_err = dynamic_cast<UserError*>(diagnostic);
    XQueryErrorCode* xquery_err = dynamic_cast<XQueryErrorCode*>(diagnostic);
    ZorbaErrorCode* zorba_err = dynamic_cast<ZorbaErrorCode*>(diagnostic);
#ifdef ZORBA_WITH_JSON
    JSONiqErrorCode* jsoniq_err = dynamic_cast<JSONiqErrorCode*>(diagnostic);
    bool isJsoniqErr = (jsoniq_err != NULL);
#endif

    bool isUserErr = (user_err != NULL);
    bool isXQueryErr = (xquery_err != NULL);
    bool isZorbaErr = (zorba_err != NULL);

    is_ref = 
    ar.add_compound_field(TYPE_LAST, !FIELD_IS_CLASS, obj, ARCHIVE_FIELD_PTR);

    if (!is_ref)
    {
      ar & isUserErr;
      ar & isXQueryErr;
      ar & isZorbaErr;
#ifdef ZORBA_WITH_JSON
      ar & isJsoniqErr;
#endif

      if (user_err)
      {
        ar & user_err->qname_;
      }
      else
      {
        const diagnostic::QName& errqn = obj->qname();
        std::string localname = errqn.localname();
        ar & localname;
      }

      ar.add_end_compound_field();
    }
  }
  else
  {
    TypeCode type;
    int id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int referencing;

    ar.read_next_compound_field(false, field_treat, type, id, referencing);

    ar.check_nonclass_field(field_treat, (ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      assert(!ar.is_serialize_base_class());
      obj = NULL;
      ar.read_end_current_level();
      return;
    }

    if (field_treat == ARCHIVE_FIELD_PTR)
    {
      bool is_user, is_xquery, is_zorba;
      bool is_jsoniq = false;

      ar & is_user;
      ar & is_xquery;
      ar & is_zorba;
#ifdef ZORBA_WITH_JSON
      ar & is_jsoniq;
#endif

      if (is_user)
      {
        UserError* user_error = new UserError(ar);
        ar & user_error->qname_;
        obj = user_error;
      }
      else if (is_xquery || is_zorba || is_jsoniq)
      {
        std::string localname;
        ar & localname;

        obj = internal::SystemDiagnosticBase::find(localname.c_str());

        ZORBA_ASSERT(obj);
      }
      else
      {
        ZORBA_ASSERT(false);//unreachable, maybe a new Error class has been added
      }

      ar.register_reference(id, field_treat, obj);

      ar.read_end_current_level();
    }
    else if ((obj = (Diagnostic*)ar.get_reference_value(referencing)))
    {
    }
    else
    {
      ZORBA_ASSERT(false);
    }
  }

}


/*******************************************************************************
  This is called during the (de)serialization of an error item.
********************************************************************************/
void operator&(Archiver& ar, ZorbaException*& obj)
{
  if (ar.is_serializing_out())
  {
    if (obj == NULL)
    {
      ar.add_compound_field(TYPE_NULL, 
                            !FIELD_IS_CLASS,
                            NULL,
                            ARCHIVE_FIELD_NULL);
      return;
    }

    assert(!ar.is_serialize_base_class());

    UserException* user_ex = dynamic_cast<UserException*>(obj);
    XQueryException* xquery_ex = dynamic_cast<XQueryException*>(obj);

    bool isUserExc = (user_ex != NULL);
    bool isXQueryExc = (xquery_ex != NULL);

    bool is_ref = ar.add_compound_field(TYPE_LAST, 
                                        !FIELD_IS_CLASS,
                                        obj, 
                                        ARCHIVE_FIELD_PTR);
    if (!is_ref)
    {
      ar & isUserExc;
      ar & isXQueryExc;

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
    TypeCode type;
    int id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_PTR;
    int referencing;

    ar.read_next_compound_field(false, field_treat, type, id, referencing);

    ar.check_nonclass_field(field_treat, (ArchiveFieldKind)-1, id);

    if (field_treat == ARCHIVE_FIELD_NULL)
    {
      assert(!ar.is_serialize_base_class());
      obj = NULL;
      ar.read_end_current_level();
      return;
    }

    if (field_treat == ARCHIVE_FIELD_PTR)
    {
      bool is_user, is_xquery;

      ar & is_user;
      ar & is_xquery;

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
    else if ((obj = (ZorbaException*)ar.get_reference_value(referencing)))
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
  if (ar.is_serializing_out())
  {
    bool is_ref =
    ar.add_compound_field(TYPE_LAST, !FIELD_IS_CLASS, &obj, ARCHIVE_FIELD_NORMAL);

    if (!is_ref)
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
    TypeCode type;
    int id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int referencing;

    ar.read_next_compound_field(false, field_treat, type, id, referencing);

    ar.check_nonclass_field(field_treat, ARCHIVE_FIELD_NORMAL, id);

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
void operator&(Archiver& ar, zorba::XQueryStackTrace& obj)
{
  if (ar.is_serializing_out())
  {
    bool is_ref =
    ar.add_compound_field(TYPE_LAST, !FIELD_IS_CLASS, &obj, ARCHIVE_FIELD_NORMAL);

    if (!is_ref)
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
    TypeCode type;
    int id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int referencing;

    ar.read_next_compound_field(false, field_treat, type, id, referencing);

    ar.check_nonclass_field(field_treat, ARCHIVE_FIELD_NORMAL, id);

    ar & obj.trace_;
    ar.read_end_current_level();
  }
}


/*******************************************************************************

********************************************************************************/
void operator&(Archiver& ar, zorba::XQueryStackTrace::Entry& obj)
{
  if (ar.is_serializing_out())
  {
    bool is_ref;
    is_ref = ar.add_compound_field(TYPE_LAST,
                                   !FIELD_IS_CLASS, 
                                   &obj,
                                   ARCHIVE_FIELD_NORMAL);
    if (!is_ref)
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
    TypeCode type;
    int id;
    ArchiveFieldKind field_treat = ARCHIVE_FIELD_NORMAL;
    int referencing;

    ar.read_next_compound_field(false, field_treat, type, id, referencing);

    ar.check_nonclass_field(field_treat, ARCHIVE_FIELD_NORMAL, id);

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
