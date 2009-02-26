
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


bool XQueryXConvertor::isWhitespace(char c)
{
  if((c == ' ')  || (c == '\t') ||
     (c == '\n') || (c == '\r'))
    return true;
  else
    return false;
}

char* XQueryXConvertor::skipWhitespaces(char *xquery_str)
{
  while(isWhitespace(*xquery_str))
       xquery_str++;
  return xquery_str;
}

//identify XQueryX by content: root tag = "<prefix:module ... xmlns:prefix="http://www.w3.org/2005/XQueryX" ... > "
bool  XQueryXConvertor::isXQueryX(char *xquery_str)
{
  char  *cursor = xquery_str;

  if((cursor[0] == 0xEF) && (cursor[1] == 0xBB) && (cursor[2] == 0xBF))
  {
    //UTF8 mark (on Windows text editors) U+FEFF
    cursor += 3;//skip
  }

  cursor = skipWhitespaces(cursor);
checkTag:
  if(*cursor != '<')
    return false;
  cursor++;
  if(*cursor == '?') //skip xml pi
  {
    while((*cursor != '>') && (*cursor != 0))
      cursor++;
    if(*cursor == 0)
      return false;
    cursor++;
    cursor = skipWhitespaces(cursor);
    goto checkTag;
  }
  else if(*cursor == '!')
  {
    //skip comments
    while((*cursor != '>') && (*cursor != 0))
      cursor++;
    if(*cursor == 0)
      return false;
    cursor++;
    cursor = skipWhitespaces(cursor);
    goto checkTag;
  }

  //now read root tag
  cursor = skipWhitespaces(cursor);
  //read qname
  char *cursor2 = cursor;
  std::string prefix;
  while((*cursor2 != ':') && !isWhitespace(*cursor2) && (*cursor2 != 0))
    cursor2++;
  if(*cursor2 == 0)
    return false;
  if(*cursor2 == ':')
  {  
    *cursor2 = 0;
    prefix = cursor;
    *cursor2 = ':';
    cursor2++;
    cursor = cursor2;
    //read until whitespace
    while(!isWhitespace(*cursor2) && (*cursor2 != 0))
      cursor2++;
    if(*cursor2 == 0)
      return false;
  }
  if(((cursor2-cursor) != 6) || strncmp(cursor , "module", 6))
    return false;
  cursor = skipWhitespaces(cursor2);

  //read namespaces
  while((*cursor != '>') && (*cursor != 0))
  {
    //read attributes and namespaces and check for module XQueryX prefix
    cursor2 = cursor;
    while((*cursor2 != ':') && (*cursor2 != '=') && (*cursor2 != 0))
      cursor2++;
    if(*cursor2 == 0)
      return false;
    bool  is_namespace = false;
    bool  found_namespace = false;
    bool  has_prefix = false;
    if(*cursor2 == ':')
    {
      has_prefix = true;
      *cursor2 = 0;
      if(!strcmp(cursor, "xmlns"))
        is_namespace = true;
      *cursor2 = ':';
      cursor2++;
      cursor = cursor2;
      while((*cursor2 != '=') && (*cursor2 != 0))
        cursor2++;
      if(*cursor2 == 0)
        return false;
    }
    //cursor2 points to '='
    *cursor2 = 0;
    if(is_namespace && !prefix.compare(cursor))
      found_namespace = true;
    else if(!has_prefix && !strcmp(cursor, "xmlns") && prefix.empty())
      found_namespace = true;
    *cursor2 = '=';
    cursor = skipWhitespaces(cursor2+1);
    if((*cursor != '"') && (*cursor != '\''))
      return false;
    char  quotes_char = *cursor;
    cursor++;
    cursor2 = cursor;
    while((*cursor2 != quotes_char) && (*cursor2 != 0))
      cursor2++;
    if(*cursor2 == 0)
      return false;
    if(found_namespace)
    {
      *cursor2 = 0;
      //check the namespace 
      if(!strcmp(cursor, "http://www.w3.org/2005/XQueryX"))
      {
        *cursor2 = quotes_char;
        return true;//is XQueryX !!!
      }
      else
      {
        *cursor2 = quotes_char;
        return false;
      }
    }
    cursor = skipWhitespaces(cursor2+1);
  }
  return false;
}


}//end namespace zorba

#endif//ZORBA_XQUERYX
