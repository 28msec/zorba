#ifndef ZORBA_EXCEPTION_API_H
#define ZORBA_EXCEPTION_API_H

#include <zorba/error.h>
#include <zorba/string.h>

namespace zorba {

  class ZorbaException
  {
    public:
      virtual ~ZorbaException() throw();

      virtual ZorbaError::ErrorCode
      getErrorCode() const;

      virtual String
      getDescription() const;

    protected:
      ZorbaException(const ZorbaError::ErrorCode&, const String&);
      ZorbaError::ErrorCode theErrorCode;
      String                theDescription;

  }; /* class ZorbaException */

  class DynamicException : public ZorbaException
  {
    friend std::ostream& operator<<(std::ostream&, const DynamicException&);
    public:
      DynamicException(const ZorbaError::ErrorCode&, const String&);
      virtual ~DynamicException() throw();

  }; /* class DynamicException */

  class StaticException : public ZorbaException
  {
    friend std::ostream& operator<<(std::ostream&, const StaticException&);
    public:
      StaticException(const ZorbaError::ErrorCode&, const String&);
      virtual ~StaticException() throw();

  }; /* class StaticException */

  class TypeException : public ZorbaException
  {
    friend std::ostream& operator<<(std::ostream&, const TypeException&);
    public:
      TypeException(const ZorbaError::ErrorCode&, const String&);
      virtual ~TypeException() throw();

  }; /* class TypeException */

  class SerializationException : public ZorbaException
  {
    friend std::ostream& operator<<(std::ostream&, const SerializationException&);
    public:
      SerializationException(const ZorbaError::ErrorCode&, const String&);
      virtual ~SerializationException() throw();

  }; /* class SerializationException */

  class SystemException : public ZorbaException
  {
    friend std::ostream& operator<<(std::ostream&, const SystemException&);
    public:
      SystemException(const ZorbaError::ErrorCode&, const String&);
      virtual ~SystemException() throw();

  }; /* class SystemException */

  std::ostream& operator<< (std::ostream& os, const ZorbaException& aException);
  std::ostream& operator<< (std::ostream& os, const StaticException& aException);
  std::ostream& operator<< (std::ostream& os, const DynamicException& aException);
  std::ostream& operator<< (std::ostream& os, const TypeException& aException);
  std::ostream& operator<< (std::ostream& os, const SerializationException& aException);
  std::ostream& operator<< (std::ostream& os, const SystemException& aException);

} /* namespace zorba */
#endif
