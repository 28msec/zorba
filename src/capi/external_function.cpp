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
#include "capi/external_function.h"
#include "capi/error.h"
#include "capi/sequence.h"
#include "zorbaerrors/error_manager.h"
#include <zorba/item_sequence.h>

using namespace zorba;

namespace zorbac {

  class ExternalFunctionWrapperSequence : public ItemSequence {
    public:
      ExternalFunctionWrapperSequence(StatelessExternalFunction::Arguments_t args,
      external_function_init init,
      external_function_release release,
      void* global_user_data)
        : theArgs(args),
          theInitFunction(init),
          theReleaseFunction(release),
          theUserData(0),
          theGlobalUserData(global_user_data)
      {
        if (theInitFunction)
          theInitFunction(&theUserData, theGlobalUserData);

        theSequences = new XQC_Sequence_s[args.size()];

        XQC_Sequence_s* lTmp = theSequences;
        for (unsigned int i = 0; i < args.size(); ++i) {
          std::auto_ptr<Sequence> lSeq(new Sequence());
          lSeq->theItemSequence = args[i];
          lTmp->data = lSeq.get();
          Sequence::assign_functions(lTmp);
          // override normal Sequence's free() with our own
          lTmp->free = external_sequence_free;
          lSeq.release();
          lTmp++;
        }
      }

      ~ExternalFunctionWrapperSequence()
      {
        if (theReleaseFunction)
          theReleaseFunction(theUserData, theGlobalUserData);

        delete[] theSequences;
      }

      static void
      external_sequence_free(XQC_Sequence* sequence)
      {
      }

      virtual 
      bool next(zorba::Item& i)
      {
// TODO commented out pending rewrite of external function API
//         XQC_Error lRes = theNextFunction(theSequences, theArgs.size(), 
//         &theItem, theUserData, theGlobalUserData);
//         if ( lRes == XQC_END_OF_SEQUENCE)
//           return false;

//         if ( lRes != XQC_NO_ERROR ) {
//           // TODO external_function_next returns XQC_Error for now,
//           // but ZORBA_ERROR wants XQUERY_ERROR. Someday this
//           // disparity should be cleaned up. For now toss a
//           // general-purpose XQUERY_ERROR.
//           ZORBA_ERROR(XQP0019_INTERNAL_ERROR);
//         }

//         i = static_cast<zorbac::Item*>(theItem->data)->theItem;
//         assert (!i.isNull());

        return true;
      }

    private:
      StatelessExternalFunction::Arguments_t theArgs; 
      external_function_init                 theInitFunction;
      external_function_release              theReleaseFunction;
      void*                                  theUserData;
      XQC_Sequence_s*                        theSequences;
      void*                                  theGlobalUserData;
  };


  ExternalFunctionWrapper::ExternalFunctionWrapper(const char* uri, 
  const char* localname,
  external_function_init init,
  external_function_release release,
  void* global_user_data)
    : theURI(uri),
      theLocalName(localname),
      theInitFunction(init),
      theReleaseFunction(release),
      theGlobalUserData(global_user_data) {}

  String
  ExternalFunctionWrapper::getURI() const 
  { 
    return theURI;
  }

  String
  ExternalFunctionWrapper::getLocalName() const 
  { 
    return theLocalName;
  }

  ItemSequence_t
  ExternalFunctionWrapper::evaluate(const StatelessExternalFunction::Arguments_t& args) const
  {
    return ItemSequence_t(new ExternalFunctionWrapperSequence(args, 
    theInitFunction, 
    theReleaseFunction,
    theGlobalUserData));
  }

} /* namespace zorbac */
