#include <iostream>

#include <zorba/zorba.h>
#include <zorba/sax2.h>

using namespace zorba;

class XMLSerializer: public SAX2_ContentHandler
{
  protected:
    std::ostream & theOStream;
    bool preserveWhiteSpaces;

  public:
    XMLSerializer( std::ostream & aOStream, bool useWS = true )
      : theOStream( aOStream ),
        preserveWhiteSpaces( useWS ){}

    virtual ~XMLSerializer(){}

    void setDocumentLocator( const SAX2_Locator * const locator ){}

    void startDocument()
    {
      //theOStream << "<?xml version=\"1.0\" ?>\n";
    }

    void endDocument()
    {
      theOStream << std::endl;
    }

    void startElement( const String &uri, const String &localname, const String &qname,
                        const SAX2_Attributes &attrs, const SAX2_Namespaces &ns )
    {
      theOStream << "<" << qname;
      for ( unsigned int i = 0; i < attrs.getLength(); i++ )
      {
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
      if ( preserveWhiteSpaces )
      {
        theOStream << whitespace;
      }
    }

    void startPrefixMapping( const String	& prefix, const String	& uri ){}

    void endPrefixMapping( const String & prefix ){}

    void skippedEntity( const	String & name ){}
};

int sax2( int argc, char * argv[] )
{
  XMLSerializer lContentHandler( std::cerr );
  Zorba * lZorba = Zorba::getInstance();
  try
  {
    XQuery_t lQuery = lZorba->compileQuery("<a xmlns:f=\"foo\" xmlns=\"http://flworfound.org/defaultns\"> text a text a <b xmlns:ns1=\"http://flworfound.org/usecase1\" attr1=\"value1\" attr2=\"value2\"> text b </b><f:bar>foo</f:bar><foo /><bar /><b><![CDATA[ foo ]]></b></a>");
    lQuery->registerSAXHandler( &lContentHandler );
    lQuery->executeSAX();
    lQuery->close();
  } catch ( StaticException &e ) {
    std::cerr << e << std::endl;
  } catch ( DynamicException &e ) {
    std::cerr << e << std::endl;
  }
  lZorba->shutdown();
  return 0;
}

