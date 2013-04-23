/*
 * Copyright 2013 The FLWOR Foundation.
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
#include "compiler/parser/query_loc.h"
#include "compiler/parser/location.hh"

namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_declare = "declare", *the_create = "create";

QueryLoc createQueryLoc(const location& aLoc)
{
  QueryLoc lLoc;
  lLoc.setFilename(aLoc.begin.filename->c_str());
  lLoc.setLineBegin(aLoc.begin.line);
  lLoc.setColumnBegin(aLoc.begin.column);
  lLoc.setLineEnd(aLoc.end.line);
  lLoc.setColumnEnd(aLoc.end.column);
  return lLoc;
}

} // namespace parser

} // namespace zorba
