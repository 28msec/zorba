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
#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <cassert>

#include <zorba/debugger_event_handler.h>
#include <zorba/util/base64_util.h>

#include "debugger/debugger_clientimpl.h"
#include "debugger/socket_streambuf.h"

namespace zorba {
  
DebuggerClient*
DebuggerClient::createDebuggerClient(
  DebuggerEventHandler* aHandler,
  unsigned short aPort,
  const std::string& aHost)
{
  return new DebuggerClientImpl(aHost, aPort, aHandler);
}

// ****************************************************************************

DebuggerListener::DebuggerListener(DebuggerClientImpl* aClient)
  : theClient(aClient), theStopLooping(false)
{
}

void
DebuggerListener::run()
{
  while (!theStopLooping) {
    std::string str;
    std::getline(*(theClient->theInStream), str, '\0');

#ifndef NDEBUG
    std::stringstream lStr(str);
    std::size_t length;
    lStr >> length;
#endif

    std::getline(*(theClient->theInStream), str, '\0');

    // only assert if we have a good stream (no stream was broken,
    // case in which an empty string will be returned)
    if (theClient->theInStream->good()) {
#ifndef NDEBUG
      assert(str.size() == length);
#endif
    } else {
      break;
    }

    theClient->theHandler->parseMessage(str);

    // TODO: this was the initial implementation. This will have to change
    this->sleep_(250);
  }
}
  
void
DebuggerListener::finish()
{
}

void
DebuggerListener::stopLooping()
{
  theStopLooping = true;
}

// ****************************************************************************

DebuggerClientImpl::DebuggerClientImpl(
  const std::string& aHost,
  unsigned short aPort,
  DebuggerEventHandler* aHandler)
  : theServerSocket(aHost, aPort),
    theSocket(0),
    theInStreamBuffer(0),
    theOutStreamBuffer(0),
    theInStream(0),
    theOutStream(0),
    theHandler(aHandler),
    theListener(0),
    theLastId(0)
{
}

DebuggerClientImpl::~DebuggerClientImpl()
{
  if (theListener) {
    if (theListener->status() == DebuggerListener::RUNNING) {
      theListener->stopLooping();
      theListener->join();
    }
    delete theListener;
  }
  if (theSocket) {
    theInStream->sync();
    delete theInStream;

    theOutStream->flush();
    delete theInStream;

    delete theOutStreamBuffer;
    delete theInStreamBuffer;

    theSocket->close();
    theSocket->cleanUp();
    delete theSocket;
  }
}
  
void
DebuggerClientImpl::accept()
{
  theListener = new DebuggerListener(this);
  theSocket = theServerSocket.accept();
  theInStreamBuffer = new SocketStreambuf(*theSocket);
  theOutStreamBuffer = new SocketStreambuf(*theSocket);
  theInStream = new std::istream(theInStreamBuffer);
  theOutStream = new std::ostream(theOutStreamBuffer);
  theListener->start();
}
  
std::size_t
DebuggerClientImpl::status()
{
  std::size_t id = ++theLastId;
  *theOutStream << "status -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::variables()
{
  // we hack the protocol to return all properties if the context ID is -1
  std::size_t id = ++theLastId;
  *theOutStream << "context_get -c -1 -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::feature_get(std::string const& aFeatureName)
{
  std::size_t id = ++theLastId;
  *theOutStream << "feature_get -i " << id << " -n " << aFeatureName << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::feature_set(std::string const &aFeatureName,
                                            std::string const &aValue)
{
  std::size_t id = ++theLastId;
  *theOutStream << "feature_set -i " << id << " -n " << aFeatureName << " -v "
              << aValue << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::run()
{
  std::size_t id = ++theLastId;
  *theOutStream << "run -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::step_into()
{
  std::size_t id = ++theLastId;
  *theOutStream << "step_into -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::step_over()
{
  std::size_t id = ++theLastId;
  *theOutStream << "step_over -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::step_out()
{
  std::size_t id = ++theLastId;
  *theOutStream << "step_out -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::stop(bool withQuit)
{
  std::size_t id = ++theLastId;
  *theOutStream << "stop -i " << id;
  if (!withQuit) {
    *theOutStream << " -z 1";
  }
  *theOutStream << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::detach()
{
  std::size_t id = ++theLastId;
  *theOutStream << "detach -i " << id << '\0';
  theOutStream->flush();
  return id;
}

std::size_t
DebuggerClientImpl::breakpoint_set(
  BreakpointType aType,
  bool aEnabled,
  const std::string& aFilename,
  int aLinenumber,
  const std::string& aFunctionName,
  const std::string& aExceptionName,
  unsigned hit_value,
  HitCondition aCondition,
  bool aIsTemporary,
  const std::string& aExpression)
{
  std::size_t id = ++theLastId;
  *theOutStream << "breakpoint_set -i " << id
              << " -t ";
  switch (aType) {
    case Line:
      *theOutStream << "line";
      break;
    case Call:
      *theOutStream << "call";
      break;
    case Return:
      *theOutStream << "return";
      break;
    case Exception:
      *theOutStream << "exception";
      break;
    case Conditional:
      *theOutStream << "conditional";
      break;
    case Watch:
      *theOutStream << "watch";
      break;
  }
  if (!aEnabled)
    *theOutStream << " -s disabled";
  if (aFilename != "") {
    *theOutStream << " -f \"" << aFilename << "\"";
  }
  if (aLinenumber != -1)
    *theOutStream << " -n " << aLinenumber;
  if (aFunctionName != "")
    *theOutStream << " -m " << aFunctionName;
  if (aExceptionName != "")
    *theOutStream << " -x " << aExceptionName;
  if (hit_value != 0)
    *theOutStream << " -h " << hit_value;
  switch (aCondition) {
    case BiggerEqual:
      break;
    case Equal:
      *theOutStream << " -o == ";
      break;
    case Multiple:
      *theOutStream << " -o % ";
  }
  if (aIsTemporary)
    *theOutStream << " -r 1 ";
  if (aExpression != "")
    *theOutStream << " -- " << aExpression;
  *theOutStream << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::breakpoint_get(std::size_t aBreakpointId)
{
  std::size_t id = ++theLastId;
  *theOutStream << "breakpoint_get -i " << id << " -d " << aBreakpointId << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::breakpoint_update(
  std::size_t aBreakpointId,
  bool aEnabled,
  int aLinenumber,
  unsigned hit_value,
  HitCondition aCondition)
{
  std::size_t id = ++theLastId;
  *theOutStream << "breakpoint_update -i " << id
              << " -d " << aBreakpointId;
  if (aEnabled)
    *theOutStream << " -s disabled";
  if (aLinenumber != -1)
    *theOutStream << " -n " << aLinenumber;
  if (hit_value != 0)
    *theOutStream << " -h " << hit_value;
  switch (aCondition) {
    case BiggerEqual:
      break;
    case Equal:
      *theOutStream << " -o == ";
      break;
    case Multiple:
      *theOutStream << " -o % ";
  }
  *theOutStream << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::breakpoint_remove(std::size_t aBreakpointId)
{
  std::size_t id = ++theLastId;
  *theOutStream << "breakpoint_remove -i " << id << " -d " << aBreakpointId << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::breakpoint_list()
{
  std::size_t id = ++theLastId;
  *theOutStream << "breakpoint_list -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::stack_depth()
{
  std::size_t id = ++theLastId;
  *theOutStream << "stack_depth -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::stack_get(int depth)
{
  std::size_t id = ++theLastId;
  *theOutStream << "stack_get";
  if (depth >= 0) {
    *theOutStream << " -d " << depth;
  }
  *theOutStream << " -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::context_names(int depth)
{
  std::size_t id = ++theLastId;
  *theOutStream << "context_names";
  if (depth >= 0) {
    *theOutStream << " -d " << depth;
  }
  *theOutStream << " -i " << id << '\0';
  theOutStream->flush();
  return id;
}

std::size_t
DebuggerClientImpl::context_get(int depth, int contextId)
{
  std::size_t id = ++theLastId;
  *theOutStream << "context_get";
  if (depth >= 0) {
    *theOutStream << " -d " << depth;
  }
  if (contextId >= 0){
    *theOutStream << " -c " << contextId;
  }
  *theOutStream << " -i " << id << '\0';
  theOutStream->flush();
  return id;
}

std::size_t
DebuggerClientImpl::typemap_get()
{
  std::size_t id = ++theLastId;
  *theOutStream << "typemap_get -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::property_get(
  const std::string& aPropertyLongName,
  int aStackDepth,
  int aContextId,
  std::size_t aMaxDataSize,
  int aDatapage,
  const std::string& aPropertyKey)
{
  std::size_t id = property_x("property_get", aPropertyLongName, aStackDepth, aContextId, aMaxDataSize);
  if (aDatapage >= 0)
    *theOutStream << " -p " << aDatapage;
  if (aPropertyKey != "")
    *theOutStream << " -k " << aPropertyKey;
  *theOutStream << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::property_set(
  const std::string& aPropertyLongName,
  int aStackDepth,
  int aContextId,
  std::size_t aMaxDataSize,
  const std::string& aPropertyAddress)
{
  std::size_t id = property_x("property_set", aPropertyLongName, aStackDepth, aContextId, aMaxDataSize);
  if (aPropertyAddress != "")
    *theOutStream << " -a " << aPropertyAddress;
  *theOutStream << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::property_value(
  const std::string& aPropertyLongName,
  int aStackDepth,
  int aContextId,
  std::size_t aMaxDataSize,
  int aDatapage,
  const std::string& aPropertyKey,
  const std::string& aPropertyAddress)
{
  std::size_t id = property_x("property_get", aPropertyLongName, aStackDepth, aContextId, aMaxDataSize);
  if (aDatapage >= 0)
    *theOutStream << " -p " << aDatapage;
  if (aPropertyKey != "")
    *theOutStream << " -k " << aPropertyKey;
  if (aPropertyAddress != "")
    *theOutStream << " -a " << aPropertyAddress;
  *theOutStream << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::property_x(
  const std::string& aCommand,
  const std::string& aPropertyLongName,
  int aStackDepth,
  int aContextId,
  std::size_t aMaxDataSize)
{
  std::size_t id = ++theLastId;
  *theOutStream << aCommand << " -i " << id << " -n " << aPropertyLongName;
  if (aStackDepth > 0)
    *theOutStream << " -d " << aStackDepth;
  if (aContextId > 0)
    *theOutStream << " -c " << aContextId;
  if (aMaxDataSize > 0)
    *theOutStream << " -m " << aMaxDataSize;
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::source(
  std::string const &aFile,
  unsigned int aBeginLine,
  unsigned int aEndLine)
{
  std::size_t id = ++theLastId;
  *theOutStream << "source -i " << id;
  // enable zorba extensions
  *theOutStream << " -z 1";
  *theOutStream << " -f \"" << aFile << "\"";
  if (aBeginLine)
    *theOutStream << " -b " << aBeginLine;
  if (aEndLine)
    *theOutStream << " -e " << aEndLine;
  *theOutStream << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::stream_option(OutputStream aStream, StreamBehaviour aBehaviour)
{
  std::size_t id = ++theLastId;
  switch (aStream) {
    case Stdout:
      *theOutStream << "stdout";
      break;
    case Stderr:
      *theOutStream << "stderr";
      break;
    case Stdin:
      *theOutStream << "stdin";
      break;
  }
  *theOutStream << " -i " << id << " -c ";
  switch (aBehaviour) {
    case Disable:
      *theOutStream << "0";
      break;
    case CopyData:
      *theOutStream << "1";
      break;
    case Redirection:
      *theOutStream << "2";
      break;
  }
  *theOutStream << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::do_break()
{
  std::size_t id = ++theLastId;
  *theOutStream << "break -i " << id << '\0';
  theOutStream->flush();
  return id;
}
  
std::size_t
DebuggerClientImpl::eval(std::string const &aExpr)
{
  std::size_t id = ++theLastId;
  *theOutStream << "eval -i " << id << " -- ";
  base64::encode( aExpr, *theOutStream );
  *theOutStream << '\0';
  theOutStream->flush();
  return id;
}
  
void
DebuggerClientImpl::quit()
{
  theListener->stopLooping();
  theListener->join();
}

} // namespace zorba
