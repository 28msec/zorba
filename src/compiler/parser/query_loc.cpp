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

#include <ostream>
#include <sstream>

#include "compiler/parser/query_loc.h"

namespace zorba 
{

QueryLoc QueryLoc::null;


QueryLoc::QueryLoc()
 :
  theFilename(""),
  theLineBegin (0),
  theColumnBegin (0),
  theLineEnd (0),
  theColumnEnd (0)
{
}


QueryLoc::QueryLoc( zstring const &filename, line_type lineBegin,
                    line_type lineEnd, column_type columnBegin,
                    column_type columnEnd ) :
  theFilename(filename),
  theLineBegin(lineBegin),
  theColumnBegin(columnBegin),
  theLineEnd(lineEnd),
  theColumnEnd(columnEnd)
{
}


std::ostream& operator<<(std::ostream& aOstr, const QueryLoc& aQueryLoc) 
{
  if (!aQueryLoc.theFilename.empty())
  {
    aOstr << aQueryLoc.theFilename;
  }

  bool lPrintLines = aQueryLoc.theLineBegin != 0;
  bool lPrintColumns = aQueryLoc.theLineBegin && aQueryLoc.theLineEnd &&
      aQueryLoc.theColumnBegin && aQueryLoc.theColumnEnd;

  if (lPrintLines)
  {
    aOstr << ":" << aQueryLoc.theLineBegin;
    if (lPrintColumns)
      aOstr << "." << aQueryLoc.theColumnBegin;

    aOstr << "-" << (aQueryLoc.theLineEnd ? aQueryLoc.theLineEnd : aQueryLoc.theLineBegin);
    if (lPrintColumns)
      aOstr << "." << aQueryLoc.theColumnEnd;
  }

  return aOstr;
}


bool QueryLoc::equals(const QueryLoc& loc) const
{
  std::stringstream lFile;
  lFile << theFilename.c_str();
  std::string lFile1(lFile.str());
  std::string lFile2;
  std::string::iterator it;

  for (it = lFile1.begin(); it != lFile1.end(); ++it)
  {
    if (*it == '\\')
    {
      lFile2.append(1, *it);
      ++it;
      if (*it == '\\')
      {
        continue;
      }
    }
    lFile2.append(1, *it);
  }

  return (loc.getFilename() == lFile2 &&
          theColumnBegin == loc.getColumnBegin() &&
          theColumnEnd == loc.getColumnEnd() &&
          theLineBegin == loc.getLineBegin() &&
          theLineEnd == loc.getLineEnd());
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
