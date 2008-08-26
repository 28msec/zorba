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
#define sleep(s) Sleep(s*1000)
#endif

#include <simplestore/simplestore.h>
#include <zorba/zorba.h>

#ifdef ZORBA_DEBUGGER
#include "debugcmd_client.h"
#ifdef ZORBA_HAVE_PTHREAD_H
#include <pthread.h>
#define ZORBA_THREAD_RETURN void *
#else
#define ZORBA_THREAD_RETURN DWORD WINAPI
#endif
#include <csignal>
#endif

#include <zorbatypes/zorbatypes_decl.h>
#include <zorbatypes/datetime.h>
#include <zorbatypes/duration.h>
#include <zorbatypes/floatimpl.h>

#include <zorba/util/path.h>

#include "util/time.h"

namespace zorbatm = zorba::time;

#ifdef ZORBA_DEBUGGER
struct server_args
{
  std::auto_ptr<std::istream> *theQuery;
  std::string *theFileName;
  unsigned short theRequestPort;
  unsigned short theEventPort;
};

ZORBA_THREAD_RETURN server( void * args)
{
  server_args * lArgs = (server_args*)args;
  try {
    zorba::simplestore::SimpleStore* lStore = zorba::simplestore::SimpleStoreManager::getStore();
    zorba::Zorba *lZorba = zorba::Zorba::getInstance(lStore);
    XQuery_t lQuery = lZorba->createQuery();
    lQuery->setFileName(*lArgs->theFileName);
    lQuery->setDebugMode(true);
    Zorba_CompilerHints lHints;
    lHints.opt_level = ZORBA_OPT_LEVEL_O0;
    lQuery->compile(*lArgs->theQuery->get(), lHints);
    lQuery->debug(lArgs->theRequestPort, lArgs->theEventPort);
    lQuery->close();
  } catch( std::exception &e ) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}
#endif

bool
populateStaticContext(
    zorba::StaticContext_t& aStaticContext,
    ZorbaCMDProperties* aProperties)
{
  if (aProperties->boundarySpace().size() != 0 )
    aStaticContext->setBoundarySpacePolicy(
                       (aProperties->boundarySpace().compare("preserve") == 0 
                        ? preserve_space 
                        : strip_space));

  if (aProperties->constructionMode().size() != 0)
    aStaticContext->setConstructionMode( aProperties->boundarySpace().compare("preserve") == 0 
                                         ? preserve_cons 
                                         : strip_cons );

  if (aProperties->orderingMode().size() != 0 )
  {
    aStaticContext->setOrderingMode( aProperties->boundarySpace().compare("ordered") == 0 
                                     ? ordered 
                                     : unordered );
  }

  if (aProperties->baseUri().size() != 0 )
    aStaticContext->setBaseURI( aProperties->baseUri() );

  if (aProperties->defaultCollation().size() != 0 )
  {
    try {
      aStaticContext->addCollation( aProperties->defaultCollation() );
    } catch (zorba::ZorbaException& e) {
      std::cout << "Error: the given collation '" << aProperties->defaultCollation() << "' is not a valid collation." << std::endl;
      return false;
    }
    aStaticContext->setDefaultCollation( aProperties->defaultCollation() );
  }
  return true;
}


