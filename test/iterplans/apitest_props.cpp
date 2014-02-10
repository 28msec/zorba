/*
 * Copyright 2006-2014 The FLWOR Foundation.
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
#include "apitest_props.h"

///////////////////////////////////////////////////////////////////////////////

APITestProperties::APITestProperties() {
  as_file_ = false;
  compile_only_ = false;
  debug_ = false;
  debug_host_ = "127.0.0.1";
  debug_port_ = 28028;
  iter_plan_test_ = false;
  jsoniq_ = false;
  lib_module_ = false;
  load_plan_ = false;
  optimization_level_ = 1;
  parse_only_ = false;
  print_query_ = false;
  serialize_only_query_ = false;
  test_plan_serialization_ = false;
  tz_ = 0;
  use_serializer_ = false;
}

APITestProperties& APITestProperties::instance() {
  static APITestProperties instance;
  return instance;
}

///////////////////////////////////////////////////////////////////////////////

/* vim:set et sw=2 ts=2: */
