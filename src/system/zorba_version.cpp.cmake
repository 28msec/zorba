#include "zorba/system/zorba_version.h"

#include <string>
#include <sstream>

namespace xqp {

  int ZorbaVersion::theMajorVersion = @CPACK_PACKAGE_VERSION_MAJOR@;
  int ZorbaVersion::theMinorVersion = @CPACK_PACKAGE_VERSION_MINOR@;
  int ZorbaVersion::thePatchVersion = @CPACK_PACKAGE_VERSION_PATCH@;

  int
  ZorbaVersion::getZorbaMajorVersion() { return theMajorVersion; }

  int
  ZorbaVersion::getZorbaMinorVersion() { return theMinorVersion; }

  int
  ZorbaVersion::getZorbaPatchVersion() { return thePatchVersion; }

  std::string
  ZorbaVersion::getZorbaVersion() 
  {
    std::ostringstream lStream;
    lStream << getZorbaMajorVersion() << "." << getZorbaMinorVersion() << "." << getZorbaPatchVersion();
    return lStream.str();
  }

} /* end namespace xqp */

