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

#ifndef ZORBA_CMD_PROPERTIES_H
#define ZORBA_CMD_PROPERTIES_H

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

struct sctx_opt {
  std::string clark_qname;
  std::string value;
};

typedef std::vector<sctx_opt> sctx_opts;

#ifndef ZORBA_NO_FULL_TEXT
struct ft_mapping {
  std::string uri;
  std::string value;
};

typedef std::vector<ft_mapping> ft_mappings;
#endif /* ZORBA_NO_FULL_TEXT */

struct ZorbaCmdProperties {
  static ZorbaCmdProperties& instance();

  bool          as_files_;
  std::string   base_uri_;
  std::string   boundary_space_;
  bool          byte_order_mark_;
  std::string   classpath_;
  bool          compile_only_;
  std::string   construction_mode_;
  std::string   ctx_item_;
#ifdef ZORBA_WITH_DEBUGGER
  bool          debug_;
  std::string   debug_host_;
  unsigned      debug_port_;
#endif /* ZORBA_WITH_DEBUGGER */
  std::string   default_collation_;
  external_vars external_vars_;
  bool          indent_;
  bool          jsoniq_;
  bool          lib_module_;
  std::string   lib_path_;
  bool          load_plan_;
  std::string   module_path_;
  unsigned long multiple_;
  bool          no_logo_;
  bool          no_serializer_;
  bool          omit_xml_declaration_;
  unsigned      optimization_level_;
  std::string   ordering_mode_;
#ifdef ZORBA_WITH_FILE_ACCESS
  std::string   output_file_;
#endif /* ZORBA_WITH_FILE_ACCESS */
  bool          parse_only_;
  bool          print_errors_as_xml_;
  bool          print_query_;
  bool          save_plan_;
  sctx_opts     sctx_opts_;
  bool          serialize_html_;
  bool          serialize_only_query_;
  bool          serialize_plan_;
  bool          serialize_text_;
#ifndef ZORBA_NO_FULL_TEXT
  ft_mappings   stop_words_mapping_;
  ft_mappings   thesaurus_mapping_;
#endif /* ZORBA_NO_FULL_TEXT */
  long          timeout_;               // unused
  bool          timing_;
  bool          trailing_nl_;
  std::string   uri_path_;

  serialization_params      serialization_params_;
  std::vector<std::string>  queries_or_files_;

private:
  ZorbaCmdProperties();
};

///////////////////////////////////////////////////////////////////////////////

#endif /* ZORBA_CMD_PROPERTIES_H */
/* vim:set et sw=2 ts=2: */
