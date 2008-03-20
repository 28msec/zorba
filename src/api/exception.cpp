#ifndef ZORBA_EXCEPTION_H
#define ZORBA_EXCEPTION_H

#include <ostream>
#include <zorba/exception.h>
#include <zorba/error.h>
#include <zorba/string.h>

namespace zorba {

  ZorbaException::ZorbaException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription)
    : theErrorCode(aErrorCode),
      theDescription(aDescription) {}

  ZorbaException::~ZorbaException() throw() { }

  ZorbaError::ErrorCode
  ZorbaException::getErrorCode() const { return theErrorCode; }

  String
  ZorbaException::getDescription() const { return theDescription; }

  DynamicException::DynamicException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription)
    : ZorbaException(aErrorCode, aDescription) {}

  DynamicException::~DynamicException() throw()  { }

  StaticException::StaticException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription)
    : ZorbaException(aErrorCode, aDescription) {}

  StaticException::~StaticException() throw() { }


  TypeException::TypeException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription)
    : ZorbaException(aErrorCode, aDescription) {}

  TypeException::~TypeException() throw() { }

  SerializationException::SerializationException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription)
    : ZorbaException(aErrorCode, aDescription) {}

  SerializationException::~SerializationException() throw() { }

  SystemException::SystemException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription)
    : ZorbaException(aErrorCode, aDescription) {}

  SystemException::~SystemException() throw() { }

  std::ostream& operator<< (std::ostream& os, const ZorbaException& aException)
  {
    return os << "[" << ZorbaError::getErrorCode(aException.getErrorCode()) 
              << "] " << aException.getDescription();
  }

  std::ostream& operator<< (std::ostream& os, const DynamicException& aException)
  {
    return os << (ZorbaException)aException;
  }

  std::ostream& operator<< (std::ostream& os, const StaticException& aException)
  {
    return os << (ZorbaException)aException;
  }

  std::ostream& operator<< (std::ostream& os, const TypeException& aException)
  {
    return os << (ZorbaException)aException;
  }

  std::ostream& operator<< (std::ostream& os, const SerializationException& aException)
  {
    return os << (ZorbaException)aException;
  }

  std::ostream& operator<< (std::ostream& os, const SystemException& aException)
  {
    return os << (ZorbaException)aException;
  }


} /* namespace zorba */

#endif
