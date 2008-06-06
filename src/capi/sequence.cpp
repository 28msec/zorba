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
#include "capi/sequence.h"

#include <cassert>
#include <zorba/zorba.h>
#include "capi/item.h"

using namespace zorba;

namespace zorbac {

  XQUERY_ERROR
  Sequence::next(XQC_Sequence seq, XQC_Item item)
  {
     try {
       ResultIterator* lIter = static_cast<ResultIterator*>(seq->data);
       zorbac::Item* lInnerItem = static_cast<zorbac::Item*>(item->data);
       lInnerItem->theStrings.clear();
 
       if ( lIter->next(lInnerItem->theItem) )
         return XQ_NO_ERROR;
 
       return API0025_END_OF_SEQUENCE;
     } catch (ZorbaException& e) {
       return e.getErrorCode();
     } catch (...) {
       return XQP0019_INTERNAL_ERROR;
     }
  }

  void
  Sequence::free(XQC_Sequence seq)
  {
     try {
       ResultIterator* lIter = static_cast<ResultIterator*>(seq->data);
       lIter->close();
       lIter->removeReference();
       delete seq;
     } catch (ZorbaException& e) {
       assert(false);
     } catch (...) {
       assert(false);
     }
  }

  void
  Sequence::assign_functions(XQC_Sequence seq)
  {
    seq->next = Sequence::next;
    seq->free = Sequence::free;
  }

} /* namespace zorbac */
