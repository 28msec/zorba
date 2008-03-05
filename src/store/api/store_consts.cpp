
#include <zorba/store_consts.h>

namespace zorba { namespace store {

static const char* theNodeKindStrings[7] =
{
  "anyNode",
  "documentNode",
  "elementNode",
  "attributeNode",
  "textNode",
  "piNode",
  "commentNode"
};


std::string StoreConsts::toString(NodeKind k)
{
  return theNodeKindStrings[k];
}

} // namespace store
} // namespace zorba
