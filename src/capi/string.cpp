#include "capi/string.h"

#include <zorba/zorba.h>

using namespace zorba;

namespace zorbac {
 
  XQUERY_ERROR
  String::to_char(XQC_String str, const char** res)
  {
    try {
      zorba::String* lInnerString = static_cast<zorba::String*>(str->data);
      *res = lInnerString->c_str();
      return XQ_SUCCESS;
    } catch (ZorbaException &e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }
 
  void
  String::free(XQC_String str)
  {
    try {
      zorba::String* lInnerString = static_cast<zorba::String*>(str->data);
      delete lInnerString;
      delete str;
    } catch (ZorbaException &e) {
      assert(false); 
    } catch (...) {
      assert(false); 
    }
  }
}; /* namespace zorbac */
