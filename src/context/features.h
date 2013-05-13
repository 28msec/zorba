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
#ifndef ZORBA_CONTEXT_FEATURES_H
#define ZORBA_CONTEXT_FEATURES_H

#include <iostream>

///////////////////////////////////////////////////////////////////////////////

namespace zorba {

  namespace feature {

    enum kind {
      ddl         = 1,
      scripting   = 4,
      trace       = 8,
      dtd         = 16,
      http_resolution = 32,
    };

    bool kind_for( char const*, kind& );

  }

} // namespace zorba

#endif
/* vim:set et sw=2 ts=2: */
