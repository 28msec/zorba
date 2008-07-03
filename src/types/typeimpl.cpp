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
#include <iostream>
#include "system/globalenv.h"
#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/root_typemanager.h"
#include "zorbaerrors/Assert.h"


namespace zorba {

const char *XQType::KIND_STRINGS[XQType::NONE_KIND + 1] =
{
  "ATOMIC_TYPE_KIND",
  "NODE_TYPE_KIND",
  "ANY_TYPE_KIND",
  "ITEM_KIND",
  "ANY_SIMPLE_TYPE_KIND",
  "UNTYPED_KIND",
  "EMPTY_KIND",
  "NONE_KIND"
};

const char *AtomicXQType::ATOMIC_TYPE_CODE_STRINGS[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE] =
{
  "XS_ANY_ATOMIC",
  "XS_STRING",
  "XS_NORMALIZED_STRING",
  "XS_TOKEN",
  "XS_LANGUAGE",
  "XS_NMTOKEN",
  "XS_NAME",
  "XS_NCNAME",
  "XS_ID",
  "XS_IDREF",
  "XS_ENTITY",
  "XS_UNTYPED_ATOMIC",
  "XS_DATETIME",
  "XS_DATE",
  "XS_TIME",
  "XS_DURATION",
  "XS_DT_DURATION",
  "XS_YM_DURATION",
  "XS_FLOAT",
  "XS_DOUBLE",
  "XS_DECIMAL",
  "XS_INTEGER",
  "XS_NON_POSITIVE_INTEGER",
  "XS_NEGATIVE_INTEGER",
  "XS_LONG",
  "XS_INT",
  "XS_SHORT",
  "XS_BYTE",
  "XS_NON_NEGATIVE_INTEGER",
  "XS_UNSIGNED_LONG",
  "XS_UNSIGNED_INT",
  "XS_UNSIGNED_SHORT",
  "XS_UNSIGNED_BYTE",
  "XS_POSITIVE_INTEGER",
  "XS_GYEAR_MONTH",
  "XS_GYEAR",
  "XS_GMONTH_DAY",
  "XS_GDAY",
  "XS_GMONTH",
  "XS_BOOLEAN",
  "XS_BASE64BINARY",
  "XS_HEXBINARY",
  "XS_ANY_URI",
  "XS_QNAME",
  "XS_NOTATION"
};

std::ostream& XQType::serialize(std::ostream& os) const
{
  return os << "[XQType " << KIND_STRINGS[type_kind()] << TypeOps::decode_quantifier (get_quantifier()) << "]";
}


std::string XQType::toString() const
{
  std::ostringstream os;
  serialize(os);
  return os.str();
}

std::ostream& AtomicXQType::serialize(std::ostream& os) const
{
  return os << "[AtomicXQType " << ATOMIC_TYPE_CODE_STRINGS[get_type_code()] << TypeOps::decode_quantifier (get_quantifier()) << "]";
}

NodeXQType::NodeXQType(
    const TypeManager *manager,
    rchandle<NodeTest> nodetest,
    xqtref_t content_type,
    TypeConstants::quantifier_t quantifier)
  :
  XQType(manager, NODE_TYPE_KIND, quantifier), m_nodetest(nodetest), m_content_type(content_type)
{
}

std::ostream& NodeXQType::serialize(std::ostream& os) const
{
  rchandle<NodeTest> node_test = get_nodetest ();
  store::StoreConsts::NodeKind node_kind = node_test->get_kind ();
  xqtref_t content_type = get_content_type ();
  rchandle<NodeNameTest> nametest = node_test->get_nametest();
  os << "[NodeXQType " << store::StoreConsts::toString (node_kind)
     << TypeOps::decode_quantifier (get_quantifier()) << " ";
  if (nametest != NULL) {
    os << "nametest=[uri: " << nametest->get_uri () << ", local: " << nametest->get_local () << "]";
  }
  if (content_type != NULL)
  {
    os << "content=";
    os << content_type->toString ();
  }
  return os << "]";
}
    
UserDefinedXQType::UserDefinedXQType(const TypeManager *manager, store::Item_t qname, xqtref_t baseType, TypeConstants::quantifier_t quantifier) :
    XQType(manager, USER_DEFINED_KIND, quantifier), _qname(qname), _baseType(baseType)
{
    ZORBA_ASSERT(baseType!=NULL);

    switch (baseType.getp()->type_kind())
    {
    case USER_DEFINED_KIND:
        {
            const UserDefinedXQType& udBaseType = static_cast<const UserDefinedXQType&>(*baseType);
            _isAtomic = udBaseType.isAtomic();
        }
        break;
    case ATOMIC_TYPE_KIND:
        _isAtomic = true;
        break;
    default:
        _isAtomic = false;            
    }        
}

bool UserDefinedXQType::isSuperTypeOf(const XQType& subType) const
{
    if (this==&subType)
    {
        return true;
    }
    
    xqtref_t baseType = getBaseType();
    const XQType* baseType_ptr = baseType.getp();

    do
    {
        if (baseType_ptr == &subType)
            return true;
        
        switch(baseType_ptr->type_kind())
        {
        case XQType::ATOMIC_TYPE_KIND:
            return false;
            break;
            
        case XQType::USER_DEFINED_KIND:
            {
                const UserDefinedXQType* udBaseType_ptr = static_cast<const UserDefinedXQType*>(baseType_ptr);
                baseType_ptr = udBaseType_ptr->getBaseType().getp();
            }
            break;
        
        default:
            return false;
        }
    }
    while(true);
    
    return false;
}

std::ostream& UserDefinedXQType::serialize(std::ostream& os) const
{
    return os << "[UserDefinedXQType " << " " << TypeOps::decode_quantifier (get_quantifier()) 
        << _qname->getLocalName()->str() << "@" << _qname->getNamespace()->str() << " " << 
        ( _isAtomic ? "isAtomic" : "" ) << " base:" << TypeOps::toString(*_baseType) << " ]";
}    
}  // namespace zorba
