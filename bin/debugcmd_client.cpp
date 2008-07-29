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
#include "debugcmd_client.h"

#include <fstream>
#include <sstream>
#include <csignal>
#include <boost/bind.hpp> 
#include <zorba/zorba.h>

using namespace zorba;

#ifdef SIGINT /* not all system have SIGINT */
void suspend( int aSignum )
{
  ZorbaDebuggerClient * lClient = CommandLineEventHandler::getClient();
  if( lClient != 0 && lClient->isQueryRunning() )
  {
    lClient->suspend();
  } else {
    //if the query is not running, we call the default signal handling
    signal( SIGINT, SIG_DFL ); 
    raise( SIGINT );
  }
}
#endif

ZorbaDebuggerClient * CommandLineEventHandler::theClient = 0;

ZorbaDebuggerClient * CommandLineEventHandler::getClient()
{
  return theClient;
}

CommandLineEventHandler::CommandLineEventHandler( std::string aFileName,
                                                  std::auto_ptr<std::istream> &aQueryFile,
                                                  std::istream & anInput,
                                                  std::ostream & anOutput,
                                                  ZorbaDebuggerClient * aClient )
 : theFileName( aFileName ),
   theQueryFile( aQueryFile ),
   theOutput( anOutput ),
   theInput( anInput )
{
  theClient = aClient;
}

void CommandLineEventHandler::listMore()
{
  int start = theClient->getLineNo() - 4;
  if ( start <= 0 )
  {
    list( 1, 9 );
  } else {
    list( start, theClient->getLineNo() + 4 );
  }
}

void CommandLineEventHandler::list()
{
  int start = theClient->getLineNo() - 2;
  if ( start <= 0 )
  {
    list( 1, 5 );
  } else {
    list( start, theClient->getLineNo() + 2 );
  }
}

void CommandLineEventHandler::list( unsigned int aLineNo )
{
  list( aLineNo, aLineNo );
}

void CommandLineEventHandler::list( unsigned int aBegin, unsigned int anEnd, bool listAll )
{
  std::string lLine;
  unsigned int lLineNo = 0;
  std::ifstream * lFile = dynamic_cast< std::ifstream * >( theQueryFile.get() );
  if ( lFile != 0 )
  {
    theQueryFile.reset( new std::ifstream( theFileName.c_str() ) );
  } else {
    theQueryFile->clear();
    theQueryFile->seekg( 0, std::ios::beg );
  }
  
  while ( theQueryFile->good() && ! theQueryFile->eof() )
  {
    lLineNo++;
    std::getline( *theQueryFile, lLine, '\n');
    if ( (lLineNo >= aBegin && lLineNo <= anEnd) || listAll )
    {
      if ( lLineNo == theClient->getLineNo() )
      {
#ifdef WIN32
        HANDLE lConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        const int saved_configuration = GetConsoleTextAttribute(lConsole);
        SetConsoleTextAttribute(lConsole, 4+15*16); 
        theOutput << lLineNo << '\t' << lLine <<  std::endl;
        SetConsoleTextAttribute(lConsole, saved_configuration);
#else
        theOutput << "\033[1m" << lLineNo << '\t' << lLine << "\033[0m" << std::endl;
#endif
     } else {
        theOutput << lLineNo << '\t' << lLine << std::endl;
      }
    }
  }
}

void CommandLineEventHandler::suspend( int aSignum )
{
  if( theClient->isQueryRunning() )
  {
    theClient->suspend();
  } else {
    exit(8);  
  }
}

void CommandLineEventHandler::started(){}

void CommandLineEventHandler::idle()
{
  theOutput << "Query idle" << std::endl;
  handle_cmd();
}

void CommandLineEventHandler::suspended( QueryLocation & aLocation, SuspendedBy aCause )
{
  list( aLocation.getLineBegin() );
  handle_cmd();
}

void CommandLineEventHandler::resumed()
{
  //do nothing...
}

void CommandLineEventHandler::terminated()
{
  theOutput << "End of query execution" << std::endl;
  handle_cmd();
}

