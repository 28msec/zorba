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
#include "stdafx.h"

#include <zorba/debugger_default_event_handler.h>

zorba::DefaultDebuggerEventHandler::~DefaultDebuggerEventHandler()
{
}

void zorba::DefaultDebuggerEventHandler::started()
{
}

void zorba::DefaultDebuggerEventHandler::idle()
{
}

void zorba::DefaultDebuggerEventHandler::resumed()
{
}

void zorba::DefaultDebuggerEventHandler::terminated()
{
}

void zorba::DefaultDebuggerEventHandler::suspended(
  zorba::QueryLocation & aLocation,
  zorba::SuspendedBy aCause)
{
}

void zorba::DefaultDebuggerEventHandler::evaluated(
  zorba::String &anExpr, 
  std::list<std::pair<String,String> > &aValuesAndTypes)
{
}

void zorba::DefaultDebuggerEventHandler::evaluated(zorba::String &anExpr, 
                                                   zorba::String &anError)
{
}
/* vim:set et sw=2 ts=2: */
