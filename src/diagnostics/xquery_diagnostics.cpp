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

#include "util/stl_util.h"

#include "xquery_diagnostics.h"

namespace zorba {

XQueryDiagnostics::XQueryDiagnostics() {
}

XQueryDiagnostics::~XQueryDiagnostics() {
  ztd::delete_ptr_seq( errors_ );
  clear_warnings();
}

void XQueryDiagnostics::clear_warnings() {
  ztd::delete_ptr_seq( warnings_ );
  warnings_.clear();
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
