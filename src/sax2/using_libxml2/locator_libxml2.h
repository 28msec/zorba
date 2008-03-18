
#ifndef ZORBA_SAX2_LOCATOR_IMPLEMENTATION_WITH_LIBXML2_28_FEB_2008
#define ZORBA_SAX2_LOCATOR_IMPLEMENTATION_WITH_LIBXML2_28_FEB_2008

#include "zorba/sax2.h"
#include <libxml/tree.h>

namespace zorba{

class SAX2_LocatorLibXML2 : public SAX2_Locator
{
  xmlParserCtxtPtr ctxt;
  xmlSAXLocatorPtr loc;
public:
  SAX2_LocatorLibXML2(xmlParserCtxtPtr ctxt, xmlSAXLocatorPtr loc);
  virtual unsigned long  getLineNumber () const;
   
  virtual unsigned long  getColumnNumber () const;
};

}//end namespace zorba

#endif
