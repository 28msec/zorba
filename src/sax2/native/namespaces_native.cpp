
#include "sax2/native/namespaces_native.h"
#include "zorba/item.h"

namespace zorba{

SAX2_NamespacesNative::SAX2_NamespacesNative(store::NsBindings *local_nsBindings, store::Item *item)
{
  this->local_nsBindings = local_nsBindings;
  nb_local = local_nsBindings->size();

  item->getNamespaceBindings(parent_nsBindings,
                             store::StoreConsts::ONLY_PARENT_NAMESPACES);
  nb_parent = parent_nsBindings.size();
}

SAX2_NamespacesNative::~SAX2_NamespacesNative()
{
}

unsigned int SAX2_NamespacesNative::getLength()
{
  return nb_local + nb_parent;
}

const xqp_string  SAX2_NamespacesNative::getPrefix( unsigned int index )
{
  if(index < nb_local)
    return (*local_nsBindings)[index].first;
  else
    return parent_nsBindings[index-nb_local].first;
}

const xqp_string  SAX2_NamespacesNative::getURI( unsigned int index )
{
  if(index < nb_local)
    return (*local_nsBindings)[index].second;
  else
    return parent_nsBindings[index-nb_local].second;
}

const xqp_string  SAX2_NamespacesNative::getURI( xqp_string prefix)
{
  unsigned int    i;
  for(i=0;i<nb_local;i++)
  {
    if((*local_nsBindings)[i].first == prefix)
      return (*local_nsBindings)[i].second;
  }
  for(i=0;i<nb_parent;i++)
  {
    if(parent_nsBindings[i].first == prefix)
      return parent_nsBindings[i].second;
  }

  return "";
}


}//namespace zorba
