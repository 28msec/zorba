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

#pragma once
#ifndef ZORBA_COMPILER_EXPR_FACTORY_H
#define ZORBA_COMPILER_EXPR_FACTORY_H

#include memory_manager.h

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/*
 * Creates all Exprs and deletes them at it's deletion.
 */
class ExprFactory
{

public:
  ExprFactory(){};
  ~ExprFactory(){};
private:
  MemManager memory;
  std::list<expr*> exprList;
public:
  //Here all createType functions are
};

} // namespace zorba

#endif /*ZORBA_COMPILER_EXPR_FACTORY_H*/
/* vim:set et sw=2 ts=2: */
