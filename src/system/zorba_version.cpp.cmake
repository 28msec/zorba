#include "zorba/system/zorba_version.h"

#include <string>
#include <sstream>

namespace xqp {

  uint32_t ZorbaVersion::ZORBA_MAJOR_VERSION = @CPACK_PACKAGE_VERSION_MAJOR@;
  uint32_t ZorbaVersion::ZORBA_MINOR_VERSION = @CPACK_PACKAGE_VERSION_MINOR@;
  uint32_t ZorbaVersion::ZORBA_PATCH_VERSION = @CPACK_PACKAGE_VERSION_PATCH@;

  uint32_t
  ZorbaVersion::getZorbaMajorVersion() { return ZORBA_MAJOR_VERSION; }

  uint32_t
  ZorbaVersion::getZorbaMinorVersion() { return ZORBA_MINOR_VERSION; }

  uint32_t
  ZorbaVersion::getZorbaPatchVersion() { return ZORBA_PATCH_VERSION; }

  std::string
  ZorbaVersion::getZorbaVersion() 
  {
    std::ostringstream lStream;
    lStream << getZorbaMajorVersion() << "." << getZorbaMinorVersion() << "." << getZorbaPatchVersion();
    return lStream.str();
  }

} /* end namespace xqp */

