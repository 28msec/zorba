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
#ifndef ZORBA_ZORBAC_API_H
#define ZORBA_ZORBAC_API_H

#include <stdio.h>
#include <zorba/config.h>
#include <zorba/static_context_consts.h>
#include <zorba/options.h>

typedef struct XQC_Implementation_s XQC_Implementation;

typedef struct XQC_Expression_s XQC_Expression;

typedef struct XQC_StaticContext_s XQC_StaticContext;

typedef struct XQC_DynamicContext_s XQC_DynamicContext;

typedef struct XQC_Sequence_s XQC_Sequence;

typedef struct XQC_OutputStream_s* XQC_OutputStream;
typedef struct XQC_InputStream_s XQC_InputStream;
typedef struct XQC_ErrorHandler_s XQC_ErrorHandler;

// XQC_Error
/**
 * The error enumeration used by all XQC functions to designate error condition.
 * All XQC functions return a value of type ::XQC_Error.
 */
typedef enum {
  XQC_NO_ERROR = 0,          ///< No error.
  XQC_END_OF_SEQUENCE,       ///< The end of the XQC_Sequence has been reached.
  XQC_NO_CURRENT_ITEM,
  XQC_PARSE_ERROR,
  XQC_INVALID_ARGUMENT,
  XQC_NOT_NODE,

  XQC_INTERNAL_ERROR,        ///< An implementation specific error has occurred.
  XQC_NOT_IMPLEMENTED,       ///< The implementation does not implement that function.
  /**
   * The encoding of the query has not been recognized, or is not supported by the
   * implementation. All implementations must support queries in UTF-8.
   */
  XQC_UNRECOGNIZED_ENCODING,

  XQC_STATIC_ERROR,          ///< A static error has occured while preparing the query
  XQC_TYPE_ERROR,            ///< A type error has occured while preparing or executing the query
  XQC_DYNAMIC_ERROR,         ///< A dynamic error has occured while preparing or executing the query
  XQC_SERIALIZATION_ERROR    ///< A serialization error has occured while serializing the output of a query
} XQC_Error;


// XQC_ItemType
typedef enum {
  XQC_EMPTY_TYPE = 0,

  XQC_DOCUMENT_TYPE,
  XQC_ELEMENT_TYPE,
  XQC_ATTRIBUTE_TYPE,
  XQC_TEXT_TYPE,
  XQC_PROCESSING_INSTRUCTION_TYPE,
  XQC_COMMENT_TYPE,
  XQC_NAMESPACE_TYPE,

  XQC_ANY_SIMPLE_TYPE,
  XQC_ANY_URI_TYPE,
  XQC_BASE_64_BINARY_TYPE,
  XQC_BOOLEAN_TYPE,
  XQC_DATE_TYPE,
  XQC_DATE_TIME_TYPE,
  XQC_DAY_TIME_DURATION_TYPE,
  XQC_DECIMAL_TYPE,
  XQC_DOUBLE_TYPE,
  XQC_DURATION_TYPE,
  XQC_FLOAT_TYPE,
  XQC_G_DAY_TYPE,
  XQC_G_MONTH_TYPE,
  XQC_G_MONTH_DAY_TYPE,
  XQC_G_YEAR_TYPE,
  XQC_G_YEAR_MONTH_TYPE,
  XQC_HEX_BINARY_TYPE,
  XQC_NOTATION_TYPE,
  XQC_QNAME_TYPE,
  XQC_STRING_TYPE,
  XQC_TIME_TYPE,
  XQC_UNTYPED_ATOMIC_TYPE,
  XQC_YEAR_MONTH_DURATION_TYPE
	
} XQC_ItemType;


// external functions
typedef void (*external_function_init)(void** user_data, void* global_user_data);

typedef void (*external_function_release)(void* user_data, void* global_user_data);


