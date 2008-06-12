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
#include <zorba/error.h>
#include <zorba/static_context_consts.h>
#include <zorba/options.h>

typedef struct XQC_Implementation_s* XQC_Implementation;
typedef XQC_Implementation* XQC_Implementation_Ref;

typedef struct XQC_Query_s* XQC_Query;
typedef XQC_Query* XQC_Query_Ref;

typedef struct XQC_StaticContext_s* XQC_StaticContext;
typedef XQC_StaticContext*  XQC_StaticContext_Ref;

typedef struct XQC_DynamicContext_s* XQC_DynamicContext;
typedef XQC_DynamicContext* XQC_DynamicContext_Ref;

typedef struct XQC_Sequence_s* XQC_Sequence;
typedef XQC_Sequence* XQC_Sequence_Ref;

typedef struct XQC_Item_s* XQC_Item;
typedef XQC_Item* XQC_Item_Ref;

typedef struct XQC_ItemFactory_s*  XQC_ItemFactory;
typedef XQC_ItemFactory* XQC_ItemFactory_Ref;

typedef struct XQC_Collection_s*  XQC_Collection;
typedef XQC_Collection* XQC_Collection_Ref;

typedef struct XQC_DataManager_s*  XQC_DataManager;
typedef XQC_DataManager* XQC_DataManager_Ref;

typedef struct XQC_OutputStream_s* XQC_OutputStream;
typedef struct XQC_InputStream_s* XQC_InputStream;
typedef struct XQC_ErrorHandler_s* XQC_ErrorHandler;


// external functions
typedef void (*external_function_init)(void** user_data, void* global_user_data);

