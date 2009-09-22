#ifndef ZORBA_DEBUGGER_SERVER_RUNNABLE
#define ZORBA_DEBUGGER_SERVER_RUNNABLE

#include <iostream>

#include "zorba/config.h"
#include "zorba/api_shared_types.h"
#include "zorbautils/runnable.h"
#include "zorba/options.h"

namespace zorba {

class DebuggerServerRunnable : public Runnable {

public:
    DebuggerServerRunnable(const XQuery_t& aQuery,
                           std::ostream&   aOutStream,
                           unsigned short  aRequestPort,
                           unsigned short  aEventPort,
                           Zorba_SerializerOptions* aSerializerOptions = 0);
    virtual ~DebuggerServerRunnable();

    virtual void
    run();

    virtual void
    finish();

private:
    XQuery_t       theQuery;
    std::ostream&  theOutStream;
    unsigned short theRequestPort;
    unsigned short theEventPort;
    Zorba_SerializerOptions* theSerializerOptions;

}; /* class DebuggerServerRunnable */

} /* namespace zorba */

#endif
