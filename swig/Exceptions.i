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


%{  /////////////// Implementations



#include <zorba/error.h>

class ZorbaException 
{
 protected:
  const zorba::ZorbaException* theException; 
  ZorbaException() {}
  ZorbaException(const zorba::ZorbaException *en)
  { theException = en; } 

 public:
  virtual std::string getDescription() const 
  { return std::string(theException->getDescription().c_str()); }

  virtual int getErrorCode () const
  { return theException->getErrorCode(); }

  virtual unsigned int getFileLineNumber () const
  { return theException->getFileLineNumber(); }

  virtual std::string getFileName () const
  { return std::string(theException->getFileName().c_str()); }
};

class QueryException : public ZorbaException 
{
 protected:
  QueryException() {}
  QueryException(const zorba::QueryException *qe) : ZorbaException(qe) {}
};

class SystemException : public ZorbaException 
{
  friend class ErrorHandler;

 protected:
  SystemException (const zorba::SystemException *se) : ZorbaException(se) {}
  SystemException() {}

 public:
};

class DynamicException : public QueryException 
{
  friend class ErrorHandler;

 protected:
  const zorba::DynamicException* theException;
  DynamicException (const zorba::DynamicException *de) : QueryException(de) {}
  DynamicException() {}

 public:
};

class SerializationException : public QueryException 
{
  friend class ErrorHandler;

 protected:
  const zorba::SerializationException* theException;
  SerializationException (const zorba::SerializationException *se) : 
      QueryException(se) {}
  SerializationException() {}

 public:
};

class StaticException : public QueryException 
{
  friend class ErrorHandler;

 protected:
  const zorba::StaticException* theException;
  StaticException (const zorba::StaticException *se) : 
      QueryException(se) {}
  StaticException() {}

 public:
};

class TypeException : public QueryException 
{
  friend class ErrorHandler;

 protected:
  const zorba::TypeException* theException;
  TypeException (const zorba::TypeException *se) : 
      QueryException(se) {}
  TypeException() {}

 public:
};

class UserException : public QueryException 
{
  friend class ErrorHandler;

 protected:
  const zorba::UserException* theException;
  UserException (const zorba::UserException *se) : 
      QueryException(se) {}
  UserException() {}

 public:
};





%}  //////////////// end Implementations

    // Interface

#ifdef SWIGJAVA
%include "enums.swg"
%javaconst(1);
#endif
%rename(XQueryError) XQUERY_ERROR;
#include <zorba/error.h>


class ZorbaException 
{
 private:
  ZorbaException();
 
 public:
  virtual std::string  getDescription()    const;
  virtual int          getErrorCode()      const;
  virtual unsigned int getFileLineNumber() const;
  virtual std::string  getFileName()       const;
};

class QueryException : public ZorbaException 
{
 private:
  QueryException();
};

class SystemException : public ZorbaException 
{
 private:
  SystemException();
};

class DynamicException : public ZorbaException 
{
 private:
  DynamicException();
};

class SerializationException : public QueryException 
{
 private:
  SerializationException();
};

class StaticException : public QueryException 
{
 private:
  StaticException();
};

class TypeException : public QueryException 
{
 private:
  TypeException();
};

class UserException : public QueryException 
{
 private:
  UserException();
};

