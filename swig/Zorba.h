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
#ifndef API_ZORBA_H
#define API_ZORBA_H

class Zorba 
{
 private:
  zorba::Zorba* theZorba;
  Zorba(zorba::Zorba* aZorba) : theZorba(aZorba){};
 public:
  Zorba():theZorba(0){}
  Zorba(const Zorba& aZorba) : theZorba(aZorba.theZorba) {};
  
  static Zorba getInstance(const Store&);
  StaticContext createStaticContext();
  XQuery createQuery();
  XQuery compileQuery(const std::string& aStr);
  XQuery compileQuery(const std::string& aStr, StaticContext &aStaticContext );
  //XQuery compileQuery(const ZIStreamHelper& aZorbaStream);
  //XQuery compileQuery(const ZIStreamHelper& aZorbaStream, StaticContext &aStaticContext );
  ItemFactory getItemFactory();
  XQuery compileQuery(const std::string& aStr, DiagnosticHandler* aDiagnosticHandler);
  XQuery compileQuery(const std::string& aStr, StaticContext &aStaticContext, 
                      DiagnosticHandler* aDiagnosticHandler);
  XQuery compileQuery(const std::string& aStr, CompilerHints &aCompilerHints, 
                      DiagnosticHandler* aDiagnosticHandler);
  XmlDataManager getXmlDataManager();
  void shutdown();
  std::string getVersion();
  int getMajorVersion();
  int getMinorVersion();
  int getPatchVersion();

}; // class Zorba

#endif