#ifdef __cplusplus
extern "C" {
#endif

  /**
   * The zorba_implementation function creates a new ::XQC_Implementation object.
   * Thereby, the Zorba processor is initialized.
   * The user is responsible for freeing the object by calling the free() function
   * of the XQC_Implementation struct.
   *
   * \param store A pointer to the store that is being used by the Zorba instance that is created
   *              by this call.
   * \param[out] impl The newly created XQC_Implementation object.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   */
  ZORBA_DLL_PUBLIC XQC_Error
  zorba_implementation(XQC_Implementation **impl, void* store);


  /**
   * The ::XQC_Implementation struct provides factory functions for parsing queries. 
   * An XQC_Implementation object is thread-safe and can be used by multiple threads 
   * of execution at the same time.
   *
   * Creating an XQC_Implementation object can be done using the zorba_implementation function.
   * Once created, the user is responsible for freeing the object by calling
   * the free() function. 
   * The XQC_Implementation object should not be freed before all objects created using it's
   * functions have been freed - doing so causes undefined behaviour.
   */
  struct XQC_Implementation_s 
  {
    /**
     * Creates a static context suitable for use in the parse() and parse_file()
     * functions. The user is responsible for freeing the ::XQC_StaticContext object returned by calling
     * XQC_StaticContext::free().
     *
     * \param implementation The XQC_Implementation that this function pointer is a member of
     * \param[out] context The newly created XQC_StaticContext object.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQP0019_INTERNAL_ERROR
     */
    XQC_Error 
    (*create_context)(XQC_Implementation *impl, XQC_StaticContext **context);

    /**
     * Prepares a query from a string, returning an ::XQC_Expression object. 
     * The user is responsible for freeing the ::XQC_Expression object
     * returned by calling XQC_Expression::free().
     *
     * \param implementation The XQC_Implementation that this function pointer is a member of.
     * \param string The query to prepare as a string.
     * \param context The initial static context for this query, or null to use the default 
     *        static context.
     * \param handler An optional error handler whose <code>error</code> function is called
     *                if preparing the query fails.
     * \param[out] expression The resulting prepared expression.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQP0019_INTERNAL_ERROR
     * \retval An XQuery static or type error (e.g. XPST*, XPTY*)
     */
    XQC_Error 
    (*prepare)(XQC_Implementation* implementation, 
               const char* query_string,
               XQC_StaticContext* context, 
               XQC_Expression** query);

    /**
     * Prepares a query from a FILE pointer, returning an ::XQC_Expression object.
     * The user remains responsible for closing the file after parsing. 
     * The user is responsible for freeing the ::XQC_Expression object returned by
     * calling XQC_Expression::free().
     *
     * \param implementation The XQC_Implementation that this function pointer is a member of.
     * \param file The file containing the query to prepare.
     * \param context The initial static context for this query, or null to use the default 
     *        static context.
     * \param handler An optional error handler whose <code>error</code> function is called
     *                if preparing the query fails.
     * \param[out] expression The resulting prepared expression.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQP0019_INTERNAL_ERROR
     * \retval An XQuery static or type error (e.g. XPST*, XPTY*)
     */
    XQC_Error 
    (*prepare_file)(XQC_Implementation* implementation, 
                    FILE* query_file,
                    XQC_StaticContext* context, 
                    XQC_Expression** query);

    /**
     * Prepares a query from a ::XQC_InputStream, returning an ::XQC_Expression object.
     * The user is responsible for freeing the ::XQC_Expression object returned by
     * calling XQC_Expression::free().
     *
     * \param implementation The XQC_Implementation that this function pointer is a member of.
     * \param stream The input stream returning the query to prepare.
     *               free will be called on the XQC_InputStream after the query has been read.
     * \param context The initial static context for this query, or null to use the default 
     *        static context.
     * \param handler An optional error handler whose <code>error</code> function is called
     *                if preparing the query fails.
     * \param[out] expression The resulting prepared expression.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQP0019_INTERNAL_ERROR
     * \retval An XQuery static or type error (e.g. XPST*, XPTY*)
     */
    XQC_Error
    (*prepare_stream)(XQC_Implementation* implementation, 
                      XQC_InputStream* stream,
                      XQC_StaticContext* context, 
                      XQC_Expression** query);

    /**
     * Called to free the resources associated with the XQC_Implementation.
     * 
     * \param implementation The XQC_Implementation that this function pointer is a member of
     */
    void
    (*free)(XQC_Implementation *implementation);

  };

  /**
   * The ::XQC_Expression struct represents a pre-parsed query, and allows the user to execute 
   * that query any number of times. An ::XQC_Expression object is thread-safe and 
   * can be used by multiple threads of execution at the same time.
   *
   * ::XQC_Expression objects are created by calling the XQC_Implementation::prepare() or 
   * XQC_Implementation::prepare_file() functions. 
   * Once created, the user is responsible for freeing the object by calling the free() function. 
   * The ::XQC_Expression object should be freed before the ::XQC_Implementation object
   * that created it.
   */
  struct XQC_Expression_s 
  {
    /**
     * This function returns the dynamic context that belongs to this query and
     * is used during query execution.
     * The context can be used, for example, to set values of external variables,
     * the default collation, or the current datetime.
     * It is only available if the query has been compiled, otherwise
     * an error is reported. Moreover, the context must not be modified during the
     * execution of a query (i.e. if a ResultIterator is opened).
     * The user is responsible for freeing the ::XQC_DynamicContext object returned by calling
     * XQC_DynamicContext::free().
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQP0019_INTERNAL_ERROR
     */
    XQC_Error
    (*create_context)(XQC_Expression *query, XQC_DynamicContext** context);

    /**
     * Executes the query represented by the XQC_Expression object.
     * An ::XQC_Sequence object is returned which can be used to examine the results 
     * of the query execution. The user is responsible for freeing the
     * ::XQC_Sequence object returned by calling XQC_Sequence::free().
     *
     * \param query The XQC_Expression that this function pointer is a member of.
     * \param[out] sequence The newly created XQC_Sequence object.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQP0019_INTERNAL_ERROR
     * \retval ::API0024_CANNOT_ITERATE_OVER_UPDATE_QUERY
     * \retval An XQuery dynamic or type error (e.g. XPDY*, XPTY*)
     */
    XQC_Error 
    (*execute)(XQC_Expression* query, XQC_DynamicContext* ctx, XQC_Sequence** sequence);

    /**
     * Called to free the resources associated with the XQC_Expression.
     * 
     * \param query The XQC_Expression that this function pointer is a member of.
     */
    void
    (*free)(XQC_Expression* query);

  };

  /**
   * The ::XQC_StaticContext struct provides a way to specify values for the static context of 
   * the query to be prepared. An ::XQC_StaticContext object is not thread-safe - threads should 
   * each use their own instance of a ::XQC_StaticContext object (see create_child_context).
   *
   * ::XQC_StaticContext objects are created by calling the XQC_Implementation::create_context() 
   * function. Once created, the user is responsible for freeing the object by calling
   * the free() function. 
   * The ::XQC_StaticContext object should be freed before the ::XQC_Implementation object that
   * created it.
   */
  struct XQC_StaticContext_s 
  {
    /**
     * Creates a child context of the given static context.
     * A child context contains the same information as it's parent context but
     * it allows the user to override and add information.
     * The user is responsible for freeing the ::XQC_StaticContext object returned by calling
     * XQC_StaticContext::free().
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] child_context The newly created XQC_StaticContext object which is
     *             a child of the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQP0019_INTERNAL_ERROR
     */
    XQC_Error
    (*create_child_context)(XQC_StaticContext *context, XQC_StaticContext **child_context);

    /**
     * Adds a (prefix, uri) pair to the set of statically known namespaces of
     * the given context.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of.
     * \param prefix The prefix of the namespace to add to the given XQC_StaticContext.
     * \param uri    The uri of the namespace to add to the given XQC_StaticContext.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*declare_ns)(XQC_StaticContext *context, const char* prefix, const char* uri);

    /**
     * Returns the namespace uri that belongs to the given prefix.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param prefix The prefix of the namespace to add to the given XQC_StaticContext.
     * \param[out] result_ns The namespace uri of the namespace registered with the given prefix.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*get_ns_by_prefix)(XQC_StaticContext *context, const char* prefix, const char** result_ns);

    /**
     * Sets the value of the default namespace for elements and types.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param uri The uri of the default element and type namespace to set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_default_element_and_type_ns)(XQC_StaticContext *context, const char* uri);

    /**
     * Returns the default namespace for elements and types.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] uri The uri of the default element and type namespace that is set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*get_default_element_and_type_ns)(XQC_StaticContext *context, const char** uri);

    /**
     * Sets the default namespace for functions.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param uri The uri of the default function namespace to set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_default_function_ns)(XQC_StaticContext *context, const char* uri);

    /**
     * Returns the default namespace for functions set in this static context.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] uri The uri of the default function namespace that is set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*get_default_function_ns)(XQC_StaticContext *context, const char** uri);

    /**
     * Add a collation URI.
     * The URI specifies the locale and collation strength of the collation that is added.
     * A valid collation URI must begin with http://www.flworfound.org/collations/.
     * This prefix is followed by a collation strength (i.e. PRIMARY, SECONDARY, TERTIARY,
     * QUATTERNARY, or IDENTICAL) followed by a '/'.
     * After the strength a lower-case two- or three-letter ISO-639 language code must follow.
     * The URI may end with an upper-case two-letter ISO-3166.
     * For example, http://www.flworfound.org/collations/PRIMARY/en/US
     * specifies an english language with US begin the country..
     *
     * Internally, ICU is used for comparing strings. For detailed description see
     * http://www.icu-project.org/apiref/icu4c/classCollator.html
     * and http://www.icu-project.org/apiref/icu4c/classLocale.html
     * 
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param uri The URI of the collation to add.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQST0038
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*add_collation)(XQC_StaticContext *context, const char* uri);

    /** 
     * Set the URI of the default collation.
     * (see http://www.w3.org/TR/xquery/#static_context)
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param uri The URI of the default collation to set
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQST0038
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_default_collation)(XQC_StaticContext *context, const char* uri);

    /** 
     * Get the URI of the default collation. The uri returned is valid
     * as long as the corresponding XQC_StaticContext object is valid.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] uri The URI of the default collation that is currently set in the given context.
     */
    XQC_Error
    (*get_default_collation)(XQC_StaticContext *context, const char** uri);

    /**
     * Sets the XQuery processor's version to either xquery_version_1_0 or xquery_version_1_1.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param mode The xquery_version_t to set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_xquery_version)(XQC_StaticContext* context, xquery_version_t mode );

    /**
     * Returns the XQuery processor's version that is set in the given static context.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] mode The xquery_version_t that is set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error 
    (*get_xquery_version)(XQC_StaticContext* context, xquery_version_t* mode);
 
    /**
     * Sets the XPath 1.0 compatibility mode to either xpath1_0 or xpath2_0.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param mode The xpath1_0compatib_mode_t to set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_xpath1_0_mode)(XQC_StaticContext* context, xpath1_0compatib_mode_t mode );

    /**
     * Returns the XPath 1.0 compatibility that is set in the given static context.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] mode The xpath1_0compatib_mode_t that is set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error 
    (*get_xpath1_0_mode)(XQC_StaticContext* context, xpath1_0compatib_mode_t* mode);

    /**
     * Sets the construction mode to either preserve_cons or strip_cons.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param mode The construction_mode_t to set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_construction_mode)(XQC_StaticContext* context, construction_mode_t mode );

    /**
     * Returns the construction mode that is set in the given static context.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] mode The construction_mode_t that is set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*get_construction_mode)(XQC_StaticContext* context, construction_mode_t* mode);

    /**
     * Sets the ordering mode to either order or unordered.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param mode The ordering_mode_t to set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_ordering_mode)(XQC_StaticContext* context, ordering_mode_t mode );

    /**
     * Returns the ordering mode that is set in the given static context.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] mode The ordering_mode_t that is set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*get_ordering_mode)(XQC_StaticContext* context, ordering_mode_t* mode );

    /**
     * Sets the default order mode for empty sequences to either empty_least or
     * empty_greatest
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param mode The order_empty_mode_t to set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_default_order_empty_sequences)(XQC_StaticContext* context, order_empty_mode_t mode );

    /**
     * Returns the default order mode for empty sequences that is set in the given
     * static context.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] mode The order_empty_mode_t that is set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*get_default_order_empty_sequences)(XQC_StaticContext* context, order_empty_mode_t* mode );

    /**
     * Sets the boundary space policy to either preserve_space or strip_space.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param mode The boundary_space_mode_t to set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error  
    (*set_boundary_space_policy)(XQC_StaticContext* context, boundary_space_mode_t mode);

    /**
     * Returns the boundary space policy that is set in the given static context.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] mode The boundary_space_mode_t that is set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*get_boundary_space_policy)(XQC_StaticContext* context, boundary_space_mode_t* mode );

    /**
     * Sets the copy namespace mode which consists of the preserve and the inherit mode.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param preserve The preserve_mode_t to set in the given context.
     * \param inherit The inherit_mode_t to set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error 
    (*set_copy_ns_mode)(XQC_StaticContext* context,  
                        preserve_mode_t preserve,
                        inherit_mode_t inherit );

    /**
     * Returns the copy namespace mode as a pair consisting of the preserve and the inherit
     * mode.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] preserve The preserve_mode_t that is set in the given context.
     * \param[out] inherit The inherit_mode_t that is set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*get_copy_ns_mode)(XQC_StaticContext* context,
                        preserve_mode_t* aPreserve,
                        inherit_mode_t* aInherit );

    /**
     * Sets the base uri in the given static context.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param base_uri The base uri to set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_base_uri)(XQC_StaticContext* context, const char* base_uri );

    /**
     * Returns the base uri that is set in the given static context.
     * The returned base uri is only valid as long as the corresponding static context
     * is valid.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param[out] base_uri The base uri that is set in the given context.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*get_base_uri)(XQC_StaticContext* context, const char** base_uri);

    XQC_Error (*set_error_handler)(XQC_StaticContext *context, XQC_ErrorHandler *handler);
    XQC_Error (*get_error_handler)(const XQC_StaticContext *context, XQC_ErrorHandler **handler);

    /**
     * Register an external function that can be called within a query.
     * One external function consists of three function parameters, i.e. init, next, and release.
     *
     * \param context The XQC_StaticContext that this function pointer is a member of
     * \param uri The URI of the external function to add.
     * \param localname The localname of the function to add.
     * \param init A callback function pointer that is called once when the external function
     *             is initialized. The init function gets the global_user_data pointer
     *             as parameter.
     * \param release A callback function pointer that is called once when the external function
     *                is deinitialized.
     * \param global_user_data User specific data that is passed to the init function as a parameter.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::API0019_FUNCTION_ALREADY_REGISTERED,
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*register_external_function)(XQC_StaticContext* context, 
                                  const char* uri,
                                  const char* localname,
                                  external_function_init init,
                                  external_function_release release,
                                  void* global_user_data);

    /**
     * Called to free the resources associated with the XQC_StaticContext.
     * 
     * \param context The XQC_StaticContext that this function pointer is a member of
     */
    void
    (*free)(XQC_StaticContext* context);

  };

  /**
   * An object of the type ::XQC_DynamicContext contains the information that is available at the 
   * time the query is executed.  It contains the information that is defined in the %XQuery 
   * specification (see http://www.w3.org/TR/xquery/#eval_context).
   * An instance of this struct can be retrieved by calling the <code>get_dynamic_context</code> function
   * of an ::XQC_Expression object.
   */
  struct XQC_DynamicContext_s 
  {
    /**
     * Sets the context item to the current item of the XQC_Sequence given. The user remains
     * responsible for freeing the XQC_Sequence passed as the value - the XQC_Sequence must
     * not be freed until the XQC_DynamicContext has been freed or it's context item set to
     * a different value.
     *
     * \param context The XQC_DynamicContext that this function pointer is a member of
     * \param value The XQC_Sequence value for the context item, or 0 to remove the existing
     * context item value.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     * \retval ::XQC_NO_CURRENT_ITEM if there is no current item in the value.
     *
     * \todo What happens if the context item value is the wrong type?
     * \todo Do we allow the value to come from another implementation?
     */
    XQC_Error (*set_context_item)(XQC_DynamicContext *context, XQC_Sequence *value);

    /**
     * Sets the external variable to the sequence given.
     *
     * \param context The XQC_DynamicContext that this function pointer is a member of
     * \param qname The qname of the external variable to set
     * \param value The XQC_Sequence value for the variable.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_variable)(XQC_DynamicContext* context, const char* qname, XQC_Sequence* value);

    /**
     * Sets the implicit timezone parameter.
     *
     * \param context The XQC_DynamicContext that this function pointer is a member of
     * \param timezone The implicit timezone to set
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error 
    (*set_implicit_timezone)(XQC_DynamicContext* context, int timezone);

      
    XQC_Error
    (*set_error_handler)(XQC_DynamicContext *context, XQC_ErrorHandler *handler);
    XQC_Error
    (*get_error_handler)(const XQC_DynamicContext *context, XQC_ErrorHandler **handler);

    /** 
     * Defines the value of the default collection that is used when calling the
     * fn:collection function without a parameter.
     *
     * \param context The XQC_DynamicContext that this function pointer is a member of
     * \param collection_uri the URI of the collection used by the fn:collection function.
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_INTERNAL_ERROR
     */
    XQC_Error
    (*set_default_collection)(XQC_DynamicContext* context, const char* collection_uri);

    /**
     * Called to free the resources associated with the XQC_DynamicContext.
     * 
     * \param context The XQC_DynamicContext that this function pointer is a member of
     */
    void
    (*free)(XQC_DynamicContext* context);

  };



  /** 
   * This struct represents an instance of the XQuery 1.0 and XPath 2.0 Data Model (XDM).
   *
   * See http://www.w3.org/TR/xpath-datamodel/.
   */
  struct XQC_Sequence_s 
  {

    /** 
     * Get the next item of the sequence.
     *
     * \param sequence The XQC_Sequence_s that this function pointer is a member of
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQP0019_INTERNAL_ERROR
     * \retval any XQuery type or dynamic error
     */
    XQC_Error
    (*next)(XQC_Sequence* sequence);

    /**
     * Returns an item type enumeration for the type of the current item.
     *
     * \param sequence The XQC_Sequence that this function pointer is a member of
     * \param[out] type the XQC_ItemType of the current item
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_NO_CURRENT_ITEM if there is no current item, either because next()
     *   has not been called yet, or because the end of the sequence has been reached.
     */
    XQC_Error
    (*item_type)(const XQC_Sequence *sequence, XQC_ItemType *type);

    /**
     * The string value is the string that is extracted by calling the fn:string function
     * on the Item (see http://www.w3.org/TR/xpath-functions/#func-string).
     * Note that this function is available for all types of Items.
     *
     * \param item The XQC_Sequence that this function pointer is a member of
     * \param[out] string_value The string-value of the given item.
     *             This string is valid as long as the given item is valid.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQP0019_INTERNAL_ERROR
     * \retval ::XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE
     */
    XQC_Error
    (*string_value)(const XQC_Sequence* sequence, const char** string_value);

    /**
     * Returns the value of the current item in the sequence as an integer - this is equivalent to calling
     * <code>fn:number()</code> (http://www.w3.org/TR/xpath-functions/#func-number) on the current item, and
     * casting the result to an int. This is available for all item types.
     *
     * \param sequence The XQC_Sequence that this function pointer is a member of
     * \param[out] value The value of the current item as an int.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_NO_CURRENT_ITEM if there is no current item, either because next()
     *   has not been called yet, or because the end of the sequence has been reached.
     */
    XQC_Error
    (*integer_value)(const XQC_Sequence *sequence, int *value);

    /**
     * Returns the value of the current item in the sequence as a double - this is equivalent to calling
     * <code>fn:number()</code> (http://www.w3.org/TR/xpath-functions/#func-number) on the current item.
     * This is available for all item types.
     *
     * \param sequence The XQC_Sequence that this function pointer is a member of
     * \param[out] value The value of the current item as a double.
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_NO_CURRENT_ITEM if there is no current item, either because next()
     *   has not been called yet, or because the end of the sequence has been reached.
     */
    XQC_Error
    (*double_value)(const XQC_Sequence *sequence, double *value);

    /**
     * Returns the name for the current node as a (URI, localname) pair.
     *
     * \param sequence The XQC_Sequence that this function pointer is a member of
     * \param[out] uri The URI of the name of the current node. The memory for the string will be valid
     * until a subsequent call to XQC_Sequence::next().
     * \param[out] name The localname of the name of the current node. The memory for the string will be valid
     * until a subsequent call to XQC_Sequence::next().
     *
     * \retval ::XQC_NO_ERROR
     * \retval ::XQC_NO_CURRENT_ITEM if there is no current item, either because next()
     *   has not been called yet, or because the end of the sequence has been reached.
     * \retval ::XQC_NOT_NODE if the current item is not a node.
     */
    XQC_Error
    (*node_name)(const XQC_Sequence *sequence, const char **uri, const char **name);

    /**
     * called to free the resources associated with the xqc_sequence.
     * 
     * \param sequence the XQC_Sequence that this function pointer is a member of
     */
    void
    (*free)(XQC_Sequence* sequence);

  };

  /**
   * The ::XQC_OutputStream struct is designed to be passed to an XQC implementation in order
   * to return streaming data (i.e. the result of a query).
   */
  struct XQC_OutputStream_s
  {
    /**
     * The function is called to provide the streaming result of a query
     * in the buffer provided. 
     *
     * \param stream The XQC_OutputStream that this function pointer is a member of
     * \param buf The buffer that contains the data
     * \param length The length of the contents in the buffer
     */
    void
    (*write)(XQC_OutputStream stream, const char* buf, unsigned int length);

    /**
     * Called to free the resources associated with the XQC_OutputStream.
     * Free is called by the implementation if it finished writing to the stream.
     * 
     * \param stream The XQC_OutputStream that this function pointer is a member of
     *
     */
    void 
    (*free)(XQC_OutputStream stream);

    /**
     * Can be used for user specific purposes.
     */
    void* user_data;
  };

  /**
   * The ::XQC_InputStream struct is designed to be populated by users for the purpose
   * of streaming data into an XQC implementation.
   */
  struct XQC_InputStream_s
  {
    /**
     * The function called to read more of the input (e.g. the query). The function should read
     * the next chunk of input into the buffer provided, returning the length of the
     * data read.
     *
     * \param stream The XQC_InputStream that this function pointer is a member of
     * \param[out] buffer The buffer to read the data into
     * \param length The length of the buffer
     *
     * \return The number of bytes read - this will be less than length if the end of the input is reached
     *         or -1 if an error occured
     *
     */
    int
    (*read)(XQC_InputStream* stream, char* buf, unsigned int length);

    /**
     * Called to free the resources associated with the XQC_InputStream.
     * The free function is called by the implementation if it finished reading from the stream.
     * This allows for lazy evaluation without the user needing to know when reading from the
     * stream has finished.
     * 
     * \param stream The XQC_InputStream that this function pointer is a member of
     *
     */
    void 
    (*free)(XQC_InputStream* stream);

    /**
     * Can be used for user specific purposes.
     */
    void* user_data;
  };

  /**
   * The ::XQC_ErrorHandler struct is designed to be populated by users for the purpose
   * of collecting more detailed error messages from an XQC implementation. An XQC_ErrorHandler
   * can be set for a query using the XQC_Expression::set_error_handler() function.
   *
   * The XQC_ErrorHandler struct has no free() function pointer because the user remains 
   * responsible for freeing the resources associated with this struct.
   */
  struct XQC_ErrorHandler_s {

    /**
     * The function is called when an error occurs. The function receives the components of the
     * error as arguments. When this function returns, the implementation will exit query parsing or
     * execution with the error enumeration value passed as an argument.
     *
     * \param handler The XQC_ErrorHandler that this function pointer is a member of
     * \param error The error as a value of the XQC_Error enum.
     * \param local_name The local name of the error or an empty string if no local_name is given 
     *                   (e.g. for errors not defined in the spec).
     * \param description A detailed description of the error or an empty string if no description is available.
     * \param query_uri The uri of the query causing the error or an empty string if no uri is available for the query.
     * \param line The line number of the query where the error occured.
     * \param components The column number in the line in the query where the error occured.
     */
    void (*error)(XQC_ErrorHandler* handler, 
                  XQC_Error error,
                  const char   *local_name,
                  const char   *description,
                  const char   *query_uri,
                  unsigned int line,
                  unsigned int column);

    /**
     * Can be used for user specific purposes.
     */
    void *user_data;

  };


  /** 
   * \example csimple.c
   *  This is a simple example that demonstrate how to use the Zorba XQuery Engine to
   *  create, compile, and execute queries.
   *
   * \example ccontext.c
   *  This file demonstrates how the item factory can be used to create new items and 
   *  bind the items to external variables in the dynamic context before executing a query.
   *
   * \example cerror.c
   *  This file demonstrates how to use the error callback function when a static, runtime, type, or serialization
   *  error occurs during parsing or executing the query.
   *
   * \example cexternal_functions.c
   *  This file demonstrates how to write an external function.
   *
   * \example cserialization.c
   * This file shows how to use serialize the result of a query. It includes examples that
   * demonstrate how to change serialization parameters or use the XQC_OutputStream to
   * retrieve the query result as a stream.
   */

#ifdef __cplusplus
}
#endif

#endif
