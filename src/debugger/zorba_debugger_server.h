#ifndef ZORBA_DEBUGGER_SERVER
#define ZORBA_DEBUGGER_SERVER

#include "debugger/debugger_common.h"

#include <ostream>

struct Zorba_SerializerOptions;
typedef struct Zorba_SerializerOptions Zorba_SerializerOptions_t;

namespace zorba {
  class XQueryImpl;
  class DebuggerCommunicator;
  class ZorbaDebuggerRuntime;

  class ZorbaDebuggerServer {
  public: // Creation and destruction
    //************************************
    // Method:    ZorbaDebuggerServer
    // FullName:  zorba::ZorbaDebuggerServer::ZorbaDebuggerServer
    // Access:    public 
    // Qualifier: This constructor creates a new server
    //            Object.
    // Parameter: XQueryImpl * aQuery is a Pointer to a valid XQuery
    //            object which will be executed by the server.
    // Parameter: std::ostream & anOstream is the output stream to which
    //            to which the results of the query will be serialized.
    // Parameter: unsigned short requestPort is the port where the server
    //            listens for new requests from the client (like run,
    //            break, next ...)
    // Parameter: unsigned short eventPort is the port on which the client
    //            gets informed, when an event occurred (like terminated,
    //            suspended...)
    //************************************
    ZorbaDebuggerServer(XQueryImpl* aQuery,
                        Zorba_SerializerOptions& serializerOption,
                        std::ostream& anOstream,
                        unsigned short requestPort = 8000,
                        unsigned short eventPort = 9000);
    virtual ~ZorbaDebuggerServer();
  public:
    //************************************
    // Method:    run
    // FullName:  zorba::ZorbaDebuggerServer::run
    // Access:    public 
    // Returns:   void
    // Qualifier: This method is called when the thread starts (as documented in
    //            zorba::Runnable), makes a handshake and waits for
    //            commands from the client.
    //************************************
    virtual void
    run();
  private:
    unsigned short                    theRequestPort;
    unsigned short                    theEventPort;
    DebuggerCommunicator*             theCommunicator;
    ZorbaDebuggerRuntime*             theRuntime;
  };
}

#endif

