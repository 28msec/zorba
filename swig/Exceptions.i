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
#include <zorba/xquery_exception.h>
#include <zorba/user_exception.h>

class ZorbaException 
{
 protected:
  const zorba::ZorbaException* theException; 
  ZorbaException() {}
  ZorbaException(const zorba::ZorbaException *en)
  { theException = en; } 

  //friend class DiagnosticHandler;
 public:
  virtual std::string getDescription() const 
  { return std::string(theException->what()); }

  virtual zorba::Error const& getErrorCode () const
  { return theException->diagnostic(); }

  virtual unsigned int getFileLineNumber () const
  { return theException->raise_line(); }

  virtual std::string getFileName () const
  { return std::string(theException->raise_file()); }

  static std::string getErrorCodeAsString(zorba::Error const &error)
  { 
    std::ostringstream oss;
    oss << error.qname();
    return oss.str();
  }
};

class XQueryException : public ZorbaException 
{
 protected:
  XQueryException() {}
  XQueryException(const zorba::XQueryException *qe) : ZorbaException(qe) {}

  //friend class DiagnosticHandler;
 private:
  const zorba::XQueryException* getQEx() const
  { return dynamic_cast<const zorba::XQueryException*>(theException); }
 public:
  virtual unsigned int getColumnBegin () const
  { return getQEx()->source_column(); }
  virtual unsigned int getLineBegin () const
  { return getQEx()->source_line(); }
  virtual std::string  getQueryURI () const
  { return std::string(getQEx()->source_uri()); }
};

class UserException : public XQueryException 
{
  //friend class DiagnosticHandler;

 protected:
  UserException (const zorba::UserException *se) : 
      XQueryException(se) {}
  UserException() {}
};





%}  //////////////// end Implementations

    // Interface

#ifdef SWIGJAVA
%include "enums.swg"
%javaconst(1);
#endif
%rename(XQueryErrorEnum) zorba::Error;
#include <zorba/error.h>


class ZorbaException 
{
 private:
  ZorbaException();
 
 public:
  virtual std::string  getDescription()    const;
  virtual zorba::Error const& getErrorCode()      const;
  virtual unsigned int getFileLineNumber() const;
  virtual std::string  getFileName()       const;
  static  std::string  getErrorCodeAsString(const zorba::Error &aErrorCode);
};

class XQueryException : public ZorbaException 
{
 private:
  XQueryException();
 public:
  virtual unsigned int 	getColumnBegin () const;
  virtual unsigned int 	getLineBegin () const;
  virtual std::string 	getQueryURI () const;
};

/* vim:set et sw=2 ts=2: */
