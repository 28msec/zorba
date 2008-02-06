#ifndef ZORBA_VERSION_H
#define ZORBA_VERSION_H

#include <string>
#include <sstream>

namespace xqp {

class ZorbaVersion
{ 
protected:
  static uint32_t ZORBA_MAJOR_VERSION;
  static uint32_t ZORBA_MINOR_VERSION;
  static uint32_t ZORBA_PATCH_VERSION;

public:
  static uint32_t getZorbaMajorVersion();

  static uint32_t getZorbaMinorVersion();

  static uint32_t getZorbaPatchVersion();

  static std::string getZorbaVersion();

};

} /* end namespace xqp */

#endif
