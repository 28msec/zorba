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

#include "capi/cexternal_function.h"
#include "capi/csequence.h"
#include "capi/user_item_sequence.h"
#include <zorba/item_sequence.h>

using namespace zorba;

namespace zorbac {

  CExternalFunction::CExternalFunction
  (const char* uri, const char* localname, external_function_init init_fn,
    external_function_next next_fn, external_function_free free_fn,
    void* function_user_data, ItemFactory* factory, XQC_ErrorHandler* handler)
    : theURI(uri),
      theLocalName(localname),
      theInitFunction(init_fn),
      theNextFunction(next_fn),
      theFreeFunction(free_fn),
      theFunctionUserData(function_user_data),
      theFactory(factory),
      theErrorHandler(handler)
  {
  }

  CExternalFunction::~CExternalFunction()
  {
  }

  String
  CExternalFunction::getURI() const 
  { 
    return theURI;
  }

  String
  CExternalFunction::getLocalName() const 
  { 
    return theLocalName;
  }

  ItemSequence_t
  CExternalFunction::evaluate
  (const ExternalFunction::Arguments_t& args) const
  {
    unsigned int lSequencesSize = (unsigned int)args.size();
    XQC_Sequence** lSequences = new XQC_Sequence*[lSequencesSize];

    // Wrap each Argument (which is just an ItemSequence) in a
    // CSequence, and keep an array of each corresponding
    // XQC_Sequence. These ItemSequences are being memory-managed by
    // the Zorba engine, so we request that CSequence NOT free them
    // when the CSequence is deleted.
    for (unsigned int i = 0; i < lSequencesSize; ++i) {
      std::auto_ptr<CSequence> lSeq(new CSequence(args[i], false, NULL));
      lSequences[i] = lSeq.release()->getXQC();
    }

    return ItemSequence_t(new UserItemSequence(lSequences, lSequencesSize, 
        theInitFunction, theNextFunction, theFreeFunction,
        theFunctionUserData, theFactory, theErrorHandler));
  }

} /* namespace zorbac */
/* vim:set et sw=2 ts=2: */
