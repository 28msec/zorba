#ifndef ZORBA_EXCEPTION_H
#define ZORBA_EXCEPTION_H

#include <ostream>
#include <zorba/exception.h>
#include <zorba/error.h>
#include <zorba/string.h>

namespace zorba {

  ZorbaException::ZorbaException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                                 const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : theErrorCode(aErrorCode),
      theDescription(aDescription),
      theFileName(afilename),
      theLineBegin(linebegin),
      theColumnBegin(columnbegin) {}

  ZorbaException::~ZorbaException() throw() { }

  ZorbaError::ErrorCode
  ZorbaException::getErrorCode() const { return theErrorCode; }

  String
  ZorbaException::getDescription() const { return theDescription; }

  String
  ZorbaException::getFileName() const { return theFileName; }

  unsigned int
  ZorbaException::getLineBegin() const { return theLineBegin; }

  unsigned int
  ZorbaException::getColumnBegin() const { return theColumnBegin; }

  DynamicException::DynamicException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : ZorbaException(aErrorCode, aDescription, afilename, linebegin, columnbegin) {}

  DynamicException::~DynamicException() throw()  { }

  StaticException::StaticException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : ZorbaException(aErrorCode, aDescription, afilename, linebegin, columnbegin) {}

  StaticException::~StaticException() throw() { }


  TypeException::TypeException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : ZorbaException(aErrorCode, aDescription, afilename, linebegin, columnbegin) {}

  TypeException::~TypeException() throw() { }

  SerializationException::SerializationException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : ZorbaException(aErrorCode, aDescription, afilename, linebegin, columnbegin) {}

  SerializationException::~SerializationException() throw() { }

  SystemException::SystemException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : ZorbaException(aErrorCode, aDescription, afilename, linebegin, columnbegin) {}

  SystemException::~SystemException() throw() { }

  std::ostream& operator<< (std::ostream& os, const ZorbaException& aException)
  {
    return os << "Error on line " << aException.getLineBegin() << " column " << aException.getColumnBegin() << std::endl
           << "[" << ZorbaError::getErrorCode(aException.getErrorCode()) << "] " << aException.getDescription();
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
