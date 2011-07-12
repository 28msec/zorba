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
#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/rewriters/common_rewriter.h"
#include "compiler/rewriter/rewriters/phase1_rewriter.h"

namespace zorba {

Phase1Rewriter::Phase1Rewriter()
{
  ADD_SINGLETON_DRIVER(ExpandBuildIndex);
}

Phase1Rewriter::~Phase1Rewriter()
{
}

}
/* vim:set et sw=2 ts=2: */
