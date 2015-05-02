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
AnnotationInternal::theConflictRuleSet;

std::vector<AnnotationInternal::AnnotationRequirement>
AnnotationInternal::theRequiredRuleSet;


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
  GENV_ITEMFACTORY->createQName(qname, static_context::XQUERY_NS, "", "public");
  id = fn_public;
  theAnnotId2NameMap[id] = qname;
  theAnnotName2IdMap.insert(qname, id);

  GENV_ITEMFACTORY->createQName(qname, static_context::XQUERY_NS, "", "private");
  id = fn_private;
  theAnnotId2NameMap[id] = qname;
  theAnnotName2IdMap.insert(qname, id);

#define ZANN(a, b)                                                     \
  GENV_ITEMFACTORY->createQName(qname, ZORBA_ANNOTATIONS_NS, "", #a);  \
  id = zann_##b;                                                       \
  theAnnotId2NameMap[id] = qname;                                      \
  theAnnotName2IdMap.insert(qname, id);


  //
  // Zorba annotations - strictlydeterministic/deterministic/nondeterministic
  //
  ZANN(strictlydeterministic, strictlydeterministic);
  ZANN(deterministic, deterministic);
  ZANN(nondeterministic, nondeterministic);

  //
  // Zorba annotations - caching behaviour
  //
  ZANN(exclude-from-cache-key, exclude_from_cache_key);
  ZANN(compare-with-deep-equal, compare_with_deep_equal);

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

#define ZANN(a) \
  ( uint64_t(1) << static_cast<uint64_t>(AnnotationInternal::a) )

  // create a set of rules to detect conflicts between annotations
  theConflictRuleSet.push_back(
       ZANN(zann_unique) |
       ZANN(zann_nonunique));

  theConflictRuleSet.push_back(
      ZANN(zann_value_equality) |
      ZANN(zann_general_equality) |
      ZANN(zann_value_range) |
      ZANN(zann_general_range));

  theConflictRuleSet.push_back(
      ZANN(zann_automatic) |
      ZANN(zann_manual));

  theConflictRuleSet.push_back(
      ZANN(zann_mutable) |
      ZANN(zann_queue) |
      ZANN(zann_append_only) |
      ZANN(zann_const));

  theConflictRuleSet.push_back(
      ZANN(zann_ordered) |
      ZANN(zann_unordered));

  theConflictRuleSet.push_back(
      ZANN(zann_assignable) |
      ZANN(zann_nonassignable));

  theConflictRuleSet.push_back(
      ZANN(zann_strictlydeterministic) |
      ZANN(zann_deterministic) |
      ZANN(zann_nondeterministic));

  theConflictRuleSet.push_back(
      ZANN(zann_strictlydeterministic) |
      ZANN(zann_cache));

  theConflictRuleSet.push_back(
      ZANN(zann_sequential) |
      ZANN(zann_nonsequential));

  theConflictRuleSet.push_back(
      ZANN(fn_private) |
      ZANN(fn_public));

  theConflictRuleSet.push_back(
      ZANN(zann_unordered) |
      ZANN(zann_queue));

  theConflictRuleSet.push_back(
      ZANN(zann_unordered) |
      ZANN(zann_append_only));

  theConflictRuleSet.push_back(
      ZANN(zann_queue) |
      ZANN(zann_append_only));

  theConflictRuleSet.push_back(
      ZANN(zann_read_only_nodes) |
      ZANN(zann_mutable_nodes));

  // create a set of rules to detect missing requirements between annotations
  theRequiredRuleSet.push_back(AnnotationRequirement(
      zann_exclude_from_cache_key,
      ZANN(zann_cache) | ZANN(zann_strictlydeterministic)
    ));

  theRequiredRuleSet.push_back(AnnotationRequirement(
      zann_compare_with_deep_equal,
      ZANN(zann_cache) | ZANN(zann_strictlydeterministic)
    ));

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
  assert(static_cast<unsigned>(id) < theAnnotId2NameMap.size());

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
  for (Annotations::iterator ite = theAnnotationList.begin();
       ite != theAnnotationList.end();
       ++ite)
  {
    delete *ite;
  }
}


/*******************************************************************************

********************************************************************************/
void AnnotationList::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theAnnotationList;
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal* AnnotationList::get(size_type index) const
{
  if (index < theAnnotationList.size())
    return theAnnotationList[index];
  else
    return NULL;
}


