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

#endif
