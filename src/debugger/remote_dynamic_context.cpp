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

#include <zorba/default_error_handler.h>
#include <zorba/zorba.h>

#include "debugger/remote_dynamic_context.h"
#include "debugger/debugger_clientimpl.h"
#include "debugger/debugger_protocol.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "store/api/item.h"
#include "api/unmarshaller.h"
#include "api/zorbaimpl.h"

namespace zorba {

  RemoteDynamicContext::RemoteDynamicContext(  XQueryImpl * aQuery, ZorbaDebuggerClientImpl * aDebuggerClient ): DynamicContextImpl( aQuery ), theDebuggerClient( aDebuggerClient ){}

  RemoteDynamicContext::~RemoteDynamicContext()
  {
  }

  bool RemoteDynamicContext::setVariable( const String& aQName, const Item& aItem )
  {
    AbstractCommandMessage * lmsg = new VariableMessage( aQName, aItem );
    theDebuggerClient->send( lmsg );
    delete lmsg;
    return true;
  }
}//end of namespace
