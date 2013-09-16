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

#ifndef ZORBA_OPTIONS_H
#define ZORBA_OPTIONS_H
#include <zorba/config.h>

#ifdef __cplusplus
#include <iostream>
#include <string>
#include <utility>                      /* for pair */
#include <vector>
#endif /* __cplusplus */

/*****************************************************************************/

#ifdef __cplusplus
typedef bool Zorba_opt_bool_t;
#else
typedef char Zorba_opt_bool_t;
#endif /* __cplusplus */

/** \brief The optimization level used for optimizing the query. */
typedef enum {
  ZORBA_OPT_LEVEL_O0, /**< Don't use any optimization. */
  ZORBA_OPT_LEVEL_O1,  /**< Use basic optimizations
                           (e.g.\ removing sorting, removing duplicate elimination,
                           or constant folding). */
  ZORBA_OPT_LEVEL_O2  /** Use basic optimizations (like O1) and some
                        * more optimizations (like not to generate an iterator
                        * for inlined functions) - call stacks in case of
                        * an exception are not generated.
                        */
} Zorba_opt_level_t;

/** \brief Set of hints that can be passed to the query compiler.
 *
 * An instance of this class can be passed to the compileQuery function
 * of the Zorba class or the compile function of this class.
 * The members of this class represent hints that are passed to the
 * query compiler. For example, whether optimization of the query
 * should be done (O1) or not (O0).
 *
 * example_6 in file \link simple.cpp \endlink shows an example
 * how CompilerHints can be used.
 */
typedef struct Zorba_CompilerHints 
{
  /** \brief The optimization level that is used */
  Zorba_opt_level_t opt_level;

  /** \brief Treat the query as a library module */
  Zorba_opt_bool_t lib_module;

  /**
   * \brief By default, this flag is set to false. Applications may set it to
   * true if they plan to execute the query only via one of the methods that 
   * serialize the query result.
   */
  Zorba_opt_bool_t for_serialization_only;

#ifdef __cplusplus
  /** \brief Default constructor for CompilerHints which assigns default values to all hints (C++ only).
   *
   * Default values:
   *   - optimization level: O1
   *   - library module: false
   */
  ZORBA_DLL_PUBLIC Zorba_CompilerHints();
#endif /* __cplusplus */
} Zorba_CompilerHints_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** \brief Helper function for C to set default values ComplilerHints struct.
 *
 * \retval Zorba_CompilerHints_t with default member values
 */
ZORBA_DLL_PUBLIC void Zorba_CompilerHints_default(Zorba_CompilerHints_t*);

#ifdef __cplusplus
} // extern "C"
#endif /* __cplusplus */

/*****************************************************************************/

typedef enum 
{
  ZORBA_SERIALIZATION_METHOD_XML,
  ZORBA_SERIALIZATION_METHOD_HTML,
  ZORBA_SERIALIZATION_METHOD_XHTML,
  ZORBA_SERIALIZATION_METHOD_TEXT,
  ZORBA_SERIALIZATION_METHOD_BINARY,
  ZORBA_SERIALIZATION_METHOD_JSON,
  ZORBA_SERIALIZATION_METHOD_JSON_XML_HYBRID
} Zorba_serialization_method_t;

typedef enum 
{
  ZORBA_BYTE_ORDER_MARK_NO,
  ZORBA_BYTE_ORDER_MARK_YES
} Zorba_byte_order_mark_t;

typedef enum 
{
  ZORBA_ESCAPE_URI_ATTRIBUTES_NO,
  ZORBA_ESCAPE_URI_ATTRIBUTES_YES
} Zorba_escape_uri_attributes_t;

typedef enum {
  ZORBA_INCLUDE_CONTENT_TYPE_NO,
  ZORBA_INCLUDE_CONTENT_TYPE_YES
} Zorba_include_content_type_t;

typedef enum {
  ZORBA_INDENT_NO,
  ZORBA_INDENT_YES
} Zorba_indent_t;

typedef enum {
  ZORBA_NORMALIZATION_FORM_NONE,
  ZORBA_NORMALIZATION_FORM_NFC,
  ZORBA_NORMALIZATION_FORM_NFD,
  ZORBA_NORMALIZATION_FORM_NFKC,
  ZORBA_NORMALIZATION_FORM_NFKD,
  ZORBA_NORMALIZATION_FORM_FULLY_normalized
} Zorba_normalization_form_t;

typedef enum {
  ZORBA_OMIT_XML_DECLARATION_NO,
  ZORBA_OMIT_XML_DECLARATION_YES
} Zorba_omit_xml_declaration_t;

typedef enum {
  ZORBA_STANDALONE_NO,
  ZORBA_STANDALONE_YES,
  ZORBA_STANDALONE_OMIT
} Zorba_standalone_t;

typedef enum {
  ZORBA_UNDECLARE_PREFIXES_NO,
  ZORBA_UNDECLARE_PREFIXES_YES
} Zorba_undeclare_prefixes_t;

typedef enum {
  DONT_SAVE_UNUSED_FUNCTIONS,
  SAVE_UNUSED_FUNCTIONS
} Zorba_save_plan_options_t;

typedef enum {
  JSONIQ_EXTENSIONS_NO,
  JSONIQ_EXTENSIONS_YES
} Zorba_jsoniq_extensions_t;

typedef enum {
  JSONIQ_MULTIPLE_ITEMS_NO,
  JSONIQ_MULTIPLE_ITEMS_YES
} Zorba_jsoniq_multiple_items_t;

/*****************************************************************************/

/**
 * Wraps a \c char* to make it a compile-time error to assign to the pointer
 * directly.
 */
