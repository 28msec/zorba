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
#include "stdafx.h"

#include "annotations/annotations.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "compiler/expression/expr.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "system/globalenv.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(AnnotationInternal)

SERIALIZABLE_CLASS_VERSIONS(AnnotationList)


std::vector<store::Item_t>
AnnotationInternal::theAnnotId2NameMap;

ItemHandleHashMap<AnnotationInternal::AnnotationId>
AnnotationInternal::theAnnotName2IdMap(0, NULL, 64, false);

std::vector<AnnotationInternal::RuleBitSet>
AnnotationInternal::theRuleSet;


/*******************************************************************************
  Static method, called from GlobalEnvironment::init()
********************************************************************************/
void AnnotationInternal::createBuiltIn()
{
  store::Item_t qname;
  AnnotationId id;

  theAnnotId2NameMap.resize(zann_end);

  //
  // W3C annotations
  //
  GENV_ITEMFACTORY->createQName(qname, static_context::W3C_FN_NS, "fn", "public");
  id = fn_public;
  theAnnotId2NameMap[id] = qname;
  theAnnotName2IdMap.insert(qname, id);

  GENV_ITEMFACTORY->createQName(qname, static_context::W3C_FN_NS, "fn", "private");
  id = fn_private;
  theAnnotId2NameMap[id] = qname;
  theAnnotName2IdMap.insert(qname, id);

#define ZANN(a, b)                                                     \
  GENV_ITEMFACTORY->createQName(qname, ZORBA_ANNOTATIONS_NS, "", #a);  \
  id = zann_##b;                                                       \
  theAnnotId2NameMap[id] = qname;                                      \
  theAnnotName2IdMap.insert(qname, id);


  //
  // Zorba annotations - deterministic/nondeterministic
  //
  ZANN(deterministic, deterministic);
  ZANN(nondeterministic, nondeterministic);

  //
  // Zorba annotations - xquery scripting
  //
  ZANN(assignable, assignable);
  ZANN(nonassignable, nonassignable);

  ZANN(sequential, sequential);
  ZANN(nonsequential, nonsequential);

  //
  // Zorba annotations - optimizer
  //
  ZANN(propagates-input-nodes, propagates_input_nodes);
  ZANN(must-copy-input-nodes, must_copy_input_nodes);

  //
  // Zorba annotations - misc
  //
  ZANN(variadic, variadic);

  ZANN(streamable, streamable);

  ZANN(cache, cache);
  ZANN(no-cache, nocache);

  //
  // Zorba annotations - xqddf
  //
  ZANN(unique, unique);
  ZANN(nonunique, nonunique);

  ZANN(value-equality, value_equality);
  ZANN(general-equality, general_equality);
  ZANN(value-range, value_range);
  ZANN(general-range, general_range);

  ZANN(automatic, automatic);
  ZANN(manual, manual);

  ZANN(mutable, mutable);
  ZANN(queue, queue);
  ZANN(append-only, append_only);
  ZANN(const, const);

  ZANN(ordered, ordered);
  ZANN(unordered, unordered);

  ZANN(read-only-nodes, read_only_nodes);
  ZANN(mutable-nodes, mutable_nodes);

#undef ZANN

  // create a set of rules to detect conflicts between annotations
#define ZANN(a) \
  ( 1 << static_cast<uint64_t>(AnnotationInternal::a) )

  theRuleSet.push_back(
       ZANN(zann_unique) |
       ZANN(zann_nonunique));

  theRuleSet.push_back(
      ZANN(zann_value_equality) |
      ZANN(zann_general_equality) |
      ZANN(zann_value_range) |
      ZANN(zann_general_range));

  theRuleSet.push_back(
      ZANN(zann_automatic) |
      ZANN(zann_manual));

  theRuleSet.push_back(
      ZANN(zann_mutable) |
      ZANN(zann_queue) |
      ZANN(zann_append_only) |
      ZANN(zann_const));

  theRuleSet.push_back(
      ZANN(zann_ordered) |
      ZANN(zann_unordered));

  theRuleSet.push_back(
      ZANN(zann_assignable) |
      ZANN(zann_nonassignable));

  theRuleSet.push_back(
      ZANN(zann_deterministic) |
      ZANN(zann_nondeterministic));

  theRuleSet.push_back(
      ZANN(zann_sequential) |
      ZANN(zann_nonsequential));

  theRuleSet.push_back(
      ZANN(zann_cache) |
      ZANN(zann_nocache));

  theRuleSet.push_back(
      ZANN(fn_private) |
      ZANN(fn_public));

  theRuleSet.push_back(
      ZANN(zann_unordered) |
      ZANN(zann_queue));

  theRuleSet.push_back(
      ZANN(zann_unordered) |
      ZANN(zann_append_only));

  theRuleSet.push_back(
      ZANN(zann_queue) |
      ZANN(zann_append_only));

  theRuleSet.push_back(
      ZANN(zann_read_only_nodes) |
      ZANN(zann_mutable_nodes));
#undef ZANN
}


/*******************************************************************************
  Static method, called from GlobalEnvironment::destroy()
********************************************************************************/
void AnnotationInternal::destroyBuiltIn()
{
  theAnnotId2NameMap.clear();
  theAnnotName2IdMap.clear();
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal::AnnotationId AnnotationInternal::lookup(
    const store::Item_t& qname)
{
  ItemHandleHashMap<AnnotationId>::iterator ite = theAnnotName2IdMap.find(qname);

  if (ite == theAnnotName2IdMap.end())
    return zann_end;

  return (*ite).second;
}


/*******************************************************************************

********************************************************************************/
store::Item* AnnotationInternal::lookup(AnnotationInternal::AnnotationId id)
{
  assert(id < zann_end);
  assert(id < theAnnotId2NameMap.size());

  return theAnnotId2NameMap[id].getp();
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal::AnnotationInternal(const store::Item_t& qname)
  :
  theId(zann_end),
  theQName(qname)
{
  ItemHandleHashMap<AnnotationId>::iterator ite = theAnnotName2IdMap.find(qname);
  if (ite != theAnnotName2IdMap.end())
    theId = (*ite).second;
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal::AnnotationInternal(
  const store::Item_t& qname,
  std::vector<store::Item_t>& literals)
  :
  theId(zann_end),
  theQName(qname)
{
  theLiterals.swap(literals);

  ItemHandleHashMap<AnnotationId>::iterator ite = theAnnotName2IdMap.find(qname);
  if (ite != theAnnotName2IdMap.end())
    theId = (*ite).second;
}


/*******************************************************************************

********************************************************************************/
void AnnotationInternal::serialize(::zorba::serialization::Archiver& ar)
{
  SERIALIZE_ENUM(AnnotationId, theId);
  ar & theQName;
  ar & theLiterals;
}


/*******************************************************************************

********************************************************************************/
const store::Item* AnnotationInternal::getQName() const
{
  return theQName.getp();
}


/*******************************************************************************

********************************************************************************/
csize AnnotationInternal::getNumLiterals() const
{
  return theLiterals.size();
}


/*******************************************************************************

********************************************************************************/
store::Item* AnnotationInternal::getLiteral(csize index) const
{
  if (index < theLiterals.size())
    return theLiterals[index].getp();
  else
    return NULL;
}


/*******************************************************************************

********************************************************************************/
AnnotationList::AnnotationList()
{
}


/*******************************************************************************

********************************************************************************/
AnnotationList::~AnnotationList()
{
}


/*******************************************************************************

********************************************************************************/
void AnnotationList::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theAnnotationList;
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal* AnnotationList::get(csize index) const
{
  if (index < theAnnotationList.size())
    return theAnnotationList[index].getp();
  else
    return NULL;
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal* AnnotationList::get(AnnotationInternal::AnnotationId id) const
{
  for (ListConstIter_t ite = theAnnotationList.begin();
       ite != theAnnotationList.end();
       ++ite)
  {
    if ((*ite)->getId() == id)
      return (*ite).getp();
  }

  return NULL;
}


/*******************************************************************************

********************************************************************************/
bool AnnotationList::contains(AnnotationInternal::AnnotationId id) const
{
  return (get(id) != NULL);
}


/*******************************************************************************

********************************************************************************/
void AnnotationList::push_back(
    const store::Item_t& qname,
    const std::vector<const_expr* >& literals)
{
  std::vector<store::Item_t> lLiterals;

  for (std::vector<const_expr* >::const_iterator it = literals.begin();
       it != literals.end();
       ++it)
  {
    lLiterals.push_back((*it)->get_val());
  }

  theAnnotationList.push_back(new AnnotationInternal(qname, lLiterals));
}


/*******************************************************************************
  Called from translator::end_visit(const AnnotationListParsenode& v, void*)
********************************************************************************/
void AnnotationList::checkConflictingDeclarations(const QueryLoc& loc) const
{
  // make sure we don't have more annotations then max 64 bit
  assert(AnnotationInternal::zann_end < 64);

  RuleBitSet lCurrAnn;

  // mark and detect duplicates
  for (ListConstIter_t ite = theAnnotationList.begin();
       ite != theAnnotationList.end();
       ++ite)
  {
    const store::Item* qname = (*ite)->getQName();
    AnnotationId id = (*ite)->getId();

    // detect duplicate annotations (if we "know" them)
    if (id != AnnotationInternal::zann_end && lCurrAnn.test(id))
    {
      RAISE_ERROR(err::XQST0106, loc,
      ERROR_PARAMS(qname->getStringValue(), ZED(XQST0106_THE_SAME)));
    }

    lCurrAnn.set(id);
  }

  // check rules
  std::vector<RuleBitSet>::const_iterator ite = AnnotationInternal::theRuleSet.begin();
  std::vector<RuleBitSet>::const_iterator end = AnnotationInternal::theRuleSet.end();

  for (; ite != end; ++ite)
  {
    const RuleBitSet& lCurrSet = *ite;

    if ((lCurrAnn & lCurrSet).count() >  1)
    {
      // build error string to return set of conflicting annotations
      std::ostringstream lProblems;
      for (csize i = 0, j = 0; i < AnnotationInternal::zann_end; ++i)
      {
        if (lCurrSet.test(i))
        {
          AnnotationId id = static_cast<AnnotationId>(i);

          lProblems << AnnotationInternal::lookup(id)->getStringValue()
                    << ((j == lCurrSet.count() - 1) ? "" : ", ");
          ++j;
        }
      }

      RAISE_ERROR(err::XQST0106, loc,
      ERROR_PARAMS(lProblems.str(), ZED(XQST0106_CONFLICTING)));
    }
  }
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
