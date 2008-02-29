
#include "zorba/sax2.h"
#include "sax2/using_libxml2/xmlreader_libxml2.h"
#include <iostream>
#include "zorba/errors.h"
#include "zorba/compiled_xquery.h"
#include "errors/error_factory.h"
#include "system/zorba.h"
#include "system/zorba_engine.h"

#include "sax2/using_libxml2/locator_libxml2.h"
#include "sax2/using_libxml2/attributes_libxml2.h"
#include "sax2/using_libxml2/namespaces_libxml2.h"

#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/xmlstring.h>


namespace xqp{

SAX2_XMLReaderLibXML2::SAX2_XMLReaderLibXML2(
                      SAX2_ContentHandler *content_handler,
                      SAX2_ErrorHandler *error_handler,
                      SAX2_DTDHandler   *dtd_handler,
                      SAX2_DeclHandler  *decl_handler,
                      SAX2_LexicalHandler* lexical_handler) :
    SAX2_XMLReader(content_handler, error_handler, 
                  dtd_handler, decl_handler, lexical_handler)
{
  memset(&theSaxHandler, 0, sizeof(theSaxHandler) );
  theSaxHandler.initialized = XML_SAX2_MAGIC;
//  theSaxHandler.internalSubset = zorba_internalSubsetSAXFunc;
//  theSaxHandler.isStandalone = zorba_isStandaloneSAXFunc;
//  theSaxHandler.hasInternalSubset = zorba_hasInternalSubsetSAXFunc;
//  theSaxHandler.hasExternalSubset = zorba_hasExternalSubsetSAXFunc;
//  theSaxHandler.resolveEntity = zorba_resolveEntitySAXFunc;
//  theSaxHandler.getEntity = zorba_getEntitySAXFunc;
  if(decl_handler)
    theSaxHandler.entityDecl = zorba_entityDeclSAXFunc;
  if(dtd_handler)
    theSaxHandler.notationDecl = zorba_notationDeclSAXFunc;
  if(decl_handler)
  {
    theSaxHandler.attributeDecl = zorba_attributeDeclSAXFunc;
    theSaxHandler.elementDecl = zorba_elementDeclSAXFunc;
  }
  if(dtd_handler)
    theSaxHandler.unparsedEntityDecl = zorba_unparsedEntityDeclSAXFunc;
  if(content_handler)
  {
    theSaxHandler.setDocumentLocator = zorba_setDocumentLocatorSAXFunc;
    theSaxHandler.startDocument = zorba_startDocumentSAXFunc;
    theSaxHandler.endDocument = zorba_endDocumentSAXFunc;
  }
//  theSaxHandler.startElement = zorba_startElementSAXFunc;
//  theSaxHandler.endElement = zorba_endElementSAXFunc;
//  theSaxHandler.reference = zorba_referenceSAXFunc;
  if(content_handler)
  {
    theSaxHandler.characters = zorba_charactersSAXFunc;
    theSaxHandler.ignorableWhitespace = zorba_ignorableWhitespaceSAXFunc;
    theSaxHandler.processingInstruction = zorba_processingInstructionSAXFunc;
  }
  if(lexical_handler)
    theSaxHandler.comment = zorba_commentSAXFunc;
  if(error_handler)
  {
    theSaxHandler.warning = zorba_warningSAXFunc;
    theSaxHandler.error = zorba_errorSAXFunc;
    theSaxHandler.fatalError = zorba_fatalErrorSAXFunc; /* unused error() get all the errors */
  }
//  theSaxHandler.getParameterEntity = zorba_getParameterEntitySAXFunc;
  theSaxHandler.cdataBlock = zorba_cdataBlockSAXFunc;
//  theSaxHandler.externalSubset = zorba_externalSubsetSAXFunc;

  if(content_handler)
  {
    theSaxHandler.startElementNs = zorba_startElementNsSAX2Func;
    theSaxHandler.endElementNs = zorba_endElementNsSAX2Func;
  }

  locator = NULL;
  ctxt = NULL;
}

SAX2_XMLReaderLibXML2::~SAX2_XMLReaderLibXML2()
{
  if(ctxt)
    xmlFreeParserCtxt(ctxt);
  ctxt = NULL;
}

bool SAX2_XMLReaderLibXML2::parse(XQuery_t xquery)
{
  std::ostringstream    oss;
  std::string           strxml;
  if(!xquery->serializeXML(oss))
    return false;

  strxml = oss.str();
  ctxt = xmlCreatePushParserCtxt(&theSaxHandler, this, strxml.c_str(), strxml.length(), NULL);

  try{
    if (ctxt == NULL)
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQP0023_GET_RESULTS_AS_SAX_FAILED);
		  return false;
    }
  }CATCH_ALL_RETURN_false;

  xmlFreeParserCtxt(ctxt);
  ctxt = NULL;

  return true;
}

