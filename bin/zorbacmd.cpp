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
#include "zorbacmdproperties.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#ifdef WIN32
#include <windows.h>
#endif

#include <zorba/zorba.h>
#include <simplestore/simplestore.h>

#ifdef ZORBA_DEBUGGER
#include "debugcmd_client.h"

#include <csignal>
#include <zorbautils/thread.h>
#endif

#include <boost/date_time/posix_time/posix_time.hpp>

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/convenience.hpp>

#include "util/time.h"

namespace fs = boost::filesystem;

namespace zorbatm = zorba::time;

#ifdef ZORBA_DEBUGGER
struct server_args
{
  std::istream * theQuery;
  const char * theFileName;
  unsigned short theRequestPort;
  unsigned short theEventPort;
};

THREAD_RETURN_TYPE server( void * args)
{
  server_args * lArgs = (server_args*)args;
  try
  {
    zorba::simplestore::SimpleStore* lStore = zorba::simplestore::SimpleStoreManager::getStore();
    zorba::ZorbaDebugger * lDebugger = zorba::Zorba::getInstance(lStore)->getDebugger();
    lDebugger->start( lStore, lArgs->theQuery, lArgs->theFileName, lArgs->theRequestPort, lArgs->theEventPort );
  } catch( std::exception &e ) {
    std::cout << e.what() << std::endl;
    exit(7);
  }
  return 0;
}
#endif

bool
populateStaticContext(
    zorba::StaticContext_t& aStaticContext,
    ZorbaCMDProperties* aProperties)
{
  if (aProperties->getBoundarySpace().size() != 0 )
  {
    aStaticContext->setBoundarySpacePolicy(
                       (aProperties->getBoundarySpace().compare("preserve") == 0 
                        ? preserve_space 
                        : strip_space));
  }

  if (aProperties->getConstructionMode().size() != 0)
  {
    aStaticContext->setConstructionMode( aProperties->getBoundarySpace().compare("preserve") == 0 
                                         ? preserve_cons 
                                         : strip_cons );
  }

  if (aProperties->getOrderingMode().size() != 0 )
  {
    aStaticContext->setOrderingMode( aProperties->getBoundarySpace().compare("ordered") == 0 
                                     ? ordered 
                                     : unordered );
  }

  if (aProperties->getBaseUri().size() != 0 )
  {
    aStaticContext->setBaseURI( aProperties->getBaseUri() );
  }

  if (aProperties->getDefaultCollation().size() != 0 )
  {
    try {
      aStaticContext->addCollation( aProperties->getDefaultCollation() );
    } catch (zorba::ZorbaException& e) {
      std::cerr << "The given collation '" << aProperties->getDefaultCollation() << "' is not a valid collation." << std::endl;
      return false;
    }
    aStaticContext->setDefaultCollation( aProperties->getDefaultCollation() );
  }
  return true;
}


bool
populateDynamicContext(zorba::DynamicContext* aDynamicContext, ZorbaCMDProperties* aProperties)
{
  if ( aProperties->getContextItem().size() != 0 ) {
    std::ifstream* lInStream = new std::ifstream(aProperties->getContextItem().c_str());
    aDynamicContext->setContextItemAsDocument(aProperties->getContextItem(), 
                                              std::auto_ptr<std::istream>(lInStream));
  }

  for (ZorbaCMDProperties::ExternalVars_t::const_iterator lIter = aProperties->externalVarsBegin();
      lIter != aProperties->externalVarsEnd(); ++lIter)
    if ((*lIter).inline_file) {
      std::ifstream* lInStream = new std::ifstream((*lIter).var_value.c_str());
      aDynamicContext->setVariableAsDocument((*lIter).var_name, (*lIter).var_value, 
                                             std::auto_ptr<std::istream>(lInStream));
    } else {
      zorba::Item lItem = zorba::Zorba::getInstance(NULL)
                            ->getItemFactory()->createString((*lIter).var_value);
      aDynamicContext->setVariable((*lIter).var_name, lItem);
    }
    
  return true;
}


