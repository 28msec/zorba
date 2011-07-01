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
#include <sstream>
#include <cstring>
#include <iostream>
#include "socket_streambuf.h"

namespace zorba {
  
  static const int BUF_SIZE = 1024;
  
  socket_streambuf::socket_streambuf(TCPSocket& aSocket)
  : theSocket(aSocket)
  {
    theInputBuffer = new char_type[BUF_SIZE];
    theOutputBuffer = new char_type[BUF_SIZE];
    setg(theInputBuffer, theInputBuffer, theInputBuffer);
    setp(theOutputBuffer, theOutputBuffer + BUF_SIZE);
  }
  
  socket_streambuf::~socket_streambuf()
  {
    delete[] theInputBuffer;
  }
  
  int socket_streambuf::sync()
  {
#if 0
    std::cout << "sending:" << std::endl << std::string(pbase(), pptr() - pbase()) << std::endl;
#endif
    theSocket.send(pbase(), pptr() - pbase());
    setp(theOutputBuffer, theOutputBuffer + BUF_SIZE);
    return 0;
  }
  
  int socket_streambuf::underflow() {
    int size = theSocket.recv(theInputBuffer, BUF_SIZE);
    if (size == 0)
      return EOF;
    setg(theInputBuffer, theInputBuffer, theInputBuffer + size);
    return theInputBuffer[0];
  }
  
  int socket_streambuf::overflow(int c)
  {
#if 0
    std::cout << "sending:" << std::endl << std::string(pbase(), pptr() - pbase()) << std::endl;
#endif
    theSocket.send(pbase(), pptr() - pbase());
    setp(theOutputBuffer, theOutputBuffer + BUF_SIZE);
    sputc(c);
    return 0;
  }
  
  DebuggerResponse::DebuggerResponse(std::istream& aStream)
  {
  }
  
  bool DebuggerResponse::isInit() const {
    std::string rootNodeName(reinterpret_cast<const char*>(theDoc->children->name));
    if (rootNodeName == "init")
      return true;
    return false;
  }
}
