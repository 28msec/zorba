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
#include <zorba/diagnostic_handler.h>
#include <zorba/iterator.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>
#include <zorba/user_exception.h>

using namespace zorba;

bool
error_example_1(Zorba* aZorba)
{
  try {
	  XQuery_t lQuery = aZorba->compileQuery("1 div 0"); 

    std::cout << lQuery << std::endl;
  } catch ( ZorbaException& e) {
    std::cout << e << std::endl;
    return true;
  }

	return false;
}

bool
error_example_2(Zorba* aZorba)
{
  try {
	  XQuery_t lQuery = aZorba->compileQuery("1 div"); 

  } catch ( ZorbaException const& e ) {
    std::cout << e << std::endl;
    if ( e.diagnostic().kind() == diagnostic::XQUERY_STATIC )
      return true;
  }

  return false;
}

class MyDiagnosticHandler  : public DiagnosticHandler 
{
public:
  void error( ZorbaException const &ze ) 
  { 
    if ( ze.diagnostic().kind() == diagnostic::XQUERY_STATIC )
      std::cerr << ze << std::endl;
    else
      ze.polymorphic_throw();
  }

  void warning( XQueryWarning const &xw )
  {
    std::cerr << xw << std::endl;
  }
};

bool
error_example_3(Zorba* aZorba)
{
  MyDiagnosticHandler lHandler;

	XQuery_t lQuery = aZorba->compileQuery("for $i in", &lHandler); 

	return true;
}


bool
error_example_4(Zorba* aZorba)
{
  MyDiagnosticHandler lHandler;

  try {
    // move this outside if constant folding is fixed
    XQuery_t lQuery = aZorba->compileQuery("1 div 0"); 

    lQuery->registerDiagnosticHandler(&lHandler);
    std::cout << lQuery << std::endl;
  } catch (ZorbaException const& e) {
    std::cerr << e << std::endl; 
    if ( e.diagnostic().kind() == diagnostic::XQUERY_DYNAMIC )
      return true;
  }

	return false;
}


bool
error_example_5(Zorba* aZorba)
{
  try {
    XQuery_t lQuery = aZorba->compileQuery("fn:error(fn:QName('http://www.w3.org/2005/xqt-errors', 'err:FOER0000'), 'a user error', 1 to 10)"); 

    std::cout << lQuery << std::endl;
  } catch (UserException const& e) {
    // get the error object of an error that was raised
    // using the fn:error function
    UserException::error_object_type const &error = e.error_object();

    UserException::error_object_type::const_iterator it;
    for ( it = error.begin(); it != error.end(); ++it ) {
      std::cout << it->getStringValue() << std::endl;
    }
    return true;
  } catch (ZorbaException const& ze) {
    std::cerr << ze << std::endl;
    return false;
  }

	return false;
}

bool
error_example_6(Zorba* aZorba)
{
  try {
    Item lQName = aZorba->getItemFactory()->createQName(
        "http://zorba.io/options/warnings", "", "error");

    // make sure that the warning zwarn::ZWST0002 is turned
    // into an error
    StaticContext_t lCtx = aZorba->createStaticContext();
    lCtx->declareOption(lQName, "ZWST0003");

    std::ostringstream s;
    s << "declare namespace z = 'http://zorba.io/annotations';" << std::endl
      << "declare %z:sequential function local:foo() { 1 };" << std::endl
      << "local:foo()" << std::endl;
    XQuery_t lQuery = aZorba->compileQuery(s.str(), lCtx); 

    std::cout << lQuery << std::endl;
  } catch (const XQueryException&) {
    return true;
  } catch (const ZorbaException& ze) {
    std::cerr << ze << std::endl;
    return false;
  }
	return false;
}

bool
error_example_7(Zorba* aZorba)
{
  try {
    std::ostringstream s;
    s << "declare function local:test() { fn:error() };" << std::endl
      << "local:test()" << std::endl;                                  
    XQuery_t lQuery = aZorba->compileQuery(s.str()); 

    std::cout << lQuery << std::endl;
  } catch (ZorbaException const& ze) {
    std::cerr << "=== Error XML + Stacktrace ===" << std::endl;
    std::cerr << XQueryException::trace
              << ZorbaException::format_xml
              << ze 
              << std::endl;                            
    std::cerr << "=== Error Text + Stacktrace ===" << std::endl;
    std::cerr << XQueryException::trace
              << ZorbaException::format_text 
              << ze 
              << std::endl;                            
    return true;
  }
	return false;
}

int 
errors(int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

  std::cout << "executing example 1" << std::endl;
  res = error_example_1(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 2" << std::endl;
  res = error_example_2(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 3" << std::endl;
  res = error_example_3(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 4" << std::endl;
  res = error_example_4(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 5" << std::endl;
  res = error_example_5(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 6" << std::endl;
  res = error_example_6(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  std::cout << "executing example 7" << std::endl;
  res = error_example_7(lZorba);
  if (!res) return 1; 
  std::cout << std::endl;

  lZorba->shutdown();
  zorba::StoreManager::shutdownStore(lStore);
  return 0;
}
