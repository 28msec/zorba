
#ifndef ZORBA_SAX2_ELEMENT_NAMESPACES_NATIVE_17_MAR_2008
#define ZORBA_SAX2_ELEMENT_NAMESPACES_NATIVE_17_MAR_2008

#include "zorba/sax2.h"
#include "zorba/item.h"

namespace zorba{

class SAX2_NamespacesNative : public SAX2_Namespaces
{
  unsigned int nb_local;
  unsigned int nb_parent;
  //prefix/URI pairs
  store::NsBindings *local_nsBindings;
  store::NsBindings parent_nsBindings;

public:
  SAX2_NamespacesNative(store::NsBindings *local_nsBindings, store::Item *item);
  virtual ~SAX2_NamespacesNative();

  virtual unsigned int getLength();
  
  virtual const xqp_string  getPrefix( unsigned int index );
  virtual const xqp_string  getURI( unsigned int index );

  virtual const xqp_string  getURI( xqp_string prefix);
};

}
#endif

