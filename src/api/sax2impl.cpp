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

namespace zorba{
/////////////////////////////////////////////////////////////////////////////////
// SAX2 Attributes
SAX2AttributesImpl::SAX2AttributesImpl(store::Item *item)
{
  store::Iterator_t    attr_it;
  SAX2_XmlAttribute   a;
  store::Item_t      item_qname;
  attr_it = item->getAttributes();
  if(attr_it == NULL)
    return;
  attr_it->open();
  store::Item_t child;
  attr_it->next(child);
  while (child!= NULL)
  {		
    //emit_node(&*child, depth);
    item_qname = child->getNodeName();
    a.uri = item_qname->getNamespace();
    a.localname = item_qname->getLocalName();
    a.qname = item_qname->getStringValue().getp();
    a.value = child->getStringValue().getp();
    a.type = child->getType()->getStringValue().getp();
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
  return attrs.size();
}

const String SAX2AttributesImpl::getURI(const unsigned int index) const
{
  return &*(attrs[index].uri).theStrStore;
}

const String SAX2AttributesImpl::getLocalName(const unsigned int index) const
{
  return &*(attrs[index].localname).theStrStore;
}

const String SAX2AttributesImpl::getQName(const unsigned int index) const
{
  return &*(attrs[index].qname).theStrStore;
}

const String SAX2AttributesImpl::getType(const unsigned int index) const
{
  return &*(attrs[index].type).theStrStore;
}

const String SAX2AttributesImpl::getValue(const unsigned int index) const
{
  return &*(attrs[index].value).theStrStore;
}

int SAX2AttributesImpl::getIndex(const String &  uri, const String & localPart ) const
{
  unsigned int  i;
  unsigned int  size = attrs.size();
  for(i=0;i<size;i++)
  {
    String lAttrURI(attrs[i].uri);
    String lLocalName(attrs[i].localname);
    if((lAttrURI == uri) && (localPart == lLocalName))
      return i;
  }

  return -1;
}

int SAX2AttributesImpl::getIndex(const String & qName ) const
{
  unsigned int  i;
  unsigned int  size = attrs.size();
  for(i=0;i<size;i++)
  {
    String lQName( attrs[i].qname );
    if( qName == lQName )
      return i;
  }

  return -1;
}

const String SAX2AttributesImpl::getType(const String & uri, const String & localPart ) const
{
  unsigned int  i;
  unsigned int  size = attrs.size();
  for(i=0;i<size;i++)
  {
    String lattruri(attrs[i].uri);
    String llocalname(attrs[i].localname);
    if((uri == lattruri) && (localPart == llocalname))
    {
      String lType(attrs[i].type);
      return lType;
    }
  }
  return "";
}

const String SAX2AttributesImpl::getType(const String & qName) const
{
  unsigned int  i;
  unsigned int  size = attrs.size();
  for(i=0;i<size;i++)
  {
    String lQName( attrs[i].qname );
    if(qName == lQName)
    {
      String lType( attrs[i].type ); 
      return lType;
    }
  }
  return "";
}

const String SAX2AttributesImpl::getValue(const String & uri, const String & localPart ) const
{
  unsigned int  i;
  unsigned int  size = attrs.size();
  for(i=0;i<size;i++)
  {
    String lattruri(attrs[i].uri);
    String llocalname(attrs[i].localname);
    if((uri == lattruri) && (localPart == llocalname))
    {
      String lvalue(attrs[i].value);
      return lvalue;
    }
  }
  return "";
}

const String SAX2AttributesImpl::getValue(const String & qName) const
{
  unsigned int  i;
  unsigned int  size = attrs.size();
  for(i=0;i<size;i++)
  {
    String lQName( attrs[i].qname );
    if(qName == lQName)
    {
      String lValue( attrs[i].value ); 
      return lValue;
    }
  }
  return "";
}
}//end namespace zorba
