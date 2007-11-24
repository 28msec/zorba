
#ifndef XQP_STORE_NODEID
#define XQP_STORE_NODEID

#include <vector>
#include "types/representations.h"

namespace xqp
{

/*******************************************************************************

********************************************************************************/
class OrdPathId
{
 protected:
  static const unsigned long DEFAULT_PATH_SIZE = 32;

 protected:
  unsigned long       theTreeId;

  long                theDeweyArray[DEFAULT_PATH_SIZE];
  long*               theDeweyId;
  unsigned long       theLength;
  unsigned long       theMaxLength;

public:
  OrdPathId() : theTreeId(0),
                theDeweyId(theDeweyArray),
                theLength(0),
                theMaxLength(DEFAULT_PATH_SIZE) { }
  
  OrdPathId(const OrdPathId& other);

  ~OrdPathId() { clear(); }

  OrdPathId& operator=(const OrdPathId& other);

  void init();
  void clear();

  unsigned long size() const { return theLength; }

  void push_child();
  void pop_child();

  xqp_string show() const;
};

}

#endif
