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
  class xqpStringStore;

  class PlanIterator;
  typedef rchandle<PlanIterator> PlanIter_t;

  class FnBooleanIterator;
#ifndef ZORBA_NO_XMLSCHEMA
  class ValidateIterator;
#endif
  class LogicIterator;
  class CompareIterator;
  class AtomicValuesEquivalenceIterator;
  class UDFunctionCallIterator;
  class StatelessExtFunctionCallIterator;
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
  template < class AddOperation, TypeConstants::atomic_type_code_t > class SpecificNumArithIterator;
  template < class SubtractOperation, TypeConstants::atomic_type_code_t > class SpecificNumArithIterator;
  template < class MultiplyOperation, TypeConstants::atomic_type_code_t > class SpecificNumArithIterator;
  template < class DivideOperation, TypeConstants::atomic_type_code_t > class SpecificNumArithIterator;
  template < TypeConstants::atomic_type_code_t > class TypedValueCompareIterator;

  class OpNumericUnaryIterator;
  class OpDoubleUnaryIterator;

  class FnIdIterator;
  class FnIdRefIterator;
  class FnDistinctValuesIterator;
  class FnMinMaxIterator;
  class TextIterator;
  class DocumentIterator;
  class DocumentContentIterator;
  class CastIterator;
  class NameCastIterator;
  class CastableIterator;
  class PromoteIterator;
  class CtxVarIterator;
  class CtxVarDeclIterator;
  class CtxVarAssignIterator;
  class CtxVarExistsIterator;
  class EvalIterator;
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
  class CreateTupleIterator;
  class GetTupleFieldIterator;
  class FTContainsIterator;

  class ZorbaSchemaTypeIterator;
#ifdef ZORBA_WITH_TIDY
  class ZorbaTidyIterator;
  class ZorbaTDocIterator;
#endif  /* ZORBA_WITH_TIDY */
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

  class ZorbaDebugIterator;
  class DebuggerSingletonIterator;

#ifdef ZORBA_WITH_REST
  class ZorbaRestGetIterator;
  class ZorbaRestPostIterator;
  class ZorbaRestPutIterator;
  class ZorbaRestDeleteIterator;
  class ZorbaRestHeadIterator;
#endif

  class HoistIterator;
  class UnhoistIterator;

class IndexRangeProbeIterator;
class IndexPointProbeIterator;
class IndexGeneralPointProbeIterator;
class IndexGeneralRangeProbeIterator;
class ValueIndexEntryBuilderIterator;
class GeneralIndexEntryBuilderIterator;
class RefreshIndexIterator;
class CreateIndexIterator;
class CreateInternalIndexIterator;
class DeleteIndexIterator;

class DynamicFnCallIterator;


 #define PLAN_ITER_VISITOR(class)                \
  virtual void beginVisit ( const class& ) = 0;  \
  virtual void endVisit ( const class& ) = 0

