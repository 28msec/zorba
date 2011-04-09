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

#include <sstream>

#include "utils.h"

namespace zorba { namespace debugger {
  zstring queryLocToJSON( const QueryLoc& aLoc )
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

zorba::QueryLoc fromJSONToQueryLoc(json_t* aLocJ)
{
  QueryLoc lLoc;
  json_t* lTmpObj = json_object_get(aLocJ, "fileName");
  if (lTmpObj != 0) {
    std::string lFileName(json_string_value(lTmpObj));
    std::string::iterator it;
    for (it = lFileName.begin(); it != lFileName.end(); it++) {
      if (*it == '\\') {
        lFileName.erase(it);
        ++it;
      }
    } 
    lLoc.setFilename(lFileName);
  }

  lTmpObj = json_object_get(aLocJ, "lineBegin");
  if (lTmpObj != 0) {
    lLoc.setLineBegin((unsigned int)(json_integer_value(lTmpObj)));
  }

  lTmpObj = json_object_get(aLocJ, "columnBegin");
  if (lTmpObj != 0) {
    lLoc.setColumnBegin((unsigned int)(json_integer_value(lTmpObj)));
  }

  lTmpObj = json_object_get(aLocJ, "lineEnd");
  if (lTmpObj != 0) {
    lLoc.setLineEnd((unsigned int)(json_integer_value(lTmpObj)));
  }

  lTmpObj = json_object_get(aLocJ, "columnEnd");
  if (lTmpObj != 0) {
    lLoc.setColumnEnd((unsigned int)(json_integer_value(lTmpObj)));
  }

  return lLoc;
}

}} // namespace zorba, debugger
