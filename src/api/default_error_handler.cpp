#include <zorba/default_error_handler.h>

#include <zorba/exception.h>

namespace zorba {

  void
  DefaultErrorHandler::staticError ( const StaticException& aStaticException )
  {
    throw aStaticException;
  }

  void
  DefaultErrorHandler::dynamicError ( const DynamicException& aDynamicException )
  {
    throw aDynamicException;
  }

  void
  DefaultErrorHandler::typeError ( const TypeException& aTypeException )
  {
    throw aTypeException;
  }

  void
  DefaultErrorHandler::serializationError ( const SerializationException& aSerializationException )
  {
    throw aSerializationException;
  }

  void
  DefaultErrorHandler::systemError ( const SystemException& aSystemException )
  {
    throw aSystemException;
  }

} /* namespace zorba */
