#ifndef ZORBA_VERSION_API_H
#define ZORBA_VERSION_API_H

#include <string>

namespace zorba {

  class Version
  { 
    protected:
      static int theMajorVersion;
      static int theMinorVersion;
      static int thePatchVersion;

    public:
      static int 
      getMajorVersion();

      static int 
      getMinorVersion();

      static int 
      getPatchVersion();

      static std::string
      getVersion();

  };

  std::ostream& operator<< (std::ostream& os, const Version& aVersion);


} /* end namespace zorba */
#endif
