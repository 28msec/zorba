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

%{  // start Implementation
  
  std::string XQuery::execute()
  {
    Zorba_SerializerOptions_t lSerOptions;
    lSerOptions.indent = ZORBA_INDENT_NO;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    std::stringstream lStream;
    lStream << theQuery;
    std::string str = lStream.str();
    return str;
  }
  
  void XQuery::compile (const std::string &aQuery)
  {
    theQuery->compile(aQuery);
  }

  void XQuery::compile (const std::string &aQuery, StaticContext &aStaticContext )
  {
    Zorba_CompilerHints_t hints;
    theQuery->compile(aQuery, aStaticContext.theStaticContext, hints);
  }
  
  std::string XQuery::printPlanAsXML()
  {
    std::ostringstream lStream;
    theQuery->printPlan(lStream);
    return lStream.str();
  }

  std::string XQuery::printPlanAsDOT()
  {
    std::ostringstream lStream;
    theQuery->printPlan(lStream, true);
    return lStream.str();
  }
  
  DynamicContext XQuery::getDynamicContext()
  {
    return DynamicContext(theQuery->getDynamicContext());
  }

  StaticContext XQuery::getStaticContext()
  {
    return StaticContext( zorba::StaticContext_t( const_cast<zorba::StaticContext *>(theQuery->getStaticContext()) ) );
  }

  StaticCollectionManager XQuery::getStaticCollectionManager()
  {
    return StaticCollectionManager( theQuery->getStaticCollectionManager() );
  }

  void XQuery::getExternalVariables(Iterator& vars) const 
  { theQuery->getExternalVariables( vars.theIterator ); }

#ifdef SWIGPYTHON
  void XQuery::executeSAX(SAX2ContentHandlerProxy* contentHandlerProxy)
  { theQuery->executeSAX(contentHandlerProxy); }
#endif

  void XQuery::destroy() { theQuery = 0; }
  Iterator XQuery::iterator() { return Iterator(theQuery->iterator()); }

  void XQuery::execute( ZorbaStream& stream )
  {
    Zorba_SerializerOptions_t lSerOptions;
    lSerOptions.indent = ZORBA_INDENT_NO;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
    ZorbaBuffer buffer(stream);
    std::ostream lStream(&buffer);
    theQuery->execute(lStream, &lSerOptions);
    return;
  }

%}  // end   Implementation

%include "XQuery.h"
