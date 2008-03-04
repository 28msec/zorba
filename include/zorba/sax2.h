
#ifndef ZORBA_SAX_INTERFACE_25_FEB_2008
#define ZORBA_SAX_INTERFACE_25_FEB_2008

//#include <zorba/rchandle.h>
#include <zorbatypes/xqpstring.h>
#include <zorbatypes/representations.h>

namespace zorba{

/*
SAX2 interface inspired from Xerces C++.
User has to implement his own classes derived from this interfaces
in order to receive XML events.

*/

class SAX2_ParseException;
typedef rchandle<SAX2_ParseException>   SAX2_ParseException_t;

class SAX2_Locator;
class SAX2_Exception;
class SAX2_Attributes;
class SAX2_Namespaces;

class SAX2_Exception
{
  xqp_string message;
public:
  SAX2_Exception(xqp_string message);
  SAX2_Exception(SAX2_Exception &orig);
  virtual ~SAX2_Exception();
  virtual const xqp_string  getMessage () const;
};

class SAX2_ContentHandler
{
public:
    virtual ~SAX2_ContentHandler() {}

    //x2
    virtual void setDocumentLocator(const SAX2_Locator* const locator) {}
    //x2
    virtual void startDocument() throw (SAX2_Exception) {}
    //x2
    virtual void endDocument ()  throw (SAX2_Exception) {}

    //x2
    virtual void startElement(
                      const xqp_string    uri,
                      const xqp_string    localname,
                      const xqp_string    qname,
                      const SAX2_Attributes   &attrs,
                      const SAX2_Namespaces   &namespaces) throw (SAX2_Exception) {}
    //x2
    virtual void endElement(
		                  const xqp_string uri,
		                  const xqp_string localname,
                      const xqp_string qname) throw (SAX2_Exception) {}
    //x2
    virtual void characters(const char* text, unsigned long length) throw (SAX2_Exception) {}
    //x2
    virtual void processingInstruction(
                      const xqp_string    target,
                      const xqp_string    data) throw (SAX2_Exception) {}
    //x2
    virtual void ignorableWhitespace(const char* whitespace, unsigned long length) throw (SAX2_Exception) {}

    
    virtual void startPrefixMapping(
	                    const	xqp_string	prefix,
                      const	xqp_string	uri)  throw (SAX2_Exception) {}

    virtual void endPrefixMapping(const	xqp_string	prefix)  throw (SAX2_Exception) {}

    virtual void skippedEntity( const	xqp_string	name )  throw (SAX2_Exception) {}
};


class SAX2_Attributes
{
public:
    /** Destructor */
    virtual ~SAX2_Attributes() {}

    //x2
    virtual unsigned int getLength() const = 0;

  	virtual const xqp_string getURI(const unsigned int index) const = 0;

    virtual const xqp_string getLocalName(const unsigned int index) const = 0;

    virtual const xqp_string getQName(const unsigned int index) const = 0;

    virtual const xqp_string getType(const unsigned int index) const = 0;

    virtual const xqp_string getValue(const unsigned int index) const = 0;

  	virtual int getIndex(const xqp_string uri, const xqp_string localPart ) const = 0 ;

  	virtual int getIndex(const xqp_string qName ) const = 0 ;

  	virtual const xqp_string getType(const xqp_string uri, const xqp_string localPart ) const = 0 ;

    virtual const xqp_string getType(const xqp_string qName) const = 0;

  	virtual const xqp_string getValue(const xqp_string uri, const xqp_string localPart ) const = 0 ;

    virtual const xqp_string getValue(const xqp_string qName) const = 0;

    //Zorba specific:
    //do a persistent duplicate
    virtual SAX2_Attributes*   clone() = 0;
};

class SAX2_Namespaces
{
public:
  virtual ~SAX2_Namespaces() {}

  virtual unsigned int getLength() = 0;
  
  virtual const xqp_string  getPrefix( unsigned int index ) = 0;
  virtual const xqp_string  getURI( unsigned int index ) = 0;

  virtual const xqp_string  getURI( xqp_string prefix) = 0;

};

class SAX2_Locator
{
protected:
  xqp_string    publicId;
  xqp_string    systemId;
  unsigned long line;
  unsigned long column;
public:
  virtual  ~SAX2_Locator () {}
 
  virtual const xqp_string  getPublicId () const {return publicId;}
   
  virtual const xqp_string  getSystemId () const {return systemId;}
   
