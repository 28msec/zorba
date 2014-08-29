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
#ifndef ZORBA_PROPERTIES_BASE_H
#define ZORBA_PROPERTIES_BASE_H

// standard
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Zorba
#include <zorba/config.h>
#include <zorba/options.h>
#include <zorba/internal/ztd.h>
#include <zorba/internal/type_traits.h>
#include <zorba/internal/unique_ptr.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * \brief This class provides access to global properties.
 *
 * This class provides access to global properties set for Zorba in environment
 * and configuration file.
 */
class ZORBA_DLL_PUBLIC Properties {
public:
  /**
   * Gets the singleton instance.
   *
   * @return Returns said instance.
   */
  static Properties& instance();

#ifndef NDEBUG
  /**
   * Gets whether abort(3) will be called when a ZorbaException is thrown.
   * (This is a developer debugging aid.)
   */
  bool getAbort() const {
    return abort_;
  }

  /**
   * Sets whether abort(3) will be called when a ZorbaException is thrown.
   * (This is a developer debugging aid.)
   *
   * @param abort If \c true, call abort(3) when a ZorbaException is thrown.
   */
  void setAbort( bool abort ) {
    abort_ = abort;
  }
#endif /* NDEBUG */

  /**
   * Gets the stream used for additional developer debugging output.
   * (This has nothing to do with the Zorba debugger.)
   *
   * @return Returns said stream; default: standard output.
   */
  std::ostream& getDebugStream() const {
    return *debug_stream_.get();
  }

  /**
   * Sets the file to use for additional developer debugging output.
   * (This has nothing to do with the Zorba debugger.)
   *
   * @param file The path to the file to use.
   */
  void setDebugFile( char const *file );

  /**
   * Sets the file to use for additional developer debugging output.
   * (This has nothing to do with the Zorba debugger.)
   *
   * @tparam StringType The string type.
   * @param file The path to the file to use.
   */
  template<class StringType>
  typename std::enable_if<ZORBA_HAS_C_STR(StringType),void>::type
  setDebugFile( StringType const &file ) {
    setDebugFile( file.c_str() );
  }

  /**
   * Sets the stream to use for additional developer debugging output.
   * (This has nothing to do with the Zorba debugger.)
   *
   * @param stream The stream to use.
   * @param take_ownership If \c true, \a stream will be deleted when Zorba
   * shuts down.
   */
  void setDebugStream( std::ostream &os, bool take_ownership = false );

  bool getDumpLib() const {
    return dump_lib_;
  }

  void setDumpLib( bool b ) {
    dump_lib_ = b;
  }

  bool getForceGFLWOR() const {
    return force_gflwor_;
  }

  void setForceGFLWOR( bool b ) {
    force_gflwor_ = b;
  }

  bool getInferJoins() const {
    return infer_joins_;
  }

  void setInferJoins( bool b ) {
    infer_joins_ = b;
  }

  bool getInlineUDF() const {
    return inline_udf_;
  }

  void setInlineUDF( bool b ) {
    inline_udf_ = b;
  }

  std::string const& getClassPath() const {
    return classpath_;
  }

  void setClassPath( char const *classpath ) {
    classpath_ = classpath;
  }

  template<class StringType>
  typename std::enable_if<ZORBA_HAS_C_STR(StringType),void>::type
  setClassPath( StringType const &classpath ) {
    setClassPath( classpath.c_str() );
  }

  /**
   * \brief Get global JVM classpath property.
   *
   * Before the JVM is started this will return the classpath set by
   * command line option, the CLASSPATH environment variable and in Zorba
   * config file.
   *
   * After the JVM is started this will contain in addition the paths to jars
   * used by modules that make use of the JVM.
   *
   * @deprecated Use getClassPath().
   */
  void getJVMClassPath( std::string &jvmClasspath ) const {
    jvmClasspath = getClassPath();
  }

  /**
   * \brief Set global JVM classpath property.
   *
   * This method should be used to set additional JVM classpath for modules
   * that make use of JVM. This will overide the classpath set by CLASSPATH
   * environment variable or Zorba config file.
   *
   * Once the JVM is started this method doesn't have any effect.
   *
   * @deprecated Use setClassPath().
   */
  void setJVMClassPath( std::string const &jvmClasspath ) {
    setClassPath( jvmClasspath );
  }

  bool getLoopHoisting() const {
    return loop_hoisting_;
  }

  void setLoopHoisting( bool b ) {
    loop_hoisting_ = b;
  }

  uint32_t getMaxUDFCallDepth() const {
    return max_udf_call_depth_;
  }

  void setMaxUDFCallDepth( uint32_t u ) {
    max_udf_call_depth_ = u;
  }

  bool getNoCopyOptim() const {
    return no_copy_optim_;
  }

  void setNoCopyOptim( bool b ) {
    no_copy_optim_ = b;
  }

  bool getNoTreeIDs() const {
    return no_tree_ids_;
  }

  void setNoTreeIDs( bool b ) {
    no_tree_ids_ = b;
  }

  bool getNoUncalledIterators() const {
    return no_uncalled_iterators_;
  }

