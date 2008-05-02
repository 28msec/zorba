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
#include <stdio.h>
#include <memory.h>
#include <string>
//#include <libxml/xmlmemory.h>

#include <zorba/store_consts.h>

#include "common/common.h"
#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "util/Assert.h"

//#include "store/naive/string_pool.h"
#include "store/minimal/min_store.h"
#include "store/minimal/min_loader.h"
#include "store/minimal/min_atomic_items.h"
#include "store/minimal/min_node_items.h"
#include "store/minimal/min_store_defs.h"
//#include "store/minimal/min_qname_pool.h"
#include "store/minimal/min_nsbindings.h"
#include "store/api/collection.h"
#include "zorbatypes/datetime.h"

#include "types/casting.h"
#include "context/namespace_context.h"
#include <string>
#include <stdarg.h>

namespace zorba { namespace store {

#ifndef NDEBUG

int traceLevel = 0;

#define LOADER_TRACE(level, msg)             \
{                                            \
  if (level <= traceLevel)                   \
    std::cout << msg << std::endl;           \
}

#define LOADER_TRACE1(msg) LOADER_TRACE(1, msg);
#define LOADER_TRACE2(msg) LOADER_TRACE(2, msg);
#define LOADER_TRACE3(msg) LOADER_TRACE(3, msg);

#else
#define LOADER_TRACE(msg)
#define LOADER_TRACE1(msg)
#define LOADER_TRACE2(msg)
#define LOADER_TRACE3(msg)
#endif

#define ZORBA_LOADER_CHECK_ERROR(loader) \
  do { \
    if (theErrorManager->hasErrors()) \
      return; \
  } while (0);

/*******************************************************************************

********************************************************************************/
XmlLoader::XmlLoader(error::ErrorManager* aErrorManager)
:
  theBaseUri(NULL),
  theDocUri(NULL),
  theTree(NULL),
  theRootNode(NULL),
  theErrorManager(aErrorManager)
{
  theOrdPath.init();

  //memset(&theSaxHandler, 0, sizeof(theSaxHandler) );
  //theSaxHandler.initialized = XML_SAX2_MAGIC;
  //theSaxHandler.startDocument = &XmlLoader::startDocument;
  //theSaxHandler.endDocument = &XmlLoader::endDocument;
  //theSaxHandler.startElementNs = &XmlLoader::startElement;
  //theSaxHandler.endElementNs = &XmlLoader::endElement;
  //theSaxHandler.characters = &XmlLoader::characters;
  //theSaxHandler.cdataBlock = &XmlLoader::cdataBlock;
  //theSaxHandler.comment = &XmlLoader::comment;
  //theSaxHandler.processingInstruction = &XmlLoader::processingInstruction;
  //theSaxHandler.warning = &XmlLoader::warning;
  //theSaxHandler.error = &XmlLoader::error;

  buff_size = 0;
  buff_pos = 0;
}


/*******************************************************************************

********************************************************************************/
XmlLoader::~XmlLoader()
{
  ///delete all remaining tags
  clear_tag_stack();
}

void XmlLoader::clear_tag_stack()
{
  std::list<TAG_ELEM*>::reverse_iterator    tag_it;

  for(tag_it = tag_stack.rbegin(); tag_it != tag_stack.rend(); tag_it++)
    delete (*tag_it);
  tag_stack.clear();
}

/*******************************************************************************
  Method called to do cleanup in case of errors.
********************************************************************************/
void XmlLoader::abort()
{
  theBaseUri = NULL;
  theDocUri = NULL;

  if (theTree != NULL)
  {
    delete theTree;
    theTree = NULL;
  }

  theOrdPath.init();
  theRootNode = NULL;

  while(!theNodeStack.empty())
  {
    XmlNode* node = theNodeStack.top();
    theNodeStack.pop();
    if (node != NULL)
      node->deleteTree();
  }

  while(!theBindingsStack.empty())
  {
    NsBindingsContext* ctx = theBindingsStack.top();
    theBindingsStack.pop();
    delete ctx;
  }

  theWarnings.clear();

  clear_tag_stack();

  buff_size = 0;
  buff_pos = 0;

}


/*******************************************************************************
  Method used to reset the loader so it can be used to load another document.
********************************************************************************/
void XmlLoader::reset()
{
  theBaseUri = NULL;
  theDocUri = NULL;

  theTree = NULL;
  theOrdPath.init();
  theRootNode = NULL;

  theNodeStack.pop();

  ZORBA_ASSERT(theNodeStack.empty());
  ZORBA_ASSERT(theBindingsStack.empty());

  theWarnings.clear();

  clear_tag_stack();

  buff_size = 0;
  buff_pos = 0;
}


/*******************************************************************************

********************************************************************************/
void XmlLoader::setRoot(XmlNode* root)
{
  theRootNode = root;
  theTree->setRoot(root);
}


/*******************************************************************************
  Read up to "size" bytes from the given input stream into the given buffer.
  Return the number of bytes actually read, throw an exception if any I/O
  error occured.
********************************************************************************/
//long XmlLoader::readPacket(std::istream& stream, char* buf, long size)
//{
//  try
//  {
//    stream.read(buf, size);
//
//    if (stream.bad())
//    {
//      ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
//                                ZorbaError::XQP0016_LOADER_IO_ERROR,
//                                "Input stream in bad state");
//    }
//
//    return stream.gcount();
//  }
//  catch (std::iostream::failure e)
//  {
//    ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
//                              ZorbaError::XQP0016_LOADER_IO_ERROR, e.what());
//  }
//  catch (...)
//  {
//    ZORBA_ERROR_DESC_CONTINUE(theErrorManager, 
//                              ZorbaError::XQP0016_LOADER_IO_ERROR,
//                              "Unknown exception");
//  }
//
//  return -1;
//}

int XmlLoader::read_char(std::istream &stream)
{
  if(buff_pos == buff_size)
  {
    stream.read(theBuffer, sizeof(theBuffer));
    buff_size = stream.gcount();
    if(!buff_size)
      return 0;
    buff_pos = 0;
  }
  prev_c = current_c;
  if(current_c)
  {
    current_c = 0;
    return prev_c;
  }
  prev_c = theBuffer[buff_pos++];
  return prev_c;
}

void XmlLoader::unread_char()
{
  current_c = prev_c;
}

bool XmlLoader::isWhitespace(int c)
{
  if((c == ' ') || (c == '\t') || (c == '\r') || (c == '\n'))
    return true;
  else
    return false;
}

bool XmlLoader::isNameChar(int c)
{
  if((c != '.') && (c != '-') && (c != '_') && (c != ':') &&
    !GenericCast::isLetter(c) && !GenericCast::isDigit(c) &&
    !GenericCast::isCombiningChar(c) && !GenericCast::isExtender(c))
    return false;
  else
    return true;
}

void XmlLoader::skip_whitespaces(std::istream &stream)
{
  int c;
  while(1)
  {
    c = read_char(stream);
    if(!isWhitespace(c))
    {
      unread_char();
      break;
    }
  }
}

#define READ_ATTRIBUTE_QNAME   true

bool XmlLoader::read_qname(std::istream &stream, QNAME_ELEM &qname, bool read_attr)
{
  int c;
  c = read_char(stream);
  if(c != ':')
  {
    if((c != '_') && !GenericCast::isLetter(c))
      return false;
    qname.localname = c;
    while(1)
    {
      c = read_char(stream);
      if(c == ':')
      {
        unread_char();
        break;
      }
      if(isWhitespace(c) || (read_attr && (c == '=')) || 
                            (!read_attr && ((c == '>') || (c == '/'))))
      {
        unread_char();
        break;
      }
      if((c != '.') && (c != '-') && (c != '_') &&
        !GenericCast::isLetter(c) && !GenericCast::isDigit(c) &&
        !GenericCast::isCombiningChar(c) && !GenericCast::isExtender(c))
        return false;
      qname.localname += c;
    }
  }
  else
    unread_char();

  c = read_char(stream);
  if(c != ':')
  {
    unread_char();
    return true;
  }

  qname.prefix = qname.localname;

  c = read_char(stream);
  if((c != '_') && !GenericCast::isLetter(c))
    return false;
  qname.localname = c;
  while(1)
  {
    c = read_char(stream);
    if(isWhitespace(c) || (read_attr && (c == '=')) || 
                          (!read_attr && ((c == '>') || (c == '/'))))
    {
      unread_char();
      break;
    }
    if((c != '.') && (c != '-') && (c != '_') &&
      !GenericCast::isLetter(c) && !GenericCast::isDigit(c) &&
      !GenericCast::isCombiningChar(c) && !GenericCast::isExtender(c))
      return false;
    qname.localname += c;
  }

  return true;
}

bool XmlLoader::read_attributes(std::istream &stream, attr_list_t &all_attributes)
{
  ATTR_ELEM   new_elem;
  int c;
  while(1)
  {
    //for each attribute
    all_attributes.push_back(new_elem);
    ATTR_ELEM   &last_attr = all_attributes.back();

    skip_whitespaces(stream);

    c = read_char(stream);
    unread_char();
    if(!c)
      return false;
    if((c == '>') || (c == '/'))
    {
      all_attributes.pop_back();
      unread_char();
      return true;
    }
    
    if(!read_qname(stream, last_attr.name, READ_ATTRIBUTE_QNAME))
      return false;

    skip_whitespaces(stream);

    c = read_char(stream);
    if(c != '=')
      return false;

    skip_whitespaces(stream);
    c = read_char(stream);
    if((c != '\'') && (c != '"'))
      return false;

    char  value_start = c;
    while(1)
    {
      c = read_char(stream);
      if(c == value_start)
        break;
      if(!c)
        return false;
      last_attr.attr_value += c;
    }
  }
  return true;
}

bool XmlLoader::fill_in_uri(std::string &prefix, std::string &result_uri)
{
  std::list<TAG_ELEM*>::reverse_iterator    tag_it;
  NsBindings::iterator      ns_it;

  for(tag_it = tag_stack.rbegin(); tag_it != tag_stack.rend();tag_it++)
  {
    for(ns_it=(*tag_it)->ns_bindings.begin(); ns_it != (*tag_it)->ns_bindings.end(); ns_it++)
    {
      if((*ns_it).first == prefix)
      {
        result_uri = (*ns_it).second;
        return true;
      }
    }
  }
  return false;
}

bool XmlLoader::compareQNames(QNAME_ELEM &name1, QNAME_ELEM &name2)
{
  if((name1.localname == name2.localname) &&
    (name1.uri == name2.uri))
    return true;
  else
    return false;
}

bool XmlLoader::read_tag(std::istream& stream)
{
  char  c;
  bool is_end_tag = false;

  c = read_char(stream);
  if(c != '<')
    return false;
  c = read_char(stream);
  if(c == '/')
    is_end_tag = true;
  else if(c == '!')
    return read_comment(stream);
  else if(c == '?')
    return read_pi(stream);
  else
    unread_char();

  skip_whitespaces(stream);

  TAG_ELEM*    tag_elem = new TAG_ELEM;

  if(!read_qname(stream, tag_elem->name, !READ_ATTRIBUTE_QNAME))
  {
    delete tag_elem;
    return false;
  }

  skip_whitespaces(stream);

  if(is_end_tag)
  {
    if(tag_stack.empty())
    {
      delete tag_elem;
      return false;///no tags to close
    }
    if(!fill_in_uri(tag_elem->name.prefix, tag_elem->name.uri) && !tag_elem->name.prefix.empty())
    {
      delete tag_elem;
      return false;
    }
    TAG_ELEM    *&last_tag = tag_stack.back();
    if(!compareQNames(last_tag->name, tag_elem->name))
    {
      delete tag_elem;
      return false;
    }

    delete tag_elem;

    skip_whitespaces(stream);
    c = read_char(stream);
    if(c != '>')
    {
      return false;
    }

    //notify as SAX event
    endElement(last_tag->name.localname.c_str(), last_tag->name.prefix.c_str(), last_tag->name.uri.c_str());

    delete last_tag;
    tag_stack.pop_back();
    return true;
  }

//  skip_whitespaces(stream);

  //read all attributes and namespaces in this tag
  attr_list_t   all_attributes;
  if(!read_attributes(stream, all_attributes))
  {
    delete tag_elem;
    return false;
  }

  tag_stack.push_back(tag_elem);

  //pick up the namespaces
  attr_list_t::iterator   attr_it, temp_it;
  std::pair<std::string, std::string> nsbind;
  for(attr_it = all_attributes.begin(); attr_it != all_attributes.end();)
  {
    if((*attr_it).name.localname == "xmlns")
    {
      if(!(*attr_it).name.prefix.empty())
        return false;///"xmlns" is the default namespace
      nsbind.first = "";
      nsbind.second = (*attr_it).attr_value;
      tag_elem->ns_bindings.push_back(nsbind);

      temp_it = attr_it;
      temp_it++;
      all_attributes.erase(attr_it);
      attr_it = temp_it;
      continue;
    }
    else if((*attr_it).name.prefix == "xmlns")
    {
      if(((*attr_it).name.localname == "xml") && ((*attr_it).attr_value != XML_NS))
        return false;
      if(((*attr_it).name.localname == "xs") && ((*attr_it).attr_value != XML_SCHEMA_NS))
        return false;
      if(((*attr_it).name.localname == "xsi") && ((*attr_it).attr_value != XSI_NS))
        return false;
      if((*attr_it).name.localname == "xmlns")
        return false;

      nsbind.first =  (*attr_it).name.localname;
      nsbind.second = (*attr_it).attr_value;
      tag_elem->ns_bindings.push_back(nsbind);

      temp_it = attr_it;
      temp_it++;
      all_attributes.erase(attr_it);
      attr_it = temp_it;
      continue;
    }
    attr_it++;
  }

  //fill in the uri part of tag elem and attributes
  if(!fill_in_uri(tag_elem->name.prefix, tag_elem->name.uri) && !tag_elem->name.prefix.empty())
    return false;

  //fill in the uri part of attributes, if they have prefix
  for(attr_it = all_attributes.begin(); attr_it != all_attributes.end(); attr_it++)
  {
    if(!(*attr_it).name.prefix.empty() &&
        !fill_in_uri((*attr_it).name.prefix, (*attr_it).name.uri))
      return false;
  }

  //send start_element SAX notification
  const char  **namespaces = NULL;
  int   ns_size;
  const char  **attributes = NULL;
  int   attr_size;

  ns_size = tag_elem->ns_bindings.size();
  if(ns_size)
  {
    namespaces = new const char*[ns_size*2];
    for(int i=0; i<ns_size;i++)
    {
      namespaces[i*2] = tag_elem->ns_bindings[i].first.c_str();
      namespaces[i*2+1] = tag_elem->ns_bindings[i].second.c_str();
    }
  }
  attr_size = all_attributes.size();
  if(attr_size)
  {
    attributes = new const char*[attr_size*5];
//      const char* lname = reinterpret_cast<const char*>(attributes[index]);
//      const char* prefix = reinterpret_cast<const char*>(attributes[index+1]);
//      const char* uri = reinterpret_cast<const char*>(attributes[index+2]);
//      const char* valueBegin = reinterpret_cast<const char*>(attributes[index+3]);
//      const char* valueEnd = reinterpret_cast<const char*>(attributes[index+4]);
    int i=0;
    for(attr_it = all_attributes.begin(); attr_it != all_attributes.end(); attr_it++, i++)
    {
      attributes[i*5] = (*attr_it).name.localname.c_str();
      attributes[i*5+1] = (*attr_it).name.prefix.c_str();
      attributes[i*5+2] = (*attr_it).name.uri.c_str();
      attributes[i*5+3] = (*attr_it).attr_value.c_str();
      attributes[i*5+4] = (*attr_it).attr_value.c_str() + (*attr_it).attr_value.length();
    }
  }

  startElement(tag_elem->name.localname.c_str(),
              tag_elem->name.prefix.c_str(),
              tag_elem->name.uri.c_str(),
              ns_size,
              namespaces,
              attr_size,
              0,
              attributes);

  delete [] namespaces;
  delete [] attributes;

  c = read_char(stream);
  if(c == '/')
  {
    c = read_char(stream);
    if(c != '>')
      return false;
    ///end this tag
    //notify as SAX event
    endElement(tag_elem->name.localname.c_str(), tag_elem->name.prefix.c_str(), tag_elem->name.uri.c_str());

    delete tag_elem;
    tag_stack.pop_back();
  }

  return true;
}

bool XmlLoader::read_characters(std::istream &stream, bool *end_document)
{
  int c;
  std::string chars;

  *end_document = false;
  while(1)
  {
    c = read_char(stream);
    if(!c)
    {
      *end_document = true;
      if(!chars.empty())
      {
        for(int i=0; i < chars.length(); i++)
          if(!isWhitespace(chars[i]))
            return false;
        return true;
      }
      else
        return true;
    }
    if(c == '<')
    {
      unread_char();
      break;
    }
    chars += c;
  }


  //send characters as SAX event
  characters(chars.c_str(), chars.length());

  return true;
}

bool XmlLoader::read_comment(std::istream &stream)
{
  int c;
  std::string comment_str;

  c = read_char(stream);
  if(c != '-')
    return false;
  c = read_char(stream);
  if(c != '-')
    return false;

  while(1)
  {
    c = read_char(stream);
    if(!c)
      return false;
    if(c == '-')
    {
      c = read_char(stream);
      if(c != '-')
      {
        comment_str += '-';
        comment_str += c;
        continue;
      }
      c = read_char(stream);
      if(c != '>')
        return false;
      break;
    }
    comment_str += c;
  }


  //send comment as SAX event
  comment(comment_str.c_str());

  return true;
}

bool XmlLoader::read_pi(std::istream &stream)
{
  int c;
  std::string pitarget;
  std::string pidata;

  c = read_char(stream);
  if(!((c == '_') || (c == ':') || GenericCast::isLetter(c)))
    return false;
  pitarget = c;
  while(1)
  {
    c = read_char(stream);
    if(isWhitespace(c))
      break;
    if(c == '?')
      break;
    if(!isNameChar(c))
      return false;
    pitarget += c;
  }

  if((pitarget.length() == 3) &&
    (tolower(pitarget[0]) == 'x') &&
    (tolower(pitarget[1]) == 'm') &&
    (tolower(pitarget[2]) == 'l'))
    return false;

  if(c != '?')
  {
    //read pi data
    skip_whitespaces(stream);
    while(1)
    {
      c = read_char(stream);
      if(!c)
        return false;
      if(c == '?')
      {
        c = read_char(stream);
        if(c == '>')
          break;
        pidata += '?';
      }
      pidata += c;
    }
  }
  else
  {
    c = read_char(stream);
    if(c != '>')
      return false;
  }

  //send Processing Instruction as SAX event
  processingInstruction(pitarget.c_str(), pidata.c_str());

  return true;
}

/*******************************************************************************

********************************************************************************/
XmlNode* XmlLoader::loadXml(xqpStringStore_t& uri, std::istream& stream)
{
  bool  end_document = false;
  theDocUri.transfer(uri);
  theTree = new XmlTree(NULL, GET_STORE().getTreeId());
  prev_c = 0;
  current_c = 0;

  startDocument();

  skip_whitespaces(stream);
  while(!end_document)
  {
    if(!read_tag(stream))
    {
      endDocument();
      ZORBA_ERROR_PARAM_CONTINUE_OSS(theErrorManager,
                                     ZorbaError::XQP0017_LOADER_PARSING_ERROR,
                                     "The document with URI " << *theDocUri
                                     <<" is not well formed", "");
      abort();
      return NULL;
    }
    if(!read_characters(stream, &end_document))
    {
       endDocument();
      ZORBA_ERROR_PARAM_CONTINUE_OSS(theErrorManager,
                                     ZorbaError::XQP0017_LOADER_PARSING_ERROR,
                                     "The document with URI " << *theDocUri
                                     <<" is not well formed", "");
      abort();
      return NULL;
    }
  }

  endDocument();
  if(!tag_stack.empty())
  {
    ZORBA_ERROR_PARAM_CONTINUE_OSS(theErrorManager,
                                   ZorbaError::XQP0017_LOADER_PARSING_ERROR,
                                   "The document with URI " << *theDocUri
                                   <<" is not well formed", "");
    abort();
    return NULL;
  }

/*  xmlParserCtxtPtr ctxt = NULL;
  long numChars;

  theDocUri = uri;

  theTree = new XmlTree(NULL, GET_STORE().getTreeId());

  try
  {
    numChars = readPacket(stream, theBuffer, 4096);

    if (numChars < 0)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager, 
                                ZorbaError::XQP0016_LOADER_IO_ERROR,
                                "Unknown I/O error");
      abort();
      return NULL;
    }
    else if (numChars == 0)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager, 
                                ZorbaError::XQP0016_LOADER_IO_ERROR,
                                "No input data.");
      abort();
      return NULL;
    }

    ctxt = xmlCreatePushParserCtxt(&theSaxHandler, this, theBuffer, numChars, NULL);

    if (ctxt == NULL)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                                ZorbaError::XQP0017_LOADER_PARSING_ERROR, 
                                "Failed to initialize parser");
      abort();
			return NULL;
    }

    while ((numChars = readPacket(stream, theBuffer, 4096)) > 0)
    {
      xmlParseChunk(ctxt, theBuffer, numChars, 0);
    }

    if (numChars < 0)
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                                ZorbaError::XQP0016_LOADER_IO_ERROR,
                                "Unknown I/O error");
      xmlFreeParserCtxt(ctxt);
      abort();
      return NULL;
    }

    xmlParseChunk(ctxt, theBuffer, 0, 1);
  }
  catch(...)
  {
    xmlFreeParserCtxt(ctxt);
    abort();
    return NULL;
  }

  bool ok = ctxt->wellFormed != 0;

  xmlFreeParserCtxt(ctxt);

  if (!ok)
  {
    if (theDocUri != NULL)
    {
      ZORBA_ERROR_PARAM_CONTINUE_OSS(theErrorManager,
                                     ZorbaError::XQP0017_LOADER_PARSING_ERROR,
                                     "The document with URI " << *theDocUri
                                     <<" is not well formed", "");
    }
    else
    {
      ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                                ZorbaError::XQP0017_LOADER_PARSING_ERROR,
                                "Not well formed XML");
    }

    abort();
    return NULL;
  }
*/

  XmlNode* resultNode = theRootNode;
  reset();
  return resultNode;
}


/*******************************************************************************
  SAX2 callback when the start of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void XmlLoader::startDocument()
{
//  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));
//  ZORBA_LOADER_CHECK_ERROR(loader);

  xqpStringStore_t docUri = theDocUri;
  xqpStringStore_t baseUri = theBaseUri;
  if (docUri == NULL)
  {
    std::ostringstream uristream;
    uristream << "zorba://internalDocumentURI-" << theTree->getId();

    docUri = new xqpStringStore(uristream.str().c_str());
  }

  LoadedDocumentNode* docNode = new LoadedDocumentNode(baseUri, docUri);

  setRoot(docNode);
  theNodeStack.push(docNode);
  theNodeStack.push(NULL);

  SYNC_CODE(docNode->theRCLockPtr = &theTree->getRCLock();)
  docNode->setId(theTree, &theOrdPath);
  theOrdPath.pushChild();

  LOADER_TRACE1("Start Doc Node = " << docNode);
}


/*******************************************************************************
  SAX2 callback when the end of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void XmlLoader::endDocument()
{
//  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));
//  ZORBA_LOADER_CHECK_ERROR(loader);

  // This check is required because it is possible (in case of mal-formed doc)
  // that libXml calls endDocument() without having called startDocument().
  if (theNodeStack.size() == 0 )
    return;
  
  std::vector<XmlNode*> revChildNodes;

  XmlNode* childNode = theNodeStack.top();

  while (childNode != NULL)
  {
    revChildNodes.push_back(childNode);
    theNodeStack.pop();
    childNode = theNodeStack.top();
  }
  theNodeStack.pop();

  LoadedDocumentNode* docNode = dynamic_cast<LoadedDocumentNode*>(theNodeStack.top());
  ZORBA_ASSERT(docNode != NULL);

  NodeVector& children = docNode->children();
  children.resize(revChildNodes.size());

  std::vector<XmlNode*>::const_reverse_iterator it;
  ulong i = 0;
  for (it = revChildNodes.rbegin();
       it != (std::vector<XmlNode*>::const_reverse_iterator)revChildNodes.rend();
       it++, i++)
  {
    children.set(*it, i, false);
    (*it)->setParent(docNode);
  }

  LOADER_TRACE2("End Doc Node = " << docNode);
}


/*******************************************************************************
  SAX2 callback when an element start has been detected by the parser. It
  provides the expanded qname of the element, as well as the new namespace
  declarations on the element (if any).

  ctx:           the user data (XML parser context)
  localname:     the local name of the element
  prefix:        the element namespace prefix if available
  URI:           the element namespace name if available
  nb_namespaces: number of namespace definitions on that node
  namespaces:    pointer to the array of prefix/URI pairs namespace definitions
  nb_attributes: the number of attributes on that node
  nb_defaulted:  the number of defaulted attributes. The defaulted ones are at
                 the end of the array
 attributes:     pointer to the array of (localname/prefix/URI/value/end)
                 attribute values.
********************************************************************************/
void XmlLoader::startElement(
    const char * lname, 
    const char * prefix, 
    const char * uri,
    int numNamespaces,
    const char ** namespaces,
    int numAttrs, 
    int numDefaulted, 
    const char ** attributes)
{
  SimpleStore& store = GET_STORE();
//  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));
//  ZORBA_LOADER_CHECK_ERROR(loader);
//  QNamePool& qnpool = store.getQNamePool();

  ulong numAttributes = (ulong)numAttrs;
  ulong numBindings = (ulong)numNamespaces;

  // Construct node name and type
//  Item_t qname = qnpool.insert(reinterpret_cast<const char*>(uri),
//                               reinterpret_cast<const char*>(prefix),
//                               reinterpret_cast<const char*>(lname));
  Item_t  qname = new QNameItemImpl(reinterpret_cast<const char*>(uri),
                                   reinterpret_cast<const char*>(prefix),
                                   reinterpret_cast<const char*>(lname));
  Item_t tname = store.theSchemaTypeNames[XS_UNTYPED];

  // Create the element node and push it to the node stack
  LoadedElementNode* elemNode = new LoadedElementNode(qname,
                                                      tname,
                                                      numBindings,
                                                      numAttributes);
  if (theNodeStack.empty())
    setRoot(elemNode);

  theNodeStack.push(elemNode);
  theNodeStack.push(NULL);

  // Assign the current node id to this node, and compute the next node id.
  elemNode->setId(theTree, &theOrdPath);
  theOrdPath.pushChild();

  SYNC_CODE(elemNode->theRCLockPtr = &theTree->getRCLock();)

  LOADER_TRACE1("Start Element: node = " << elemNode << " name = ["
                << (prefix != NULL ? prefix : (char*)"") << ":" << lname
                << " (" << (uri != NULL ? uri : (char*)"NULL") << ")]"
                << std::endl << " ordpath = " << elemNode->getOrdPath().show()
                << std::endl);

  // Process namespace bindings
  if (numBindings > 0)
  {
    NsBindings& bindings = elemNode->getNsContext()->getBindings();

    for (ulong i = 0; i < numBindings; ++i)
    {
      const char* prefix = reinterpret_cast<const char*>(namespaces[i * 2]);
      const char* nsuri = reinterpret_cast<const char*>(namespaces[i * 2 + 1]);

      if (prefix == NULL)
        prefix = "";

      xqpStringStore_t pooledNs;
//      store.getNamespacePool().insertc(nsuri, pooledNs);
      pooledNs = new xqpStringStore(nsuri);

      bindings[i].first = prefix;
      bindings[i].second = pooledNs.getp();

      LOADER_TRACE1("namespace decl: [" << prefix  << ":" << nsuri << "]");
    }

    theBindingsStack.push(elemNode->getNsContext());
  }

  // Process attributes
  if (numAttributes > 0)
  {
    NodeVector& attrNodes = elemNode->attributes();

    ulong index = 0;
    for (ulong i = 0; i < numAttributes; ++i, index += 5)
    {
      const char* lname = reinterpret_cast<const char*>(attributes[index]);
      const char* prefix = reinterpret_cast<const char*>(attributes[index+1]);
      const char* uri = reinterpret_cast<const char*>(attributes[index+2]);
      const char* valueBegin = reinterpret_cast<const char*>(attributes[index+3]);
      const char* valueEnd = reinterpret_cast<const char*>(attributes[index+4]);

      //Item_t qname = qnpool.insert(uri, prefix, lname);
      Item_t  qname = new QNameItemImpl(uri, prefix, lname);
      xqpStringStore_t value = new xqpStringStore(valueBegin, valueEnd);

      Item_t typeName = store.theSchemaTypeNames[XS_UNTYPED_ATOMIC];
      Item_t typedValue = new UntypedAtomicItemImpl(value);

      AttributeNode* attrNode = new AttributeNode(qname, typeName, false);
      attrNode->theParent = elemNode;
      attrNode->setId(theTree, &theOrdPath);
      attrNode->theTypedValue.transfer(typedValue);

      attrNodes.set(attrNode, i, false);

      theOrdPath.nextChild();

      SYNC_CODE(attrNode->theRCLockPtr = &theTree->getRCLock();)

      LOADER_TRACE1("Attribute: node = " << attrNode
                    << " name [" << (prefix != NULL ? prefix : "") << ":"
                    << lname << " (" << (uri != NULL ? uri : "NULL") << ")]"
                    << " value = " << value->c_str() << std::endl
                    << " ordpath = " << attrNode->getOrdPath().show() << std::endl);
    }
  }
}

  
/*******************************************************************************
  SAX2 callback when an element end has been detected by the parser. It
  provides the expanded qname of the element.

  ctx:       the user data (XML parser context)
  localname: the local name of the element
  prefix:    the element namespace prefix if available
  URI:       the element namespace name if available
********************************************************************************/
void  XmlLoader::endElement(
    const char * localName, 
    const char * prefix, 
    const char * uri)
{
//  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));
//  ZORBA_LOADER_CHECK_ERROR(loader);

  // Collect the children of this element node from the node stack
  std::vector<XmlNode*> revChildNodes;

  XmlNode* prevChild = NULL;
  XmlNode* currChild = theNodeStack.top();
  while (currChild != NULL)
  {
    if (currChild->getNodeKind() == StoreConsts::textNode &&
        prevChild != NULL &&
        prevChild->getNodeKind() == StoreConsts::textNode)
    {
      prevChild->getStringValueP()->str() = currChild->getStringValueP()->str() +
                                            prevChild->getStringValueP()->str();
      delete currChild;
    }
    else
    {
      revChildNodes.push_back(currChild);
      prevChild = currChild;
    }

    theNodeStack.pop();
    currChild = theNodeStack.top();
  }
  theNodeStack.pop();

  // The element node is now at the top of the stack
  LoadedElementNode* elemNode = dynamic_cast<LoadedElementNode*>(theNodeStack.top());
  ZORBA_ASSERT(elemNode != NULL);

  LOADER_TRACE2("End Element: node = " << elemNode << " name ["
                << (prefix != NULL ? prefix : (char*)"") << ":" << localName
                << " (" << (uri != NULL ? uri : (char*)"NULL") << ")]");

  // For each child, make this element node its parent and fix its namespace
  // bindings context. Note: the children were popped from the stack in reverse
  // order, so we copy them into the element node in the correct order.
  NodeVector& children = elemNode->children();
  children.resize(revChildNodes.size());

  std::vector<XmlNode*>::const_reverse_iterator it;
  ulong i = 0;
  for (it = revChildNodes.rbegin();
       it != (std::vector<XmlNode*>::const_reverse_iterator)revChildNodes.rend();
       it++, i++)
  {
    currChild = *it;

    children.set(currChild, i, false);
    currChild->setParent(elemNode);

    if (currChild->getNodeKind() == StoreConsts::elementNode)
    {
      if (!theBindingsStack.empty())
        currChild->setNsContext(theBindingsStack.top());
      else
        currChild->setNsContext(NULL);
    }
  }

  if (elemNode->getNsContext() != NULL)
  {
    theBindingsStack.pop();
  }

  // Adjust the dewey id
  theOrdPath.popChild();
}


/*******************************************************************************
  SAX2 callback when xml text has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a char string
  len: the number of char
********************************************************************************/
void XmlLoader::characters( const char * ch, int len)
{
//  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
//  ZORBA_LOADER_CHECK_ERROR(loader);

  const char* charp = reinterpret_cast<const char*>(ch);
  xqpStringStore_t content(new xqpStringStore(charp, len));

  XmlNode* textNode = new TextNode(content);

  if (theNodeStack.empty())
    setRoot(textNode);

  theNodeStack.push(textNode);

  textNode->setId(theTree, &theOrdPath);
  theOrdPath.nextChild();

  SYNC_CODE(textNode->theRCLockPtr = &theTree->getRCLock();)

  LOADER_TRACE1("Text Node = " << textNode << " content = "
                << std::string(charp, len) << std::endl << " ordpath = "
                << textNode->getOrdPath().show() << std::endl);
}


/*******************************************************************************
  SAX2 callback when a CDATA block has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a char string
  len: the number of char
********************************************************************************/
void XmlLoader::cdataBlock( const char * ch, int len)
{
//  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
//  ZORBA_LOADER_CHECK_ERROR(loader);

  const char* charp = reinterpret_cast<const char*>(ch);
  xqpStringStore_t content(new xqpStringStore(charp, len));

  XmlNode* textNode = new TextNode(content);

  if (theNodeStack.empty())
    setRoot(textNode);

  theNodeStack.push(textNode);

  textNode->setId(theTree, &theOrdPath);
  theOrdPath.nextChild();

  SYNC_CODE(textNode->theRCLockPtr = &theTree->getRCLock();)
 
  LOADER_TRACE1("Text Node = " << textNode << " content = "
                << std::string(charp, len) << std::endl << " ordpath = "
                << textNode->getOrdPath().show() << std::endl);
}


/*******************************************************************************
  SAX2 callback when a processing instruction has been detected by the parser.

  ctx: the user data (XML parser context)

********************************************************************************/
void XmlLoader::processingInstruction(
    const char * targetp, 
    const char * data)
{
//  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
//  ZORBA_LOADER_CHECK_ERROR(loader);

  xqpStringStore_t content = new xqpStringStore(reinterpret_cast<const char*>(data));
  xqpStringStore_t target = new xqpStringStore(reinterpret_cast<const char*>(targetp));

  XmlNode* piNode = new PiNode(target, content);

  if (theNodeStack.empty())
    setRoot(piNode);

  theNodeStack.push(piNode);

  piNode->setId(theTree, &theOrdPath);
  theOrdPath.nextChild();

  SYNC_CODE(piNode->theRCLockPtr = &theTree->getRCLock();)

  LOADER_TRACE1("Pi Node = " << piNode << " target = "
                << targetp << std::endl << " ordpath = "
                << piNode->getOrdPath().show() << std::endl);
}


/*******************************************************************************
  SAX2 callback when a comment has been detected by the parser.

  ctx: the user data (XML parser context)
  content:  the comment content
********************************************************************************/
void XmlLoader::comment(const char * ch)
{
//  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
//  ZORBA_LOADER_CHECK_ERROR(loader);

  const char* charp = reinterpret_cast<const char*>(ch);
  xqpStringStore_t content(new xqpStringStore(charp));

  XmlNode* commentNode = new CommentNode(content);

  if (theNodeStack.empty())
    setRoot(commentNode);

  theNodeStack.push(commentNode);

  commentNode->setId(theTree, &theOrdPath);
  theOrdPath.nextChild();

  SYNC_CODE(commentNode->theRCLockPtr = &theTree->getRCLock();)

  LOADER_TRACE1("Comment Node = " << commentNode << " content = "
                << charp << std::endl << " ordpath = "
                << commentNode->getOrdPath().show() << std::endl);
}


/*******************************************************************************
  Display and format an error messages, callback.
 
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  XmlLoader::error(const char * msg, ... )
{
//  XmlLoader* loader = (static_cast<XmlLoader *>(ctx));
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);
  ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                            ZorbaError::XQP0017_LOADER_PARSING_ERROR, buf);
}


/*******************************************************************************
   Display and format a warning messages, callback.
  
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  XmlLoader::warning(const char * msg, ... )
{
//  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);
  if (!theWarnings.empty())
    theWarnings += "+ ";
  theWarnings += buf;
}

#undef ZORBA_ERROR_DESC_CONTINUE

} // namespace store
} // namespace zorba