  virtual unsigned long  getLineNumber () const {return line;}
   
  virtual unsigned long  getColumnNumber () const {return column;}

};

class SAX2_DTDHandler
{
public:
  virtual  ~SAX2_DTDHandler () {}
 
  //x2
  virtual void  notationDecl (const xqp_string name, 
                              const xqp_string publicId, 
                              const xqp_string systemId) throw (SAX2_Exception) {}
  //x2
  virtual void  unparsedEntityDecl (const xqp_string name, 
                                    const xqp_string publicId, 
                                    const xqp_string systemId, 
                                    const xqp_string notationName) throw (SAX2_Exception) {}
   
//  virtual void  resetDocType ()=0;
};

/*not supported

class InputSource {
 InputSource();
 InputSource(String systemId);
 InputSource(java.io.InputStream in);
 InputSource(java.io.Reader in);
// getters
 String getPublicId();
 String getSystemId();
 java.io.InputStream getByteStream();
 String getEncoding();
 java.io.Reader getCharacterStream();
// setters
 void setPublicId(String publicId);
 void setSystemId(String systemId);
 void setByteStream(java.io.InputStream in);
 void setEncoding(String encodingName);
 void setCharacterStream(java.io.Reader in);
}

class SAX2_EntityResolver{
public:
  InputSource *resolveEntity(const xqp_string publicId,
                            const xqp_string systemId) throws SAXException {}
};
*/

class SAX2_DeclHandler
{
public:
  virtual  ~SAX2_DeclHandler () {}
  
  //x2
  virtual void  attributeDecl (const xqp_string element, 
                              const xqp_string attribute, 
                              const xqp_string type, 
                              const xqp_string mode, 
                              const xqp_string defaultValue) throw (SAX2_Exception) {}
  //x2
  virtual void  elementDecl (const xqp_string name, 
                             const xqp_string model) throw (SAX2_Exception) {}
   
  virtual void  externalEntityDecl (const xqp_string name, 
                                    const xqp_string publicId, 
                                    const xqp_string systemId) throw (SAX2_Exception) {}
   
  virtual void  internalEntityDecl (const xqp_string name, 
                                    const xqp_string value) throw (SAX2_Exception) {}
 
};

class SAX2_LexicalHandler
{
public:
  virtual  ~SAX2_LexicalHandler () {}
   
  virtual void  startDTD (const xqp_string root, 
                          const xqp_string publicId, 
                          const xqp_string systemId) throw (SAX2_Exception) {}
  virtual void  endDTD () throw (SAX2_Exception) {}
   
  virtual void  startEntity (const xqp_string name) throw (SAX2_Exception) {}
  virtual void  endEntity (const xqp_string name) throw (SAX2_Exception) {}
   
  virtual void  startCDATA () throw (SAX2_Exception) {}
  virtual void  endCDATA () throw (SAX2_Exception) {}

  //x2
  virtual void  comment (const char* chars, unsigned long length) throw (SAX2_Exception) {}
};

class SAX2_ErrorHandler
{
public:
  virtual  ~SAX2_ErrorHandler () {};
   
  virtual void  warning (const SAX2_ParseException& warn) throw (SAX2_Exception) {}
   
  virtual void  error (const SAX2_ParseException& err) throw (SAX2_Exception) {}
   
  virtual void  fatalError (const SAX2_ParseException& err) throw (SAX2_Exception) {}
   
//  virtual void  resetErrors ()=0;
};

//the SAX exception class hierarchy

class SAX2_NotRecognizedException : public SAX2_Exception
{
public:
  SAX2_NotRecognizedException(xqp_string message);
};

class SAX2_NotSupportedException : public SAX2_Exception
{
public:
  SAX2_NotSupportedException(xqp_string message);
};

class SAX2_ParseException : public SAX2_Exception
{
protected:
  xqp_string publicId;
  xqp_string systemId;
  int line;
  int column;
public:
  SAX2_ParseException(xqp_string message, SAX2_Locator *where);
  SAX2_ParseException(xqp_string message,
                    xqp_string publicId, 
                    xqp_string systemId, 
                    int line, int column);
  SAX2_ParseException(SAX2_ParseException &orig);

  virtual long  getColumnNumber () const;
   
  virtual long  getLineNumber () const;
   
  virtual const xqp_string  getPublicId () const;
   
  virtual const xqp_string  getSystemId () const;
};

}//end namespace zorba

#endif
