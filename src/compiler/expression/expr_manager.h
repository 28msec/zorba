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
#ifndef ZORBA_COMPILER_EXPRMANAGER_H
#define ZORBA_COMPILER_EXPRMANAGER_H

#include "expr.h"

namespace zorba
{

class ExprManager
{
public:
  ExprManager();
  ~ExprManager();

  expr* reg(expr*);

private:
  std::list<expr*> theExprs;
};

} // namespace zorba

#endif // ZORBA_COMPILER_EXPRMANAGER_H
