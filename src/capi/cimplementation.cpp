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

#include "capi/cimplementation.h"

#include <sstream>
#include <memory>

#include "capi/cexpression.h"
#include "capi/cstatic_context.h"
#include "capi/csequence.h"
#include "capi/user_item_sequence.h"
#include "capi/error.h"
#include "capi/single_item_sequence.h"

#include "api/staticcontextimpl.h"
#include "api/xqueryimpl.h"

#include "context/static_context.h"


using namespace zorba;

// These need to be slightly different than CAPI_TRY/CATCH because
// there is no theErrorHandler member on CImplementation.
#define CIMPL_TRY \
  XQC_ErrorHandler* handler = NULL;                     \
  CImplementation* me = CImplementation::get(impl);     \
  try

#define CIMPL_CATCH \
  catch (XQueryException const& qe) {                                   \
    return Error::handle_and_convert_queryexception(handler, qe);       \
  } catch (ZorbaException const &ze) {                                  \
    return Error::convert_xquery_error(ze.diagnostic());                \
  } catch (...) {                                                       \
    return XQC_INTERNAL_ERROR;                                          \
  }                                                                     \
  return XQC_NO_ERROR


namespace zorbac {

  /**
   * data for create_*_sequence() methods.
   */
  class CrSeqData {
    public:
      CrSeqData(unsigned int argc, XQC_ItemType type, bool typed_value)
        : theIsTypedValue(typed_value),
          theSize(argc),
          theCount(0),
          theType(type)
      {
      }

      /**
       * If true, this is a singleton sequence of typed data.
       */
      bool theIsTypedValue;
      /**
       * The number of entries.
       */
      unsigned int theSize;
      /**
       * Which entry to return next.
       */
      unsigned int theCount;
      /**
       * Type; will determine which member of the union to refer to.
       */
      XQC_ItemType theType;
      /**
       * One of these will point to the user-supplied data.
       */
      union {
          double* theDoubles;
          int* theInts;
          const char** theStrings;
          const char* theString;
      };
  };

  /**
   * create_*_sequence() method callbacks.
   */
  void
  crseq_init(void** user_data, void* sequence_data)
  {
    // No user-data to create, nothing to do
  }

  XQC_Error
  crseq_next(XQC_Sequence** args, unsigned int argc,
    Zorba_ItemSetter* setter, void* user_data, void* sequence_data)
  {
    CrSeqData* lData = static_cast<CrSeqData*> (sequence_data);
    if (lData->theCount >= lData->theSize) {
      return XQC_END_OF_SEQUENCE;
    }
    else if (lData->theIsTypedValue) {
      // Singleton sequence; increment count so we stop next time
      lData->theCount++;
      setter->set_typed_value(setter, lData->theType, lData->theString);
    }
    else {
      switch (lData->theType) {
        case XQC_DECIMAL_TYPE:
          setter->set_integer(setter, lData->theInts[lData->theCount++]);
          break;
        case XQC_DOUBLE_TYPE:
          setter->set_double(setter, lData->theDoubles[lData->theCount++]);
          break;
        case XQC_STRING_TYPE:
          setter->set_string(setter, lData->theStrings[lData->theCount++]);
          break;
        default:
          assert(false);
          return XQC_TYPE_ERROR;
      }
    }
    return XQC_NO_ERROR;
  }

  void
  crseq_free(void* user_data, void* sequence_data)
  {
    // The UserItemSequence is being deleted, so delete the sequence data
    CrSeqData* lData = static_cast<CrSeqData*> (sequence_data);
    delete lData;
  }

