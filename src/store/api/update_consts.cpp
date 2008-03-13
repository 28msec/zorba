
#include "store/api/update_consts.h"

namespace zorba { namespace store {

static const char* theUpdateKindStrings[] =
{
  "insert_before",
  "insert_after",
  "insert_into",
  "insert_into_first",
  "insert_into_last",
  "insert_attribute",
  "delete",
  "replace_node",
  "replace_value",
  "replace_content",
  "rename"
};


std::string UpdateConsts::toString(UpdateKind k)
{
  return theUpdateKindStrings[k];
}

} // namespace store
} // namespace zorba
