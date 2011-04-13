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

#include "api/functionimpl.h"
#include "api/zorbaimpl.h"
#include "functions/function.h"
#include "zorbaerrors/error_manager.h"

namespace zorba 
{

bool FunctionImpl::isUpdating() const
{
  return theFunction->isUpdating();
}

bool FunctionImpl::isPrivate() const
{
  return theFunction->isPrivate();
}

bool FunctionImpl::isDeterministic() const
{
  return theFunction->isDeterministic();
}

bool FunctionImpl::isSequential() const
{
  return theFunction->isSequential();
}

bool FunctionImpl::requiresDynamicContext() const
{
  return theFunction->accessesDynCtx();
}


Item FunctionImpl::getFunctionName() const
{
  try 
  {
    Item lFunctionName(theFunction->getName());
    return lFunctionName;
  } 
  catch (ZorbaException const& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
  return Item(0);
}


size_t
FunctionImpl::getArity() const
{
  return theFunction->getArity();
}

bool
FunctionImpl::isVariadic() const
{
  return theFunction->isVariadic();
}

} /* namespace zorba */
