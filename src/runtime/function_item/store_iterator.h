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
#ifndef ZORBA_FUNCTION_ITEM_STORE_ITERATOR_H
#define ZORBA_FUNCTION_ITEM_STORE_ITERATOR_H

#include "store/api/iterator.h"

#include <vector>

#include "common/shared_types.h"

#include "compiler/expression/function_item_expr.h"

namespace zorba 
{ 

class function;

namespace store 
{

class FunctionItemIterator: public Iterator
{
  private:
    CompilerCB* theCCB;
    static_context* theSctx;
    function_item_expr theExpr;
    bool isInline;
    store::Iterator_t theImplementation;
    std::vector<PlanIter_t> theArguments;
    
  public:
    FunctionItemIterator(CompilerCB* aCCB, 
        static_context* aSctx,
        function_item_expr& anExpr,
        bool inlined)
      : 
        theCCB(aCCB),
        theSctx(aSctx),
        theExpr(anExpr),
        isInline(inlined),
        theImplementation(0)
    {}

    void open();
    bool next(Item_t&);
    void reset();
    void close();

    FunctionItemIterator* setArgs(std::vector<PlanIter_t>& args)
    {
      theArguments = args;
      return this;
    }

    FunctionItemIterator* addArg(const PlanIter_t& arg)
    {
      theArguments.push_back(arg);
      return this;
    }

    const std::vector<PlanIter_t>& getArgs() const
    {
      return theArguments;
    }
};
}//end of namespace store
}//end of namespace zorba

#endif
