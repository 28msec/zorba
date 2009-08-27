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
#include "zorbaerrors/error_manager.h"
#include "errors/user_error.h"
#include "zorbatypes/URI.h"

#include "api/serialization/serializer.h"

#include "system/globalenv.h"

#include "types/schema/Utils.h"

#include "compiler/api/compilercb.h"

#include "runtime/misc/MiscImpl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/util/iterator_impl.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/pul.h"

#include "context/static_context.h"


#include <iostream>


namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(FnErrorIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnErrorIterator)

SERIALIZABLE_CLASS_VERSIONS(FnResolveUriIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnResolveUriIterator)

SERIALIZABLE_CLASS_VERSIONS(SequentialIterator)
END_SERIALIZABLE_CLASS_VERSIONS(SequentialIterator)

SERIALIZABLE_CLASS_VERSIONS(FlowCtlIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FlowCtlIterator)

SERIALIZABLE_CLASS_VERSIONS(LoopIterator)
END_SERIALIZABLE_CLASS_VERSIONS(LoopIterator)

SERIALIZABLE_CLASS_VERSIONS(FnReadStringIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnReadStringIterator)

SERIALIZABLE_CLASS_VERSIONS(FnPrintIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnPrintIterator)

// 3 The Error Function
//---------------------
bool FnErrorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  static const char *err_ns = "http://www.w3.org/2005/xqt-errors";
  store::Item_t err_qname;
  GENV_ITEMFACTORY->createQName (err_qname, err_ns, "err", "FOER0000");
  store::Item_t lTmpQName;
  store::Item_t lTmpErrorObject;
  store::Item_t lTmpDescr;
  xqp_string ns;
  xqp_string description;
  std::vector<store::Item_t> lErrorObject; 

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size () >= 1) {
    if (consumeNext(lTmpQName, theChildren[0].getp(), planState))
      err_qname = lTmpQName;
  }
  if (theChildren.size () >= 2) {
    consumeNext(lTmpDescr, theChildren[1].getp(), planState);
    description = lTmpDescr->getStringValue ().getp();
  }
  if (theChildren.size() == 3) {
    while (consumeNext(lTmpErrorObject, theChildren[2].getp(), planState)) {
      lErrorObject.push_back(lTmpErrorObject);
    }
  }
  
  {
    error::ZorbaUserError lError(err_qname, description, loc, 
                                 __FILE__, __LINE__, lErrorObject);
    throw lError;
  }

  STACK_END (state);
}


// 8.1 fn:resolve-uri
//---------------------
void FnResolveUriIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<FnResolveUriIterator, PlanIteratorState>::
  openImpl(planState, offset);
    
  this->theSctx = planState.theCompilerCB->getStaticContext(this->sctx);
}


bool FnResolveUriIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqpStringStore_t strRelative;
  xqpStringStore_t strBase;
  xqpStringStore_t strResult;
  URI              baseURI;
  URI              resolvedURI;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0], planState ))
  {
    strRelative = item->getStringValue();

    //If first param is an absolute URI reference, it is returned unchanged.
    try{
      resolvedURI = URI(&*strRelative);
    } catch (error::ZorbaError&) {}

    if (resolvedURI.is_absolute()) {
      strResult = strRelative;
    }
    else 
    {
      try 
      {
        if (theChildren.size() == 1) 
        {
          // use base-uri from static context
          strBase = theSctx->baseuri().getStore();
          if (strBase->empty()) 
          {
            ZORBA_ERROR_LOC_DESC(FONS0005, loc,
                                 "base-uri is not initialized in the static context");
          }
        }
        else if (consumeNext(item, theChildren[1], planState )) 
        {
          // two parameters => get baseuri from the second argument
          strBase = item->getStringValue();
        } 
        else
        {
          ZORBA_ERROR_LOC_DESC(FORG0009, loc, "Can't treat empty-sequence as base-uri");
        }
        baseURI = URI(&*strBase, true);
      } 
      catch (error::ZorbaError& e) 
      {
        ZORBA_ERROR_LOC_DESC(FORG0002, loc,
                             "String {" + strBase->str() +  "} is not a valid URI: " + e.theDescription);
      }

      try 
      {
        resolvedURI = URI(baseURI, &*strRelative, true); // resolve with baseURI or return strRelative if it's a valid absolute URI
        strResult = resolvedURI.toString().getStore();
      }
      catch (error::ZorbaError& e) 
      {
        ZORBA_ERROR_LOC_DESC(FORG0002, loc, e.theDescription);
      }
    }
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strResult), state);
  } // else return empty sequence if the first argument is the empty sequence

  STACK_END (state);
}


