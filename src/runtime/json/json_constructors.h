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


namespace zorba {


/*********************************************************************************

*********************************************************************************/
class JSONArrayIterator : public NaryBaseIterator<JSONArrayIterator,
                                                  PlanIteratorState>
{
protected:
  std::vector<bool> theCopyInputs;

public:
  SERIALIZABLE_CLASS(JSONArrayIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  JSONArrayIterator,
  NaryBaseIterator<JSONArrayIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  JSONArrayIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& content,
      bool copyInput);

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*********************************************************************************

*********************************************************************************/
class JSONPairIterator : public BinaryBaseIterator<JSONPairIterator,
                                                   PlanIteratorState>
{
protected:
  bool theCopyInput;

public:
  SERIALIZABLE_CLASS(JSONPairIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  JSONPairIterator,
  BinaryBaseIterator<JSONPairIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  JSONPairIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t& name,
      PlanIter_t& value,
      bool copyInput);

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*********************************************************************************

*********************************************************************************/
class JSONObjectIterator : public NaryBaseIterator<JSONObjectIterator,
                                                   PlanIteratorState>
{
protected:
  std::vector<bool> theCopyInputs;

public:
  SERIALIZABLE_CLASS(JSONObjectIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  JSONObjectIterator,
  NaryBaseIterator<JSONObjectIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  JSONObjectIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children,
      bool copyInput);

  bool isConstructor() const { return true; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


}

#endif // ZORBA_WITH_JSON

#endif
