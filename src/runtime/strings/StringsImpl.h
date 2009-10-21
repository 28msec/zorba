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
#ifndef ZORBA_STRINGS_IMPL_H
#define ZORBA_STRINGS_IMPL_H

#include "common/common.h"
#include "common/shared_types.h"

#include "zorbautils/checked_vector.h"

#include "runtime/base/narybase.h"

#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"

namespace zorba {


/*______________________________________________________________________
 *
 * 7.2 Functions to Assemble and Disassemble Strings
 *_______________________________________________________________________*/
/*
 * 7.2.2 fn:string-to-codepoints
 * --------------------*/
/*begin class StringToCodepointsIterator*/
class StringToCodepointsState : public PlanIteratorState
{
private:
  checked_vector<xqp_uint> resVector;
  xqp_uint iter;
public:
  void init(PlanState&);
  void reset(PlanState&);

  // TODO for performance reasons we should inline these functions or provide direct access to the members
  void setIterator(xqp_uint);
  void setVector(checked_vector<xqp_uint> vect);
  
  xqp_uint getItem(xqp_uint iter);
  xqp_uint getVectSize();
  xqp_uint getIterator();
};


NARY_ITER_STATE (StringToCodepointsIterator, StringToCodepointsState);
/*end class StringToCodepointsIterator*/

// 7.6.4 fn:tokenize
class FnTokenizeIteratorState : public PlanIteratorState {
  public:
    xqp_string  theString; // the remaining string
    xqp_int     start_pos;
    xqp_boolean hasmatched;
    xqp_string  thePattern, theFlags;

    void init(PlanState&);
    void reset(PlanState&);
};

NARY_ITER_STATE(FnTokenizeIterator, FnTokenizeIteratorState);

}/*namespace zorba*/
#endif /* ZORBA_STRINGS_IMPL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
