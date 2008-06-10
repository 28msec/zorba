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
  * \param[out] expression The resulting prepared expression.
  *
  * \retval ::XQC_NO_ERROR
  * \retval ::XQP0019_INTERNAL_ERROR
  * \retval An XQuery static or type error (e.g. XPST*, XPTY*)
  */
	XQUERY_ERROR 
  (*prepare)(XQC_Implementation implementation, const char *query_string,
		         XQC_StaticContext context, XQC_Query_Ref query);

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
   * \param[out] expression The resulting prepared expression.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval An XQuery static or type error (e.g. XPST*, XPTY*)
   */
	XQUERY_ERROR 
  (*prepare_file)(XQC_Implementation implementation, FILE *query_file,
		              XQC_StaticContext context, XQC_Query_Ref query);

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
   * \param[out] expression The resulting prepared expression.
   *
   * \retval ::XQC_NO_ERROR
   * \retval ::XQP0019_INTERNAL_ERROR
   * \retval An XQuery static or type error (e.g. XPST*, XPTY*)
   */
  XQUERY_ERROR
  (*prepare_stream)(XQC_Implementation implementation, XQC_InputStream stream,
                    XQC_StaticContext context, XQC_Query_Ref query);
 
  XQUERY_ERROR
  (*create_item)(XQC_Implementation implementation, XQC_Item_Ref item);

  XQUERY_ERROR
  (*item_factory)(XQC_Implementation implementation, XQC_ItemFactory_Ref factory);  

  XQUERY_ERROR
  (*data_manager)(XQC_Implementation implementation, XQC_DataManager_Ref data_manager);


  /**
   * Called to free the resources associated with the XQC_Implementation.
   * 
   * \param implementation The XQC_Implementation that this function pointer is a member of
   */
  void
  (*free)(XQC_Implementation implementation);

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
	XQUERY_ERROR
  (*get_dynamic_context)(XQC_Query query, XQC_DynamicContext_Ref context);

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
  * Called to free the resources associated with the XQC_Query.
  * 
  * \param query The XQC_Query that this function pointer is a member of.
  */
  void
  (*free)(XQC_Query query);

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

  XQUERY_ERROR
  (*add_collation)(XQC_StaticContext context, const char* uri);

  XQUERY_ERROR
  (*set_default_collation)(XQC_StaticContext context, const char* uri);

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

  void* data;
};


struct XQC_DynamicContext_s 
{
	XQUERY_ERROR 
  (*set_context_item) (XQC_DynamicContext context, XQC_Item value);

  XQUERY_ERROR
  (*set_context_document)(XQC_DynamicContext context, const char* doc_uri, FILE* document);

  XQUERY_ERROR
  (*set_variable_item)(XQC_DynamicContext context, const char* qname, XQC_Item value);

  XQUERY_ERROR
  (*set_variable_sequence)(XQC_DynamicContext context, const char* qname, XQC_Sequence value);

  XQUERY_ERROR
  (*set_variable_document)(XQC_DynamicContext context, const char* var_qname, const char* doc_uri, FILE* document);

  XQUERY_ERROR 
  (*set_implicit_timezone)(XQC_DynamicContext context, int timezone);

  XQUERY_ERROR
  (*set_default_collection)(XQC_DynamicContext context, XQC_Item collection_uri);

  void
  (*free)(XQC_DynamicContext context);

  void* data;
};

struct XQC_Item_s 
{
  XQUERY_ERROR
  (*string_value)(XQC_Item item, const char**);

  XQUERY_ERROR
  (*prefix)(XQC_Item item, const char**);

  XQUERY_ERROR
  (*ns)(XQC_Item item, const char**);

  XQUERY_ERROR
  (*localname)(XQC_Item item, const char**);

  XQUERY_ERROR
  (*boolean_value)(XQC_Item item, int*);

  XQUERY_ERROR
  (*nan)(XQC_Item item, int*);

  XQUERY_ERROR
  (*pos_or_neg_inf)(XQC_Item item, int*);

  void
  (*free)(XQC_Item item);

  void* data;
};

struct XQC_ItemFactory_s
{
  XQUERY_ERROR
  (*create_string)(XQC_ItemFactory factory, const char* str, XQC_Item_Ref item); 

  XQUERY_ERROR
  (*create_anyuri)(XQC_ItemFactory factory, const char* str, XQC_Item_Ref item); 

  XQUERY_ERROR
  (*create_qname2)(XQC_ItemFactory factory, const char* uri, const char* localname, XQC_Item_Ref item); 
  
  XQUERY_ERROR
  (*create_qname3)(XQC_ItemFactory factory, const char* uri, const char* prefix,
                   const char* localname, XQC_Item_Ref item); 

  XQUERY_ERROR
  (*create_boolean)(XQC_ItemFactory factory, int boolean, XQC_Item_Ref item); 

  void
  (*free)(XQC_ItemFactory factory);

  void* data;
};

struct XQC_Sequence_s 
{
  XQUERY_ERROR
  (*next)(XQC_Sequence sequence, XQC_Item item);

  void
  (*free)(XQC_Sequence sequence);

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

  void* data;
};

struct XQC_OutputStream_s
{
  void
  (*write)(XQC_OutputStream stream, const char* buf, unsigned int length);

  void 
  (*free)(XQC_OutputStream stream);

  void* user_data;
};

struct XQC_InputStream_s
{
  int
  (*read)(XQC_InputStream stream, char* buf, unsigned int length);

  void 
  (*free)(XQC_InputStream stream);

  void* user_data;
};

/** 
 * \example csimple.c
 *  This is a simple example that demonstrate how to use the Zorba XQuery Engine to
 *  create, compile, and execute queries.
 *
 * \example cdatamanager.cpp
 *  This file contains some examples that demonstrate how the data manger can be used
 *  to load files, create collection, etc.
 *
 * \example ccontext.cpp
 *  This file demonstrates how the item factory can be used to create new items and 
 *  bind the items to external variables in the dynamic context before executing a query.
 */

#ifdef __cplusplus
}
#endif

#endif
