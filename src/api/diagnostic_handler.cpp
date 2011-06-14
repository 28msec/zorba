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

#include <iostream>

#include <zorba/diagnostic_handler.h>

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

DiagnosticHandler::~DiagnosticHandler() {
  // out-of-line since it's virtual
}

void DiagnosticHandler::error( ZorbaException const &e ) {
  //
  // Must NOT simply do "throw e".
  // See http://www.parashift.com/c++-faq-lite/exceptions.html#faq-17.16
  //
  e.polymorphic_throw();
}

void DiagnosticHandler::warning( XQueryWarning const &w ) {
  cerr << w << endl;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
