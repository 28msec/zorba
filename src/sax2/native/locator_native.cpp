
#include "sax2/native/locator_native.h"

namespace zorba{

void    SAX2_LocatorNative::setPublicId(xqp_string publicId)
{
  this->publicId = publicId;
}

void    SAX2_LocatorNative::setSystemId(xqp_string systemId)
{
  this->systemId = systemId;
}


}//end namespace zorba
