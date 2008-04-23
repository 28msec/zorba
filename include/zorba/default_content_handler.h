#ifndef ZORBA_DEFAULT_CONTENT_HANDLER_API_H
#define ZORBA_DEFAULT_CONTENT_HANDLER_API_H

#include <zorba/sax2.h>

namespace zorba{

  class DefaultContentHandler: public SAX2_ContentHandler,
                               public SAX2_LexicalHandler
  {
    public:
      /**
       * SAX2 Content Handler
       *
       */
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
  
      /**
       * SAX2 Declaration handler
       */
      void elementDecl ( const String & name, const String & model ) {}

      void attributeDecl ( const String & eName, const String & aName,
                           const String & type,  const String & mode,
                           const String & value ) {}

      void internalEntityDecl ( const String & name, const String & value ) {}

      void externalEntityDecl ( const String & name, const String & publicId,
                                const String & systemId ) {}

      /**
       * SAX2 DTD handler
       */
      void notationDecl ( const String & name, const String & publicId, const String & systemId ) {}

      void unparsedEntityDecl ( const String & name, const String & publicId,
                                const String & systemId, const String & notationName ) {}

      void resetDocType () {}

      /**
       * SAX2 Lexical handler
       */
      void comment ( const String & chars ) {}

      void endCDATA () {}

      void endDTD () {}

      void endEntity ( const String & name ) {}

      void startCDATA () {}

      void startDTD ( const String & name, const String & publicId,
                      const String & systemId ) {}

      void startEntity ( const String & name ) {}
  };
}//end of namespace
#endif
