#include <string>
#include <sstream>

#include <zorba/zorba_version.h>

namespace xqp {

  // the following vars will be replaced by cmake
  int ZorbaVersion::theMajorVersion = @ZORBA_MAJOR_NUMBER@;
  int ZorbaVersion::theMinorVersion = @ZORBA_MINOR_NUMBER@;
  int ZorbaVersion::thePatchVersion = @ZORBA_PATCH_NUMBER@;

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

