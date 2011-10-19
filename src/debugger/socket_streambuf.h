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
#ifndef ZORBA_SOCKET_STREAMBUF_H
#define ZORBA_SOCKET_STREAMBUF_H

#include <libxml/parser.h>
#include <libxml/xmlstring.h>

#include "socket.h"

namespace zorba {
  
class SocketStreambuf : public std::streambuf {
  public:
    SocketStreambuf(TCPSocket& aSocket);
    virtual ~SocketStreambuf();

  protected:
    virtual int sync();
    virtual int underflow();
    virtual int overflow(int c = EOF);

  private:
    TCPSocket& theSocket;
    char_type* theInputBuffer;
    char_type* theOutputBuffer;
};
  
class DebuggerResponse {
  friend class DebuggerClientImpl;

  private:
    DebuggerResponse(std::istream& aStream);

  public: // API
    bool isInit() const;

  private:
    xmlDocPtr theDoc;
};

} // namespace zorba

#endif // ZORBA_SOCKET_STREAMBUF_H
