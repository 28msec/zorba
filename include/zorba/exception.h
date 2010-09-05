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

#include <vector>

#include <zorba/config.h>
#include <zorba/error.h>
#include <zorba/zorbastring.h>
#include <zorba/iterator.h>
#include <zorba/query_location.h>

namespace zorba {

class ZORBA_DLL_PUBLIC StackEntry {
  private:
    zorba::Item theFunctionName;
    unsigned int theFunctionArity;
    QueryLocation_t theLocation;

  public:
    StackEntry(zorba::Item aName, unsigned int arity, QueryLocation_t aLocation):
      theFunctionName(aName), theFunctionArity(arity), theLocation(aLocation){}

   const zorba::Item& getFunctionName() const { return theFunctionName; }
   unsigned int getFunctionArity() const { return theFunctionArity; }
   const QueryLocation_t getLocation() const { return theLocation; }
};

/** \brief Base class of all exceptions thrown by %Zorba.
 */
class ZORBA_DLL_PUBLIC ZorbaException
{
 public:
  //typedef std::pair<zorba::Item, QueryLocation_t> StackEntry_t;
  typedef StackEntry StackEntry_t;
  typedef std::vector<StackEntry_t> StackTrace_t;
  /** \brief Destructor
   */
  virtual ~ZorbaException() throw();

  /** \brief Get the ErrorCode of the error that is reported by this exception.
   */
  virtual XQUERY_ERROR
  getErrorCode() const;


  /** \brief Get the description of the error that is reported by this exception.
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


  /** \brief Static function to convert an XQUERY_ERROR to a String
   *
   * @param  aErrorCode the XQUERY_ERROR to convert to a String.
   * @return String the String representation of the XQUERY_ERROR.
   */
  static std::string
  getErrorCodeAsString(const XQUERY_ERROR& aErrorCode);

  /** \brief Get the complete stack trace.
    *
    * @return a vector of query locations - the location of all
    *         functions called.
    */
  virtual StackTrace_t
  getStackTrace() const;

protected:
  friend class ZorbaImpl;
  friend class ExternalFunctionData;

  /** \brief Proctected constructor - only the %Zorba engine and external functions 
   *         can construct and throw exceptions.
   */
  ZorbaException(const XQUERY_ERROR&, const String& aDescription,
                 const String& aFileName, unsigned int aFileLineNumber,
                 StackTrace_t queryLocs);

  XQUERY_ERROR   theErrorCode;
  String         theDescription;
  String         theFileName;
  unsigned int   theFileLineNumber;
  StackTrace_t  theStackTrace;
};


/** \brief QueryException is the base class for all errors that occur during query processing
 *         and have a direct connection to the query, i.e. information about the location
 *         where the error occured in the query is available.
 */
class ZORBA_DLL_PUBLIC QueryException : public ZorbaException 
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

  /** \brief Get the uri of the query where the error occured.
   *
   * @return String the uri of the query
   */
  virtual String
  getQueryURI() const;

protected:
  friend ZORBA_DLL_PUBLIC std::ostream& operator<<(std::ostream&, const QueryException&);
  friend class ZorbaImpl;

  /** \brief Proctected constructor - only the %Zorba engine
   *         can construct and throw exceptions.
   */
  QueryException(
        const XQUERY_ERROR&,
        const String& aDescription, 
        const String& afilename,
        unsigned int afilelinenumber,
        const String& queryuri,
        unsigned int linebegin,
        unsigned int columnbegin,
        ZorbaException::StackTrace_t aStackTrace);

protected:
  unsigned int  theLineBegin;
  unsigned int  theColumnBegin;
  String        theQueryURI;
};


/** \brief DynamicException represents a dynamic error as defined in the %XQuery 1.0
 *         Specification (see http://www.w3.org/TR/xquery/#id-kinds-of-errors).
 */
class ZORBA_DLL_PUBLIC DynamicException : public QueryException
{
  friend ZORBA_DLL_PUBLIC std::ostream& operator<<(std::ostream&, const DynamicException&);
  friend class ZorbaImpl;

public:
  /** \brief Destructor
   */
  virtual ~DynamicException() throw();

protected:
  /** \brief Proctected constructor - only the %Zorba engine
   *         can construct and throw exceptions.
   */
  DynamicException(
        const XQUERY_ERROR&,
        const String&,
        const String& afilename,
        unsigned int afilelinenumber,
        const String& queryuri,
        unsigned int linebegin,
        unsigned int columnbegin,
        ZorbaException::StackTrace_t aStackTrace);
};


/** \brief StaticException represents a static error as defined in the %XQuery 1.0
 *         Specification (see http://www.w3.org/TR/xquery/#id-kinds-of-errors).
 */
class ZORBA_DLL_PUBLIC StaticException : public QueryException
{
  friend ZORBA_DLL_PUBLIC std::ostream& operator<<(std::ostream&, const StaticException&);
  friend class ZorbaImpl;

public:
  /** \brief Destructor
   */
  virtual ~StaticException() throw();

protected:
  /** \brief Proctected constructor - only the %Zorba engine
   *         can construct and throw exceptions.
   */
  StaticException(
        const XQUERY_ERROR&,
        const String&,
        const String& afilename,
        unsigned int afilelinenumber,
        const String& queryuri,
        unsigned int linebegin,
        unsigned int columnbegin,
        ZorbaException::StackTrace_t aStackTrace);
};


