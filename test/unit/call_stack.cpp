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

#include <sstream>
#include <iostream>

#include <zorba/zorba.h>
#include <zorba/xquery_exception.h>
#include <zorba/xquery_stack_trace.h>
#include <zorba/store_manager.h>

using namespace zorba;

static bool equals( XQueryStackTrace::Entry const &entry, char const *fn_name,
                    XQueryStackTrace::line_type line,
                    XQueryStackTrace::column_type col ) {
  return entry.getFnName() == fn_name
      && entry.getLine() == line
      && entry.getColumn() == col;
}

#define XQUERY_LOCAL_FUNCTIONS_NS \
  "{http://www.w3.org/2005/xquery-local-functions}"


/**
  * @brief tests, if the call stack is filled correctly, if a
  *        user error is thrown.
  */
bool test_call_stack1(Zorba* aZorba)
{
  std::stringstream lStream;
  lStream << "declare function local:test($a)" "\n";
  lStream << "{" "\n";
  lStream << "  fn:error(xs:QName(\"local:blubb\"))" "\n";
  lStream << "};" "\n";
  lStream << "" "\n";
  lStream << "declare function local:test1($a)" "\n";
  lStream << "{" "\n";
  lStream << "  local:test($a)" "\n";
  lStream << "};" "\n";
  lStream << "" "\n";
  lStream << "local:test1(\"blubb\")" "\n";
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (XQueryException const& e) {
    XQueryStackTrace const &lTrace = e.query_trace();
    if (lTrace.size() != 2)
      return false;
    XQueryStackTrace::const_iterator it = lTrace.begin();
    if ( !equals( *it, XQUERY_LOCAL_FUNCTIONS_NS "test", 8, 3 ) )
      return false;
    if ( !equals( *++it, XQUERY_LOCAL_FUNCTIONS_NS "test1", 11, 1 ) )
      return false;
  } catch (...) {
    return false;
  }
  return true;
}

/**
  * @brief tests, if the call stack is filled correctly, if a
  *        runtime error is thrown.
  */
bool test_call_stack2(Zorba* aZorba)
{
  std::stringstream lStream;
  lStream << "declare function local:test($a)" "\n";
  lStream << "{" "\n";
  lStream << "  blubb" "\n";
  lStream << "};" "\n";
  lStream << "" "\n";
  lStream << "declare function local:test1($a)" "\n";
  lStream << "{" "\n";
  lStream << "  local:test($a)" "\n";
  lStream << "};" "\n";
  lStream << "" "\n";
  lStream << "local:test1(\"blubb\")" "\n";
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (XQueryException const& e) {
    XQueryStackTrace const &lTrace = e.query_trace();
    if (lTrace.size() != 2)
      return false;
    XQueryStackTrace::const_iterator it = lTrace.begin();
    if ( !equals( *it, XQUERY_LOCAL_FUNCTIONS_NS "test", 8, 3 ) )
      return false;
    if ( !equals( *++it, XQUERY_LOCAL_FUNCTIONS_NS "test1", 11, 1 ) )
      return false;
  } catch (...) {
    return false;
  }
  return true;
}

/**
  * @brief This is a test, to see if the call stack still works if
  *        the optimizer does some hoisting.
  */
bool test_call_stack3(Zorba* aZorba)
{
  std::stringstream lStream;
  lStream << "declare function local:test() {" "\n";
  lStream << "  fn:error(xs:QName(\"local:blubb\"))" "\n";
  lStream << "};" "\n";
  lStream << "" "\n";
  lStream << "for $x in (1,2,3)" "\n";
  lStream << "return" "\n";
  lStream << "  $x * local:test()" "\n";
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (XQueryException const& e) {
    XQueryStackTrace const &lTrace = e.query_trace();
    if (lTrace.size() != 1)
      return false;
    if ( !equals( *lTrace.begin(), XQUERY_LOCAL_FUNCTIONS_NS "test", 7, 8 ) )
      return false;
  } catch (...) {
    return false;
  }
  return true;
}

