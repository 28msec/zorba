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
#ifndef ZORBA_RUNTIME_ACCESS_ACCESS_H
#define ZORBA_RUNTIME_ACCESS_ACCESS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 *      Summary: returns a list of environment variable names that are suitable for 
 *      passing to fn:environment-variable, as a (possible empty) sequence of 
 *      strings.
 *      
 *      The function returns a sequence of strings, being the names of the environment 
 *      variables in the dynamic context in some implementation-defined order.
 *    
 * Author: Zorba Team
 */
class FnAvailableEnvironmentVariablesIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theIterator; //the current iterator

  FnAvailableEnvironmentVariablesIteratorState();

  ~FnAvailableEnvironmentVariablesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnAvailableEnvironmentVariablesIterator : public NaryBaseIterator<FnAvailableEnvironmentVariablesIterator, FnAvailableEnvironmentVariablesIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnAvailableEnvironmentVariablesIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnAvailableEnvironmentVariablesIterator,
    NaryBaseIterator<FnAvailableEnvironmentVariablesIterator, FnAvailableEnvironmentVariablesIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnAvailableEnvironmentVariablesIterator, FnAvailableEnvironmentVariablesIteratorState>*)this);
  }

  FnAvailableEnvironmentVariablesIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnAvailableEnvironmentVariablesIterator, FnAvailableEnvironmentVariablesIteratorState>(sctx, loc, children)
  {}

  virtual ~FnAvailableEnvironmentVariablesIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      Summary: Returns the value of a system environment variable, if it exists.
 *
 *      If there is no environment variable with a matching name, the function returns 
 *      the empty sequence.
 *    
 * Author: Zorba Team
 */
class FnEnvironmentVariableIterator : public NaryBaseIterator<FnEnvironmentVariableIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnEnvironmentVariableIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnEnvironmentVariableIterator,
    NaryBaseIterator<FnEnvironmentVariableIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnEnvironmentVariableIterator, PlanIteratorState>*)this);
  }

  FnEnvironmentVariableIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnEnvironmentVariableIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnEnvironmentVariableIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
