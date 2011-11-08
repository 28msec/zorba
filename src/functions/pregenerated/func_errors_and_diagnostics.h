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


#ifndef ZORBA_FUNCTIONS_ERRORS_AND_DIAGNOSTICS_H
#define ZORBA_FUNCTIONS_ERRORS_AND_DIAGNOSTICS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_errors_and_diagnostics(static_context* sctx);




//fn:error
class fn_error : public function
{
public:
  fn_error(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  short getScriptingKind() const { return VACUOUS_EXPR; }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return producer == 2; }

  CODEGEN_DECL();
};


//fn:trace
class fn_trace : public function
{
public:
  fn_trace(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool isMap(ulong producer) const { return producer == 0; }

  bool propagatesDistinctNodes(csize producer) const { return producer == 0; }

  bool propagatesSortedNodes(csize producer) const { return producer == 0; }

  BoolAnnotationValue ignoresSortedNodes(expr* fo, csize producer) const;

  BoolAnnotationValue ignoresDuplicateNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
