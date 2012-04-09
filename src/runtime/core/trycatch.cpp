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

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"
#include "diagnostics/user_exception.h"

#include "runtime/core/trycatch.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/core/var_iterators.h"
#include "runtime/util/item_iterator.h"

#include "store/api/store.h"
#include "store/api/temp_seq.h"

#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "types/node_test.h"
#include "types/root_typemanager.h"
#include "zorbamisc/ns_consts.h"


namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(TryCatchIterator::CatchClause)

SERIALIZABLE_CLASS_VERSIONS(TryCatchIterator)


TryCatchIteratorState::TryCatchIteratorState()
  : 
  theTempIterator(NULL),
  theCatchIterator(NULL)
{
}


TryCatchIteratorState::~TryCatchIteratorState()
{
  if (theTempIterator != NULL) 
  {
    theTempIterator->close();
    theTempIterator = NULL;
  }

  std::vector<store::Iterator_t>::iterator lIters = theErrorIters.begin();
  std::vector<store::Iterator_t>::iterator lItersEnd = theErrorIters.end();
  for (; lIters != lItersEnd; ++lIters) {
    (*lIters)->close();
  }
}


void
TryCatchIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
}


void
TryCatchIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);
  if ( theTargetSequence )
    theTargetSequence->purge(); // release the target sequence
  if (theTempIterator != NULL) {
    theTempIterator->close();
    theTempIterator = NULL;
  }
  theCatchIterator = NULL;

  std::vector<store::Iterator_t>::iterator lIters = theErrorIters.begin();
  std::vector<store::Iterator_t>::iterator lItersEnd = theErrorIters.end();
  for (; lIters != lItersEnd; ++lIters) {
    (*lIters)->close();
  }

}


TryCatchIterator::CatchClause::~CatchClause()
{
}


TryCatchIterator::TryCatchIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& aBlock,
    std::vector<CatchClause>& aCatchClauses)
  :
  UnaryBaseIterator<TryCatchIterator, TryCatchIteratorState> (sctx, loc, aBlock),
  theCatchClauses(aCatchClauses)
{
}


TryCatchIterator::~TryCatchIterator()
{
}


void TryCatchIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<TryCatchIteratorState>::createState(planState,
                                                      theStateOffset,
                                                      offset);

  StateTraitsImpl<TryCatchIteratorState>::initState(planState, theStateOffset);

  theChild->open(planState, offset);

  std::vector<TryCatchIterator::CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::const_iterator lEnd = theCatchClauses.end();

  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->open(planState, offset);
  }

}

uint32_t
TryCatchIterator::getStateSizeOfSubtree() const
{
	uint32_t size = theChild->getStateSizeOfSubtree() + getStateSize();

  std::vector<CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<CatchClause>::const_iterator lEnd = theCatchClauses.end();
  for (; lIter!= lEnd; ++lIter )
  {
		size += ( *lIter ).catch_expr->getStateSizeOfSubtree();
	}

  return size;
}


// check if/which catch matches and bind the state's catch iterator to the matching catch clause
bool
TryCatchIterator::matchedCatch(
    ZorbaException const& e,
    TryCatchIteratorState* state,
    PlanState& planState) const
{
  std::vector<CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<CatchClause>::const_iterator lEnd = theCatchClauses.end();
  for (; lIter!= lEnd; ++lIter )
  {
    const CatchClause& cc = *lIter;
    const std::vector<NodeNameTest_t>& nts = cc.node_names;
    std::vector<NodeNameTest_t>::const_iterator i;
    for(i = nts.begin(); i != nts.end(); ++i)
    {
      const NodeNameTest& nt = **i;
			diagnostic::QName const &err_name = e.diagnostic().qname();
      if (nt.matches(err_name.localname(), err_name.ns()))
      {
        state->theCatchIterator = cc.catch_expr;
        bindErrorVars(e, &cc, planState);
        return true;
      }
    }
  }
  return false;
}

