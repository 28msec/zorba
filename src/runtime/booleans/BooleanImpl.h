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
#ifndef ZORBA_RUNTIME_BOOLEAN
#define ZORBA_RUNTIME_BOOLEAN

#include "common/shared_types.h"

#include "types/typeconstants.h"
#include "types/typemanager.h"

#include "compiler/expression/expr_consts.h"

#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"

#include "system/globalenv.h"


namespace zorba
{

class RuntimeCB; // TODO we should have a shared_runtime_types.h
class GenericCast;


/*******************************************************************************
  15.1.1 fn:boolean
  fn:boolean($arg as item()*) as xs:boolean

  Computes the effective boolean value of the sequence $arg.
********************************************************************************/
class FnBooleanIterator : public UnaryBaseIterator<FnBooleanIterator, PlanIteratorState>
{
private:
  bool theNegate;

public:
  SERIALIZABLE_CLASS(FnBooleanIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  FnBooleanIterator,
  UnaryBaseIterator<FnBooleanIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (UnaryBaseIterator<FnBooleanIterator, PlanIteratorState>*)this);

    ar & theNegate;
  }

public:
  FnBooleanIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t& aIter,
      bool aNegate = false );

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

public:
  /**
   * Static function which computes the effective boolean value of a passed iterator.
   *
   * @param loc location of the iterator which invokes this function
   * @param planState
   * @param iterator
   * @param negate optinal parameter which negates the effective boolean value (default == false)
   * @return effective boolean value
   */
  static bool effectiveBooleanValue(
      const QueryLoc& loc,
      PlanState& planState,
      const PlanIterator* ,
      bool negate = false);
};


/*******************************************************************************

********************************************************************************/
class OrIterator : public NaryBaseIterator<OrIterator, PlanIteratorState>
{
public:
  SERIALIZABLE_CLASS(OrIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  OrIterator,
  NaryBaseIterator<OrIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  OrIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& inChildren);

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************

********************************************************************************/
class AndIterator : public NaryBaseIterator<AndIterator, PlanIteratorState>
{
public:
  SERIALIZABLE_CLASS(AndIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  AndIterator,
  NaryBaseIterator<AndIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  AndIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& inChildren);

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************
  Iterator for general and value comparisons
********************************************************************************/
class CompareIterator : public BinaryBaseIterator<CompareIterator, PlanIteratorState>
{
private:
  CompareConsts::CompareType  theCompType;
  bool                        theIsGeneralComparison;
  TypeManager               * theTypeManager;
  int32_t                     theTimezone;
  XQPCollator               * theCollation;

public:
  SERIALIZABLE_CLASS(CompareIterator);

  CompareIterator(::zorba::serialization::Archiver& ar)
    :
    BinaryBaseIterator<CompareIterator, PlanIteratorState>(ar),
    theTypeManager(NULL),
    theTimezone(0),
    theCollation(NULL)
  {
  }

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<CompareIterator, PlanIteratorState>*)this);

    SERIALIZE_ENUM(CompareConsts::CompareType, theCompType)
    ar & theIsGeneralComparison;
    SERIALIZE_TYPEMANAGER(TypeManager, theTypeManager);
    ar & theTimezone;
    ar & theCollation;
  }

public:
  CompareIterator (
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t theChild0,
        PlanIter_t theChild1,
        CompareConsts::CompareType aCompType);

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

public:
  static bool valueComparison(
        const QueryLoc& loc,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        CompareConsts::CompareType aCompType,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  static bool valueEqual(
        const QueryLoc& loc,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  static long valueCompare(
        const QueryLoc& loc,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  static bool generalComparison(
        const QueryLoc& loc,
        store::Item_t& aItem0,
        store::Item_t& aItem_1,
        CompareConsts::CompareType aCompType,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator*   aCollation);

  static bool generalEqual(
        const QueryLoc& loc,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  static long generalCompare(
        const QueryLoc& loc,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  static bool equal(
        const QueryLoc& loc,
        const store::Item_t& aItem0,
        const store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  static long compare(
        const QueryLoc& loc,
        const store::Item_t& aItem0,
        const store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

private:
  static void valueCasting(
        const QueryLoc& loc,
        const TypeManager* typemgr,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        store::Item_t& castItem0,
        store::Item_t& castItem1);

  static void generalCasting(
        const QueryLoc& loc,
        const TypeManager* typemgr,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        store::Item_t& castItem0,
        store::Item_t& castItem1);
};


/*******************************************************************************

********************************************************************************/
template <store::SchemaTypeCode ATC>
class TypedValueCompareIterator : public NaryBaseIterator<TypedValueCompareIterator<ATC>,
                                                          PlanIteratorState>
{
  CompareConsts::CompareType  theCompType;
  int32_t                     theTimezone;
  XQPCollator               * theCollation;

public:
  SERIALIZABLE_TEMPLATE_CLASS(TypedValueCompareIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  TypedValueCompareIterator,
  NaryBaseIterator<TypedValueCompareIterator<ATC>, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<TypedValueCompareIterator<ATC>, PlanIteratorState>*)this);

    SERIALIZE_ENUM(CompareConsts::CompareType, theCompType);
    ar & theTimezone;
    ar & theCollation;
  }

public:
  TypedValueCompareIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& children,
        CompareConsts::CompareType aCompType)
    :
    NaryBaseIterator<TypedValueCompareIterator<ATC>, PlanIteratorState>(sctx, loc, children),
    theCompType(aCompType),
    theTimezone(0),
    theCollation(NULL)
  {}

  ~TypedValueCompareIterator () {}

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};

/*******************************************************************************
  Atomic Values Equivalence Iterator

  http://www.w3.org/TR/xquery-11/#dt-equivalence-two-atomic-values
********************************************************************************/
class AtomicValuesEquivalenceIterator : 
public BinaryBaseIterator<AtomicValuesEquivalenceIterator, PlanIteratorState>
{
private:
  CompareConsts::CompareType  theCompType;
  TypeManager               * theTypeManager;
  int32_t                     theTimezone;
  XQPCollator               * theCollation;

public:
  SERIALIZABLE_CLASS(AtomicValuesEquivalenceIterator);

  AtomicValuesEquivalenceIterator(::zorba::serialization::Archiver& ar)
    :
    BinaryBaseIterator<AtomicValuesEquivalenceIterator, PlanIteratorState>(ar),
    theTypeManager(NULL),
    theTimezone(0),
    theCollation(NULL)
  {
  }

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<AtomicValuesEquivalenceIterator, PlanIteratorState>*)this);

    SERIALIZE_ENUM(CompareConsts::CompareType, theCompType);
    SERIALIZE_TYPEMANAGER(TypeManager, theTypeManager);
    ar & theTimezone;
    ar & theCollation;
  }

public:
  AtomicValuesEquivalenceIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t theChild0,
      PlanIter_t theChild1);

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

};

}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
