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

namespace zorba 
{

  namespace error 
  {
    class ErrorManager;
    class ZorbaError;
  }
  
  namespace store 
  {
    class CopyMode;
    class Item;
    typedef rchandle<Item> Item_t;
    class ItemIterator;
    typedef rchandle<ItemIterator> ItemIterator_t;
    class TempSeq;
    typedef rchandle<TempSeq> TempSeq_t;
    class PUL;
    typedef rchandle<PUL> PUL_t;
    class ItemFactory;
    class IteratorFactory;
    class Collection;
    typedef rchandle<Collection> Collection_t;
    class AnyUriItem;
    typedef rchandle<AnyUriItem> AnyUriItem_t;
    class Store;
    class XmlDataManager_Impl;
    class Iterator;
    typedef rchandle<Iterator> Iterator_t;
  }

  namespace types 
  {
    class TypeIdentifier; 
  };

class TypeManager;
class CollationCache;

class QueryLoc;
class XQType;
class namespace_context;
class function;
class user_function;
class ItemIterator;
class PlanIterator;
class PlanState;
class XQueryCompiler;
class XQueryCompilerSubsystem;
class Rewriter;
class RewriterContext;
class NodeNameTest;

class context;
class static_context;
class dynamic_context;
class CompilerCB;
class PlanWrapper;

// Parsenodes
class parsenode; class exprnode;

// Expression nodes
class expr; class var_expr;

class XQPCollator;
class ItemVariableIterator;
typedef rchandle<ItemVariableIterator> ItemVariableIterator_t;

typedef rchandle<parsenode> parsenode_t;
typedef rchandle<expr> expr_t;
typedef const_rchandle<XQType> xqtref_t;
typedef rchandle<namespace_context> NamespaceContext_t;
typedef rchandle<PlanIterator> PlanIter_t;

typedef rchandle<NodeNameTest> NodeNameTest_t;
typedef rchandle<static_context> static_context_t;
typedef rchandle<CompilerCB> CompilerCB_t;
typedef rchandle<PlanWrapper> PlanWrapper_t;
typedef rchandle<PlanIterator> PlanIterator_t;
typedef rchandle<ItemIterator> ItemIterator_t;

/* datetime stuff */
class DateTime;
class Date;
class DayTimeDuration;
class Decimal;
class Duration;
class Time;
class TimeZone;
class YearMonthDuration;
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
typedef rchandle<DayTimeDuration> DayTimeDuration_t;
typedef rchandle<YearMonthDuration> YearMonthDuration_t;
typedef rchandle<Duration> Duration_t;
typedef rchandle<GYearMonth> GYearMonth_t;
typedef rchandle<GYear> GYear_t;
typedef rchandle<GMonthDay> GMonthDay_t;
typedef rchandle<GDay> GDay_t;
typedef rchandle<GMonth> GMonth_t;

/* numerics */
template <class Object> class FloatImpl;
class Integer;

/* numerics */
typedef FloatImpl<double> Double;
typedef FloatImpl<float>  Float;

/* runtime */
class RuntimeCB;
class ForVarIterator;
typedef rchandle<ForVarIterator> ForVarIter_t;

class LetVarIterator;
typedef rchandle<LetVarIterator> LetVarIter_t;

/* api */
class serializer;

}

#endif /* ZORBA_SHARED_TYPES_H */
/* vim:set ts=2 sw=2: */
