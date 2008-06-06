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
#include <vector>

#include <zorba/debugger_client.h>

#include "debugcmd_client.h"

bool isCommand( std::string & aLine, std::string aCommand )
{
  return aLine.substr( 0, aCommand.length() ) == aCommand;
}

void debugcmd_client( std::istream & anInput,
                      std::ostream & anOutput,
                      unsigned short aRequestPortno,
                      unsigned short aEventPortno )
{
  zorba::ZorbaDebuggerClient * lDebuggerClient;
  try
  {
    lDebuggerClient = zorba::ZorbaDebuggerClient::createClient( aRequestPortno,
                                                                aEventPortno );
  } catch( std::exception &e ) {
    anOutput << "Could not start the debugger client: " << std::endl;
    anOutput << e.what() << std::endl;
    exit(7);
  }

  while( ! anInput.eof() )
  {
    anOutput << "(xqdb) ";
    anOutput.flush();
    
    std::string lLine;
    
    std::getline( anInput, lLine );
    
    if ( isCommand( lLine, "q" ) || isCommand( lLine, "quit" ) )
    {
      lDebuggerClient->terminate();
      while( ! lDebuggerClient->isQueryTerminated() )
      {
        usleep(10);
      }
      exit(7);
    } else if  ( isCommand( lLine, "b" ) || isCommand( lLine, "break" ) ) {
      unsigned int lLineNo;
      std::cerr << "Line: " << lLineNo << std::endl;
    } else if ( isCommand( lLine, "r" ) || isCommand( lLine, "run" ) ) {
      lDebuggerClient->run();
      while( lDebuggerClient->isQueryRunning() )
      {
        std::cout.flush();     
      }
      sleep( 1 );
    } else if ( isCommand( lLine, "s" ) || isCommand( lLine, "stop" ) ) {
      if( lDebuggerClient->isQueryIdle() || lDebuggerClient->isQueryTerminated() )
      {
        anOutput << "There is no query running." << std::endl;
      } else {
        lDebuggerClient->terminate();
        anOutput << "Query execution terminated" << std::endl;
      }
    }else if ( isCommand( lLine, "h" ) || isCommand( lLine, "help" ) ) {
      //TODO: Full documentation of each command
      anOutput << "List of available commands:" << std::endl;
      anOutput << "run   -- Run the query." << std::endl;
      anOutput << "break -- Set a breakpoint at the specified file and line." << std::endl;
      anOutput << "list  -- Display the executed query line." << std::endl;
      anOutput << "stop  -- Stop the query execution." << std::endl;
      anOutput << "quit  -- Quit Zorba debugger." << std::endl;
      anOutput << "version -- Display the version of Zorba engine and its debugger" << std::endl;
      anOutput << "help  -- This help." << std::endl;
    } else {
      anOutput << "Unknown command \"" << lLine << "\" Try \"help\"." << std::endl;
    }
  }
}
