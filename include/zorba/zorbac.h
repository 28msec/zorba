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
#include <xqc.h>

typedef struct Zorba_StaticContext_s Zorba_StaticContext;

typedef struct Zorba_OutputStream_s Zorba_OutputStream;

typedef struct Zorba_ErrorHandler_s Zorba_ErrorHandler;


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


  struct Zorba_StaticContext_s {
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
  };

  /**
   * The ::Zorba_OutputStream struct is designed to be passed to an XQC implementation in order
   * to return streaming data (i.e. the result of a query).
   */
  struct Zorba_OutputStream_s
  {
    /**
     * The function is called to provide the streaming result of a query
     * in the buffer provided. 
     *
     * \param stream The Zorba_OutputStream that this function pointer is a member of
     * \param buf The buffer that contains the data
     * \param length The length of the contents in the buffer
     */
    void
    (*write)(Zorba_OutputStream stream, const char* buf, unsigned int length);

    /**
     * Called to free the resources associated with the Zorba_OutputStream.
     * Free is called by the implementation if it finished writing to the stream.
     * 
     * \param stream The Zorba_OutputStream that this function pointer is a member of
     *
     */
    void 
    (*free)(Zorba_OutputStream stream);

    /**
     * Can be used for user specific purposes.
     */
    void* user_data;
  };


  struct Zorba_ErrorHandler_s {

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

#ifdef __cplusplus
}
#endif

#endif
