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

typedef struct XQC_String_s* XQC_String;
typedef XQC_String* XQC_String_Ref;

typedef struct XQC_ItemFactory_s*  XQC_ItemFactory;
typedef XQC_ItemFactory* XQC_ItemFactory_Ref;

typedef struct XQC_OutputStream_s* XQC_OutputStream;

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
  (*compile)(XQC_Implementation implementation, const char *query_string,
		         XQC_StaticContext context, XQC_Query_Ref query);

	XQUERY_ERROR 
  (*compile_file)(XQC_Implementation implementation, FILE *query_file,
		              XQC_StaticContext context, XQC_Query_Ref query);

  void
  (*free)(XQC_Implementation implementation);

  XQUERY_ERROR
  (*create_item)(XQC_Implementation implementation, XQC_Item_Ref item);

  XQUERY_ERROR
  (*create_string)(XQC_Implementation implementation, const char* str, XQC_String_Ref res);

  XQUERY_ERROR
  (*item_factory)(XQC_Implementation implementation, XQC_ItemFactory_Ref factory);  

  void* data;
};

struct XQC_Query_s 
{
	XQUERY_ERROR
  (*get_dynamic_context)(XQC_Query query, XQC_DynamicContext_Ref context);

	XQUERY_ERROR 
  (*execute)(XQC_Query query, FILE*);

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
  (*add_namespace)(XQC_StaticContext context, XQC_String prefix, XQC_String uri);

  XQUERY_ERROR
  (*get_namespace_by_prefix)(XQC_StaticContext context, XQC_String prefix, XQC_String_Ref result_ns);

  XQUERY_ERROR
  (*set_default_element_and_type_ns)(XQC_StaticContext context, XQC_String uri);

  XQUERY_ERROR
  (*get_default_element_and_type_ns)(XQC_StaticContext context, XQC_String_Ref uri);

  XQUERY_ERROR
  (*set_default_function_ns)(XQC_StaticContext context, XQC_String uri);

  XQUERY_ERROR
  (*get_default_function_ns)(XQC_StaticContext context, XQC_String_Ref uri);

  XQUERY_ERROR
  (*add_collation)(XQC_StaticContext context, XQC_String uri);

  XQUERY_ERROR
  (*set_default_collation)(XQC_StaticContext context, XQC_String uri);

  XQUERY_ERROR
  (*get_default_collation)(XQC_StaticContext context, XQC_String_Ref uri);

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
  (*set_base_uri)(XQC_StaticContext context, XQC_String base_uri );

  XQUERY_ERROR
  (*get_base_uri)(XQC_StaticContext context, XQC_String_Ref base_uri);

  void
  (*free)(XQC_StaticContext context);

  void* data;
};

struct XQC_DynamicContext_s 
{

	XQUERY_ERROR 
  (*set_context_item) (XQC_DynamicContext context, XQC_Item value);

	XQUERY_ERROR 
  (*set_context_sequence)(XQC_DynamicContext context, XQC_Sequence value);

  void
  (*free)(XQC_DynamicContext context);

  void* data;
};

struct XQC_String_s 
{
  XQUERY_ERROR
  (*create)(XQC_String_Ref str);

  XQUERY_ERROR
  (*to_char)(XQC_String str, const char** res);

  void
  (*free)(XQC_String str);

  void* data;
};

struct XQC_Item_s 
{
  XQUERY_ERROR
  (*string_value)(XQC_Item item, XQC_String);

  XQUERY_ERROR
  (*prefix)(XQC_Item item, XQC_String);

  XQUERY_ERROR
  (*ns)(XQC_Item item, XQC_String);

  XQUERY_ERROR
  (*localname)(XQC_Item item, XQC_String);

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

struct XQC_OutputStream_s 
{
  void* user_data;

  unsigned int
  (*callback)(XQC_OutputStream stream, void* buffer, unsigned int size);

  void* data;
};

struct XQC_ItemFactory_s
{
  XQUERY_ERROR
  (*create_string)(XQC_ItemFactory factory, XQC_String str, XQC_Item_Ref item); 

  XQUERY_ERROR
  (*create_anyuri)(XQC_ItemFactory factory, XQC_String str, XQC_Item_Ref item); 

  XQUERY_ERROR
  (*create_qname2)(XQC_ItemFactory factory, XQC_String uri, XQC_String localname, XQC_Item_Ref item); 
  
  XQUERY_ERROR
  (*create_qname3)(XQC_ItemFactory factory, XQC_String uri, XQC_String prefix,
                   XQC_String localname, XQC_Item_Ref item); 

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


#ifdef __cplusplus
}
#endif

#endif