/**
 * <zerr:stack>
 *   <zerr:entry>
 *     <zerr:function name="foo" arity="0"/>
 *     <zerr:location name="blub.txt" line-begin="0" line-end="0"
 *       column-begin="0" column-end="0"/>
 *   </zerr:entry>
 * </zerr:stack>
 */
store::Item_t
TryCatchIterator::getStackTrace(const XQueryStackTrace& s) const
{
  store::NsBindings lBindings;
  zstring lBaseURI        = ZORBA_ERR_NS;
  store::Item_t lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;

  store::Item_t lStackQName, lEntryQName, lFNQName, lLocationQName;
  store::Item_t lNameQName, lNSQName, lLocalQName;
  store::Item_t lArityQName, lLineBeginQName, lLineEndQName;
  store::Item_t lColumnBeginQName, lColumnEndQName;

  GENV_ITEMFACTORY->createQName(lStackQName, ZORBA_ERR_NS, "", "stack");
  GENV_ITEMFACTORY->createQName(lEntryQName, ZORBA_ERR_NS, "", "entry");
  GENV_ITEMFACTORY->createQName(lFNQName, ZORBA_ERR_NS, "", "function");
  GENV_ITEMFACTORY->createQName(lLocationQName, ZORBA_ERR_NS, "", "location");
  GENV_ITEMFACTORY->createQName(lNameQName, "", "", "name");
  GENV_ITEMFACTORY->createQName(lNSQName, "", "", "namespace");
  GENV_ITEMFACTORY->createQName(lLocalQName, "", "", "localname");
  GENV_ITEMFACTORY->createQName(lArityQName, "", "", "arity");
  GENV_ITEMFACTORY->createQName(lLineBeginQName, "", "", "line-begin");
  GENV_ITEMFACTORY->createQName(lLineEndQName, "", "", "line-end");
  GENV_ITEMFACTORY->createQName(lColumnBeginQName, "", "", "column-begin");
  GENV_ITEMFACTORY->createQName(lColumnEndQName, "", "", "column-end");

  store::Item_t lResult;
  GENV_ITEMFACTORY->createElementNode(
      lResult, NULL, lStackQName, lTypeName,
      true, false, lBindings, lBaseURI);

  for (XQueryStackTrace::const_iterator lIter = s.begin();
       lIter != s.end(); ++lIter)
  {
    GENV_ITEMFACTORY->createQName(lStackQName, ZORBA_ERR_NS, "", "stack");
    GENV_ITEMFACTORY->createQName(lEntryQName, ZORBA_ERR_NS, "", "entry");
    GENV_ITEMFACTORY->createQName(lFNQName, ZORBA_ERR_NS, "", "function");
    GENV_ITEMFACTORY->createQName(lLocationQName, ZORBA_ERR_NS, "", "location");
    GENV_ITEMFACTORY->createQName(lNameQName, "", "", "name");
    GENV_ITEMFACTORY->createQName(lNSQName, "", "", "namespace");
    GENV_ITEMFACTORY->createQName(lLocalQName, "", "", "localname");
    GENV_ITEMFACTORY->createQName(lArityQName, "", "", "arity");
    GENV_ITEMFACTORY->createQName(lLineBeginQName, "", "", "line-begin");
    GENV_ITEMFACTORY->createQName(lLineEndQName, "", "", "line-end");
    GENV_ITEMFACTORY->createQName(lColumnBeginQName, "", "", "column-begin");
    GENV_ITEMFACTORY->createQName(lColumnEndQName, "", "", "column-end");
    store::Item_t lEntry;

    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createElementNode(
        lEntry, lResult, lEntryQName, lTypeName,
        true, false, lBindings, lBaseURI);

    store::Item_t lFunction, lLocation;

    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createElementNode(
        lFunction, lEntry, lFNQName, lTypeName,
        true, false, lBindings, lBaseURI);

    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createElementNode(
        lLocation, lEntry, lLocationQName, lTypeName,
        true, false, lBindings, lBaseURI);

    store::Item_t lTmpAttr;
    store::Item_t lTmpValue;

    // function namespace
    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    zstring lTmpString = lIter->getFnName().ns();
    GENV_ITEMFACTORY->createString( lTmpValue, lTmpString );
    GENV_ITEMFACTORY->createAttributeNode(
        lTmpAttr, lFunction.getp(), lNSQName, lTypeName,
        lTmpValue);

    // function localname
    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    lTmpString = lIter->getFnName().localname();
    GENV_ITEMFACTORY->createString( lTmpValue, lTmpString );
    GENV_ITEMFACTORY->createAttributeNode(
        lTmpAttr, lFunction.getp(), lLocalQName, lTypeName,
        lTmpValue);

    // function arity
    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createInteger( lTmpValue, lIter->getFnArity() );
    GENV_ITEMFACTORY->createAttributeNode(
        lTmpAttr, lFunction.getp(), lArityQName, lTypeName,
        lTmpValue);

    // location name
    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    lTmpString = lIter->getFileName().c_str();
    GENV_ITEMFACTORY->createString( lTmpValue, lTmpString );
    GENV_ITEMFACTORY->createAttributeNode(
        lTmpAttr, lLocation.getp(), lNameQName, lTypeName,
        lTmpValue);

    // location line begin
    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createInteger( lTmpValue, lIter->getLine() );
    GENV_ITEMFACTORY->createAttributeNode(
        lTmpAttr, lLocation.getp(), lLineBeginQName, lTypeName,
        lTmpValue);

    // location line end
    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createInteger( lTmpValue, lIter->getLineEnd() );
    GENV_ITEMFACTORY->createAttributeNode(
        lTmpAttr, lLocation.getp(), lLineEndQName, lTypeName,
        lTmpValue);

    // location column begin
    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createInteger( lTmpValue, lIter->getColumn() );
    GENV_ITEMFACTORY->createAttributeNode(
        lTmpAttr, lLocation.getp(), lColumnBeginQName, lTypeName,
        lTmpValue);

    // location column end
    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
    GENV_ITEMFACTORY->createInteger( lTmpValue, lIter->getColumnEnd() );
    GENV_ITEMFACTORY->createAttributeNode(
        lTmpAttr, lLocation.getp(), lColumnEndQName, lTypeName,
        lTmpValue);

  }
  return lResult;
}