bool
createSerializerOptions(Zorba_SerializerOptions& lSerOptions, ZorbaCMDProperties* aProperties)
{
  if ( aProperties->indent() )
    lSerOptions.indent = ZORBA_INDENT_YES;
  else
    lSerOptions.indent = ZORBA_INDENT_NO;

  if ( aProperties->omitXMLDeclaration() )
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  else
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_NO;

  if ( aProperties->byteOrderMark() )
    lSerOptions.byte_order_mark = ZORBA_BYTE_ORDER_MARK_YES;
  else
    lSerOptions.byte_order_mark = ZORBA_BYTE_ORDER_MARK_NO;

  if ( aProperties->serializeHTML() )
    lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
  else  
    lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;

  return true;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Main                                                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#ifndef _WIN32_WCE
int main(int argc, char* argv[])
#else
int _tmain(int argc, _TCHAR* argv[])
#endif
{
  zorba::Zorba* lZorbaInstance = zorba::Zorba::getInstance(zorba::simplestore::SimpleStoreManager::getStore());

  // time compilation and execution per each query
  boost::posix_time::ptime lStartCompileTime, lStopCompileTime;
  boost::posix_time::ptime lStartFirstExecutionTime, lStopFirstExecutionTime;
  boost::posix_time::ptime lStartExecutionTime, lStopExecutionTime;
  boost::posix_time::time_duration lDiffCompileTime;
  boost::posix_time::time_duration lDiffFirstExecutionTime;
  boost::posix_time::time_duration lDiffExecutionTime;

  zorbatm::timeinfo lStartCompileTimeInfo, lStopCompileTimeInfo;
  zorbatm::timeinfo lStartFirstExecutionTimeInfo, lStopFirstExecutionTimeInfo;
  zorbatm::timeinfo lStartExecutionTimeInfo, lStopExecutionTimeInfo;
  double lDiffCompileUserTime;
  double lDiffFirstExecutionUserTime;
  double lDiffExecutionUserTime;

  // parse the command line and/or the properties file
  ZorbaCMDProperties lProperties;

  try
  {
    if ( !lProperties.loadProperties(argc, argv) )
    {
      lProperties.printHelp();
      return 1;
    }
  } catch (boost::program_options::error& e)
  {
    std::cerr << e.what() << std::endl;
    lProperties.printHelp();
    return 1;
  }

  bool lTiming = lProperties.useTiming();

  // print the help 
  if (lProperties.printHelp())
  {
    lProperties.printHelp(std::cout); 
    return 0;
  }

  // print zorba version
  if (lProperties.printVersion())
  {
    std::cout << "Zorba XQuery Engine, Version: " 
              << zorba::Zorba::version() << std::endl;
    return 0;
  }
  
  // write to file or standard out
  std::auto_ptr<std::ostream> lFileStream (lProperties.getOutputFile().size() > 0 
                                           ? new std::ofstream(lProperties.getOutputFile().c_str()) 
                                           : 0 );
  std::ostream* lOutputStream = lFileStream.get();
  if ( lOutputStream == 0 ) 
  {
    lOutputStream = &std::cout;
  }
  else if ( !lOutputStream->good() ) 
  {
    std::cerr << "could not write to output file " << lProperties.getOutputFile() << std::endl;
    lProperties.printHelp(std::cerr);
    return 2;
  }

  if(lProperties.queriesOrFilesBegin() == lProperties.queriesOrFilesEnd())
  {
    std::cerr << "No query" << std::endl;
    lProperties.printHelp(std::cerr);
    return 3;
  }

  int queryNo = 1;
  for (ZorbaCMDProperties::QueriesOrFiles_t::const_iterator lIter = lProperties.queriesOrFilesBegin();
       lIter != lProperties.queriesOrFilesEnd();
       ++lIter)
  {
    // input file (either from a file or given as parameter)
    const char* fname = (*lIter).c_str();
    fs::path path;
    std::auto_ptr<std::istream> qfile;
    
    if (! lProperties.inlineQuery()) {
      path = fs::system_complete (fname);
      qfile.reset (new std::ifstream (path.native_file_string ().c_str ()));
    }
    else {
      qfile.reset (new std::istringstream(fname));
    }
    
    if ( !lProperties.inlineQuery() && !qfile->good() || qfile->eof() ) {
      std::cerr << "file " << fname << " not found or not readable" << std::endl;
      lProperties.printHelp(std::cerr);
      return 3;
    } else if (*fname == '\0') {
      std::cerr << "No query" << std::endl;
      lProperties.printHelp(std::cerr);
      return 3;
    }

    // print the query if requested
    if ( lProperties.printQuery() )
    {
      *lOutputStream << "\nQuery number " << queryNo << " :\n";
      std::copy (std::istreambuf_iterator<char> (*qfile),
                 std::istreambuf_iterator<char> (), std::ostreambuf_iterator<char> (*lOutputStream));
      *lOutputStream << std::endl;
      qfile->seekg(0); // go back to the beginning
    }

    zorba::XQuery_t lQuery;
    zorba::StaticContext_t lStaticContext = lZorbaInstance->createStaticContext();

    // populate the static context with information passed as parameter
    if (! populateStaticContext(lStaticContext, &lProperties) ) {
      lProperties.printHelp(std::cerr);
      return 3;
    }

#ifdef ZORBA_DEBUGGER
    server_args * lArgs = new server_args;
    lArgs->theQuery = qfile.get();
    lArgs->theFileName = fname;
    lArgs->theRequestPort = lProperties.requestPort();
    lArgs->theEventPort = lProperties.eventPort();
  
    // debug server
    if ( lProperties.debugServer() )
    {
      std::cout << "Zorba XQuery debugger server." << std::endl;
      std::cout << "Copyright 2006-2008 The FLWOR Foundation." << std::endl;
      std::cout << "License: Apache License 2.0: <http://www.apache.org/licenses/LICENSE-2.0>" << std::endl;
      server( (void *)lArgs );
      
    } else if ( lProperties.debugClient() ) {
    
      std::cout << "Zorba XQuery debugger client." << std::endl;
      std::cout << "Copyright 2006-2008 The FLWOR Foundation." << std::endl;
      std::cout << "License: Apache License 2.0: <http://www.apache.org/licenses/LICENSE-2.0>" << std::endl;
      //copy the input stream
      //std::stringstream out;
      //std::copy( std::istreambuf_iterator<char>(*qfile),
      //           std::istreambuf_iterator<char>(),
      //           std::ostreambuf_iterator<char>(out));
      //qfile->seekg(0);
      //std::istringstream lInputQuery( out.str() );
      //start the server thread
      
      Thread lServerThread( server, lArgs );

      //Try to connect 3 times on the server thread
      for ( unsigned int i = 0; i < 3; i++ )
      {
        try
        {
          //wait a second before trying to reconnect
#ifdef WIN32
          Sleep(1000);
#else
          sleep(1);
#endif
          ZorbaDebuggerClient * debuggerClient = ZorbaDebuggerClient::createClient( lProperties.requestPort(), lProperties.eventPort() );
          CommandLineEventHandler lEventHandler( qfile.get(), std::cin, std::cout, debuggerClient );
#ifdef SIGINT /* not all system have SIGINT */
          signal( SIGINT, suspend );
#endif
          debuggerClient->registerEventHandler( &lEventHandler );
          lServerThread.join();
        } catch( std::exception &e ) {
          if ( i < 2 ){ continue; }
          std::cerr << "Could not start the debugger client: " << std::endl;
          std::cerr << e.what() << std::endl;
          exit(7);
        }
        return 0;
      }
    }
#endif

    try 
    {
      Zorba_CompilerHints lHints;

      // default is O1
      if (lProperties.getOptLevel() == "O0")
        lHints.opt_level = ZORBA_OPT_LEVEL_O0;

      if (lTiming) 
      {
        lStartCompileTime = boost::posix_time::microsec_clock::local_time();
        zorbatm::get_timeinfo (lStartCompileTimeInfo);
      }

      lQuery = lZorbaInstance->createQuery ();
      if (! lProperties.inlineQuery())
        lQuery->setFileName (path.string ());
      lQuery->compile (*qfile, lStaticContext, lHints);
    
      if (lTiming) 
      {
        lStopCompileTime = boost::posix_time::microsec_clock::local_time();
        zorbatm::get_timeinfo (lStopCompileTimeInfo);
      }
    }
    catch (zorba::QueryException& qe) 
    {
      std::cerr << qe << std::endl;
      return 5;
    }
    catch (zorba::ZorbaException& ze) 
    {
      std::cerr << ze << std::endl;
      return 6;
    }

    // populate the dynamic context
    zorba::DynamicContext* lDynamicContext = lQuery->getDynamicContext();
    try 
    {
      if ( ! populateDynamicContext(lDynamicContext, &lProperties) )
      {
        lProperties.printHelp(std::cerr);
        return 4;
      }
    } catch (zorba::QueryException& qe) {
      std::cerr << qe << std::endl;
      return 5;
    } catch (zorba::ZorbaException& ze) {
      std::cerr << ze << std::endl;
      return 6;
    }

    int lNumExecutions = lProperties.getNoOfExecutions();

    try
    {
      Zorba_SerializerOptions lSerOptions;
      createSerializerOptions(lSerOptions, &lProperties);

      if (lTiming) 
      {
        lStartFirstExecutionTime = boost::posix_time::microsec_clock::local_time();
        zorbatm::get_timeinfo (lStartFirstExecutionTimeInfo);
      }

      // RUN THE QUERY ONCE
      if (lQuery->isUpdateQuery()) 
        lQuery->applyUpdates();
      else
        lQuery->serialize(*lOutputStream, lSerOptions);

      if (lTiming) 
      {
        lStopFirstExecutionTime = boost::posix_time::microsec_clock::local_time();
        zorbatm::get_timeinfo (lStopFirstExecutionTimeInfo);
      }

      if (lTiming) 
      {
        lStartExecutionTime = boost::posix_time::microsec_clock::local_time();
        zorbatm::get_timeinfo (lStartExecutionTimeInfo);
      }

      int numExecutions = lNumExecutions - 1;

      // RUN THE QUERY N TIMES
      while (--numExecutions >= 0 ) 
      {
        if (lQuery->isUpdateQuery())
          lQuery->applyUpdates();
        else
          lQuery->serialize(*lOutputStream, lSerOptions);
      }

      if (lTiming) 
      {
        lStopExecutionTime = boost::posix_time::microsec_clock::local_time();
        zorbatm::get_timeinfo (lStopExecutionTimeInfo);
      }
    }
    catch (zorba::QueryException& qe) 
    {
      std::cerr << qe << std::endl;
      return 5;
    }
    catch (zorba::ZorbaException& ze) 
    {
      std::cerr << ze << std::endl;
      return 6;
    }

    if (lTiming) 
    {
      std::cout.precision (3); std::cout.setf (std::ios::fixed);
      lNumExecutions = lProperties.getNoOfExecutions();

      std::cout << std::endl << "Number of executions = " << lNumExecutions
                << std::endl;

      lDiffCompileTime = lStopCompileTime - lStartCompileTime;

      lDiffCompileUserTime = zorbatm::get_time_elapsed (zorbatm::extract_user_time_detail (lStartCompileTimeInfo), zorbatm::extract_user_time_detail (lStopCompileTimeInfo));

      std::cout << "Compilation time: "
                << lDiffCompileTime.total_milliseconds()
                << " (user: " << lDiffCompileUserTime << ")"
                << " milliseconds" << std::endl;
      
      lDiffFirstExecutionTime = lStopFirstExecutionTime - lStartFirstExecutionTime;

      lDiffFirstExecutionUserTime = zorbatm::get_time_elapsed (zorbatm::extract_user_time_detail (lStartFirstExecutionTimeInfo), zorbatm::extract_user_time_detail (lStopFirstExecutionTimeInfo));

      std::cout << "First Execution time: "
                << lDiffFirstExecutionTime.total_milliseconds()
                << " (user: " << lDiffFirstExecutionUserTime << ")"
                << " milliseconds (i.e. parsing the document is included)" << std::endl;
    
      if (lNumExecutions > 1) 
      {
        lDiffExecutionTime = (lStopExecutionTime - lStartExecutionTime) /
                             (lNumExecutions - 1);

        lDiffExecutionUserTime =
          zorbatm::get_time_elapsed (zorbatm::extract_user_time_detail (lStartExecutionTimeInfo),
                                     zorbatm::extract_user_time_detail (lStopExecutionTimeInfo))
          / (lNumExecutions - 1);

        std::cout << "Average Execution time: "
                  << lDiffExecutionTime.total_milliseconds()
                  << " (user: " << lDiffExecutionUserTime << ")"
                  << " milliseconds" << std::endl;
      }
    }
    
    queryNo++;
  }
  
  return 0;
}