  void setNoUncalledIterators( bool b ) {
    no_uncalled_iterators_ = b;
  }

  double getWallTimeThreshold() const {
    return wall_time_threshold_;
  }

  void setWallTimeThreshold( double d ) {
    wall_time_threshold_ = d;
  }

  unsigned getOptimizationLevel() const {
    return optimization_level_;
  }

  void setOptimizationLevel( unsigned optimization_level );

  Zorba_plan_format_t getPlanFormat() const {
    return plan_format_;
  }

  void setPlanFormat( Zorba_plan_format_t format ) {
    plan_format_ = format;
  }

  bool getPrintAST() const {
    return print_ast_;
  }

  void setPrintAST( bool b ) {
    print_ast_ = b;
  }

  bool getPrintIntermediateOpt() const {
    return print_intermediate_opt_;
  }

  void setPrintIntermediateOpt( bool b ) {
    print_intermediate_opt_ = b;
  }

  bool getPrintItemFlow() const {
    return print_item_flow_;
  }

  void setPrintItemFlow( bool b ) {
    print_item_flow_ = b ;
  }

  bool getPrintLocations() const {
    return print_locations_;
  }

  void setPrintLocations( bool b ) {
    print_locations_ = b;
  }

  bool getPrintOptimized() const {
    return print_optimized_;
  }

  void setPrintOptimized( bool b ) {
    print_optimized_ = b;
  }

  bool getPrintStaticTypes() const {
    return print_static_types_;
  }

  void setPrintStaticTypes( bool b ) {
    print_static_types_ = b;
  }

  bool getPrintTranslated() const {
    return print_translated_;
  }

  void setPrintTranslated( bool b ) {
    print_translated_ = b;
  }

  bool getCollectProfile() const {
    return collect_profile_;
  }

  void setCollectProfile( bool profile ) {
    collect_profile_ = profile;
    profile_format_ = profile ? profile_format_ : PROFILE_FORMAT_NONE;
  }

  Zorba_profile_format_t getProfileFormat() const {
      return profile_format_;
  }

  void setProfileFormat( Zorba_profile_format_t format ) {
    profile_format_ = format;
    collect_profile_ = format != PROFILE_FORMAT_NONE ? true : collect_profile_;
  }

  bool getStableIteratorIDs() const {
    return stable_iterator_ids_;
  }

  void setStableIteratorIDs( bool b ) {
    stable_iterator_ids_ = b;
  }

  bool getTraceCodegen() const {
    return trace_codegen_;
  }

  void setTraceCodegen( bool b ) {
    trace_codegen_ = b;
  }

#ifndef ZORBA_NO_FULL_TEXT
  bool getTraceFulltext() const {
    return trace_fulltext_;
  }

  void setTraceFulltext( bool b ) {
    trace_fulltext_ = b;
  }
#endif /* ZORBA_NO_FULL_TEXT */

  bool getTraceParsing() const {
    return trace_parsing_;
  }

  void setTraceParsing( bool b ) {
    trace_parsing_ = b;
  }

  bool getTraceScanning() const {
    return trace_scanning_;
  }

  void setTraceScanning( bool b ) {
    trace_scanning_ = b;
  }

  bool getTraceTranslator() const {
    return trace_translator_;
  }

  void setTraceTranslator( bool b ) {
    trace_translator_ = b;
  }

  bool getUseIndexes() const {
    return use_indexes_;
  }

  void setUseIndexes( bool b ) {
    use_indexes_ = b;
  }

private:
  typedef std::unique_ptr<std::ostream> stream_ptr;

  Properties();
  ~Properties();

#ifndef NDEBUG
  bool                   abort_;
#endif /* NDEBUG */
  std::string            classpath_;
  bool                   collect_profile_;
  stream_ptr             debug_stream_;
  bool                   owns_debug_stream_;
  bool                   dump_lib_;
  bool                   force_gflwor_;
  bool                   infer_joins_;
  bool                   inline_udf_;
  bool                   loop_hoisting_;
  uint32_t               max_udf_call_depth_;
  bool                   no_copy_optim_;
  bool                   no_tree_ids_;
  bool                   no_uncalled_iterators_;
  unsigned               optimization_level_;
  Zorba_plan_format_t    plan_format_;
  bool                   print_ast_;
  bool                   print_intermediate_opt_;
  bool                   print_item_flow_;
  bool                   print_locations_;
  bool                   print_optimized_;
  bool                   print_static_types_;
  bool                   print_translated_;
  Zorba_profile_format_t profile_format_;
  bool                   stable_iterator_ids_;
  bool                   trace_codegen_;
#ifndef ZORBA_NO_FULL_TEXT
  bool                   trace_fulltext_;
#endif /* ZORBA_NO_FULL_TEXT */
  bool                   trace_parsing_;
  bool                   trace_scanning_;
  bool                   trace_translator_;
  bool                   use_indexes_;
  double                 wall_time_threshold_;
};

// deprecated name
typedef Properties PropertiesGlobal;

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  // ZORBA_PROPERTIES_BASE_H
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
