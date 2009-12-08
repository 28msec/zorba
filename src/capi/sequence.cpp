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
#include "capi/error.h"

using namespace zorba;

namespace zorbac {

  zorba::ResultIterator*
  getResultIterator(XQC_Sequence* sequence)
  {
    return (static_cast<zorbac::Sequence*>(sequence->data))->theSequence.get();
  }

  XQC_Error
  Sequence::next(XQC_Sequence* seq, XQC_Item item)
  {
    ResultIterator* lIter = 0;
    try {
      lIter = getResultIterator(seq);
      zorbac::Item* lInnerItem = static_cast<zorbac::Item*>(item->data);
      lInnerItem->theStrings.clear();
 
      if ( lIter->next(lInnerItem->theItem) )
        return XQC_NO_ERROR;
 
      return XQC_END_OF_SEQUENCE;
    } catch (QueryException& qe) {
      zorbac::Sequence* lSeq = static_cast<zorbac::Sequence*>(seq->data);
      if (lSeq->theErrorHandler) {                                      \
        lSeq->theErrorHandler->error(lSeq->theErrorHandler, Error::convert_xquery_error(qe.getErrorCode()),
        ZorbaException::getErrorCodeAsString(qe.getErrorCode()).c_str(),
        qe.getDescription().c_str(),
        qe.getQueryURI().c_str(),
        qe.getLineBegin(),
        qe.getColumnBegin());
      }
      return Error::convert_xquery_error(qe.getErrorCode());
    } catch (ZorbaException &ze) {
      return Error::convert_xquery_error(ze.getErrorCode());
    } catch (...) {
      return XQC_INTERNAL_ERROR;
    }
  }

  void
  Sequence::free(XQC_Sequence* seq)
  {
     try {
       ResultIterator* lIter = getResultIterator(seq);
       lIter->close();
       delete static_cast<zorbac::Sequence*>(seq->data);
       delete seq;
     } catch (ZorbaException&) {
       assert(false);
     } catch (...) {
       assert(false);
     }
  }

  void
  Sequence::assign_functions(XQC_Sequence* seq)
  {
    seq->next = Sequence::next;
    seq->free = Sequence::free;
  }

} /* namespace zorbac */
