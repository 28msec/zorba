#ifndef ZORBA_EXCEPTION_API_H
#define ZORBA_EXCEPTION_API_H

#include <zorba/error.h>
#include <zorba/zorbastring.h>

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
      friend class ZorbaImpl;
      ZorbaException(const ZorbaError::ErrorCode&, const String& aDescription);
      ZorbaError::ErrorCode theErrorCode;
      String                theDescription;
  }; /* class ZorbaException */

  class QueryException : public ZorbaException 
  {
    public:
      virtual ~QueryException() throw();

      virtual String
      getFileName() const;

      virtual unsigned int
      getLineBegin() const;

      virtual unsigned int
      getColumnBegin() const;

    protected:
      friend std::ostream& operator<<(std::ostream&, const QueryException&);
      friend class ZorbaImpl;
      QueryException(const ZorbaError::ErrorCode&, const String& aDescription, 
                     const String& afilename, unsigned int linebegin, unsigned int columnbegin);
      String                theFileName;
      unsigned int          theLineBegin;
      unsigned int          theColumnBegin;
  };

  class DynamicException : public QueryException
  {
    friend std::ostream& operator<<(std::ostream&, const DynamicException&);
    public:
      DynamicException(const ZorbaError::ErrorCode&, const String&,
                       const String& afilename, unsigned int linebegin, unsigned int columnbegin);
      virtual ~DynamicException() throw();

  }; /* class DynamicException */

  class StaticException : public QueryException
  {
    friend std::ostream& operator<<(std::ostream&, const StaticException&);
    public:
      StaticException(const ZorbaError::ErrorCode&, const String&,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin);
      virtual ~StaticException() throw();

  }; /* class StaticException */

  class TypeException : public QueryException
  {
    friend std::ostream& operator<<(std::ostream&, const TypeException&);
    public:
      TypeException(const ZorbaError::ErrorCode&, const String&,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin);
      virtual ~TypeException() throw();

  }; /* class TypeException */

  class SerializationException : public QueryException
  {
    friend std::ostream& operator<<(std::ostream&, const SerializationException&);
    public:
      SerializationException(const ZorbaError::ErrorCode&, const String&,
                      const String& afilename, unsigned int linebegin, unsigned int columnbegin);
      virtual ~SerializationException() throw();

  }; /* class SerializationException */

  class SystemException : public ZorbaException
  {
    friend std::ostream& operator<<(std::ostream&, const ZorbaException&);
    public:
      SystemException(const ZorbaError::ErrorCode&, const String&);
      virtual ~SystemException() throw();

  }; /* class SystemException */

  std::ostream& operator<< (std::ostream& os, const ZorbaException& aException);
  std::ostream& operator<< (std::ostream& os, const QueryException& aException);
  std::ostream& operator<< (std::ostream& os, const StaticException& aException);
  std::ostream& operator<< (std::ostream& os, const DynamicException& aException);
  std::ostream& operator<< (std::ostream& os, const TypeException& aException);
  std::ostream& operator<< (std::ostream& os, const SerializationException& aException);
  std::ostream& operator<< (std::ostream& os, const SystemException& aException);

} /* namespace zorba */
#endif
