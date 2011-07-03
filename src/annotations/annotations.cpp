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
#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"

#include "context/static_context.h"
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
  bool have_public_or_private = false;
  bool have_determ_or_nondeterm = false;
  bool have_assignable = false;
  bool have_sequential = false;

  static_context& lCtx = GENV_ROOT_STATIC_CONTEXT;

  store::Item_t lPublic = lCtx.lookup_ann("public");
  store::Item_t lPrivate = lCtx.lookup_ann("private");
  store::Item_t lDeterministic = lCtx.lookup_ann("deterministic");
  store::Item_t lNonDeterministic = lCtx.lookup_ann("nondeterministic");
  store::Item_t lAssignable = lCtx.lookup_ann("assignable");
  store::Item_t lNonAssignable = lCtx.lookup_ann("nonassignable");
  store::Item_t lSequential = lCtx.lookup_ann("sequential");
  store::Item_t lNonSequential = lCtx.lookup_ann("nonsequential");

  for (ListConstIter_t lIter = theAnnotationList.begin();
       lIter != theAnnotationList.end();
       ++lIter)
  {
    const store::Item* lQName = (*lIter)->getQName();

    if (lQName->equals(lPublic) || lQName->equals(lPrivate))
    {
      if (have_public_or_private)
        throw XQUERY_EXCEPTION(
            err::XQST0106,
            ERROR_PARAMS(lQName->getStringValue()),
            ERROR_LOC(loc));

      have_public_or_private = true;
    }
    else if (lQName->equals(lDeterministic) ||
             lQName->equals(lNonDeterministic))
    {
      if (have_determ_or_nondeterm)
        throw XQUERY_EXCEPTION(
            err::XQST0106,
            ERROR_PARAMS(lQName->getStringValue()),
            ERROR_LOC(loc));

      have_determ_or_nondeterm = true;
    }
    else if (lQName->equals(lAssignable) ||
             lQName->equals(lNonAssignable))
    {
      if (have_assignable)
        throw XQUERY_EXCEPTION(
            err::XQST0106,
            ERROR_PARAMS(lQName->getStringValue()),
            ERROR_LOC(loc));

      have_assignable = true;
    }
    else if (lQName->equals(lSequential) ||
             lQName->equals(lNonSequential))
    {
      if (have_sequential)
        throw XQUERY_EXCEPTION(
            err::XQST0106,
            ERROR_PARAMS(lQName->getStringValue()),
            ERROR_LOC(loc));

      have_sequential = true;
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
  aCtx->add_ann("public", lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, static_context::W3C_FN_NS, "fn", "private");
  aCtx->add_ann("private", lTmp);

  //
  // Zorba annotations - deterministic/nondeterministic
  //
  GENV_ITEMFACTORY->createQName(lTmp, "http://www.zorba-xquery.com/annotations", "", "deterministic");
  aCtx->add_ann("deterministic", lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, "http://www.zorba-xquery.com/annotations", "", "nondeterministic");
  aCtx->add_ann("nondeterministic", lTmp);

  //
  // Zorba annotations - xquery scripting
  //
  GENV_ITEMFACTORY->createQName(lTmp, "http://www.zorba-xquery.com/annotations", "", "assignable");
  aCtx->add_ann("assignable", lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, "http://www.zorba-xquery.com/annotations", "", "nonassignable");
  aCtx->add_ann("nonassignable", lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, "http://www.zorba-xquery.com/annotations", "", "sequential");
  aCtx->add_ann("sequential", lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, "http://www.zorba-xquery.com/annotations", "", "nonsequential");
  aCtx->add_ann("nonsequential", lTmp);

  //
  // Zorba annotations - misc
  //
  GENV_ITEMFACTORY->createQName(lTmp, "http://www.zorba-xquery.com/annotations", "", "variadic");
  aCtx->add_ann("variadic", lTmp);

  GENV_ITEMFACTORY->createQName(lTmp, "http://www.zorba-xquery.com/annotations", "", "streamable");
  aCtx->add_ann("streamable", lTmp);
}

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
