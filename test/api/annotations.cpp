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
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string.h>

#include <zorba/zorba.h>
#include <zorba/annotation.h>
#include <zorba/store_manager.h>
#include <zorba/serializer.h>
#include <zorba/singleton_item_sequence.h>

using namespace zorba;


const char query_1[] = "\
declare %public function local:public() \
{   \
  1 \
};  \
local:public()  \
";

const char query_2[] = "\
declare namespace test = \"test\"; \
declare %test:custom(123, \"string literal\", 456, \"just random\") function local:func() \
{     \
  1   \
};    \
local:func() \
";


bool
test_annotations_1(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery(query_1);
  const StaticContext* sctx = lQuery->getStaticContext();

  Item lQName = aZorba->getItemFactory()->createQName("http://www.w3.org/2005/xquery-local-functions", "public");
  std::vector<Annotation_t> annotations;
  sctx->getFunctionAnnotations(lQName, 0, annotations);

  if (annotations.size() != 1)
    return false;

  if (annotations[0]->getQName().getStringValue() != "public")
    return false;

	return true;
}


bool
test_annotations_2(Zorba* aZorba)
{
  XQuery_t lQuery = aZorba->compileQuery(query_2);
  const StaticContext* sctx = lQuery->getStaticContext();

  Item lQName = aZorba->getItemFactory()->createQName("http://www.w3.org/2005/xquery-local-functions", "func");
  std::vector<Annotation_t> annotations;
  sctx->getFunctionAnnotations(lQName, 0, annotations);

  if (annotations.size() != 1)
    return false;

  std::string result;
  result += annotations[0]->getQName().getStringValue().c_str();

  for (unsigned int i=0; i<annotations[0]->getLiteralsCount(); i++)
  {
    result += " ";
    result += annotations[0]->getLiteral(i).getStringValue().c_str();
  }
  
  if (result != "test:custom 123 string literal 456 just random")
    return false;

  return true;
}


int
annotations(int argc, char* argv[])
{
  Zorba* lZorba = Zorba::getInstance(zorba::StoreManager::getStore());

  if (!test_annotations_1(lZorba))
    return 1;

  if (!test_annotations_2(lZorba))
    return 1;

  return 0;
}
