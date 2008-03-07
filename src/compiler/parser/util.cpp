#include <zorbatypes/utf8.h>
#include "compiler/parser/util.h"
#include "compiler/parser/query_loc.h"
#include "errors/error_factory.h"

using namespace std;
namespace zorba {

// TODO: reuse (better) code that is probably available elsewhere in Zorba
int decode_entity (const char *in, string *out) {
  QueryLoc loc;
  const char *start = in;
  if (in [0] == '#') {
    ++in;
    int base = 10;
    if (*in == 'x') { base = 16; ++in; }
    for (; *in == '0'; ++in);
    unsigned long n = strtoul (in, (char **) &in, base);
    if (*in++ != ';')
      ZORBA_ERROR_ALERT (ZorbaError::XPST0003, &loc);
    if (! is_code_point_valid (n))
      ZORBA_ERROR_ALERT (ZorbaError::XQST0090, &loc);
    UTF8Encode (n, back_inserter (*out));
    return in - start;
  }
#define M( str, len, r ) if (strncmp (in, str, len) == 0) { *out += r; return len; }
  M ("amp;", 4, "&") else
  M ("lt;", 3, "<") else
  M ("gt;", 3, ">") else
  M ("quot;", 5, "\"") else
  M ("apos;", 5, "'")
#undef M

  ZORBA_ERROR_ALERT (ZorbaError::XPST0003, &loc);
  return -1;
}

}
