#ifndef ZORBA_STORE_API_COPYMODE
#define ZORBA_STORE_API_COPYMODE

#include <string>

namespace zorba { namespace store {

struct CopyMode
{
public:
  bool  theAssignIds;
  bool  theTypePreserve;
  bool  theNsPreserve;
  bool  theNsInherit;

  CopyMode()
    :
    theAssignIds(true),
    theTypePreserve(true),
    theNsPreserve(true),
    theNsInherit(true)
  {
  }

  void set(bool assignIds, bool typePreserve, bool nsPreserve, bool nsInherit)
  {
    theAssignIds = assignIds;
    theTypePreserve = typePreserve;
    theNsPreserve = nsPreserve;
    theNsInherit = nsInherit;
  }

  std::string toString() const
  {
    std::string s;
    s = "[";
    s += (theAssignIds ? "T" : "F");
    s += " ";
    s += (theTypePreserve ? "T" : "F");
    s += " ";
    s += (theNsPreserve ? "T" : "F");
    s += " ";
    s += (theNsInherit ? "T" : "F");
    s += "]";
    return s;
  }
};

} // namespace store
} // namespace zorba
#endif
