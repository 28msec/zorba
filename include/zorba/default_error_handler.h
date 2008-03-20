#ifndef ZORBA_DEFAULT_ERROR_HANDLER_API_H
#define ZORBA_DEFAULT_ERROR_HANDLER_API_H

#include <zorba/error_handler.h>

namespace zorba {

  class DefaultErrorHandler : public ErrorHandler
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
