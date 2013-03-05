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

// This include needs to be kept in order to make sure the
// auto_ptr<dynamic_context> manages to dealocate the
// dynamic_context object.
#include "context/dynamic_context.h"

#include "runtime/function_item/function_item.h"
#include "runtime/core/fncall_iterator.h"
#include "runtime/base/plan_iterator.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/expr_manager.h"

#include "functions/signature.h"
#include "functions/udf.h"

#include "store/api/temp_seq.h"

#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"

// TODO: delete, debugging purposes
#include "runtime/visitors/printer_visitor_api.h"
#include "runtime/visitors/iterprinter.h"




namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(DynamicFunctionInfo)

SERIALIZABLE_CLASS_VERSIONS(FunctionItem)

SERIALIZABLE_CLASS_VERSIONS(DynamicFunctionIterator)


/*******************************************************************************

********************************************************************************/
DynamicFunctionInfo::DynamicFunctionInfo(// CompilerCB *ccb,
                                         static_context* closureSctx,
                                         const QueryLoc& loc,
                                         function* func,
                                         store::Item_t qname,
                                         uint32_t arity,
                                         bool isInline,
                                         bool needsContextItem)
  :
//  theCCB(ccb),
  theMustDeleteCCB(false),
  theClosureSctx(closureSctx),
  theLoc(loc),
  theFunction(func),
  theQName(qname),
  theArity(arity),
  theIsInline(isInline),
  theNeedsContextItem(needsContextItem)
{
//  std::cerr << "--> created DynamicFunctionInfo: " << this << " func: " << theFunction.getp() << " counter: " << (theFunction.getp()? theFunction->getRefCount() : 0) << std::endl;
}


DynamicFunctionInfo::DynamicFunctionInfo(::zorba::serialization::Archiver& ar)
{
//  std::cerr << "--> created DynamicFunctionInfo: " << this << " func: " << theFunction.getp() << " counter: " << (theFunction.getp()? theFunction->getRefCount() : 0) << std::endl;
}

DynamicFunctionInfo::~DynamicFunctionInfo()
{
  if (theMustDeleteCCB)
    delete theCCB;
//  std::cerr << "--> deleted ~DynamicFunctionInfo: " << this << " func: " << theFunction.getp() << " counter: " << (theFunction.getp()? theFunction->getRefCount() : 0) << std::endl;
}


void DynamicFunctionInfo::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theCCB;
  ar & theMustDeleteCCB;
  ar & theClosureSctx;
  ar & theLoc;
  ar & theFunction;
  ar & theQName;
  ar & theArity;
  ar & theIsInline;
  ar & theNeedsContextItem;

  // ar & theScopedVarsValues;
  // ar & theSubstVarsValues;
  ar & theScopedVarsNames;
  ar & theIsGlobalVar;
  ar & theVarId;

  ar & theScopedVarsIterators;

  if (ar.is_serializing_out())
  {
    uint32_t planStateSize;
    (void)static_cast<user_function*>(theFunction.getp())->getPlan(planStateSize);
  }
}


void DynamicFunctionInfo::add_variable(expr* var, var_expr* substVar, const store::Item_t& name, int isGlobal)
{
  theScopedVarsValues.push_back(var);
  theSubstVarsValues.push_back(substVar);
  theScopedVarsNames.push_back(name);
  theIsGlobalVar.push_back(isGlobal);
  theVarId.push_back(0);
}

/*******************************************************************************

********************************************************************************/
FunctionItem::FunctionItem(::zorba::serialization::Archiver& ar)
  :
  store::Item(store::Item::FUNCTION)
{
}

FunctionItem::FunctionItem(const DynamicFunctionInfo_t& dynamicFunctionInfo,
                           dynamic_context* dctx)
  :
  store::Item(store::Item::FUNCTION),
  theDynamicFunctionInfo(dynamicFunctionInfo),
  theArity(dynamicFunctionInfo->theArity),
  theClosureDctx(dctx)
{
  assert(theDynamicFunctionInfo->theFunction->isUdf());
  theArgumentsValues.resize(theDynamicFunctionInfo->theArity);
}

void FunctionItem::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theDynamicFunctionInfo;
  ar & theArity;
  ar & theArgumentsValues;
}


