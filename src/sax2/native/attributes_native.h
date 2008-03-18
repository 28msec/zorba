
#ifndef ZORBA_SAX2_ATTRIBUTES_NATIVE_17_MAR_2008
#define ZORBA_SAX2_ATTRIBUTES_NATIVE_17_MAR_2008

#include "zorba/sax2.h"
#include "zorba/item.h"

namespace zorba{

class SAX2_AttributesNative : public SAX2_Attributes
{
  typedef struct
  {
    xqp_string    uri;
    xqp_string    localname;
    xqp_string    qname;
    xqp_string    value;
  }SAX2_XmlAttribute;
  //list of pairs localname/prefix/URI/valueBegin/valueEnd
  std::vector<SAX2_XmlAttribute>   attrs;
  //bool  own_data;
public:
  SAX2_AttributesNative( store::Item *item);
    SAX2_AttributesNative( SAX2_AttributesNative *orig);

    /** Destructor */
    virtual ~SAX2_AttributesNative();

    //x2
    virtual unsigned int getLength() const;

  	virtual const xqp_string getURI(const unsigned int index) const;

    virtual const xqp_string getLocalName(const unsigned int index) const;

    virtual const xqp_string getQName(const unsigned int index) const;

    virtual const xqp_string getType(const unsigned int index) const;

    virtual const xqp_string getValue(const unsigned int index) const;

  	virtual int getIndex(const xqp_string uri, const xqp_string localPart ) const;

  	virtual int getIndex(const xqp_string qName ) const;

  	virtual const xqp_string getType(const xqp_string uri, const xqp_string localPart ) const;

    virtual const xqp_string getType(const xqp_string qName) const;

  	virtual const xqp_string getValue(const xqp_string uri, const xqp_string localPart ) const;

    virtual const xqp_string getValue(const xqp_string qName) const;

    //Zorba specific:
    //do a persistent duplicate
    virtual SAX2_Attributes*   clone();
};

}


#endif