typedef XQUERY_ERROR (*external_function_next) (XQC_Sequence args,
                                                int argc,
                                                XQC_Item_Ref result,
                                                void* user_data,
                                                void* global_user_data);

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
XQUERY_ERROR
zorba_implementation(XQC_Implementation_Ref impl, void* store);


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
	XQUERY_ERROR 
  (*create_context)(XQC_Implementation impl, XQC_StaticContext_Ref context);

 /**
  * Prepares a query from a string, returning an ::XQC_Query object. 
  * The user is responsible for freeing the ::XQC_Query object
  * returned by calling XQC_Query::free().
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
	XQUERY_ERROR 
  (*prepare)(XQC_Implementation implementation, 
             const char *query_string,
		         XQC_StaticContext context, 
             XQC_ErrorHandler handler, 
             XQC_Query_Ref query);

  /**
   * Prepares a query from a FILE pointer, returning an ::XQC_Query object.
   * The user remains responsible for closing the file after parsing. 
   * The user is responsible for freeing the ::XQC_Query object returned by
   * calling XQC_Query::free().
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
	XQUERY_ERROR 
  (*prepare_file)(XQC_Implementation implementation, 
                  FILE *query_file,
		              XQC_StaticContext context, 
                  XQC_ErrorHandler handler,
                  XQC_Query_Ref query);

  /**
   * Prepares a query from a ::XQC_InputStream, returning an ::XQC_Query object.
   * The user is responsible for freeing the ::XQC_Query object returned by
   * calling XQC_Query::free().
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
  XQUERY_ERROR
  (*prepare_stream)(XQC_Implementation implementation, 
                    XQC_InputStream stream,
                    XQC_StaticContext context, 
                    XQC_ErrorHandler handler,
                    XQC_Query_Ref query);
 
  /**
   * Creates an item wrapper suitable for use in the ::XQC_Sequence::next function or
   * the ::XQC_ItemFactory::create functions.
   * The user is responsible for freeing the XQC_Item object returned by calling
   * XQC_Item::free().
   *
   * \param implementation The XQC_Implementation that this function pointer is a member of
   * \param[out] item The newly created XQC_Item wrapper object.
   *
	 * \retval ::XQC_NO_ERROR
	 * \retval ::XQP0019_INTERNAL_ERROR
   */
  XQUERY_ERROR
  (*create_item)(XQC_Implementation implementation, XQC_Item_Ref item);

  /**
   * Creates a XQC_ItemFactory that can be used for creating items, i.e. instances of the 
   * XQuery data model (XDM).
   * The user is responsible for freeing the XQC_ItemFactory object returned by calling
   * XQC_ItemFactory::free().
   *
   * \param implementation The XQC_Implementation that this function pointer is a member of
   * \param[out] factory The newly created XQC_ItemFactory  object.
   *
	 * \retval ::XQC_NO_ERROR
	 * \retval ::XQP0019_INTERNAL_ERROR
   */
  XQUERY_ERROR
  (*item_factory)(XQC_Implementation implementation, XQC_ItemFactory_Ref factory);  

  /**
   * Creates a XQC_DataManager that can be used for managing collections and documents.
   * The user is responsible for freeing the XQC_DataManager object returned by calling
   * XQC_DataManager::free().
   *
   * \param implementation The XQC_Implementation that this function pointer is a member of
   * \param[out] data_manager The newly created XQC_DataManager object.
   *
	 * \retval ::XQC_NO_ERROR
	 * \retval ::XQP0019_INTERNAL_ERROR
   */
  XQUERY_ERROR
  (*data_manager)(XQC_Implementation implementation, XQC_DataManager_Ref data_manager);


  /**
   * Called to free the resources associated with the XQC_Implementation.
   * 
   * \param implementation The XQC_Implementation that this function pointer is a member of
   */
  void
  (*free)(XQC_Implementation implementation);

  /**
   * for internal use only
   */
  void* data;
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
struct XQC_Query_s 
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
	XQUERY_ERROR
  (*get_dynamic_context)(XQC_Query query, XQC_DynamicContext_Ref context);

  /**
   * This function returns the static context that belongs to this query.
   * The static context is only available if the query has been compiled, otherwise
   * an error is reported.
   * The context has all the components and values that have been set by the either
   * the static context that was passed when creating the query and and those that
   * were set in the prolog of the query.
   * Note that after compilation of the query the static context is a read only structure.
	 * The user is responsible for freeing the ::XQC_StaticContext object returned by calling
	 * XQC_StaticContext::free().
   *
	 * \retval ::XQC_NO_ERROR
	 * \retval ::XQP0019_INTERNAL_ERROR
   */
  XQUERY_ERROR
  (*get_static_context)(XQC_Query, XQC_StaticContext_Ref context);

 /**
  * Executes the query represented by the XQC_Query object and prints the serialized XML
  * output to the given FILE pointer. The user remains responsible for closing
  * the file.
  *
  * \param query The XQC_Query that this function pointer is a member of.
  * \param file The FILE pointer to print the serialized result to.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQP0019_INTERNAL_ERROR
  * \retval ::API0023_CANNOT_SERIALIZE_UPDATE_QUERY
  * \retval An XQuery dynamic or type error (e.g. XPDY*, XPTY*)
  */
	XQUERY_ERROR 
  (*execute)(XQC_Query query, FILE* file);

 /**
  * Executes the query represented by the XQC_Query object and prints the serialized
  * output to the given FILE pointer. The target format of the serialization is 
  * specified by the passed serializer options.
  *
  * \param query The XQC_Query that this function pointer is a member of.
  * \param options The Zorba_SerializerOptions_t that specifies serializer options.
  * \param file The FILE pointer to print the serialized result to.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQP0019_INTERNAL_ERROR
  * \retval ::API0023_CANNOT_SERIALIZE_UPDATE_QUERY
  * \retval An XQuery dynamic or type error (e.g. XPDY*, XPTY*)
  */
  XQUERY_ERROR
  (*serialize_file)(XQC_Query query, const Zorba_SerializerOptions_t* options, FILE* file); 

 /**
  * Executes the query represented by the XQC_Query object and writes the serialized
  * output to the given ::XQC_OutputStream. The target format of the serialization is 
  * specified by the passed serializer options.
  *
  * \param query The XQC_Query that this function pointer is a member of.
  * \param options The Zorba_SerializerOptions_t that specifies serializer options.
  * \param file The XQC_OutputStream to print the serialized result to.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQP0019_INTERNAL_ERROR
  * \retval ::API0023_CANNOT_SERIALIZE_UPDATE_QUERY
  * \retval An XQuery dynamic or type error (e.g. XPDY*, XPTY*)
  */
  XQUERY_ERROR
  (*serialize_stream)(XQC_Query query, const Zorba_SerializerOptions_t* options, XQC_OutputStream stream); 

 /** 
  * Checks if the query is an updating query.
  *
  * \param query The XQC_Query that this function pionter is a member of.
  *
  * \retval 1 if query is updating query, else 0
  */
  int
  (*is_update_query)(XQC_Query query);

 /**
  * Applies the updates declared in the query represented by the XQC_Query object.
  *
  * \param query The XQC_Query that this function pointer is a member of.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQP0019_INTERNAL_ERROR
  * \retval ::API0023_CANNOT_SERIALIZE_UPDATE_QUERY
  * \retval An XQuery dynamic or type error (e.g. XPDY*, XPTY*)
  */
	XQUERY_ERROR 
  (*apply_updates)(XQC_Query query);

 /**
  * Executes the query represented by the XQC_Query object.
  * An ::XQC_Sequence object is returned which can be used to examine the results 
  * of the query execution. The user is responsible for freeing the
  * ::XQC_Sequence object returned by calling XQC_Sequence::free().
  *
  * \param query The XQC_Query that this function pointer is a member of.
  * \param[out] sequence The newly created XQC_Sequence object.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQP0019_INTERNAL_ERROR
  * \retval ::API0024_CANNOT_ITERATE_OVER_UPDATE_QUERY
  * \retval An XQuery dynamic or type error (e.g. XPDY*, XPTY*)
  */
	XQUERY_ERROR 
  (*sequence)(XQC_Query query, XQC_Sequence_Ref sequence);

  /**
   * Sets the error handler whose <code>error</code> function is called
   * if an error occurs when executing the query.
   * The user keeps the ownership of this object and is required to freeing
   * the aquired resources.
   */
  void
  (*set_error_handler)(XQC_Query query, XQC_ErrorHandler handler);

 /**
  * Called to free the resources associated with the XQC_Query.
  * 
  * \param query The XQC_Query that this function pointer is a member of.
  */
  void
  (*free)(XQC_Query query);

  /**
   * for internal use only
   */
  void* data;
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
  XQUERY_ERROR
  (*create_child_context)(XQC_StaticContext context, XQC_StaticContext_Ref child_context);

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
  XQUERY_ERROR
  (*declare_ns)(XQC_StaticContext context, const char* prefix, const char* uri);

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
  XQUERY_ERROR
  (*get_ns_by_prefix)(XQC_StaticContext context, const char* prefix, const char** result_ns);

  /**
   * Sets the value of the default namespace for elements and types.
   *
	 * \param context The XQC_StaticContext that this function pointer is a member of
   * \param uri The uri of the default element and type namespace to set in the given context.
   *
	 * \retval ::XQC_NO_ERROR
	 * \retval ::XQC_INTERNAL_ERROR
   */
  XQUERY_ERROR
  (*set_default_element_and_type_ns)(XQC_StaticContext context, const char* uri);

 /**
  * Returns the default namespace for elements and types.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param[out] uri The uri of the default element and type namespace that is set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR
  (*get_default_element_and_type_ns)(XQC_StaticContext context, const char** uri);

 /**
  * Sets the default namespace for functions.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param uri The uri of the default function namespace to set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR
  (*set_default_function_ns)(XQC_StaticContext context, const char* uri);

 /**
  * Returns the default namespace for functions set in this static context.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param[out] uri The uri of the default function namespace that is set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR
  (*get_default_function_ns)(XQC_StaticContext context, const char** uri);

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
  XQUERY_ERROR
  (*add_collation)(XQC_StaticContext context, const char* uri);

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
  XQUERY_ERROR
  (*set_default_collation)(XQC_StaticContext context, const char* uri);

  /** 
   * Get the URI of the default collation. The uri returned is valid
   * as long as the corresponding XQC_StaticContext object is valid.
   *
   * \param context The XQC_StaticContext that this function pointer is a member of
   * \param[out] uri The URI of the default collation that is currently set in the given context.
   */
  XQUERY_ERROR
  (*get_default_collation)(XQC_StaticContext context, const char** uri);

 /**
  * Sets the XPath 1.0 compatibility mode to either xpath1_0 or xpath2_0.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param mode The xpath1_0compatib_mode_t to set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR
  (*set_xpath1_0_mode)(XQC_StaticContext context, xpath1_0compatib_mode_t mode );

 /**
  * Returns the XPath 1.0 compatibility that is set in the given static context.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param[out] mode The xpath1_0compatib_mode_t that is set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR 
  (*get_xpath1_0_mode)(XQC_StaticContext context, xpath1_0compatib_mode_t* mode);

 /**
  * Sets the construction mode to either preserve_cons or strip_cons.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param mode The construction_mode_t to set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR
  (*set_construction_mode)(XQC_StaticContext context, construction_mode_t mode );

 /**
  * Returns the construction mode that is set in the given static context.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param[out] mode The construction_mode_t that is set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR
  (*get_construction_mode)(XQC_StaticContext context, construction_mode_t* mode);

 /**
  * Sets the ordering mode to either order or unordered.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param mode The ordering_mode_t to set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR
  (*set_ordering_mode)(XQC_StaticContext context, ordering_mode_t mode );

 /**
  * Returns the ordering mode that is set in the given static context.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param[out] mode The ordering_mode_t that is set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR
  (*get_ordering_mode)(XQC_StaticContext context, ordering_mode_t* mode );

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
  XQUERY_ERROR
  (*set_default_order_empty_sequences)(XQC_StaticContext context, order_empty_mode_t mode );

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
  XQUERY_ERROR
  (*get_default_order_empty_sequences)(XQC_StaticContext context, order_empty_mode_t* mode );

 /**
  * Sets the boundary space policy to either preserve_space or strip_space.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param mode The boundary_space_mode_t to set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR  
  (*set_boundary_space_policy)(XQC_StaticContext context, boundary_space_mode_t mode);

 /**
  * Returns the boundary space policy that is set in the given static context.
  *
  * \param context The XQC_StaticContext that this function pointer is a member of
  * \param[out] mode The boundary_space_mode_t that is set in the given context.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQC_INTERNAL_ERROR
  */
  XQUERY_ERROR
  (*get_boundary_space_policy)(XQC_StaticContext context, boundary_space_mode_t* mode );

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
  XQUERY_ERROR 
  (*set_copy_ns_mode)(XQC_StaticContext context,  
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
  XQUERY_ERROR
  (*get_copy_ns_mode)(XQC_StaticContext context,
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
  XQUERY_ERROR
  (*set_base_uri)(XQC_StaticContext context, const char* base_uri );

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
  XQUERY_ERROR
  (*get_base_uri)(XQC_StaticContext context, const char** base_uri);

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
   * \param next A callback function pointer that is called each time the corresponding
   *             XQuery function is executed. 
   * \param release A callback function pointer that is called once when the external function
   *                is deinitialized.
   * \param global_user_data User specific data that is passed to the init function as a parameter.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::API0019_FUNCTION_ALREADY_REGISTERED,
   * \retval ::XQC_INTERNAL_ERROR
   */
  XQUERY_ERROR
  (*register_external_function)(XQC_StaticContext context, 
                                const char* uri,
                                const char* localname,
                                external_function_init init,
                                external_function_next next,
                                external_function_release release,
                                void* global_user_data);

 /**
  * Called to free the resources associated with the XQC_StaticContext.
  * 
  * \param context The XQC_StaticContext that this function pointer is a member of
  */
  void
  (*free)(XQC_StaticContext context);

  /**
   * for internal use only
   */
  void* data;
};

/**
 * An object of the type ::XQC_DynamicContext contains the information that is available at the 
 * time the query is executed.  It contains the information that is defined in the %XQuery 
 * specification (see http://www.w3.org/TR/xquery/#eval_context).
 * An instance of this struct can be retrieved by calling the <code>get_dynamic_context</code> function
 * of an ::XQC_Query object.
 */
struct XQC_DynamicContext_s 
{
	/**
	 * Sets the context item to the given ::XQC_Item.
	 *
	 * \param context The XQC_DynamicContext that this function pointer is a member of
	 * \param value The XQC_Item for the context item.
	 *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQC_INTERNAL_ERROR
	 */
	XQUERY_ERROR 
  (*set_context_item) (XQC_DynamicContext context, XQC_Item value);

	/**
	 * Sets the context item to the document given by the FILE pointer.
   * The provided document is accessible by the provided doc_uri.
	 *
	 * \param context The XQC_DynamicContext that this function pointer is a member of
	 * \param doc_uri The URI referencing the given document
   * \param document The document to which the context item should be set as a FILE pointer.
	 *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0016_LOADER_IO_ERROR,
   * \retval ::XQP0017_LOADER_PARSING_ERROR, 
   * \retval ::XQC_INTERNAL_ERROR
	 */
  XQUERY_ERROR
  (*set_context_document)(XQC_DynamicContext context, const char* doc_uri, FILE* document);

	/**
	 * Sets the external variable to the value given.
	 *
	 * \param context The XQC_DynamicContext that this function pointer is a member of
	 * \param qname The qname of the external variable to set
   * \param value The XQC_Item value for the variable.
	 *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQC_INTERNAL_ERROR
	 */
  XQUERY_ERROR
  (*set_variable_item)(XQC_DynamicContext context, const char* qname, XQC_Item value);

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
  XQUERY_ERROR
  (*set_variable_sequence)(XQC_DynamicContext context, const char* qname, XQC_Sequence value);

	/**
	 * Sets the external variable to the document given by the FILE pointer.
	 *
	 * \param context The XQC_DynamicContext that this function pointer is a member of
	 * \param var_qname The qname of the external variable to set
	 * \param doc_uri The URI referencing the given document
   * \param document The document to which the context item should be set as a FILE pointer.
	 *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0016_LOADER_IO_ERROR,
   * \retval ::XQP0017_LOADER_PARSING_ERROR, 
   * \retval ::XQC_INTERNAL_ERROR
	 */
  XQUERY_ERROR
  (*set_variable_document)(XQC_DynamicContext context, const char* var_qname, const char* doc_uri, FILE* document);

	/**
   * Sets the implicit timezone parameter.
   *
   * \param context The XQC_DynamicContext that this function pointer is a member of
	 * \param timezone The implicit timezone to set
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQC_INTERNAL_ERROR
	 */
  XQUERY_ERROR 
  (*set_implicit_timezone)(XQC_DynamicContext context, int timezone);

  /** 
   * Defines the value of the default collection that is used when calling the
   * fn:collection function without a parameter.
   *
   * \param context The XQC_DynamicContext that this function pointer is a member of
   * \param collection_uri the URI of the collection used by the fn:collection function.
   * \retval ::XQC_NO_ERROR
   * \retval ::XQC_INTERNAL_ERROR
   */
  XQUERY_ERROR
  (*set_default_collection)(XQC_DynamicContext context, XQC_Item collection_uri);

  /**
   * Called to free the resources associated with the XQC_DynamicContext.
   * 
   * \param context The XQC_DynamicContext that this function pointer is a member of
   */
  void
  (*free)(XQC_DynamicContext context);

  /**
   * for internal use only
   */
  void* data;
};

/**
 * This struct is Zorba's representation of an Item as defined in the
 * XQuery 1.0 and XPath 2.0 Data Model (XDM); see http://www.w3.org/TR/xpath-datamodel/. 
 * 
 * Instances of the XDM are a sequence, i.e. an ordered collection of zero or more items.
 * In the Zorba API, a sequence is represented by the XQC_Sequence struct.
 *
 * The Item class is the union of all XQuery node and atomic types.
 * The class provides functions to access the information of an Item. Note that not
 * all functions are defined on every Item kind. If a function is called on an Item that
 * does not provide the function called, an XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE error
 * is raised.
 *
 * A new atomic Item can be created using the ItemFactory. A new node Item should be created
 * by the result of a query.
 */
struct XQC_Item_s 
{
  /**
   * The string value is the string that is extracted by calling the fn:string function
   * on the Item (see http://www.w3.org/TR/xpath-functions/#func-string).
   * Note that this function is available for all types of Items.
   *
   * \param item The XQC_Item that this function pointer is a member of
   * \param[out] string_value The string-value of the given item.
   *             This string is valid as long as the given item is valid.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE
   */
  XQUERY_ERROR
  (*string_value)(XQC_Item item, const char** string_value);

  /**
   * Get the (optional) value of a QName's prefix.
   * Note that this function is only available for Items of type QName.
   *
   * \param item The XQC_Item that this function pointer is a member of
   * \param[out] prefix The prefix of the given QName item.
   *             This string is valid as long as the given item is valid.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE
   */
  XQUERY_ERROR
  (*prefix)(XQC_Item item, const char** prefix);

  /**
   * Get the (optional) value of a QName's namespace.
   * Note that this function is only available for Items of type QName.
   *
   * \param item The XQC_Item that this function pointer is a member of
   * \param[out] namespace The namespace of the given QName item.
   *             This string is valid as long as the given item is valid.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE
   */
  XQUERY_ERROR
  (*ns)(XQC_Item item, const char** namespace);

  /**
   * Get the value of a QName's localname.
   * Note that this function is only available for Items of type QName.
   *
   * \param item The XQC_Item that this function pointer is a member of
   * \param[out] localname The localname of the given QName item.
   *             This string is valid as long as the given item is valid.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE
   */
  XQUERY_ERROR
  (*localname)(XQC_Item item, const char** local_name);

  /** 
   * Get the bool value of the boolean Item.
   * Note that this function is only available for Items of type boolean.
   *
   * \param item The XQC_Item that this function pointer is a member of
   * \param[out] bool_value 1 if the boolean value of the given item is true, 0 otherwise.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE
   */
  XQUERY_ERROR
  (*boolean_value)(XQC_Item item, int* bool_value);

  /**
   * Check if the value of the Item is not a number (NaN).
   * Note that this function is implemented for all item types but may only return
   * 1 for a numeric item (e.g. Double or Float).
   *
   * \param item The XQC_Item that this function pointer is a member of
   * \param[out] is_nan 1 if the given item is not a number, 0 otherwise.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE
   */
  XQUERY_ERROR
  (*nan)(XQC_Item item, int* is_nan);

  /**
    Check if the value of the Item is positive or negative infinity.
   * Note that this function is only available for numeric items (e.g. Double or Float).
   *
   * \param item The XQC_Item that this function pointer is a member of
   * \param[out] inf 1 if the given item is +/-INF, 0 otherwise.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0024_FUNCTION_NOT_IMPLEMENTED_FOR_ITEMTYPE
   */
  XQUERY_ERROR
  (*pos_or_neg_inf)(XQC_Item item, int* inf);

  /**
   * Called to free the resources associated with the XQC_Item.
   * 
   * \param item The XQC_Item that this function pointer is a member of
   */
  void
  (*free)(XQC_Item item);

  /**
   * for internal use only
   */
  void* data;
};

/**
 * An instance of this class can be obtained by calling <code>item_factory</code> function
 * of an ::XQC_Implementation object.
 *
 * Each <code>create_XXX</code> function of this struct creates an ::XQC_Item of an XML Schema item.
 * Each of the functions takes either NULL or a valid XQC_Item wrapper. The latter is created
 * by calling <code>XQC_Implementation::create_item</code>. In both cases, the user is responsible 
 * for freeing the object by calling the XQC_Item::free() function.
 */
struct XQC_ItemFactory_s
{
  /** 
   * Creates a String Item see [http://www.w3.org/TR/xmlschema-2/#string].
   *
   * \param factory The XQC_ItemFactory that this function pointer is a member of
   * \param str The string as a char pointer.
   * \pram[out] item The item to create. This can either be a wrapper created using 
   *                 ::XQC_ItemFactory::create_item or a pointer initialized to 0.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0025_COULD_NOT_CREATE_ITEM
   */
  XQUERY_ERROR
  (*create_string)(XQC_ItemFactory factory, const char* str, XQC_Item_Ref item); 

  /** 
   * Creates an AnyURI Item see [http://www.w3.org/TR/xmlschema-2/#anyURI]
   *
   * \param factory The XQC_ItemFactory that this function pointer is a member of
   * \param str The uri as a char pointer.
   * \pram[out] item The item to create. This can either be a wrapper created using 
   *                 ::XQC_ItemFactory::create_item or a pointer initialized to 0.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0025_COULD_NOT_CREATE_ITEM
   */
  XQUERY_ERROR
  (*create_anyuri)(XQC_ItemFactory factory, const char* str, XQC_Item_Ref item); 

  /**
   * Creates a QName Item see [http://www.w3.org/TR/xmlschema-2/#QName]
   *
   * \param factory The XQC_ItemFactory that this function pointer is a member of
   * \param str The uri as a char pointer.
   * \param localname The localname as a char pointer.
   * \pram[out] item The item to create. This can either be a wrapper created using 
   *                 ::XQC_ItemFactory::create_item or a pointer initialized to 0.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0025_COULD_NOT_CREATE_ITEM
   */
  XQUERY_ERROR
  (*create_qname2)(XQC_ItemFactory factory, 
                   const char* uri,
                   const char* localname,
                   XQC_Item_Ref item); 
  
  /**
   * Creates a QName Item see [http://www.w3.org/TR/xmlschema-2/#QName]
   *
   * \param factory The XQC_ItemFactory that this function pointer is a member of
   * \param str The uri as a char pointer.
   * \param prefix The prefix as a char pointer.
   * \param localname The localname as a char pointer.
   * \pram[out] item The item to create. This can either be a wrapper created using 
   *                 ::XQC_ItemFactory::create_item or a pointer initialized to 0.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0025_COULD_NOT_CREATE_ITEM
   */
  XQUERY_ERROR
  (*create_qname3)(XQC_ItemFactory factory, 
                   const char* uri,
                   const char* prefix,
                   const char* localname,
                   XQC_Item_Ref item); 

  /** 
   * Creates a Boolean Item see [http://www.w3.org/TR/xmlschema-2/#bool]
   *
   * \param factory The XQC_ItemFactory that this function pointer is a member of
   * \param boolean 0 for a boolean <code>false</code> boolean item, 1 otherwise.
   * \pram[out] item The item to create. This can either be a wrapper created using 
   *                 ::XQC_ItemFactory::create_item or a pointer initialized to 0.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval ::XQP0025_COULD_NOT_CREATE_ITEM
   */
  XQUERY_ERROR
  (*create_boolean)(XQC_ItemFactory factory, int boolean, XQC_Item_Ref item); 

  /**
   * Called to free the resources associated with the XQC_ItemFactory.
   * 
   * \param factory The XQC_ItemFactory that this function pointer is a member of
   */
  void
  (*free)(XQC_ItemFactory factory);

  /**
   * for internal use only
   */
  void* data;
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
   * \param[out] item The item wrapper that should contain the next item if XQ_NO_ERROR is returned
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval any XQuery type or dynamic error
   */
  XQUERY_ERROR
  (*next)(XQC_Sequence sequence, XQC_Item item);

  /**
   * Called to free the resources associated with the XQC_ItemFactory.
   * 
   * \param factory The XQC_Sequence that this function pointer is a member of
   */
  void
  (*free)(XQC_Sequence sequence);

  /**
   * for internal use only
   */
  void* data;
};

struct XQC_Collection_s
{
  XQUERY_ERROR
  (*get_uri)(XQC_Collection collection, XQC_Item_Ref uri_item);

  XQUERY_ERROR
  (*add_node)(XQC_Collection collection, XQC_Item node);

  XQUERY_ERROR
  (*delete_node)(XQC_Collection collection, XQC_Item node);

  XQUERY_ERROR
  (*add_sequence)(XQC_Collection collection, XQC_Sequence sequence);

  XQUERY_ERROR
  (*add_document)(XQC_Collection collection, FILE* doc);

  XQUERY_ERROR
  (*add_document_char)(XQC_Collection collection, const char* doc);

  void
  (*free)(XQC_Collection collection);

  /**
   * for internal use only
   */
  void* data;
};

struct XQC_DataManager_s
{
  XQUERY_ERROR
  (*load_document)(XQC_DataManager data_manager, const char* doc_uri, FILE* document);

  XQUERY_ERROR
  (*load_document_uri)(XQC_DataManager data_manager, const char* location);

  XQUERY_ERROR
  (*get_document)(XQC_DataManager data_manager, const char* document_uri, XQC_Item_Ref doc);

  XQUERY_ERROR
  (*delete_document)(XQC_DataManager data_manager, const char* document_uri);

  XQUERY_ERROR
  (*create_collection)(XQC_DataManager data_manager, const char* collection_uri, XQC_Collection_Ref col);

  XQUERY_ERROR
  (*get_collection)(XQC_DataManager data_manager, const char* collection_uri, XQC_Collection_Ref collection);

  XQUERY_ERROR
  (*delete_collection)(XQC_DataManager data_manager, const char* collection_uri);

  void
  (*free)(XQC_DataManager data_manager);

  /**
   * for internal use only
   */
  void* data;
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
  (*read)(XQC_InputStream stream, char* buf, unsigned int length);

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
  (*free)(XQC_InputStream stream);

	/**
	 * Can be used for user specific purposes.
	 */
  void* user_data;
};

/**
 * The ::XQC_ErrorHandler struct is designed to be populated by users for the purpose
 * of collecting more detailed error messages from an XQC implementation. An XQC_ErrorHandler
 * can be set for a query using the XQC_Query::set_error_handler() function.
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
     * \param error The error as a value of the XQUERY_ERROR enum.
     * \param local_name The local name of the error or an empty string if no local_name is given 
     *                   (e.g. for errors not defined in the spec).
     * \param description A detailed description of the error or an empty string if no description is available.
     * \param query_uri The uri of the query causing the error or an empty string if no uri is available for the query.
     * \param line The line number of the query where the error occured.
     * \param components The column number in the line in the query where the error occured.
     */
    void (*error)(XQC_ErrorHandler handler, 
                  XQUERY_ERROR error,
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
 * \example cdatamanager.c
 *  This file contains some examples that demonstrate how the data manger can be used
 *  to load files, create collection, etc.
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
