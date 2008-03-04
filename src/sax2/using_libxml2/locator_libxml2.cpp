
#include "sax2/using_libxml2/locator_libxml2.h"

namespace zorba{

SAX2_LocatorLibXML2::SAX2_LocatorLibXML2 (xmlParserCtxtPtr ctxt, 
                                          xmlSAXLocatorPtr loc)
{
  publicId = (const char*)loc->getPublicId(ctxt);
  systemId = (const char*)loc->getSystemId(ctxt);
  line = loc->getLineNumber(ctxt);
  column = loc->getColumnNumber(ctxt);
}

}
