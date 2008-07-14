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

#include "zorbamisc/config/platform.h"
#include "zorbaerrors/error_manager.h"
//#include "system/globalenv.h"
#include "zorbaerrors/Assert.h"

#include "store/minimal/min_store.h"
#include "store/minimal/min_loader.h"
#include "store/minimal/min_node_vector.h"
#include "store/minimal/string_pool.h"
#include "store/minimal/min_nsbindings.h"
#include "store/minimal/min_store_defs.h"
#include "store/api/collection.h"
#include "store/api/item_factory.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/chartype.h"

//#include "context/static_context.h"
#include "zorbamisc/ns_consts.h"

//#include "types/casting.h"
//#include "context/namespace_context.h"
#include <string>
#include <stdarg.h>

namespace zorba { namespace storeminimal {

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
    if (loader.theErrorManager && loader.theErrorManager->hasErrors()) \
      return; \
  } while (0);

xqpString   g_empty_string;
xqpString   g_xml_ns(XML_NS);
xqpString   g_xml_schema_ns(XML_SCHEMA_NS);
xqpString   g_xsi_ns(XSI_NS);



mystring::mystring(int grow_by)
{
  this->grow_by = grow_by;
  buff = prealloc_buff;
  buff_total = sizeof(prealloc_buff)-1;
  buff_written = 0;
}

mystring::~mystring()
{
  if(buff != prealloc_buff)
    free(buff);
}

void mystring::clear()
{
  buff_written = 0;
}

void mystring::append(char c)
{
  if(buff_written >= buff_total)
  {
    //realloc
    buff_total += grow_by;
    if(buff != prealloc_buff)
      buff = (char*)realloc(buff, buff_total+1);
    else
    {
      buff = (char*)malloc(buff_total+1);
      memcpy(buff, prealloc_buff, buff_written);
    }
  }
  buff[buff_written++] = c;
}

int   mystring::length()
{
  return buff_written;
}

const char *mystring::c_str()
{
  buff[buff_written] = 0;
  return buff;
}

bool mystring::empty()
{
  return buff_written == 0;
}

bool mystring::byteEqual(const char *str, int str_len)
{
  if(str_len != buff_written)
    return false;
  buff[buff_written] = 0;
  return !memcmp(buff, str, str_len);
}


/*******************************************************************************

********************************************************************************/
XmlLoader::XmlLoader(store::ItemFactory *factory, error::ErrorManager* aErrorManager)
:
  theFactory(factory),
  theBaseUri(NULL),
  theDocUri(NULL),
  theRootNode(NULL),
  theErrorManager(aErrorManager),
  store(GET_STORE()),
  namespacePool(store.getNamespacePool()),
  temp_buff(1024)
{
  //temp_buff.reserve(1024);

  buff_size = 0;
  buff_pos = 0;
  stream = NULL;

  elem_attrs.reserve(10);

}


/*******************************************************************************

********************************************************************************/
XmlLoader::~XmlLoader()
{
  ///delete all remaining tags
  clear_tag_stack();

  delete stream;
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
void XmlLoader::abortload()
{
  theBaseUri = NULL;
  theDocUri = NULL;

  if(theRootNode != NULL)
    theRootNode->getTree()->attachedloader = NULL;
  theRootNode = NULL;

  theWarnings.clear();

  clear_tag_stack();

  buff_size = 0;
  buff_pos = 0;

}



int XmlLoader::read_char()
{
  if(current_c)
  {
    prev_c = current_c;
    current_c = 0;
    return prev_c;
  }
  if(buff_pos == buff_size)
  {
    if(buff_size && (buff_size < sizeof(theBuffer)))
      return 0;
    stream->read(theBuffer, sizeof(theBuffer));
    buff_size = stream->gcount();
    if(!buff_size)
      return 0;
    buff_pos = 0;
  }
  prev_c = (unsigned char)theBuffer[buff_pos++];
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
    !XQCharType::isLetter(c) && !XQCharType::isDigit(c) &&
    !XQCharType::isCombiningChar(c) && !XQCharType::isExtender(c))
    return false;
  else
    return true;
}

void XmlLoader::skip_whitespaces()
{
  int c;
  while(1)
  {
    c = read_char();
    if(!isWhitespace(c))
    {
      unread_char();
      break;
    }
  }
}

#define READ_ATTRIBUTE_QNAME   true

bool XmlLoader::read_qname(QNAME_ELEM &qname, bool read_attr)
{
  int c;
  int localpos = 0;
  qname.uri = g_empty_string.theStrStore;
  c = read_char();
  if(c != ':')
  {
    if((c != '_') && !XQCharType::isLetter(c))
      return false;
    //qname.localname = new xqpStringStore;
    //qname.localname->append_in_place(c);
    qname.localname[localpos++] = c;
    while(1)
    {
      c = read_char();
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
        !XQCharType::isLetter(c) && !XQCharType::isDigit(c) &&
        !XQCharType::isCombiningChar(c) && !XQCharType::isExtender(c))
        return false;
      //qname.localname->append_in_place(c);
      qname.localname[localpos++] = c;
    }
  }
  else
    unread_char();

