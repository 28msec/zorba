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

#include "errors/user_error.h"

#include "compiler/parser/query_loc.h"

#include "store/api/item.h"

namespace zorba { namespace error {

ZorbaUserError::ZorbaUserError(
    const ::zorba::store::Item_t&        aErrQName,
    const zstring&                       aDescription,
    const QueryLoc&                      aLocation,
    const std::string&                   aFileName,
    int                                  aLineNumber,
    std::vector< ::zorba::store::Item_t> aErrorObject)
  :
  ZorbaError(aErrQName->getLocalName().str(),
             aErrQName->getPrefix().str(),
             aErrQName->getNamespace().str(),
             aDescription,
             aLocation.getLineBegin(),
             aLocation.getColumnBegin(),
             aLocation.getFilename().str(),
             aFileName,
             aLineNumber),
  theErrorObject(aErrorObject)
{
}

    
ZorbaUserError::~ZorbaUserError()
{
}


std::auto_ptr<ZorbaError>
ZorbaUserError::clone() const
{
  std::auto_ptr<ZorbaError> err(new ZorbaUserError(*this));
  return err;
}
    
} /* namespace error */
} /* namespace zorba */