/** \brief TypeException represents a type error as defined in the %XQuery 1.0
 *         Specification (see http://www.w3.org/TR/xquery/#id-kinds-of-errors).
 */
class ZORBA_DLL_PUBLIC TypeException : public QueryException
{
  friend ZORBA_DLL_PUBLIC std::ostream& operator<<(std::ostream&, const TypeException&);
  friend class ZorbaImpl;

public:
  /** \brief Destructor
   */
  virtual ~TypeException() throw();

protected:
  /** \brief Proctected constructor - only the %Zorba engine
   *         can construct and throw exceptions.
   */
  TypeException(
        const XQUERY_ERROR&,
        const String&,
        const String& afilename,
        unsigned int afilelinenumber,
        const String& queryuri,
        unsigned int linebegin,
        unsigned int columnbegin,
        ZorbaException::StackTrace_t aStackTrace);

};


/** \brief SerializationException represents a serialization error as defined in the 
 *         XSLT 2.0 and XQuery 1.0 Serialization Specification 
 *         (see http://www.w3.org/TR/2005/CR-xslt-xquery-serialization-20051103/)
 */
class ZORBA_DLL_PUBLIC SerializationException : public ZorbaException
{
  friend ZORBA_DLL_PUBLIC std::ostream& operator<<(std::ostream&, const ZorbaException&);
  friend class ZorbaImpl;

public:
  /** \brief Destructor
   */
  virtual ~SerializationException() throw();

protected:
  /** \brief Proctected constructor - only the %Zorba engine
   *         can construct and throw exceptions.
   */
  SerializationException(
    const XQUERY_ERROR&,
    const String& aDescription,
    const String& afilename,
    unsigned int afilelinenumber,
    ZorbaException::StackTrace_t aStackTrace);

};

/** \brief UserException is raised if an error is raised by using the fn:error
 *         function in a query.
 */
class ZORBA_DLL_PUBLIC UserException : public QueryException
{
  friend ZORBA_DLL_PUBLIC std::ostream& operator<<(std::ostream&, const UserException&);
  friend class ZorbaImpl;

public:
  /** \brief Destructor
   */
  virtual ~UserException() throw();

  /** \brief Returns the sequence that may be passed as third parameter
   *         to the fn:error function.
   */
  virtual Iterator_t
  getErrorObject() const;

protected:
  /** \brief Proctected constructor - only the %Zorba engine
   *         can construct and throw exceptions.
   */
  UserException(
        const XQUERY_ERROR&,
        const String& aDescription,
        const String& afilename,
        unsigned int afilelinenumber,
        const String& queryuri,
        unsigned int linebegin,
        unsigned int columnbegin,
        QueryException::StackTrace_t queryLocs);

  /** \brief Proctected constructor - only the %Zorba engine
   *         can construct and throw exceptions.
   */
  UserException(
        const XQUERY_ERROR&,
        const String& aDescription,
        const String& afilename,
        unsigned int afilelinenumber,
        const String& queryuri,
        unsigned int linebegin,
        unsigned int columnbegin,
        QueryException::StackTrace_t queryLocs,
        const Iterator_t& aErrorObject);

  Iterator_t            theErrorObject;
};


/** \brief SystemException represents an error that occurs in the %Zorba system.
 */
class ZORBA_DLL_PUBLIC SystemException : public ZorbaException
{
  friend ZORBA_DLL_PUBLIC std::ostream& operator<<(std::ostream&, const ZorbaException&);
  friend class ZorbaImpl;
  friend class Item;

public:
  /** \brief Destructor
   */
  virtual ~SystemException() throw();

protected:
  /** \brief Proctected constructor - only the %Zorba engine
   *         can construct and throw exceptions.
   */
  SystemException(const XQUERY_ERROR&, const String& aDescription,
                  const String& afilename, unsigned int afilelinenumber,
                  ZorbaException::StackTrace_t aStackTrace);

  SystemException(const XQUERY_ERROR&, const String& aDescription,
                  const String& afilename, unsigned int afilelinenumber);
};


/** \brief Print information about the exception to the given output stream */
ZORBA_DLL_PUBLIC
std::ostream& operator<< (std::ostream& os, const ZorbaException& aException);
/** \brief Print information about the exception to the given output stream */
ZORBA_DLL_PUBLIC
std::ostream& operator<< (std::ostream& os, const QueryException& aException);
/** \brief Print information about the exception to the given output stream */
ZORBA_DLL_PUBLIC
std::ostream& operator<< (std::ostream& os, const StaticException& aException);
/** \brief Print information about the exception to the given output stream */
ZORBA_DLL_PUBLIC
std::ostream& operator<< (std::ostream& os, const DynamicException& aException);
/** \brief Print information about the exception to the given output stream */
ZORBA_DLL_PUBLIC
std::ostream& operator<< (std::ostream& os, const TypeException& aException);
/** \brief Print information about the exception to the given output stream */
ZORBA_DLL_PUBLIC
std::ostream& operator<< (std::ostream& os, const SerializationException& aException);
/** \brief Print information about the exception to the given output stream */
ZORBA_DLL_PUBLIC
std::ostream& operator<< (std::ostream& os, const UserException& aException);
/** \brief Print information about the exception to the given output stream */
ZORBA_DLL_PUBLIC
std::ostream& operator<< (std::ostream& os, const SystemException& aException);

} /* namespace zorba */
#endif
