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

class PlanIterator;
typedef rchandle<PlanIterator> PlanIter_t;

class FnBooleanIterator;
#ifndef ZORBA_NO_XMLSCHEMA
class ValidateIterator;
#endif
class OrIterator;
class AndIterator;
  class CompareIterator;
  class AtomicValuesEquivalenceIterator;
  class UDFunctionCallIterator;
  class ExtFunctionCallIterator;
  class ElementIterator;
  class AttributeIterator;
  class CommentIterator;
  class PiIterator;
  class RefIterator;
  class SingletonIterator;
  class EmptyIterator;
  class ForVarIterator;
  typedef rchandle<ForVarIterator> ForVarIter_t;
  class LetVarIterator;
  typedef rchandle<LetVarIterator> LetVarIter_t;
  class EnclosedIterator;
  class IfThenElseIterator;
  class TryCatchIterator;
  class NodeDistinctIterator;
  class NodeSortIterator;
  class AxisIteratorHelper;
  template <class Object, class State> class AxisIterator;
  class SelfAxisIterator;
  class AttributeAxisIterator;
  class ParentAxisIterator;
  class AncestorAxisIterator;
  class AncestorReverseAxisIterator;
  class AncestorSelfAxisIterator;
  class AncestorSelfReverseAxisIterator;
  class RSiblingAxisIterator;
  class LSiblingAxisIterator;
  class LSiblingReverseAxisIterator;
  class ChildAxisIterator;
  class DescendantAxisIterator;
  class DescendantSelfAxisIterator;
  class PrecedingAxisIterator;
  class PrecedingReverseAxisIterator;
  class FollowingAxisIterator;
  class PathIterator;
  class InstanceOfIterator;
  class TreatIterator;
  class EitherNodesOrAtomicsIterator;
  class AddOperation;
  class SubtractOperation;
  class MultiplyOperation;
  class DivideOperation;
  class IntegerDivideOperation;
  class ModOperation;
  template < class AddOperation> class NumArithIterator;
  template < class SubtractOperation> class NumArithIterator;
  template < class MultiplyOperation> class NumArithIterator;
  template < class DivideOperation> class NumArithIterator;
  template < class IntegerDivideOperation> class NumArithIterator;
  template < class ModOperation> class NumArithIterator;
  template < class AddOperation> class GenericArithIterator;
  template < class SubtractOperation> class GenericArithIterator;
  template < class MultiplyOperation> class GenericArithIterator;
  template < class DivideOperation> class GenericArithIterator;
  template < class IntegerDivideOperation> class GenericArithIterator;
  template < class ModOperation> class GenericArithIterator;
  template < class AddOperation, store::SchemaTypeCode > class SpecificNumArithIterator;
  template < class SubtractOperation, store::SchemaTypeCode > class SpecificNumArithIterator;
  template < class MultiplyOperation, store::SchemaTypeCode > class SpecificNumArithIterator;
  template < class DivideOperation, store::SchemaTypeCode > class SpecificNumArithIterator;
  template < store::SchemaTypeCode > class TypedValueCompareIterator;

  class OpNumericUnaryIterator;
  class OpDoubleUnaryIterator;

  class FnIdIterator;
  class FnElementWithIdIterator;
  class FnIdRefIterator;
  class FnDistinctValuesIterator;
  class FnMinMaxIterator;
  class TextIterator;
  class DocumentIterator;
  class CastIterator;
  class NameCastIterator;
  class CastableIterator;
  class PromoteIterator;

  class CtxVarIterator;
  class CtxVarDeclareIterator;
  class CtxVarAssignIterator;
  class CtxVarIsSetIterator;

  class FnDateTimeConstructorIterator;
  class FnAdjustToTimeZoneIterator_1;
  class FnAdjustToTimeZoneIterator_2;
  class FnFormatDateTimeIterator;

  class InsertIterator;
  class DeleteIterator;
  class ReplaceIterator;
  class RenameIterator;
  class TransformIterator;
  class ApplyIterator;

  class FTContainsIterator;

  class ZorbaSchemaTypeIterator;
//   class ZorbaRandomIterator;
#ifdef ZORBA_WITH_FOP
  class ZorbaFopIterator;
#endif

namespace flwor
{
  class FLWORIterator;
  class TupleStreamIterator;
  class TupleSourceIterator;
  class ForIterator;
  class OuterForIterator;
  class LetIterator;
  class WhereIterator;
  class CountIterator;
  class GroupByIterator;
  class OrderByIterator;
  class WindowIterator;
}

#ifdef ZORBA_WITH_DEBUGGER
class DebugIterator;
class DebuggerSingletonIterator;
#endif

class HoistIterator;
class UnhoistIterator;

class ProbeIndexPointValueIterator;
class ProbeIndexPointGeneralIterator;
class ProbeIndexRangeValueIterator;
class ProbeIndexRangeGeneralIterator;
class ValueIndexEntryBuilderIterator;
class GeneralIndexEntryBuilderIterator;
class RefreshIndexIterator;
class CreateIndexIterator;
class CreateInternalIndexIterator;
class DeleteIndexIterator;

class DynamicFnCallIterator;

class EvalIterator;

class MaterializeIterator;

class SequentialIterator;
class ExitIterator;
class ExitCatcherIterator;
class LoopIterator;
class FlowCtlIterator;

class CountCollectionIterator;

#define PLAN_ITER_VISITOR(class)                \
virtual void beginVisit ( const class& ) = 0;  \
virtual void endVisit ( const class& ) = 0

/* vim:set et sw=2 ts=2: */
