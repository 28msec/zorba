#include "representations.h"

namespace zorba {

class URI
{
 public:

  typedef enum {
    INVALID_URI,
    RESOLUTION_ERROR,
    MAX_ERROR_CODE
  } error_t;

  static bool is_valid (const xqpStringStore_t& uri);

  // Has semantics of fn:resolve-uri (uri, base):
  // * if @p rel is absolute OR if @p base is relative, result is @p rel
  // * otherwise attempts relative URI resolution
  // @return error code, or URI::MAX_ERROR_CODE if no error
  static error_t resolve_relative(
        const xqpStringStore_t& base,
        const xqpStringStore_t& rel,
        xqpStringStore_t&       result);
  };

}
