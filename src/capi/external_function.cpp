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
#include "capi/item.h"
#include "zorbaerrors/error_manager.h"
#include <zorba/item_sequence.h>

using namespace zorba;

namespace zorbac {

  class ExternalFunctionSequence {
  public:
    static XQUERY_ERROR
    next(XQC_Sequence sequence, XQC_Item item)
    {
      try {
        ItemSequence* lSeq = static_cast<ItemSequence*>(sequence->data);  
        zorbac::Item* lInnerItem = static_cast<zorbac::Item*>(item->data);
        lInnerItem->theStrings.clear();

         if ( lSeq->next(lInnerItem->theItem) )
           return XQ_NO_ERROR;
 
         return API0025_END_OF_SEQUENCE;
       } catch (ZorbaException& e) {
         return e.getErrorCode();
       } catch (...) {
         return XQP0019_INTERNAL_ERROR;
       }
    }

    static void
    free(XQC_Sequence sequence)
    {
    }

    static void
    assign_functions(XQC_Sequence sequence)
    {
      sequence->next = ExternalFunctionSequence::next;
      sequence->free = ExternalFunctionSequence::free;
    }
  }; /* class ExternalFunctionSequence */

  class ExternalFunctionWrapperSequence : public ItemSequence {
      public:
          ExternalFunctionWrapperSequence(StatelessExternalFunction::Arguments_t args,
                                          external_function_init init,
                                          external_function_next next,
                                          external_function_release release,
                                          void* global_user_data)
              : theArgs(args),
                theInitFunction(init),
                theNextFunction(next),
                theReleaseFunction(release),
                theUserData(0),
                theItem(0),
                theGlobalUserData(global_user_data)
          {
            if (theInitFunction)
              theInitFunction(&theUserData, theGlobalUserData);

              theSequences = new XQC_Sequence_s[args.size()];

              XQC_Sequence_s* lTmp = theSequences;
              for (unsigned int i = 0; i < args.size(); ++i) {
                (lTmp)->data = args[i];
                ExternalFunctionSequence::assign_functions(lTmp);
                lTmp++;
              }
          }

					~ExternalFunctionWrapperSequence()
          {
            if (theReleaseFunction)
              theReleaseFunction(theUserData, theGlobalUserData);

            delete[] theSequences;
          }

					virtual 
          bool next(zorba::Item& i)
          {
						XQUERY_ERROR lRes = theNextFunction(theSequences, theArgs.size(), 
                                                &theItem, theUserData, theGlobalUserData);
						if ( lRes == API0025_END_OF_SEQUENCE)
							return false;

            if ( lRes != XQ_NO_ERROR ) {
              ZORBA_ERROR(lRes);
            }

						i = static_cast<zorbac::Item*>(theItem->data)->theItem;
            assert (!i.isNull());

            return true;
          }

      private:
         StatelessExternalFunction::Arguments_t theArgs; 
         external_function_init                 theInitFunction;
         external_function_next                 theNextFunction;
         external_function_release              theReleaseFunction;
         void* 																	theUserData;
         XQC_Item                               theItem;
         XQC_Sequence_s*                        theSequences;
         void*                                  theGlobalUserData;
  };


  ExternalFunctionWrapper::ExternalFunctionWrapper(const char* uri, 
                                                   const char* localname,
                                                   external_function_init init,
                                                   external_function_next next,
                                                   external_function_release release,
                                                   void* global_user_data)
    : theURI(uri),
      theLocalName(localname),
      theInitFunction(init),
      theNextFunction(next),
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
                                                              theNextFunction,
                                                              theReleaseFunction,
                                                              theGlobalUserData));
  }

} /* namespace zorbac */
