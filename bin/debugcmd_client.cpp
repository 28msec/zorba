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

CommandLineEventHandler::CommandLineEventHandler( std::auto_ptr<std::istream> &aQueryFile,
                                                  std::istream & anInput,
                                                  std::ostream & anOutput,
                                                  ZorbaDebuggerClient * aClient )
 : theQueryFile( aQueryFile ),
   theOutput( anOutput ),
   theInput( anInput )
{
  theClient = aClient;
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

void CommandLineEventHandler::history()
{
  theOutput << "Command history:" << std::endl;
  for ( unsigned int i = 0 ; i < theHistory.size(); i++ )
  {
    theOutput << i+1 << ' ' << theHistory.at( i ) << std::endl;
  }
}

void CommandLineEventHandler::list( unsigned int aLineNo )
{
  list( aLineNo, aLineNo );
}

void CommandLineEventHandler::list( unsigned int aBegin, unsigned int anEnd )
{
  std::string lLine;
  unsigned int lLineNo = 0;
  std::ifstream * lFile = dynamic_cast< std::ifstream * >( theQueryFile.get() );
  if ( lFile != 0 )
  {
    theQueryFile.reset( new std::ifstream( theClient->getFileName().c_str() ) );
  } else {
    theQueryFile->clear();
    theQueryFile->seekg( 0, std::ios::beg );
  }
  
  while ( ! theQueryFile->eof() )
  {
    lLineNo++;
    std::getline( *theQueryFile, lLine, '\n');
    if ( lLineNo >= aBegin && lLineNo <= anEnd )
    {
      theOutput << lLineNo << '\t' << lLine << std::endl;
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

void CommandLineEventHandler::evaluated( String &anExpr, String &aResult )
{
  theOutput << aResult << std::endl;
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
    theOutput.flush();
    theOutput << "(xqdb) ";
    theOutput.flush();
    std::string lLine;
    std::getline( theInput, lLine, '\n');
    handle_cmd( lLine );
}

void CommandLineEventHandler::handle_cmd( unsigned int aCommandNo )
{
  if ( aCommandNo > 0 && aCommandNo <= theHistory.size() )
  {
    handle_cmd( theHistory.at( aCommandNo ) );
  } else {
    theOutput << "Invalid command number. Try \"history\"." << std::endl;
  }
}

void CommandLineEventHandler::handle_cmd( std::string aCommand )
{
  if( ! theInput.eof() )
  {
    if ( aCommand == "" )
    {
      handle_cmd();
      return;
    }
    
    if ( aCommand.at(0) != '%' )
    {
      std::vector< std::string >::iterator lEnd;
      lEnd = std::unique( theHistory.begin(), theHistory.end() );
      theHistory.erase( lEnd, theHistory.end() );
      theHistory.push_back( aCommand );
    }

	  std::vector<std::string> lArgs = get_args( aCommand );
    
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
          handle_cmd();
          return;
        }
      }
      theClient->quit();
      exit(7);
    } else if ( lCommand == "s" || lCommand == "stop" ) {
      theClient->terminate();
      return;
    } else if ( lCommand == "cl" || lCommand == "clear" ) {
      theClient->clearBreakpoints();
    } else if  ( lCommand == "b" || lCommand == "break" ) {
      if ( lArgs.size() < 2 )
      {
        theOutput << "Invalid syntax." << std::endl;
        theOutput << "(b|break) <line number>" << std::endl;
      } else {
        unsigned int lLineNo = atoi( lArgs.at(1).c_str() );
        if( lLineNo == 0 )
        {
          theOutput << "Invalid line number: " << lArgs.at(1) << '.' << std::endl;
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
      if ( theClient->isQuerySuspended() )
      {
        list();
      } else {
        theOutput << "The query is not suspended." << std::endl;
      }
    } else if( lCommand == "vars" || lCommand == "variables" ) {
      std::list<Variable> list = theClient->getAllVariables();
      std::list<Variable>::iterator it;
      for ( it = list.begin(); it != list.end(); it++ )
      {
        theOutput << "$" << it->getName() << " (" << it->getType() << ")" << std::endl;
      }
    }else if ( lCommand == "v" || lCommand == "version" ) {
        version();
    } else if ( lCommand == "hi" || lCommand == "history" ) {
        history();
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
    } else if( lCommand.at( 0 ) == '%' ) {
      unsigned int lCommandNo = atoi( lCommand.substr( 1 ).c_str() );
      handle_cmd( lCommandNo - 1 ); 
    } else {
      theOutput << "Unknown command \"" << aCommand << "\" Try \"help\"." << std::endl;
    }
    handle_cmd();
  }
}

void CommandLineEventHandler::help()
{
  //TODO: Full documentation of each command
  theOutput << "List of available commands:" << std::endl;
  theOutput << "history  -- Print the command history." << std::endl;
  theOutput << "%<num>   -- Execute a previous command." << std::endl;
  theOutput << "run      -- Run the query." << std::endl;
  theOutput << "eval     -- Evaluate an xquery expression and print its result." << std::endl;
  theOutput << "break    -- Set a breakpoint at the specified file and line." << std::endl;
  theOutput << "continue -- Resume the query execution." << std::endl;
  theOutput << "next     -- Step over the next instruction." << std::endl;
  theOutput << "clear    -- Clear breakpoints." << std::endl;
  theOutput << "list     -- Display the executed query line." << std::endl;
  theOutput << "stop     -- Stop the query execution." << std::endl;
  theOutput << "quit     -- Quit Zorba debugger." << std::endl;
  theOutput << "version  -- Display the version of Zorba engine and its debugger" << std::endl;
  theOutput << "help     -- This help." << std::endl;
}

void CommandLineEventHandler::version()
{
  //TODO: Add debugger version
  theOutput << "Zorba " << Zorba::version() << '.' << std::endl;
}

