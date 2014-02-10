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

// local
#include "zorbacmd_props.h"

///////////////////////////////////////////////////////////////////////////////

ZorbaCmdProperties::ZorbaCmdProperties() {
  as_files_ = true;
  byte_order_mark_ = false;
  compile_only_ = false;
#ifdef ZORBA_WITH_DEBUGGER
  debug_ = false;
  debug_host_ = "127.0.0.1";
  debug_port_ = 28028;
#endif /* ZORBA_WITH_DEBUGGER */
  indent_ = false;
  jsoniq_ = false;
  lib_module_ = false;
  load_plan_ = false;
  multiple_ = 1;
  no_logo_ = false;
  no_serializer_ = false;
  omit_xml_declaration_ = false;
  optimization_level_ = 1;
  parse_only_ = false;
  print_errors_as_xml_ = false;
  print_query_ = false;
  save_plan_ = false;
  serialize_html_ = false;
  serialize_only_query_ = false;
  serialize_plan_ = false;
  serialize_text_ = false;
  timeout_ = -1;
  timing_ = false;
  trailing_nl_ = false;
}

ZorbaCmdProperties& ZorbaCmdProperties::instance() {
  static ZorbaCmdProperties instance;
  return instance;
}

///////////////////////////////////////////////////////////////////////////////

/* vim:set et sw=2 ts=2: */