  /**
   * Utility method to create an XQC_Sequence based on a CrSeqData.
   */
  void
  CImplementation::create_sequence
  (std::auto_ptr<CrSeqData> data, XQC_Sequence** seq)
  {
    // Create a UserItemSequence to return the data in order as items.
    std::auto_ptr<UserItemSequence> lItemSeq
      (new UserItemSequence(NULL, 0, &crseq_init, &crseq_next, &crseq_free,
        data.get(), theZorba->getItemFactory(), NULL));

    // Wrap in a CSequence to produce an XQC_Sequence. We pass "true"
    // to make CSequence assume memory-management responsibility for
    // the UserItemSequence.
    std::auto_ptr<CSequence> lSeq (new CSequence(lItemSeq.get(), true, NULL));

    lItemSeq.release();
    data.release();
    (*seq) = lSeq.release()->getXQC();
  }

  /**
   * Utility method to read an XQC_InputStream to a std::stringstream.
   * TODO don't eagerly consume?
   */
  XQC_Error
  CImplementation::readXQCInputStream
  (XQC_InputStream* aXQCStream, std::stringstream& aStream)
  {
    char lBuf[1024];
    memset(lBuf, 0, 1024);

    int lRead = 0;
    while ( (lRead = aXQCStream->read(aXQCStream, lBuf, 1024)) >= 1024 ) {
      aStream.write(lBuf, lRead);
    }
    if (lRead > 0) {
      assert (lRead < 1024);
      aStream.write(lBuf, lRead);
    }

    aXQCStream->free(aXQCStream);
    if (lRead == -1) {
      return XQC_INTERNAL_ERROR;
    }
    return XQC_NO_ERROR;
  }


  /**
   * Utility method to read a FILE* to a std::stringstream.
   * TODO don't eagerly consume?
   */
  XQC_Error
  CImplementation::readFile
  (FILE* aFile, std::stringstream& aStream)
  {
    char lBuf[1024];
    memset(lBuf, 0, 1024);

    size_t lRead = 0;
    while ( (lRead = fread(lBuf, 1, 1024, aFile)) > 0 ) {
      aStream.write(lBuf, (std::streamsize)lRead);
    }
    if (!feof(aFile)) {
      return XQC_INTERNAL_ERROR;
    }
    return XQC_NO_ERROR;
  }
  


  CImplementation::CImplementation(Zorba* aZorba)
    : theZorba(aZorba)
  {
    memset(&theXQCImpl, 0, sizeof (XQC_Implementation));
    theXQCImpl.create_context = CImplementation::create_context;
    theXQCImpl.prepare        = CImplementation::prepare;
    theXQCImpl.prepare_file   = CImplementation::prepare_file;
    theXQCImpl.prepare_stream = CImplementation::prepare_stream;
    theXQCImpl.parse_document = CImplementation::parse_document;
    theXQCImpl.parse_document_file = CImplementation::parse_document_file;
    theXQCImpl.parse_document_stream = CImplementation::parse_document_stream;
    theXQCImpl.create_empty_sequence =
      CImplementation::create_empty_sequence;
    theXQCImpl.create_singleton_sequence =
      CImplementation::create_singleton_sequence;
    theXQCImpl.create_string_sequence =
      CImplementation::create_string_sequence;
    theXQCImpl.create_integer_sequence =
      CImplementation::create_integer_sequence;
    theXQCImpl.create_double_sequence =
      CImplementation::create_double_sequence;
    theXQCImpl.free           = CImplementation::free;
  }

  CImplementation::~CImplementation()
  {
    theZorba->shutdown();
  }

  CImplementation*
  CImplementation::get(const XQC_Implementation* xqc)
  {
    return (CImplementation*)
      (((char*)xqc) - CLASS_OFFSET(CImplementation, theXQCImpl));
  }

  Zorba*
  CImplementation::getCPP()
  {
    return theZorba;
  }

  XQC_Implementation*
  CImplementation::getXQC()
  {
    return &theXQCImpl;
  }

  XQC_Error
  CImplementation::create_context
  (XQC_Implementation* impl, XQC_StaticContext** context)
  {
    CIMPL_TRY {
      // Create a C++ StaticContext, wrap in a CStaticContext, then
      // return the inner XQC_StaticContext
      StaticContext_t lContext = me->theZorba->createStaticContext();
      std::auto_ptr<CStaticContext> lCCtx
        (new CStaticContext(lContext, me->theZorba, NULL));
      (*context) = lCCtx.release()->getXQC();
    }
    CIMPL_CATCH;
  }