const store::Item_t FunctionItem::getFunctionName() const
{
  return theDynamicFunctionInfo->theQName;
}


uint32_t FunctionItem::getArity() const
{
  return theArity;
}


uint32_t FunctionItem::getStartArity() const
{
  return theDynamicFunctionInfo->theArity;
}


const signature& FunctionItem::getSignature() const
{
  return theDynamicFunctionInfo->theFunction->getSignature();
}


const std::vector<PlanIter_t>& FunctionItem::getArgumentsValues() const
{
  return theArgumentsValues;
}


bool FunctionItem::isArgumentApplied(unsigned int pos) const
{
  assert(pos < theArgumentsValues.size());
  return (theArgumentsValues[pos].getp() != NULL);
}


void FunctionItem::setArgumentValue(unsigned int pos, const PlanIter_t& value)
{
  theArity--;

  // find the pos-th NULL value and fill it
  for (unsigned int i=0; i<theArgumentsValues.size(); i++)
    if (theArgumentsValues[i] == NULL)
    {
      if (pos == 0)
      {
        theArgumentsValues[i] = value;
        return;
      }
      else
        pos--;
    }

  assert(false);
}

PlanIter_t FunctionItem::getImplementation(const std::vector<PlanIter_t>& dynChildren, CompilerCB* ccb)
{
  std::vector<PlanIter_t> args;
  args.resize(theArgumentsValues.size());

  std::vector<PlanIter_t>::iterator argsIte = args.begin();
  std::vector<PlanIter_t>::iterator ite = theArgumentsValues.begin();
  std::vector<PlanIter_t>::const_iterator ite2 = dynChildren.begin();
  ++ite2; // skip the first child because it's the function item

  for( ; argsIte != args.end(); ++argsIte, ++ite)
  {
    if (*ite != NULL)
    {
      *argsIte = *ite;
      static_cast<PlanStateIteratorWrapper*>(ite->getp())->reset();
    }
    else
    {
      *argsIte = *ite2;
      ++ite2;
    }
  }

  if (theDynamicFunctionInfo->theCCB != NULL)
    ccb = theDynamicFunctionInfo->theCCB;

  expr* dummy = ccb->theEM->create_function_item_expr(NULL, NULL, theDynamicFunctionInfo->theLoc, NULL, false, false);
  
  PlanIter_t udfCallIterator =
      theDynamicFunctionInfo->theFunction->codegen(ccb,
                                                   theDynamicFunctionInfo->theClosureSctx,
                                                   theDynamicFunctionInfo->theLoc,
                                                   args,
                                                   *dummy);
      
  /* TODO: remove this code and also clean-up the code in item_iterator.cpp
  PlanIter_t udfCallIterator =
      theDynamicFunctionInfo->theFunction->codegen(theCCB.get(),
                                                   theCCB->theRootSctx,
                                                   theDynamicFunctionInfo->theLoc,
                                                   args,
                                                   *dummy);
  */

  /*
  std::cerr << "Iterator tree for dynamic function call:\n";
  XMLIterPrinter vp(std::cerr);
  print_iter_plan(vp, udfCallIterator);
  std::cerr << std::endl;
  */

  UDFunctionCallIterator* udfIter = static_cast<UDFunctionCallIterator*>(udfCallIterator.getp());
  udfIter->setDynamic();
  udfIter->setFunctionItem(this);
  return udfCallIterator;
}


zstring FunctionItem::show() const
{
  std::ostringstream lRes;
  lRes << getFunctionName()->getStringValue();
  if (!isInline())
    lRes << "#" << getArity() << " (" << theDynamicFunctionInfo->theLoc << ")";
  return lRes.str();
}


/*******************************************************************************

********************************************************************************/
void DynamicFunctionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (NaryBaseIterator<DynamicFunctionIterator, PlanIteratorState>*)this);
  ar & theDynamicFunctionInfo;
}


