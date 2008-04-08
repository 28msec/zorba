#include <iostream>
#include "system/globalenv.h"
#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/root_typemanager.h"

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
  XQType(manager, quantifier), m_nodetest(nodetest), m_content_type(content_type)
{
}

std::ostream& NodeXQType::serialize(std::ostream& os) const
{
  rchandle<NodeTest> node_test = get_nodetest ();
  store::StoreConsts::NodeKind node_kind = node_test->get_kind ();
  xqtref_t content_type = get_content_type ();
  return
    os << "[NodeXQType "
       << store::StoreConsts::toString (node_kind) << " "
       << (content_type == NULL ? "" : xqp_string ("content=") + content_type->toString ())
       << TypeOps::decode_quantifier (get_quantifier()) << "]";
}
    
UserDefinedXQType::UserDefinedXQType(const TypeManager *manager, store::Item_t& qname, xqtref_t baseType, TypeConstants::quantifier_t quantifier) :
    XQType(manager, quantifier), _qname(qname), _baseType(baseType)
{
    assert(baseType!=NULL);

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

bool UserDefinedXQType::isSubTypeOf(const XQType& superType) const
{
    if (this==&superType)
    {
        return true;
    }
    
    //const XQType* baseType_ptr = &getBaseType();
    const XQType* baseType_ptr = getBaseType().getp();
    do
    {
        if (baseType_ptr == &superType)
            return true;
        
        switch(baseType_ptr->type_kind())
        {
        case XQType::ATOMIC_TYPE_KIND:
            return false;
            break;
            
        case XQType::USER_DEFINED_KIND:
            {
                UserDefinedXQType* udBaseType_ptr = (UserDefinedXQType*)baseType_ptr;//static_cast<UD&>(baseType);
                //baseType_ptr = &(udBaseType_ptr->getBaseType());
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
}
