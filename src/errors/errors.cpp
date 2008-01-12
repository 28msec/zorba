
#include "errors/errors.h"
#include "store/api/item.h"

namespace xqp
{

static const char *canonical_err_names[ZorbaError::MAX_ZORBA_ERROR_CODE + 1];

static struct canonical_err_names_initializer 
{
  canonical_err_names_initializer () 
  {
#define DEF_ERR_CODE( code, name ) canonical_err_names [ ZorbaError::code ] = #name
      DEF_ERR_CODE (XPST0001, XPST0001);
      DEF_ERR_CODE (XPDY0002, XPDY0002);
      DEF_ERR_CODE (XPST0003, XPST0003);
      DEF_ERR_CODE (XPTY0004, XPTY0004);
      DEF_ERR_CODE (XPST0005, XPST0005);
      DEF_ERR_CODE (FORG0006, FORG0006);
      DEF_ERR_CODE (XPST0008, XPST0008);
      DEF_ERR_CODE (XQST0009, XQST0009);
      DEF_ERR_CODE (XPST0010, XPST0010);
      DEF_ERR_CODE (XQST0012, XQST0012);
      DEF_ERR_CODE (XQST0013, XQST0013);
      DEF_ERR_CODE (XQST0016, XQST0016);
      DEF_ERR_CODE (XPST0017, XPST0017);
      DEF_ERR_CODE (XPTY0018, XPTY0018);
      DEF_ERR_CODE (XPTY0019, XPTY0019);
      DEF_ERR_CODE (XPTY0020, XPTY0020);
      DEF_ERR_CODE (XQST0022, XQST0022);
      DEF_ERR_CODE (XQTY0024, XQTY0024);
      DEF_ERR_CODE (XQDY0025, XQDY0025);
      DEF_ERR_CODE (XQDY0026, XQDY0026);
      DEF_ERR_CODE (XQDY0027, XQDY0027);
      DEF_ERR_CODE (XQTY0030, XQTY0030);
      DEF_ERR_CODE (XQST0031, XQST0031);
      DEF_ERR_CODE (XQST0032, XQST0032);
      DEF_ERR_CODE (XQST0033, XQST0033);
      DEF_ERR_CODE (XQST0034, XQST0034);
      DEF_ERR_CODE (XQST0035, XQST0035);
      DEF_ERR_CODE (XQST0036, XQST0036);
      DEF_ERR_CODE (XQST0038, XQST0038);
      DEF_ERR_CODE (XQST0039, XQST0039);
      DEF_ERR_CODE (XQST0040, XQST0040);
      DEF_ERR_CODE (XQDY0041, XQDY0041);
      DEF_ERR_CODE (XQDY0044, XQDY0044);
      DEF_ERR_CODE (XQST0045, XQST0045);
      DEF_ERR_CODE (XQST0046, XQST0046);
      DEF_ERR_CODE (XQST0047, XQST0047);
      DEF_ERR_CODE (XQST0048, XQST0048);
      DEF_ERR_CODE (XQST0049, XQST0049);
      DEF_ERR_CODE (XPDY0050, XPDY0050);
      DEF_ERR_CODE (XPST0051, XPST0051);
      DEF_ERR_CODE (XQST0054, XQST0054);
      DEF_ERR_CODE (XQST0055, XQST0055);
      DEF_ERR_CODE (XQST0057, XQST0057);
      DEF_ERR_CODE (XQST0058, XQST0058);
      DEF_ERR_CODE (XQST0059, XQST0059);
      DEF_ERR_CODE (XQST0060, XQST0060);
      DEF_ERR_CODE (XQDY0061, XQDY0061);
      DEF_ERR_CODE (XQDY0064, XQDY0064);
      DEF_ERR_CODE (XQST0065, XQST0065);
      DEF_ERR_CODE (XQST0066, XQST0066);
      DEF_ERR_CODE (XQST0067, XQST0067);
      DEF_ERR_CODE (XQST0068, XQST0068);
      DEF_ERR_CODE (XQST0069, XQST0069);
      DEF_ERR_CODE (XQST0070, XQST0070);
      DEF_ERR_CODE (XQST0071, XQST0071);
      DEF_ERR_CODE (XQDY0072, XQDY0072);
      DEF_ERR_CODE (XQST0073, XQST0073);
      DEF_ERR_CODE (XQDY0074, XQDY0074);
      DEF_ERR_CODE (XQST0075, XQST0075);
      DEF_ERR_CODE (XQST0076, XQST0076);
      DEF_ERR_CODE (XQST0079, XQST0079);
      DEF_ERR_CODE (XPST0080, XPST0080);
      DEF_ERR_CODE (XPST0081, XPST0081);
      DEF_ERR_CODE (XQDY0084, XQDY0084);
      DEF_ERR_CODE (XQST0085, XQST0085);
      DEF_ERR_CODE (XQTY0086, XQTY0086);
      DEF_ERR_CODE (XQST0087, XQST0087);
      DEF_ERR_CODE (XQST0088, XQST0088);
      DEF_ERR_CODE (XQST0089, XQST0089);
      DEF_ERR_CODE (XQST0090, XQST0090);
      DEF_ERR_CODE (FOER0000, FOER0000);
      DEF_ERR_CODE (FOAR0001, FOAR0001);
      DEF_ERR_CODE (FOAR0002, FOAR0002);
      DEF_ERR_CODE (FOCA0001, FOCA0001);
      DEF_ERR_CODE (FOCA0002, FOCA0002);
      DEF_ERR_CODE (FOCA0003, FOCA0003);
      DEF_ERR_CODE (FOCA0005, FOCA0005);
      DEF_ERR_CODE (FOCA0006, FOCA0006);
      DEF_ERR_CODE (FOCH0001, FOCH0001);
      DEF_ERR_CODE (FOCH0002, FOCH0002);
      DEF_ERR_CODE (FOCH0003, FOCH0003);
      DEF_ERR_CODE (FOCH0004, FOCH0004);
      DEF_ERR_CODE (FODC0001, FODC0001);
      DEF_ERR_CODE (FODC0002, FODC0002);
      DEF_ERR_CODE (FODC0003, FODC0003);
      DEF_ERR_CODE (FODC0004, FODC0004);
      DEF_ERR_CODE (FODC0005, FODC0005);
      DEF_ERR_CODE (FODT0001, FODT0001);
      DEF_ERR_CODE (FODT0002, FODT0002);
      DEF_ERR_CODE (FODT0003, FODT0003);
      DEF_ERR_CODE (FONS0004, FONS0004);
      DEF_ERR_CODE (FONS0005, FONS0005);
      DEF_ERR_CODE (FORG0001, FORG0001);
      DEF_ERR_CODE (FORG0002, FORG0002);
      DEF_ERR_CODE (FORG0003, FORG0003);
      DEF_ERR_CODE (FORG0004, FORG0004);
      DEF_ERR_CODE (FORG0005, FORG0005);
      DEF_ERR_CODE (FORG0006, FORG0006);
      DEF_ERR_CODE (FORG0008, FORG0008);
      DEF_ERR_CODE (FORG0009, FORG0009);
      DEF_ERR_CODE (FORX0001, FORX0001);
      DEF_ERR_CODE (FORX0002, FORX0002);
      DEF_ERR_CODE (FORX0003, FORX0003);
      DEF_ERR_CODE (FORX0004, FORX0004);
      DEF_ERR_CODE (FOTY0012, FOTY0012);
      DEF_ERR_CODE (SENR0001_Item_is_attribute_or_namespace_node, SENR0001);
      DEF_ERR_CODE (SEPM0016_Invalid_parameter_value, SEPM0016);
      DEF_ERR_CODE (XQP0000_DYNAMIC_RUNTIME_ERROR, XQP0000);
      DEF_ERR_CODE (XQP0001_DYNAMIC_ITERATOR_OVERRUN, XQP0001);
      DEF_ERR_CODE (XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD, XQP0002);
      DEF_ERR_CODE (XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND, XQP0003);
      DEF_ERR_CODE (XQP0004_SYSTEM_NOT_SUPPORTED, XQP0004);
      DEF_ERR_CODE (XQP0005_SYSTEM_ASSERT_FAILED, XQP0005);
      DEF_ERR_CODE (XQP0006_SYSTEM_HASH_ERROR_KEYLEN_EXCEEDS_MAXKEYLEN, XQP0006);
      DEF_ERR_CODE (XQP0007_SYSTEM_VECTOR_OUT_OF_RANGE, XQP0007);
      DEF_ERR_CODE (XQP0008_SYSTEM_READ_LOCK_FAILED, XQP0008);
      DEF_ERR_CODE (XQP0009_SYSTEM_WRITE_LOCK_FAILED, XQP0009);
      DEF_ERR_CODE (XQP0010_SYSTEM_POP_FROM_EMPTY_LIST, XQP0010);
      DEF_ERR_CODE (XQP0011_SYSTEM_FILE_ERROR_IN_FUNCTION, XQP0011);
      DEF_ERR_CODE (XQP0012_SYSTEM_FXCHARHEAP_IOEXCEPTION, XQP0012);
      DEF_ERR_CODE (XQP0013_SYSTEM_MMFILE_IOEXCEPTION, XQP0013);
      DEF_ERR_CODE (XQP0015_SYSTEM_NOT_YET_IMPLEMENTED, XQP0015);
      DEF_ERR_CODE (XQP0016_LOADER_IO_ERROR, XQP0016);
      DEF_ERR_CODE (XQP0017_LOADER_NOT_WELL_FORMED_XML, XQP0017);
      DEF_ERR_CODE (XQP0018_NODEID_OUT_OF_RANGE, XQP0018);
      DEF_ERR_CODE (API0001_XQUERY_STRING_IS_EMPTY, API0001);
      DEF_ERR_CODE (API0002_COMPILE_FAILED, API0002);
      DEF_ERR_CODE (API0003_XQUERY_NOT_COMPILED, API0003);
      DEF_ERR_CODE (API0004_XQUERY_ALREADY_COMPILED, API0004);
      DEF_ERR_CODE (API0005_COLLECTION_ALREADY_EXISTS, API0005);
      DEF_ERR_CODE (API0006_COLLECTION_NOT_FOUND, API0006);
      DEF_ERR_CODE (API0007_COLLECTION_ITEM_MUST_BE_A_NODE, API0007);
      DEF_ERR_CODE (API0008, API0008);
#undef DEF_ERR_CODE

  }
} canonical_err_names_initializer_obj;



/*******************************************************************************

********************************************************************************/
ZorbaAlertLocation::ZorbaAlertLocation()
{
	filename = "";
	line = 0;
	column = 0;
}


/*******************************************************************************

********************************************************************************/
ZorbaAlert::~ZorbaAlert() {}

ZorbaError::~ZorbaError() {}

ZorbaWarning::~ZorbaWarning() {}

ZorbaNotify::~ZorbaNotify() {}

ZorbaAskUser::~ZorbaAskUser() {}

ZorbaFnError::~ZorbaFnError() {}

ZorbaFnTrace::~ZorbaFnTrace() {}



/*******************************************************************************

********************************************************************************/
#if 1
std::string ZorbaError::toString(ZorbaError::ErrorCodes code)
{
  return canonical_err_names[code];
}
#else
std::string ZorbaError::toString(ZorbaError::ErrorCodes aErrorCode)
{
  switch (aErrorCode)
  {
    case XPDY0002: return std::string("XPDY0002");
    case XPDY0021: return std::string("XPDY0021");
    case XPDY0050: return std::string("XPDY0050");

    case XPST0001: return std::string("XPST0001");
    case XPST0003: return std::string("XPST0003");
    case XPST0005: return std::string("XPST0005");
    case XPST0008: return std::string("XPST0008");
    case XPST0010: return std::string("XPST0010");
    case XPST0017: return std::string("XPST0017");
    case XPST0051: return std::string("XPST0051");
    case XPST0080: return std::string("XPST0080");
    case XPST0081: return std::string("XPST0081");
    case XPST0083: return std::string("XPST0083");

    case XPTY0004: return std::string("XPTY0004");
    case XPTY0006: return std::string("XPTY0006");
    case XPTY0007: return std::string("XPTY0007");
    case XPTY0018: return std::string("XPTY0018");
    case XPTY0019: return std::string("XPTY0019");
    case XPTY0020: return std::string("XPTY0020");

    case XQDY0025: return std::string("XQDY0025");
    case XQDY0026: return std::string("XQDY0026");
    case XQDY0027: return std::string("XQDY0027");
    case XQDY0029: return std::string("XQDY0029");
    case XQDY0041: return std::string("XQDY0041");
    case XQDY0044: return std::string("XQDY0044");
    case XQDY0052: return std::string("XQDY0052");
    case XQDY0061: return std::string("XQDY0061");
    case XQDY0062: return std::string("XQDY0062");
    case XQDY0064: return std::string("XQDY0064");
    case XQDY0072: return std::string("XQDY0072");
    case XQDY0074: return std::string("XQDY0074");
    case XQDY0084: return std::string("XQDY0084");
    case XQDY0091: return std::string("XQDY0091");
    case XQDY0092: return std::string("XQDY0092");

    case XQST0009: return std::string("XQST0009");
    case XQST0012: return std::string("XQST0012");
    case XQST0013: return std::string("XQST0013");
    case XQST0014: return std::string("XQST0014");
    case XQST0015: return std::string("XQST0015");
    case XQST0016: return std::string("XQST0016");
    case XQST0022: return std::string("XQST0022");
    case XQST0031: return std::string("XQST0031");
    case XQST0032: return std::string("XQST0032");
    case XQST0033: return std::string("XQST0033");
    case XQST0034: return std::string("XQST0034");
    case XQST0035: return std::string("XQST0035");
    case XQST0036: return std::string("XQST0036");
    case XQST0037: return std::string("XQST0037");
    case XQST0038: return std::string("XQST0038");
    case XQST0039: return std::string("XQST0039");
    case XQST0040: return std::string("XQST0040");
    case XQST0042: return std::string("XQST0042");
    case XQST0043: return std::string("XQST0043");
    case XQST0045: return std::string("XQST0045");
    case XQST0046: return std::string("XQST0046");
    case XQST0047: return std::string("XQST0047");
    case XQST0048: return std::string("XQST0048");
    case XQST0049: return std::string("XQST0049");
    case XQST0053: return std::string("XQST0053");
    case XQST0054: return std::string("XQST0054");
    case XQST0055: return std::string("XQST0055");
    case XQST0056: return std::string("XQST0056");
    case XQST0057: return std::string("XQST0057");
    case XQST0058: return std::string("XQST0058");
    case XQST0059: return std::string("XQST0059");
    case XQST0060: return std::string("XQST0060");
    case XQST0063: return std::string("XQST0063");
    case XQST0065: return std::string("XQST0065");
    case XQST0066: return std::string("XQST0066");
    case XQST0067: return std::string("XQST0067");
    case XQST0068: return std::string("XQST0068");
    case XQST0069: return std::string("XQST0069");
    case XQST0070: return std::string("XQST0070");
    case XQST0071: return std::string("XQST0071");
    case XQST0073: return std::string("XQST0073");
    case XQST0075: return std::string("XQST0075");
    case XQST0076: return std::string("XQST0076");
    case XQST0077: return std::string("XQST0077");
    case XQST0078: return std::string("XQST0078");
    case XQST0079: return std::string("XQST0079");
    case XQST0082: return std::string("XQST0082");
    case XQST0085: return std::string("XQST0085");
    case XQST0087: return std::string("XQST0087");
    case XQST0088: return std::string("XQST0088");
    case XQST0089: return std::string("XQST0089");
    case XQST0090: return std::string("XQST0090");
    case XQST0093: return std::string("XQST0093");

    case XQTY0023: return std::string("XQTY0023");
    case XQTY0024: return std::string("XQTY0024");
    case XQTY0028: return std::string("XQTY0028");
    case XQTY0030: return std::string("XQTY0030");
    case XQTY0086: return std::string("XQTY0086");

    case FOER0000: return std::string("FOER0000");
    case FOAR0001: return std::string("FOAR0001");
    case FOAR0002: return std::string("FOAR0002");
    case FOCA0001: return std::string("FOCA0001");
    case FOCA0002: return std::string("FOCA0002");
    case FOCA0003: return std::string("FOCA0003");
    case FOCA0005: return std::string("FOCA0005");
    case FOCA0006: return std::string("FOCA0006");
    case FOCH0001: return std::string("FOCH0001");
    case FOCH0002: return std::string("FOCH0002");
    case FOCH0003: return std::string("FOCH0003");
    case FOCH0004: return std::string("FOCH0004");
    case FODC0001: return std::string("FODC0001");
    case FODC0002: return std::string("FODC0002");
    case FODC0003: return std::string("FODC0003");
    case FODC0004: return std::string("FODC0004");
    case FODC0005: return std::string("FODC0005");
    case FODT0001: return std::string("FODT0001");
    case FODT0002: return std::string("FODT0002");
    case FODT0003: return std::string("FODT0003");
    case FONS0004: return std::string("FONS0004");
    case FONS0005: return std::string("FONS0005");
    case FORG0001: return std::string("FORG0001");
    case FORG0002: return std::string("FORG0002");
    case FORG0003: return std::string("FORG0003");
    case FORG0004: return std::string("FORG0004");
    case FORG0005: return std::string("FORG0005");
    case FORG0006: return std::string("FORG0006");
    case FORG0008: return std::string("FORG0008");
    case FORG0009: return std::string("FORG0009");
    case FORX0001: return std::string("FORX0001");
    case FORX0002: return std::string("FORX0002");
    case FORX0003: return std::string("FORX0003");
    case FORX0004: return std::string("FORX0004");
    case FOTY0012: return std::string("FOTY0012");

    case SENR0001_Item_is_attribute_or_namespace_node: 
      return std::string("SENR0001_Item_is_attribute_or_namespace_node");

  	case SEPM0016_Invalid_parameter_value: 
      return std::string("SEPM0016_Invalid_parameter_value");

    case XQP0000_DYNAMIC_RUNTIME_ERROR: 
      return std::string("XQP0000_DYNAMIC_RUNTIME_ERROR");
    case XQP0001_DYNAMIC_ITERATOR_OVERRUN: 
      return std::string("XQP0001_DYNAMIC_ITERATOR_OVERRUN");
    case XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD: 
      return std::string("XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD");
    case XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND: 
      return std::string("XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND");
    case XQP0004_SYSTEM_NOT_SUPPORTED: 
      return std::string("XQP0004_SYSTEM_NOT_SUPPORTED");
    case XQP0005_SYSTEM_ASSERT_FAILED: 
      return std::string("XQP0005_SYSTEM_ASSERT_FAILED");
    case XQP0006_SYSTEM_HASH_ERROR_KEYLEN_EXCEEDS_MAXKEYLEN: 
      return std::string("XQP0006_SYSTEM_HASH_ERROR_KEYLEN_EXCEEDS_MAXKEYLEN");
    case XQP0007_SYSTEM_VECTOR_OUT_OF_RANGE: 
      return std::string("XQP0007_SYSTEM_VECTOR_OUT_OF_RANGE");
    case XQP0008_SYSTEM_READ_LOCK_FAILED: 
      return std::string("XQP0008_SYSTEM_READ_LOCK_FAILED");
    case XQP0009_SYSTEM_WRITE_LOCK_FAILED: 
      return std::string("XQP0009_SYSTEM_WRITE_LOCK_FAILED");
    case XQP0010_SYSTEM_POP_FROM_EMPTY_LIST: 
      return std::string("XQP0010_SYSTEM_POP_FROM_EMPTY_LIST");
    case XQP0011_SYSTEM_FILE_ERROR_IN_FUNCTION: 
      return std::string("XQP0011_SYSTEM_FILE_ERROR_IN_FUNCTION");
    case XQP0012_SYSTEM_FXCHARHEAP_IOEXCEPTION:
      return std::string("XQP0012_SYSTEM_FXCHARHEAP_IOEXCEPTION");
    case XQP0013_SYSTEM_MMFILE_IOEXCEPTION: 
      return std::string("XQP0013_SYSTEM_MMFILE_IOEXCEPTION");
    case XQP0015_SYSTEM_NOT_YET_IMPLEMENTED: 
      return std::string("XQP0015_SYSTEM_NOT_YET_IMPLEMENTED");
    case XQP0016_LOADER_IO_ERROR: 
      return std::string("XQP0016_LOADER_IO_ERROR");
    case XQP0017_LOADER_NOT_WELL_FORMED_XML:
      return std::string("XQP0017_LOADER_NOT_WELL_FORMED_XML");
    case XQP0018_NODEID_OUT_OF_RANGE: 
      return std::string("XQP0018_NODEID_OUT_OF_RANGE");

    case API0001_XQUERY_STRING_IS_EMPTY: 
      return std::string("API0001_XQUERY_STRING_IS_EMPTY");
    case API0002_COMPILE_FAILED: 
      return std::string("API0002_COMPILE_FAILED");
    case API0003_XQUERY_NOT_COMPILED: 
      return std::string("API0003_XQUERY_NOT_COMPILED");
    case API0004_XQUERY_ALREADY_COMPILED: 
      return std::string("API0004_XQUERY_ALREADY_COMPILED");
    case API0005_COLLECTION_ALREADY_EXISTS: 
      return std::string("API0005_COLLECTION_ALREADY_EXISTS");
    case API0006_COLLECTION_NOT_FOUND: 
      return std::string("API0006_COLLECTION_NOT_FOUND");
    case API0007_COLLECTION_ITEM_MUST_BE_A_NODE: 
      return std::string("API0007_COLLECTION_ITEM_MUST_BE_A_NODE");
    case API0008: 
      return std::string("API0008");
    default:
      return std::string("Unknown error code");
  }
}
#endif
}