  qname.localname[localpos] = 0;
  qname.localname_len = localpos;
  c = read_char();
  if(c != ':')
  {
    //qname.prefix = g_empty_string.theStrStore;
    qname.prefix_len = 0;
    qname.prefix[0] = 0;
    unread_char();
    return true;
  }

  //qname.prefix = new xqpStringStore(qname.localname);
  strcpy(qname.prefix, qname.localname);
  qname.prefix_len = qname.localname_len;
  localpos = 0;

  c = read_char();
  if((c != '_') && !XQCharType::isLetter(c))
    return false;
  //qname.localname = new xqpStringStore;
  //qname.localname->append_in_place(c);
  qname.localname[localpos++] = c;
  while(1)
  {
    c = read_char();
    if(isWhitespace(c) || (read_attr && (c == '=')) || 
                          (!read_attr && ((c == '>') || (c == '/'))))
    {
      unread_char();
      break;
    }
    if((c != '.') && (c != '-') && (c != '_') &&
      !XQCharType::isLetter(c) && !XQCharType::isDigit(c) &&
      !XQCharType::isCombiningChar(c) && !XQCharType::isExtender(c))
      return false;
    //qname.localname->append_in_place(c);
    qname.localname[localpos++] = c;
  }
  qname.localname[localpos] = 0;
  qname.localname_len = localpos;

  return true;
}

bool XmlLoader::read_attributes(store::NsBindings *nsbindings,//ElementTreeNode *elemNode,
                              attr_list_t& attrs)
{
  ATTR_ELEM   attr;
  int c;
  while(1)
  {
    //for each attribute and namespace

    skip_whitespaces();

    c = read_char();
    unread_char();
    if(!c)
      return false;
    if((c == '>') || (c == '/') || (reading_prolog && (c == '?')))
    {
      break;
    }
    
    if(!read_qname(attr.name, READ_ATTRIBUTE_QNAME))
      return false;

    skip_whitespaces();

    c = read_char();
    if(c != '=')
      return false;

    skip_whitespaces();
    c = read_char();
    if((c != '\'') && (c != '"'))
      return false;

    //attr.value = new xqpStringStore(10);
    temp_buff.clear();
    char  value_start = c;
    while(1)
    {
      c = read_char();
      if(c == value_start)
        break;
      if(!c)
        return false;
      //attr.value->append_in_place(c);
      temp_buff.append(c);
    }


    //pick up the namespaces
    if((attr.name.localname_len == 5) && !strcmp(attr.name.localname, "xmlns"))
    {
      //if(!attr.name.prefix->empty())
      if(attr.name.prefix[0])
        return false;///"xmlns" is the default namespace
    //  nsbind.first = "";
    //  nsbind.second = attr_value.getp();
    //  if(nscontext == NULL)
    //    nscontext = new NsBindingsContext;
    //  store::NsBindings& bindings = nscontext->getBindings();
    //  bindings.push_back(nsbind);
      if(nsbindings)
      {
        xqpStringStore_t pooledNs;
        namespacePool.insertc(temp_buff.c_str(), pooledNs);
        //elemNode->addLocalBinding(g_empty_string.getStore(), 
        //                          pooledNs.getp());
        nsbindings->push_back(std::pair<xqpString, xqpString>(g_empty_string.getStore(), pooledNs.getp()));
      }
    }
    //else if((attr.name.prefix != NULL) && attr.name.prefix->byteEqual("xmlns"))
    else if((attr.name.prefix_len == 5) && !strcmp(attr.name.prefix, "xmlns"))
    {
      if((attr.name.localname_len == 3) && (!strcmp(attr.name.localname, "xml")) && (!temp_buff.byteEqual(XML_NS, sizeof(XML_NS)-1)))
        return false;
      if((attr.name.localname_len == 2) && (!strcmp(attr.name.localname, "xs")) && (!temp_buff.byteEqual(XML_SCHEMA_NS, sizeof(XML_SCHEMA_NS)-1)))
        return false;
      if((attr.name.localname_len == 3) && (!strcmp(attr.name.localname, "xsi")) && (!temp_buff.byteEqual(XSI_NS, sizeof(XSI_NS)-1)))
        return false;
      if((attr.name.localname_len == 5) && !strcmp(attr.name.localname, "xmlns"))
        return false;

    //  nsbind.first =  name.localname.getp();
    //  nsbind.second = attr_value.getp();
    //  if(nscontext == NULL)
    //    nscontext = new NsBindingsContext;
    //  store::NsBindings& bindings = nscontext->getBindings();
    //  bindings.push_back(nsbind);
      if(nsbindings)
      {
        xqpStringStore_t pooledNs;
        namespacePool.insertc(temp_buff.c_str(), pooledNs);
       // elemNode->addLocalBinding(new xqpStringStore(attr.name.localname),
       //                           pooledNs.getp());
        nsbindings->push_back(std::pair<xqpString, xqpString>(new xqpStringStore(attr.name.localname), pooledNs.getp()));
      }
    }
    else
    {
      attr.value = new xqpStringStore(temp_buff.c_str(), temp_buff.length());
      attrs.push_back(attr);
    }

  }
//  if(elemNode)
//    elemNode->setNsContext(nscontext);
  return true;
}

