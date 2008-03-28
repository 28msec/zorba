#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <zorba/zorba.h>

#include "zorbacmdproperties.h"

#include <boost/date_time/posix_time/posix_time.hpp>

bool
populateStaticContext(zorba::StaticContext_t& aStaticContext, ZorbaCMDProperties* aProperties)
{
  if (aProperties->getBoundarySpace().size() != 0 )
  {
    aStaticContext->setBoundarySpacePolicy( aProperties->getBoundarySpace().compare("preserve") == 0 
                                            ? zorba::StaticContext::preserve_space 
                                            : zorba::StaticContext::strip_space );
  }

  if (aProperties->getConstructionMode().size() != 0 )
  {
    aStaticContext->setConstructionMode( aProperties->getBoundarySpace().compare("preserve") == 0 
                                         ? zorba::StaticContext::preserve_cons 
                                         : zorba::StaticContext::strip_cons );
  }

  if (aProperties->getOrderingMode().size() != 0 )
  {
    aStaticContext->setOrderingMode( aProperties->getBoundarySpace().compare("ordered") == 0 
                                     ? zorba::StaticContext::ordered 
                                     : zorba::StaticContext::unordered );
  }

  if (aProperties->getBaseUri().size() != 0 )
  {
    // TODO
    //aStaticContext->setBaseURI( zorba::xqp_string(aProperties->getBaseUri()) );
  }

  if (aProperties->getDefaultCollation().size() != 0 )
  {
    // TODO 
    //aStaticContext->setDefaultCollation( zorba::xqp_string(aProperties->getDefaultCollation()) );
  }
  return true;
}

bool
populateDynamicContext(zorba::DynamicContext_t& aDynamicContext, ZorbaCMDProperties* aProperties)
{
  if ( aProperties->getContextItem().size() != 0 ) {
    std::ifstream lInStream(aProperties->getContextItem().c_str());
    aDynamicContext->setContextItemAsDocument(aProperties->getContextItem(), lInStream);
  }

  for (ZorbaCMDProperties::ExternalVars_t::const_iterator lIter = aProperties->externalVarsBegin();
      lIter != aProperties->externalVarsEnd(); ++lIter)
    if ((*lIter).inline_file) {
      std::ifstream lInStream((*lIter).var_value.c_str());
      aDynamicContext->setVariableAsDocument((*lIter).var_name, (*lIter).var_value, lInStream);
    } else {
      zorba::Item lItem = zorba::Zorba::getInstance()->getItemFactory()->createString((*lIter).var_value);
      aDynamicContext->setVariable((*lIter).var_name, lItem);
    }
    
  return true;
}

