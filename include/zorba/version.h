#ifndef ZORBA_VERSION_H
#define ZORBA_VERSION_H

#include <zorba/common/common.h>
#include <string>
#include <sstream>

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

} /* end namespace zorba */
#endif