bool XmlLoader::fill_in_uri(store::NsBindings  *nsbindings,
                            char *prefix, int prefix_len, xqpStringStore_t &result_uri)
{
  if(nsbindings)
  {
    store::NsBindings::iterator      ns_it;

    for(ns_it=nsbindings->begin(); ns_it != nsbindings->end(); ns_it++)
    {
      if((*ns_it).first.byteEqual(prefix, prefix_len))
      {
        result_uri = (*ns_it).second.getStore();
        return true;
      }
    }
  }
  std::list<TAG_ELEM*>::reverse_iterator    tag_it;
  store::NsBindings::iterator      ns_it;

  for(tag_it = tag_stack.rbegin(); tag_it != tag_stack.rend();tag_it++)
  {
    ElementTreeNode       *elemNode = (*tag_it)->elemNode;
    NsBindingsContext     *ns_context = elemNode->getNsContext();
    if(!ns_context)
      continue;
    store::NsBindings  &ns_bindings = ns_context->getBindings();
    for(ns_it=ns_bindings.begin(); ns_it != ns_bindings.end(); ns_it++)
    {
      if((*ns_it).first.byteEqual(prefix, prefix_len))
      {
        result_uri = (*ns_it).second.getStore();
        return true;
      }
    }
  }

  //result_uri = elemNode->findBinding(prefix);
/*  result_uri = NULL;
  const NsBindingsContext* currentContext = elemNode->getNsContext();

  while (currentContext != NULL)
  {
    const store::NsBindings& bindings = currentContext->getBindings();
    ulong numBindings = bindings.size();

    for (ulong i = 0; i < numBindings; i++)
    {
      if (bindings[i].first.getStore()->byteEqual(prefix))
      {
        result_uri = bindings[i].second.getStore();
        break;
      }
    }

    currentContext = currentContext->getParent();
  }

 */
  //if(result_uri != NULL)
  //  return true;


  ///look into default namespaces
  if((prefix_len == 3) && !strcmp(prefix, "xml"))
  {
    result_uri = g_xml_ns.getStore();
    return true;
  }
  if((prefix_len == 2) && !strcmp(prefix, "xs"))
  {
    result_uri = g_xml_schema_ns.getStore();
    return true;
  }
  if((prefix_len == 3) && !strcmp(prefix, "xsi"))
  {
    result_uri = g_xsi_ns.getStore();
    return true;
  }

  result_uri = g_empty_string.theStrStore;
  return false;
}

bool XmlLoader::compareQNames(QNAME_ELEM &name1, QNAME_ELEM &name2)
{
  if(name1.localname_len != name2.localname_len)
    return false;
  if((!strcmp(name1.localname, name2.localname)) &&
    (name1.uri->byteEqual(*name2.uri)))
    return true;
  else
    return false;
}

