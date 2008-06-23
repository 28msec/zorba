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
#include <string>
#include <zorba/debugger_client.h>

#include "debugcmd_client.h"

#if WIN32
#include <windows.h>
#endif

using namespace zorba;

CommandLineEventHandler::CommandLineEventHandler( std::ostream & anOutput ): theOutput( anOutput ){}

void CommandLineEventHandler::started()
{

}

void CommandLineEventHandler::idle()
{

}

void CommandLineEventHandler::suspended( QueryLocation & aLocation, SuspendedBy aCause )
{
  theOutput << "Suspended at line " << aLocation.getLineBegin() << std::endl; 
}

void CommandLineEventHandler::resumed()
{

}

void CommandLineEventHandler::terminated()
{

}

std::vector<std::string> get_args( const std::string& str )
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

void debugcmd_client( std::istream & anInput,
                      std::ostream & anOutput,
                      unsigned short aRequestPortno,
                      unsigned short aEventPortno )
{
  zorba::ZorbaDebuggerClient * lDebuggerClient;
  try
  {
    lDebuggerClient = ZorbaDebuggerClient::createClient( aRequestPortno, aEventPortno );
    CommandLineEventHandler lEventHandler( anOutput );
    lDebuggerClient->registerEventHandler( &lEventHandler );
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
    std::getline( anInput, lLine, '\n' );

	  std::vector<std::string> lArgs = get_args( lLine );
    std::string lCommand = lArgs.at( 0 ); 
    
    if ( lCommand == "q" || lCommand == "quit" )
    {
      lDebuggerClient->terminate();
    } else if  ( lCommand == "b" || lCommand == "break" ) {
     
      if ( lArgs.size() < 2 )
      {
        anOutput << "Invalid syntax." << std::endl;
        anOutput << "(b|break) <line number>" << std::endl;
      }
      unsigned int lLineNo = atoi( lArgs.at(1).c_str() );
      lDebuggerClient->addBreakpoint( lLineNo );
      anOutput << "Set breakpoint at line " << lLineNo << std::endl;
    
    } else if ( lCommand ==  "r" || lCommand == "run" ) {
      
      lDebuggerClient->run();
      
#if WIN32
	  Sleep( 1 );
#else
	  sleep( 1 );
#endif
    
    } else if ( lCommand == "s" || lCommand ==  "stop" ) {
      if( lDebuggerClient->isQueryIdle() || lDebuggerClient->isQueryTerminated() )
      {
        anOutput << "There is no query running." << std::endl;
      } else {
        lDebuggerClient->terminate();
        anOutput << "Query execution terminated" << std::endl;
      }
    }else if ( lCommand == "h" || lCommand == "help" ) {
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
