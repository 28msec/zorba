#ifndef ZORBA_SAX2_API_H
#define ZORBA_SAX2_API_H

#include <zorba/api_shared_types.h>

namespace zorba{

class SAX2_Locator;
class SAX2_Attributes;
class SAX2_Namespaces;

class SAX2_ContentHandler
{
  public:

    virtual
    ~SAX2_ContentHandler() {}

    virtual void
    setDocumentLocator( const SAX2_Locator * const locator ) = 0;

    virtual void
    startDocument() = 0;

    virtual void
    endDocument() = 0;

    virtual void
    startElement( const String &uri, const String &localname, const String &qname,
                  const SAX2_Attributes &attrs, const SAX2_Namespaces &ns ) = 0;

    virtual void
    endElement( const String &uri, const String &localname, const String &qname ) = 0;
    
    virtual void
    characters( const String & text ) = 0;
    
    virtual void
    processingInstruction( const String &target, const String &data ) = 0;

    virtual void
    ignorableWhitespace( const String & text ) = 0;

    virtual void
    startPrefixMapping( const String	& prefix, const String	& uri ) = 0;

    virtual void
    endPrefixMapping( const String & prefix ) = 0;

    virtual void
    skippedEntity( const	String & name ) = 0;
};

class SAX2_Attributes
{
  public:
    
    virtual
    ~SAX2_Attributes() {}
    
    virtual unsigned int
    getLength() const = 0;

  	virtual const String
    getURI( const unsigned int index) const = 0;

    virtual const String
    getLocalName( const unsigned int index) const = 0;

    virtual const String
    getQName( const unsigned int index) const = 0;

    virtual const String
    getType( const unsigned int index) const = 0;

    virtual const String
    getValue( const unsigned int index) const = 0;

  	virtual int
    getIndex( const String & uri, const String & localPart ) const = 0 ;

  	virtual int
    getIndex(const String & qName ) const = 0 ;

  	virtual const
    String getType(const String & uri, const String & localPart ) const = 0 ;

    virtual const
    String getType( const String & qName ) const = 0;

  	virtual const
    String getValue( const String & uri, const String & localPart ) const = 0 ;

    virtual const
    String getValue( const String & qName ) const = 0;
};

class SAX2_Namespaces
{
  public:
    virtual
    ~SAX2_Namespaces() {}

    virtual unsigned int
    getLength() const = 0;
  
    virtual const String
    getPrefix( unsigned int index ) const = 0;
  
    virtual const String
    getURI( unsigned int index ) const = 0;

    virtual const String
    getURI( String &  prefix ) const = 0;
};

class SAX2_Locator
{
  public:
    virtual
    ~SAX2_Locator () {}
 
    virtual const String
    getPublicId () const = 0;
   
    virtual const String
    getSystemId () const = 0;
   
    virtual unsigned long
    getLineNumber () const = 0;
   
    virtual unsigned long
    getColumnNumber () const = 0;
};

class SAX2_DeclHandler
{
  public:
    virtual
    ~SAX2_DeclHandler () {}

    virtual void
    elementDecl ( const String & name, const String & model ) = 0;

    virtual void
    attributeDecl ( const String & eName, const String & aName,
                    const String & type,  const String & mode,
                    const String & value ) = 0;

    virtual void
    internalEntityDecl ( const String & name, const String & value ) = 0;

    virtual void
    externalEntityDecl ( const String & name, const String & publicId,
                        const String & systemId ) = 0;
};

class SAX2_LexicalHandler
{
  public:
    virtual
    ~SAX2_LexicalHandler () {}

    virtual void
    comment ( const String & chars ) = 0;

    virtual void
    endCDATA () = 0;

    virtual void
    endDTD () = 0;

    virtual void
    endEntity ( const String & name ) = 0;

    virtual void
    startCDATA () = 0;

    virtual void
    startDTD ( const String & name, const String & publicId,
               const String & systemId ) = 0;

    virtual void
    startEntity ( const String & name ) = 0;
};

class SAX2_DTDHandler
{
  public:
    virtual
    ~SAX2_DTDHandler () {}

    virtual void
    notationDecl ( const String & name, const String & publicId, const String & systemId ) = 0;

    virtual void
    unparsedEntityDecl ( const String & name, const String & publicId,
                         const String & systemId, const String & notationName ) = 0;

    virtual void
    resetDocType () = 0;
};
}
//end namespace zorba
#endif
