#include "capi/sequence.h"

#include <zorba/zorba.h>
#include "capi/shared_wrapper.h"

using namespace zorba;

namespace zorbac {

 XQUERY_ERROR
 Sequence::next(XQC_Sequence seq, XQC_Item item)
 {
    try {
      SharedWrapper<ResultIterator>* lIter = static_cast<SharedWrapper<ResultIterator>* >(seq->data);
      Item* lInnerItem = static_cast<Item*>(item->data);

      if ( lIter->theObject->next(*lInnerItem) )
        return XQ_SUCCESS;

      return API0025_END_OF_SEQUENCE;
    } catch (ZorbaException& e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
 }

 XQUERY_ERROR 
 Sequence::free(XQC_Sequence seq)
 {
    try {
      SharedWrapper<ResultIterator>* lIter = static_cast<SharedWrapper<ResultIterator>* >(seq->data);
      delete lIter;
      delete seq;
    } catch (ZorbaException& e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
 }

} /* namespace zorbac */