#ifndef _WIN32_WCE
int main(int argc, char* argv[])
#else
int _tmain(int argc, _TCHAR* argv[])
#endif
{
  zorba::Zorba* lZorbaInstance = zorba::Zorba::getInstance();

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
              << zorba::Zorba::version() << std::endl;
    return 0;
  }
  
  // write to file or standard out
  std::auto_ptr<std::ostream> lFileStream (lProperties.getOutputFile().size() > 0 
                                           ? new std::ofstream(lProperties.getOutputFile().c_str()) 
                                           : 0 );
  std::ostream* lOutputStream = lFileStream.get();
  if ( lOutputStream == 0 ) {
    lOutputStream = &std::cout;
  }
  else if ( !lOutputStream->good() ) {
    std::cerr << "could not write to output file " << lProperties.getOutputFile() << std::endl;
    return 2;
  }

  // input file (either from a file or given as parameter)
  const char* fname = lProperties.getQueryOrFile().c_str();
  std::auto_ptr<std::istream> qfile(!lProperties.inlineQuery() && *fname!='\0' ?
                                     (std::istream*) new std::ifstream(fname) :
                                     (std::istream*) new std::istringstream(fname));

  if ( !lProperties.inlineQuery() && !qfile->good() || qfile->eof() ) {
    std::cerr << "file " << fname << " not found not readable" << std::endl;
    return 3;
  } else if (*fname == '\0') {
    std::cerr << "no query given" << std::endl;
    return 3;
  }



  // print the query if requested
  if ( lProperties.printQuery() )
  {
    *lOutputStream << "Query:\n";
    std::copy (std::istreambuf_iterator<char> (*qfile), 
               std::istreambuf_iterator<char> (), std::ostreambuf_iterator<char> (*lOutputStream));
    *lOutputStream << std::endl;
    qfile->seekg(0); // go back to the beginning
  }

  // time compilation and execution
  bool lTiming = lProperties.useTiming();
  boost::posix_time::ptime lStartCompileTime, lStopCompileTime;
  boost::posix_time::ptime lStartFirstExecutionTime, lStopFirstExecutionTime;
  boost::posix_time::ptime lStartExecutionTime, lStopExecutionTime;
  boost::posix_time::time_duration lDiffCompileTime;
  boost::posix_time::time_duration lDiffFirstExecutionTime;
  boost::posix_time::time_duration lDiffExecutionTime;

  zorba::XQuery_t lQuery;
  zorba::StaticContext_t lStaticContext = lZorbaInstance->createStaticContext();

  // populate the static context with information passed as parameter
  if (! populateStaticContext(lStaticContext, &lProperties) ) {
    return 3;
  }

  try {
    if (lTiming)
      lStartCompileTime = boost::posix_time::microsec_clock::local_time();

    lQuery = lZorbaInstance->createQuery(*qfile, lStaticContext);

    if (lTiming)
      lStopCompileTime = boost::posix_time::microsec_clock::local_time();
  }
  catch (zorba::ZorbaException& e) // catch parse errors and exit the program
  {
    std::cerr << e << std::endl;
    return 3;
  }

  // populat the dynamic context
  zorba::DynamicContext_t lDynamicContext = lQuery->getDynamicContext();
  try {
    if ( ! populateDynamicContext(lDynamicContext, &lProperties) )
    {
      return 4;
    }
  } catch (zorba::ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return 6;
  }

  int lNumExecutions = lProperties.getNoOfExecutions();

  try
  {
    if (lTiming)
      lStartFirstExecutionTime = boost::posix_time::microsec_clock::local_time();

      
    if (lProperties.serializeHTML()) {
  //  lQuery->serializeHTML(*lOutputStream);
    } else if (lProperties.serializeText()) {
  //  lQuery->serializeTEXT(*lOutputStream);
    } else
      *lOutputStream << lQuery;

    if (lTiming)
      lStopFirstExecutionTime = boost::posix_time::microsec_clock::local_time();

    lNumExecutions--;

    if (lTiming)
      lStartExecutionTime = boost::posix_time::microsec_clock::local_time();

    while (--lNumExecutions >= 0 )
    {
      if (lProperties.serializeHTML()) {
//        lQuery->serializeHTML(*lOutputStream);
      } else if (lProperties.serializeText()) {
//        lQuery->serializeTEXT(*lOutputStream);
      } else
        *lOutputStream << lQuery;
    }

    if (lTiming)
      lStopExecutionTime = boost::posix_time::microsec_clock::local_time();

  }
  catch (zorba::ZorbaException& e)
  {
    std::cerr << e << std::endl;
    return 5;
  } 
  
  if (lTiming) {
    lNumExecutions = lProperties.getNoOfExecutions();

    std::cerr << std::endl << "Number of executions = "
              << lNumExecutions << std::endl;

    lDiffCompileTime = lStopCompileTime - lStartCompileTime; 
    std::cerr << "Compilation time: " 
              << lDiffCompileTime.total_milliseconds()
              << " milliseconds" << std::endl;

    lDiffFirstExecutionTime = lStopFirstExecutionTime - lStartFirstExecutionTime;
    std::cerr << "First Execution time: " 
              << lDiffFirstExecutionTime.total_milliseconds()
              << " milliseconds (i.e. parsing the document is included)" << std::endl;

    if (lNumExecutions > 1) {
      lDiffExecutionTime = (lStopExecutionTime - lStartExecutionTime) /
                            (lNumExecutions - 1); 
      std::cerr << "Average Execution time: " 
                << lDiffExecutionTime.total_milliseconds()
                << " milliseconds" << std::endl;
    }
  }

  return 0;
}