// void SAX2_XMLReaderLibXML2::zorba_internalSubsetSAXFunc (void *ctx,
//			const xmlChar *name,
//			const xmlChar *ExternalID,
//			const xmlChar *SystemID);
// void SAX2_XMLReaderLibXML2::zorba_externalSubsetSAXFunc (void *ctx,
//			const xmlChar *name,
//			const xmlChar *ExternalID,
//			const xmlChar *SystemID);
// xmlEntityPtr SAX2_XMLReaderLibXML2::zorba_getEntitySAXFunc (void *ctx,
//			const xmlChar *name)
// {
//  return xmlGetPredefinedEntity(name);
// }
// xmlEntityPtr SAX2_XMLReaderLibXML2::zorba_getParameterEntitySAXFunc (void *ctx,
//			const xmlChar *name);
void SAX2_XMLReaderLibXML2::zorba_entityDeclSAXFunc (void *ctx,
			const xmlChar *name,
			int type,
			const xmlChar *publicId,
			const xmlChar *systemId,
			xmlChar *content)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  switch(type)
  {
  case  XML_INTERNAL_GENERAL_ENTITY:
  case  XML_INTERNAL_PARAMETER_ENTITY:
  case  XML_INTERNAL_PREDEFINED_ENTITY:
    xmlreader->decl_handler->internalEntityDecl((const char*)name, (const char*)content);
    break;
  case  XML_EXTERNAL_GENERAL_UNPARSED_ENTITY:
  case  XML_EXTERNAL_GENERAL_PARSED_ENTITY:
  case  XML_EXTERNAL_PARAMETER_ENTITY:
    xmlreader->decl_handler->externalEntityDecl((const char*)name, (const char*)publicId, (const char*)systemId);
    break;
  }
}
void SAX2_XMLReaderLibXML2::zorba_notationDeclSAXFunc(void *ctx,
			const xmlChar *name,
			const xmlChar *publicId,
			const xmlChar *systemId)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  xmlreader->dtd_handler->notationDecl((const char*)name, (const char*)publicId, (const char*)systemId);
}

void SAX2_XMLReaderLibXML2::zorba_attributeDeclSAXFunc(void *ctx,
			const xmlChar *elem,
			const xmlChar *fullname,
			int type,
			int def,
			const xmlChar *defaultValue,
			xmlEnumerationPtr tree)
{
  xqp_string  strtype;
  xqp_string  strmode;

  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;

  switch(type)
  {
  case  XML_ATTRIBUTE_CDATA:
    strtype = "CDATA";break;
  case  XML_ATTRIBUTE_ID:
    strtype = "ID";break;
  case  XML_ATTRIBUTE_IDREF:
    strtype = "IDREF";break;
  case  XML_ATTRIBUTE_IDREFS:
    strtype = "IDREFS";break;
  case  XML_ATTRIBUTE_ENTITY:
    strtype = "ENTITY";break;
  case  XML_ATTRIBUTE_ENTITIES:
    strtype = "ENTITIES";break;
  case  XML_ATTRIBUTE_NMTOKEN:
    strtype = "NMTOKEN";break;
  case  XML_ATTRIBUTE_NMTOKENS:
    strtype = "NMTOKENS";break;
  case  XML_ATTRIBUTE_NOTATION:
    strtype = "NOTATION ";//continue as ENUMERATION
  case  XML_ATTRIBUTE_ENUMERATION:
  {
    strtype += "(";
    xmlEnumeration    *temp_enum;
    temp_enum = tree;
    while(temp_enum)
    {
      strtype += (const char*)temp_enum->name;
      temp_enum = temp_enum->next;
      if(temp_enum)
        strtype += "|";
    }
    strtype += ")";break;
  }
  }//end switch(type)

  switch(def)
  {
  case  XML_ATTRIBUTE_NONE:
    strmode = "";break;
  case  XML_ATTRIBUTE_REQUIRED:
    strmode = "#REQUIRED";break;
  case  XML_ATTRIBUTE_IMPLIED:
    strmode = "#IMPLIED";break;
  case  XML_ATTRIBUTE_FIXED:
    strmode = "#FIXED";break;
  }
  xmlreader->decl_handler->attributeDecl((const char*)elem, (const char*)fullname, strtype, strmode, (const char*)defaultValue);
}