bool
populateDynamicContext(zorba::DynamicContext* aDynamicContext, ZorbaCMDProperties* aProperties)
{
  if ( aProperties->contextItem().size() != 0 ) {
    std::ifstream* lInStream = new std::ifstream(aProperties->contextItem().c_str());
    aDynamicContext->setContextItemAsDocument(aProperties->contextItem(), 
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

  if ( aProperties->omitXmlDeclaration() )
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  else
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_NO;

  if ( aProperties->byteOrderMark() )
    lSerOptions.byte_order_mark = ZORBA_BYTE_ORDER_MARK_YES;
  else
    lSerOptions.byte_order_mark = ZORBA_BYTE_ORDER_MARK_NO;

  if ( aProperties->serializeHtml() )
    lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
  else if ( aProperties->serializeText() )
    lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;
  else  
    lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;

  return true;
}

std::string parseFileURI (bool asPath, const std::string &str) {
  if (asPath)
    return str;
  static const char *pfx = "file://";
  static unsigned plen = strlen (pfx);
  if (str.compare (0, plen, pfx) == 0)
    return str.substr (plen);
  else
    return "";
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
  zorba::DateTime lStartCompileTime, lStopCompileTime;
  zorba::DateTime lStartFirstExecutionTime, lStopFirstExecutionTime;
  zorba::DateTime lStartExecutionTime, lStopExecutionTime;
  std::auto_ptr<zorba::Duration> lDiffCompileTime;
  std::auto_ptr<zorba::Duration> lDiffFirstExecutionTime;
  std::auto_ptr<zorba::Duration> lDiffExecutionTime;

  zorbatm::timeinfo lStartCompileTimeInfo, lStopCompileTimeInfo;
  zorbatm::timeinfo lStartFirstExecutionTimeInfo, lStopFirstExecutionTimeInfo;
  zorbatm::timeinfo lStartExecutionTimeInfo, lStopExecutionTimeInfo;
  double lDiffCompileUserTime;
  double lDiffFirstExecutionUserTime;
  double lDiffExecutionUserTime;

  // parse the command line and/or the properties file
  ZorbaCMDProperties lProperties;
  if (! lProperties.loadProperties(argc, argv)) {
      return 1;
  }

  bool lTiming = lProperties.timing();

  // write to file or standard out
  std::auto_ptr<std::ostream> lFileStream (lProperties.outputFile().size() > 0 
                                           ? new std::ofstream(lProperties.outputFile().c_str()) 
                                           : 0 );
  std::ostream* lOutputStream = lFileStream.get();
  if ( lOutputStream == 0 ) 
  {
    lOutputStream = &std::cout;
  }
  else if ( !lOutputStream->good() ) 
  {
    std::cout << "Error: could not write to output file " << lProperties.outputFile() << std::endl;
    lProperties.printHelp(std::cout);
    return 2;
  }

  if(lProperties.queriesOrFilesBegin() == lProperties.queriesOrFilesEnd())
  {
    std::cout << "Error: no queries submitted" << std::endl;
    lProperties.printHelp(std::cout);
    return 3;
  }

  int queryNo = 1;
  for (ZorbaCMDProperties::QueriesOrFiles_t::const_iterator lIter = lProperties.queriesOrFilesBegin();
       lIter != lProperties.queriesOrFilesEnd();
       ++lIter)
  {
    // input file (either from a file or given as parameter)
    std::string fURI = *lIter;
    std::string fname = parseFileURI (lProperties.asFiles (), fURI);
    zorba::filesystem_path path (fname);
    bool asFile = ! fname.empty ();
    std::auto_ptr<std::istream> qfile;
    
    if (asFile) {
      path.resolve_relative ();
      qfile.reset (new std::ifstream (path.c_str ()));
    }
    else {
      qfile.reset (new std::istringstream(fURI));
    }
    
    if ( asFile && (!qfile->good() || qfile->eof()) ) {
      std::cout << "Error: file " << fname << " not found or not readable" << std::endl;
      lProperties.printHelp(std::cout);
      return 3;
    } else if (fURI.empty ()) {
      std::cout << "Error: empty query" << std::endl;
      lProperties.printHelp(std::cout);
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
      lProperties.printHelp(std::cout);
      return 3;
    }

#ifdef ZORBA_DEBUGGER
    
    std::auto_ptr<server_args> lArgs( new server_args() ); 
    std::auto_ptr<std::istream> lXQ( new std::ifstream(path.c_str()) );
    std::auto_ptr<std::string> lFileName(new std::string(path.get_path ()));
    lArgs->theQuery = &lXQ;
    lArgs->theFileName = lFileName.get();
    lArgs->theRequestPort = lProperties.getRequestPort();
    lArgs->theEventPort = lProperties.getEventPort();
  
    // debug server
    if ( lProperties.debugServer() )
    {
      std::cout << "Zorba XQuery debugger server." << std::endl;
      std::cout << "Copyright 2006-2008 The FLWOR Foundation." << std::endl;
      std::cout << "License: Apache License 2.0: <http://www.apache.org/licenses/LICENSE-2.0>" << std::endl;
      server( (void *)lArgs.get() );
      return 0;  
    } else if ( lProperties.debugClient() ) {
    
      std::cout << "Zorba XQuery debugger client." << std::endl;
      std::cout << "Copyright 2006-2008 The FLWOR Foundation." << std::endl;
      std::cout << "License: Apache License 2.0: <http://www.apache.org/licenses/LICENSE-2.0>" << std::endl;
      
      //start the server thread
#ifdef ZORBA_HAVE_PTHREAD_H
      pthread_t lServerThread;
      if ( pthread_create( &lServerThread, 0, server, lArgs.get() ) != 0 )
#else
      HANDLE lServerThread;
      if ( ( lServerThread = CreateThread( 0, 0, server, lArgs.get(), 0, 0 ) ) == 0 )
#endif
      {
        std::cerr << "Couldn't start the server thread" << std::endl;
        return 7;
      }
      //Try to connect 3 times on the server thread
      for ( unsigned int i = 0; i < 3; i++ )
      {
        try
        {
          //wait 1 second before trying to reconnect
          sleep(1);
          ZorbaDebuggerClient * debuggerClient = ZorbaDebuggerClient::createClient( lProperties.getRequestPort(), lProperties.getEventPort() );
          CommandLineEventHandler lEventHandler( *lIter, *lArgs->theQuery, std::cin, std::cout, debuggerClient );
#ifdef SIGINT /* not all system have SIGINT */
          signal( SIGINT, suspend );
#endif
          debuggerClient->registerEventHandler( &lEventHandler );
#ifdef ZORBA_HAVE_PTHREAD_H
          pthread_join( lServerThread, 0 );
          pthread_cancel( lServerThread );
#else
          WaitForSingleObject( theThread, INFINITE );
          CloseHandler( lServerThread );
#endif
      	  delete debuggerClient;
          return 0;
        } catch( std::exception &e ) {
          if ( i < 2 ){ continue; }
          std::cout << "Could not start the debugger client: " << std::endl;
          std::cout << e.what() << std::endl;
          return 7;
        }
      }
    }
#endif

    try 
    {
      Zorba_CompilerHints lHints;

      // default is O1
      if (lProperties.optimizationLevel() == "O0")
        lHints.opt_level = ZORBA_OPT_LEVEL_O0;

      if (lTiming) 
      {
        zorba::DateTime::getLocalTime(lStartCompileTime);
        zorbatm::get_timeinfo (lStartCompileTimeInfo);
      }

      lQuery = lZorbaInstance->createQuery ();
      if (asFile)
        lQuery->setFileName (path.get_path ());
      lQuery->compile (*qfile, lStaticContext, lHints);
    
      if (lTiming) 
      {
        zorba::DateTime::getLocalTime(lStopCompileTime);
        zorbatm::get_timeinfo (lStopCompileTimeInfo);
      }
    }
    catch (zorba::QueryException& qe) 
    {
      std::cout << qe << std::endl;
      return 5;
    }
    catch (zorba::ZorbaException& ze) 
    {
      std::cout << ze << std::endl;
      return 6;
    }

    // populate the dynamic context
    zorba::DynamicContext* lDynamicContext = lQuery->getDynamicContext();
    try 
    {
      if ( ! populateDynamicContext(lDynamicContext, &lProperties) )
      {
        lProperties.printHelp(std::cout);
        return 4;
      }
    } catch (zorba::QueryException& qe) {
      std::cout << qe << std::endl;
      return 5;
    } catch (zorba::ZorbaException& ze) {
      std::cout << ze << std::endl;
      return 6;
    }

    int lNumExecutions = lProperties.multiple();

    try
    {
      Zorba_SerializerOptions lSerOptions;
      createSerializerOptions(lSerOptions, &lProperties);

      if (lTiming) 
      {
        zorba::DateTime::getLocalTime(lStartFirstExecutionTime);
        zorbatm::get_timeinfo (lStartFirstExecutionTimeInfo);
      }

      // RUN THE QUERY ONCE
      if (lQuery->isUpdateQuery()) 
        lQuery->applyUpdates();
      else
        lQuery->serialize(*lOutputStream, lSerOptions);

      if (lTiming) 
      {
        zorba::DateTime::getLocalTime(lStopFirstExecutionTime);
        zorbatm::get_timeinfo (lStopFirstExecutionTimeInfo);
      }

      if (lTiming) 
      {
        zorba::DateTime::getLocalTime(lStartExecutionTime);
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
        zorba::DateTime::getLocalTime(lStopExecutionTime);
        zorbatm::get_timeinfo (lStopExecutionTimeInfo);
      }
    }
    catch (zorba::QueryException& qe) 
    {
      std::cout << qe << std::endl;
      return 5;
    }
    catch (zorba::ZorbaException& ze) 
    {
      std::cout << ze << std::endl;
      return 6;
    }

    if (lTiming) 
    {
      std::cout.precision (3); std::cout.setf (std::ios::fixed);
      lNumExecutions = lProperties.multiple();

      std::cout << std::endl << "Number of executions = " << lNumExecutions
                << std::endl;

      lDiffCompileTime = std::auto_ptr<zorba::Duration>(lStopCompileTime.subtractDateTime(&lStartCompileTime, 0));

      lDiffCompileUserTime = zorbatm::get_time_elapsed (zorbatm::extract_user_time_detail (lStartCompileTimeInfo), zorbatm::extract_user_time_detail (lStopCompileTimeInfo));

      std::cout << "Compilation time: "
                << lDiffCompileTime->getTotalMilliseconds()
                << " (user: " << lDiffCompileUserTime << ")"
                << " milliseconds" << std::endl;
      
      lDiffFirstExecutionTime = std::auto_ptr<zorba::Duration>(lStopFirstExecutionTime.subtractDateTime(&lStartFirstExecutionTime, 0));

      lDiffFirstExecutionUserTime = zorbatm::get_time_elapsed (zorbatm::extract_user_time_detail (lStartFirstExecutionTimeInfo), zorbatm::extract_user_time_detail (lStopFirstExecutionTimeInfo));

      std::cout << "First Execution time: "
                << lDiffFirstExecutionTime->getTotalMilliseconds()
                << " (user: " << lDiffFirstExecutionUserTime << ")"
                << " milliseconds (i.e. parsing the document is included)" << std::endl;
    
      if (lNumExecutions > 1) 
      {
        std::auto_ptr<zorba::Duration> temp = std::auto_ptr<zorba::Duration>(lStopExecutionTime.subtractDateTime(&lStartExecutionTime, 0));
        lDiffExecutionTime =  std::auto_ptr<zorba::Duration>(*temp / zorba::Double::parseInt(lNumExecutions - 1));

        lDiffExecutionUserTime =
          zorbatm::get_time_elapsed (zorbatm::extract_user_time_detail (lStartExecutionTimeInfo),
                                     zorbatm::extract_user_time_detail (lStopExecutionTimeInfo))
          / (lNumExecutions - 1);

        std::cout << "Average Execution time: "
                  << lDiffExecutionTime->getTotalMilliseconds()
                  << " (user: " << lDiffExecutionUserTime << ")"
                  << " milliseconds" << std::endl;
      }
    }
    
    queryNo++;
  }
  
  return 0;
}
