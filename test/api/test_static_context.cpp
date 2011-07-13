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

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cassert>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/xquery_exception.h>
#include <zorba/diagnostic_list.h>


using namespace zorba;

#define SCTX_TEST_CALL(test_function_name) \
{ \
  int result = test_function_name(lZorba); \
  if (result != 0) { \
    std::cerr << #test_function_name << " failed"<< std::endl; \
    return result; \
  } \
}
// use this to test correct behaviour
#define SCTX_TEST_RESOLVE(BASE, URI, RESULT) \
{ \
  StaticContext_t lSctx = lZorba->createStaticContext(); \
  try { \
    std::cout << "\"" << BASE << "\"" << " + " << "\"" << URI << "\"" << " = " << std::endl; \
    String lResolved2 = lSctx->resolve(URI, BASE); \
    lSctx->setBaseURI(BASE); \
    String lResolved1 = lSctx->resolve(URI); \
    std::cout << "r1: \"" << lResolved1 << "\"" << std::endl; \
    std::cout << "r2: \"" << lResolved2 << "\"" << std::endl; \
    if (lResolved1 != RESULT) { \
      std::cout << "Bad r1 result! Expected: \"" << RESULT << "\"" << std::endl; \
      lFailed = true; \
    } \
    if (lResolved2 != RESULT) { \
      std::cout << "Bad r2 result! Expected: \"" << RESULT << "\"" << std::endl; \
      lFailed = true; \
    } \
    std::cout << "Correct!" << std::endl; \
    std::cout << "-----------------------------------------------------------------------" << std::endl; \
  } catch (ZorbaException const&) { \
    std::cout << "Exception!" << std::endl; \
    std::cout << "-----------------------------------------------------------------------" << std::endl; \
    lFailed = true; \
  } \
}

// use this to test exceptions thrown
#define SCTX_TEST_RESOLVE_EXCEPTION(BASE, URI) \
{ \
  StaticContext_t lSctx = lZorba->createStaticContext(); \
  try { \
    std::cout << "\"" << BASE << "\"" << " + " << "\"" << URI << "\"" << std::endl; \
    String lResolved2 = lSctx->resolve(URI, BASE); \
    std::cout << "\"" << lResolved2 << "\"" << std::endl; \
    std::cout << "This should have thrown an exception!" << std::endl; \
    std::cout << "-----------------------------------------------------------------------" << std::endl; \
    return 1; \
  } catch (ZorbaException const& e) { \
    std::cout << "Caught exception. " << e << std::endl << "Good!" << std::endl; \
    std::cout << "-----------------------------------------------------------------------" << std::endl; \
  } \
}

int
test_disabled_function(Zorba* lZorba)
{
  StaticContext_t lSctx1 = lZorba->createStaticContext();
  StaticContext_t lSctx2 = lZorba->createStaticContext();
 
  Item lQName = lZorba->getItemFactory()->createQName(
                "http://www.w3.org/2005/xpath-functions",
                "current-dateTime");

  lSctx1->disableFunction(lQName, 0);
 
  // test if function is disabled in static context 1
  try {
    XQuery_t lQuery = lZorba->compileQuery("fn:current-dateTime()", lSctx1);
    return 1; // must raise a function not found exception
  } catch (ZorbaException const& e) {
    // fail if any other exception
    if (e.diagnostic() != err::XPST0017) {
      std::cerr << e << std::endl;
      return 2;
    }
  }

  // test if function exists in static context 2
  try {
    XQuery_t lQuery = lZorba->compileQuery("fn:current-dateTime()", lSctx2);
  } catch (ZorbaException const& e) {
    std::cerr << e << std::endl;
    return 3;
  }

  return 0;
}

int
test_resolve(Zorba* lZorba)
{
  bool lFailed = false;

  SCTX_TEST_RESOLVE("http://www.example.com/dir/file", "relative_path", "http://www.example.com/dir/relative_path");
  SCTX_TEST_RESOLVE("http://www.example.com/dir/file", "relative_path_slash/", "http://www.example.com/dir/relative_path_slash/");
  SCTX_TEST_RESOLVE("http://www.example.com/dir/file", "relative_path/two_segments", "http://www.example.com/dir/relative_path/two_segments");
  SCTX_TEST_RESOLVE("http://www.example.com/dir/file", "/absolute_path", "http://www.example.com/absolute_path");
  SCTX_TEST_RESOLVE("http://www.example.com/dir/file", "/absolute_path_slash/", "http://www.example.com/absolute_path_slash/");
  SCTX_TEST_RESOLVE("http://www.example.com/dir/file", "/absolute_path/two_segments", "http://www.example.com/absolute_path/two_segments");
  SCTX_TEST_RESOLVE("http://www.example.com/dir/file", "..", "http://www.example.com/");
  SCTX_TEST_RESOLVE("http://www.example.com/dir/file", "../..", "http://www.example.com/");
  // failing
  SCTX_TEST_RESOLVE("http://www.example.com/", "../dir/..", "http://www.example.com/");
  // failing
  SCTX_TEST_RESOLVE("http://www.example.com/", "/../dir/../..", "http://www.example.com/");
  // failing
  SCTX_TEST_RESOLVE("http://www.example.com/", "../dir1/../dir2", "http://www.example.com/");
  // failing
  SCTX_TEST_RESOLVE("http://www.example.com/", "/../dir1/../dir2", "http://www.example.com/");
  SCTX_TEST_RESOLVE_EXCEPTION("http://www.example.com/%", "");
  // failing
  SCTX_TEST_RESOLVE_EXCEPTION("http://www.example.com/\\", "");
  // failing
  SCTX_TEST_RESOLVE_EXCEPTION("http://www.example.com/", "\\");
  // failing
  SCTX_TEST_RESOLVE_EXCEPTION("http://www.example.com/ ", "");
  // failing
  SCTX_TEST_RESOLVE_EXCEPTION("http://www.example.com/", " ");
  SCTX_TEST_RESOLVE_EXCEPTION("", "");
  
  if (lFailed) {
    std::cerr << "at least one of the above tests failed" << std::endl;
    return 1;
  } else {
    return 0;
  }
}

/**
 * main
 */
int
test_static_context(int argc, char* argv[]) 
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);

  SCTX_TEST_CALL(test_disabled_function);
  SCTX_TEST_CALL(test_resolve);

  return 0;
}
