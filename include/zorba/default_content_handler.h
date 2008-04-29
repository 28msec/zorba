/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_DEFAULT_CONTENT_HANDLER_API_H
#define ZORBA_DEFAULT_CONTENT_HANDLER_API_H

#include <zorba/sax2.h>

namespace zorba{
  
  /** \brief A default content handler class implementing the SAX2_ContentHandler and
   *         SAX2_LexicalHandler interfaces with all functions being implemented and doing
   *         nothing.
   *
   * See SAX2_ContentHandler for a documentation.
   */

  class DefaultContentHandler: public SAX2_ContentHandler,
                               public SAX2_LexicalHandler
  {
    public:
      virtual 
      ~DefaultContentHandler() {}

      void 
      startDocument() {}

      void 
      endDocument() {}

      void 
      startElement( const String &uri, const String &localname, const String &qname,
                    const SAX2_Attributes& aAttrs, const SAX2_Namespaces& aNS ) {}
    
      void
      endElement( const String &uri, const String &localname, const String &qname ) {}
    
      void
      characters( const String & text ) {}
    
      void
      processingInstruction( const String &target, const String &data ) {}

      void
      ignorableWhitespace( const String & whitespace ) {}

      void
      startPrefixMapping( const String	& prefix, const String	& uri ) {}

      void 
      endPrefixMapping( const String & prefix ) {}

      void 
      skippedEntity( const	String & name ) {}
  
      void elementDecl ( const String & name, const String & model ) {}

      void attributeDecl ( const String & eName, const String & aName,
                           const String & type,  const String & mode,
                           const String & value ) {}

      void internalEntityDecl ( const String & name, const String & value ) {}

      void externalEntityDecl ( const String & name, const String & publicId,
                                const String & systemId ) {}

      void notationDecl ( const String & name, const String & publicId, const String & systemId ) {}

      void unparsedEntityDecl ( const String & name, const String & publicId,
                                const String & systemId, const String & notationName ) {}

      void resetDocType () {}

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
