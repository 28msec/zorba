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

#ifndef ZORBA_APITEST_PROPERTIES_H
#define ZORBA_APITEST_PROPERTIES_H

// standard
#include <string>
#include <vector>
#include <utility>                      /* for pair */

// Zorba
#include <zorba/config.h>

///////////////////////////////////////////////////////////////////////////////

struct external_var {
  std::string var_name;
  std::string var_value;
  bool        inline_file;

  external_var() : inline_file( false ) { }
};

typedef std::vector<external_var> external_vars;

typedef std::pair<std::string,std::string> serialization_param;
typedef std::vector<serialization_param> serialization_params;

struct APITestProperties {
  static APITestProperties& instance();

  bool          as_file_;
  bool          compile_only_;
#ifdef ZORBA_WITH_DEBUGGER
  bool          debug_;
  std::string   debug_host_;
  unsigned      debug_port_;
#endif /* ZORBA_WITH_DEBUGGER */
  std::string   dot_plan_file_;
  external_vars external_vars_;
  bool          iter_plan_test_;        // unused
  bool          jsoniq_;
  bool          lib_module_;
  std::string   lib_path_;
  bool          load_plan_;
  unsigned      optimization_level_;
#ifdef ZORBA_WITH_FILE_ACCESS
  std::string   output_file_;
#endif /* ZORBA_WITH_FILE_ACCESS */
  bool          parse_only_;
  bool          print_query_;
  std::string   query_;
  bool          serialize_only_query_;
  bool          test_plan_serialization_;
  int           tz_;
  bool          use_serializer_;

  serialization_params serialization_params_;

private:
  APITestProperties();
};

///////////////////////////////////////////////////////////////////////////////

#endif /* ZORBA_APITEST_PROPERTIES_H */
/* vim:set et sw=2 ts=2: */
