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
//#include "stdafx.h"

#include "debugger/socket.h"

#include <sstream>


#if defined WIN32 || defined WINCE
#include <winsock2.h>
  typedef int socklen_t;
  typedef char raw_type;

#ifdef WIN32
static bool initialized = false;
#endif
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#include <cstring>
#include <cstdlib>

  typedef void raw_type;
#endif

#include <errno.h>

#include "zorbautils/lock.h"

namespace zorba {

// Function to fill in address structure given an address and port
static void fillAddr(const std::string &address, unsigned short port, 
                     sockaddr_in &addr) {
  // we have to lock calls to gethostbyname because
  // it's not thread-safe
  static zorba::Lock theLock;
  memset(&addr, 0, sizeof(addr));  // Zero out address structure
  addr.sin_family = AF_INET;       // Internet address

  theLock.rlock();
  hostent *host;  // Resolve name
  if ((host = gethostbyname(address.c_str())) == NULL) {
    // strerror() will not work for gethostbyname() and hstrerror() 
    // is supposedly obsolete
    theLock.unlock();
    throw DebuggerSocketException("Failed to resolve name (gethostbyname())");
  }
  addr.sin_addr.s_addr = *((unsigned long *) host->h_addr_list[0]);

  addr.sin_port = htons(port);     // Assign port in network byte order
  theLock.unlock();
}

// Socket Code

Socket::Socket(int aType, int aProtocol)
{
#ifdef WIN32
  if (!initialized) {
    WORD wVersionRequested;
    WSADATA wsaData;

    wVersionRequested = MAKEWORD(2, 0);              // Request WinSock v2.0
    if (WSAStartup(wVersionRequested, &wsaData) != 0) {  // Load WinSock DLL
      throw DebuggerSocketException("Unable to load WinSock DLL");
    }
    initialized = true;
  }
#endif

  // Make a new socket
  theDescriptor = socket(PF_INET, aType, aProtocol);
  if (theDescriptor == INVALID_SOCKET) {
      throw DebuggerSocketException("Socket creation failed (socket())", true);
  }
}

Socket::Socket(SOCKET aDescriptor)
{
  this->theDescriptor = aDescriptor;
}

Socket::~Socket() {
  close();
}

void
Socket::close() {
#ifdef WIN32
  ::closesocket(theDescriptor);
#else
  ::close(theDescriptor);
#endif
}

std::string Socket::getLocalAddress() {
  sockaddr_in addr;
  unsigned int addr_len = sizeof(addr);

  if (getsockname(theDescriptor, (sockaddr *) &addr, (socklen_t *) &addr_len) < 0) {
    throw DebuggerSocketException("Fetch of local address failed (getsockname())", true);
  }
  return inet_ntoa(addr.sin_addr);
}

unsigned short Socket::getLocalPort() {
  sockaddr_in addr;
  unsigned int addr_len = sizeof(addr);

  if (getsockname(theDescriptor, (sockaddr *) &addr, (socklen_t *) &addr_len) < 0) {
    throw DebuggerSocketException("Fetch of local port failed (getsockname())", true);
  }
  return ntohs(addr.sin_port);
}

void Socket::setLocalPort(unsigned short localPort) {
  // Bind the socket to its port
  sockaddr_in localAddr;
  memset(&localAddr, 0, sizeof(localAddr));
  localAddr.sin_family = AF_INET;
  localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  localAddr.sin_port = htons(localPort);
  int opt = 1;
  setsockopt(theDescriptor, SOL_SOCKET,SO_REUSEADDR, (char *)&opt, (socklen_t)sizeof(opt)); 
  if (bind(theDescriptor, (sockaddr *) &localAddr, sizeof(sockaddr_in)) < 0) {
    std::stringstream lMsg;
    lMsg << "Set of local port failed: " << localPort;
    throw DebuggerSocketException(lMsg.str(), true);
  }
}

void Socket::setLocalAddressAndPort(const std::string &localAddress,
    unsigned short localPort) {
  // Get the address of the requested host
  sockaddr_in localAddr;
  fillAddr(localAddress, localPort, localAddr);
  int opt = 1;
  setsockopt(theDescriptor, SOL_SOCKET,SO_REUSEADDR, (char *)&opt, (socklen_t)sizeof(opt)); 
  if (bind(theDescriptor, (sockaddr *) &localAddr, sizeof(sockaddr_in)) < 0) {
    throw DebuggerSocketException("Set of local address and port failed (bind())", true);
  }
}

void Socket::cleanUp() {
#ifdef WIN32
    if (WSACleanup() != 0) {
      throw DebuggerSocketException("WSACleanup() failed");
    }
#endif
}

unsigned short Socket::resolveService(const std::string &service,
                                      const std::string &protocol) {
  struct servent *serv;        /* Structure containing service information */

  if ((serv = getservbyname(service.c_str(), protocol.c_str())) == NULL)
    return atoi(service.c_str());  /* Service is port number */
  else 
    return ntohs(serv->s_port);    /* Found port (network byte order) by name */
}

// CommunicatingSocket Code

CommunicatingSocket::CommunicatingSocket(int type, int protocol):
  Socket(type, protocol) {
}

CommunicatingSocket::CommunicatingSocket(SOCKET newConnSD) : Socket(newConnSD) {
}

void CommunicatingSocket::connect(const std::string &foreignAddress,
    unsigned short foreignPort) {
  // Get the address of the requested host
  sockaddr_in destAddr;
  fillAddr(foreignAddress, foreignPort, destAddr);

  // Try to connect to the given port
  if (::connect(theDescriptor, (sockaddr *) &destAddr, sizeof(destAddr)) < 0) {
    std::stringstream lMsg;
    lMsg << "Connection @" << foreignAddress << ":" << foreignPort << " failed.";
    throw DebuggerSocketException( lMsg.str(), true);
  }
}

void CommunicatingSocket::send(const void *buffer, int bufferLen) 
{
  if (::send(theDescriptor, (raw_type *) buffer, bufferLen, 0) < 0) {
    throw DebuggerSocketException("Send failed (send())", true);
  }
}

int CommunicatingSocket::recv(void *buffer, int bufferLen) {
  int rtn;
  if ((rtn = ::recv(theDescriptor, (raw_type *) buffer, bufferLen, 0)) < 0) {
    throw DebuggerSocketException("Received failed (recv())", true);
  }
  
  return rtn;
}

std::string CommunicatingSocket::getForeignAddress() {
  sockaddr_in addr;
  unsigned int addr_len = sizeof(addr);

  if (getpeername(theDescriptor, (sockaddr *) &addr,(socklen_t *) &addr_len) < 0) {
    throw DebuggerSocketException("Fetch of foreign address failed (getpeername())", true);
  }
  return inet_ntoa(addr.sin_addr);
}

unsigned short CommunicatingSocket::getForeignPort() {
  sockaddr_in addr;
  unsigned int addr_len = sizeof(addr);

  if (getpeername(theDescriptor, (sockaddr *) &addr, (socklen_t *) &addr_len) < 0) {
    throw DebuggerSocketException("Fetch of foreign port failed (getpeername())", true);
  }
  return ntohs(addr.sin_port);
}

// TCPSocket Code

TCPSocket::TCPSocket(): CommunicatingSocket(SOCK_STREAM, IPPROTO_TCP) {
}

TCPSocket::TCPSocket(const std::string &foreignAddress, unsigned short foreignPort): CommunicatingSocket(SOCK_STREAM, IPPROTO_TCP) {
  connect(foreignAddress, foreignPort);
}

TCPSocket::TCPSocket(SOCKET newConnSD) : CommunicatingSocket(newConnSD) {
}

// TCPServerSocket Code

TCPServerSocket::TCPServerSocket(unsigned short localPort, int queueLen): Socket(SOCK_STREAM, IPPROTO_TCP) {
  setLocalPort(localPort);
  setListen(queueLen);
}

TCPServerSocket::TCPServerSocket(const std::string &localAddress, 
    unsigned short localPort, int queueLen): Socket(SOCK_STREAM, IPPROTO_TCP) {
  setLocalAddressAndPort(localAddress, localPort);
  setListen(queueLen);
}

TCPSocket *TCPServerSocket::accept() {
  SOCKET newConnSD = ::accept(theDescriptor, NULL, 0);
  if (newConnSD == INVALID_SOCKET) {
    throw DebuggerSocketException("Accept failed (accept())", true);
  }

  return new TCPSocket(newConnSD);
}

void TCPServerSocket::setListen(int queueLen) {
  if (listen(theDescriptor, queueLen) < 0) {
    throw DebuggerSocketException("Set listening socket failed (listen())", true);
  }
}

}//end of namespace
