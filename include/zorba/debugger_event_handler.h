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
#pragma once

#include <string>

namespace zorba {
  class DebuggerEventHandler {
  public:
    /**
     * @brief This method gets called whenever the debugger client
     *        gets a message from the debug engine.
     *
     * When the client gets a message from the debug engine, it reads the
     * message to a string and calls this method. The message is an XML
     * document - so the implementation has to parse this node.
     *
     * @param aMessage The message recieved from the debug engine.
     */
    virtual void parseMessage(const std::string& aMessage) = 0;

    /**
     * @brief Method which gets called if an error occurs.
     *
     * This method gets called if an error occurs. This can be either
     * an error in the client or in the parser.
     *
     * @param errcode The error code.
     * @param msg A UI usable message.
     */
    virtual void error(unsigned int errcode, const std::string& msg) = 0;
  };
}
