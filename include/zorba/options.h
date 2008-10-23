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

#include <vector>
#include <zorba/zorbastring.h>

/** \brief The optimization level used for optimizing the query. */
typedef enum {
  ZORBA_OPT_LEVEL_O0, /**< Don't use any optimization. */
  ZORBA_OPT_LEVEL_O1  /**< Use basic optimizations 
                           (e.g.\ removing sorting, removing duplicate elimination, 
                           or constant folding). */
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
typedef struct Zorba_CompilerHints {
  /** \brief The optimization level that is used */
  Zorba_opt_level_t opt_level;
#ifdef __cplusplus
  /** \brief Default constructor for CompilerHints which assigns default values to all hints (C++ only).
   *
   * Default values:
   *   - optimization level: O1 
   */
  Zorba_CompilerHints();
#endif
} Zorba_CompilerHints_t;

typedef enum {
  ZORBA_SERIALIZATION_METHOD_XML, 
  ZORBA_SERIALIZATION_METHOD_HTML,
  ZORBA_SERIALIZATION_METHOD_XHTML,
  ZORBA_SERIALIZATION_METHOD_TEXT
} Zorba_serialization_method_t;

typedef enum {
  ZORBA_BYTE_ORDER_MARK_YES, 
  ZORBA_BYTE_ORDER_MARK_NO
} Zorba_byte_order_mark_t;

typedef enum {
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

/** \brief Options that configure the serialization process of a query result.
*         See http://www.w3.org/TR/2005/CR-xslt-xquery-serialization-20051103/.
*
* This struct defines options that can be passed to the serialization process of a query
* result. An instance of this class can be passed to the serialize function.
*
* File \link serialization.cpp \endlink contains examples that show how to use
* the SerializerOptions.
*/
typedef struct Zorba_SerializerOptions {
  Zorba_serialization_method_t  ser_method;
  Zorba_byte_order_mark_t       byte_order_mark;
  Zorba_escape_uri_attributes_t escape_uri_attributes;
  Zorba_include_content_type_t  include_content_type;
  Zorba_indent_t                indent;
  Zorba_normalization_form_t    normalization_form;
  Zorba_omit_xml_declaration_t  omit_xml_declaration;
  Zorba_standalone_t            standalone; 
  Zorba_undeclare_prefixes_t    undeclare_prefixes;
  zorba::String                 doctype_system;
  zorba::String                 doctype_public;

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
#ifdef __cplusplus
  Zorba_SerializerOptions();
#endif
} Zorba_SerializerOptions_t;

/** \brief Helper function to create a Zorba_SerializerOptions from a vector of key / value 
 *         string pairs 
 *
 * \retval The created Zorba_SerializerOptions structure
 */
Zorba_SerializerOptions SerializerOptionsFromStringParams(const std::vector<std::pair<std::string,std::string> >& params);

#ifdef __cplusplus
extern "C" {
#endif

/** \brief Helper function for C to create a Zorba_CompilerHints_t struct 
 *         because of missing default constructor. 
 *
 * \retval Zorba_CompilerHints_t with default member values 
 */
Zorba_CompilerHints_t Zorba_CompilerHints_default();

/** \brief Helper function for C to create a Zorba_SerializerOptions_t struct 
 *         because of missing default constructor. 
 *
 * \retval Zorba_CompilerHints_t with default member values 
 */
Zorba_SerializerOptions_t Zorba_SerializerOptions_default();

#ifdef __cplusplus
}
#endif

#endif

