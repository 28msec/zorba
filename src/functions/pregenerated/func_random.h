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


#ifndef ZORBA_FUNCTIONS_RANDOM_H
#define ZORBA_FUNCTIONS_RANDOM_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_random(static_context* sctx);




//fn-zorba-random:seeded-random
class fn_zorba_random_seeded_random : public function
{
public:
  fn_zorba_random_seeded_random(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn-zorba-random:random
class fn_zorba_random_random : public function
{
public:
  fn_zorba_random_random(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  CODEGEN_DECL();
};


//fn-zorba-util:uuid
class fn_zorba_util_uuid : public function
{
public:
  fn_zorba_util_uuid(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {
setDeterministic(false);

  }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