/*******************************************************************************

********************************************************************************/
DynamicFunctionIterator::DynamicFunctionIterator(
      static_context* sctx,
      const QueryLoc& loc,
      DynamicFunctionInfo* fnInfo)
  :
  NaryBaseIterator<DynamicFunctionIterator, PlanIteratorState>(sctx, loc, fnInfo->theScopedVarsIterators),
  theDynamicFunctionInfo(fnInfo)
{
//  std::cerr << "--> created DynamicFunctionIterator: " << this // << " id: " << getId()
//            <<  " with DynamicFunctionInfo: " << theDynamicFunctionInfo << " counter: " << (theDynamicFunctionInfo.getp() ? theDynamicFunctionInfo->getRefCount() : 0) << std::endl;
}

DynamicFunctionIterator::~DynamicFunctionIterator()
{
//  std::cerr << "--> deleted ~DynamicFunctionIterator: " << this // << " id: " << getId()
//            << " with DynamicFunctionInfo: " << theDynamicFunctionInfo << " counter: " << (theDynamicFunctionInfo.getp() ? theDynamicFunctionInfo->getRefCount() : 0) << std::endl;
}

bool DynamicFunctionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

//  std::cerr << "--> DynamicFunctionIterator(): runtime theSctx: " << theSctx->toString() << std::endl;
//  std::cerr << "--> DynamicFunctionIterator(): evalSctx: " << theDynamicFunctionInfo->theSctx->toString() << std::endl;
//  std::cerr << "--> DynamicFunctionIterator(): importSctx: " << theDynamicFunctionInfo->theImportSctx->toString() << std::endl;

  // This portion is taken from the eval iterator
  {
    // Create the "import" sctx. The importOuterEnv() method (called below) will
    // register into the importSctx (a) the outer vars of the eval query and (b)
    // the expression-level ns bindings of the outer query at the place where
    // the eval call appears at.
//    static_context* importSctx = theSctx->create_child_context();

    // Create the root sctx for the eval query
    // static_context* evalSctx = importSctx->create_child_context();

    // Create the ccb for the eval query

    // std::auto_ptr<CompilerCB> evalCCB;
    // evalCCB.reset(new CompilerCB(*planState.theCompilerCB));
    // evalCCB->theRootSctx = evalSctx;
    // (evalCCB->theSctxMap)[1] = evalSctx;


    // Create the dynamic context for the eval query
    std::auto_ptr<dynamic_context> evalDctx;
    evalDctx.reset(new dynamic_context(planState.theGlobalDynCtx));

    // Import the outer environment.
    // importOuterEnv(planState, evalCCB.get(), importSctx, evalDctx.get());
    importOuterEnv(planState, theDynamicFunctionInfo->theCCB, theDynamicFunctionInfo->theClosureSctx, evalDctx.get());

    // std::cerr << "--> after impotOuterEnv(): evalDctx: " << evalDctx->toString() << std::endl;

    // Set the values for the (explicit) external vars of the eval query
    // setExternalVariables(theDynamicFunctionInfo->theCCB, importSctx, evalDctx.get());
//    setExternalVariables(theDynamicFunctionInfo->theCCB, theDynamicFunctionInfo->theClosureSctx, evalDctx.get());

    /*
    std::cerr << "--> " << toString() << ": creating function item with params: " << std::endl;
    for (csize i=0; i<theChildren.size(); i++)
    {
      std::cerr << "    "
          << (theDynamicFunctionInfo->theScopedVarsNames[i].getp() ?
              theDynamicFunctionInfo->theScopedVarsNames[i]->show() : "")
          // << ": " << (varsValues[i].getp() ? varsValues[i]->toString() : "NULL")
          << std::endl;
    }
    */

    // std::cerr << "--> the body before: " << static_cast<user_function*>(theDynamicFunctionInfo->theFunction.getp())->getBody()->toString() << std::endl;

    result = new FunctionItem(theDynamicFunctionInfo, evalDctx.release());
  }

  STACK_PUSH ( result != NULL, state );
  STACK_END (state);
}


/********************************************************************************

  These functions are copied from the EvalIterator -- maybe they could be shared.

********************************************************************************/

