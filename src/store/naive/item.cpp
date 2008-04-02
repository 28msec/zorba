
#include "errors/error_manager.h"
#include "util/Assert.h"
#include "zorbatypes/datetime.h"

#include "store/api/item.h"
#include "store/api/iterator.h"

#include "system/globalenv.h"

#include "api/serialization/serializer.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"

namespace zorba { namespace store {


Item_t
Item::getType( ) const
{
  ZORBA_ASSERT(false);
  return 0;
}


bool Item::equals(Item_t, RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  ZORBA_ASSERT(false);
  return false;
}


Item_t Item::getEBV() const
{
  ZORBA_ASSERT(false);
  return 0;
}


Item_t Item::getAtomizationValue() const
{
  ZORBA_ASSERT(false);
  return 0;
}


xqpStringStore_t Item::getStringValue() const
{
  ZORBA_ASSERT(false);
  return 0;
}


/**
 * Helper method with is used to return a StringValue of an Item
 * by pointer instead of rchandle
 */
xqpStringStore* Item::getStringValueP() 
{
  ZORBA_ASSERT(false);
  return 0;
}


/**
 * Get a hash value computed from the value of this item.
 *
 * @return The hash value
 */
uint32_t Item::hash(RuntimeCB* aRuntimeCB, XQPCollator* coll) const
{
  ZORBA_ASSERT(false);
  return 0;
};


/* -------------------  Methods for AtomicValues ------------------------------ */
/**
 *  getXValue functions:
 *  @return  value of type X
 *
 *  Assuming that the item is an AtomicValue of a particular kind X, return the value
 *  of the item. Implementations of X, e.g., a specific DoubleValue implementation, will override
 *  its specific getXValue method (i.e., getDoubleValue) and not change any of the other methods.
 *  Implementations of the seven kinds of nodes should not override the definition of these
 *  methods.
 */
  
/** Accessor for xs:base64Binary
 */
xqp_base64Binary Item::getBase64BinaryValue() const
{
  ZORBA_ASSERT(false);
  return xqp_base64Binary("");
}

/** Accessor for xs:boolean
 */
bool Item::getBooleanValue() const
{
  ZORBA_ASSERT(false);
  return false;
}

/** Accessor for xs:decimal, xs:(nonPositive | negative | nonNegativeInteger | positive)integer,
 * xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
 */
xqp_decimal Item::getDecimalValue() const
{
  ZORBA_ASSERT(false);
  return Decimal::parseInt(0);
}

/** Accessor for xs:int
 */
xqp_int Item::getIntValue() const
{
  ZORBA_ASSERT(false);
  return 0;
}

/** Accessor for xs:(nonPositive | negative | nonNegativeInteger | positive)integer,
 * xs:(unsigned)long, xs:(unsigned)int, xs:(unsigned)short, xs:(unsigned)byte
 */
xqp_integer Item::getIntegerValue() const
{
  ZORBA_ASSERT(false);
  return Integer::parseInt((int32_t)0);
}

/** Accessor for xs:long
 */
xqp_long Item::getLongValue() const
{
  ZORBA_ASSERT(false);
  return 0;
}

/** Accessor for xs:short
 */
xqp_short Item::getShortValue() const
{
  ZORBA_ASSERT(false);
  return 0;
}

/** Accessor for xs:nonNegativeInteager, xs:positiveInteger
 */
xqp_uinteger Item::getUnsignedIntegerValue() const
{
  ZORBA_ASSERT(false);
  return Integer::parseInt(0);
}

/** Accessor for xs:unsignedChar, xs:unsignedByte
 */
xqp_ubyte Item::getUnsignedByteValue() const
{
  ZORBA_ASSERT(false);
  return 0;
}

xqp_byte Item::getByteValue() const
{
  ZORBA_ASSERT(false);
  return 0;
}

/** Accessor for xs:date
 */
xqp_date Item::getDateValue() const
{
  ZORBA_ASSERT(false);
  return xqp_date();
}

/** Accessor for xs:dateTime
 */
xqp_dateTime Item::getDateTimeValue() const
{
  ZORBA_ASSERT(false);
  return xqp_dateTime();
}

/** Accessor for xs:double
 */
xqp_double Item::getDoubleValue() const
{
  ZORBA_ASSERT(false);
  return xqp_double::parseInt(0);
}

/** Accessor for xs:duration
 */
xqp_duration Item::getDurationValue() const
{
  ZORBA_ASSERT(false);
  return xqp_duration();
}

/* Accessor for xs:dayTimeDuration
  */
xqp_dayTimeDuration Item::getDayTimeDurationValue() const
{
  ZORBA_ASSERT(false);
  return xqp_dayTimeDuration();
}

/*Accessor for xs:yearMonthDuration
  */
YearMonthDuration_t Item::getYearMonthDurationValue() const
{
  ZORBA_ASSERT(false);
  return xqp_yearMonthDuration();
}

/** Accessor for xs:ENTITIES, xs:IDREFS, xs:NMTOKENS
 */
std::vector<xqp_string> Item::getStringVectorValue() const
{
  ZORBA_ASSERT(false);
  return std::vector<xqp_string>();
}

/** Accessor for xs:float
 */
xqp_float Item::getFloatValue() const
{
  ZORBA_ASSERT(false);
  return xqp_float::parseInt(0);
}

/** Accessor for xs:gDay
 */
xqp_gDay Item::getGDayValue() const
{
  ZORBA_ASSERT(false);
  return xqp_gDay();
}

/** Accessor for xs:gMonth
 */
xqp_gMonth Item::getGMonthValue() const
{
  ZORBA_ASSERT(false);
  return xqp_gMonth();
}

/** Accessor for xs:gMonthDay
 */
xqp_gMonthDay Item::getGMonthDayValue() const
{
  ZORBA_ASSERT(false);
  return xqp_gMonthDay();
}

/** Accessor for xs:gYear
 */
xqp_gYear Item::getGYearValue() const
{
  ZORBA_ASSERT(false);
  return xqp_gYear();
}

/** Accessor for xs:gYearMonth
 */
xqp_gYearMonth Item::getGYearMonthValue() const
{
  ZORBA_ASSERT(false);
  return xqp_gYearMonth();
}

/** Accessor for xs:hexBinary
 */
xqp_hexBinary Item::getHexBinaryValue() const
{
  ZORBA_ASSERT(false);
  return xqp_hexBinary("");
}

/** Accessor for xs:nonNegativeIntegerValue, xs:positiveInteger, xs:unsignedInt
 */
xqp_uint Item::getUnsignedIntValue() const
{
  ZORBA_ASSERT(false);
  return 0;
}

/** Accessor for xs:time
 */
xqp_time Item::getTimeValue() const
{
  ZORBA_ASSERT(false);
  return xqp_time();
}

/** Accessor for xs:unsignedLong
 */
xqp_ulong Item::getUnsignedLongValue() const
{
  ZORBA_ASSERT(false);
  return 0;
}

/** Accessor for xs:unsignedShort
 */
xqp_ushort Item::getUnsignedShortValue() const
{
  ZORBA_ASSERT(false);
  return 0;
}

/**
 * Helper method for numeric atomic items
 * @return true, if containing number is not-a-number (possible for floating-point numbers)
 */
bool Item::isNaN() const
{
  ZORBA_ASSERT(false);
  return false;
}

/**
 * Helper method for numeric atomic items
 * @return true, if containing numbers represents -INF or +INF
 */
bool Item::isPosOrNegInf() const
{
  ZORBA_ASSERT(false);
  return false;
}

/* -------------------  Methods for Nodes ------------------------------------- */

/**
 *  getNodeProperty functions - Accessor of XDM (see XDM specification, Section 5)
 *  @return  value of node property
 *
 *  Assuming that the item is a node, return the properties of that particular node.
 *  Since all these properties are defined on all seven kinds of nodes (documents, elements,
 *  attributes, etc.), the implementations of all seven kinds of nodes must override these
 *  methods. Implementations of atomic values should keep the default (error) implementation
 *  of these methods.
 */

/** Accessor for element node
 *  @return  attribute*
 */
Iterator_t Item::getAttributes() const
{
  ZORBA_ASSERT(false);
  return NULL;
}

/** Accessor for document node, element node, attribute node,
 * processing instruction node, comment node, text node
 *  @return  uri?
 */
xqp_string Item::getBaseURI() const
{
  ZORBA_ASSERT(false);
  return "";
}

/** Accessor for document node, element node
 *  @return  node*
 */
Iterator_t Item::getChildren() const
{
  ZORBA_ASSERT(false);
  return NULL;
}

/** Accessor for document node
 *  @return  uri?
 */
xqp_string Item::getDocumentURI() const
{
  ZORBA_ASSERT(false);
  return "";
}

/** Accessor for attribute node
 * @return isId: Used for attribute items (defines the attribute an id?)
 */
bool Item::isId() const
{
  ZORBA_ASSERT(false);
  return false;
}

/** Accessor for attribute node
 * @return isIdRefs Used for attribute (defines the attribute an idref?))
 */
bool Item::isIdRefs() const
{
  ZORBA_ASSERT(false);
  return false;
}

/** Accessor for element node
 *  @return  returns prefix namespace pairs
 */
void Item::getNamespaceBindings(
    NsBindings& bindings,
    StoreConsts::NsScoping ns_scoping) const
{
  ZORBA_ASSERT(false);
}


/** Accessor for element node
 *  @return  boolean?
 */
bool Item::getNilled() const
{
  ZORBA_ASSERT(false);
  return false;
}

/** Accessor for document node, element node, attribute node, namespace node,
 *  processing instruction node, comment node, text node
 *  @return  TypeCode of the current node
 */
NodeKind Item::getNodeKind() const
{
  ZORBA_ASSERT(false);
  return StoreConsts::elementNode;
}

/** Accessor for element node, attribute node
 *  @return qname?
 */
store::Item_t Item::getNodeName() const
{
  ZORBA_ASSERT(false);
  return NULL;
}

/** Accessor for element node, attribute node, namespace node, processing instruction node,
 * comment node, text node
 * @return node?
 */
store::Item* Item::getParent() const
{
  ZORBA_ASSERT(false);
  return NULL;
}

/** Accessor for document node, element node, attribute node, namespace node,
 * processing instruction node, comment node, text node
 *
 * @return typedValue?
 */
Iterator_t Item::getTypedValue() const
{
  ZORBA_ASSERT(false);
  return NULL;
}

/** Accessor for xs:qname, namespace node
 * @return namespace uri
 */
xqp_string Item::getNamespace() const
{
  ZORBA_ASSERT(false);
  return "";
}

/** Accessor for xs:qname, namespace node
 * @return namespace prefix
 */
xqp_string Item::getPrefix() const
{
  ZORBA_ASSERT(false);
  return "";
}

/** Accessor for xs:qname
 * @return namespace local name
 */
xqp_string Item::getLocalName() const
{
  ZORBA_ASSERT(false);
  return "";
}

/** Accessor for document node
 * @return unparsed entity public id
 */
xqp_string Item::getUnparsedEntityPublicId() const
{
  ZORBA_ASSERT(false);
  return "";
}

/** Accessor for document node
 * @return unparsed entity system id
 */
xqp_string Item::getUnparsedEntitySystemId() const
{
  ZORBA_ASSERT(false);
  return "";
}

/**
 *  Accessor for processing instruction node
 * @return target of the PI
 */
xqp_string Item::getTarget() const
{
  ZORBA_ASSERT(false);
  return "";
}

bool Item::isNumeric() const 
{
  xqtref_t type = GENV_TYPESYSTEM.create_type(getType(), TypeConstants::QUANT_ONE);
  return TypeOps::is_numeric(*type);
}


xqp_string Item::show() const
{
  return  std::string ( typeid ( *this ).name() ) + ": 'show' not implemented!";
}


void Item::serializeXML(serializer& ser, std::ostream& os) const
{
  ser.serialize(this, os);
}


void Item::applyUpdates()
{
  ZORBA_ASSERT(false);
}


void Item::serializeUpdates(serializer& ser, std::ostream& os)
{
  ZORBA_ASSERT(false);
}


} // namespace store
} // namespace zorba
