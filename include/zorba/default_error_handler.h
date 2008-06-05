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
#ifndef ZORBA_DEFAULT_ERROR_HANDLER_API_H
#define ZORBA_DEFAULT_ERROR_HANDLER_API_H

#include <zorba/config.h>
#include <zorba/error_handler.h>

namespace zorba {

  class ZORBA_EXTERN_DECL DefaultErrorHandler : public ErrorHandler
  {
    public:
      virtual ~DefaultErrorHandler() {}

      virtual void
      staticError ( const StaticException& aStaticError );

      virtual void
      dynamicError ( const DynamicException& aDynamicError );

      virtual void
      typeError ( const TypeException& aTypeError );

      virtual void
      serializationError ( const SerializationException& aSerializationError );

      virtual void
      systemError ( const SystemException& aSystemError );

  }; /* class DefaultErrorHandler */

} /* namespace zorba */

#endif
