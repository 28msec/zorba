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

#include "compiler/parser/query_loc.h"

#include <ostream>

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

#ifdef ZORBA_DEBUGGER
 xqpString QueryLoc::toJSON() const
 {
  std::stringstream lJSONString;
  std::string lTmp( theFilenameBegin );
  std::string lFileName;
  std::string::iterator it;
  for(it=lTmp.begin(); it!=lTmp.end(); it++)
  {
    if ( *it == '\\' )
    {
      lFileName.append(1, *it);
    }
    lFileName.append(1, *it);
  } 
  lJSONString << "{";
  lJSONString << "\"fileName\":\"" << lFileName << "\",";
  lJSONString << "\"lineBegin\":" << theLineBegin << ",";
  lJSONString << "\"columnBegin\":" << theColumnBegin << ",";
  lJSONString << "\"lineEnd\":" << theLineEnd << ",";
  lJSONString << "\"columnEnd\":" << theColumnEnd;
  lJSONString << "}";
  return lJSONString.str();
 }

 QueryLoc QueryLoc::fromJSON(json::value *obj)
 {
    QueryLoc loc; 
    if ( (*obj)["fileName"] != 0 )
    {
      std::wstring *lFileName = (*obj)["fileName"]->getstring(L"", true);
      std::string filename( lFileName->begin()+1, lFileName->end()-1 );
      loc.setFilenameBegin( &filename );
      delete lFileName;
    }
    
    if ( (*obj)["lineBegin"] != 0 )
    {
      loc.setLineBegin( (*obj)["lineBegin"]->getinteger() );
    }
    
    if ( (*obj)["columnBegin"] != 0 )
    {
      loc.setColumnBegin( (*obj)["columnBegin"]->getinteger() );
    }

    if ( (*obj)["lineEnd"] != 0 )
    {
      loc.setLineEnd( (*obj)["lineEnd"]->getinteger() );
    }

    if ( (*obj)["columnEnd"] != 0 )
    {
      loc.setColumnEnd( (*obj)["columnEnd"]->getinteger() );
    }
    return loc;
 }
#endif
} // namespace zorba
