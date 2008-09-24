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
#include <zorba/zorba.h>
#ifdef WIN32
#include <windows.h>
#endif

using namespace zorba;

#ifdef SIGINT /* not all system have SIGINT */
void suspend( int aSignum )
{
  ZorbaDebuggerClient * lClient = CommandLineEventHandler::getClient();
  if(lClient != 0 && lClient->isQueryRunning())
  {
    lClient->suspend();
  }else{
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
                                                  ZorbaDebuggerClient * aClient,
                                                  bool aColor)
 : theFileName( aFileName ),
   theQueryFile( aQueryFile ),
   theLocation(0),
   theOutput( anOutput ),
   theInput( anInput ),
   colors(aColor)
{
  theClient = aClient;
}

void CommandLineEventHandler::update_location()
{
  theLocation.reset( theClient->getLocation() );
}

void CommandLineEventHandler::listMore()
{
  update_location();
  int start = theLocation->getLineBegin() - 4;
  if ( start <= 0 )
  {
    list(1, 9);
  } else {
    list(start, theLocation->getLineBegin() + 4);
  }
}

void CommandLineEventHandler::list()
{
  update_location();
  int start = theLocation->getLineBegin() - 2;
  if (start <= 0)
  {
    list(1, 5);
  } else {
    list(start, theLocation->getLineBegin() + 2);
  }
}

void CommandLineEventHandler::list( unsigned int aLineNo )
{
  list( aLineNo, aLineNo );
}

void CommandLineEventHandler::list( std::string &aFileName )
{
  int start = theFileName.length() - aFileName.length();
  if( start >= 0)
  {
    std::stringstream lFileName;
    lFileName << theFileName.substr(0, start+1) << "/" << aFileName;
    theOutput << lFileName.str() << std::endl;
    std::ifstream lFile(lFileName.str().c_str());
    while(lFile.good())
    {
      std::string lLine;
      getline(lFile, lLine, '\n');
      theOutput << lLine << std::endl;
    }
  } else {
    theOutput << "Couldn't find " << aFileName << std::endl;
  } 
}

void CommandLineEventHandler::list( unsigned int aBegin, unsigned int anEnd, bool listAll )
{
  update_location();
  std::string lLine;
  unsigned int lLineNo = 0;
  std::string::iterator lIterator;
  unsigned int i = 0;
  std::ifstream * lFile = dynamic_cast< std::ifstream * >( theQueryFile.get() );
  if ( lFile != 0 )
  {
    if( theLocation->getFileName() == "" )
    {
      theQueryFile.reset( new std::ifstream( theFileName.c_str() ) );
    } else {
      
      theQueryFile.reset( new std::ifstream( theLocation->getFileName().c_str() ) );
    }
  } else {
    theQueryFile->clear();
    theQueryFile->seekg( 0, std::ios::beg );
  }
  theOutput << std::endl; 
  while(theQueryFile->good() && !theQueryFile->eof())
  {
    lLineNo++;
    std::getline( *theQueryFile, lLine, '\n');
    if ( (lLineNo >= aBegin && lLineNo <= anEnd) || listAll )
    {
      if ( lLineNo >= theLocation->getLineBegin() && lLineNo <= theLocation->getLineEnd() )
      {
#ifdef WIN32
        if(colors)
        {
          HANDLE lConsole = GetStdHandle(STD_OUTPUT_HANDLE);
          CONSOLE_SCREEN_BUFFER_INFO lConsoleInfo;
          GetConsoleScreenBufferInfo(lConsole, &lConsoleInfo);
          const int saved_configuration = lConsoleInfo.wAttributes;
          SetConsoleTextAttribute(lConsole, 15+0*16); 
        }
        theOutput << lLineNo << '\t';
        if(colors) SetConsoleTextAttribute(lConsole, saved_configuration);
        for(unsigned int j=1; j <= lLine.length(); j++)
        {
          if((lLineNo==theLocation->getLineBegin() && j >= theLocation->getColumnBegin()) ||
             (theLocation->getLineBegin() != theLocation->getLineEnd() && lLineNo==theLocation->getLineEnd() && j <= theLocation->getColumnEnd()) ||
             (lLineNo > theLocation->getLineBegin() && lLineNo < theLocation->getLineEnd())
            )
          {
            if(colors) SetConsoleTextAttribute(lConsole, 15+0*16); 
            theOutput << lLine.at(j-1);
            if(colors) SetConsoleTextAttribute(lConsole, saved_configuration);
          } else {
            if(colors) SetConsoleTextAttribute(lConsole, 15+0*16); 
            theOutput << lLine.at(j-1);
            if(colors) SetConsoleTextAttribute(lConsole, saved_configuration);
          }
        }
#else
        if(colors) 
          theOutput << "\033[1m" << lLineNo << '\t' << "\033[0m"; 
        else
          theOutput << lLineNo << '\t';
        for(unsigned int j=1; j <= lLine.length(); j++)
        {
          if(colors && ((lLineNo==theLocation->getLineBegin() && j >= theLocation->getColumnBegin()) ||
             (theLocation->getLineBegin() != theLocation->getLineEnd() && lLineNo==theLocation->getLineEnd() && j <= theLocation->getColumnEnd()) ||
             (lLineNo > theLocation->getLineBegin() && lLineNo < theLocation->getLineEnd()))
            )
          {
            theOutput << "\033[1m" << lLine.at(j-1) << "\033[0m";
          } else {
            theOutput << lLine.at(j-1);
          }
        }
#endif
        theOutput << std::endl;
     } else {
        theOutput << lLineNo << '\t' << lLine << std::endl;
      }
    }
  }
  theOutput << std::endl;
}

void CommandLineEventHandler::suspend( int aSignum )
{
  if( theClient->isQueryRunning() )
  {
    theClient->suspend();
  } else {
    //if the query is not running, we call the default signal handler
    signal( SIGINT, SIG_DFL );
    raise( SIGINT );
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
  theOutput << std::endl << "End of query execution" << std::endl;
  handle_cmd();
}

void CommandLineEventHandler::evaluated(String &anExpr, std::map<String, String> &aValuesAndTypes)
{
  std::map<String, String>::iterator it;
  for(it=aValuesAndTypes.begin(); it!=aValuesAndTypes.end(); ++it)
  {
    theOutput << it->first << " " << it->second << std::endl;
  }
  handle_cmd();
}
  
void CommandLineEventHandler::evaluated(String &anExpr, String &anError)
{
  theOutput << anError << std::endl;
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

std::string CommandLineEventHandler::get_expression( const std::vector<std::string> arr )
{
  std::string lExpr;
  std::vector<std::string>::const_iterator it;
  for ( it = arr.begin(); it != arr.end(); ++it )
  {
    if ( it != arr.begin() )
    {
      lExpr.append( *it );
    }
  }
  return lExpr;
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
        if(theClient->isQueryRunning() || theClient->isQuerySuspended())
        {
          theOutput << "The query is running. Exit anyway? (y or n) " << std::endl;
          std::getline( theInput, quit, '\n');
          if( quit != "y" && quit != "yes" )
          {
            continue;
          }
        } else {
          theClient->quit();  
        }
      }
      theClient->quit();
      return;
    //TODO: unimplemented command
    //} else if ( lCommand == "s" || lCommand == "stop" ) {
      //theClient->terminate();
    }else if ( lCommand == "delete" || lCommand == "cl" || lCommand == "clear" ) {
      if ( lArgs.size() >= 2 && lArgs.at(1) == "all" )
      {
        theClient->clearBreakpoints();
        theOutput << "All breakpoints have been cleared." << std::endl;
      } else if ( lArgs.size() >= 2 && atoi(lArgs.at(1).c_str()) > 0 ) {
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
        theClient->addBreakpoint( get_expression( lArgs ) );
        theOutput << "Set watchpoint: " << get_expression( lArgs ) << '.' << std::endl;
      }
    } else if  ( lCommand == "b" || lCommand == "break" ) {
      if ( lArgs.size() < 2 )
      {
        theOutput << "Invalid syntax." << std::endl;
        theOutput << "(b|break) <filename>+:<line number>" << std::endl;
      } else {
        std::string::size_type loc = lArgs.at(1).find(':');
        if( loc != std::string::npos)
        {
          std::string lFileName = lArgs.at(1).substr(0, loc);
          unsigned int lLineNo = atoi( lArgs.at(1).substr(loc+1).c_str() );
          if( lLineNo == 0 )
          {
            theOutput << "Invalid line number"  << std::endl;
          } else {
            theClient->addBreakpoint( lFileName, lLineNo );
          }
        } else {
          unsigned int lLineNo = atoi( lArgs.at(1).c_str() );
          if( lLineNo == 0 )
          {
            theOutput << "Invalid line number." << std::endl;
          } else {
            String lFileName(theFileName);
            theClient->addBreakpoint( lFileName, lLineNo );
            theOutput << "Set breakpoint at line " << lLineNo << " in " << lFileName << '.' << std::endl;
          }
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
        theClient->resume();
        //theOutput << "next is not implemented yet." << std::endl;
        //theClient->stepOver();
        return;
      } else {
        theOutput << "The query is not suspended." << std::endl;
      }
    } else if ( lCommand == "l" || lCommand == "list" ) {
        update_location();
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
        } else if ( lArgs.size() >= 2 && atoi(lArgs.at(1).c_str()) > 0 ) {
          int line = atoi(lArgs.at(1).c_str());
          int start = theLocation.get()==0?0:theLocation->getLineBegin()-line;
          int end = theLocation.get()==0?0:theLocation->getLineBegin()+line;
          list( start<=0?1:start, end<=0?1:end );
        } else if ( lArgs.size() >= 2 && atoi(lArgs.at(1).c_str()) == 0 ) {
          list(lArgs.at(1));
        } else {
          list();
       }
    } else if( lCommand == "var" || lCommand == "vars" || lCommand == "variables" ) {
      
      std::list<Variable> global = theClient->getGlobalVariables();
      std::list<Variable>::iterator it;
      theOutput << "Global variables:" << std::endl;
      for ( it = global.begin(); it != global.end(); it++ )
      {
        theOutput << "$" << it->getName() << " " << it->getType() << std::endl;
      }
      theOutput << std::endl << "Local variables:" << std::endl;
      std::list<Variable> locals = theClient->getLocalVariables();
      for ( it = locals.begin(); it != locals.end(); it++ )
      {
        theOutput << "$" << it->getName() << " " << it->getType() << std::endl;
      }
    } else if ( lCommand == "globals" ) {
      std::list<Variable> list = theClient->getGlobalVariables();
      std::list<Variable>::iterator it;
      for ( it = list.begin(); it != list.end(); it++ )
      {
        theOutput << "$" << it->getName() << " " << it->getType() << std::endl;
      }
    } else if ( lCommand == "locals" ) {
      std::list<Variable> list = theClient->getLocalVariables();
      std::list<Variable>::iterator it;
      for ( it = list.begin(); it != list.end(); it++ )
      {
        theOutput << "$" << it->getName() << " " << it->getType() << std::endl;
      }
    } else if ( lCommand == "v" || lCommand == "version" ) {
        version();
    } else if ( lCommand == "p" || lCommand == "print" ||
                lCommand == "e" || lCommand == "eval" ) {
        if ( lArgs.size() < 2 )
        {
          theOutput << "Invalid syntax." << std::endl;
          theOutput << "(e|eval) <expr>" << std::endl;
          handle_cmd();
        } else {
          String lExpr( get_expression( lArgs ) );  
          theClient->eval( lExpr );
        }
        return;
    } else {
      theOutput << "Unknown command \"" << lLine << "\" Try \"help\"." << std::endl;
    }
  }
}

