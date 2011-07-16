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

#include <sstream>

#include <zorba/zorba.h>
#include <zorba/item.h>
#include <zorba/diagnostic_handler.h>
#include <zorba/xquery_exception.h>
#include <zorba/user_exception.h>


class Specification;

/*******************************************************************************

********************************************************************************/
class TestDiagnosticHandler : public zorba::DiagnosticHandler 
{
public:
  void error(const zorba::ZorbaException& ze)
  {
    registerError(ze);
  }

  bool errors() const
  {
    return !m_qnames.empty();
  }

  std::vector<std::string> const& getErrorQNames() const
  {
    return m_qnames;
  }

  const std::vector<zorba::String>& getErrorDescs() const
  {
    return m_desc;
  }
  
  void clear()
  {
    m_qnames.clear();
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

  void warning( const zorba::XQueryWarning &xw )
  {
    // TODO: should do something with the warning
  }

private:
  std::vector<std::string>    m_qnames;
  std::vector<zorba::String>  m_desc;
  std::string                 theErrorFile;

  void registerError(const zorba::ZorbaException& e)
  {
    std::ostringstream strdescr;
    strdescr << e.diagnostic().qname().ns() << ":" << e.diagnostic().qname().localname();
    m_qnames.push_back(strdescr.str());
    strdescr.clear();

    if(zorba::XQueryException const *xe = dynamic_cast<zorba::XQueryException const*>(&e))
    {
      strdescr << e.what()
               << "[line " << xe->source_line() << "]"
               << "[column " <<  xe->source_column() << "]"
               << "[file " <<  xe->source_uri() << "]";
      if(zorba::UserException const *ue = dynamic_cast<zorba::UserException const*>(&e))
      {
        zorba::UserException::error_object_type  const & err_objs = ue->error_object();
        if(!err_objs.empty())
        {
          strdescr << " and ..." << std::endl << "User parameters:";
          for(size_t i=0;i<err_objs.size();i++)
          {
            strdescr << std::endl;
            strdescr << err_objs[i].getStringValue();
          }
        }
      }
    }
    else
    {
      strdescr << e.what();
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
  std::vector<zorba::URIMapper*>  theURIMappers;
  std::vector<zorba::URLResolver*>  theURLResolvers;
};


void createDynamicContext(
    DriverContext& driverCtx,
    const zorba::StaticContext_t& aBaseCtx,
    zorba::XQuery_t& query,
    bool enableDtd,
    zorba::DiagnosticHandler& errHandler);

void setOptions(
    DriverContext& driverCtx,
    const zorba::StaticContext_t& sctx);

void addURIMapper(
    DriverContext& driverCtx,
    const zorba::StaticContext_t& sctx,
    zorba::URIMapper* mapper);

void addURLResolver(
    DriverContext& driverCtx,
    const zorba::StaticContext_t& sctx,
    zorba::URLResolver* resolver);

void setFullTextURIMappers(
    DriverContext& driverCtx,
    const zorba::StaticContext_t& sctx);

void slurp_file(
    const char* fname,
    std::string& result,
    const std::string& rbkt_src_dir,
    const std::string& rbkt_bin_dir);

bool isErrorExpected(
    const TestDiagnosticHandler& errHandler,
    const Specification* aSpec);

bool isStaticError(
    std::string strValue);

void printErrors(
    const TestDiagnosticHandler& errHandler,
    const char* msg,
    bool printInFile,
    std::ostream& output = std::cout);

void setModulePaths(
    std::string paths,
    zorba::StaticContext_t& sctx);

Zorba_CompilerHints getCompilerHints();

zorba::Item createItem(
    DriverContext& driverCtx,
    std::string strValue);


#endif /* TEST_RBKT_TESTDRIVER_COMMON */