  XQC_Error 
  CImplementation::prepare
  (XQC_Implementation* impl, const char* query_string,
    const XQC_StaticContext* context, XQC_Expression** expr)
  {
    CIMPL_TRY {
      XQuery_t lQuery;
      if (context) {
        context->get_error_handler(context, &handler);
      }

      if (context) {
        StaticContext_t lContext = CStaticContext::get(context)->getCPP();
        // reference counting in the smartptr takes care of garbage collection
        lQuery = me->theZorba->compileQuery(query_string, lContext);
      } else {
        lQuery = me->theZorba->compileQuery(query_string);
      }

      std::auto_ptr<CExpression> lExpr(new CExpression(lQuery, handler));
      (*expr) = lExpr.release()->getXQC();
    }
    CIMPL_CATCH;
  }

  XQC_Error 
  CImplementation::prepare_file
  (XQC_Implementation* impl, FILE* query_file,
    const XQC_StaticContext* context, XQC_Expression** expr)
  {
    CIMPL_TRY {
      XQuery_t lQuery;
      if (context) {
        context->get_error_handler(context, &handler);
      }

      std::stringstream lStream;
      XQC_Error lError = readFile(query_file, lStream);
      if (lError != XQC_NO_ERROR) {
        return lError;
      }

      if (context) {
        StaticContext_t lContext = CStaticContext::get(context)->getCPP();
        lQuery = me->theZorba->compileQuery(lStream, lContext);
      } else {
        lQuery = me->theZorba->compileQuery(lStream);
      }

      std::auto_ptr<CExpression> lExpr(new CExpression(lQuery, handler));
      (*expr) = lExpr.release()->getXQC();
    }
    CIMPL_CATCH;
  }

  XQC_Error
  CImplementation::prepare_stream
  (XQC_Implementation* impl, XQC_InputStream* stream,
    const XQC_StaticContext* context, XQC_Expression **expr)
  {
    CIMPL_TRY { 
      XQuery_t lQuery;
      if (context) {
        context->get_error_handler(context, &handler);
      }

      std::stringstream lStream;
      XQC_Error lError = readXQCInputStream(stream, lStream);
      if (lError != XQC_NO_ERROR) {
        return lError;
      }

      if (context) {
        StaticContext_t lContext = CStaticContext::get(context)->getCPP();
        lQuery = me->theZorba->compileQuery(lStream, lContext);
      } else {
        lQuery = me->theZorba->compileQuery(lStream);
      }

      std::auto_ptr<CExpression> lExpr(new CExpression(lQuery, handler));
      (*expr) = lExpr.release()->getXQC();
    }
    CIMPL_CATCH; 
  }

  XQC_Error
  CImplementation::parse_istream(std::istream& aStream, XQC_Sequence** seq) {
    XmlDataManager* lXdm = theZorba->getXmlDataManager();
    Item lDoc = lXdm->parseXML(aStream);
    if (lDoc.isNull()) {
      // XmlDataManager doesn't throw exceptions, just passes them
      // to a ErrorHandler, which we don't have.
      return XQC_INTERNAL_ERROR;
    }

    std::auto_ptr<SingleItemSequence> lItemSeq(new SingleItemSequence(lDoc));
    // Wrap in a CSequence to produce an XQC_Sequence. We pass "true"
    // to make CSequence assume memory-management responsibility for
    // the SingleItemSequence.
    std::auto_ptr<CSequence> lSeq(new CSequence(lItemSeq.get(), true, NULL));

    lItemSeq.release();
    (*seq) = lSeq.release()->getXQC();
    return XQC_NO_ERROR;
  }

