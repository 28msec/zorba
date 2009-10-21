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


#ifndef ZORBA_FUNCTIONS_CONVERTORS_H
#define ZORBA_FUNCTIONS_CONVERTORS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba{


void populate_context_convertors(static_context* sctx);



//zorba-json:parse
class zorba_json_parse : public function
{
public:
  zorba_json_parse ( const signature& sig) : function (sig, FunctionConsts::ZORBA_JSON_PARSE) {}

  PlanIter_t codegen( CompilerCB*,
                      static_context* sctx,
                      const QueryLoc& loc,
                      std::vector<PlanIter_t>& argv,
                      AnnotationHolder& ann) const;
};

//zorba-json:serialize
class zorba_json_serialize : public function
{
public:
  zorba_json_serialize ( const signature& sig) : function (sig, FunctionConsts::ZORBA_JSON_SERIALIZE) {}

  PlanIter_t codegen( CompilerCB*,
                      static_context* sctx,
                      const QueryLoc& loc,
                      std::vector<PlanIter_t>& argv,
                      AnnotationHolder& ann) const;
};

//zorba-json-ml:parse
class zorba_json_ml_parse : public function
{
public:
  zorba_json_ml_parse ( const signature& sig) : function (sig, FunctionConsts::ZORBA_JSON_ML_PARSE) {}

  PlanIter_t codegen( CompilerCB*,
                      static_context* sctx,
                      const QueryLoc& loc,
                      std::vector<PlanIter_t>& argv,
                      AnnotationHolder& ann) const;
};

//zorba-json-ml:serialize
class zorba_json_ml_serialize : public function
{
public:
  zorba_json_ml_serialize ( const signature& sig) : function (sig, FunctionConsts::ZORBA_JSON_ML_SERIALIZE) {}

  PlanIter_t codegen( CompilerCB*,
                      static_context* sctx,
                      const QueryLoc& loc,
                      std::vector<PlanIter_t>& argv,
                      AnnotationHolder& ann) const;
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
