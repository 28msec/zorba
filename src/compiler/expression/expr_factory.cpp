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

#include expr_factory.h
#include memory_manager.h

namespace zorba {

ExprFactory(){};

~ExprFactory()
{
  for(std::list<expr*>::iterator ite = exprList.begin();
    ite != exprList.end();
    ++ite)
  {
    *ite->~expr();
  }
}

//Macro to generate an expr of type TYPE with the args following
#define returnNewExpr(TYPE, ...) \
  void *mem = memory.allocate(sizeof(TYPE)); \
  TYPE *newExpr = new(mem) TYPE(__VA_ARGS__); \
  return newExpr;

} // namespace zorba
