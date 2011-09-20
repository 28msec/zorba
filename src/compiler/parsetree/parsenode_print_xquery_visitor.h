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
#pragma once
#ifndef ZORBA_PARSENODE_PRINT_XQUERY_VISITOR_H
#define ZORBA_PARSENODE_PRINT_XQUERY_VISITOR_H

#include <map>
#include <stack>

#include "common/shared_types.h"
#include "zorbatypes/zstring.h"

namespace zorba {
  typedef std::stack<zstring> Parameters;
  typedef std::map<zstring, Parameters> FunctionIndex;
  FunctionIndex print_parsetree_xquery(std::ostream&, const parsenode*);
}//namespace
#endif
/* vim:set et sw=2 ts=2: */
