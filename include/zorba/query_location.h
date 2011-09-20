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

#ifndef QUERYLOCATION_H
#define QUERYLOCATION_H

#include <zorba/config.h>
#include <zorba/smart_ptr.h>
#include <zorba/api_shared_types.h>

namespace zorba{

  /**
   * Representation of the current location location
   * in the remote query.
   * This location goes from the starting line and column
   * to the ending line and column.
   */
  class ZORBA_DLL_PUBLIC QueryLocation: public SmartObject
  {
    public:

      virtual
      ~QueryLocation(){}

      virtual String
      getFileName() const = 0;

      virtual unsigned int
      getLineBegin() const = 0;

      virtual unsigned int
      getLineEnd() const = 0;

      virtual unsigned int
      getColumnBegin() const = 0;

      virtual unsigned int
      getColumnEnd() const = 0;

      virtual String
      toString() const = 0;
  };

} // namespace zorba

#endif // QUERYLOCATION_H
/* vim:set et sw=2 ts=2: */
