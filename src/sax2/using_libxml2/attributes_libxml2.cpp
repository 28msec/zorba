
#include "sax2/using_libxml2/attributes_libxml2.h"
#include <string.h>
//#include <libxml/xmlmemory.h>
#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"

namespace zorba{

SAX2_AttributesLibXML2::SAX2_AttributesLibXML2(	int nb_attributes,
		                    const char **attributes)
{
  this->nb_attributes = nb_attributes;
  this->attributes = attributes;
  own_data = false;
}

SAX2_AttributesLibXML2::SAX2_AttributesLibXML2(SAX2_AttributesLibXML2 *orig)
{
  int   i;

  nb_attributes = orig->nb_attributes;
  attributes = new const char*[nb_attributes*5];
  for(i=0;i<nb_attributes;i++)
  {
    attributes[i*5] = strdup(orig->attributes[i*5]);
    attributes[i*5+1] = strdup(orig->attributes[i*5+1]);
    attributes[i*5+2] = strdup(orig->attributes[i*5+2]);
    attributes[i*5+3] = strdup(orig->attributes[i*5+3]);
    attributes[i*5+4] = attributes[i*5+3] + strlen(attributes[i*5+3]);
  }
  own_data = true;
}

/** Destructor */
SAX2_AttributesLibXML2::~SAX2_AttributesLibXML2() 
{
  if(own_data)
  {
    for(int i=0;i<nb_attributes;i++)
    {
      free((void*)attributes[i*5]);
      free((void*)attributes[i*5+1]);
      free((void*)attributes[i*5+2]);
      free((void*)attributes[i*5+3]);
    }
    delete[] attributes;
  }
}

//x2
unsigned int SAX2_AttributesLibXML2::getLength() const
{
  return nb_attributes;
}

const xqp_string SAX2_AttributesLibXML2::getURI(const unsigned int index) const
{
  return attributes[index*5+2];
}

const xqp_string SAX2_AttributesLibXML2::getLocalName(const unsigned int index) const
{
  return attributes[index*5+0];
}

const xqp_string SAX2_AttributesLibXML2::getQName(const unsigned int index) const
{
  if(attributes[index*5+1] && attributes[index*5+1][0])
    return (xqp_string)attributes[index*5+1] + ":" + attributes[index*5+0];
  else
    return attributes[index*5+0];
}

const xqp_string SAX2_AttributesLibXML2::getType(const unsigned int index) const
{
  return "";
}

const xqp_string SAX2_AttributesLibXML2::getValue(const unsigned int index) const
{
  return xqpStringStore(attributes[index*5+3], attributes[index*5+4]);
}

int SAX2_AttributesLibXML2::getIndex(const xqp_string uri, const xqp_string localPart ) const
{
  int   i;
  for(i=0;i<nb_attributes;i++)
  {
    if((uri == attributes[i*5+2]) &&
      (localPart == attributes[i*5+0]))
      return i;
  }
  
  return -1;
}

int SAX2_AttributesLibXML2::getIndex(const xqp_string qName ) const
{
  int   i;
  int   prefix_len;
  const char  *strqName = qName.c_str();

  for(i=0;i<nb_attributes;i++)
  {
    prefix_len = strlen(attributes[i*5+1]);
    if((!strncmp(strqName, attributes[i*5+1], prefix_len)) &&
      (strqName[prefix_len] == ':') &&
      (!strcmp(strqName+prefix_len+1, attributes[i*5+0])))
      return i;
  }
  
  return -1;
}

const xqp_string SAX2_AttributesLibXML2::getType(const xqp_string uri, const xqp_string localPart ) const
{
  return "";
}

const xqp_string SAX2_AttributesLibXML2::getType(const xqp_string qName) const
{
  return "";
}

const xqp_string SAX2_AttributesLibXML2::getValue(const xqp_string uri, const xqp_string localPart ) const
{
  int   i;
  for(i=0;i<nb_attributes;i++)
  {
    if((uri == attributes[i*5+2]) &&
      (localPart == attributes[i*5+0]))
      return xqpStringStore(attributes[i*5+3], attributes[i*5+4]);
  }
  
  return "";
}

const xqp_string SAX2_AttributesLibXML2::getValue(const xqp_string qName) const
{
  int   i;
  int   prefix_len;
  const char  *strqName = qName.c_str();

  for(i=0;i<nb_attributes;i++)
  {
    prefix_len = strlen(attributes[i*5+1]);
    if((!strncmp(strqName, attributes[i*5+1], prefix_len)) &&
      (strqName[prefix_len] == ':') &&
      (!strcmp(strqName+prefix_len+1, attributes[i*5+0])))
      return xqpStringStore(attributes[i*5+3], attributes[i*5+4]);
  }
  
  return "";
}

//Zorba specific:
//do a persistent duplicate
SAX2_Attributes*   SAX2_AttributesLibXML2::clone()
{
  return new SAX2_AttributesLibXML2(this);
}

}
