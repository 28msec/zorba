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
#ifndef ZORBA_EXCEPTION_API_H
#define ZORBA_EXCEPTION_API_H

#include <zorba/error.h>
#include <zorba/zorbastring.h>

namespace zorba {

/** \brief Base class of all exceptions thrown by %Zorba.
 */
class ZorbaException
{
 public:
  /** \brief Destructor
   */
  virtual ~ZorbaException() throw();

  /** \brief Get the ErrorCode of the error that is reported by this exception.
   */
  virtual ZorbaError::ErrorCode
  getErrorCode() const;

  /** \brief Get the descriptionof the error that is reported by this exception.
   */
  virtual String
  getDescription() const;

  /** \brief Get the name of the source file in which the error occured.
   *
   * Note that this information is mainly for debugging purposes.
   *
   * @return String the name of the file where the error occured.
   */
  virtual String
  getFileName() const;

  /** \brief Get the line number in the source file in which the error occured.
   *
   * Note that this information is mainly for debugging purposes.
   *
   * @return unsigned int the line number in the source file.
   */
  virtual unsigned int
  getFileLineNumber() const;


protected:
  friend class ZorbaImpl;
  /** \brief Proctected constructor - only the %Zorba engine can construct and throw
   *         exceptions.
   */
  ZorbaException(const ZorbaError::ErrorCode&, const String& aDescription,
                 const String& aFileName, unsigned int aFileLineNumber);

  ZorbaError::ErrorCode theErrorCode;
  String                theDescription;
  String                theFileName;
  unsigned int          theFileLineNumber;          
};

/** \brief QueryException is the base class for all errors that occur during query processing
 *         and have a direct connection to the query, i.e. information about the location
 *         where the error occured in the query is available.
 */
class QueryException : public ZorbaException 
{
 public:
  /** \brief Destructor
   */
  virtual ~QueryException() throw();

  /** \brief Get the line number in the query where the error occured.
   *
   * @return unsigned int the line number in the query.
   */
  virtual unsigned int
  getLineBegin() const;

  /** \brief Get the column number in the query where the error occured.
   *
   * @return unsigned int the column number in the query.
   */
  virtual unsigned int
  getColumnBegin() const;

protected:
  friend std::ostream& operator<<(std::ostream&, const QueryException&);
  friend class ZorbaImpl;

  /** \brief Proctected constructor - only the %Zorba engine can construct and throw
   *         exceptions.
   */
  QueryException(
        const ZorbaError::ErrorCode&,
        const String& aDescription, 
        const String& afilename,
        unsigned int afilelinenumber,
        unsigned int linebegin,
        unsigned int columnbegin);

protected:
  unsigned int          theLineBegin;
  unsigned int          theColumnBegin;
};


/** \brief DynamicException represents a dynamic error as defined in the %XQuery 1.0
 *         Specification (see http://www.w3.org/TR/xquery/#id-kinds-of-errors).
 */
class DynamicException : public QueryException
{
  friend std::ostream& operator<<(std::ostream&, const DynamicException&);
  friend class ZorbaImpl;

public:
  /** \brief Destructor
   */
  virtual ~DynamicException() throw();

protected:
  /** \brief Proctected constructor - only the %Zorba engine can construct and throw
   *         exceptions.
   */
  DynamicException(
        const ZorbaError::ErrorCode&,
        const String&,
        const String& afilename,
        unsigned int afilelinenumber,
        unsigned int linebegin,
        unsigned int columnbegin);
};


/** \brief StaticException represents a static error as defined in the %XQuery 1.0
 *         Specification (see http://www.w3.org/TR/xquery/#id-kinds-of-errors).
 */
class StaticException : public QueryException
{
  friend std::ostream& operator<<(std::ostream&, const StaticException&);
  friend class ZorbaImpl;


public:
  /** \brief Destructor
   */
  virtual ~StaticException() throw();

protected:
  /** \brief Proctected constructor - only the %Zorba engine can construct and throw
   *         exceptions.
   */
  StaticException(
        const ZorbaError::ErrorCode&,
        const String&,
        const String& afilename,
        unsigned int afilelinenumber,
        unsigned int linebegin,
        unsigned int columnbegin);
};


/** \brief TypeException represents a type error as defined in the %XQuery 1.0
 *         Specification (see http://www.w3.org/TR/xquery/#id-kinds-of-errors).
 */
class TypeException : public QueryException
{
  friend std::ostream& operator<<(std::ostream&, const TypeException&);
  friend class ZorbaImpl;


public:
  /** \brief Destructor
   */
  virtual ~TypeException() throw();

protected:
  /** \brief Proctected constructor - only the %Zorba engine can construct and throw
   *         exceptions.
   */
  TypeException(
        const ZorbaError::ErrorCode&,
        const String&,
        const String& afilename,
        unsigned int afilelinenumber,
        unsigned int linebegin,
        unsigned int columnbegin);

};


/** \brief SerializationException represents a serialization error as defined in the 
 *         XSLT 2.0 and XQuery 1.0 Serialization Specification 
 *         (see http://www.w3.org/TR/2005/CR-xslt-xquery-serialization-20051103/)
 */
class SerializationException : public QueryException
{
  friend std::ostream& operator<<(std::ostream&, const SerializationException&);
  friend class ZorbaImpl;

public:
  /** \brief Destructor
   */
  virtual ~SerializationException() throw();

protected:
  /** \brief Proctected constructor - only the %Zorba engine can construct and throw
   *         exceptions.
   */
  SerializationException(
        const ZorbaError::ErrorCode&,
        const String& aDescription,
        const String& afilename,
        unsigned int afilelinenumber,
        unsigned int linebegin,
        unsigned int columnbegin);

};

/** \brief SystemException represents an error that occurs in the %Zorba system.
 */
class SystemException : public ZorbaException
{
  friend std::ostream& operator<<(std::ostream&, const ZorbaException&);
  friend class ZorbaImpl;
  friend class Item;

public:
  /** \brief Destructor
   */
  virtual ~SystemException() throw();

protected:
  /** \brief Proctected constructor - only the %Zorba engine can construct and throw
   *         exceptions.
   */
  SystemException(const ZorbaError::ErrorCode&, const String& aDescription,
                  const String& afilename, unsigned int afilelinenumber);

};


/** \brief Print information about the exception to the given output stream */
std::ostream& operator<< (std::ostream& os, const ZorbaException& aException);
/** \brief Print information about the exception to the given output stream */
std::ostream& operator<< (std::ostream& os, const QueryException& aException);
/** \brief Print information about the exception to the given output stream */
std::ostream& operator<< (std::ostream& os, const StaticException& aException);
/** \brief Print information about the exception to the given output stream */
std::ostream& operator<< (std::ostream& os, const DynamicException& aException);
/** \brief Print information about the exception to the given output stream */
std::ostream& operator<< (std::ostream& os, const TypeException& aException);
/** \brief Print information about the exception to the given output stream */
std::ostream& operator<< (std::ostream& os, const SerializationException& aException);
/** \brief Print information about the exception to the given output stream */
std::ostream& operator<< (std::ostream& os, const SystemException& aException);

} /* namespace zorba */
#endif
