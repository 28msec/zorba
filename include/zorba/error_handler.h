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
#ifndef ZORBA_ERROR_HANDLER_API_H
#define ZORBA_ERROR_HANDLER_API_H

#include <zorba/exception.h>

namespace zorba {

  class ErrorHandler 
  {
    public:
      virtual ~ErrorHandler() {}

      virtual void
      staticError ( const StaticException& aStaticError ) = 0;

      virtual void
      dynamicError ( const DynamicException& aDynamicError ) = 0;

      virtual void
      typeError ( const TypeException& aTypeError ) = 0;

      virtual void
      serializationError ( const  SerializationException& aSerializationError ) = 0;

      virtual void
      systemError ( const SystemException& aSystemError ) = 0;
   };

} /* namespace zorba */

#endif