/****************************************************************************//**
  This method imports a static and dynamic environment from the quter query into
  the eval query. In particular:

  (a) imports into the importSctx all the outer vars of the eval query
  (b) imports into the importSctx all the ns bindings of the outer query at the
      place where the eval call appears at
  (c) Copies all the var values from the outer-query global dctx into the eval-
      query dctx.
  (d) For each of the non-global outer vars, places its value into the eval dctx.
      The var value is represented as a PlanIteratorWrapper over the subplan that
      evaluates the domain expr of the eval var.
  (e) Computes the max var id of all the var values set in steps (c) and (d).
      This max varid will be passed to the compiler of the eval query so that
      the varids that will be generated for the eval query will not conflict with
      the varids of the outer vars and the outer-query global vars.
********************************************************************************/
void DynamicFunctionIterator::importOuterEnv(
    PlanState& planState,
    CompilerCB* evalCCB,
    static_context* importSctx,
    dynamic_context* evalDctx) const
{
  ulong maxOuterVarId = 1;

  // Copy all the var values from the outer-query global dctx into the eval-query
  // dctx. This is need to handle the following scenario: (a) $x is an outer-query
  // global var that is not among the outer vars of the eval query (because $x was
  // hidden at the point where the eval call is made inside the outer query), and
  // (b) foo() is a function decalred in the outer query that accessed $x and is
  // invoked by the eval query. The copying must be done using the same positions
  // (i.e., var ids) in the eval dctx as in the outer-query dctx.

  dynamic_context* outerDctx = evalDctx->getParent();

  const std::vector<dynamic_context::VarValue>& outerGlobalValues =
  outerDctx->get_variables();

  // std::cerr << "--> importOuterEnv(): outerDctx: " << outerDctx->toString() << std::endl;

  csize numOuterGlobalVars = outerGlobalValues.size();

  for (csize i = 0; i < numOuterGlobalVars; ++i)
  {
    const dynamic_context::VarValue& outerVar = outerGlobalValues[i];

    if (!outerVar.isSet())
      continue;

    ulong outerVarId = static_cast<ulong>(i);

    if (outerVarId > maxOuterVarId)
      maxOuterVarId = outerVarId;

    store::Item_t itemValue;
    store::TempSeq_t seqValue;

    if (outerVar.hasItemValue())
    {
      store::Item_t value = outerVar.theValue.item;
      evalDctx->add_variable(outerVarId, value);
    }
    else
    {
      store::Iterator_t iteValue = outerVar.theValue.temp_seq->getIterator();
      evalDctx->add_variable(outerVarId, iteValue);
    }
  }

  ++maxOuterVarId;

  // Import the outer vars. Specifically, for each outer var:
  // (a) create a declaration inside the importSctx.
  // (b) Set its var id
  // (c) If it is not a global one, set its value within the eval dctx.


  csize curChild = -1;

  csize numOuterVars = theDynamicFunctionInfo->theScopedVarsNames.size();


  for (csize i = 0; i < numOuterVars; ++i)
  {
    /*
    var_expr* ve = evalCCB->theEM->create_var_expr(importSctx,
                                                   NULL,
                                                   loc,
                                                   var_expr::hof_var,
                                                   theDynamicFunctionInfo->theScopedVarsNames[i].getp());
    */


    // ve->set_type(theOuterVarTypes[i]); TODO: get types

    if (!theDynamicFunctionInfo->theIsGlobalVar[i])
    {
      ++curChild;

      store::Iterator_t iter = new PlanIteratorWrapper(theChildren[curChild], planState);

      // std::cerr << "--> binding iter: " << theChildren[curChild]->toString() << " with varId: " << theDynamicFunctionInfo->theVarId[i] << std::endl;

      // evalDctx->add_variable(maxOuterVarId, iter);
      evalDctx->add_variable(theDynamicFunctionInfo->theVarId[i], iter);

      /*
      ve->set_unique_id(maxOuterVarId);

      // std::cerr << "--> importOuterEnv(): var: " << theDynamicFunctionInfo->theScopedVarsNames[i]->toString() << " assigned id: " << maxOuterVarId << std::endl;

      if (theDynamicFunctionInfo->theSubstVarsValues[i] != NULL
          &&
          theDynamicFunctionInfo->theSubstVarsValues[i]->get_unique_id() == 0)
      {
        theDynamicFunctionInfo->theSubstVarsValues[i]->set_var_info(NULL);
        theDynamicFunctionInfo->theSubstVarsValues[i]->set_unique_id(maxOuterVarId);
      }

      ++maxOuterVarId;
      */
    }
    else
    {
      /*
      static_context* outerSctx = importSctx->get_parent();

      VarInfo* outerGlobalVar = outerSctx->lookup_var(theDynamicFunctionInfo->theScopedVarsNames[i]);

      ulong outerGlobalVarId = 0;

      if (outerGlobalVar)
      {
        outerGlobalVarId = outerGlobalVar->getId();
      }
      else
      {
        // std::cerr << "--> searching for var: " << theDynamicFunctionInfo->theScopedVarsNames[i]->toString() << std::endl;
        for (csize j=0; j<theDynamicFunctionInfo->theSubstVarsValues.size(); j++)
        {
          // std::cerr << "    substVar: " << (theDynamicFunctionInfo->theSubstVarsValues[j] ? theDynamicFunctionInfo->theSubstVarsValues[j]->toString() : "NULL");
          if (theDynamicFunctionInfo->theSubstVarsValues[j]->get_name()->equals(theDynamicFunctionInfo->theScopedVarsNames[i].getp()))
            outerGlobalVarId = theDynamicFunctionInfo->theSubstVarsValues[j]->get_unique_id();
        }
      }

      // ZORBA_ASSERT(outerGlobalVar);

      // std::cerr << "--> importOuterEnv(): outerSctx: " << outerSctx->toString() << std::endl;

      //std::cerr << "--> importOuterEnv(): updating id for subst_var: "
      //          << (theDynamicFunctionInfo->theSubstVarsValues[i] ? theDynamicFunctionInfo->theSubstVarsValues[i]->toString() : "NULL\n");


      if (theDynamicFunctionInfo->theSubstVarsValues[i] != NULL
          &&
          theDynamicFunctionInfo->theSubstVarsValues[i]->get_unique_id() == 0)
      {
        theDynamicFunctionInfo->theSubstVarsValues[i]->set_unique_id(outerGlobalVarId);
      }

      ve->set_unique_id(outerGlobalVarId);
      */
    }

    // importSctx->bind_var(ve, loc);
  }


  // Import the outer-query ns bindings
  store::NsBindings::const_iterator ite = theDynamicFunctionInfo->theLocalBindings.begin();
  store::NsBindings::const_iterator end = theDynamicFunctionInfo->theLocalBindings.end();

  for (; ite != end; ++ite)
  {
    importSctx->bind_ns(ite->first, ite->second, loc);
  }
}