typedef struct Zorba_opaque_char_ptr {
  char const *ptr;
#ifdef __cplusplus
  operator char const*() const {
    return ptr;
  }
#endif /* __cplusplus */
} Zorba_opaque_char_ptr_t;

#ifdef __cplusplus
inline std::ostream& operator<<( std::ostream &o,
                                 Zorba_opaque_char_ptr const &p ) {
  return o << p.ptr;
}
#endif /* __cplusplus */

/** \brief Options that configure the serialization process of a query result.
 *         See http://www.w3.org/TR/2005/CR-xslt-xquery-serialization-20051103/.
 *
 * This struct defines options that can be passed to the serialization process
 * of a query result. An instance of this class can be passed to the serialize
 * function.
 *
 * File \link serialization.cpp \endlink contains examples that show how to use
 * the SerializerOptions.
 */
typedef struct ZORBA_DLL_PUBLIC Zorba_SerializerOptions
{
  Zorba_serialization_method_t  ser_method;
  Zorba_byte_order_mark_t       byte_order_mark;
  Zorba_escape_uri_attributes_t escape_uri_attributes;
  Zorba_include_content_type_t  include_content_type;
  Zorba_indent_t                indent;
  Zorba_normalization_form_t    normalization_form;
  Zorba_omit_xml_declaration_t  omit_xml_declaration;
  Zorba_standalone_t            standalone;
  Zorba_undeclare_prefixes_t    undeclare_prefixes;

  // DO NOT DIRECTLY ASSIGN VALUES TO THESE.  Use set().
  Zorba_opaque_char_ptr_t       encoding;
  Zorba_opaque_char_ptr_t       media_type;
  Zorba_opaque_char_ptr_t       doctype_system;
  Zorba_opaque_char_ptr_t       doctype_public;
  Zorba_opaque_char_ptr_t       cdata_section_elements;
  Zorba_opaque_char_ptr_t       item_separator;
  Zorba_opaque_char_ptr_t       version;

  Zorba_jsoniq_multiple_items_t jsoniq_multiple_items;
  Zorba_serialization_method_t  jsoniq_xdm_method;

#ifdef __cplusplus
  typedef std::pair<std::string,std::string> string_pair;

  /**
   * Default constructor that sets default values as follows:
   *  - serialization method: XML
   *  - byte-order-mark: NO
   *  - esacpe-uri-attributes: NO
   *  - include-content-type: NO
   *  - indent: NO
   *  - normalization-form: none
   *  - omit-xml-declaration: NO
   *  - standalone: omit
   *  - undeclare-prefixes: NO
   */
  Zorba_SerializerOptions();

  /**
   * Copy constructor.
   */
  Zorba_SerializerOptions( Zorba_SerializerOptions const& );

  /**
   * Constructs options using multiple serializer option values.
   *
   * @param option_values The option/value pairs to set.
   * @throws err::SEPM0016 if an option/value is invalid.
   */
  Zorba_SerializerOptions( std::vector<string_pair> const &option_values );

  /**
   * Destructor that frees all internal data.
   */
  ~Zorba_SerializerOptions();

  /**
   * Assignment operator.
   */
  Zorba_SerializerOptions& operator=( Zorba_SerializerOptions const& );

  /**
   * Sets a serializer option value.
   *
   * @param option The name of the option to set.
   * @param value The option's new value.
   * @throws err::SEPM0016 if an option/value is invalid.
   */
  void set( char const *option, char const *value );

  /**
   * Sets multiple serializer option values.
   *
   * @param option_values The option/value pairs to set.
   * @throws err::SEPM0016 if an option/value is invalid.
   */
  void set( std::vector<string_pair> const &option_values );
#endif /* __cplusplus */

} Zorba_SerializerOptions_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * Initializes a Zorba_SerializerOptions.  This is needed only in C code; C++
 * code calls the default constructor.
 *
 * @param opts The Zorba_SerializerOptions to be initialized.
 */
ZORBA_DLL_PUBLIC
void Zorba_SerializerOptions_init( Zorba_SerializerOptions_t *opts );

/**
 * Frees all internal data used by a Zorba_SerializerOptions.  This is needed
 * only in C code; C++ code calls the destructor. Note that this does \e not
 * free \a opts itself (which may be on the stack).
 *
 * @param opts The Zorba_SerializerOptions to be freed.
 */
ZORBA_DLL_PUBLIC
void Zorba_SerializerOptions_free( Zorba_SerializerOptions_t *opts );

/**
 * Sets an option in a Zorba_SerializerOptions.
 *
 * @param opts The Zorba_SerializerOptions to affect.
 * @param option The name of the option to be set.
 * @param value The option's new value.
 * @return \c true only if all the arguments were valid; \c false otherwise.
 */
ZORBA_DLL_PUBLIC
Zorba_opt_bool_t Zorba_SerializerOptions_set( Zorba_SerializerOptions_t *opts,
                                              char const *option,
                                              char const *value );

#ifdef __cplusplus
} // extern "C"

inline Zorba_SerializerOptions::Zorba_SerializerOptions() {
  Zorba_SerializerOptions_init( this );
}

inline Zorba_SerializerOptions::
Zorba_SerializerOptions( std::vector<string_pair> const &option_values ) {
  Zorba_SerializerOptions_init( this );
  set( option_values );
}

inline Zorba_SerializerOptions::~Zorba_SerializerOptions() {
  Zorba_SerializerOptions_free( this );
}
#endif /* __cplusplus */

/*****************************************************************************/

#endif /* ZORBA_OPTIONS_H */
/* vim:set et sw=2 ts=2: */
