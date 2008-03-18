
#include "sax2/using_libxml2/locator_libxml2.h"

namespace zorba{

SAX2_LocatorLibXML2::SAX2_LocatorLibXML2 (xmlParserCtxtPtr ctxt, 
                                          xmlSAXLocatorPtr loc)
{
  this->ctxt = ctxt;
  this->loc = loc;
  publicId = (const char*)loc->getPublicId(ctxt);
  systemId = (const char*)loc->getSystemId(ctxt);
}

unsigned long  SAX2_LocatorLibXML2::getLineNumber () const
{
  return loc->getLineNumber(ctxt);
}

unsigned long  SAX2_LocatorLibXML2::getColumnNumber () const
{
  return loc->getColumnNumber(ctxt);
}

}//end namespace zorba
