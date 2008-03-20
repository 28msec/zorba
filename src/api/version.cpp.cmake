#include <string>
#include <ostream>
#include <sstream>

#include <zorba/version.h>

namespace zorba {

  // the following vars will be replaced by cmake
  int Version::theMajorVersion = @ZORBA_MAJOR_NUMBER@;
  int Version::theMinorVersion = @ZORBA_MINOR_NUMBER@;
  int Version::thePatchVersion = @ZORBA_PATCH_NUMBER@;

  int
  Version::getMajorVersion() { return theMajorVersion; }

  int
  Version::getMinorVersion() { return theMinorVersion; }

  int
  Version::getPatchVersion() { return thePatchVersion; }

  std::string
  Version::getVersion() 
  {
    std::ostringstream lStream;
    lStream << getMajorVersion() << "." << getMinorVersion() << "." << getPatchVersion();
    return lStream.str();
  }


  std::ostream& operator<< (std::ostream& os, const Version& aVersion)
  {
    os << aVersion.getVersion();
    return os;
  }

} /* end namespace zorba */
