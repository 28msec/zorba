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
#include <zorba/store_manager.h>

using namespace zorba;


/**
  * @brief tests, if the call stack is filled correctly, if a
  *        user error is thrown.
  */
bool test_call_stack1(Zorba* aZorba)
{
  bool lResult = true;
  std::stringstream lStream;
  lStream << "declare function local:test($a)" << std::endl;
  lStream << "{" << std::endl;
  lStream << "  fn:error(xs:QName(\"local:blubb\"))" << std::endl;
  lStream << "};" << std::endl;
  lStream << "" << std::endl;
  lStream << "declare function local:test1($a)" << std::endl;
  lStream << "{" << std::endl;
  lStream << "  local:test($a)" << std::endl;
  lStream << "};" << std::endl;
  lStream << "" << std::endl;
  lStream << "local:test1(\"blubb\")" << std::endl;
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (ZorbaException& e) {
    ZorbaException::StackTrace_t lTrace = e.getStackTrace();
    if (lTrace.size() != 2)
      return false;
    Item lQName = lTrace[0].getFunctionName();
    if (lQName.getNamespace() != "http://www.w3.org/2005/xquery-local-functions")
      lResult = false;
    if (lQName.getLocalName() != "test")
      lResult = false;
    lQName = lTrace[1].getFunctionName();
    if (lQName.getNamespace() != "http://www.w3.org/2005/xquery-local-functions")
      lResult = false;
    if (lQName.getLocalName() != "test1")
      lResult = false;
  } catch (...) {
    lResult = false;
  }
  return lResult;
}

/**
  * @brief tests, if the call stack is filled correctly, if a
  *        runtime error is thrown.
  */
bool test_call_stack2(Zorba* aZorba)
{
  bool lResult = true;
  std::stringstream lStream;
  lStream << "declare function local:test($a)" << std::endl;
  lStream << "{" << std::endl;
  lStream << "  blubb" << std::endl;
  lStream << "};" << std::endl;
  lStream << "" << std::endl;
  lStream << "declare function local:test1($a)" << std::endl;
  lStream << "{" << std::endl;
  lStream << "  local:test($a)" << std::endl;
  lStream << "};" << std::endl;
  lStream << "" << std::endl;
  lStream << "local:test1(\"blubb\")" << std::endl;
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (ZorbaException& e) {
    ZorbaException::StackTrace_t lTrace = e.getStackTrace();
    if (lTrace.size() != 2)
      return false;
    Item lQName = lTrace[0].getFunctionName();
    if (lQName.getNamespace() != "http://www.w3.org/2005/xquery-local-functions")
      lResult = false;
    if (lQName.getLocalName() != "test")
      lResult = false;
    lQName = lTrace[1].getFunctionName();
    if (lQName.getNamespace() != "http://www.w3.org/2005/xquery-local-functions")
      lResult = false;
    if (lQName.getLocalName() != "test1")
      lResult = false;
  } catch (...) {
    lResult = false;
  }
  return lResult;
}

/**
  * @brief This is a test, to see if the call stack still works if
  *        the optimizer does some hoisting.
  */
bool test_call_stack3(Zorba* aZorba)
{
  bool lResult = true;
  std::stringstream lStream;
  lStream << "declare function local:test() {" << std::endl;
  lStream << "  fn:error(xs:QName(\"local:blubb\"))" << std::endl;
  lStream << "};" << std::endl;
  lStream << "" << std::endl;
  lStream << "for $x in (1,2,3)" << std::endl;
  lStream << "return" << std::endl;
  lStream << "  $x * local:test()" << std::endl;
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (ZorbaException& e) {
    ZorbaException::StackTrace_t lTrace = e.getStackTrace();
    if (lTrace.size() != 1)
      return false;
    Item lQName = lTrace[0].getFunctionName();
    if (lQName.getNamespace() != "http://www.w3.org/2005/xquery-local-functions")
      lResult = false;
    if (lQName.getLocalName() != "test")
      lResult = false;
  } catch (...) {
    lResult = false;
  }
  return lResult;
}

bool test_call_stack4(Zorba* aZorba)
{
  bool lResult = true;
  std::stringstream lStream;
  lStream << "declare variable $a := 3;" << std::endl;
  lStream << "" << std::endl;
  lStream << "declare function local:foo()" << std::endl;
  lStream << "{" << std::endl;
  lStream << "   $a + $a, blubb" << std::endl;
  lStream << "};" << std::endl;
  lStream << "" << std::endl;
  lStream << "for $i in 1 to 10" << std::endl;
  lStream << "return local:foo()" << std::endl;
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (ZorbaException& e) {
    ZorbaException::StackTrace_t lTrace = e.getStackTrace();
    if (lTrace.size() != 1)
      return false;
    Item lQName = lTrace[0].getFunctionName();
    if (lQName.getNamespace() != "http://www.w3.org/2005/xquery-local-functions")
      lResult = false;
    if (lQName.getLocalName() != "foo")
      lResult = false;
  } catch (...) {
    lResult = false;
  }
  return lResult;
}

// error must only be addd to the stack trace if throw 
// in the scope of the function's body.
bool test_call_stack5(Zorba* aZorba)
{
  bool lResult = true;
  std::stringstream lStream;
  lStream << "declare function local:foo($x)" << std::endl;
  lStream << "{" << std::endl;
  lStream << "  $x" << std::endl;
  lStream << "};" << std::endl;
  lStream << "" << std::endl;
  lStream << "let $x := fn:error(xs:QName('local:foo'))" << std::endl;
  lStream << "return local:foo($x)" << std::endl;
  XQuery_t lQuery = aZorba->compileQuery(lStream);
  try {
    std::stringstream lQueryResult;
    lQueryResult << lQuery;
  } catch (ZorbaException& e) {
    ZorbaException::StackTrace_t lTrace = e.getStackTrace();
    if (lTrace.size() != 0)
      lResult = false;
  } catch (...) {
    lResult = false;
  }
  return lResult;
}

int call_stack (int argc, char* argv[])
{
  void* lStore = zorba::StoreManager::getStore();
  Zorba* lZorba = Zorba::getInstance(lStore);
  if (!test_call_stack1(lZorba))
    return 1;
  if (!test_call_stack2(lZorba))
    return 1;
  if (!test_call_stack3(lZorba))
    return 1;
  if (!test_call_stack4(lZorba))
    return 1;
  if (!test_call_stack5(lZorba))
    return 1;
  return 0;
}
