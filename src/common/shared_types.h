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
#ifndef ZORBA_SHARED_TYPES_H
#define ZORBA_SHARED_TYPES_H

#include "zorbamisc/config/platform.h"

#include "zorbatypes/rchandle.h"

#include "store/api/shared_types.h"

namespace zorba
{

class XQueryDiagnostics;

namespace types
{
  class TypeIdentifier;
};


class TypeManager;
class XQType;
class NodeNameTest;
typedef const_rchandle<XQType> xqtref_t;
typedef rchandle<NodeNameTest> NodeNameTest_t;

class XQPCollator;

class QueryLoc;

class function;
typedef rchandle<function> function_t;

class user_function;
typedef rchandle<user_function> user_function_t;

class ItemIterator;

class CompilerCB;
class XQueryCompiler;
class XQueryCompilerSubsystem;
class Rewriter;
class RewriterContext;

class context;
class static_context;
class dynamic_context;
class namespace_context;
typedef rchandle<static_context> static_context_t;

/* runtime */
class RuntimeCB;
class PlanWrapper;
class PlanIterator;
class PlanState;
class ForVarIterator;
class LetVarIterator;

typedef rchandle<PlanIterator> PlanIter_t;
typedef rchandle<PlanWrapper> PlanWrapper_t;
typedef rchandle<ItemIterator> ItemIterator_t;
typedef rchandle<ForVarIterator> ForVarIter_t;
typedef rchandle<LetVarIterator> LetVarIter_t;

class ValueIndexInsertSession;
typedef rchandle<ValueIndexInsertSession> ValueIndexInsertSession_t;


// Parsenodes
class parsenode;
class exprnode;
typedef rchandle<parsenode> parsenode_t;

// Annotations
class AnnotationList;
typedef rchandle<AnnotationList> AnnotationList_t;

// Expression nodes
class expr;
class fo_expr;
class var_expr;
class flwor_clause;
class forletwin_clause;
class for_clause;
class let_clause;

class ItemVariableIterator;
typedef rchandle<ItemVariableIterator> ItemVariableIterator_t;

typedef rchandle<namespace_context> NamespaceContext_t;

typedef rchandle<CompilerCB> CompilerCB_t;


/* datetime stuff */
class DateTime;
class Date;
class Decimal;
class Duration;
class Time;
class TimeZone;
class GYearMonth;
class GYear;
class GMonthDay;
class GDay;
class GMonth;
class xqpString;
class xqpStringStore;
typedef rchandle<xqpStringStore> xqpStringStore_t;
typedef rchandle<DateTime> DateTime_t;
typedef rchandle<Date> Date_t;
typedef rchandle<Time> Time_t;
typedef rchandle<TimeZone> TimeZone_t;
typedef rchandle<Duration> Duration_t;
typedef rchandle<GYearMonth> GYearMonth_t;
typedef rchandle<GYear> GYear_t;
typedef rchandle<GMonthDay> GMonthDay_t;
typedef rchandle<GDay> GDay_t;
typedef rchandle<GMonth> GMonth_t;

/* numerics */
template<typename FloatType> class FloatImpl;
typedef FloatImpl<double> Double;
typedef FloatImpl<float>  Float;
#ifdef ZORBA_WITH_BIG_INTEGER
class IntegerImpl;
typedef IntegerImpl Integer;
typedef IntegerImpl UInteger;
#else
template<typename IntType> class IntegerImpl;
typedef IntegerImpl<long long> Integer;
typedef IntegerImpl<unsigned long long> UInteger;
#endif /* ZORBA_WITH_BIG_INTEGER */

/* api */
class serializer;

} // namespace zorba

#endif /* ZORBA_SHARED_TYPES_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
