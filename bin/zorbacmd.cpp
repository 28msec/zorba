#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <inttypes.h>

#include "zorba/zorba_singlethread.h"

#include "zorbacmdproperties.h"

#include "boost/date_time/posix_time/posix_time.hpp" 

bool
populateStaticContext(xqp::StaticQueryContext_t& aStaticContext, ZorbaCMDProperties* aProperties)
{
  if (aProperties->getBoundarySpace().size() != 0 )
  {
    aStaticContext->setBoundarySpacePolicy( aProperties->getBoundarySpace().compare("preserve") == 0 
                                            ? xqp::StaticQueryContext::preserve_space 
                                            : xqp::StaticQueryContext::strip_space );
  }

  if (aProperties->getConstructionMode().size() != 0 )
  {
    aStaticContext->setConstructionMode( aProperties->getBoundarySpace().compare("preserve") == 0 
                                         ? xqp::StaticQueryContext::cons_preserve 
                                         : xqp::StaticQueryContext::cons_strip );
  }

  if (aProperties->getOrderingMode().size() != 0 )
  {
    aStaticContext->setOrderingMode( aProperties->getBoundarySpace().compare("ordered") == 0 
                                     ? xqp::StaticQueryContext::ordered 
                                     : xqp::StaticQueryContext::unordered );
  }

  if (aProperties->getBaseUri().size() != 0 )
  {
    aStaticContext->setBaseURI( xqp::xqp_string(aProperties->getBaseUri()) );
  }

  if (aProperties->getDefaultCollation().size() != 0 )
  {
    aStaticContext->setDefaultCollation( xqp::xqp_string(aProperties->getDefaultCollation()) );
  }
  return true;
}

bool
populateDynamicContext(xqp::DynamicQueryContext_t& aDynamicContext, ZorbaCMDProperties* aProperties)
{
  if ( aProperties->getContextItem().size() != 0 )  
    aDynamicContext->setContextItemAsDocumentFromFile(aProperties->getContextItem());

  for (ZorbaCMDProperties::ExternalVars_t::const_iterator lIter = aProperties->externalVarsBegin();
      lIter != aProperties->externalVarsEnd(); ++lIter)
    if ((*lIter).inline_file)
      aDynamicContext->setVariableAsDocumentFromFile((*lIter).var_name, (*lIter).var_value);
    else
      aDynamicContext->setVariableAsString((*lIter).var_name, xqp::xqp_string((*lIter).var_value));
    
  return true;
}

#ifndef _WIN32_WCE
int main(int argc, char* argv[])
#else
int _tmain(int argc, _TCHAR* argv[])
#endif
{
  xqp::ZorbaAlertsManager::setThrowExceptionsMode(true);
  xqp::ZorbaSingleThread_t lZorbaInstance = xqp::ZorbaSingleThread::getInstance();

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
    lProperties.printHelp();
    return 1;
  }

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
              << xqp::ZorbaSingleThread::getZorbaVersion() << std::endl;
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
    return 2;
  }

  // the query or the query file
  const std::string& lQueryOrFile = lProperties.getQueryOrFile();

  // print the query if requested
  if ( lProperties.printQuery() )
  {
    if ( lProperties.inlineQuery() )
    {
      *lOutputStream << "Query:" << std::endl << lQueryOrFile << std::endl;
    }
    else
    {
       std::ifstream lInFileStream(lQueryOrFile.c_str());
       if ( !lInFileStream )
       {
         std::cerr << "Query file not found or not readable" << std::endl;
         return 4;
       }

      *lOutputStream << "Query:" << std::endl << lInFileStream.rdbuf() << std::endl;
    }
  }

  // time compilation and execution
  bool lTiming = lProperties.useTiming();
  boost::posix_time::ptime lStartCompileTime, lStopCompileTime;
  boost::posix_time::ptime lStartExecutionTime, lStopExecutionTime;
  boost::posix_time::time_duration lDiffCompileTime;
  boost::posix_time::time_duration lDiffExecutionTime;

  xqp::XQuery_t lQuery;
  xqp::StaticQueryContext_t lStaticContext = lZorbaInstance->createStaticContext();

  // populate the static context with information passed as parameter
  if (! populateStaticContext(lStaticContext, &lProperties) )
  {
    return 3;
  }

  try 
  {
    if ( lProperties.inlineQuery() )
    {
      if (lTiming)
        lStartCompileTime = boost::posix_time::microsec_clock::local_time();

      lQuery = lZorbaInstance->createQuery(lQueryOrFile, lStaticContext);

      if (lTiming)
        lStopCompileTime = boost::posix_time::microsec_clock::local_time();
    }
    else
    {
      if (lTiming)
        lStartCompileTime = boost::posix_time::microsec_clock::local_time();

      lQuery = lZorbaInstance->createQueryFromFile(lQueryOrFile, lStaticContext);

      if (lTiming)
        lStopCompileTime = boost::posix_time::microsec_clock::local_time();
    }
  } catch (xqp::ZorbaException& e) // catch parse errors and exit the program
  {
    std::cerr << e << std::endl;
    return 3;
  }

  // populat the dynamic context
  xqp::DynamicQueryContext_t lDynamicContext;
  try {
    lDynamicContext = lZorbaInstance->createDynamicContext();
    if ( ! populateDynamicContext(lDynamicContext, &lProperties) )
    {
      return 4;
    }
  } catch (xqp::ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return 6;
  }

  try
  {
    int lMultipleExecutions = lProperties.getNoOfExecutions();

    if (lTiming)
      lStartExecutionTime = boost::posix_time::microsec_clock::local_time();

    while (--lMultipleExecutions >= 0 )
    {
      lQuery->initExecution(lDynamicContext);

      if (lProperties.serializeHTML())
        lQuery->serializeHTML(*lOutputStream);
      else if (lProperties.serializeText())
        lQuery->serializeTEXT(*lOutputStream);
      else
        lQuery->serializeXML(*lOutputStream);
    }

    if (lTiming)
      lStopExecutionTime = boost::posix_time::microsec_clock::local_time();

  } catch (xqp::ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return 5;
  } 
  
  if (lTiming)
  {
    lDiffCompileTime = lStopCompileTime - lStartCompileTime; 
    lDiffExecutionTime = (lStopExecutionTime - lStartExecutionTime)/lProperties.getNoOfExecutions(); 

    std::cerr << "Compile time: " 
              << boost::posix_time::to_simple_string(lDiffCompileTime) << std::endl;

    std::cerr << "(Average) execution time: " 
              << boost::posix_time::to_simple_string(lDiffExecutionTime) << std::endl;
  }

  return 0;
}
