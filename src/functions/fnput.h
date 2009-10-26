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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************


#ifndef ZORBA_FUNCTIONS_FNPUT_H
#define ZORBA_FUNCTIONS_FNPUT_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba{


void populate_context_fnput(static_context* sctx);



//fn:put
class fn_put : public function
{
public:
  fn_put(const signature& sig) : function(sig, FunctionConsts::FN_PUT) {}

  expr_update_t getUpdateType() const { return UPDATE_EXPR; }

  CODEGEN_DECL();

  bool propagatesInputToOutput(uint32_t aProducer) const;
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
