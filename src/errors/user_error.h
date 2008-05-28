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
#ifndef ZORBA_ERRORS_USER_ERROR_H
#define ZORBA_ERRORS_USER_ERROR_H

#include <string>
#include <vector>

#include "zorbaerrors/errors.h"

#include "common/shared_types.h"

namespace zorba { namespace error {


/*******************************************************************************
  Used for implementing the fn:error function.
********************************************************************************/
class ZorbaUserError : public ZorbaError
{
public:
  std::vector< ::zorba::store::Item_t> theErrorObject;

public:
  ZorbaUserError(
        const ::zorba::store::Item_t& aErrorQName,
        const xqpString& aDescription,
        const QueryLoc& aLocation,
        const std::string& aFileName,
        int aLineNumber,
        std::vector< ::zorba::store::Item_t> aErrorObject);

  virtual ~ZorbaUserError();

  virtual bool
  isUserError() const          { return true; }
};


} /* namespace error */
} /* namespace zorba */
#endif
