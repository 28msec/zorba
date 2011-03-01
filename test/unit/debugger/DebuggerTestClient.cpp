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
#include "DebuggerTestClient.h"

#include <zorba/zorba.h>

#include <iostream>
#include <sstream>
#include <memory>

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif


using namespace std;
using namespace zorba;

namespace zorba {

DebuggerTestClient::DebuggerTestClient(int aRequestPort, int aEventPort, std::iostream& aQuery)
  : m_request_port(aRequestPort),
    m_event_port(aEventPort),
    m_client(DebuggerClient::createClient(aRequestPort, aEventPort)),
    m_handler(new DebuggerTestHandler(m_client)),
    m_query(aQuery)
{
	m_client->registerEventHandler(m_handler);
}

DebuggerTestClient::~DebuggerTestClient()
{
  delete m_client;
  delete m_handler;
}

void
DebuggerTestClient::run()
{
	m_client->run();
}

void
DebuggerTestClient::eval(std::string anExpr)
{
  String lStr(anExpr);
  m_client->eval(lStr);
}

bool
DebuggerTestClient::waitUntil(DebuggerTestHandler::DebuggerState aDesiredState, int aSeconds)
{
	return m_handler->waitUntil(aDesiredState, aSeconds);
}

std::pair<String, std::list<std::pair<String, String> > >
DebuggerTestClient::getLastEvent()
{
  return m_handler->getLastEvent();
}

void
DebuggerTestClient::resume()
{
  m_client->resume();
}

QueryLocation_t
DebuggerTestClient::addBreakpoint(std::string& aFile, unsigned int aLine)
{
  QueryLocation_t lLocation(m_client->addBreakpoint(aFile, aLine));
  if(lLocation == NULL || lLocation->getLineBegin() == 0) {
    std::cerr << "Couldn't find an expression to break in " << aFile << " at line " << aLine << "\n";
  } else {
    std::cerr << "Set breakpoint at: " <<  lLocation.get()->toString().c_str() << "\n";
  }
  return lLocation;
}

QueryLocation_t
DebuggerTestClient::getLocation() const
{
  return m_client->getLocation();
}

void
DebuggerTestClient::terminate()
{
  m_client->terminate();
}

std::vector<std::string>
DebuggerTestClient::getVariableNames()
{
  std::vector<std::string> lResult;
  std::list<Variable> lVars = m_client->getAllVariables();
  std::list<Variable>::iterator lIter;
  for (lIter = lVars.begin(); lIter != lVars.end(); lIter++) {
    lResult.push_back(lIter->getName().c_str());
  }
  return lResult;
}

void
DebuggerTestClient::clearBreakpoint(std::string& aFile, unsigned int aLine)
{
  m_client->clearBreakpoint(aFile, aLine);
}

}
