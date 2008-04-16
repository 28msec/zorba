#ifndef ZORBA_DEFAULT_CONTENT_HANDLER_API_H
#define ZORBA_DEFAULT_CONTENT_HANDLER_API_H

#include <zorba/sax2.h>

namespace zorba{

  class DefaultContentHandler: public SAX2_ContentHandler
  {
    public:

      virtual ~DefaultContentHandler(){}

      void setDocumentLocator( const SAX2_Locator * const locator ){}

      void startDocument(){}

      void endDocument(){}

      void startElement( const String &uri, const String &localname, const String &qname,
                        const SAX2_Attributes &attrs, const SAX2_Namespaces &ns ){}
    
      void endElement( const String &uri, const String &localname, const String &qname ){}
    
      void characters( const String & text ){}
    
      void processingInstruction( const String &target, const String &data ){}

      void ignorableWhitespace( const String & whitespace ){}

      void startPrefixMapping( const String	& prefix, const String	& uri ){}

      void endPrefixMapping( const String & prefix ){}

      void skippedEntity( const	String & name ){}
  };
}//end of namespace
#endif

