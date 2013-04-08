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
#include "stdafx.h"
#include <string>

#include "compiler/parser/zorba_parser_error.h"
#include "compiler/parser/parser_helpers.h"

namespace zorba
{

ZorbaParserError::ZorbaParserError(std::string _msg, Error const &code)
  :
  msg(_msg), err_code(code)
{
}

ZorbaParserError::ZorbaParserError(std::string _msg, const location& aLoc, Error const &code)
  :
  msg(_msg), loc(parser::createQueryLoc(aLoc)), err_code(code)
{
}

ZorbaParserError::ZorbaParserError(std::string _msg, const QueryLoc& aLoc, Error const &code)
  :
  msg(_msg), loc(aLoc), err_code(code)
{
}

}
