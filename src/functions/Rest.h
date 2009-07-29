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
#ifndef ZORBA_REST_H
#define ZORBA_REST_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class rest_get : public function
{
public:
  rest_get(const signature&);

  PlanIter_t codegen (CompilerCB* cb,
                      short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  bool isPureFunction () const { return false; }
};

class rest_get_tidy : public function
{
public:
  rest_get_tidy(const signature&);

  PlanIter_t codegen (CompilerCB* cb,
                      short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  bool isPureFunction () const { return false; }
};

class rest_post : public function
{
public:
  rest_post(const signature&);

  PlanIter_t codegen (CompilerCB* cb,
                      short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
  bool isPureFunction () const { return false; }
};

class rest_put : public function
{
public:
  rest_put(const signature&);

  PlanIter_t codegen (CompilerCB* cb,
                      short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
  bool isPureFunction () const { return false; }
};

class rest_delete : public function
{
public:
  rest_delete(const signature&);

  PlanIter_t codegen (CompilerCB* cb,
                      short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
  bool isPureFunction () const { return false; }
};

class rest_head : public function
{
public:
  rest_head(const signature&);

  PlanIter_t codegen (CompilerCB* cb,
                      short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
  bool isPureFunction () const { return false; }
};


} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
