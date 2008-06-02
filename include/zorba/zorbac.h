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


typedef XQUERY_ERROR*     XQUERY_ERROR_REF;

#ifdef __cplusplus
extern "C" {
#endif

XQUERY_ERROR
zorba_implementation(XQC_Implementation_Ref impl);

struct XQC_Implementation_s 
{
	XQUERY_ERROR 
  (*create_context)(XQC_Implementation impl, XQC_StaticContext_Ref context);

	XQUERY_ERROR 
  (*prepare)(XQC_Implementation implementation, const char *query_string,
		         XQC_StaticContext context, XQC_Query_Ref query);

	XQUERY_ERROR 
  (*prepare_file)(XQC_Implementation implementation, FILE *query_file,
		              XQC_StaticContext context, XQC_Query_Ref query);
 
  XQUERY_ERROR
  (*create_item)(XQC_Implementation implementation, XQC_Item_Ref item);

  XQUERY_ERROR
  (*item_factory)(XQC_Implementation implementation, XQC_ItemFactory_Ref factory);  

  XQUERY_ERROR
  (*data_manager)(XQC_Implementation implementation, XQC_DataManager_Ref data_manager);

  void
  (*free)(XQC_Implementation implementation);

  void* data;
};

struct XQC_Query_s 
{
	XQUERY_ERROR
  (*get_dynamic_context)(XQC_Query query, XQC_DynamicContext_Ref context);

  XQUERY_ERROR
  (*get_static_context)(XQC_Query, XQC_StaticContext_Ref context);

	XQUERY_ERROR 
  (*execute)(XQC_Query query, FILE*);

	XQUERY_ERROR 
  (*apply_updates)(XQC_Query query);

	XQUERY_ERROR 
  (*sequence)(XQC_Query query, XQC_Sequence_Ref sequence);

  void
  (*free)(XQC_Query query);

  void* data;
};

struct XQC_StaticContext_s 
{
  XQUERY_ERROR
  (*create_child_context)(XQC_StaticContext context, XQC_StaticContext_Ref child_context);

  XQUERY_ERROR
  (*add_namespace)(XQC_StaticContext context, const char* prefix, const char* uri);

  XQUERY_ERROR
  (*get_namespace_by_prefix)(XQC_StaticContext context, const char* prefix, const char** result_ns);

  XQUERY_ERROR
  (*set_default_element_and_type_ns)(XQC_StaticContext context, const char* uri);

  XQUERY_ERROR
  (*get_default_element_and_type_ns)(XQC_StaticContext context, const char** uri);

  XQUERY_ERROR
  (*set_default_function_ns)(XQC_StaticContext context, const char* uri);

  XQUERY_ERROR
  (*get_default_function_ns)(XQC_StaticContext context, const char** uri);

  XQUERY_ERROR
  (*add_collation)(XQC_StaticContext context, const char* uri);

  XQUERY_ERROR
  (*set_default_collation)(XQC_StaticContext context, const char* uri);

  XQUERY_ERROR
  (*get_default_collation)(XQC_StaticContext context, const char** uri);

  XQUERY_ERROR
  (*set_xpath1_0_mode)(XQC_StaticContext context, xpath1_0compatib_mode_t mode );

  XQUERY_ERROR 
  (*get_xpath1_0_mode)(XQC_StaticContext context, xpath1_0compatib_mode_t* mode);

  XQUERY_ERROR
  (*set_construction_mode)(XQC_StaticContext context, construction_mode_t mode );

  XQUERY_ERROR
  (*get_construction_mode)(XQC_StaticContext context, construction_mode_t* mode);

  XQUERY_ERROR
  (*set_ordering_mode)(XQC_StaticContext context, ordering_mode_t mode );

  XQUERY_ERROR
  (*get_ordering_mode)(XQC_StaticContext context, ordering_mode_t* mode );

  XQUERY_ERROR
  (*set_default_order_empty_sequences)(XQC_StaticContext context, order_empty_mode_t mode );

  XQUERY_ERROR
  (*get_default_order_empty_sequences)(XQC_StaticContext context, order_empty_mode_t* mode );

  XQUERY_ERROR  
  (*set_boundary_space_policy)(XQC_StaticContext context, boundary_space_mode_t mode);

  XQUERY_ERROR
  (*get_boundary_space_policy)(XQC_StaticContext context, boundary_space_mode_t* mode );

  XQUERY_ERROR 
  (*set_copy_namespaces_mode)(XQC_StaticContext context,  
                              preserve_mode_t preserve,
                              inherit_mode_t inherit );

  XQUERY_ERROR
  (*get_copy_namespaces_mode)(XQC_StaticContext context,
                              preserve_mode_t* aPreserve,
                              inherit_mode_t* aInherit );

  XQUERY_ERROR
  (*set_base_uri)(XQC_StaticContext context, const char* base_uri );

  XQUERY_ERROR
  (*get_base_uri)(XQC_StaticContext context, const char** base_uri);

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

  XQUERY_ERROR
  (*reset)(XQC_Sequence sequence);

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


#ifdef __cplusplus
}
#endif

#endif