/****************************************************************************//**

********************************************************************************/
void DynamicFunctionIterator::setExternalVariables(
    CompilerCB* ccb,
    static_context* importSctx,
    dynamic_context* evalDctx) const
{
  std::vector<VarInfo*> innerVars;

  CompilerCB::SctxMap::const_iterator sctxIte = ccb->theSctxMap.begin();
  CompilerCB::SctxMap::const_iterator sctxEnd = ccb->theSctxMap.end();

  for (; sctxIte != sctxEnd; ++sctxIte)
  {
    sctxIte->second->getVariables(innerVars, true, false, true);
  }

  FOR_EACH(std::vector<VarInfo*>, ite, innerVars)
  {
    VarInfo* innerVar = (*ite);

    if (!innerVar->isExternal())
      continue;

    ulong innerVarId = innerVar->getId();

    VarInfo* outerVar = importSctx->lookup_var(innerVar->getName());

    if (!outerVar)
      continue;

    store::Item_t itemValue;
    store::TempSeq_t seqValue;

//    std::cerr << "--> setExternalVariables(): dctx->get_variable(): innerVar name: " << innerVar->getName()->toString() << " id: " << innerVar->getId() << std::endl
//              << "                                                  outerVar name: " << outerVar->getName()->toString() << " id: " << outerVar->getId()
//              << std::endl;

    evalDctx->get_variable(outerVar->getId(),
                           outerVar->getName(),
                           loc,
                           itemValue,
                           seqValue);

    if (itemValue != NULL)
    {
      evalDctx->add_variable(innerVarId, itemValue);
    }
    else
    {
      store::Iterator_t iteValue = seqValue->getIterator();
      evalDctx->add_variable(innerVarId, iteValue);
    }
  }
}

NARY_ACCEPT(DynamicFunctionIterator)


} //namespace zorba
/* vim:set et sw=2 ts=2: */