bool XmlLoader::read_tag()
{
  char  c;
  is_end_tag = 0;

  c = read_char();
  if(c != '<')
    return false;
  c = read_char();
  if(c == '/')
    is_end_tag = 1;
  else if(c == '!')
    return read_comment();
  else if(c == '?')
    return read_pi();
  else
    unread_char();

  skip_whitespaces();

  TAG_ELEM*    tag_elem = new TAG_ELEM;

  if(!read_qname(tag_elem->name, !READ_ATTRIBUTE_QNAME))
  {
    delete tag_elem;
    return false;
  }

  skip_whitespaces();

  if(is_end_tag)
  {
    if(tag_stack.empty())
    {
      delete tag_elem;
      return false;///no tags to close
    }
    TAG_ELEM    *&last_tag = tag_stack.back();
    if(!fill_in_uri(NULL, tag_elem->name.prefix, tag_elem->name.prefix_len, tag_elem->name.uri) && tag_elem->name.prefix[0])
    {
      delete tag_elem;
      return false;
    }
    if(!compareQNames(last_tag->name, tag_elem->name))
    {
      delete tag_elem;
      return false;
    }

    delete tag_elem;

    skip_whitespaces();
    c = read_char();
    if(c != '>')
    {
      return false;
    }

    //notify as SAX event
    endElement();//this, last_tag->name.localname.c_str(), last_tag->name.prefix.c_str(), last_tag->name.uri.c_str());

    delete last_tag;
    tag_stack.pop_back();
    return true;
  }

//  skip_whitespaces();
//  QNameItemImpl*  qname = new QNameItemImpl(g_empty_string.theStrStore,//reinterpret_cast<const char*>(uri),
//                                   tag_elem->name.prefix,//reinterpret_cast<const char*>(prefix),
//                                   tag_elem->name.localname);//reinterpret_cast<const char*>(lname));
//  store::Item_t    qname_item(qname);
  ///-store::Item_t tname = store.theSchemaTypeNames[XS_UNTYPED];
  // Create the element node and push it to the node stack
  ///-tag_elem->elemNode = new ElementTreeNode(NULL,//qname_item,
  ///-                                        tname);//numAttributes);

  //NodeVector  &elem_attrs = tag_elem->elemNode->attributes();
//  attr_list_t elem_attrs;
// elem_attrs.reserve(10);
  elem_attrs.clear();
  store::NsBindings  nsbindings;
  //read all attributes and namespaces in this tag
  if(!read_attributes(&nsbindings, elem_attrs))
  {
    delete tag_elem;
    return false;
  }


/*-  std::list<TAG_ELEM*>::reverse_iterator      parent_tag;
  XmlNode   *parent_elem;
  parent_tag = tag_stack.rbegin();
  parent_tag++;
  if(parent_tag == tag_stack.rend())
    parent_elem = theRootNode;
  else
    parent_elem = (*parent_tag)->elemNode;

  tag_elem->elemNode->attachedloader = this;
  tag_elem->elemNode->depth = tag_stack.size();//has been already pushed into tag stack
  tag_elem->elemNode->setParent(parent_elem);
  parent_elem->children().push_back(tag_elem->elemNode, false);

  // Assign the current node id to this node, and compute the next node id.
  tag_elem->elemNode->setId(theTree, &theOrdPath);
  theOrdPath.pushChild();

  SYNC_CODE(tag_elem->elemNode->theRCLockPtr = &theTree->getRCLock();)

  NsBindingsContext   *nscontext = tag_elem->elemNode->getNsContext();
  if(nscontext && nscontext->getBindings().size())
  {
    nscontext->setParent(parent_elem->getNsContext());
  }
  else 
  {
    tag_elem->elemNode->setNsContext(parent_elem->getNsContext());
  }
*/
  //fill in the uri part of tag elem and attributes
  if(!fill_in_uri(&nsbindings, tag_elem->name.prefix, tag_elem->name.prefix_len, tag_elem->name.uri))
  {
    //if(!tag_elem->name.prefix->empty())
    if(tag_elem->name.prefix[0])
      return false;
  }
  tag_stack.push_back(tag_elem);
//  bool  inserted;
/*-  tag_elem->elemNode->theName = qnpool.insert(tag_elem->name.uri->c_str(), 
                                              tag_elem->name.prefix, 
                                              tag_elem->name.localname);
*/

/*  //send start_element SAX notification
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

  startElement(this, tag_elem->name.localname.c_str(),
              tag_elem->name.prefix.c_str(),
              tag_elem->name.uri.c_str(),
              ns_size,
              namespaces,
              attr_size,
              0,
              attributes);
*/
  startElement(tag_elem, nsbindings, elem_attrs);

//  delete [] namespaces;
//  delete [] attributes;

  c = read_char();
  if(c == '/')
  {
    c = read_char();
    if(c != '>')
      return false;
    ///end this tag
    //notify as SAX event
    is_end_tag = 2;
    endElement();//this, tag_elem->name.localname.c_str(), tag_elem->name.prefix.c_str(), tag_elem->name.uri.c_str());

    delete tag_elem;
    tag_stack.pop_back();
  }

  return true;
}

