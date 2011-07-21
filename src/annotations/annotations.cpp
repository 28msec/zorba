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

#include <cmath>

#include "annotations/annotations.h"
#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "compiler/expression/expr.h"

#include "zorbaserialization/serialization_engine.h"

#include "diagnostics/assert.h"

#include "system/globalenv.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(AnnotationInternal)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationInternal)

SERIALIZABLE_CLASS_VERSIONS(AnnotationLiteral)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationLiteral)

SERIALIZABLE_CLASS_VERSIONS(AnnotationList)
END_SERIALIZABLE_CLASS_VERSIONS(AnnotationList);


/*******************************************************************************

********************************************************************************/
AnnotationInternal::AnnotationInternal(const store::Item_t& aExpandedQName)
  :
  theQName(aExpandedQName)
{
}


AnnotationInternal::AnnotationInternal(
  const store::Item_t& aExpandedQName,
  const std::vector<AnnotationLiteral_t>& aLiteralList)
  :
  theQName(aExpandedQName),
  theLiteralList(aLiteralList)
{
}


void AnnotationInternal::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theQName;
  ar & theLiteralList;
}


const store::Item* AnnotationInternal::getQName() const
{
  return theQName.getp();
}


unsigned int AnnotationInternal::getNumLiterals() const
{
  return (unsigned int)theLiteralList.size();
}


const AnnotationLiteral* AnnotationInternal::getLiteral(unsigned int index) const
{
  if (index < theLiteralList.size())
    return theLiteralList[index];
  else
    return NULL;
}


/*******************************************************************************

********************************************************************************/
void AnnotationLiteral::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theLiteral;
}


AnnotationLiteral::AnnotationLiteral(const store::Item_t& aLiteralValue)
  : theLiteral(aLiteralValue)
{
}


store::Item_t AnnotationLiteral::getLiteralItem() const
{
  return theLiteral;
}


