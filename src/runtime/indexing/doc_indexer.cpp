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

#include "context/dynamic_context.h"

#include "compiler/expression/var_expr.h"
#include "compiler/codegen/plan_visitor.h"

#include "runtime/api/plan_wrapper.h"
#include "runtime/base/plan_iterator.h"
#include "runtime/indexing/doc_indexer.h"

#include "store/api/item.h"


namespace zorba 
{


/*******************************************************************************

********************************************************************************/
DocIndexer::DocIndexer(
    bool general,
    csize numColumns,
    PlanIterator* plan,
    var_expr* var)
  :
  theIsGeneral(general),
  theNumColumns(numColumns),
  theIndexerPlan(plan),
  theNodeVar(var)
{
}


/*******************************************************************************

********************************************************************************/
DocIndexer::~DocIndexer()
{
  if (thePlanWrapper)
    thePlanWrapper->close();
}


/*******************************************************************************

********************************************************************************/
void DocIndexer::setup(CompilerCB* ccb)
{
  if (thePlanWrapper == NULL)
  {
    thePlanWrapper = new PlanWrapper(theIndexerPlan, ccb, NULL, NULL);

    theDctx = static_cast<PlanWrapper*>(thePlanWrapper.getp())->dctx();

    theDctx->declare_variable(theNodeVar->get_unique_id());

    thePlanWrapper->open();
  }
}


/*******************************************************************************

********************************************************************************/
void DocIndexer::createIndexEntries(
    store::Item* docNode,
    store::IndexDelta& delta)
{
  store::Item_t tmp = docNode;
  theDctx->set_variable(theNodeVar->get_unique_id(),
                        theNodeVar->get_name(),
                        QueryLoc::null,
                        tmp);

  store::Item_t domainNode;

  try
  {
    if (theIsGeneral)
    {
      if (thePlanWrapper->next(domainNode))
      {
        store::Item_t key;
        bool more = true;

        while (more)
        {
          assert(domainNode->isNode());

          while ((more = thePlanWrapper->next(key)))
          {
            if (key->isNode())
            {
              domainNode.transfer(key);
              break;
            }

            store::Item_t node = domainNode;
            delta.addGeneralPair(node, key);
          }
        }
      }
    }
    else
    {
      store::IndexKey* key = NULL;

      //std::cout << "Computing value index delta" << std::endl;

      try
      {
        while (thePlanWrapper->next(domainNode))
        {
          key = new store::IndexKey(theNumColumns);

          for (csize i = 0; i < theNumColumns; ++i)
          {
            if (!thePlanWrapper->next((*key)[i]))
            {
              throw ZORBA_EXCEPTION(zerr::ZXQP0003_INTERNAL_ERROR,
              ERROR_PARAMS(ZED(IncompleteKeyInIndexRefresh)));
            }
          }
      
          /*
          std::cout << "[ node: " << domainNode.getp()
                    << " , key: " << key
                    << " , keyval: " << (*key)[0]->getStringValue()
                    << " ]" << std::endl;
          */
          delta.addValuePair(domainNode, key);
          key = NULL;
        }

        //std::cout << std::endl;
      }
      catch(...)
      {
        if (key != NULL)
          delete key;

        throw;
      }
    }
  }
  catch(...)
  {
    delta.clear();

    theDctx->unset_variable(theNodeVar->get_unique_id(),
                            theNodeVar->get_name(),
                            QueryLoc::null);

    thePlanWrapper->reset();

    throw;
  }

  //std::cout << std::endl << std::endl;

  theDctx->unset_variable(theNodeVar->get_unique_id(),
                          theNodeVar->get_name(),
                          QueryLoc::null);

  thePlanWrapper->reset();
}



}

/* vim:set et sw=2 ts=2: */
