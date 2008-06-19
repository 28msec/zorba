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

#include <iostream>

#include <zorba/zorba.h>
#include <zorba/default_content_handler.h>
#include <simplestore/simplestore.h>

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

  simplestore::SimpleStore* lStore = simplestore::SimpleStoreManager::getStore();

  // initialize the Zorba engine and get a pointer to it
  Zorba* lZorba = Zorba::getInstance(lStore);

  try 
  {
    // compile a query
    XQuery_t lQuery = lZorba->compileQuery("<a xmlns:f=\"foo\" xmlns=\"http://zorba-xquery.com/defaultns\"> text a text a <b xmlns:ns1=\"http://zorba-xquery.com/usecase1\" attr1=\"value1\" attr2=\"value2\"> text b </b><f:bar>foo</f:bar><foo /><bar /><b><![CDATA[ foo ]]></b></a>");

    // register the content handler created above
    lQuery->registerSAXHandler( &lContentHandler );

    // execute the query and call according SAX callbacks 
    // i.e. equivalent to serializing to xml and parsing using SAX).
    lQuery->executeSAX();
  }
  catch ( ZorbaException &e ) 
  {
    std::cerr << e << std::endl;
  }

  lZorba->shutdown();
  simplestore::SimpleStoreManager::shutdownStore(lStore);
  return 0;
}

