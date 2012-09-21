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
#include <vector>
#include <zorba/zorba_string.h>
#endif


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

#if !defined(__cplusplus)
  typedef enum { false = 0, true = 1 } bool;
#endif

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
  bool lib_module;

  /**
   * \brief By default, this flag is set to false. Applications may set it to
   * true if they plan to execute the query only via one of the methods that 
   * serialize the query result.
   */
  bool for_serialization_only;

#ifdef __cplusplus
  /** \brief Default constructor for CompilerHints which assigns default values to all hints (C++ only).
   *
   * Default values:
   *   - optimization level: O1
   *   - library module: false
   */
  ZORBA_DLL_PUBLIC Zorba_CompilerHints();
#endif
} Zorba_CompilerHints_t;


typedef enum 
{
  ZORBA_SERIALIZATION_METHOD_XML,
  ZORBA_SERIALIZATION_METHOD_HTML,
  ZORBA_SERIALIZATION_METHOD_XHTML,
  ZORBA_SERIALIZATION_METHOD_TEXT,
  ZORBA_SERIALIZATION_METHOD_BINARY,
#ifdef ZORBA_WITH_JSON
  ZORBA_SERIALIZATION_METHOD_JSON,
  ZORBA_SERIALIZATION_METHOD_JSONIQ
#endif
} Zorba_serialization_method_t;


typedef enum 
{
  ZORBA_BYTE_ORDER_MARK_YES,
  ZORBA_BYTE_ORDER_MARK_NO
} Zorba_byte_order_mark_t;


typedef enum 
{
  ZORBA_ESCAPE_URI_ATTRIBUTES_YES,
  ZORBA_ESCAPE_URI_ATTRIBUTES_NO
} Zorba_escape_uri_attributes_t;

typedef enum {
  ZORBA_INCLUDE_CONTENT_TYPE_YES,
  ZORBA_INCLUDE_CONTENT_TYPE_NO
} Zorba_include_content_type_t;

typedef enum {
  ZORBA_INDENT_YES,
  ZORBA_INDENT_NO
} Zorba_indent_t;

typedef enum {
  ZORBA_NORMALIZATION_FORM_NFC,
  ZORBA_NORMALIZATION_FORM_NFD,
  ZORBA_NORMALIZATION_FORM_NFKC,
  ZORBA_NORMALIZATION_FORM_NFKD,
  ZORBA_NORMALIZATION_FORM_FULLY_normalized,
  ZORBA_NORMALIZATION_FORM_NONE
} Zorba_normalization_form_t;

typedef enum {
  ZORBA_OMIT_XML_DECLARATION_YES,
  ZORBA_OMIT_XML_DECLARATION_NO
} Zorba_omit_xml_declaration_t;

typedef enum {
  ZORBA_STANDALONE_YES,
  ZORBA_STANDALONE_NO,
  ZORBA_STANDALONE_OMIT
} Zorba_standalone_t;

typedef enum {
  ZORBA_UNDECLARE_PREFIXES_YES,
  ZORBA_UNDECLARE_PREFIXES_NO
} Zorba_undeclare_prefixes_t;

typedef enum {
  ZORBA_ENCODING_UTF8,
  ZORBA_ENCODING_UTF16
} Zorba_encoding_t;

typedef enum {
  ZORBA_USE_BINARY_ARCHIVE,
  ZORBA_USE_XML_ARCHIVE
} Zorba_binary_plan_format_t;

typedef enum {
  DONT_SAVE_UNUSED_FUNCTIONS = 0,
  SAVE_UNUSED_FUNCTIONS = 1
} Zorba_save_plan_options_t;

typedef enum {
  JSONIQ_EXTENSIONS_YES,
  JSONIQ_EXTENSIONS_NO
} Zorba_jsoniq_extensions_t;

typedef enum {
  JSONIQ_MULTIPLE_ITEMS_NO,
  JSONIQ_MULTIPLE_ITEMS_ARRAY,
  JSONIQ_MULTIPLE_ITEMS_APPENDED
} Zorba_jsoniq_multiple_items_t;