bool SequentialIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  rchandle<store::PUL> lPul;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  for (unsigned i = 0; i < theChildren.size() - 1; i++) 
  {
    while (CONSUME (result, i))
    {
      if (theChildren[i]->isUpdating())
      {
        std::set<zorba::store::Item*> validationNodes;

        static_cast<store::PUL *> (result.getp ())->applyUpdates(validationNodes);

        store::Item_t validationPul = GENV_ITEMFACTORY->createPendingUpdateList();

#ifndef ZORBA_NO_XMLSCHEMA
        QueryLoc& loc = theChildren[i]->loc;
        validateAfterUpdate(validationNodes,
                            validationPul,
                            getStaticContext(planState),
                            loc);
#endif
        validationPul->applyUpdates(validationNodes);
      }
    }
  }

  while (CONSUME (result, theChildren.size () - 1))
    STACK_PUSH (true, state);

  STACK_END (state);
}


bool FlowCtlIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  switch (act) {
  case EXIT:
    throw ExitException (new PlanIteratorWrapper (theChildren [0], planState));
  default:
    throw FlowCtlException (act);
  }
    
  STACK_END (state);
}

bool FnReadStringIterator::nextImpl (store::Item_t& result, PlanState& planState) const {
  PlanIteratorState *state;
  xqpStringStore_t xstr;
  char str [512];
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  std::cin.getline (str, sizeof (str));
  xstr = new xqpStringStore (str);
  GENV_ITEMFACTORY->createString (result, xstr);
  STACK_PUSH (true, state);
  STACK_END (state);
}


bool FnPrintIterator::nextImpl (store::Item_t& result, PlanState& planState) const 
{
  std::ostringstream os;
  serializer* lSerializer = NULL;
  store::Item_t item;
  xqpStringStore_t resString;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (CONSUME (item, theChildren.size () - 1))
  {
    if (item->isNode())
    {
      if (lSerializer == NULL)
      {
        lSerializer = new serializer(planState.theCompilerCB->m_error_manager);
        lSerializer->set_parameter("omit-xml-declaration", "yes");
      }

	  if (m_printToConsole) {
		  lSerializer->serialize(item.getp(), std::cout);
	  } else {
		  lSerializer->serialize(item.getp(), os);
	  }
    }
    else
    {
	  if (m_printToConsole) {
        std::cout << item->getStringValue ();
	  } else {
	    os << item->getStringValue();
	  }
    }
  }
  if (!m_printToConsole) {
    resString = new xqpStringStore(os.str());
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, resString) , state);
  }
  STACK_END (state);
}


bool LoopIterator::nextImpl (store::Item_t& result, PlanState& planState) const {
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  for (;;) {
    try {
      while (! CONSUME (result, 0))
        theChildren [0]->reset (planState);
    } catch (FlowCtlIterator::FlowCtlException &e) {
      switch (e.act) {
      case FlowCtlIterator::BREAK:
        goto done;
      case FlowCtlIterator::CONTINUE:
        theChildren [0]->reset (planState);
        continue;
      default:
        throw;
      }
    }
    STACK_PUSH (true, state);
  }

done:
  STACK_END (state);
}

} /* namespace zorba */
