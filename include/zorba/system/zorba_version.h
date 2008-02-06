#ifndef ZORBA_VERSION_H
#define ZORBA_VERSION_H

#include "zorba/common.h"
#include <string>
#include <sstream>

namespace xqp {

class ZorbaVersion
{ 
protected:
  static int theMajorVersion;
  static int theMinorVersion;
  static int thePatchVersion;

public:
  static int getZorbaMajorVersion();

  static int getZorbaMinorVersion();

  static int getZorbaPatchVersion();

  static std::string getZorbaVersion();

};

} /* end namespace xqp */

#endif
