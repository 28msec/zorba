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

#include "context/features.h"
#include "util/string_util.h"

namespace zorba {

  namespace feature {

    bool kind_for( char const* s, kind& res)
    {
      if ( ztd::equals(s, "ddl") )
      {
        res = ddl;
        return true;
      }
      else if ( ztd::equals(s, "scripting") )
      {
        res = scripting;
        return true;
      }
      else if ( ztd::equals(s, "hof") )
      {
        res = hof;
        return true;
      }
      else if ( ztd::equals(s, "trace") )
      {
        res = trace;
        return true;
      }
      else if ( ztd::equals(s, "dtd") )
      {
        res = dtd;
        return true;
      }
      return false;
    }
  }

}

/* vim:set et sw=2 ts=2: */

