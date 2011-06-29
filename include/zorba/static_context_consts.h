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
#ifndef ZORBA_STATIC_CONTEXT_CONSTS_API_H
#define ZORBA_STATIC_CONTEXT_CONSTS_API_H

namespace zorba
{

/** \brief XPath 1.0 compatibility mode as defined in 
 *         http://www.w3.org/TR/xquery/#static_context 
 */
typedef enum { xpath2_0, xpath1_0 } xpath1_0compatib_mode_t;

/** \brief Ordering mode as defined in http://www.w3.org/TR/xquery/#static_context.
 */
typedef enum { ordered, unordered } ordering_mode_t;

/** \brief Default order for empty sequences as defined in 
 *         http://www.w3.org/TR/xquery/#static_context.
 */
typedef enum { empty_greatest, empty_least } order_empty_mode_t;

/** \brief Inherit part of the Copy-namespace mode as defined in 
 *         http://www.w3.org/TR/xquery/#static_context.
 */
typedef enum  { inherit_ns, no_inherit_ns } inherit_mode_t;

/** \brief Preserve part of the Copy-namespace mode as defined in 
 *         http://www.w3.org/TR/xquery/#static_context.
 */
typedef enum { preserve_ns, no_preserve_ns } preserve_mode_t;

/** \brief Boundary-space policy as defined in http://www.w3.org/TR/xquery/#static_context.
 */
typedef enum { preserve_space, strip_space } boundary_space_mode_t;

/** \brief Construction mode as defined in http://www.w3.org/TR/xquery/#static_context.
 */
typedef enum { preserve_cons, strip_cons } construction_mode_t;

/** \brief The XQuery version, taken from the version declaration, an XQuery 3.0 feature.
 */
typedef enum { xquery_version_1_0 = 100, xquery_version_3_0 = 300 } xquery_version_t;

/** \brief Revalidation mode as defined in
 *         http://www.w3.org/TR/xquery-update-10/#id-revalidation-declaration
 */
typedef enum { validate_skip, validate_lax, validate_strict } validation_mode_t;

/** \brief Update property of a collection as defined
 *         in the XQuery Data Definition Facility
 */
typedef enum { coll_const, coll_append_only, coll_queue, coll_mutable } collection_update_property_t;

/** \brief Order property of a collection as defined
 *         in the XQuery Data Definition Facility
 */
typedef enum { coll_ordered, coll_unordered } collection_order_property_t;

/** \brief Node modifier of a collection as defined
 *         in the XQuery Data Definition Facility
 */
typedef enum { coll_node_const, coll_node_mutable } collection_node_modifier_t;

/** \brief Maintenance mode of an index as defined
 *         in the XQuery Data Definition Facility
 */
typedef enum { index_automatic, index_manual } index_maintenance_mode_t;

/** \brief Container kind of an index as defined
 *         in the XQuery Data Definition Facility
 */
typedef enum { index_hash, index_tree } index_container_kind_t;

}

#endif
/* vim:set et sw=2 ts=2: */
