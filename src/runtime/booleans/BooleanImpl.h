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
  static bool effectiveBooleanValue (
        const QueryLoc& loc,
        PlanState& planState,
        const PlanIterator* ,
        bool negate = false);
};


/*******************************************************************************

********************************************************************************/
class LogicIterator : public BinaryBaseIterator<LogicIterator, PlanIteratorState>
{
public:
  enum LogicType {
    AND, OR
  };

private:
  LogicType theLogicType;

public:
  SERIALIZABLE_CLASS(LogicIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  LogicIterator,
  BinaryBaseIterator<LogicIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (BinaryBaseIterator<LogicIterator, PlanIteratorState>*)this);
    SERIALIZE_ENUM(LogicType, theLogicType)
  }

public:
  LogicIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t aChild0,
        PlanIter_t aChild1,
        LogicType aLogicType);

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
  long                        theTimezone;
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
  /**
   * Value comparison of the passed two items with the operator
   * which is defined in the CompareIterator object.
   *
   * @param item0
   * @param item1
   * @param aCompType
   * @param aCollation optional collation parameter
   * @return
   */
  static bool valueComparison(
        const QueryLoc& loc,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        CompareConsts::CompareType aCompType,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  /**
   * Value Equal on the passed items
   *
   * @param aItem0
   * @param aItem1
   * @param aCollation optional collation parameter
   * @return 1 (equal), 0 (not equal), -2 (value equal not possible)
   */
  static bool valueEqual(
        const QueryLoc& loc,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  /**
   * Value Comparison on the passed items
   * @param aItem0
   * @param aItem1
   * @param aCollation options collation parameter
   * @return -1 (smaller),
   *          0 (equal),
   *          1 (bigger),
   *          2 (not equal, not bigger, not smaller),
   *         -2 (value comparison not possible)
   */
  static long valueCompare(
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  /**
   * General comparison of the passed two items with the operator
   * which is defined in the CompareIterator object.
   *
   * @param item0
   * @param item1
   * @param aCompType
   * @param aCollation optional collation parameter
   * @return
   */
  static bool generalComparison(
        const QueryLoc& loc,
        store::Item_t& aItem0,
        store::Item_t& aItem_1,
        CompareConsts::CompareType aCompType,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator*   aCollation);

  /**
   * General Equal on the passed items
   * @param aItem0
   * @param aItem1
   * @param aCollation options collation parameter
   * @return 1 (equal), 0 (not equal), -2 (general equal not possible)
   */
  static bool generalEqual(
        const QueryLoc& loc,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  /**
   * General Comparison on the passed items
   * @param aItem0
   * @param aItem1
   * @param aCollation options collation parameter (passed as pointer to make it possible to be set to 0)
   * @return -1 (smaller), 0 (equal), 1 (bigger),
   *          2 (not equal, not bigger, not smaller), -2 (general comparison not possible)
   */
  static long generalCompare(
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  /**
   * Checks if the two passed items contain the same value (without performing and
   * castings or promotions on the two items). 
   *
   * @param  item0
   * @param  item1
   * @param  aCollation optional collation parameter (passed as pointer to make
   *         it possible to be set to 0)
   * @return true if the two item are equal; false otherwise.
   * @throw  XPTY0004 if the two items are not comparable
   */
  static bool equal(
        const QueryLoc& loc,
        const store::Item_t& aItem0,
        const store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

  /**
   * Compares two items (without castings and promotions which are used in general
   * and value comparison).
   * @param item0
   * @param item1
   * @param aCollation optional collation parameter (passed as pointer to make
   *        it possible to be set to 0)
   * @return -1, if item0 &lt; item1
   *          0, if item0 == item1
   *          1, if item0 &gt; item1
   *          2, if item0 not equal, not bigger, not smaller item1 (special case
   *             when an Item has the value NaN)
   *         -2, if it is not possible to compare the values the two passed items
   */
  static long compare(
        const store::Item_t& aItem0,
        const store::Item_t& aItem1,
        const TypeManager* typemgr,
        long timezone,
        XQPCollator* aCollation);

private:
  static void valueCasting(
        const TypeManager* typemgr,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        store::Item_t& castItem0,
        store::Item_t& castItem1);

  static void generalCasting(
        const TypeManager* typemgr,
        store::Item_t& aItem0,
        store::Item_t& aItem1,
        store::Item_t& castItem0,
        store::Item_t& castItem1);
};


/*******************************************************************************

********************************************************************************/
template <TypeConstants::atomic_type_code_t ATC>
class TypedValueCompareIterator : public NaryBaseIterator<TypedValueCompareIterator<ATC>,
                                                          PlanIteratorState>
{
  CompareConsts::CompareType  theCompType;
  long                        theTimezone;
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
    theTimezone (0),
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
class AtomicValuesEquivalenceIterator : public BinaryBaseIterator<AtomicValuesEquivalenceIterator, PlanIteratorState>
{
private:
  CompareConsts::CompareType  theCompType;
  TypeManager               * theTypeManager;
  long                        theTimezone;
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
    serialize_baseclass(ar, (BinaryBaseIterator<AtomicValuesEquivalenceIterator, PlanIteratorState>*)this);

	SERIALIZE_ENUM(CompareConsts::CompareType, theCompType);
    SERIALIZE_TYPEMANAGER(TypeManager, theTypeManager);
    ar & theTimezone;
    ar & theCollation;
  }

public:
  AtomicValuesEquivalenceIterator(static_context* sctx,
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
