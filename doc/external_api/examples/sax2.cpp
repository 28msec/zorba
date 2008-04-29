#include <iostream>

#include <zorba/zorba.h>
#include <zorba/default_content_handler.h>

using namespace zorba;

// implement a new sax content handler
// that prints information to an output stream passed in the constructor
class XMLSerializer: public DefaultContentHandler
{
  protected:
    std::ostream& theOStream;
    bool preserveWhiteSpaces;

  public:
    XMLSerializer( std::ostream & aOStream, bool useWS = true )
      : theOStream( aOStream ),
        preserveWhiteSpaces( useWS ){}

    virtual ~XMLSerializer(){}

    void endDocument()
    {
      theOStream << std::endl;
    }

    void startElement( const String &uri, const String &localname,
                       const String &qname, const SAX2_Attributes& attrs ) 
    {
      theOStream << "<" << qname;
      for ( unsigned int i = 0; i < attrs.getLength(); i++ ) {
        theOStream  <<  " " << attrs.getQName( i ) << "=\"" << attrs.getValue( i ) << "\"";    
      }
      theOStream << ">";
    }

    void endElement( const String &uri, const String &localname, const String &qname )
    {
      theOStream << "</" << qname << ">";
    }
    
    void characters( const String & text )
    {
      theOStream << text;
    }
    
    void processingInstruction( const String &target, const String &data ){}

    void ignorableWhitespace( const String & whitespace )
    {
      if ( preserveWhiteSpaces ) {
        theOStream << whitespace;
      }
    }
};

int sax2( int argc, char * argv[] )
{
  // create a SAX content handler that prints all events to standard out
  XMLSerializer lContentHandler( std::cout );

  // initialize the Zorba engine and get a pointer to it
  Zorba* lZorba = Zorba::getInstance();

  try {

    // compile a query
    XQuery_t lQuery = lZorba->compileQuery("<a xmlns:f=\"foo\" xmlns=\"http://flworfound.org/defaultns\"> text a text a <b xmlns:ns1=\"http://flworfound.org/usecase1\" attr1=\"value1\" attr2=\"value2\"> text b </b><f:bar>foo</f:bar><foo /><bar /><b><![CDATA[ foo ]]></b></a>");

    // register the content handler created above
    lQuery->registerSAXHandler( &lContentHandler );

    // execute the query and call according SAX callbacks 
    // i.e. equivalent to serializing to xml and parsing using SAX).
    lQuery->executeSAX();

  } catch ( ZorbaException &e ) {
    std::cerr << e << std::endl;
  }
  return 0;
}