void
TryCatchIterator::bindErrorVars(
    ZorbaException const& e,
    const CatchClause* clause,
    PlanState& planState) const
{
  TryCatchIteratorState* state =
    StateTraitsImpl<TryCatchIteratorState>::getState(planState, theStateOffset);

  typedef std::vector<LetVarIter_t>::const_iterator LetVarConstIter;

  for (CatchClause::VarMap_t::const_iterator lIter = clause->vars.begin();
       lIter != clause->vars.end();
       ++lIter)
  {
    switch (lIter->first)
    {
      case CatchClause::err_code:
      {
        LetVarConstIter lErrorCodeVarIter = lIter->second.begin();
        LetVarConstIter lErrorCodeVarIterEnd = lIter->second.end();
        // bind the error code (always)
        store::Item_t lErrorCodeItem;
	      diagnostic::QName const &err_name = e.diagnostic().qname();
        GENV_ITEMFACTORY->createQName(
            lErrorCodeItem,
            err_name.ns(),
            err_name.prefix(),
            err_name.localname());

        for ( ; lErrorCodeVarIter != lErrorCodeVarIterEnd; lErrorCodeVarIter++ )
        {
          store::Iterator_t lErrorCodeIter = new ItemIterator(lErrorCodeItem);
          lErrorCodeIter->open();
          state->theErrorIters.push_back(lErrorCodeIter);
          (*lErrorCodeVarIter)->bind(lErrorCodeIter, planState);
        }
      }
      break;
      case CatchClause::err_desc:
      {
        LetVarConstIter lErrorDescVarIter = lIter->second.begin();
        LetVarConstIter lErrorDescVarIterEnd = lIter->second.end();
        for ( ; lErrorDescVarIter != lErrorDescVarIterEnd; lErrorDescVarIter++ )
        {
          // bind the description or the empty sequence
          store::Iterator_t lErrorDescIter;
	      	char const *const what = e.what();
          if (what && *what)
          {
            zstring errDescr = what;
            store::Item_t errDescItem;
            GENV_ITEMFACTORY->createString(errDescItem, errDescr);
            lErrorDescIter = new ItemIterator(errDescItem);
          }
          else
          {
            lErrorDescIter = new ItemIterator();
          }
          lErrorDescIter->open();
          state->theErrorIters.push_back(lErrorDescIter);
          (*lErrorDescVarIter)->bind(lErrorDescIter, planState);
        }
      }
      break;
      case CatchClause::err_value:
      {
        LetVarConstIter lErrorObjVarIter = lIter->second.begin();
        LetVarConstIter lErrorObjVarIterEnd = lIter->second.end();
	      std::vector<store::Item_t> eObjs;

	      if ( UserException const *ue = dynamic_cast<UserException const*>( &e ) ) {
	      	UserException::error_object_type const &eo = ue->error_object();
	      	if ( !eo.empty() )
	      		convert_error_object( eo, &eObjs );
	      }

        for ( ; lErrorObjVarIter != lErrorObjVarIterEnd; lErrorObjVarIter++ ) {
          store::Iterator_t lErrorObjIter = eObjs.empty() ?
	      		new ItemIterator() : new ItemIterator(eObjs);
          lErrorObjIter->open();
          state->theErrorIters.push_back(lErrorObjIter);
          (*lErrorObjVarIter)->bind(lErrorObjIter, planState);
        }
      }
      break;
      case CatchClause::err_module:
      {
        LetVarConstIter lErrorModuleVarIter = lIter->second.begin();
        LetVarConstIter lErrorModuleVarIterEnd = lIter->second.end();

        for ( ; lErrorModuleVarIter != lErrorModuleVarIterEnd; lErrorModuleVarIter++ )
        {
          store::Iterator_t lErrorModuleIter;

          XQueryException const *ue;
	        if ( ( ue = dynamic_cast<XQueryException const*>( &e ) ) &&
               ue->has_source() ) {
            store::Item_t lErrorModuleItem;
            zstring lModule = ue->source_uri();
            GENV_ITEMFACTORY->createString(lErrorModuleItem, lModule);
            lErrorModuleIter = new ItemIterator(lErrorModuleItem);
	        }
          else
          {
            lErrorModuleIter = new ItemIterator();
          }
          lErrorModuleIter->open();
          state->theErrorIters.push_back(lErrorModuleIter);
          (*lErrorModuleVarIter)->bind(lErrorModuleIter, planState);
        }
      }
      break;
      case CatchClause::err_line_no:
      {
        LetVarConstIter lErrorLineVarIter = lIter->second.begin();
        LetVarConstIter lErrorLineVarIterEnd = lIter->second.end();


        for ( ; lErrorLineVarIter != lErrorLineVarIterEnd; lErrorLineVarIter++ )
        {
          store::Iterator_t lErrorLineIter;

          XQueryException const *ue;
	        if ( ( ue = dynamic_cast<XQueryException const*>( &e ) ) &&
               ue->has_source() ) {
            store::Item_t lErrorLineItem;
            GENV_ITEMFACTORY->createInteger(lErrorLineItem, ue->source_line());
            lErrorLineIter = new ItemIterator(lErrorLineItem);
	        }
          else
          {
            lErrorLineIter = new ItemIterator();
          }
          lErrorLineIter->open();
          state->theErrorIters.push_back(lErrorLineIter);
          (*lErrorLineVarIter)->bind(lErrorLineIter, planState);
        }
      }
      break;
      case CatchClause::err_column_no:
      {
        LetVarConstIter lErrorColumnVarIter = lIter->second.begin();
        LetVarConstIter lErrorColumnVarIterEnd = lIter->second.end();

        for ( ; lErrorColumnVarIter != lErrorColumnVarIterEnd; lErrorColumnVarIter++ )
        {
          store::Iterator_t lErrorColumnIter;

          XQueryException const *ue;
	        if ( ( ue = dynamic_cast<XQueryException const*>( &e ) ) &&
               ue->has_source() ) {
            store::Item_t lErrorColumnItem;
            GENV_ITEMFACTORY->createInteger(lErrorColumnItem, ue->source_column());
            lErrorColumnIter = new ItemIterator(lErrorColumnItem);
	        }
          else
          {
            lErrorColumnIter = new ItemIterator();
          }
          lErrorColumnIter->open();
          state->theErrorIters.push_back(lErrorColumnIter);
          (*lErrorColumnVarIter)->bind(lErrorColumnIter, planState);
        }
      break;
      }
      case CatchClause::zerr_stack_trace:
      {
        LetVarConstIter lStackTraceVarIter = lIter->second.begin();
        LetVarConstIter lStackTraceVarIterEnd = lIter->second.end();
        for ( ; lStackTraceVarIter != lStackTraceVarIterEnd; lStackTraceVarIter++ )
        {
          store::Iterator_t lStackTraceIter;

          XQueryException const *ue;
	        if ( ( ue = dynamic_cast<XQueryException const*>( &e ) ) &&
              !ue->query_trace().empty() ) 
          {
            lStackTraceIter = new ItemIterator(
                getStackTrace( ue->query_trace() ) );
          }
          else
          {
            lStackTraceIter = new ItemIterator();
          }
          lStackTraceIter->open();
          state->theErrorIters.push_back(lStackTraceIter);
          (*lStackTraceVarIter)->bind(lStackTraceIter, planState);
        }
      break;
      }
      default: ZORBA_ASSERT(false);
    }
  }
}

