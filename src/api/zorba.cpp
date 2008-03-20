#include <zorba/zorba.h>
#include <zorba/version.h>
#include "api/zorbaimpl.h"

namespace zorba {
  
  Zorba*
  Zorba::getInstance()
  {
    static ZorbaImpl lInstance;
    if ( ! lInstance.theIsInitialized )
      lInstance.init();
    return &lInstance;
  }

  Zorba::~Zorba() { }

  const Version&
  Zorba::version()
  {
    static Version theVersion;
    return theVersion;
  }
} /* namespace zorba */
