#ifndef ZORBA_SERVER_SERVER_H_
#define ZORBA_SERVER_SERVER_H_

#define FCGI_CIN_BUFFER_SIZE 1 * 1024 * 1024
char theCinBuffer[FCGI_CIN_BUFFER_SIZE];

int main(void);
void configureSignalHandlers();
void handleConnectionAborted(int aSignal, siginfo_t *aSignalInfo, void *aContext);
void handleShtudown(int aSignal, siginfo_t *aSignalInfo, void *aContext);
void handleInternalError(int aSignal, siginfo_t *aSignalInfo, void *aContext);
void handleException(const std::string& aException);
void processRequest(const zorba::server::RequestHandler& aRequestHandler, const FCGX_Request& aRequest);

#endif
