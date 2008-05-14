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

#include <cassert>
#include <iostream>

#include <boost/thread/thread.hpp>

#include "debugger/socket.h"

using namespace zorba;
using namespace std;

const unsigned int RCVBUFSIZE = 32;

void server();
void client();

/**
 * Send the message "hello" to the send
 * and ensure that the exact same string is
 * send from the server
 */
int test_debugger_socket( int argc, char* argv[] )
{
  boost::thread thrd1 ( &server );
  boost::thread thrd2 ( &client );
  thrd1.join();
  thrd2.join();
  return 0;
}

void client()
{
	  try {
	    // Establish connection with the echo server
	    TCPSocket sock("127.0.0.1", 9000);
	  
	    // Send the string to the echo server
	    sock.send("Hello", 7);
	    //sock.send("Bar:Foo", 7);	  
	    char echoBuffer[RCVBUFSIZE + 1];    // Buffer for echo string + \0
	    int bytesReceived = 0;              // Bytes read on each recv()
	    int totalBytesReceived = 0;         // Total bytes read
	    // Receive the same string back from the server
	    cout << "Received: ";               // Setup to print the echoed string
	    while (totalBytesReceived < 7) {
	      // Receive up to the buffer size bytes from the sender
	      if ((bytesReceived = (sock.recv(echoBuffer, RCVBUFSIZE))) <= 0) {
	        cerr << "Unable to read";
	      }
	      totalBytesReceived += bytesReceived;     // Keep tally of total bytes
	      echoBuffer[bytesReceived] = '\0';        // Terminate the string!
	      cout << echoBuffer;                      // Print the echo buffer
	    }
	    cout << endl;
	    assert(strcmp(echoBuffer, "Hello") == 0);

	  } catch(SocketException &e) {
	    cerr << e.what() << endl;
      assert( false );
	  }
}

void server()
{
  try {
    TCPServerSocket servSock( 9000 );     // Server Socket object
  
    //while ( true )
    //{
    	TCPSocket *sock = servSock.accept();       // Wait for a client to connect
      cout << "Handling client ";
      try {
        cout << sock->getForeignAddress() << ":";
      } catch (SocketException e) {
        cerr << "Unable to get foreign address" << endl;
      }
      try {
        cout << sock->getForeignPort();
      } catch (SocketException e) {
        cerr << "Unable to get foreign port" << endl;
      }
      cout << endl;

      // Send received string and receive again until the end of transmission
      char echoBuffer[RCVBUFSIZE];
      int recvMsgSize;
      while ((recvMsgSize = sock->recv(echoBuffer, RCVBUFSIZE)) > 0) { // Zero means
                                                             // end of transmission
        // Echo message back to client
        sock->send(echoBuffer, recvMsgSize);
      }
      delete sock;
    //}
  } catch (SocketException &e) {
    cerr << e.what() << endl;
    assert( false );
  }
}
