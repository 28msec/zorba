/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

  Zorba Zorba::getInstance(const Store& aStore)
  {
    return Zorba(zorba::Zorba::getInstance(aStore.getStore()));
  }
  
  ItemFactory Zorba::getItemFactory()
  {
    return ItemFactory(theZorba->getItemFactory());
  }
  
  StaticContext Zorba::createStaticContext()
  {
    return StaticContext(theZorba->createStaticContext());
  }
  
  XQuery Zorba::createQuery() 
  {
    return XQuery(theZorba->createQuery());
  }

  XQuery Zorba::compileQuery(const std::string& aStr) 
  {
    return XQuery(theZorba->compileQuery(aStr));
  }

  XQuery Zorba::compileQuery(
    const std::string& aStr,
    StaticContext &aStaticContext )
  { 
    return XQuery(
      theZorba->compileQuery(
        aStr,
        aStaticContext.theStaticContext
      )
    );
  }

  XQuery Zorba::compileQuery(
    const std::string& aStr,
    DiagnosticHandler* aDiagnosticHandler
  )
  {
    return XQuery(theZorba->compileQuery(aStr, aDiagnosticHandler));
  }
  XQuery Zorba::compileQuery(
    const std::string& aStr,
    StaticContext &aStaticContext, 
    DiagnosticHandler* aDiagnosticHandler)
  { 
    return XQuery(
      theZorba->compileQuery(
        aStr,
        aStaticContext.theStaticContext,
        aDiagnosticHandler
      )
    );
  }

  XQuery Zorba::compileQuery(
    const std::string& aStr,
    CompilerHints& aCompilerHints,
    DiagnosticHandler* aDiagnosticHandler)
  { 
    return XQuery(
      theZorba->compileQuery(
        aStr,
        aCompilerHints.theCompilerHints,
        aDiagnosticHandler
      )
    );
  }

  XmlDataManager Zorba::getXmlDataManager()
  {
    return XmlDataManager(theZorba->getXmlDataManager());
  }

  void Zorba::shutdown() 
  {
    theZorba->shutdown();
  }
  std::string Zorba::getVersion() {
    return zorba::Zorba::version().getVersion();
  }
  int Zorba::getMajorVersion() {
    return zorba::Zorba::version().getMajorVersion();
  }
  int Zorba::getMinorVersion() {
    return zorba::Zorba::version().getMinorVersion();
  }
  int Zorba::getPatchVersion() {
    return zorba::Zorba::version().getPatchVersion();
  }
  bool Zorba::isXQueryXSupported() {
    #ifdef ZORBA_XQUERYX
      return true;
    #else //ZORBA_XQUERYX
      return false;
    #endif //ZORBA_XQUERYX
  }

  XQuery Zorba::compileQuery(ZorbaIOStream & aStream)
  {
    ZorbaStreamBuffer streamBuffer(aStream);
    std::istream stream(&streamBuffer);
    return XQuery(theZorba->compileQuery(stream));
  }

  XQuery Zorba::compileQuery(ZorbaIOStream & aStream, StaticContext &aStaticContext )
  { 
    ZorbaStreamBuffer streamBuffer(aStream);
    std::istream stream(&streamBuffer);
    return XQuery(theZorba->compileQuery(stream, aStaticContext.theStaticContext));
  }

%}  // end Implementation

%include "Zorba.h"
