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
#include <zorba/base64.h>
#include "debugger/debugger_clientimpl.h"
#include "debugger/socket_streambuf.h"

namespace zorba {
  
  DebuggerClient::~DebuggerClient()
  {}
  
  DebuggerClient* DebuggerClient::createDebuggerClient(DebuggerEventHandler* aHandler,
                                       unsigned short aPort,
                                       const std::string& aHost)
  {
    return new DebuggerClientImpl(aHost, aPort, aHandler);
  }
  
  DebuggerListener::DebuggerListener(DebuggerClientImpl* aClient)
  : theClient(aClient), theStopLooping(false)
  {
  }
  
  void DebuggerListener::run()
  {
    while (!theStopLooping) {
      std::string str;
      std::getline(*(theClient->theStream), str, '\0');
#ifndef NDEBUG
      std::stringstream lStr(str);
      std::size_t length;
      lStr >> length;
#endif
      // we are not interested in the length, but only in the init
      // message
      std::getline(*(theClient->theStream), str, '\0');
#ifndef NDEBUG
      assert(str.size() == length);
#endif
      theClient->theHandler->parseMessage(str);
      this->sleep_(1000);
    }
  }
  
  void DebuggerListener::finish()
  {
  }
  
  void DebuggerListener::stopLooping()
  {
    theStopLooping = true;
  }
  
  DebuggerClientImpl::DebuggerClientImpl(const std::string& aHost,
                                         unsigned short aPort,
                                         DebuggerEventHandler* aHandler)
  : theServerSocket(aHost, aPort), theSocket(0), theStreamBuffer(0), theStream(0),
  theHandler(aHandler), theListener(this), theLastId(0)
  {
  }
  
  void DebuggerClientImpl::accept() {
    theSocket = theServerSocket.accept();
    theStreamBuffer = new socket_streambuf(*theSocket);
    theStream = new std::iostream(theStreamBuffer);
    theListener.start();
  }
  
