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
#ifndef DEBUGGER_DEFAULT_EVENT_HANDLER_H
#define DEBUGGER_DEFAULT_EVENT_HANDLER_H

#include <zorba/debugger_event_handler.h>

namespace zorba{

  class ZORBA_DLL_PUBLIC DefaultDebuggerEventHandler: public DebuggerEventHandler
  {
    public:

      virtual ~DefaultDebuggerEventHandler();

      void started();

      void idle();

      void suspended( QueryLocation & aLocation, SuspendedBy aCause );

      void resumed();

      void terminated();

      virtual void
      evaluated(String &anExpr, std::list<std::pair<String, String> > &aValuesAndTypes);
  
      virtual void
      evaluated(String &anExpr, String &anError);
  };
}//end of namespace
#endif
/* vim:set et sw=2 ts=2: */
