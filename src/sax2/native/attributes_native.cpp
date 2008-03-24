
#include "sax2/native/attributes_native.h"
#include "store/api/iterator.h"
#include "store/api/item.h"

namespace zorba{

SAX2_AttributesNative::SAX2_AttributesNative(store::Item *item)
{
  Iterator_t    attr_it;
  SAX2_XmlAttribute   a;
  store::Item_t      item_qname;
  attr_it = item->getAttributes();
  if(attr_it == NULL)
    return;
  attr_it->open();
  store::Item_t   child = attr_it->next();
  while (child!= NULL)
  {		
    //emit_node(&*child, depth);
    item_qname = child->getNodeName();
    a.uri = item_qname->getNamespace();
    a.localname = item_qname->getLocalName();
    a.qname = item_qname->getStringValue();
    a.value = child->getStringValue();
    attrs.push_back(a);

    child = attr_it->next();
  }

  attr_it->close();
}

SAX2_AttributesNative::SAX2_AttributesNative(SAX2_AttributesNative *orig)
{
  attrs = orig->attrs;
}

SAX2_AttributesNative::~SAX2_AttributesNative()
{
}

//x2
unsigned int SAX2_AttributesNative::getLength() const
{
  return attrs.size();
}

const xqp_string SAX2_AttributesNative::getURI(const unsigned int index) const
{
  return attrs[index].uri;
}

const xqp_string SAX2_AttributesNative::getLocalName(const unsigned int index) const
{
  return attrs[index].localname;
}

const xqp_string SAX2_AttributesNative::getQName(const unsigned int index) const
{
  return attrs[index].qname;
}

const xqp_string SAX2_AttributesNative::getType(const unsigned int index) const
{
  return "";//??
}

const xqp_string SAX2_AttributesNative::getValue(const unsigned int index) const
{
  return attrs[index].value;
}

int SAX2_AttributesNative::getIndex(const xqp_string uri, const xqp_string localPart ) const
{
  unsigned int  i;
  unsigned int  size = attrs.size();
  for(i=0;i<size;i++)
  {
    if((uri == attrs[i].uri) && (localPart == attrs[i].localname))
      return i;
  }

  return -1;
}

int SAX2_AttributesNative::getIndex(const xqp_string qName ) const
{
  unsigned int  i;
  unsigned int  size = attrs.size();
  for(i=0;i<size;i++)
  {
    if(qName == attrs[i].qname)
      return i;
  }

  return -1;
}

const xqp_string SAX2_AttributesNative::getType(const xqp_string uri, const xqp_string localPart ) const
{
  return "";//??
}

const xqp_string SAX2_AttributesNative::getType(const xqp_string qName) const
{
  return "";//??
}

const xqp_string SAX2_AttributesNative::getValue(const xqp_string uri, const xqp_string localPart ) const
{
  unsigned int  i;
  unsigned int  size = attrs.size();
  for(i=0;i<size;i++)
  {
    if((uri == attrs[i].uri) && (localPart == attrs[i].localname))
      return attrs[i].value;
  }

  return "";
}

const xqp_string SAX2_AttributesNative::getValue(const xqp_string qName) const
{
  unsigned int  i;
  unsigned int  size = attrs.size();
  for(i=0;i<size;i++)
  {
    if(qName == attrs[i].qname)
      return attrs[i].value;
  }

  return "";
}

//Zorba specific:
//do a persistent duplicate
SAX2_Attributes*   SAX2_AttributesNative::clone()
{
  return new SAX2_AttributesNative(this);
}


}