void CommandLineEventHandler::help()
{
  theOutput << "List of available commands." << std::endl;
  theOutput << "Execution commands:" << std::endl;
  theOutput << "  run      -- Run the query." << std::endl;
  //TODO: unimplemented command
  //theOutput << "  stop     -- Stop the query execution." << std::endl;
  theOutput << "  quit     -- Quit Zorba debugger." << std::endl;
  theOutput << "  continue -- Resume the query execution." << std::endl;
  //TODO: unimplemented command
  theOutput << "  status   -- Display the status of the query." << std::endl;
  theOutput << "Breakpoint commands:" << std::endl;
  theOutput << "  break    -- Set a breakpoint at the specified file and line." << std::endl;
  theOutput << "  watch    -- Add watchpoint to the query" << std::endl;
  theOutput << "  list     -- Display the executed query line." << std::endl;
  theOutput << "  clear    -- Clear breakpoints." << std::endl;
  theOutput << "Data commands:" << std::endl;
  theOutput << "  vars     -- List all variables that are in scope." << std::endl;
  theOutput << "  eval     -- Evaluate an xquery expression and print its result." << std::endl;
  theOutput << "Zorba debugger:" << std::endl;
  theOutput << "  version  -- Display the version of Zorba engine and its debugger" << std::endl;
  theOutput << "  help     -- This help." << std::endl;
}

void CommandLineEventHandler::version()
{
  theOutput << "Zorba " << Zorba::version() << '.' << std::endl;
  theOutput << "Zorba Debugger, Version 0.0.1." << std::endl;
}