  XQC_Error
  CImplementation::parse_document(XQC_Implementation* impl,
    const char *string, XQC_Sequence** seq)
  {
    CIMPL_TRY {
      std::istringstream lStream(string);
      return me->parse_istream(lStream, seq);
    }
    CIMPL_CATCH;
  }

  XQC_Error
  CImplementation::parse_document_file(XQC_Implementation* impl,
    FILE *file, XQC_Sequence** seq)
  {
    CIMPL_TRY {
      std::stringstream lStream;
      XQC_Error lError = readFile(file, lStream);
      if (lError != XQC_NO_ERROR) {
        return lError;
      }
      return me->parse_istream(lStream, seq);
    }
    CIMPL_CATCH;
  }

  XQC_Error
  CImplementation::parse_document_stream(XQC_Implementation* impl,
    XQC_InputStream *stream, XQC_Sequence** seq)
  {
    CIMPL_TRY {
      std::stringstream lStream;
      XQC_Error lError = readXQCInputStream(stream, lStream);
      if (lError != XQC_NO_ERROR) {
        return lError;
      }
      return me->parse_istream(lStream, seq);
    }
    CIMPL_CATCH;
  }

  XQC_Error
  CImplementation::create_empty_sequence(XQC_Implementation* impl,
    XQC_Sequence** seq)
  {
    CIMPL_TRY {
      // Create a CrSeqData representing no data at all.
      std::auto_ptr<CrSeqData> lData (new CrSeqData(0, XQC_DOUBLE_TYPE, false));
      lData->theDoubles = NULL;
      me->create_sequence(lData, seq);
    }
    CIMPL_CATCH;
  }

  XQC_Error
  CImplementation::create_singleton_sequence(XQC_Implementation* impl,
    XQC_ItemType type, const char *value, XQC_Sequence** seq)
  {
    CIMPL_TRY {
      // Create a CrSeqData to hold the user's data.
      std::auto_ptr<CrSeqData> lData(new CrSeqData(1, type, true));
      lData->theString = value;
      me->create_sequence(lData, seq);
    }
    CIMPL_CATCH;
  }

  XQC_Error
  CImplementation::create_string_sequence(XQC_Implementation* impl,
    const char *values[], unsigned int count, XQC_Sequence** seq)
  {
    CIMPL_TRY {
      // Create a CrSeqData to hold the user's data.
      std::auto_ptr<CrSeqData> lData
        (new CrSeqData(count, XQC_STRING_TYPE, false));
      lData->theStrings = values;
      me->create_sequence(lData, seq);
    }
    CIMPL_CATCH;
  }

  XQC_Error
  CImplementation::create_integer_sequence(XQC_Implementation* impl,
    int values[], unsigned int count, XQC_Sequence** seq)
  {
    CIMPL_TRY {
      // Create a CrSeqData to hold the user's data.
      std::auto_ptr<CrSeqData> lData
        (new CrSeqData(count, XQC_DECIMAL_TYPE, false));
      lData->theInts = values;
      me->create_sequence(lData, seq);
    }
    CIMPL_CATCH;
  }

  XQC_Error
  CImplementation::create_double_sequence(XQC_Implementation* impl,
    double values[], unsigned int count, XQC_Sequence** seq)
  {
    CIMPL_TRY {
      // Create a CrSeqData to hold the user's data.
      std::auto_ptr<CrSeqData> lData
        (new CrSeqData(count, XQC_DOUBLE_TYPE, false));
      lData->theDoubles = values;
      me->create_sequence(lData, seq);
    }
    CIMPL_CATCH;
  }

  void *
  CImplementation::get_interface
  (const XQC_Implementation* impl, const char *name)
  {
    // No custom interfaces
    return NULL;
  }

  void
  CImplementation::free(XQC_Implementation* impl)
  {
    try {
      CImplementation* me = CImplementation::get(impl);
      delete me;
    } catch (ZorbaException const&) {
      assert(false);
    } catch (...) {
      assert(false);
    }
  }

} /* namespace zorbac */
/* vim:set et sw=2 ts=2: */
