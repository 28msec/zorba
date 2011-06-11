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
AnnotationInternal::AnnotationInternal(
  const store::Item_t& aExpandedQName
)
  : theQName(aExpandedQName)
{
}


AnnotationInternal::AnnotationInternal(
  const store::Item_t& aExpandedQName,
  const std::vector<AnnotationLiteral_t>& aLiteralList
)
  : theQName(aExpandedQName),
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


const AnnotationLiteral*
AnnotationInternal::getLiteral(unsigned int index) const
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

AnnotationList::~AnnotationList()
{
}

void
AnnotationList::push_back(
    const store::Item_t& aExpQName,
    const std::vector<rchandle<const_expr> >& aLiterals
  )
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

bool
AnnotationList::contains(const store::Item_t& aSearchQName) const
{
  // sequential search might not be the most efficient but
  // how many annotations might a function or variable have? 5?
  for (ListConstIter_t lIter = theAnnotationList.begin();
       lIter != theAnnotationList.end();
       ++lIter)
  {
    if ((*lIter)->getQName()->equals(aSearchQName))
    {
      return true;
    }
  }
  return false;
}

void
AnnotationList::checkConflictingDeclarations(const QueryLoc& loc) const
{
  bool have_public_or_private = false;
  bool have_determ_or_nondeterm = false;
  bool have_assignable = false;
  bool have_sequential = false;
  bool have_updating = false;

  static_context& lCtx = GENV_ROOT_STATIC_CONTEXT;

  store::Item_t lPublic = lCtx.lookup_ann("public");
  store::Item_t lPrivate = lCtx.lookup_ann("private");
  store::Item_t lDeterministic = lCtx.lookup_ann("deterministic");
  store::Item_t lNonDeterministic = lCtx.lookup_ann("nondeterministic");
  store::Item_t lAssignable = lCtx.lookup_ann("assignable");
  store::Item_t lNonAssignable = lCtx.lookup_ann("nonassignable");
  store::Item_t lSequential = lCtx.lookup_ann("sequential");
  store::Item_t lNonSequential = lCtx.lookup_ann("nonsequential");
  store::Item_t lUpdating = lCtx.lookup_ann("updating");
  store::Item_t lNonUpdating = lCtx.lookup_ann("nonupdating");

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
    else if (lQName->equals(lUpdating) ||
             lQName->equals(lNonUpdating))
    {
      if (have_updating)
        throw XQUERY_EXCEPTION(
            err::XQST0106,
            ERROR_PARAMS(lQName->getStringValue()),
            ERROR_LOC(loc));

      have_updating = true;
    }
  }
}

void AnnotationList::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theAnnotationList;
}

void AnnotationList::createBuiltIn(static_context* aCtx)
{
  store::Item_t lTmp;

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "public");
  aCtx->add_ann("public", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "private");
  aCtx->add_ann("private", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "deterministic");
  aCtx->add_ann("deterministic", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "nondeterministic");
  aCtx->add_ann("nondeterministic", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "assignable");
  aCtx->add_ann("assignable", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "nonassignable");
  aCtx->add_ann("nonassignable", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "sequential");
  aCtx->add_ann("sequential", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "nonsequential");
  aCtx->add_ann("nonsequential", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "updating");
  aCtx->add_ann("updating", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "nonupdating");
  aCtx->add_ann("nonupdating", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "nonupdating");
  aCtx->add_ann("nonupdating", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "assignable");
  aCtx->add_ann("assignable", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "fn", "nonassignable");
  aCtx->add_ann("nonassignable", lTmp);

  GENV_ITEMFACTORY->createQName(
      lTmp, static_context::W3C_FN_NS, "", "variadic");
  aCtx->add_ann("variadic", lTmp);
}

} /* namespace zorba */
