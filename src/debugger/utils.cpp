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
#include <json/value.h>
#include "utils.h"

namespace zorba { namespace debugger {
  zorba::xqpString queryLocToJSON( const QueryLoc& aLoc )
  {
    std::stringstream lJSONString;
    std::string lTmp( aLoc.getFilename().c_str() );
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
    lJSONString << "\"lineBegin\":" << aLoc.getLineBegin() << ",";
    lJSONString << "\"columnBegin\":" << aLoc.getColumnBegin() << ",";
    lJSONString << "\"lineEnd\":" << aLoc.getLineEnd() << ",";
    lJSONString << "\"columnEnd\":" << aLoc.getColumnEnd();
    lJSONString << "}";
    return lJSONString.str();
  }

  zorba::QueryLoc fromJSONToQueryLoc( json::value *obj )
  {
    QueryLoc loc; 
    if ( (*obj)["fileName"] != 0 )
    {
      std::wstring *lFileName = (*obj)["fileName"]->getstring(L"", true);
      std::string filename( lFileName->begin()+1, lFileName->end()-1 );
      std::string::iterator it;
      for (it = filename.begin(); it != filename.end(); it++) {
        if (*it == '\\') {
          filename.erase(it);
          ++it;
        }
      } 
      loc.setFilename( filename );
      delete lFileName;
    }

    if ( (*obj)["lineBegin"] != 0 )
    {
      loc.setLineBegin( (unsigned int)((*obj)["lineBegin"]->getinteger() ));
    }

    if ( (*obj)["columnBegin"] != 0 )
    {
      loc.setColumnBegin( (unsigned int)((*obj)["columnBegin"]->getinteger() ));
    }

    if ( (*obj)["lineEnd"] != 0 )
    {
      loc.setLineEnd( (unsigned int)((*obj)["lineEnd"]->getinteger() ));
    }

    if ( (*obj)["columnEnd"] != 0 )
    {
      loc.setColumnEnd( (unsigned int)((*obj)["columnEnd"]->getinteger() ));
    }
    return loc;
  }
}} // namespace zorba, debugger
