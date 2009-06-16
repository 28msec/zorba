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
  class FnJsonParseIteratorState : public PlanIteratorState {
    public:
      xqp_integer theCurrentPos; // the current position in the sequence

      void init(PlanState&);
      void reset(PlanState&);
  };
  NARY_ITER_STATE (ZorbaJsonParseIterator, FnJsonParseIteratorState);

  class FnJsonSerializeIteratorState : public PlanIteratorState {
    public:
      xqp_integer theCurrentPos; // the current position in the sequence

      void init(PlanState&);
      void reset(PlanState&);
  };
  NARY_ITER_STATE (ZorbaJsonSerializeIterator, FnJsonSerializeIteratorState);

  //JsonML
  class FnJsonMLParseIteratorState : public PlanIteratorState {
    public:
      xqp_integer theCurrentPos; // the current position in the sequence

      void init(PlanState&);
      void reset(PlanState&);
  };
  NARY_ITER_STATE (ZorbaJsonMLParseIterator, FnJsonMLParseIteratorState);

  class FnJsonMLSerializeIteratorState : public PlanIteratorState {
    public:
      xqp_integer theCurrentPos; // the current position in the sequence

      void init(PlanState&);
      void reset(PlanState&);
  };
  NARY_ITER_STATE (ZorbaJsonMLSerializeIterator, FnJsonMLSerializeIteratorState);
}/*namespace zorba*/

#endif /* ZORBA_RUNTIME_CONVERTORS_IMPL_H */
