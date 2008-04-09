#ifndef ZORBA_EXCEPTION_H
#define ZORBA_EXCEPTION_H

#include <ostream>
#include <zorba/exception.h>
#include <zorba/error.h>
#include <zorba/zorbastring.h>

namespace zorba {

  ZorbaException::ZorbaException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription)
    : theErrorCode(aErrorCode),
      theDescription(aDescription) {}

  ZorbaException::~ZorbaException() throw() { }

  ZorbaError::ErrorCode
  ZorbaException::getErrorCode() const { return theErrorCode; }

  String
  ZorbaException::getDescription() const { return theDescription; }

  QueryException::QueryException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                                 const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : ZorbaException(aErrorCode, aDescription),
      theFileName(afilename),
      theLineBegin(linebegin),
      theColumnBegin(columnbegin) {}

  QueryException::~QueryException() throw() { }

  String
  QueryException::getFileName() const { return theFileName; }

  unsigned int
  QueryException::getLineBegin() const { return theLineBegin; }

  unsigned int
  QueryException::getColumnBegin() const { return theColumnBegin; }

  DynamicException::DynamicException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : QueryException(aErrorCode, aDescription, afilename, linebegin, columnbegin) {}

  DynamicException::~DynamicException() throw()  { }

  StaticException::StaticException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : QueryException(aErrorCode, aDescription, afilename, linebegin, columnbegin) {}

  StaticException::~StaticException() throw() { }


  TypeException::TypeException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : QueryException(aErrorCode, aDescription, afilename, linebegin, columnbegin) {}

  TypeException::~TypeException() throw() { }

  SerializationException::SerializationException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin)
    : QueryException(aErrorCode, aDescription, afilename, linebegin, columnbegin) {}

  SerializationException::~SerializationException() throw() { }

  SystemException::SystemException(const ZorbaError::ErrorCode& aErrorCode, const String& aDescription)
    : ZorbaException(aErrorCode, aDescription) {}

  SystemException::~SystemException() throw() {}

  std::ostream& operator<< (std::ostream& os, const ZorbaException& aException)
  {
    return os << "[" << ZorbaError::getErrorCode(aException.getErrorCode()) << "] " 
              << aException.getDescription();
  }

  std::ostream& operator<< (std::ostream& os, const QueryException& aException)
  {
    return os << "Error on line " << aException.getLineBegin() 
        << " column " << aException.getColumnBegin() + 1
        << ": " 
        << (ZorbaException)aException;
  }

  std::ostream& operator<< (std::ostream& os, const DynamicException& aException)
  {
    return os << (QueryException)aException;
  }

  std::ostream& operator<< (std::ostream& os, const StaticException& aException)
  {
    return os << (QueryException)aException;
  }

  std::ostream& operator<< (std::ostream& os, const TypeException& aException)
  {
    return os << (QueryException)aException;
  }

  std::ostream& operator<< (std::ostream& os, const SerializationException& aException)
  {
    return os << (QueryException)aException;
  }

  std::ostream& operator<< (std::ostream& os, const SystemException& aException)
  {
    return  os << (ZorbaException)aException;
  }


} /* namespace zorba */

#endif
