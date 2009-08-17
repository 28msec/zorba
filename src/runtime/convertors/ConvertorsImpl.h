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

#ifndef ZORBA_RUNTIME_CONVERTORS_IMPL_H
#define ZORBA_RUNTIME_CONVERTORS_IMPL_H

#include "runtime/base/narybase.h"

namespace zorba {

//Json
class FnJsonParseIteratorState : public PlanIteratorState \
{
 public:
  xqp_string theBaseUri;
  
  void init(PlanState&);
  void reset(PlanState&);
};

NARY_ITER_STATE_SCTX(ZorbaJsonParseIterator, FnJsonParseIteratorState);


NARY_ITER (ZorbaJsonSerializeIterator);


//JsonML
class FnJsonMLParseIteratorState : public PlanIteratorState 
{
 public:
  xqp_string theBaseUri;

  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE_SCTX (ZorbaJsonMLParseIterator, FnJsonMLParseIteratorState);

NARY_ITER (ZorbaJsonMLSerializeIterator);


}/*namespace zorba*/

#endif /* ZORBA_RUNTIME_CONVERTORS_IMPL_H */
