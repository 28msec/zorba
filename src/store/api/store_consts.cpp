
#include "store/api/store_consts.h"

namespace xqp
{

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


}