  std::size_t DebuggerClientImpl::status()
  {
    std::size_t id = ++theLastId;
    *theStream << "status -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::feature_get(std::string const& aFeatureName)
  {
    std::size_t id = ++theLastId;
    *theStream << "feature-get -i " << id << " -n " << aFeatureName << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::feature_set(std::string const &aFeatureName,
                                              std::string const &aValue)
  {
    std::size_t id = ++theLastId;
    *theStream << "feature-set -i " << id << " -n " << aFeatureName << " -v "
               << aValue << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::run()
  {
    std::size_t id = ++theLastId;
    *theStream << "run -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::step_into()
  {
    std::size_t id = ++theLastId;
    *theStream << "step_into -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::step_over()
  {
    std::size_t id = ++theLastId;
    *theStream << "step_over -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::step_out()
  {
    std::size_t id = ++theLastId;
    *theStream << "step_out -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::stop()
  {
    std::size_t id = ++theLastId;
    *theStream << "stop -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::detach()
  {
    std::size_t id = ++theLastId;
    *theStream << "detach -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::breakpoint_set(BreakpointType aType,
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
    *theStream << "breakpoint_set -i " << id
               << " -t ";
    switch (aType) {
      case Line:
        *theStream << "line";
        break;
      case Call:
        *theStream << "call";
        break;
      case Return:
        *theStream << "return";
        break;
      case Exception:
        *theStream << "exception";
        break;
      case Conditional:
        *theStream << "conditional";
        break;
      case Watch:
        *theStream << "watch";
        break;
    }
    if (!aEnabled)
      *theStream << " -s disabled";
    if (aFilename != "") {
      *theStream << " -f " << aFilename;
    }
    if (aLinenumber != -1)
      *theStream << " -n " << aLinenumber;
    if (aFunctionName != "")
      *theStream << " -m " << aFunctionName;
    if (aExceptionName != "")
      *theStream << " -x " << aExceptionName;
    if (hit_value != 0)
      *theStream << " -h " << hit_value;
    switch (aCondition) {
      case BiggerEqual:
        break;
      case Equal:
        *theStream << " -o == ";
        break;
      case Multiple:
        *theStream << " -o % ";
    }
    if (aIsTemporary)
      *theStream << " -r 1 ";
    if (aExpression != "")
      *theStream << " -- " << aExpression;
    *theStream << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::breakpoint_get(std::size_t aBreakpointId)
  {
    std::size_t id = ++theLastId;
    *theStream << "breakpoint_get -i " << id << " -d " << aBreakpointId << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::breakpoint_update(std::size_t aBreakpointId,
                                                    bool aEnabled,
                                                    int aLinenumber,
                                                    unsigned hit_value,
                                                    HitCondition aCondition)
  {
    std::size_t id = ++theLastId;
    *theStream << "breakpoint_update -i " << id
               << " -d " << aBreakpointId;
    if (aEnabled)
      *theStream << " -s disabled";
    if (aLinenumber != -1)
      *theStream << " -n " << aLinenumber;
    if (hit_value != 0)
      *theStream << " -h " << hit_value;
    switch (aCondition) {
      case BiggerEqual:
        break;
      case Equal:
        *theStream << " -o == ";
        break;
      case Multiple:
        *theStream << " -o % ";
    }
    *theStream << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::breakpoint_remove(std::size_t aBreakpointId)
  {
    std::size_t id = ++theLastId;
    *theStream << "breakpoint_remove -i " << id << " -d " << aBreakpointId << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::breakpoint_list()
  {
    std::size_t id = ++theLastId;
    *theStream << "breakpoint_list -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::stack_depth()
  {
    std::size_t id = ++theLastId;
    *theStream << "stack_depth -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::stack_get(int depth)
  {
    std::size_t id = ++theLastId;
    *theStream << "stack_depth";
    if (depth > 0)
      *theStream << " -d " << depth;
    *theStream << " -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::context_names(int depth)
  {
    std::size_t id = ++theLastId;
    *theStream << "context_names";
    if (depth > 0)
      *theStream << " -d " << depth;
    *theStream << " -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::context_get(int depth, int contextId)
  {
    std::size_t id = ++theLastId;
    *theStream << "context_get";
    if (depth > 0)
      *theStream << " -d " << depth;
    if (contextId > 0)
      *theStream << " -c " << contextId;
    *theStream << " -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::typemap_get()
  {
    std::size_t id = ++theLastId;
    *theStream << "typemap_get -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::property_get(const std::string& aPropertyLongName,
                                               int aStackDepth,
                                               int aContextId,
                                               std::size_t aMaxDataSize,
                                               int aDatapage,
                                               const std::string& aPropertyKey)
  {
    std::size_t id = property_x("property_get", aPropertyLongName, aStackDepth, aContextId, aMaxDataSize);
    if (aDatapage >= 0)
      *theStream << " -p " << aDatapage;
    if (aPropertyKey != "")
      *theStream << " -k " << aPropertyKey;
    *theStream << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::property_set(const std::string& aPropertyLongName,
                                               int aStackDepth,
                                               int aContextId,
                                               std::size_t aMaxDataSize,
                                               const std::string& aPropertyAddress)
  {
    std::size_t id = property_x("property_set", aPropertyLongName, aStackDepth, aContextId, aMaxDataSize);
    if (aPropertyAddress != "")
      *theStream << " -a " << aPropertyAddress;
    *theStream << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::property_value(const std::string& aPropertyLongName,
                                                 int aStackDepth,
                                                 int aContextId,
                                                 std::size_t aMaxDataSize,
                                                 int aDatapage,
                                                 const std::string& aPropertyKey,
                                                 const std::string& aPropertyAddress)
  {
    std::size_t id = property_x("property_get", aPropertyLongName, aStackDepth, aContextId, aMaxDataSize);
    if (aDatapage >= 0)
      *theStream << " -p " << aDatapage;
    if (aPropertyKey != "")
      *theStream << " -k " << aPropertyKey;
    if (aPropertyAddress != "")
      *theStream << " -a " << aPropertyAddress;
    *theStream << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::property_x(const std::string& aCommand,
                                             const std::string& aPropertyLongName,
                                             int aStackDepth,
                                             int aContextId,
                                             std::size_t aMaxDataSize)
  {
    std::size_t id = ++theLastId;
    *theStream << aCommand << " -i " << id << " -n " << aPropertyLongName;
    if (aStackDepth > 0)
      *theStream << " -d " << aStackDepth;
    if (aContextId > 0)
      *theStream << " -c " << aContextId;
    if (aMaxDataSize > 0)
      *theStream << " -m " << aMaxDataSize;
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::source(std::string const &aFile,
                                         unsigned int aBeginLine,
                                         unsigned int aEndLine)
  {
    std::size_t id = ++theLastId;
    *theStream << "source -i " << id << " -f " << aFile;
    if (aBeginLine)
      *theStream << " -b " << aBeginLine;
    if (aEndLine)
      *theStream << " -e " << aEndLine;
    *theStream << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::stream_option(OutputStream aStream, StreamBehaviour aBehaviour)
  {
    std::size_t id = ++theLastId;
    switch (aStream) {
      case Stdout:
        *theStream << "stdout";
        break;
      case Stderr:
        *theStream << "stderr";
        break;
      case Stdin:
        *theStream << "stdin";
        break;
    }
    *theStream << " -i " << id << " -c ";
    switch (aBehaviour) {
      case Disable:
        *theStream << "0";
        break;
      case CopyData:
        *theStream << "1";
        break;
      case Redirection:
        *theStream << "2";
        break;
    }
    *theStream << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::do_break()
  {
    std::size_t id = ++theLastId;
    *theStream << "break -i " << id << '\0';
    theStream->sync();
    return id;
  }
  
  std::size_t DebuggerClientImpl::eval(std::string const &aExpr)
  {
    std::size_t id = ++theLastId;
    *theStream << "eval -i " << id << " -- " << encoding::Base64::encode(aExpr.c_str()) << '\0';
    theStream->sync();
    return id;
  }
  
  void DebuggerClientImpl::quit() {
    theListener.stopLooping();
    theListener.join();
  }
  
  
  
  DebuggerClientImpl::~DebuggerClientImpl()
  {
    if (theListener.status() == DebuggerListener::RUNNING) {
      theListener.stopLooping();
      theListener.join();
    }
    if (theSocket) {
      theSocket->close();
      theSocket->cleanUp();
      delete theSocket;
    }
    if (theStream) {
      theStream->sync();
      delete theStream;
      delete theStreamBuffer;
    }
  }
}
