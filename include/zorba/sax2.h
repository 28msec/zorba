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
#ifndef ZORBA_SAX2_API_H
#define ZORBA_SAX2_API_H

#include <zorba/api_shared_types.h>

namespace zorba{

class SAX2_Attributes;
class SAX2_Namespaces;

/** \brief Receive notification of events that result from serializing
 *         a query result as XML.
 *
 * This is an interface that is used to receive notifications resulting
 * from parsing a query result that was serialized as XML.
 *
 * Instances of classes that implement this interface can be registered for
 * a query by calling the XQuery::registerSAXHandler or XQuery::executeSAX
 * function.
 */
class SAX2_ContentHandler
{
  public:

    /** \brief Destructor
     */
    virtual
    ~SAX2_ContentHandler() {}

    /** \brief Receive notification of the beginning of a document.
     */
    virtual void
    startDocument() = 0;

    /** \brief Receive notification of the end of a document.
     */
    virtual void
    endDocument() = 0;

    /** \brief Receive notification of the beginning of an element.
     *
     * Zorba's serializer will invoke this method at the beginning of every element 
     * of the serialized query result; there will be a corresponding endElement() 
     * event for every startElement() event (even when the element is empty). 
     * All of the element's content will be reported, in order, before the 
     * corresponding endElement() event.
     *
     * @param aURI the URI of the associated namespace for this element.
     * @param aLocalname thee local part of the element name.
     * @param aQName the QName of this element.
     * @param aAttrs the attributes attached to the element, if any.
     */
    virtual void
    startElement( const String& aURI, const String& aLocalname, const String& aQName,
                  const SAX2_Attributes& aAttrs, const SAX2_Namespaces& aNS ) = 0;

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
}
//end namespace zorba
#endif