void CommandLineEventHandler::evaluated( String &anExpr, String &aResult,
                                         String &aReturnType, String &anError )
{
  if ( anError.length() > 0 )
  {
    theOutput << anError << std::endl;
  } else {
    theOutput << aResult << " (" << aReturnType << ')' << std::endl;
  }
  handle_cmd();
}

std::vector<std::string> CommandLineEventHandler::get_args( const std::string& str )
{
  // Skip delims at beginning, find start of first token
  std::string::size_type lastPos = str.find_first_not_of(' ', 0);
  // Find next delimiter @ end of token
  std::string::size_type pos     = str.find_first_of(' ', lastPos);
  // output vector
  std::vector<std::string> tokens;

  while (std::string::npos != pos || std::string::npos != lastPos)
  {
    // Found a token, add it to the vector.
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    // Skip delims.  Note the "not_of". this is beginning of token
    lastPos = str.find_first_not_of(' ', pos);
    // Find next delimiter at end of token.
    pos     = str.find_first_of(' ', lastPos);
   }
   return tokens;
}

void CommandLineEventHandler::handle_cmd()
{
  while( ! theInput.eof() )
  {
    theOutput.flush();
    theOutput << "(xqdb) ";
    theOutput.flush();
    std::string lLine;
    std::getline( theInput, lLine, '\n');
    
    if ( lLine == "" )
    {
      continue;
    }
    
	  std::vector<std::string> lArgs = get_args( lLine );
    
    std::string lCommand = lArgs.at( 0 ); 
    
    if ( lCommand == "q" || lCommand == "quit" )
    {
      if ( ! theClient->isQueryIdle() )
      {
        std::string quit;
        theOutput << "The query is running. Exit anyway? (y or n) " << std::endl;
        std::getline( theInput, quit, '\n');
        if( quit != "y" && quit != "yes" )
        {
          continue;
        }
      }
      theClient->quit();
      exit(7);
    } else if ( lCommand == "s" || lCommand == "stop" ) {
      theClient->terminate();
    }else if ( lCommand == "cl" || lCommand == "clear" ) {
      if ( lArgs.size() > 2 && lArgs.at(1) == "all" )
      {
        theClient->clearBreakpoints();
        theOutput << "All breakpoints have been cleared." << std::endl;
      } else if ( atoi(lArgs.at(1).c_str()) != 0 ) {
        bool lResult = theClient->clearBreakpoint( atoi(lArgs.at(1).c_str()) );
        if ( lResult )
        {
          theOutput << "Breakpoint " << atoi(lArgs.at(1).c_str()) << " has been cleared." << std::endl;
        } else {
          theOutput << "The breakpoint " << atoi(lArgs.at(1).c_str()) << " doesn't exit." << std::endl;
        }
      } else {
        theOutput << "Invalid syntax." << std::endl;
        theOutput << "clear <number>" << std::endl;
        theOutput << "clear all" << std::endl;
      }
    } else if ( lCommand == "w" || lCommand == "watch" ) {
      if ( lArgs.size() < 2 )
      {
        theOutput << "Invalid syntax." << std::endl;
        theOutput << "watch <xquery expr>" << std::endl;
      } else {
        theClient->addBreakpoint( lArgs.at(1) );
        theOutput << "Set watchpoint: " << lArgs.at(1) << '.' << std::endl;
      }
    } else if  ( lCommand == "b" || lCommand == "break" ) {
      if ( lArgs.size() < 2 )
      {
        theOutput << "Invalid syntax." << std::endl;
        theOutput << "(b|break) <line number>" << std::endl;
      } else {
        unsigned int lLineNo = atoi( lArgs.at(1).c_str() );
        if( lLineNo == 0 )
        {
          theOutput << "Invalid line number." << std::endl;
        } else {
          theClient->addBreakpoint( lLineNo );
          theOutput << "Set breakpoint at line " << lLineNo << '.' << std::endl;
        }
      }
    } else if ( lCommand ==  "r" || lCommand == "run" ) {
      if ( ! theClient->isQueryIdle() )
      {
        std::string reload;
        theOutput << "The query being debugged has already started." << std::endl;
        theOutput << "Reload query and start it from beginning? (y or n) " << std::endl;
        std::getline( theInput, reload, '\n');
        if ( reload != "y" && reload != "yes" )
        {
          handle_cmd();
          return;
        }
      }
      theOutput << "Launch the query" << std::endl;
      theClient->run();
      return;
    } else if ( lCommand == "h" || lCommand == "help" ) {
      help();
    } else if ( lCommand == "c" || lCommand == "continue" ) {
      if ( theClient->isQuerySuspended() )
      {
        theClient->resume();
        return;
      } else {
        theOutput << "The query is not suspended." << std::endl;
      }
    } else if ( lCommand == "n" || lCommand == "next" ) {
      if ( theClient->isQuerySuspended() )
      {
        theOutput << "next is not implemented yet." << std::endl;
        //theClient->stepOver();
        return;
      } else {
        theOutput << "The query is not suspended." << std::endl;
      }
    } else if ( lCommand == "l" || lCommand == "list" ) {
        if ( lArgs.size() >= 2 && lArgs.at(1) == "more" )
        {
          listMore();
        } else if ( lArgs.size() >= 2 && lArgs.at(1) == "all" ) {
          list( 0, 0, true );
        } else if ( lArgs.size() >= 2 && ( lArgs.at(1) == "b" || lArgs.at(1) == "breakpoints" ) ) {
          std::map<unsigned int, String> lBreakpoints = theClient->getBreakpoints();
          std::map<unsigned int, String>::const_iterator it;
          for( it = lBreakpoints.begin(); it != lBreakpoints.end(); it++ )
          {
            theOutput << "id:" << it->first << '\t' << it->second << std::endl;
          }       
        } else if ( lArgs.size() >= 2 && atoi(lArgs.at(1).c_str()) !=0 ) {
          int line = atoi(lArgs.at(1).c_str());
          int start = theClient->getLineNo()-line;
          int end = theClient->getLineNo()+line;
          list( start<=0?1:start, end<=0?1:end );
        } else {
          list();
       }
    } else if( lCommand == "var" || lCommand == "vars" || lCommand == "variables" ) {
      std::list<Variable> list = theClient->getAllVariables();
      std::list<Variable>::iterator it;
      for ( it = list.begin(); it != list.end(); it++ )
      {
        theOutput << "$" << it->getName() << " " << it->getType() << std::endl;
      }
    }else if ( lCommand == "v" || lCommand == "version" ) {
        version();
    } else if ( lCommand == "p" || lCommand == "print" ||
                lCommand == "e" || lCommand == "eval" ) {
        if ( lArgs.size() < 2 )
        {
          theOutput << "Invalid syntax." << std::endl;
          theOutput << "(e|eval) <expr>" << std::endl;
          handle_cmd();
        } else {
          String lExpr( lArgs.at(1).c_str() );  
          theClient->eval( lExpr );
        }
        return;
        //theOutput << theClient->eval() << std::endl;
        //handle_cmd();
    } else {
      theOutput << "Unknown command \"" << lLine << "\" Try \"help\"." << std::endl;
    }
  }
}

void CommandLineEventHandler::help()
{
  //TODO: Full documentation of each command
  theOutput << "List of available commands:" << std::endl;
  theOutput << "run      -- Run the query." << std::endl;
  theOutput << "eval     -- Evaluate an xquery expression and print its result." << std::endl;
  theOutput << "break    -- Set a breakpoint at the specified file and line." << std::endl;
  theOutput << "continue -- Resume the query execution." << std::endl;
  theOutput << "next     -- Step over the next instruction." << std::endl;
  theOutput << "clear    -- Clear breakpoints." << std::endl;
  theOutput << "list     -- Display the executed query line." << std::endl;
  theOutput << "status   -- Display the status of the query." << std::endl;
  theOutput << "stop     -- Stop the query execution." << std::endl;
  theOutput << "quit     -- Quit Zorba debugger." << std::endl;
  theOutput << "version  -- Display the version of Zorba engine and its debugger" << std::endl;
  theOutput << "watch    -- Add watchpoint to the query" << std::endl;
  theOutput << "help     -- This help." << std::endl;
}

void CommandLineEventHandler::version()
{
  //TODO: Add debugger version
  theOutput << "Zorba " << Zorba::version() << '.' << std::endl;
}

