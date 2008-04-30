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
#include "system/globalenv.h"
#include "functions/QNames.h"
#include "runtime/qnames/QNamesImpl.h"
#include "types/node_test.h"

 namespace zorba {
/*
 * 11.1.1 fn:resolve-QName
 * --------------------*/
/*begin class fn_resolve_qname*/
fn_resolve_qname::fn_resolve_qname(
  const signature& sig)
  :
  function(sig)
{
}

PlanIter_t
    fn_resolve_qname::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ResolveQNameIterator(loc, argv[0], argv[1]);
}


/*end class fn_resolve_qname*/

 /*
 * 11.1.2 fn:QName
 * --------------------*/
/*begin class fn_qname*/
fn_qname::fn_qname(
    const signature& sig)
     :
    function(sig)
{
}

PlanIter_t
    fn_qname::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new QNameIterator(loc, argv[0], argv[1]);
}


/*end class fn_qname*/

 /*
 * 11.2.1 op:QName-equal
 * --------------------*/
/*begin class op_qname_equal*/
op_qname_equal::op_qname_equal(
  const signature& sig)
  :
  function(sig)
{
}

PlanIter_t
    op_qname_equal::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new QNameEqualIterator(loc, argv[0], argv[1]);
}


/*end class op_qname_equal*/

 /*
 * 11.2.2 fn:prefix-from-QName
 * --------------------*/
/*begin class fn_prefix_from_qname*/
fn_prefix_from_qname::fn_prefix_from_qname(
  const signature& sig)
  :
  function(sig)
{
}

PlanIter_t
    fn_prefix_from_qname::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new PrefixFromQNameIterator(loc, argv[0]);
}


/*end class fn_prefix_from_qname*/

/*
 * 11.2.3 fn:local-name-from-QName
 * --------------------*/
/*begin class fn_local_name_from_qname*/
fn_local_name_from_qname::fn_local_name_from_qname(
  const signature& sig)
  :
  function(sig)
{
}

PlanIter_t
    fn_local_name_from_qname::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new LocalNameFromQNameIterator(loc, argv[0]);
}


/*end class fn_local_name_from_qname*/

/*
 * 11.2.4 fn:namespace-uri-from-QName
 * --------------------*/
/*begin class fn_namespace_uri_from_qname*/
fn_namespace_uri_from_qname::fn_namespace_uri_from_qname(
  const signature& sig)
  :
  function(sig)
{
}

PlanIter_t
    fn_namespace_uri_from_qname::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NamespaceUriFromQNameIterator(loc, argv[0]);
}


/*end class fn_namespace_uri_from_qname*/

/*
 * 11.2.5 fn:namespace-uri-for-prefix
 * --------------------*/
/*begin class fn_namespace_uri_for_prefix*/
fn_namespace_uri_for_prefix::fn_namespace_uri_for_prefix(
  const signature& sig)
  :
  function(sig)
{
}

PlanIter_t
    fn_namespace_uri_for_prefix::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NamespaceUriForPrefixlIterator(loc, argv[0], argv[1]);
}


/*end class fn_namespace_uri_for_prefix*/

/*
 * 11.2.6 fn:in-scope-prefixes
 * --------------------*/
/*begin class fn_in_scope_prefixes*/
fn_in_scope_prefixes::fn_in_scope_prefixes(
  const signature& sig)
  :
  function(sig)
{
}

PlanIter_t
    fn_in_scope_prefixes::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new InScopePrefixesIterator(loc, argv[0]);
}

/*end class fn_in_scope_prefixes*/
 }/*namespace zorba*/
