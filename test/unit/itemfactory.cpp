#include <cassert>
#include <iostream>

#include <zorba/zorba.h>

using namespace zorba;

bool
checkType(const Item& aItem, const String& aLocalname)
{
  try {
    return (aItem.getPrefix() == "xs" && 
            aItem.getLocalName() == aLocalname && 
            aItem.getNamespace() == "http://www.w3.org/2001/XMLSchema");
  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return false;
  }
}

#define CHECK_NOT_IMPLEMENTED(object, member) \
  try { \
    object.member;\
    assert(false); \
  } catch (SystemException &e) { \
    assert (e.getErrorCode() == ZorbaError::XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE); \
  }



int itemfactory(int argc, char* argv[]) 
{
  Zorba* lZorba = Zorba::getInstance();

  ItemFactory* lFactory = lZorba->getItemFactory();

  Item lItem;
  try {
    /** String */
    lItem = lFactory->createString("abc");
    assert ( checkType(lItem.getType(), "string") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "abc" );
    CHECK_NOT_IMPLEMENTED(lItem, isNaN() );

    /** AnyURI */
    lItem = lFactory->createAnyURI("http://www.flworfound.org/");
    assert ( checkType(lItem.getType(), "anyURI") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "http://www.flworfound.org/");

    /** QName */
    lItem = lFactory->createQName("http://www.flworfound.org", "flwor", "name");
    assert ( checkType(lItem.getType(), "QName") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "flwor:name" );
    assert ( lItem.getNamespace() == "http://www.flworfound.org" );

    lItem = lFactory->createQName("http://www.flworfound.org", "name");
    assert ( checkType(lItem.getType(), "QName") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "name" );
    assert ( lItem.getPrefix().length() == 0 );
    assert ( lItem.getPrefix().empty() );
    assert ( lItem.getNamespace() == "http://www.flworfound.org" );

    /** NCName */
    lItem = lFactory->createNCName("ncname");
    assert ( checkType(lItem.getType(), "NCName") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "ncname" );
    CHECK_NOT_IMPLEMENTED (lItem, getPrefix());
    CHECK_NOT_IMPLEMENTED (lItem, getLocalName());
    CHECK_NOT_IMPLEMENTED (lItem, getNamespace());
    CHECK_NOT_IMPLEMENTED (lItem, getBooleanValue() );

    /** Base64Binary */
    lItem = lFactory->createBase64Binary("", 0);
    assert ( checkType(lItem.getType(), "base64Binary") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "" );
    assert ( lItem.getStringValue().length() == 0 );

    lItem = lFactory->createBase64Binary("cmxjZ3R4c3JidnllcmVuZG91aWpsbXV5Z2NhamxpcmJkaWFhbmFob2VsYXVwZmJ1Z2dmanl2eHlzYmhheXFtZXR0anV2dG1q", 96);
    assert ( checkType(lItem.getType(), "base64Binary") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "cmxjZ3R4c3JidnllcmVuZG91aWpsbXV5Z2NhamxpcmJkaWFhbmFob2VsYXVwZmJ1Z2dmanl2eHlzYmhheXFtZXR0anV2dG1q" );
    assert ( lItem.getStringValue().length() == 96 );
    CHECK_NOT_IMPLEMENTED (lItem, getBooleanValue() );

    /** Boolean */
    lItem = lFactory->createBoolean(true);
    assert ( checkType(lItem.getType(), "boolean") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "true" );
    assert ( lItem.getEBV().getStringValue() == "true" ); 
    assert ( lItem.getBooleanValue() );

    lItem = lFactory->createBoolean(false);
    assert ( checkType(lItem.getType(), "boolean") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "false" );
    assert ( lItem.getEBV().getStringValue() == "false" ); 
    assert ( ! lItem.getBooleanValue() );

    /** Decimal */
    lItem = lFactory->createDecimalFromLong(12678967);
    assert ( checkType(lItem.getType(), "decimal") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "12678967" );
    assert ( lItem.getEBV().getBooleanValue() );

    lItem = lFactory->createDecimalFromDouble(12678967.32342);
    assert ( checkType(lItem.getType(), "decimal") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "12678967.32342" );
    assert ( lItem.getEBV().getBooleanValue() );

    lItem = lFactory->createDecimal("NaN");
    assert ( lItem.isNull() );

    /** Integer */
    lItem = lFactory->createInteger(23424223);
    assert ( checkType(lItem.getType(), "integer") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "23424223" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.isNaN() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    lItem = lFactory->createInteger("NaN");
    assert ( lItem.isNull() );

    /** Int */
    lItem = lFactory->createInt(23424223);
    assert ( checkType(lItem.getType(), "int") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "23424223" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.isNaN() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** Short */
    lItem = lFactory->createShort(233);
    assert ( checkType(lItem.getType(), "short") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "233" );
    assert ( lItem.getEBV().getBooleanValue() );
    assert ( !lItem.isNaN() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );
    
    /** Char */
    lItem = lFactory->createByte('a');
    assert ( checkType(lItem.getType(), "byte") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "97" );
    assert ( lItem.getEBV().getBooleanValue() );
    CHECK_NOT_IMPLEMENTED(lItem, isPosOrNegInf());
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /** Double */
    lItem = lFactory->createDouble(213123);
    assert ( checkType(lItem.getType(), "double") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "213123" );
    assert ( lItem.getEBV().getBooleanValue() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    double x = 0;
    lItem = lFactory->createDouble(static_cast<double>(x)/static_cast<double>(x));
    assert ( checkType(lItem.getType(), "double") );
    assert ( lItem.isNaN() );

    lItem = lFactory->createDouble(std::numeric_limits<double>::infinity());
    assert ( checkType(lItem.getType(), "double") );
    assert ( lItem.isPosOrNegInf() );

    lItem = lFactory->createDouble("213123");
    assert ( lItem.getStringValue() == "213123" );

    lItem = lFactory->createDouble("INF");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );

    lItem = lFactory->createDouble("-INF");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );

    lItem = lFactory->createDouble("-inf");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );

    lItem = lFactory->createDouble("inf");
    assert ( lItem.isPosOrNegInf() );
    assert ( !lItem.isNaN() );

    lItem = lFactory->createDouble("NAN");
    assert ( !lItem.isPosOrNegInf() );
    assert ( lItem.isNaN() );

    lItem = lFactory->createDouble("nAn");
    assert ( !lItem.isPosOrNegInf() );
    assert ( lItem.isNaN() );

    /* Unsigned Short */
    lItem = lFactory->createUnsignedShort(10);
    assert ( checkType(lItem.getType(), "unsignedShort") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "10" );
    assert ( lItem.getEBV().getBooleanValue() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );

    /* Unsigned Long */
    lItem = lFactory->createUnsignedLong(10);
    assert ( checkType(lItem.getType(), "unsignedLong") );
    assert ( lItem.isAtomic() );
    assert ( lItem.getStringValue() == "10" );
    assert ( lItem.getEBV().getBooleanValue() );
    CHECK_NOT_IMPLEMENTED(lItem, getBooleanValue() );


  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return 1;
  }

  return 0;
}
