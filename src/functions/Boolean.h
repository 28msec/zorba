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
#ifndef ZORBA_BOOLEAN_H
#define ZORBA_BOOLEAN_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"
#include "runtime/booleans/compare_types.h"
#include "runtime/booleans/BooleanImpl.h"

namespace zorba {


class GenericOpComparison : public function {
public:
  GenericOpComparison (const signature &sig) : function (sig) {}

  bool isComparisonFunction () const { return true; }

  virtual const char* comparison_name () const { return ""; }

  void compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const;

  virtual function *toValueComp (static_context *) const { return NULL; }

  const function *specialize(static_context *sctx, const std::vector<xqtref_t>& argTypes) const;
  
  virtual bool specializable() const { return true; }

  virtual PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const {
    return createIterator (loc, argv);
  }

protected:
  virtual PlanIter_t createIterator( const QueryLoc& loc, std::vector<PlanIter_t>& ) const = 0;
};


class ValueOpComparison : public GenericOpComparison {
public:
  ValueOpComparison (const signature &sig) : GenericOpComparison (sig) {}

  virtual bool isValueComparisonFunction() const { return true; }

  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;

  virtual bool specializable() const { return true; }

  const function *specialize(static_context *sctx, const std::vector<xqtref_t>& argTypes) const;
};


class GeneralOpComparison : public GenericOpComparison {
public:
  GeneralOpComparison (const signature &sig) : GenericOpComparison (sig) {}

  bool isGeneralComparisonFunction () const { return true; }
};



void populateContext_Boolean(static_context *sctx);
void populateContext_Comparison(static_context *sctx);
  
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