/*
Reconstruct !ENTITY declaration model from libxml parsed data
*/
xqp_string SAX2_XMLReaderLibXML2::unparseElementContent(::_xmlElementContent* content)
{
  xqp_string    strcontent;
  switch(content->type)
  {
  case  XML_ELEMENT_CONTENT_PCDATA:
    strcontent = "(#PCDATA)";break;
  case  XML_ELEMENT_CONTENT_ELEMENT:
    strcontent = "(";
    strcontent += (const char*)content->name;
    strcontent += ")";
      break;
  case  XML_ELEMENT_CONTENT_SEQ:
    strcontent = "(";
    strcontent += unparseElementContent(content->c1);
    strcontent += ",";
    strcontent += unparseElementContent(content->c2);
    strcontent += ")";
    break;
  case  XML_ELEMENT_CONTENT_OR:
    strcontent = "(";
    strcontent += unparseElementContent(content->c1);
    strcontent += "|";
    strcontent += unparseElementContent(content->c2);
    strcontent += ")";
    break;
  }

  switch(content->ocur)
  {
  case  XML_ELEMENT_CONTENT_ONCE:
    break;
  case  XML_ELEMENT_CONTENT_OPT:
    strcontent += "?"; break;
  case  XML_ELEMENT_CONTENT_MULT:
    strcontent += "*"; break;
  case  XML_ELEMENT_CONTENT_PLUS:
    strcontent += "+"; break;
  }
  return strcontent;
}

void SAX2_XMLReaderLibXML2::zorba_elementDeclSAXFunc(void *ctx,
			const xmlChar *name,
			int type,
			xmlElementContentPtr content)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  xqp_string    strmodel;

  switch(type)
  {
  case XML_ELEMENT_TYPE_UNDEFINED:
    break;
  case XML_ELEMENT_TYPE_EMPTY:
    strmodel = "EMPTY"; break;
  case XML_ELEMENT_TYPE_ANY:
    strmodel = "ANY"; break;
  case XML_ELEMENT_TYPE_MIXED:
  case XML_ELEMENT_TYPE_ELEMENT:
    if(content)
    {
      strmodel = xmlreader->unparseElementContent(content);
    }
    break;
  }

  xmlreader->decl_handler->elementDecl((const char*)name, strmodel);
}

void SAX2_XMLReaderLibXML2::zorba_unparsedEntityDeclSAXFunc(void *ctx,
			const xmlChar *name,
			const xmlChar *publicId,
			const xmlChar *systemId,
			const xmlChar *notationName)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  xmlreader->dtd_handler->unparsedEntityDecl((const char*)name, (const char*)publicId, (const char*)systemId, (const char*)notationName);
}
void SAX2_XMLReaderLibXML2::zorba_setDocumentLocatorSAXFunc (void *ctx,
			xmlSAXLocatorPtr loc)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  xmlreader->locator = new SAX2_LocatorLibXML2(xmlreader->ctxt, loc);
  xmlreader->content_handler->setDocumentLocator(xmlreader->locator);
}
void SAX2_XMLReaderLibXML2::zorba_startDocumentSAXFunc (void *ctx)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  xmlreader->content_handler->startDocument();
}
void SAX2_XMLReaderLibXML2::zorba_endDocumentSAXFunc (void *ctx)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  xmlreader->content_handler->endDocument();
}
//   void zorba_startElementSAXFunc (void *ctx,
//				const xmlChar *name,
//				const xmlChar **atts);
//   void zorba_endElementSAXFunc (void *ctx,
//				const xmlChar *name);
// void SAX2_XMLReaderLibXML2::zorba_attributeSAXFunc (void *ctx,
//			const xmlChar *name,
//			const xmlChar *value);
// void SAX2_XMLReaderLibXML2::zorba_referenceSAXFunc (void *ctx,
//			const xmlChar *name);
void SAX2_XMLReaderLibXML2::zorba_charactersSAXFunc (void *ctx,
			const xmlChar *ch,
			int len)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  xmlreader->content_handler->characters((const char*)ch, len);
}

void SAX2_XMLReaderLibXML2::zorba_ignorableWhitespaceSAXFunc (void *ctx,
			const xmlChar *ch,
			int len)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  xmlreader->content_handler->ignorableWhitespace((const char*)ch, len);
}

void SAX2_XMLReaderLibXML2::zorba_processingInstructionSAXFunc (void *ctx,
		const xmlChar *target,
		const xmlChar *data)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  xmlreader->content_handler->processingInstruction((const char*)target, (const char*)data);
}

void SAX2_XMLReaderLibXML2::zorba_commentSAXFunc (void *ctx,
		const xmlChar *value)
{
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
  xmlreader->lexical_handler->comment((const char*)value, strlen((const char*)value));
}

void SAX2_XMLReaderLibXML2::zorba_cdataBlockSAXFunc (void *ctx,
		  const xmlChar *value,
		  int len)
{
   SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;

   if(xmlreader->lexical_handler)
     xmlreader->lexical_handler->startCDATA();
   if(xmlreader->content_handler)
     xmlreader->content_handler->characters((const char*)value, len);
   if(xmlreader->lexical_handler)
     xmlreader->lexical_handler->endCDATA();
}

