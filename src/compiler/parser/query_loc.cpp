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
#include <ostream>
#include "compiler/parser/query_loc.h"

namespace zorba {
QueryLoc QueryLoc::null;

QueryLoc::QueryLoc()
 : theFilenameBegin (""),
   theLineBegin (0),
   theColumnBegin (0),
   theFilenameEnd (""),
   theLineEnd (0),
   theColumnEnd (0)
{}

QueryLoc::QueryLoc(const QueryLoc& aQueryLoc) 
 : theFilenameBegin (aQueryLoc.theFilenameBegin),
   theLineBegin (aQueryLoc.theLineBegin),
   theColumnBegin (aQueryLoc.theColumnBegin),
   theFilenameEnd (aQueryLoc.theFilenameEnd),
   theLineEnd (aQueryLoc.theLineEnd),
   theColumnEnd (aQueryLoc.theColumnEnd)
{}

std::ostream& operator<< (std::ostream& aOstr, const QueryLoc& aQueryLoc) {
  if ( !aQueryLoc.getFilenameBegin().empty() ) {
    std::string lStr = aQueryLoc.getFilenameBegin();
    aOstr << lStr << ":";
  }
  aOstr << aQueryLoc.getLineBegin() << "." << aQueryLoc.getColumnBegin() << "-" << aQueryLoc.getColumnEnd();

  return aOstr;
}

} // namespace zorba
