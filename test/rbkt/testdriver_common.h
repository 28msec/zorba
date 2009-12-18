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
#ifndef TEST_RBKT_TESTDRIVER_COMMON
#define TEST_RBKT_TESTDRIVER_COMMON

#include <zorba/zorba.h>
#include <zorba/error_handler.h>
#include <zorba/exception.h>


class Specification;


/*******************************************************************************

********************************************************************************/
class TestErrorHandler : public zorba::ErrorHandler 
{
public:
  void staticError(const zorba::StaticException& aStaticError)
  {
    registerError(aStaticError);
  }

  void dynamicError(const zorba::DynamicException& aDynamicError)
  {
    registerError(aDynamicError);
  }

  void typeError(const zorba::TypeException& aTypeError)
  {
    registerError(aTypeError);
  }

  void serializationError(const zorba::SerializationException& aSerializationError)
  {
    registerError(aSerializationError);
  }

  void systemError(const zorba::SystemException& aSystemError)
  {
    registerError(aSystemError);
  }

  void userError(const zorba::UserException& aUserError)
  {
    registerError(aUserError);
  }

  bool errors() const
  {
    return !m_errors.empty();
  }

  const std::vector<std::string>& getErrorList() const
  {
    return m_errors;
  }

  const std::vector<zorba::String>& getErrorDescs() const
  {
    return m_desc;
  }
  
  void clear()
  {
    m_errors.clear();
    m_desc.clear();
  }

  const std::string& getErrorFile() const
  {
    return theErrorFile;
  }

  void setErrorFile(const std::string& file)
  {
    theErrorFile = file;
  }

private:
  std::vector<std::string>    m_errors;
  std::vector<zorba::String>  m_desc;
  std::string                 theErrorFile;

  void registerError(const zorba::ZorbaException& e)
  {
    m_errors.push_back(zorba::ZorbaException::getErrorCodeAsString(e.getErrorCode()).c_str());
    std::ostringstream strdescr;

    if(dynamic_cast<const zorba::QueryException*>(&e))
    {
      const zorba::QueryException* qe = dynamic_cast<const zorba::QueryException*>(&e);
      strdescr <<  e.getDescription().c_str()
               << "[line " << qe->getLineBegin() << "]"
               << "[column " <<  qe->getColumnBegin() << "]"
               << "[file " <<  qe->getQueryURI().c_str() << "]";
    }
    else
    {
      strdescr << e.getDescription().c_str();
    }

    m_desc.push_back(strdescr.str());
  }
};


/*******************************************************************************

********************************************************************************/
class DriverContext
{
public:
  zorba::Zorba  * theEngine;
  Specification * theSpec;
  std::string     theRbktSourceDir;
  std::string     theRbktBinaryDir;
};


void createDynamicContext(
    DriverContext& driverCtx,
    const zorba::StaticContext_t& sctx,
    zorba::XQuery_t& query);


void slurp_file(
    const char* fname,
    std::string& result,
    const std::string& rbkt_src_dir,
    const std::string& rbkt_bin_dir);

bool isErrorExpected(
    const TestErrorHandler& errHandler,
    const Specification* aSpec);

void printErrors(
    const TestErrorHandler& errHandler,
    const char* msg,
    bool printInFile);

Zorba_CompilerHints getCompilerHints();

zorba::Item createItem(std::string strValue);


#endif
