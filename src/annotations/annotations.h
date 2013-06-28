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
#pragma once
#ifndef ZORBA_API_ANNOTATIONS_H
#define ZORBA_API_ANNOTATIONS_H

#include <vector>
#include <bitset>

#include "common/shared_types.h"

//#include "compiler/parsetree/parsenodes.h"

#include "zorbautils/hashmap_itemh.h"

namespace zorba
{

class AnnotationInternal;
class AnnotationList;

typedef rchandle<AnnotationInternal> AnnotationInternal_t;
typedef rchandle<AnnotationList> AnnotationList_t;

class const_expr;

/*******************************************************************************
  theAnnotName2IdMap:
  -------------------
  Maps annotation qnames to internal annotation ids

  theAnnotId2NameMap:
  -------------------
  The reverse of theAnnotName2IdMap

  theRuleSet:
  -----------
  A vector containing all the rules for conflicting annotations. Each rule is
  specified as a set of annotation: if 2 or more annotations in the set appear
  together in a declaration, then a conflict exists. Each set of annotations
  is implemented as a bitset indexed by annotation id.
********************************************************************************/
class AnnotationInternal : public SimpleRCObject
{
  friend class AnnotationList;

public:
  enum AnnotationId
  {
    fn_public = 0,
    fn_private,
    zann_deterministic,
    zann_nondeterministic,
    zann_assignable,
    zann_nonassignable,
    zann_sequential,
    zann_nonsequential,
    zann_propagates_input_nodes,
    zann_must_copy_input_nodes,
    zann_cache,
    zann_nocache,
    zann_variadic,
    zann_streamable,
    zann_unique,
    zann_nonunique,
    zann_value_equality,
    zann_general_equality,
    zann_value_range,
    zann_general_range,
    zann_automatic,
    zann_manual,
    zann_mutable,
    zann_queue,
    zann_append_only,
    zann_const,
    zann_ordered,
    zann_unordered,
    zann_read_only_nodes,
    zann_mutable_nodes,    
    zann_explores_json,

    // must be at the end
    zann_end
  };

protected:
  typedef std::bitset<static_cast<int>(zann_end) + 1> RuleBitSet;

protected:
  static std::vector<store::Item_t>      theAnnotId2NameMap;

  static ItemHandleHashMap<AnnotationId> theAnnotName2IdMap;

  static std::vector<RuleBitSet>         theRuleSet;

protected:
  AnnotationId                   theId;
  store::Item_t                  theQName;
  std::vector<store::Item_t>     theLiterals;

public:
  static void createBuiltIn();

  static void destroyBuiltIn();

  static AnnotationId lookup(const store::Item_t& qname);

  static store::Item* lookup(AnnotationId id);

public:
  AnnotationInternal(const store::Item_t& qname);

  AnnotationInternal(
    const store::Item_t& qname,
    std::vector<store::Item_t>& literals);

public:
  SERIALIZABLE_CLASS(AnnotationInternal);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationInternal, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  ~AnnotationInternal() { };

  AnnotationId getId() const { return theId; }

  const store::Item* getQName() const;

  csize getNumLiterals() const;

  store::Item* getLiteral(csize index) const;
};


/*******************************************************************************
  AnnotationList := Annotation*

  Annotation ::= "%" EQName  ("(" Literal  ("," Literal)* ")")?
********************************************************************************/
class AnnotationList : public SimpleRCObject
{
public:
  enum DeclarationKind
  {
    func_decl,
    var_decl,
    index_decl,
    collection_decl
  };

public:
  typedef AnnotationInternal::RuleBitSet RuleBitSet;

  typedef AnnotationInternal::AnnotationId AnnotationId;

  typedef std::vector<AnnotationInternal_t> List_t;

  typedef List_t::const_iterator ListConstIter_t;

protected:
  List_t theAnnotationList;

public:
  SERIALIZABLE_CLASS(AnnotationList);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationList, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AnnotationList();

  ~AnnotationList();

  csize size() const { return theAnnotationList.size(); }

  AnnotationInternal* get(csize index) const;

  AnnotationInternal* get(AnnotationInternal::AnnotationId id) const;

  bool contains(AnnotationInternal::AnnotationId id) const;

  void push_back(
      const store::Item_t& qname,
      const std::vector<const_expr*>& literals);
  
  void push_back(AnnotationInternal::AnnotationId id);

  void checkConflictingDeclarations(DeclarationKind k, const QueryLoc& loc) const;
};


} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
