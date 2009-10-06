#include "debugger_server_runnable.h"

#include <iostream>
#include "zorba/xquery.h"
#include "zorba/exception.h"
#include "error_printer.h"

namespace zorba {

DebuggerServerRunnable::DebuggerServerRunnable(const XQuery_t& aQuery,
                                               std::ostream&   aOutStream,
                                               unsigned short  aRequestPort,
                                               unsigned short  aEventPort,
                                               const Zorba_SerializerOptions& 
                                                aSerOpts)
  : theQuery(aQuery),
    theOutStream(aOutStream),
    theRequestPort(aRequestPort),
    theEventPort(aEventPort),
    theSerializerOptions(aSerOpts)
{
}

DebuggerServerRunnable::~DebuggerServerRunnable()
{
}

void
DebuggerServerRunnable::run()
{
  try {
    theQuery->debug(theOutStream,
      theSerializerOptions,
      theRequestPort,
      theEventPort);
  } catch (zorba::QueryException& qe) {
    ErrorPrinter::print(qe, std::cerr, false, true);
  } catch (zorba::ZorbaException& ze) {
    std::cerr << ze << std::endl;
  }
}

void
DebuggerServerRunnable::finish()
{
}

} /* namespace zorba */
