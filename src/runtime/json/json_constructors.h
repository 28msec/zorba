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
#pragma once
#ifndef ZORBA_RUNTIME_JSON_CONSTRUCTORS
#define ZORBA_RUNTIME_JSON_CONSTRUCTORS

#ifdef ZORBA_WITH_JSON

#include "common/shared_types.h"

#include "runtime/base/narybase.h"
#include "runtime/base/binarybase.h"

#include "store/api/copymode.h"

namespace zorba {


/*********************************************************************************

*********************************************************************************/
class JSONArrayIteratorState : public PlanIteratorState
{
public:
  std::vector<store::CopyMode>   theCopyModes;
  std::vector<store::Iterator_t> theSourcesWrappers;

public:
  void open(
      PlanState& planState,
      const std::vector<PlanIter_t>& sources,
      const std::vector<bool>& copyInputs);
};


class JSONArrayIterator : public NaryBaseIterator<JSONArrayIterator,
                                                  JSONArrayIteratorState>
{
protected:
  std::vector<bool> theCopyInputs;

public:
  SERIALIZABLE_CLASS(JSONArrayIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  JSONArrayIterator,
  NaryBaseIterator<JSONArrayIterator, JSONArrayIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  JSONArrayIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& content,
      bool copyInput);

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*********************************************************************************

*********************************************************************************/
class JSONObjectIteratorState : public PlanIteratorState
{
public:
  std::vector<store::CopyMode>   theCopyModes;
  std::vector<store::Iterator_t> theSourcesWrappers;

public:
  void open(
      PlanState& planState,
      const std::vector<PlanIter_t>& sources,
      const std::vector<bool>& copyInputs);
};


class JSONObjectIterator : public NaryBaseIterator<JSONObjectIterator,
                                                   JSONObjectIteratorState>
{
protected:
  std::vector<bool> theCopyInputs;
  bool              theIsAccumulating;

public:
  SERIALIZABLE_CLASS(JSONObjectIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  JSONObjectIterator,
  NaryBaseIterator<JSONObjectIterator, JSONObjectIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  JSONObjectIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children,
      bool copyInput,
      bool accumulating);

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*********************************************************************************

*********************************************************************************/
class JSONDirectObjectIterator : public NaryBaseIterator<JSONDirectObjectIterator,
                                                         PlanIteratorState>
{
protected:
  std::vector<bool> theCopyInputs;

public:
  SERIALIZABLE_CLASS(JSONDirectObjectIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONDirectObjectIterator,
  NaryBaseIterator<JSONDirectObjectIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  JSONDirectObjectIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& names,
      std::vector<PlanIter_t>& values,
      bool copyInput);

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


}

#endif // ZORBA_WITH_JSON

#endif
