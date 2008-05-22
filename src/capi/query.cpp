#include "capi/query.h"

#include <cassert>
#include <sstream>
#include <zorba/zorba.h>
#include "capi/shared_wrapper.h"
#include "capi/sequence.h"

using namespace zorba;

namespace zorbac {
      
  XQUERY_ERROR
  Query::get_dynamic_context(XQC_Query query, XQC_DynamicContext_Ref context)
  {
    return XQ_SUCCESS;
  }

  XQUERY_ERROR 
  Query::execute(XQC_Query query, FILE* file)
  {
    SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(query->data);

    std::stringstream lStream;
    char lBuf[1024];

    try {
      // TODO this is eager at the moment, we need a pull serializer
      lStream << lQuery->theObject; 
      lStream.seekg(0);

      int lRes = 0;
      while ( (lRes = lStream.readsome(lBuf, 1023)) > 0 ) {
        lBuf[lRes] = 0;
        fprintf (file, "%s", lBuf);
      }
      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR;
    }
  }

  XQUERY_ERROR 
  Query::sequence(XQC_Query query, XQC_Sequence_Ref sequence)
  {
    SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(query->data);

    try {
      ResultIterator_t lResultSmart = lQuery->theObject->iterator();
      lResultSmart->open();

      XQC_Sequence lSeq = new XQC_Sequence_s();
      *sequence = static_cast<XQC_Sequence>(lSeq);

      (*sequence)->data = new SharedWrapper<ResultIterator>(lResultSmart);
      (*sequence)->next = Sequence::next;
      (*sequence)->free = Sequence::free;

      return XQ_SUCCESS;
    } catch (ZorbaException& e) {
      return e.getErrorCode();
    } catch (...) {
      return XQP0019_INTERNAL_ERROR; 
    }
  }

  void
  Query::free(XQC_Query query)
  {
    try {
      SharedWrapper<XQuery>* lQuery = static_cast<SharedWrapper<XQuery>* >(query->data);
      delete lQuery;
      delete query;
    } catch (ZorbaException& e) {
      assert(false);
    } catch (...) {
      assert(false);
    }
  }

} /* namespace zorbac */
