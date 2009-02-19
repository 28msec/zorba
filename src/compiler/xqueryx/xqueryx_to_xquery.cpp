
#include <zorba/config.h>

#ifdef ZORBA_XQUERYX

#include <libxml/xmlmemory.h>
#include <libxml/debugXML.h>
#include <libxml/HTMLtree.h>
#include <libxml/xmlIO.h>
#include <libxml/DOCBparser.h>
#include <libxml/xinclude.h>
#include <libxml/catalog.h>
#include <libxslt/libxslt.h>
#include <libxslt/xsltinternals.h>
#include <libxslt/transform.h>
#include <libxslt/xsltutils.h>

#include "compiler/xqueryx/xqueryx_to_xquery.h"
#include "compiler/xqueryx/xqueryx_xslt.h"

#include <zorbaerrors/error_manager.h>

namespace zorba {

XQueryXConvertor::XQueryXConvertor()
{
  xqueryx2005 = NULL;
  inited = false;

  //setup libxml
  xmlSubstituteEntitiesDefault(1);
  xmlLoadExtDtdDefaultValue = 1;
}

XQueryXConvertor::~XQueryXConvertor()
{
  xsltFreeStylesheet((xsltStylesheetPtr)xqueryx2005);
  //free xslt
  xsltCleanupGlobals();

  //free libxml2
  xmlCleanupParser();
}

void XQueryXConvertor::XQueryX_init()
{
  if(!inited)
  {
    xmlDocPtr doc;
    doc = xmlParseDoc((const xmlChar*)xqueryx2005_xslt);

    xqueryx2005 = (xsltStylesheet*)xsltParseStylesheetDoc(doc);
  //	xmlFreeDoc(doc);
  }
  inited = true;
}

char* XQueryXConvertor::XQueryX2XQuery( const char *xqueryx)
{
  XQueryX_init();

  xmlDocPtr doc, res;

  doc = xmlParseDoc((const xmlChar*)xqueryx);

  if(!doc)
  {
    ZORBA_ERROR(XQP0031_MALFORMED_XQUERYX_INPUT);
    return NULL;
  }

  //xsltTransformContextPtr ctxt;
  //ctxt = xsltNewTransformContext((xsltStylesheetPtr)xqueryx2005, doc);

  const char  *param[]= {NULL};
//  res = xsltApplyStylesheetUser((xsltStylesheetPtr)xqueryx2005, doc, param,
//                                  NULL, stderr, ctxt);
  res = xsltApplyStylesheet((xsltStylesheetPtr)xqueryx2005, doc, param);
  if(!res)
  {
	  xmlFreeDoc(doc);
    ZORBA_ERROR(XQP0032_ERROR_TRANSFORMING_XQUERYX_TO_XQUERY);
    return NULL;
  }
/*  if ((ctxt->state == XSLT_STATE_ERROR) || (ctxt->state == XSLT_STATE_STOPPED))
  {
    xsltFreeTransformContext(ctxt);
	  xmlFreeDoc(doc);
    ZORBA_ERROR(XQP0032_ERROR_TRANSFORMING_XQUERYX_TO_XQUERY);
    return NULL;
  }
  xsltFreeTransformContext(ctxt);
*/ 

  char  *xquery;
  //xmlNodePtr    root_res;
  //root_res = xmlDocGetRootElement(res);
  //xquery = (char*)xmlNodeGetContent(root_res);//free it with xmlFree
  xquery = (char*)xmlNodeListGetString(res, res->children, 1);

  xmlFreeDoc(res);
	xmlFreeDoc(doc);

  return xquery;
}

void XQueryXConvertor::freeResult(char *result_str)
{
  xmlFree(result_str);
}

}//end namespace zorba

#endif//ZORBA_XQUERYX
