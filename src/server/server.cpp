#include <csignal>
#include <sys/signalfd.h>
#include <iostream>
#include <fcgio.h>

#include "debug/quick-debug.h"
#include "request-handler.h"

#include "server.h"

int main(void)
{
  /*
   * Setup signal handlers
   */
  configureSignalHandlers();

  zorba::server::RequestHandler& lRequestHandler =
      zorba::server::RequestHandler::getInstance();

  /*
   *  Backup the stdio streambufs
   */
  std::streambuf * lCinStreambuf  = std::cin.rdbuf();
  std::streambuf * lCoutStreambuf = std::cout.rdbuf();
  std::streambuf * lCerrStreambuf = std::cerr.rdbuf();

  FCGX_Request lRequest;

  FCGX_Init();
  FCGX_InitRequest(&lRequest, 0, 0);

  while (FCGX_Accept_r(&lRequest) == 0)
  {
    try
    {
      processRequest(lRequestHandler, lRequest);
      FCGX_Finish_r(&lRequest);
    }
    catch(const std::exception& e)
    {
      handleException(e.what());
    }
    catch(...)
    {
      handleException("Caught unknown exception");
    }
  }

  /*
   *  Restore the stdio streambufs
   */
  std::cin.rdbuf(lCinStreambuf);
  std::cout.rdbuf(lCoutStreambuf);
  std::cerr.rdbuf(lCerrStreambuf);

  return 0;
}

void processRequest(const zorba::server::RequestHandler& aRequestHandler, const FCGX_Request& aRequest)
{
  fcgi_streambuf lCinFCGIStreambuf(aRequest.in, theCinBuffer, FCGI_CIN_BUFFER_SIZE);
  fcgi_streambuf lCoutFCGIStreambuf(aRequest.out);
  fcgi_streambuf lCerrFCGIStreambuf(aRequest.err);

  std::cin.rdbuf(&lCinFCGIStreambuf);
  std::cout.rdbuf(&lCoutFCGIStreambuf);
  std::cerr.rdbuf(&lCerrFCGIStreambuf);

  aRequestHandler.handleRequest(aRequest);
}

void configureSignalHandlers()
{
  /*
   * SIGPIPE occurs when trying to write/print to a file descriptor
   * that has been closed.  Under mod_fastcgi, if a client aborts a
   * connection before it completes mod_fastcgi does too.  At a minimum,
   * SIGPIPE should be ignored.  Ideally, it should result in an early
   * abort of the request handling within your application and a return
   * to the top of the FastCGI accept() loop.
   */
  struct sigaction lConnectionAborted;
  sigemptyset(&lConnectionAborted.sa_mask);
  lConnectionAborted.sa_flags = SA_SIGINFO;
  lConnectionAborted.sa_sigaction = handleConnectionAborted;
  sigaction(SIGPIPE, &lConnectionAborted, NULL);

  /*
   * USR1 may be received by FastCGI applications spawned by mod_fastcgi.
   * Apache uses this signal to request a "graceful" process shutdown
   * (e.g. its used by "apachectl restart").  When mod_fastcgi's Process
   * Manager receives USR1 it sends TERM to all of the FastCGI applications
   * it spawned and then exits (its gets restarted by Apache).  This means that,
   * under Apache/mod_fastcgi, a FastCGI application that receives USR1 from
   * Apache will also receive TERM from the process manager.
   * FastCGI applications expected to be run under the control of mod_fastcgi/Apache
   * should handle USR1 by finishing any request in process and then shutting down.
   *
   * TERM is the standard signal sent to applications to request shutdown.  Typically,
   * this is considered a request for "clean" shutdown, i.e. finish anything your in
   * the middle of (within reason), free resources such as database connections, and
   * exit.  When Apache receives TERM, it does not finish handling requests in progress.
   * Whether or not you finish any request in process when TERM is received is your decision,
   * but keep in mind that under mod_fastcgi/Apache the TERM may be a "graceful" request in
   * disguise. I always finish any request in process before exiting.
   */
  struct sigaction lShutdown;
  sigemptyset(&lShutdown.sa_mask);
  lShutdown.sa_flags = SA_SIGINFO;
  sigaddset(&lShutdown.sa_mask, SIGUSR1);
  sigaddset(&lShutdown.sa_mask, SIGTERM);
  lShutdown.sa_sigaction = handleShtudown;
  sigaction(SIGUSR1, &lShutdown, NULL);
  sigaction(SIGTERM, &lShutdown, NULL);

  /*
   * Internal error signals.
   * 4  SIGILL  Illegal instruction.
   * 6  SIGABRT The program called the abort() function.
   * 7  SIGBUS  An attempt was made to access memory incorrectly.
   * 8  SIGFPE  A floating point exception happened in the program.
   * 11 SIGSEGV An attempt was made to access memory not allocated to the process.
   */
  struct sigaction lErrorAction;
  lErrorAction.sa_flags = SA_SIGINFO;
  sigemptyset(&lErrorAction.sa_mask);
  sigaddset(&lErrorAction.sa_mask, SIGILL);
  sigaddset(&lErrorAction.sa_mask, SIGABRT);
  sigaddset(&lErrorAction.sa_mask, SIGBUS);
  sigaddset(&lErrorAction.sa_mask, SIGFPE);
  sigaddset(&lErrorAction.sa_mask, SIGSEGV);
  lErrorAction.sa_sigaction = handleInternalError;
  sigaction(SIGILL, &lErrorAction, NULL);
  sigaction(SIGABRT, &lErrorAction, NULL);
  sigaction(SIGBUS, &lErrorAction, NULL);
  sigaction(SIGFPE, &lErrorAction, NULL);
  sigaction(SIGSEGV, &lErrorAction, NULL);
}

void handleConnectionAborted(int aSignal, siginfo_t *aSignalInfo, void *aContext)
{
  DEBUG_SS("Connection aborted");
}

void handleShtudown(int aSignal, siginfo_t *aSignalInfo, void *aContext)
{
  DEBUG_SS("Shutting down");
}

void handleInternalError(int aSignal, siginfo_t *aSignalInfo, void *aContext)
{
  DEBUG_SS("Caught signal " << aSignal);
  exit(aSignal);
}

void handleException(const std::string& aException)
{
  DEBUG_SS("Caught exception " << aException);
  sleep(20);
  exit(2);
}
