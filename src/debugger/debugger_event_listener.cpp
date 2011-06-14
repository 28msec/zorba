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

#include "debugger_event_listener.h"

#include <memory>

#include "api/unmarshaller.h"

#include "debugger/socket.h"
#include "debugger/debugger_clientimpl.h"
#include "debugger/message_factory.h"
#include "debugger/query_locationimpl.h"

#include "zorbautils/mutex.h"
#include "zorbautils/synchronous_logger.h"

#include "util/ascii_util.h"

namespace zorba {

DebuggerEventListener::DebuggerEventListener(DebuggerClientImpl* aClient)
  : theClient(aClient), theSocket(0), theSocketCloseMutex(0)
{
  theSocketCloseMutex = new Mutex();
}

DebuggerEventListener::~DebuggerEventListener()
{
  delete theSocketCloseMutex;
}

void
DebuggerEventListener::run()
{
  assert(theClient != 0);

  try {
    theSocket = theClient->theEventServerSocket->accept();
    while (theClient->getExecutionStatus() != QUERY_TERMINATED) {
      std::auto_ptr<AbstractMessage> lMessage(MessageFactory::buildMessage(theSocket));
      SuspendedEvent* lSuspendedMsg;
      EvaluatedEvent* lEvaluatedEvent;
      if ((lSuspendedMsg = dynamic_cast<SuspendedEvent*> (lMessage.get()))) {
        theClient->setExecutionStatus(QUERY_SUSPENDED);
        theClient->theRemoteLocation  = lSuspendedMsg->getLocation();
        if (theClient->theEventHandler) {
          QueryLocationImpl loc(lSuspendedMsg->getLocation());
          theClient->theEventHandler->suspended(loc, (SuspendedBy)lSuspendedMsg->getCause());
        }
      } else if (dynamic_cast<StartedEvent*> (lMessage.get())) {
        theClient->setExecutionStatus(QUERY_RUNNING);
        if (theClient->theEventHandler) {
          theClient->theEventHandler->started();
        }
      } else if (dynamic_cast<ResumedEvent*> (lMessage.get())) {
        theClient->setExecutionStatus(QUERY_RUNNING);
        if (theClient->theEventHandler) {
          theClient->theEventHandler->resumed();
        }
      } else if (dynamic_cast<TerminatedEvent*> (lMessage.get())) {
        if (theClient->getExecutionStatus() != QUERY_IDLE) {
          theClient->setExecutionStatus(QUERY_TERMINATED);
          if (theClient->theEventHandler) {
            theClient->theEventHandler->terminated();
          }
        }
        break;
      } else if ((lEvaluatedEvent = dynamic_cast<EvaluatedEvent*>(lMessage.get()))) {
        if (theClient->theEventHandler) {
          String lExpr( Unmarshaller::newString( lEvaluatedEvent->getExpr() ) );
          String lError( Unmarshaller::newString( lEvaluatedEvent->getError() ) );
          if (lError.length() > 0) {
            theClient->theEventHandler->evaluated(lExpr, lError);
          } else {
            std::list< std::pair<String, String> > lValuesAndTypes;
            std::list< std::pair<zstring, zstring> > lMap = lEvaluatedEvent->getValuesAndTypes();
            std::list< std::pair<zstring, zstring> >::const_iterator it;
            for (it=lMap.begin(); it!=lMap.end(); ++it) {
              zstring temp(it->first);
              ascii::replace_all( temp, "&quot;", "\"" );
              String lResult( Unmarshaller::newString( temp ) );
              String lType( Unmarshaller::newString( it->second ) );
              lValuesAndTypes.push_back(std::make_pair(lResult, lType));
            }
            theClient->theEventHandler->evaluated(lExpr, lValuesAndTypes);
          }
        }
      }
    }
  } catch(std::exception const&) {
    //do nothing...
  }
}

void
DebuggerEventListener::finish()
{
  theSocketCloseMutex->lock();
  delete theSocket;
  theSocketCloseMutex->unlock();
}

void
DebuggerEventListener::closeSocket()
{
  theSocketCloseMutex->lock();
  if (theSocket) {
    theSocket->close();
  }
  theSocketCloseMutex->unlock();
}


} //end of namespace
/* vim:set et sw=2 ts=2: */