bool XmlLoader::read_characters()
{
  int c;
  //std::string chars;

  temp_buff.clear();

  end_document = false;
  while(1)
  {
    c = read_char();
    if(!c)
    {
      end_document = true;
      //if(!content->empty())
      if(!temp_buff.empty())
      {
        const char  *chars = temp_buff.c_str();//content->c_str();
        while(*chars)
        {
          if(!isWhitespace(*chars))
            return false;
          chars++;
        }
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
    //chars += c;
    //content->append_in_place(c);
    temp_buff.append(c);
  }


  //send characters as SAX event
  //if(!content->empty())
  if(!temp_buff.empty())
  {
    xqpStringStore_t    content = new xqpStringStore(temp_buff.c_str(), temp_buff.length());
    characters(this, content);//chars.c_str(), chars.length());
  }

  return true;
}

bool XmlLoader::read_comment()
{
  int c;
  std::string comment_str;

  c = read_char();
  if(c == '[')
    return read_cdata();
  else if(c != '-')
    return false;
  c = read_char();
  if(c != '-')
    return false;

  while(1)
  {
    c = read_char();
    if(!c)
      return false;
    if(c == '-')
    {
      c = read_char();
      if(c != '-')
      {
        comment_str += '-';
        comment_str += c;
        continue;
      }
      c = read_char();
      if(c != '>')
        return false;
      break;
    }
    comment_str += c;
  }


  //send comment as SAX event
  comment(this, comment_str.c_str());

  return true;
}

bool XmlLoader::read_cdata()
{
  //<![CDATA[ <!-- --> </<<< &&&& CDATA CONTENT &&&& >>>/> <-- <!-- ]]>
  //read from CDATA..
  int c;
  std::string cdata_str;

  c = read_char();
  if(c != 'C')
    return false;
  c = read_char();
  if(c != 'D')
    return false;
  c = read_char();
  if(c != 'A')
    return false;
  c = read_char();
  if(c != 'T')
    return false;
  c = read_char();
  if(c != 'A')
    return false;
  c = read_char();
  if(c != '[')
    return false;

  //now read everything until ]]>

  while(1)
  {
    c=read_char();
    if(!c)
      return false;
    if(c == ']')
    {
      c = read_char();
      if(!c)
        return false;
      if(c == ']')
      {
        c = read_char();
        if(!c)
          return false;
        if(c == '>')
          break;
        else
          cdata_str += "]]";
      }
      else
        cdata_str += "]";
    }

    cdata_str += c;
  }

  cdataBlock(this, cdata_str.c_str(), cdata_str.length());
  return true;
}

bool XmlLoader::read_pi()
{
  int c;
  std::string pitarget;
  std::string pidata;

  c = read_char();
  if(!((c == '_') || (c == ':') || XQCharType::isLetter(c)))
    return false;
  pitarget = c;
  while(1)
  {
    c = read_char();
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
  {
    if(!reading_prolog)
      return false;
    else
      return read_xmlprolog();
  }

  if(c != '?')
  {
    //read pi data
    skip_whitespaces();
    while(1)
    {
      c = read_char();
      if(!c)
        return false;
      if(c == '?')
      {
        c = read_char();
        if(c == '>')
          break;
        pidata += '?';
      }
      pidata += c;
    }
  }
  else
  {
    c = read_char();
    if(c != '>')
      return false;
  }

  //send Processing Instruction as SAX event
  processingInstruction(this, pitarget.c_str(), pidata.c_str());

  return true;
}

bool XmlLoader::read_xmlprolog()
{
  int c;

  //c = read_char();
  //if(c != '<')
  //  return false;
  //c = read_char();
  //if(c != '?')
  //  return false;
  //c = read_char();
  //if((c != 'x') && (c != 'X'))
  //  return false;
  //c = read_char();
  //if((c != 'm') && (c != 'M'))
  //  return false;
  //c = read_char();
  //if((c != 'l') && (c != 'L'))
  //  return false;

  //LoadedNodeVector  prolog_attrs;
  attr_list_t   prolog_attrs;
  if(!read_attributes(NULL, prolog_attrs))
    return false;

  c = read_char();
  if(c != '?')
    return false;
  c = read_char();
  if(c != '>')
    return false;

//  int attr_size = prolog_attrs.size();
//  for(int i=0;i<attr_size;i++)
  attr_list_t::iterator   attr_it;
  for(attr_it=prolog_attrs.begin(); attr_it!=prolog_attrs.end(); attr_it++)
  {
//    AttributeNode *attr_node = reinterpret_cast<AttributeNode*>(prolog_attrs.get(i));
//    QNameItemImpl *attr_qname = reinterpret_cast<QNameItemImpl*>(attr_node->getNodeName());
    if(!strcmp((*attr_it).name.localname, "version"))
      this->xml_version = (*attr_it).value;
    if(!strcmp((*attr_it).name.localname, "encoding"))
      this->xml_encoding = (*attr_it).value;
  }
  reading_prolog++;
  return true;
}

XmlNode* XmlLoader::loadXml(
                            const xqpStringStore_t& uri, 
                            std::istream& stream)
{
  error::ErrorManager     *ourErrorManager = theErrorManager;

  XmlNode *root = startloadXml(uri, &stream);
  if(!root)
  {
    this->stream = NULL;
    return NULL;
  }
  theErrorManager = ourErrorManager;
  if(!continueloadXml(UNTIL_END_ELEMENT, 0))//read all doc
  {
    this->stream = NULL;
    return NULL;
  }

  this->stream = NULL;
  return root;
}

XmlNode* XmlLoader::startloadXml(
                            const xqpStringStore_t& docuri, 
                            std::istream* stream)
{
  end_document = false;
  this->stream = stream;
  theDocUri = docuri;
  prev_c = 0;
  current_c = 0;

  startDocument(this);

  {
    int c;
    c = read_char();
    if(c == 0xEF)
    {
      c = read_char();
      if(c == 0xBB)
      {
        c = read_char();
        if(c == 0xBF)//UTF8 mark (on Windows text editors) U+FEFF
        {
        }
        else
          unread_char();
      }
      else
        unread_char();
    }
    else
      unread_char();
  }

  reading_prolog = 1;
  while(reading_prolog)
  {
    skip_whitespaces();
    if(!read_tag())
    {
      endDocument(this);
      ZORBA_ERROR_PARAM_CONTINUE_OSS(theErrorManager,
                                     XQP0017_LOADER_PARSING_ERROR,
                                     "The document with URI " << *theDocUri
                                     <<" is not well formed", "");
      abortload();
      return NULL;
    }
    reading_prolog--;
  }

  theErrorManager = NULL;
  return theRootNode;
}

/*******************************************************************************

********************************************************************************/
bool XmlLoader::continueloadXml(
                           enum lazyloadType_t lazytype ,//for lazy loading, START_ELEMENT or END_ELEMENT
                           unsigned int   depth)//for lazy loading, 1 based, when to stop loading;
{
  while(1)
  {
    if(!read_characters())
    {
      endDocument(this);
      if(theErrorManager)
      {
        ZORBA_ERROR_PARAM_CONTINUE_OSS(theErrorManager,
                                     XQP0017_LOADER_PARSING_ERROR,
                                     "The document with URI " << *theDocUri
                                     <<" is not well formed", "");
      }
      abortload();
      return false;
    }
    if(end_document)
      break;
    if(!read_tag())
    {
      endDocument(this);
      if(theErrorManager)
      {
        ZORBA_ERROR_PARAM_CONTINUE_OSS(theErrorManager,
                                     XQP0017_LOADER_PARSING_ERROR,
                                     "The document with URI " << *theDocUri
                                     <<" is not well formed", "");
      }
      abortload();
      return false;
    }
    if((lazytype == UNTIL_START_ELEMENT) && (is_end_tag != 1) && (depth >= tag_stack.size()))
      return true;
    if((lazytype == UNTIL_END_ELEMENT) && (is_end_tag == 1) && (depth > tag_stack.size()))
      return true;
  }

  endDocument(this);
  if(!tag_stack.empty())
  {
    if(theErrorManager)
    {
      ZORBA_ERROR_PARAM_CONTINUE_OSS(theErrorManager,
                                   XQP0017_LOADER_PARSING_ERROR,
                                   "The document with URI " << *theDocUri
                                   <<" is not well formed", "");
    }
    abortload();
    return false;
  }


//  XmlNode* resultNode = theRootNode;
//  reset();
  if(theRootNode != NULL)
    theRootNode->getTree()->attachedloader = NULL;
  return true;//resultNode;
}


/*******************************************************************************
  SAX2 callback when the start of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void XmlLoader::startDocument(void * ctx)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    xqpStringStore_t docUri = loader.theDocUri;
    xqpStringStore_t baseUri = loader.theBaseUri;
    store::Item_t docNode;

    loader.theFactory->createDocumentNode(docNode, baseUri, docUri);

    DocumentTreeNode*     docNode_cast = dynamic_cast<DocumentTreeNode*>(docNode.getp());
    loader.theRootNode = docNode_cast;
    //docNode_cast->attachedloader = &loader;
    docNode_cast->is_full_loaded = false;
    docNode_cast->getTree()->attachedloader = &loader;

    LOADER_TRACE1("Start Doc Node = " << docNode.getp());
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  SAX2 callback when the end of document has been detected by the parser.

  ctx: the user data (XML parser context)
********************************************************************************/
void XmlLoader::endDocument(void * ctx)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>(ctx));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
//    DocumentTreeNode*     docNode = dynamic_cast<DocumentTreeNode*>(loader.theRootNode);
    if(loader.theRootNode)
    {
      //loader.theRootNode->attachedloader = NULL;
      loader.theRootNode->is_full_loaded = true;
      loader.theRootNode->finalizeNode();
    }

   LOADER_TRACE2("End Doc Node = " << loader.theRootNode.getp());
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
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
   TAG_ELEM *tag_elem,
   store::NsBindings &nsbindings,
   attr_list_t  &elem_attrs
    )
{
  try
  {
    store::Item_t qname;
    store::Item_t tname;
    store::Item_t nullValue;
    xqpStringStore_t baseUri;

    // Get the parent node from the node stack
    std::list<TAG_ELEM*>::reverse_iterator      parent_tag;
    store::Item_t   parent;
    parent_tag = tag_stack.rbegin();
    parent_tag++;
    if(parent_tag == tag_stack.rend())
      parent = theRootNode;
    else
      parent = (*parent_tag)->elemNode;

    // Construct node name and type
    theFactory->createQName(qname,
                             tag_elem->name.uri->c_str(), 
                             tag_elem->name.prefix, 
                             tag_elem->name.localname);
    //+theFactory->createQName(tname,
    //+                         "http://www.w3.org/2001/XMLSchema",
    //+                         "xs",
    //+                         "untyped");
    tname = store.theSchemaTypeNames[XS_UNTYPED];

    // If this is going to be the root of the xml tree, give it the input base uri
    if (parent == NULL)
      baseUri = theBaseUri;

    store::Item_t node;
    theFactory->createElementNode(node, parent, -1, qname, 
                                  tname, nullValue, false, false,
                                  nsbindings, baseUri);
    tag_elem->elemNode = dynamic_cast<ElementTreeNode*>(node.getp());
    tag_elem->elemNode->setIsFullLoaded(false);
    tag_elem->elemNode->depth = tag_stack.size();//has been already pushed into tag stack

    //+theFactory->createQName(tname,
    //+                         "http://www.w3.org/2001/XMLSchema",
    //+                         "xs",
    //+                         "untypedAtomic");
    tname = store.theSchemaTypeNames[XS_UNTYPED_ATOMIC];

    attr_list_t::iterator   attr_it;
    NodeVector& attrNodes = tag_elem->elemNode->attributes();
    for(attr_it=elem_attrs.begin(); attr_it!=elem_attrs.end(); attr_it++)
    {
      //if(!(*attr_it).name.prefix->empty())
      if((*attr_it).name.prefix[0])
      {
        if(!fill_in_uri(NULL, (*attr_it).name.prefix, (*attr_it).name.prefix_len, (*attr_it).name.uri))
        {
          ZORBA_ERROR_PARAM_OSS(XQP0016_LOADER_IO_ERROR,
                "Cannot find namespace for attribute",  (*attr_it).name.prefix << ":" << (*attr_it).name.localname);
        //  return false;
        }
      }
      theFactory->createQName(qname, 
                              (*attr_it).name.uri->c_str(), 
                              (*attr_it).name.prefix, 
                              (*attr_it).name.localname);


      store::Item_t tnameCopy = tname;
      store::Item_t attr;
      store::Item_t typedValue;
      theFactory->createUntypedAtomic(typedValue, (*attr_it).value);
      theFactory->createAttributeNode(attr, 
                                      node, -1, 
                                      qname, 
                                      tnameCopy, 
                                      typedValue, false, false);
    }
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}

  
/*******************************************************************************
  SAX2 callback when an element end has been detected by the parser. It
  provides the expanded qname of the element.
********************************************************************************/
void  XmlLoader::endElement()
{
  try{
    std::list<TAG_ELEM*>::reverse_iterator      this_tag;
    this_tag = tag_stack.rbegin();

    //(*this_tag)->elemNode->attachedloader = NULL;//is loaded
    (*this_tag)->elemNode->setIsFullLoaded(true);

    (*this_tag)->elemNode->finalizeNode();

    LOADER_TRACE2("End Element: node = " << (*this_tag)->elemNode << " name = "
                  << (*this_tag)->elemNode->getNodeName()->show() << std::endl);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  SAX2 callback when xml text has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a xmlChar string
  len: the number of xmlChar
********************************************************************************/
void XmlLoader::characters(void * ctx, xqpStringStore_t content)//const xmlChar * ch, int len)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

//  const char* charp = reinterpret_cast<const char*>(ch);
//  xqpStringStore_t content(new xqpStringStore(charp, len));
  try
  {
    std::list<TAG_ELEM*>::reverse_iterator      parent_tag;
    parent_tag = loader.tag_stack.rbegin();
    store::Item_t parent;
    if(parent_tag != loader.tag_stack.rend())
      parent = (*parent_tag)->elemNode;
    else
      parent = loader.theRootNode;

    store::Item_t node;
    loader.theFactory->createTextNode(node, parent, -1, content);

    LOADER_TRACE1("Text Node = " << node.getp() << std::endl
                  << node->show() << std::endl);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  SAX2 callback when a CDATA block has been detected by the parser.

  ctx: the user data (XML parser context)
  ch:  a xmlChar string
  len: the number of xmlChar
********************************************************************************/
void XmlLoader::cdataBlock(void * ctx, const xmlChar * ch, int len)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    const char* charp = reinterpret_cast<const char*>(ch);
    xqpStringStore_t content(new xqpStringStore(charp, len));

    std::list<TAG_ELEM*>::reverse_iterator      parent_tag;
    parent_tag = loader.tag_stack.rbegin();
    store::Item_t parent;
    if(parent_tag != loader.tag_stack.rend())
      parent = (*parent_tag)->elemNode;
    else
      parent = loader.theRootNode;

    // Create the text node
    store::Item_t node;
    loader.theFactory->createTextNode(node, parent, -1, content);

    LOADER_TRACE1("Text Node = " << node.getp() << std::endl
                  << node->show() << std::endl);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  SAX2 callback when a processing instruction has been detected by the parser.

  ctx: the user data (XML parser context)

********************************************************************************/
void XmlLoader::processingInstruction(
    void * ctx, 
    const xmlChar * targetp, 
    const xmlChar * data)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    xqpStringStore_t content = new xqpStringStore(reinterpret_cast<const char*>(data));
    xqpStringStore_t target = new xqpStringStore(reinterpret_cast<const char*>(targetp));
    xqpStringStore_t baseUri;

    std::list<TAG_ELEM*>::reverse_iterator      parent_tag;
    parent_tag = loader.tag_stack.rbegin();
    XmlNode *parent;
    if(parent_tag != loader.tag_stack.rend())
      parent = (*parent_tag)->elemNode;
    else
      parent = loader.theRootNode;

    store::Item_t node;
    loader.theFactory->createPiNode(node, parent, -1, target, content, baseUri);

    LOADER_TRACE1("Pi Node = " << node.getp() << std::endl
                  << node->show() << std::endl);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  SAX2 callback when a comment has been detected by the parser.

  ctx: the user data (XML parser context)
  content:  the comment content
********************************************************************************/
void XmlLoader::comment(void * ctx, const xmlChar * ch)
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
  ZORBA_LOADER_CHECK_ERROR(loader);

  try
  {
    const char* charp = reinterpret_cast<const char*>(ch);
    xqpStringStore_t content(new xqpStringStore(charp));

    std::list<TAG_ELEM*>::reverse_iterator      parent_tag;
    parent_tag = loader.tag_stack.rbegin();
    XmlNode *parent;
    if(parent_tag != loader.tag_stack.rend())
      parent = (*parent_tag)->elemNode;
    else
      parent = loader.theRootNode;

    store::Item_t node;
    loader.theFactory->createCommentNode(node, parent, -1, content);

    LOADER_TRACE1("Comment Node = " << node.getp() << std::endl
                  << node->show() << std::endl);
  }
  catch (error::ZorbaError& e)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              e.theErrorCode, e.theDescription);
  }
  catch (...)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader.theErrorManager,
                              XQP0019_INTERNAL_ERROR, "Unknown exception");
  }
}


/*******************************************************************************
  Display and format an error messages, callback.
 
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  XmlLoader::error(void * ctx, const char * msg, ... )
{
  XmlLoader* loader = (static_cast<XmlLoader *>(ctx));
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);
  if(loader->theErrorManager)
  {
    ZORBA_ERROR_DESC_CONTINUE(loader->theErrorManager,
                            XQP0017_LOADER_PARSING_ERROR, buf);
  }
}


/*******************************************************************************
   Display and format a warning messages, callback.
  
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
********************************************************************************/
void  XmlLoader::warning(void * ctx, const char * msg, ... )
{
  XmlLoader& loader = *(static_cast<XmlLoader *>( ctx ));
  char buf[1024];
  va_list args;
  va_start(args, msg);
  vsprintf(buf, msg, args);
  va_end(args);
  if (loader.theWarnings.size() > 0)
    loader.theWarnings += "+ ";
  loader.theWarnings += buf;
}

#undef ZORBA_ERROR_DESC_CONTINUE

} // namespace storeminimal
} // namespace zorba