typedef enum {
  JSONIQ_ALLOW_MIXED_XDM_JDM_YES,
  JSONIQ_ALLOW_MIXED_XDM_JDM_NO
} Zorba_jsoniq_allow_mixed_xdm_jdm_t;


/** \brief Options that configure the serialization process of a query result.
*         See http://www.w3.org/TR/2005/CR-xslt-xquery-serialization-20051103/.
*
* This struct defines options that can be passed to the serialization process of a query
* result. An instance of this class can be passed to the serialize function.
*
* File \link serialization.cpp \endlink contains examples that show how to use
* the SerializerOptions.
*/
#ifdef __cplusplus
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
  Zorba_encoding_t              encoding;

  zorba::String                 media_type;
  zorba::String                 doctype_system;
  zorba::String                 doctype_public;
  zorba::String                 cdata_section_elements;
  zorba::String                 version;

#ifdef ZORBA_WITH_JSON
  Zorba_jsoniq_extensions_t jsoniq_extensions;
  Zorba_jsoniq_multiple_items_t jsoniq_multiple_items;
  Zorba_serialization_method_t   jsoniq_xdm_method;
  Zorba_jsoniq_allow_mixed_xdm_jdm_t jsoniq_allow_mixed_xdm_jdm;
#endif /* ZORBA_WITH_JSON */

  /** \brief Default constructor for SerializerOptions which assigns default values to all
   *         options (C++ only).
   *
   * Default values:
   *   - serialization method: XML
   *   - byte-order-mark: NO
   *   - esacpe-uri-attributes: NO
   *   - include-content-type: NO
   *   - indent: NO
   *   - normalization-form: none
   *   - omit-xml-declaration: NO
   *   - standalone: omit
   *   - undeclare-prefixes: NO
   */

  Zorba_SerializerOptions();

  /** \brief Helper function to set a serializer parameter value from a key / value string pair.
   *
   *
   * \retval None
   */
  void SetSerializerOption(const char* parameter, const char* value);

  /** \brief Helper function to create a Zorba_SerializerOptions from a vector of key / value
   *         string pairs
   *
   * \retval The created Zorba_SerializerOptions structure
   */
  static Zorba_SerializerOptions SerializerOptionsFromStringParams(const std::vector<std::pair<std::string,std::string> >& params);

} Zorba_SerializerOptions_t;
#endif


#ifndef __cplusplus
struct Zorba_SerializerOptions;
typedef struct Zorba_SerializerOptions Zorba_SerializerOptions_t;
#endif


#ifdef __cplusplus
extern "C" {
#endif

/** \brief Helper function for C to set default values ComplilerHints struct.
 *
 * \retval Zorba_CompilerHints_t with default member values
 */
ZORBA_DLL_PUBLIC void Zorba_CompilerHints_default(Zorba_CompilerHints_t*);

/** \brief Helper function to create a Zorba_SerializerOptions_t struct because
 *         of missing default constructor. C++ code can delete the
 *         returned Zorba_SerializerOptions_t* struct, while C code
 *         must call Zorba_SerializerOptions_free().
 *
 * \retval Zorba_CompilerHints_t with default member values
 */
ZORBA_DLL_PUBLIC Zorba_SerializerOptions_t* Zorba_SerializerOptions_default();

/** \brief Helper function to delete a Zorba_SerializerOptions_t struct
 *
 * \retval Zorba_CompilerHints_t with default member values
 */
ZORBA_DLL_PUBLIC void Zorba_SerializerOptions_free(Zorba_SerializerOptions_t* serializerOptions);

/** \brief Helper function to set an option in a Zorba_SerializerOptions_t structure
 *
 * \param serializerOptions serializer options
 * \param parameter the serializer parameter to be configured
 * \param value the value to which the parameter should be set
 * \retval Zorba_CompilerHints_t with default member values
 */
ZORBA_DLL_PUBLIC void Zorba_SerializerOptions_set(Zorba_SerializerOptions_t* serializerOptions, const char* parameter, const char* value);


#ifdef __cplusplus
}
#endif

#endif

/* vim:set et sw=2 ts=2: */
