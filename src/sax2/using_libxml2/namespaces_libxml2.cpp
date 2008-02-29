
#include "sax2/using_libxml2/namespaces_libxml2.h"

namespace xqp{

SAX2_NamespacesLibXML2::SAX2_NamespacesLibXML2(unsigned int nb_namespaces, const char** namespaces)
{
  this->nb_namespaces = nb_namespaces;
  this->namespaces = namespaces;
}

SAX2_NamespacesLibXML2::~SAX2_NamespacesLibXML2() 
{}

unsigned int SAX2_NamespacesLibXML2::getLength()
{
  return nb_namespaces;
}

const xqp_string  SAX2_NamespacesLibXML2::getPrefix( unsigned int index )
{
  return namespaces[index*2];
}

const xqp_string  SAX2_NamespacesLibXML2::getURI( unsigned int index )
{
  return namespaces[index*2+1];
}

const xqp_string  SAX2_NamespacesLibXML2::getURI( xqp_string prefix)
{
  unsigned int i;
  for(i=0;i<nb_namespaces;i++)
  {
    if(prefix == namespaces[i*2])
      return namespaces[i*2+1];
  }
  return "";
}

}
