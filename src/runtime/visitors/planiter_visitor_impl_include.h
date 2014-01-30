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

class AddOperation;
class AncestorAxisIterator;
class AncestorReverseAxisIterator;
class AncestorSelfAxisIterator;
class AncestorSelfReverseAxisIterator;
class AndIterator;
class ApplyIterator;
class ArgumentPlaceholderIterator;
class AtomicValuesEquivalenceIterator;
class AttributeAxisIterator;
class AttributeIterator;
class AxisIteratorHelper;
class CastableIterator;
class CastIterator;
class ChildAxisIterator;
class CommentIterator;
class CompareIterator;
class CreateIndexIterator;
class CreateInternalIndexIterator;
class CtxVarAssignIterator;
class CtxVarDeclareIterator;
class CtxVarIsSetIterator;
class CtxVarIterator;
#ifdef ZORBA_WITH_DEBUGGER
class DebugIterator;
class DebuggerSingletonIterator;
#endif
class DeleteIndexIterator;
class DeleteIterator;
class DescendantAxisIterator;
class DescendantSelfAxisIterator;
class DivideOperation;
class DocumentIterator;
class EitherNodesOrAtomicsIterator;
class ElementIterator;
class EmptyIterator;
class EnclosedIterator;
class EvalIterator;
class ExitCatcherIterator;
class ExitIterator;
class ExtFunctionCallIterator;
class FlowCtlIterator;
class FnAdjustToTimeZoneIterator_1;
class FnAdjustToTimeZoneIterator_2;
class FnBooleanIterator;
class FnDateTimeConstructorIterator;
class FnDistinctValuesIterator;
class FnElementWithIdIterator;
class FnFormatDateTimeIterator;
class FnIdIterator;
class FnIdRefIterator;
class FnMinMaxIterator;
class FollowingAxisIterator;
class ForVarIterator;
class FTContainsIterator;
class FunctionItemIterator;
class GeneralIndexEntryBuilderIterator;
class HoistIterator;
class IfThenElseIterator;
class InsertIterator;
class InstanceOfIterator;
class IntegerDivideOperation;
class JSONArrayIterator;
class JSONDirectObjectIterator;
class JSONObjectInsertIterator;
class JSONObjectIterator;
class LetVarIterator;
class LoopIterator;
class LSiblingAxisIterator;
class LSiblingReverseAxisIterator;
class MaterializeIterator;
class ModOperation;
class MultiDynamicFnCallIterator;
class MultiplyOperation;
class NameCastIterator;
class NamespaceIterator;
class NodeDistinctIterator;
class NodeSortIterator;
class OpDoubleUnaryIterator;
class OpNumericUnaryIterator;
class OrIterator;
class ParentAxisIterator;
class PathIterator;
class PiIterator;
class PlanIterator;
class PrecedingAxisIterator;
class PrecedingReverseAxisIterator;
class ProbeIndexPointGeneralIterator;
class ProbeIndexPointValueIterator;
class ProbeIndexRangeGeneralIterator;
class ProbeIndexRangeValueIterator;
class PromoteIterator;
class RefIterator;
class RefreshIndexIterator;
class RenameIterator;
class ReplaceIterator;
class RSiblingAxisIterator;
class SelfAxisIterator;
class SequentialIterator;
class SingleDynamicFnCallIterator;
class SingletonIterator;
class SubtractOperation;
class TextIterator;
class TransformIterator;
class TreatIterator;
class TryCatchIterator;
class UDFunctionCallIterator;
class UnhoistIterator;
#ifndef ZORBA_NO_XMLSCHEMA
class ValidateIterator;
#endif
class ValueIndexEntryBuilderIterator;
#ifdef ZORBA_WITH_FOP
class ZorbaFopIterator;
#endif
//class ZorbaRandomIterator;
class ZorbaSchemaTypeIterator;

namespace flwor
{
  class CountIterator;
  class FLWORIterator;
  class ForIterator;
  class GroupByIterator;
  class LetIterator;
  class OrderByIterator;
  class OuterForIterator;
  class TupleSourceIterator;
  class TupleStreamIterator;
  class WhereIterator;
  class WindowIterator;
}

template<class Object,class State> class AxisIterator;
template<class AddOperation> class NumArithIterator;
template<class SubtractOperation> class NumArithIterator;
template<class MultiplyOperation> class NumArithIterator;
template<class DivideOperation> class NumArithIterator;
template<class IntegerDivideOperation> class NumArithIterator;
template<class ModOperation> class NumArithIterator;
template<class AddOperation> class GenericArithIterator;
template<class SubtractOperation> class GenericArithIterator;
template<class MultiplyOperation> class GenericArithIterator;
template<class DivideOperation> class GenericArithIterator;
template<class IntegerDivideOperation> class GenericArithIterator;
template<class ModOperation> class GenericArithIterator;
template<class AddOperation,store::SchemaTypeCode> class SpecificNumArithIterator;
template<class SubtractOperation,store::SchemaTypeCode> class SpecificNumArithIterator;
template<class MultiplyOperation,store::SchemaTypeCode> class SpecificNumArithIterator;
template<class DivideOperation,store::SchemaTypeCode> class SpecificNumArithIterator;
template<store::SchemaTypeCode> class TypedValueCompareIterator;

typedef rchandle<LetVarIterator> LetVarIter_t;
typedef rchandle<ForVarIterator> ForVarIter_t;
typedef rchandle<PlanIterator> PlanIter_t;

#define PLAN_ITER_VISITOR(...)                        \
  virtual void beginVisit( __VA_ARGS__ const& ) = 0;  \
  virtual void endVisit( __VA_ARGS__ const& ) = 0

/* vim:set et sw=2 ts=2: */