bool
TryCatchIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{

  store::Item_t item; // each item that will be returned

  store::Iterator_t lIterator;

  TryCatchIteratorState* state;
  DEFAULT_STACK_INIT(TryCatchIteratorState, state, planState);

  try
  {
    lIterator = new PlanIteratorWrapper(theChild, planState);
    state->theTargetSequence = GENV_STORE.createTempSeq(lIterator, false);
    state->theTempIterator = state->theTargetSequence->getIterator();
    state->theTempIterator->open();
  }
  catch (ZorbaException const& e)
  {
    if (!matchedCatch(e, state, planState))
    {
      throw;
    }
  }

  if (state->theTempIterator != NULL)
  {
    ZORBA_ASSERT(state->theCatchIterator == NULL);
    while (state->theTempIterator->next(result))
    {
      STACK_PUSH( true, state );
    }
  }
  else if (state->theCatchIterator != NULL)
  {
    ZORBA_ASSERT(state->theTempIterator == NULL);
    while(consumeNext(result, state->theCatchIterator.getp(), planState))
    {
      STACK_PUSH(true, state);
    }
  }
  else
  {
    ZORBA_ASSERT(false);
  }

  STACK_END (state);
}


void
TryCatchIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<TryCatchIteratorState>::reset(planState, theStateOffset);

  theChild->reset(planState);

  std::vector<TryCatchIterator::CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::const_iterator lEnd = theCatchClauses.end();

  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->reset(planState);
  }

}

void
TryCatchIterator::closeImpl(PlanState& planState)
{
  theChild->close(planState);

  std::vector<TryCatchIterator::CatchClause>::iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::iterator lEnd = theCatchClauses.end();

  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->close(planState);
  }

  StateTraitsImpl<TryCatchIteratorState>::destroyState(planState, theStateOffset);
}

void TryCatchIterator::accept(PlanIterVisitor &v) const {
  v.beginVisit(*this);
  theChild->accept ( v );
  std::vector<TryCatchIterator::CatchClause>::const_iterator lIter = theCatchClauses.begin();
  std::vector<TryCatchIterator::CatchClause>::const_iterator lEnd = theCatchClauses.end();
  for ( ; lIter != lEnd; ++lIter ) {
    ( *lIter ).catch_expr->accept ( v );
  }
  v.endVisit(*this);
}

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
