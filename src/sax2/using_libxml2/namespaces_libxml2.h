
#ifndef ZORBA_SAX2_ELEMENT_NAMESPACES_USING_LIBXML2_28_FEB_2008
#define ZORBA_SAX2_ELEMENT_NAMESPACES_USING_LIBXML2_28_FEB_2008

#include "zorba/sax2.h"

namespace xqp{

class SAX2_NamespacesLibXML2 : public SAX2_Namespaces
{
  unsigned int nb_namespaces;
  //prefix/URI pairs
  const char **namespaces;

public:
  SAX2_NamespacesLibXML2(unsigned int nb_namespaces, const char** namespaces);
  virtual ~SAX2_NamespacesLibXML2();

  virtual unsigned int getLength();
  
  virtual const xqp_string  getPrefix( unsigned int index );
  virtual const xqp_string  getURI( unsigned int index );

  virtual const xqp_string  getURI( xqp_string prefix);
};

}
#endif

