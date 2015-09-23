/*
 * Copyright 2015 Federico Cavalieri.
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
void sendError(const std::string& aErrorMessage);

#endif
