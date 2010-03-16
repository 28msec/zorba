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
 
#include "functions/func_numerics.h"

#include "system/globalenv.h"

#include "types/typeops.h"

namespace zorba 
{


/*******************************************************************************

********************************************************************************/
xqtref_t fn_floor::getReturnType(const std::vector<xqtref_t>& argTypes) const 
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  const XQType& argType = *argTypes[0];
  TypeConstants::quantifier_t quant = argType.get_quantifier();

  if (TypeOps::is_subtype(argType, *rtm.DOUBLE_TYPE_QUESTION))
  {
    return (quant == TypeConstants::QUANT_ONE ? 
            rtm.DOUBLE_TYPE_ONE :
            rtm.DOUBLE_TYPE_QUESTION);
  }
  else if (TypeOps::is_subtype(argType, *rtm.FLOAT_TYPE_QUESTION))
  {
    return (quant == TypeConstants::QUANT_ONE ? 
            rtm.FLOAT_TYPE_ONE :
            rtm.FLOAT_TYPE_QUESTION);
  }
  else if (TypeOps::is_subtype(argType, *rtm.DECIMAL_TYPE_QUESTION))
  {
    return (quant == TypeConstants::QUANT_ONE ? 
            rtm.DECIMAL_TYPE_ONE :
            rtm.DECIMAL_TYPE_QUESTION);
  }
  else if (TypeOps::is_subtype(argType, *rtm.INTEGER_TYPE_QUESTION))
  {
    return (quant == TypeConstants::QUANT_ONE ? 
            rtm.INTEGER_TYPE_ONE :
            rtm.INTEGER_TYPE_QUESTION);
  }

  return theSignature.return_type();
}


}
