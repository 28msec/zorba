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
#ifndef ZORBA_QUERY_LOCATIONIMPL
#define ZORBA_QUERY_LOCATIONIMPL

#include <zorba/debugger_event_handler.h>

#include "compiler/parser/query_loc.h"

namespace zorba {

  class QueryLocationImpl: public QueryLocation
  {
    private:
      QueryLoc theLocation;

    public:

      QueryLocationImpl( const QueryLoc & aLocation );

      virtual
      ~QueryLocationImpl(){}

      String getFileName() const; 

      unsigned int getLineBegin() const;

      unsigned int getLineEnd() const;

      unsigned int getColumnBegin() const;

      unsigned int getColumnEnd() const;

      String toString() const;
  };
}//end of namespace
#endif