void SAX2_XMLReaderLibXML2::zorba_warningSAXFunc (void *ctx,
			const char *msg, ...)
{
   SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
   SAX2_ParseException exc(msg, xmlreader->locator);
   xmlreader->error_handler->warning(exc);
}
 
void SAX2_XMLReaderLibXML2::zorba_errorSAXFunc (void *ctx,
			const char *msg, ...)
{
   SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
   SAX2_ParseException  exc(msg, xmlreader->locator);
   xmlreader->error_handler->error(exc);
}
 void SAX2_XMLReaderLibXML2::zorba_fatalErrorSAXFunc (void *ctx,
			const char *msg, ...)
{
   SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;
   SAX2_ParseException exc(msg, xmlreader->locator);
   xmlreader->error_handler->fatalError(exc);
}
 //int SAX2_XMLReaderLibXML2::zorba_isStandaloneSAXFunc (void *ctx);
// int SAX2_XMLReaderLibXML2::zorba_hasInternalSubsetSAXFunc (void *ctx);

// int SAX2_XMLReaderLibXML2::zorba_hasExternalSubsetSAXFunc (void *ctx);


 void SAX2_XMLReaderLibXML2::zorba_startElementNsSAX2Func (void *ctx,
				const xmlChar *localname,
				const xmlChar *prefix,
				const xmlChar *URI,
				int nb_namespaces,
				const xmlChar **namespaces,
				int nb_attributes,
				int nb_defaulted,
				const xmlChar **attributes)
 {
  SAX2_AttributesLibXML2 *attrs;
  SAX2_NamespacesLibXML2 *namespacesx2;
  SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;

  attrs = new SAX2_AttributesLibXML2(nb_attributes, (const char**)attributes);
  namespacesx2 = new SAX2_NamespacesLibXML2(nb_namespaces, (const char**)namespaces);
 

  xmlreader->push_namespaces(nb_namespaces, namespaces);
  xmlreader->content_handler->startElement((const char*)URI, (const char*)localname, prefix&&prefix[0] ? (xqp_string)(const char*)prefix + ":" + (const char*)localname : (const char*)localname,
                                    *attrs, *namespacesx2);
  delete attrs;
  delete namespaces;
 }

void SAX2_XMLReaderLibXML2::push_namespaces(
				                      int nb_namespaces,
				                      const xmlChar **namespaces)
{
  if(nb_namespaces == 0)
  {
    std::list<std::pair<std::string, std::string> >  new_ns_list;
    ns_list.push_back(new_ns_list);
    return;
  }

  std::list<std::list<std::pair<std::string, std::string> > >::const_iterator   ns_it;
  std::list<std::pair<std::string, std::string> >::const_iterator   pair_it;
  int   i = 0;
  const char* prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
  const char* nsuri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);
  if (prefix == NULL)
    prefix = "";

  for(ns_it = ns_list.begin(); ns_it != ns_list.end(); ns_it++)
  {
    for(pair_it = (*ns_it).begin(); pair_it != (*ns_it).end(); pair_it++)
    {
      if(((*pair_it).first != prefix) ||
        ((*pair_it).second != nsuri))
        break;

      i++;
      if(i >= nb_namespaces)
        break;
      prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
      nsuri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);
      if (prefix == NULL)
        prefix = "";
    }
  }
  
  std::list<std::pair<std::string, std::string> >  new_ns_list;

  ns_list.push_back(new_ns_list);

  std::list<std::pair<std::string, std::string> >  &ns_ref = ns_list.back();

  for(;i<nb_namespaces;i++)
  {
    prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
    nsuri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);
    if (prefix == NULL)
      prefix = "";

    //notify user for new namespaces
    content_handler->startPrefixMapping(prefix, nsuri);
    ns_ref.push_back(std::pair<std::string, std::string>(prefix, nsuri));
  }
}

void SAX2_XMLReaderLibXML2::pop_namespaces()
{
  if(ns_list.empty())
    return;
  std::list<std::pair<std::string, std::string> >  &ns_ref = ns_list.back();
  std::list<std::pair<std::string, std::string> >::const_iterator   pair_it;
  
  for(pair_it = ns_ref.begin(); pair_it != ns_ref.end(); pair_it++)
  {
    content_handler->endPrefixMapping((*pair_it).first);
  }

  ns_list.pop_back();
}

void SAX2_XMLReaderLibXML2::zorba_endElementNsSAX2Func   (void *ctx,
				const xmlChar *localname,
				const xmlChar *prefix,
				const xmlChar *URI)
{
   SAX2_XMLReaderLibXML2 *xmlreader = (SAX2_XMLReaderLibXML2*)ctx;

   xmlreader->content_handler->endElement((const char*)URI, (const char*)localname, prefix&&prefix[0] ? (xqp_string)(const char*)prefix + ":" + (const char*)localname : (const char*)localname);
   xmlreader->pop_namespaces();
}


}//end namespace xqp