AnnotationInternal* AnnotationList::getAnnotation(unsigned int index) const
{
  if (index < theAnnotationList.size())
    return theAnnotationList[index].getp();
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
void AnnotationList::push_back(
    const store::Item_t& aExpQName,
    const std::vector<rchandle<const_expr> >& aLiterals)
{
  std::vector<AnnotationLiteral_t> lLiterals;

  for (std::vector<rchandle<const_expr> >::const_iterator it = aLiterals.begin();
       it != aLiterals.end();
       ++it)
  {
    lLiterals.push_back(new AnnotationLiteral((*it)->get_val()));
  }

  theAnnotationList.push_back(new AnnotationInternal(aExpQName, lLiterals));
}


/*******************************************************************************

********************************************************************************/
bool AnnotationList::contains(const store::Item_t& aSearchQName) const
{
  if (aSearchQName.getp() == NULL)
    return false;

  // sequential search might not be the most efficient but
  // how many annotations might a function or variable have? 5?
  for (ListConstIter_t lIter = theAnnotationList.begin();
       lIter != theAnnotationList.end();
       ++lIter)
  {
    if ((*lIter)->getQName()->equals(aSearchQName))
      return true;
  }

  return false;
}


/*******************************************************************************
  Called from translator::end_visit(const AnnotationListParsenode& v, void*)
********************************************************************************/
void AnnotationList::checkConflictingDeclarations(const QueryLoc& loc) const
{
  static_context& lCtx = GENV_ROOT_STATIC_CONTEXT;

  // make sure we don't have more annotations then max 64 bit
  assert( static_cast<uint64_t>(StaticContextConsts::zann_end) <
          std::numeric_limits<uint64_t>::max() );

  RuleBitSet lCurrAnn;

  // mark and detect duplicates
  for (ListConstIter_t lIter = theAnnotationList.begin();
       lIter != theAnnotationList.end();
       ++lIter)
  {
    store::Item_t lQName = const_cast<store::Item*>((*lIter)->getQName());
    StaticContextConsts::annotations_t lAnn = lCtx.lookup_ann(lQName);

    // detect duplicate annotations
    if ( lCurrAnn.test( lAnn ) )
    {
        throw XQUERY_EXCEPTION(
            err::XQST0106,
            ERROR_PARAMS(
              lQName->getStringValue(),
              ZED(XQST0106_THE_SAME)
            ),
            ERROR_LOC(loc));
    }

    lCurrAnn.set( lAnn );
  }

  // check rules
  for ( std::vector<RuleBitSet>::const_iterator lIter = theRuleSet.begin();
        lIter != theRuleSet.end();
        ++lIter )
  {
    const RuleBitSet lCurrSet = *lIter;
    if ( ( lCurrAnn & lCurrSet ).count() >  1 )
    {
      // build error string to return set of conflicting annotations
      std::ostringstream lProblems;
      for ( size_t i = 0, j = 0; i < StaticContextConsts::zann_end; ++i )
      {
        if ( lCurrSet.test( i ) )
        {
          lProblems
            << lCtx.lookup_ann(
                static_cast<StaticContextConsts::annotations_t>(i)
              )->getStringValue()
            << ((j == lCurrSet.count() - 1) ? "" : ", ");
          ++j;
        }
      }
      throw XQUERY_EXCEPTION(
          err::XQST0106,
          ERROR_PARAMS(
            lProblems.str(),
            ZED(XQST0106_CONFLICTING)
          ),
          ERROR_LOC(loc));
    }
  }
}


void AnnotationList::createBuiltIn(static_context* aCtx)
{
  store::Item_t lTmp;

  //
  // W3C annotations
  //
  GENV_ITEMFACTORY->createQName(lTmp, static_context::W3C_FN_NS, "fn", "public");
  aCtx->add_ann(StaticContextConsts::fn_public, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, static_context::W3C_FN_NS, "fn", "private");
  aCtx->add_ann(StaticContextConsts::fn_private, lTmp);

  //
  // Zorba annotations - deterministic/nondeterministic
  //
  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "deterministic");
  aCtx->add_ann(StaticContextConsts::zann_deterministic, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "nondeterministic");
  aCtx->add_ann(StaticContextConsts::zann_nondeterministic, lTmp);

  //
  // Zorba annotations - xquery scripting
  //
  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "assignable");
  aCtx->add_ann(StaticContextConsts::zann_assignable, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "nonassignable");
  aCtx->add_ann(StaticContextConsts::zann_nonassignable, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "sequential");
  aCtx->add_ann(StaticContextConsts::zann_sequential, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "nonsequential");
  aCtx->add_ann(StaticContextConsts::zann_nonsequential, lTmp);

  //
  // Zorba annotations - misc
  //
  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "variadic");
  aCtx->add_ann(StaticContextConsts::zann_variadic, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "streamable");
  aCtx->add_ann(StaticContextConsts::zann_streamable, lTmp);

  //
  // Zorba annotations - xqddf
  //
  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "unique");
  aCtx->add_ann(StaticContextConsts::zann_unique, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "nonunique");
  aCtx->add_ann(StaticContextConsts::zann_nonunique, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "value-equality");
  aCtx->add_ann(StaticContextConsts::zann_value_equality, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "general-equality");
  aCtx->add_ann(StaticContextConsts::zann_general_equality, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "value-range");
  aCtx->add_ann(StaticContextConsts::zann_value_range, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "general-range");
  aCtx->add_ann(StaticContextConsts::zann_general_range, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "automatic");
  aCtx->add_ann(StaticContextConsts::zann_automatic, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "manual");
  aCtx->add_ann(StaticContextConsts::zann_manual, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "mutable");
  aCtx->add_ann(StaticContextConsts::zann_mutable, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "queue");
  aCtx->add_ann(StaticContextConsts::zann_queue, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "append-only");
  aCtx->add_ann(StaticContextConsts::zann_append_only, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "const");
  aCtx->add_ann(StaticContextConsts::zann_const, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "ordered");
  aCtx->add_ann(StaticContextConsts::zann_ordered, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "unordered");
  aCtx->add_ann(StaticContextConsts::zann_unordered, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "read-only-nodes");
  aCtx->add_ann(StaticContextConsts::zann_read_only_nodes, lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, ZORBA_ANNOTATIONS_NS, "", "mutable-nodes");
  aCtx->add_ann(StaticContextConsts::zann_mutable_nodes, lTmp);

  // create a set of rules to detect conflicts between annotations
#define ZANN(a) \
  ( 1 << static_cast<uint64_t>(StaticContextConsts:: a) )
  theRuleSet.push_back(
       ZANN(zann_unique) |
       ZANN(zann_nonunique)
    );
  theRuleSet.push_back(
      ZANN(zann_value_equality) |
      ZANN(zann_general_equality) |
      ZANN(zann_value_range) |
      ZANN(zann_general_range)
    );
  theRuleSet.push_back(
      ZANN(zann_automatic) |
      ZANN(zann_manual)
    );
  theRuleSet.push_back(
      ZANN(zann_mutable) |
      ZANN(zann_queue) |
      ZANN(zann_append_only) |
      ZANN(zann_const)
    );
  theRuleSet.push_back(
      ZANN(zann_ordered) |
      ZANN(zann_unordered)
    );
  theRuleSet.push_back(
      ZANN(zann_assignable) |
      ZANN(zann_nonassignable)
    );
  theRuleSet.push_back(
      ZANN(zann_deterministic) |
      ZANN(zann_nondeterministic)
    );
  theRuleSet.push_back(
      ZANN(zann_sequential) |
      ZANN(zann_nonsequential)
    );
  theRuleSet.push_back(
      ZANN(fn_private) |
      ZANN(fn_public)
    );
  theRuleSet.push_back(
      ZANN(zann_unordered) |
      ZANN(zann_queue)
    );
  theRuleSet.push_back(
      ZANN(zann_unordered) |
      ZANN(zann_append_only)
    );
  theRuleSet.push_back(
      ZANN(zann_queue) |
      ZANN(zann_append_only)
    );
  theRuleSet.push_back(
      ZANN(zann_read_only_nodes) |
      ZANN(zann_mutable_nodes)
    );
#undef ZANN
}

std::vector<AnnotationList::RuleBitSet> AnnotationList::theRuleSet;


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
