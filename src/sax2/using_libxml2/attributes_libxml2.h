
#ifndef ZORBA_SAX2_ATTRIBUTES_USING_LIBXML2_28_FEB_2008
#define ZORBA_SAX2_ATTRIBUTES_USING_LIBXML2_28_FEB_2008

#include "zorba/sax2.h"
//#include <libxml/xmlmemory.h>

namespace xqp{

class SAX2_AttributesLibXML2 : public SAX2_Attributes
{
  int   nb_attributes;
  //list of pairs localname/prefix/URI/valueBegin/valueEnd
  const char **attributes;
  bool  own_data;
public:
    SAX2_AttributesLibXML2(	int nb_attributes,
				                    const char **attributes);
    SAX2_AttributesLibXML2(	SAX2_AttributesLibXML2 *orig);

    /** Destructor */
    virtual ~SAX2_AttributesLibXML2();

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
