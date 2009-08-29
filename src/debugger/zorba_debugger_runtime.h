#ifndef ZORBA_DEBUGGER_RUNTIME
#define ZORBA_DEBUGGER_RUNTIME

#include "common/shared_types.h"

#include "zorbautils/runnable.h"

#include "zorbatypes/rchandle.h"
#include "zorbautils/lock.h"

#include "compiler/parser/query_loc.h"

#include "debugger/debugger_common.h"

#include <ostream>
#include <set>

struct Zorba_SerializerOptions;
typedef struct Zorba_SerializerOptions Zorba_SerializerOptions_t;

namespace zorba {
  class XQueryImpl;
  class AbstractCommandMessage;
  class DebuggerCommunicator;
  class ZorbaDebugIterator;
  class ReplyMessage;

  class ZorbaDebuggerRuntime : public Runnable {
  public: // Creation and destruction

    //************************************
    // Method:    ZorbaDebuggerRuntime
    // FullName:  zorba::ZorbaDebuggerRuntime::ZorbaDebuggerRuntime
    // Access:    public 
    // Qualifier: creates an instance of the debugger runtime.
    // Parameter: XQueryImpl * xqueryImpl
    // Parameter: std::ostream & oStream
    // Parameter: DebuggerCommunicator * communicator
    //************************************
    ZorbaDebuggerRuntime(
      XQueryImpl* xqueryImpl,
      std::ostream& oStream,
      const Zorba_SerializerOptions_t*  serializerOptions,
      DebuggerCommunicator* communicator);
    virtual ~ZorbaDebuggerRuntime();
  public:
    //************************************
    // Method:    run
    // FullName:  zorba::ZorbaDebuggerRuntime::run
    // Access:    public 
    // Returns:   void
    // Qualifier: This method starts the query in the new thread and waits
    //            for instructions from the client.
    //************************************
    void run();
    void finish();
  public: // Commands to the runtime
    //************************************
    // Method:    processMessage
    // FullName:  zorba::ZorbaDebuggerRuntime::processMessage
    // Access:    public 
    // Returns:   bool - true if the runtime has to be terminated - false otherwise
    // Qualifier: Reads a message and processes the command of it
    //            inside the runtime thread.
    // Parameter: AbstractCommandMessage * message
    //************************************
    bool processMessage(AbstractCommandMessage* message);
    //************************************
    // Method:    setQueryRunning
    // FullName:  zorba::ZorbaDebuggerRuntime::setQueryRunning
    // Access:    public 
    // Returns:   void
    // Qualifier: This sets the execution status from RESUMED to RUNNING.
    //            This method is used by the server to indicate, that the
    //            resumedEvent was sent to the client.
    //************************************
    void setQueryRunning();
    void setNotSendTerminateEvent();
    void resetRuntime();
  public: // Queries to the runtime
    //************************************
    // Method:    getExecutionStatus
    // FullName:  zorba::ZorbaDebuggerRuntime::getExecutionStatus
    // Access:    public 
    // Returns:   ExecutionStatus
    // Qualifier: Get the execution status of the runtime.
    //************************************
    ExecutionStatus getExecutionStatus() const;
    //************************************
    // Method:    suspend
    // FullName:  zorba::ZorbaDebuggerRuntime::suspend
    // Access:    private 
    // Returns:   void
    // Qualifier:
    // Parameter: QueryLoc & aLocation
    // Parameter: SuspensionCause aCause
    // Descr:     Suspends the runtime and sends a message to the server
    //            with the event.
    //************************************
    void suspendRuntime(QueryLoc aLocation, SuspensionCause aCause);
  private: // Implementation of runtime commands
    //************************************
    // Method:    execCommands
    // FullName:  zorba::ZorbaDebuggerRuntime::execCommands
    // Access:    private 
    // Returns:   bool - true if the runtime has to be terminated
    // Qualifier: This executes a command from the EXECUTION
    //            Type. WARNING: this methos must not be called
    //            from another method then runQuery because of 
    //            Locking!
    //************************************
    bool execCommands();
    //************************************
    // Method:    breakpointCommand
    // FullName:  zorba::ZorbaDebuggerRuntime::breakpointCommand
    // Access:    private 
    // Returns:   void
    // Qualifier: This executes a command from the BREAKPOINTS
    //            Type. WARNING: this methos must not be called
    //            from another method then runQuery because of 
    //            Locking!
    //************************************
    void breakpointCommands();
    //************************************
    // Method:    dynamicCommands
    // FullName:  zorba::ZorbaDebuggerRuntime::dynamicCommands
    // Access:    private 
    // Returns:   void
    // Qualifier:
    //************************************
    void dynamicCommands();
    //************************************
    // Method:    addBreakpoint
    // FullName:  zorba::ZorbaDebuggerRuntime::addBreakpoint
    // Access:    private 
    // Returns:   zorba::QueryLoc
    // Qualifier:
    // Parameter: const QueryLoc & aLocation
    //************************************
    QueryLoc addBreakpoint(const QueryLoc& aLocation);
    //************************************
    // Method:    getAllVariables
    // FullName:  zorba::ZorbaDebuggerRuntime::getAllVariables
    // Access:    private 
    // Returns:   ReplyMessage*
    // Qualifier:
    //************************************
    ReplyMessage* getAllVariables();
    void runQuery();
    void resumeQuery();
    void resumeRuntime();
    void terminateRuntime();

    /**
    * @brief Executes a step command on the runtime.
    *
    * @pre dynamic_cast<StepMessage*>(theCurrentMessage) != NULL
    * @post Sets a breakpoint accoring to the step kind and resumes the
    *  runtime.
    */
    void step();
  private:
    enum NextCommand {
      None,
      RunQuery
    };
  private:
    XQueryImpl*                       theQuery;
    std::ostream&                     theOStream;
    const Zorba_SerializerOptions_t*  theSerializerOptions;
    // Ownership of the communicator is hold by the server
    DebuggerCommunicator*             theCommunicator;
    PlanWrapper_t                     theWrapper;
    ExecutionStatus                   theExecStatus;
    mutable Lock                      theLock;
    AbstractCommandMessage*           theCurrentMessage;
    std::set<ZorbaDebugIterator*>     theBreakpoints;
    bool                              theNotSendTerminateEvent;
  };
}

#endif // ZORBA_DEBUGGER_RUNTIME
