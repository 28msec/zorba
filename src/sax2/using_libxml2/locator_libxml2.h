
#ifndef ZORBA_SAX2_LOCATOR_IMPLEMENTATION_WITH_LIBXML2_28_FEB_2008
#define ZORBA_SAX2_LOCATOR_IMPLEMENTATION_WITH_LIBXML2_28_FEB_2008

#include "zorba/sax2.h"
#include <libxml/tree.h>

namespace xqp{

class SAX2_LocatorLibXML2 : public SAX2_Locator
{
public:
  SAX2_LocatorLibXML2(xmlParserCtxtPtr ctxt, xmlSAXLocatorPtr loc);
};

}//end namespace xqp

#endif
