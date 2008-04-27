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
#ifndef ZORBA_CONTEXT_FUNCTIONS_H
#define ZORBA_CONTEXT_FUNCTIONS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba
{

class zorba;

// 16.3 fn:current-dateTime
class fn_current_dateTime : public function
{
  public:
    fn_current_dateTime(const signature&);
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

// 16.4 fn:current-date
class fn_current_date : public function
{
  public:
    fn_current_date(const signature&);
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

// 16.5 fn:current-time
class fn_current_time : public function
{
  public:
    fn_current_time(const signature&);
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

// 16.6 fn:implicit-timezone
class fn_implicit_timezone : public function
{
  public:
    fn_implicit_timezone(const signature&);
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

// 16.7 fn:default-collation
class fn_default_collation : public function
{
  public:
    fn_default_collation(const signature&);
     
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;

    bool requires_dyn_ctx () const { return true; }
};

} /* namespace zorba */
#endif  /* ZORBA_CONTEXT_FUNCTIONS_H */
