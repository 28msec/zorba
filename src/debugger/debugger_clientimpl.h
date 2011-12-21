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
#ifndef ZORBA_DEBUGGER_CLIENTIMPL_H
#define ZORBA_DEBUGGER_CLIENTIMPL_H

#include <string>
#include <zorba/debugger_client.h>
#include "debugger/socket.h"
#include "zorbautils/runnable.h"

namespace zorba {
  class SocketStreambuf;
  class DebuggerEventHandler;
  class DebuggerListener;
  class DebuggerClientImpl;

  class DebuggerListener : public Runnable {
  public:
    DebuggerListener(DebuggerClientImpl* aClient);
  public:
    virtual void run();
    virtual void finish();
    void stopLooping();
  private:
    DebuggerClientImpl* theClient;
    bool theStopLooping;
  };
  
  class DebuggerClientImpl : public DebuggerClient {
    friend class DebuggerListener;
  public:
    DebuggerClientImpl(const std::string& aHost,
                       unsigned short aPort,
                       DebuggerEventHandler* aHandler);
    ~DebuggerClientImpl();
  public: // API
    virtual void accept();
    virtual std::size_t status();
    virtual std::size_t variables();
    virtual std::size_t feature_get(const std::string& aFeatureName);
    virtual std::size_t feature_set(const std::string& aFeatureName,
                                    const std::string& aValue);
    virtual std::size_t run();
    virtual std::size_t step_into();
    virtual std::size_t step_out();
    virtual std::size_t step_over();
    virtual std::size_t stop();
    virtual std::size_t detach();
    virtual std::size_t breakpoint_set(BreakpointType aType,
                                       bool aEnabled = true,
                                       const std::string& aFilename = "",
                                       int aLinenumber = -1,
                                       const std::string& aFunctionName = "",
                                       const std::string& aExceptionName = "",
                                       unsigned hit_value = 0,
                                       HitCondition aCondition = BiggerEqual,
                                       bool aIsTemporary = false,
                                       const std::string& aExpression = "");
    virtual std::size_t breakpoint_get(std::size_t aBreakpointId);
    virtual std::size_t breakpoint_update(std::size_t aBreakpointId,
                                       bool aEnabled = true,
                                       int aLinenumber = -1,
                                       unsigned hit_value = 0,
                                       HitCondition aCondition = BiggerEqual);
    virtual std::size_t breakpoint_remove(std::size_t aBreakpointId);
    virtual std::size_t breakpoint_list();
    virtual std::size_t stack_depth();
    virtual std::size_t stack_get(int depth = -1);
    virtual std::size_t context_names(int depth = -1);
    virtual std::size_t context_get(int depth = -1, int contextId = -1);
    virtual std::size_t typemap_get();
    virtual std::size_t property_get(const std::string& aPropertyLongName,
                                     int aStackDepth = -1,
                                     int aContextId = -1,
                                     std::size_t aMaxDataSize = 0,
                                     int aDatapage = -1,
                                     const std::string& aPropertyKey = "");
    virtual std::size_t property_set(const std::string& aPropertyLongName,
                                     int aStackDepth = -1,
                                     int aContextId = -1,
                                     std::size_t aMaxDataSize = 0,
                                     const std::string& aPropertyAddress = "");
    virtual std::size_t property_value(const std::string& aPropertyLongName,
                                       int aStackDepth = -1,
                                       int aContextId = -1,
                                       std::size_t aMaxDataSize = 0,
                                       int aDatapage = -1,
                                       const std::string& aPropertyKey = "",
                                       const std::string& aPropertyAddress = "");
    virtual std::size_t source(const std::string& aFile, unsigned aBeginLine = 0, unsigned aEndLine = 0);
    virtual std::size_t stream_option(OutputStream aStream, StreamBehaviour aBehaviour);
    virtual std::size_t do_break();
    virtual std::size_t eval(const std::string& aExpr);
    virtual void quit();
  private:
    std::size_t property_x(const std::string& aCommand,
                           const std::string& aPropertyLongName,
                           int aStackDepth = -1,
                           int aContextId = -1,
                           std::size_t aMaxDataSize = 0);
  private:
    TCPServerSocket       theServerSocket;
    TCPSocket*            theSocket;
    SocketStreambuf*      theInStreamBuffer;
    SocketStreambuf*      theOutStreamBuffer;
    std::istream*         theInStream;
    std::ostream*         theOutStream;
    DebuggerEventHandler* theHandler;
    DebuggerListener*     theListener;
    std::size_t           theLastId;
  };

} // namespace zorba

#endif // ZORBA_DEBUGGER_CLIENTIMPL_H
