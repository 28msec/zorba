
#ifndef ZORBA_SAX2_LOCATOR_NATIVE_17_MAR_2008
#define ZORBA_SAX2_LOCATOR_NATIVE_17_MAR_2008

#include "zorba/sax2.h"

namespace zorba{

class SAX2_LocatorNative : public SAX2_Locator
{
public:
  unsigned long line;
  unsigned long column;
public:
  SAX2_LocatorNative() {}

  virtual unsigned long  getLineNumber () const {return line;}
   
  virtual unsigned long  getColumnNumber () const {return column;}

  void    setPublicId(xqp_string publicId);
  void    setSystemId(xqp_string systemId);
};

}//end namespace zorba

#endif
