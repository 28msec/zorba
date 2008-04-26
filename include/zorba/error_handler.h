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