bool test_call_stack4(Zorba* aZorba)
{
  std::stringstream lStream;
  lStream << "declare variable $a := 3;" "\n";
  lStream << "" "\n";
  lStream << "declare function local:foo()" "\n";
  lStream << "{" "\n";
  lStream << "   $a + $a, blubb" "\n";
  lStream << "};" "\n";
  lStream << "" "\n";
  lStream << "for $i in 1 to 10" "\n";
  lStream << "return local:foo()" "\n";
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (XQueryException const& e) {
    XQueryStackTrace const &lTrace = e.query_trace();
    if (lTrace.size() != 1)
      return false;
    if ( !equals( *lTrace.begin(), XQUERY_LOCAL_FUNCTIONS_NS "foo", 9, 8 ) )
      return false;
  } catch (...) {
    return false;
  }
  return true;
}

// error must only be added to the stack trace if throw 
// in the scope of the function's body.
bool test_call_stack5(Zorba* aZorba)
{
  std::stringstream lStream;
  lStream << "declare function local:foo($x)" "\n";
  lStream << "{" "\n";
  lStream << "  $x" "\n";
  lStream << "};" "\n";
  lStream << "" "\n";
  lStream << "let $x := fn:error(xs:QName('local:foo'))" "\n";
  lStream << "return local:foo($x)" "\n";
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (XQueryException const& e) {
    XQueryStackTrace const &lTrace = e.query_trace();
    if (!lTrace.empty())
      return false;
  } catch (...) {
    return false;
  }
  return true;
}

bool test_call_stack6(Zorba* aZorba)
{
  std::stringstream lStream;
  lStream << "declare function local:foo($x)" "\n";
  lStream << "{" "\n";
  lStream << "  $x" "\n";
  lStream << "};" "\n";
  lStream << "" "\n";
  lStream << "declare function local:bar($x)" "\n";
  lStream << "{" "\n";
  lStream << "  local:foo($x)" "\n";
  lStream << "};" "\n";
  lStream << "" "\n";
  lStream << "let $x := fn:error(xs:QName('local:foo'))" "\n";
  lStream << "return local:bar($x)" "\n";
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (XQueryException const& e) {
    XQueryStackTrace const &lTrace = e.query_trace();
    if (!lTrace.empty())
      return false;
  } catch (...) {
    return false;
  }
  return true;
}

bool test_call_stack7(Zorba* aZorba)
{
  std::stringstream lStream;
  lStream << "declare function local:foo($x)";
  lStream << "{";
  lStream << "  $x";
  lStream << "};";
  lStream << "";
  lStream << "declare function local:bar($x)";
  lStream << "{";
  lStream << "  local:foo($x)";
  lStream << "};";
  lStream << "";
  lStream << "let $x := fn:error(xs:QName('local:foo'))";
  lStream << "return local:bar($x)";
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (XQueryException const& e) {
    XQueryStackTrace const &lTrace = e.query_trace();
    if (!lTrace.empty())
      return false;
  } catch (...) {
    return false;
  }
  return true;
}

int call_stack (int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  std::cout << "test1" << std::endl;
  if (!test_call_stack1(lZorba))
    return 1;
  std::cout << "test2" << std::endl;
  if (!test_call_stack2(lZorba))
    return 1;
  std::cout << "test3" << std::endl;
  if (!test_call_stack3(lZorba))
    return 1;
  std::cout << "test4" << std::endl;
  if (!test_call_stack4(lZorba))
    return 1;
  std::cout << "test5" << std::endl;
  if (!test_call_stack5(lZorba))
    return 1;
  std::cout << "test6" << std::endl;
  if (!test_call_stack6(lZorba))
    return 1;
  std::cout << "test7" << std::endl;
  if (!test_call_stack7(lZorba))
    return 1;
  return 0;
}
/* vim:set et sw=2 ts=2: */
