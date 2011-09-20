/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "stdafx.h"

#include <zorba/config.h>

#ifdef ZORBA_XQUERYX

#include <libxslt/xslt.h>
#include <libxslt/transform.h>
#include <libxml/xmlerror.h>
#include <libxslt/xsltutils.h>

#include "compiler/xqueryx/xqueryx_to_xquery.h"
#include "compiler/xqueryx/xqueryx_xslt.h"

#include <diagnostics/xquery_diagnostics.h>

namespace zorba {

XQueryXConvertor::XQueryXConvertor()
{
  xqueryx_xslt = NULL;
  inited = false;
}

XQueryXConvertor::~XQueryXConvertor()
{
  if(xqueryx_xslt)
    xsltFreeStylesheet((xsltStylesheetPtr)xqueryx_xslt);
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
    doc = xmlParseDoc((xmlChar*)xqueryx_update_xslt);

    xqueryx_xslt = (xsltStylesheet*)xsltParseStylesheetDoc(doc);
  //	xmlFreeDoc(doc);
  }
  inited = true;
}

void XQueryXConvertor::zorba_xslt_error_handler(void *ctx, const char *msg, ...)
{
  if(!ctx)
    return;
  va_list args;
  va_start( args, msg );
  int     len;
  std::string  *errstr = (std::string  *)ctx;
  char    *buffer = NULL;

  len = 2000;//vsnprintf( buffer, 0, msg, args ) + 1;
    
  buffer = (char*)malloc( len * sizeof(char) );

  vsnprintf( buffer, len, msg, args );
  *errstr += buffer;
  free(buffer);
}

char* XQueryXConvertor::XQueryX2XQuery( const char *xqueryx)
{
  XQueryX_init();

  xmlDocPtr doc, res;

  //setup libxml
  xmlSubstituteEntitiesDefault(1);
  xmlLoadExtDtdDefaultValue = 1;
  errstr.clear();
  xmlSetGenericErrorFunc(&errstr, zorba_xslt_error_handler);
  xsltSetGenericErrorFunc(&errstr, zorba_xslt_error_handler);

  doc = xmlParseDoc((xmlChar*)xqueryx);

  try{
  if(!doc)
    throw ZORBA_EXCEPTION(zerr::ZXQP0031_MALFORMED_XQUERYX_INPUT, ERROR_PARAMS(errstr));

  //xsltTransformContextPtr ctxt;
  //ctxt = xsltNewTransformContext((xsltStylesheetPtr)xqueryx_xslt, doc);

  const char  *param[]= {NULL};
//  res = xsltApplyStylesheetUser((xsltStylesheetPtr)xqueryx_xslt, doc, param,
//                                  NULL, stderr, ctxt);
  res = xsltApplyStylesheet((xsltStylesheetPtr)xqueryx_xslt, doc, param);
  if(!res)
  {
    xmlFreeDoc(doc);
    throw ZORBA_EXCEPTION( zerr::ZXQP0032_ERROR_TRANSFORMING_XQUERYX_TO_XQUERY, ERROR_PARAMS(errstr) );
  }
/*  if ((ctxt->state == XSLT_STATE_ERROR) || (ctxt->state == XSLT_STATE_STOPPED))
  {
    xsltFreeTransformContext(ctxt);
    xmlFreeDoc(doc);
    throw ZORBA_EXCEPTION( zerr::ZXQP0032_ERROR_TRANSFORMING_XQUERYX_TO_XQUERY );
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
  if(!xquery)
  {
    throw ZORBA_EXCEPTION( zerr::ZXQP0032_ERROR_TRANSFORMING_XQUERYX_TO_XQUERY, ERROR_PARAMS(ZED(xqueryx_empty_content) ));
  }

  //reset the error handlers for libxml2 and libxslt
  xmlSetGenericErrorFunc(NULL, NULL);
  xsltSetGenericErrorFunc(NULL, NULL);

  return xquery;
  }
  catch(...)
  {
    //reset the error handlers for libxml2 and libxslt
    xmlSetGenericErrorFunc(NULL, NULL);
    xsltSetGenericErrorFunc(NULL, NULL);
    throw;
  }
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

  if((cursor[0] == (char)0xEF) && (cursor[1] == (char)0xBB) && (cursor[2] == (char)0xBF))
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
/* vim:set et sw=2 ts=2: */
