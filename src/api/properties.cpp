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

// standard
#include <exception>
#include <fstream>
#include <iostream>

// Zorba
#include <zorba/config.h>
#include <zorba/internal/cxx_util.h>
#include <zorba/properties.h>

#include "util/string_util.h"

using namespace std;

namespace zorba { 

///////////////////////////////////////////////////////////////////////////////

Properties::Properties() {
#ifndef NDEBUG
  abort_ = false;
#endif /* NDEBUG */
  owns_debug_stream_ = false;
  collect_profile_ = false;
  debug_stream_.reset( &cout );
  dump_lib_ = false;
  force_gflwor_ = false;
  infer_joins_ = true;
  inline_udf_ = true;
  loop_hoisting_ = true;
  max_udf_call_depth_ = 1024;
  no_copy_optim_ = true;
  no_tree_ids_ = false;
  no_uncalled_iterators_ = false;
  optimization_level_ = 1;
  plan_format_ = PLAN_FORMAT_NONE;
  print_ast_ = false;
  print_intermediate_opt_ = false;
  print_item_flow_ = false;
  print_locations_ = false;
  print_optimized_ = false;
  print_static_types_ = true;
  print_translated_ = false;
  profile_format_ = PROFILE_FORMAT_NONE;
  stable_iterator_ids_ = false;
  trace_codegen_ = false;
#ifndef ZORBA_NO_FULL_TEXT
  trace_fulltext_ = false;
#endif /* ZORBA_NO_FULL_TEXT */
  trace_parsing_ = false;
  trace_scanning_ = false;
  trace_translator_ = false;
  use_indexes_ = true;
  wall_time_threshold_ = 0;
}

Properties::~Properties() {
  if ( !owns_debug_stream_ )
    debug_stream_.release();
}

Properties& Properties::instance() {
  static Properties properties;
  return properties;
}

void Properties::setDebugFile( char const *file ) {
  if ( file && *file )
    setDebugStream( *(new ofstream( file )), true );
  else
    setDebugStream( cout );
}

void Properties::setDebugStream( ostream &os, bool take_ownership ) {
  if ( !owns_debug_stream_ )
    debug_stream_.release();
  if ( take_ownership && (&os == &cout || &os == &cerr) )
    take_ownership = false;
  owns_debug_stream_ = take_ownership;
  debug_stream_.reset( &os );
}

void Properties::setOptimizationLevel( unsigned opt_level ) {
  if ( opt_level > 2 )
    throw invalid_argument(
      BUILD_STRING( opt_level, ": invalid optimization level; must be [0-2]" )
    );
  optimization_level_ = opt_level;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
