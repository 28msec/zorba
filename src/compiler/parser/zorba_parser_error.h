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
#ifndef ZORBA_PARSER_ERROR_H
#define ZORBA_PARSER_ERROR_H

#include <string>
#include "compiler/parser/query_loc.h"
#include "compiler/parser/location.hh"
#include "diagnostics/xquery_diagnostics.h"

namespace zorba {

class ZorbaParserError
{
public:
  std::string msg;
  QueryLoc loc;
  Error const &err_code;

public:
  ZorbaParserError(std::string _msg, Error const &code = err::XPST0003);
  ZorbaParserError(std::string _msg, const location& aLoc, Error const &code = err::XPST0003);
  ZorbaParserError(std::string _msg, const QueryLoc& aLoc, Error const &code = err::XPST0003);
};

}

#endif
