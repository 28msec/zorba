#ifndef ZORBA_SAX2_IMPL_HPP
#define ZORBA_SAX2_IMPL_HPP

#include <zorba/sax2.h>
#include <zorba/item.h>

#include "zorbatypes/representations.h"
#include "store/api/item.h"

namespace zorba{

class SAX2AttributesImpl: public SAX2_Attributes
{
  typedef struct
  {
    xqp_string    uri;
    xqp_string    localname;
    xqp_string    qname;
    xqp_string    value;
    xqp_string    type;
  }SAX2_XmlAttribute;
  //list of pairs localname/prefix/URI/valueBegin/valueEnd
  std::vector<SAX2_XmlAttribute>   attrs;
  //bool  own_data;
public:
  SAX2AttributesImpl( store::Item *item);
  SAX2AttributesImpl( SAX2AttributesImpl * orig);

  /** Destructor */
  virtual ~SAX2AttributesImpl();

  unsigned int getLength() const;

  const String getURI(const unsigned int index) const;

  const String getLocalName(const unsigned int index) const;

  const String getQName(const unsigned int index) const;

  const String getType(const unsigned int index) const;

  const String getValue(const unsigned int index) const;

  int getIndex(const String & uri, const String & localPart ) const;

  int getIndex(const String & qName ) const;

  const String getType(const String & uri, const String & localPart ) const;

  const String getType(const String & qName) const;

  const String getValue(const String & uri, const String & localPart ) const;

  const String getValue(const String & qName) const;
};

class SAX2NamespacesImpl: public SAX2_Namespaces
{
  unsigned int nb_local;
  unsigned int nb_parent;
  //prefix/URI pairs
  store::NsBindings *local_nsBindings;
  store::NsBindings parent_nsBindings;

public:
  SAX2NamespacesImpl(store::NsBindings *local_nsBindings, store::Item *item);
  virtual ~SAX2NamespacesImpl();
  virtual unsigned int getLength() const;
  virtual const String  getPrefix( unsigned int index ) const;
  virtual const String  getURI( unsigned int index ) const;
  virtual const String  getURI( String & prefix) const;

};

class SAX2LocatorImpl: public SAX2_Locator
{
  protected:
    xqp_string thePublicId;
    xqp_string theSystemId;
    unsigned long theLine;
    unsigned long theColumn;

  public:
    SAX2LocatorImpl();
    const String getPublicId() const;
    const String getSystemId() const;
    unsigned long getLineNumber() const;
    unsigned long getColumnNumber() const;
    void setPublicId(String & aPublicId);
    void setSystemId(String & aSystemId);
};
}//end of namespace
#endif

