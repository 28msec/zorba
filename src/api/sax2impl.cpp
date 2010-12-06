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
#include "api/sax2impl.h"
#include "store/api/iterator.h"
#include "store/api/item.h"
#include "api/unmarshaller.h"
#include <zorba/zorbastring.h>
#include <zorba/default_content_handler.h>

namespace zorba
{

/////////////////////////////////////////////////////////////////////////////////
// SAX2 Attributes
SAX2AttributesImpl::SAX2AttributesImpl(store::Item *item)
{
  store::Iterator_t attr_it;
  store::Item_t item_qname;

  attr_it = item->getAttributes();

  if(attr_it == NULL)
    return;

  attr_it->open();

  store::Item_t child;
  attr_it->next(child);

  while (child != NULL)
  {		
    SAX2_XmlAttribute a;

    //emit_node(&*child, depth);
    item_qname = child->getNodeName();
    a.uri = item_qname->getNamespace().str();
    a.localname = item_qname->getLocalName();
    item_qname->getStringValue2(a.qname);
    child->getStringValue2(a.value);
    child->getType()->getStringValue2(a.type);
    attrs.push_back(a);

    attr_it->next(child);
  }

  attr_it->close();
}


SAX2AttributesImpl::SAX2AttributesImpl(  SAX2AttributesImpl * orig )
{
  attrs = orig->attrs;
}


SAX2AttributesImpl::~SAX2AttributesImpl()
{
}


//x2
unsigned int SAX2AttributesImpl::getLength() const
{
  return (unsigned int)attrs.size();
}


const String SAX2AttributesImpl::getURI(const unsigned int index) const
{
  return attrs[index].uri.str();
}


const String SAX2AttributesImpl::getLocalName(const unsigned int index) const
{
  return attrs[index].localname.str();
}


const String SAX2AttributesImpl::getQName(const unsigned int index) const
{
  return attrs[index].qname.str();
}


const String SAX2AttributesImpl::getType(const unsigned int index) const
{
  return attrs[index].type.str();
}


const String SAX2AttributesImpl::getValue(const unsigned int index) const
{
  return attrs[index].value.str();
}


int SAX2AttributesImpl::getIndex(const String &  uri, const String & localPart ) const
{
  unsigned int  i;
  unsigned int  size = (unsigned int)attrs.size();

  for(i = 0; i < size; i++)
  {
    String lAttrURI(attrs[i].uri.str());
    String lLocalName(attrs[i].localname.str());
    if((lAttrURI == uri) && (localPart == lLocalName))
      return i;
  }

  return -1;
}


int SAX2AttributesImpl::getIndex(const String & qName ) const
{
  unsigned int  i;
  unsigned int  size = (unsigned int)attrs.size();

  for(i = 0; i < size; i++)
  {
    String lQName( attrs[i].qname.str() );
    if(qName == lQName)
      return i;
  }

  return -1;
}


const String SAX2AttributesImpl::getType(
    const String & uri,
    const String & localPart) const
{
  unsigned int  i;
  unsigned int  size = (unsigned int)attrs.size();

  for(i = 0; i < size; i++)
  {
    String lattruri(attrs[i].uri.str());
    String llocalname(attrs[i].localname.str());

    if((uri == lattruri) && (localPart == llocalname))
    {
      String lType(attrs[i].type.str());
      return lType;
    }
  }
  return "";
}


const String SAX2AttributesImpl::getType(const String & qName) const
{
  unsigned int  i;
  unsigned int  size = (unsigned int)attrs.size();

  for(i = 0; i < size; i++)
  {
    String lQName(attrs[i].qname.str());
    if(qName == lQName)
    {
      String lType(attrs[i].type.str()); 
      return lType;
    }
  }
  return "";
}


const String SAX2AttributesImpl::getValue(
    const String & uri,
    const String & localPart ) const
{
  unsigned int  i;
  unsigned int  size = (unsigned int)attrs.size();

  for(i = 0;i < size; i++)
  {
    String lattruri(attrs[i].uri.str());
    String llocalname(attrs[i].localname.str());
    if((uri == lattruri) && (localPart == llocalname))
    {
      String lvalue(attrs[i].value.str());
      return lvalue;
    }
  }
  return "";
}


const String SAX2AttributesImpl::getValue(const String & qName) const
{
  unsigned int  i;
  unsigned int  size = (unsigned int)attrs.size();

  for(i = 0; i < size; i++)
  {
    String lQName(attrs[i].qname.str());
    if(qName == lQName)
    {
      String lValue(attrs[i].value.str()); 
      return lValue;
    }
  }
  return "";
}
}//end namespace zorba
