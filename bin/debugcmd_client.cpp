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

#include <zorba/zorba.h>

using namespace zorba;

CommandLineEventHandler::CommandLineEventHandler( std::istringstream & aQueryFile,
                                                  std::istream & anInput,
                                                  std::ostream & anOutput,
                                                  ZorbaDebuggerClient * aClient )
 : theQueryFile( aQueryFile ),
   theOutput( anOutput ),
   theInput( anInput ),
   theClient( aClient ){}

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

void CommandLineEventHandler::list( unsigned int aBegin, unsigned int anEnd )
{
  std::string lLine;
  unsigned int lLineNo = 0;
  theQueryFile.clear();
  theQueryFile.seekg( 0, std::ios::beg );
  while ( ! theQueryFile.eof() )
  {
    lLineNo++;
    std::getline( theQueryFile, lLine, '\n');
    if ( lLineNo >= aBegin && lLineNo <= aBegin )
    {
      theOutput << lLineNo << '\t' << lLine << std::endl;
    }
  }
}

void CommandLineEventHandler::started()
{
  theOutput << "Launch the query" << std::endl;
}

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
  theOutput << "End of query" << std::endl;
  exit(0);
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
  if( ! theInput.eof() )
  {
    theOutput.flush();
    theOutput << "(xqdb) ";
    theOutput.flush();
    
    std::string lLine;
    std::getline( theInput, lLine, '\n');

	  std::vector<std::string> lArgs = get_args( lLine );
    std::string lCommand = lArgs.at( 0 ); 
    
    if ( lCommand == "q" || lCommand == "quit" )
    {
      theClient->terminate();
      exit(7);
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
    } else if ( lCommand == "l" || lCommand == "list" ) {
      if ( theClient->isQuerySuspended() )
      {
        list();
        return;
      } else {
        theOutput << "The query is not suspended." << std::endl;
      }
    } else if ( lCommand == "v" || lCommand == "version" ) {
        version();
    } else {
      theOutput << "Unknown command \"" << lCommand << "\" Try \"help\"." << std::endl;
    }
    handle_cmd();
  }
}
void CommandLineEventHandler::help()
{
  //TODO: Full documentation of each command
  theOutput << "List of available commands:" << std::endl;
  theOutput << "run      -- Run the query." << std::endl;
  theOutput << "break    -- Set a breakpoint at the specified file and line." << std::endl;
  theOutput << "continue -- Resume the query execution." << std::endl;
  theOutput << "list     -- Display the executed query line." << std::endl;
//  theOutput << "stop     -- Stop the query execution." << std::endl;
  theOutput << "quit     -- Quit Zorba debugger." << std::endl;
  theOutput << "version  -- Display the version of Zorba engine and its debugger" << std::endl;
  theOutput << "help     -- This help." << std::endl;
}

void CommandLineEventHandler::version()
{
  //TODO: Add debugger version
  theOutput << "Zorba " << Zorba::version() << '.' << std::endl;
}