/*******************************************************************************

********************************************************************************/
AnnotationInternal* AnnotationList::get(AnnotationInternal::AnnotationId id) const
{
  for (Annotations::const_iterator ite = theAnnotationList.begin();
       ite != theAnnotationList.end();
       ++ite)
  {
    if ((*ite)->getId() == id)
      return (*ite);
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
  Called from translator to detect duplicates and conflicting declarations
********************************************************************************/
void AnnotationList::checkDeclarations(
    DeclarationKind declKind,
    const QueryLoc& loc) const
{
  // make sure we don't have more annotations then max 64 bit
  assert(AnnotationInternal::zann_end < 64);

  RuleBitSet lDeclaredAnnotations = checkDuplicateDeclarations(declKind, loc);
  checkConflictingDeclarations(lDeclaredAnnotations, declKind, loc);
  checkRequiredDeclarations(lDeclaredAnnotations, declKind, loc);
  checkLiterals(declKind, loc);
}

AnnotationList::RuleBitSet AnnotationList::checkDuplicateDeclarations(
    DeclarationKind declKind,
    const QueryLoc& loc) const
{
  RuleBitSet lCurrAnn;

  // mark and detect duplicates
  for (Annotations::const_iterator ite = theAnnotationList.begin();
       ite != theAnnotationList.end();
       ++ite)
  {
    const store::Item* qname = (*ite)->getQName();
    AnnotationId id = (*ite)->getId();

    // detect duplicate annotations (if we "know" them)
    if (id != AnnotationInternal::zann_end && lCurrAnn.test(id))
    {
      if (declKind == var_decl)
      {
        RAISE_ERROR(err::XQST0116, loc,
        ERROR_PARAMS(ZED(XQST0116_Duplicate), qname->getStringValue()));
      }
      else
      {
        RAISE_ERROR(err::XQST0106, loc,
        ERROR_PARAMS(ZED(XQST0106_Duplicate), qname->getStringValue()));
      }
    }
    lCurrAnn.set(id);
  }
  return lCurrAnn;
}

void AnnotationList::checkConflictingDeclarations(
    RuleBitSet currAnn,
    DeclarationKind declKind,
    const QueryLoc& loc) const
{
  // check rules
  std::vector<RuleBitSet>::const_iterator ite = AnnotationInternal::theConflictRuleSet.begin();
  std::vector<RuleBitSet>::const_iterator end = AnnotationInternal::theConflictRuleSet.end();

  for (; ite != end; ++ite)
  {
    const RuleBitSet& lCurrSet = *ite;

    if ((currAnn & lCurrSet).count() > 1)
    {
      // build error string to return set of conflicting annotations
      std::ostringstream lProblems;
      for (csize i = 0, j = 0; i < AnnotationInternal::zann_end; ++i)
      {
        if (lCurrSet.test(i))
        {
          AnnotationId id = static_cast<AnnotationId>(i);

          lProblems << AnnotationInternal::lookup(id)->getStringValue()
                    << ((j == (currAnn & lCurrSet).count() - 1) ? "" : ", ");
          ++j;
        }
      }

      if (declKind == var_decl)
      {
        RAISE_ERROR(err::XQST0116, loc,
        ERROR_PARAMS(ZED(XQST0116_Conflicting), lProblems.str()));
      }
      else
      {
        RAISE_ERROR(err::XQST0106, loc,
        ERROR_PARAMS(ZED(XQST0106_Conflicting), lProblems.str()));
      }
    }
  }
}

void AnnotationList::checkRequiredDeclarations(
    RuleBitSet declaredAnn,
    DeclarationKind declKind,
    const QueryLoc& loc) const
{
  // check rules
  std::vector<AnnotationRequirement>::const_iterator ite = AnnotationInternal::theRequiredRuleSet.begin();
  std::vector<AnnotationRequirement>::const_iterator end = AnnotationInternal::theRequiredRuleSet.end();

  for (; ite != end; ++ite)
  {
    const AnnotationId& lCurrAnn = ite->first;
    const RuleBitSet& lCurrSet = ite->second;

    if (declaredAnn.test(lCurrAnn) && (declaredAnn & lCurrSet).count() == 0)
    {
      // build error string to return set of required annotations
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

      if (declKind == var_decl)
      {
        RAISE_ERROR(err::XQST0116, loc,
        ERROR_PARAMS(ZED(XQST0116_Requirement),
            AnnotationInternal::lookup(lCurrAnn)->getStringValue(),
            lProblems.str()));
      }
      else
      {
        RAISE_ERROR(err::XQST0106, loc,
        ERROR_PARAMS(ZED(XQST0106_Requirement),
            AnnotationInternal::lookup(lCurrAnn)->getStringValue(),
            lProblems.str()));
      }
    }
  }
}

void AnnotationList::checkLiterals(DeclarationKind k, const QueryLoc& loc) const
{
  for (Annotations::const_iterator ite = theAnnotationList.begin();
       ite != theAnnotationList.end();
       ++ite)
  {
    AnnotationInternal* lAnn = *ite;
    switch (lAnn->getId())
    {
      case AnnotationInternal::zann_exclude_from_cache_key:
      case AnnotationInternal::zann_compare_with_deep_equal:
        //One or more integers
        if (!lAnn->getNumLiterals())
        {
          RAISE_ERROR(zerr::ZXQP0062_INVALID_ANNOTATION_LITERALS_NUMBER, loc,
              ERROR_PARAMS(
                  AnnotationInternal::lookup(lAnn->getId())->getStringValue(),
                  ZED(ZXQP0062_ONE_OR_MORE_LITERALS)));
        }
        for (csize i=0; i<lAnn->getNumLiterals(); ++i)
          checkLiteralType(lAnn, lAnn->getLiteral(i), store::XS_INTEGER, loc);
        break;
      default:
        break;
    }
  }
}

void AnnotationList::checkLiteralType(AnnotationInternal* ann, zorba::store::Item* literal,
    zorba::store::SchemaTypeCode type, const QueryLoc& loc) const
{
  if (literal->getTypeCode() != type)
  {
    std::ostringstream oss;
    oss << type;
    RAISE_ERROR(zerr::ZXQP0063_INVALID_ANNOTATION_LITERAL_TYPE, loc,
        ERROR_PARAMS(
            literal->getStringValue(),
            literal->getType()->getLocalName(),
            AnnotationInternal::lookup(ann->getId())->getStringValue(),
            oss.str()));
  }
}

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
