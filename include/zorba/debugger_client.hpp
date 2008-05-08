#ifndef XQP_ZORBA_DEBUGGER_CLIENT_H
#define XQP_ZORBA_DEBUGGER_CLIENT_H

#include <zorba/api_shared_types.h>

namespace zorba{

  class ZorbaDebuggerClient{

    public:

      virtual ~ZorbaDebuggerClient(){}

      static ZorbaDebuggerClient *
      createClient( unsigned short aRequestPortno, unsigned short aEventPortno );

      virtual bool
      isQueryRunning() const = 0;

      virtual bool
      isQueryIdle() const = 0;

      virtual bool
      isQuerySuspended() const = 0;

      virtual bool
      isQueryTerminated() const = 0;

      virtual void
      run() = 0;

      virtual void
      suspend() = 0;

      virtual void
      resume() = 0;

      virtual void
      terminate() = 0;

      virtual void
      stepInto() = 0;

      virtual void
      stepOut() = 0;

      virtual void
      stepOver() = 0;

      virtual void
      addBreakpoint( const String & aFileName, const unsigned int aLineNo ) = 0;

      virtual void
      clearBreakpoint( const String & aFileName, const unsigned int aLineNo ) = 0;
  };


}//end of namespace
#endif
