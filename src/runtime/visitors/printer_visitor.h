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

#ifndef ZORBA_RUNTIME_PRINTER_VISITOR_H
#define ZORBA_RUNTIME_PRINTER_VISITOR_H

#include "runtime/visitors/planiter_visitor.h"

#include "common/common.h"

namespace zorba {

  class PlanIterator;
  class IterPrinter;

  void print_iter_plan (IterPrinter& aPrinter, PlanIterator* aIter);

  class PrinterVisitor : public PlanIterVisitor {
  private:
    IterPrinter& thePrinter;
    PlanIterator* theIterator;
    int theId;
  public:
    PrinterVisitor(IterPrinter& aPrinter, PlanIterator* aIter)
    :    thePrinter(aPrinter), theIterator(aIter), theId(0) {}

    void print();
    void printCommons(const PlanIterator* aIter, int theId);

#include "runtime/visitors/printer_visitor_impl.h"

    void beginVisit( const FnConcatIterator& );
    void endVisit  ( const FnConcatIterator& );

    void beginVisit( const FnIndexOfIterator& );
    void endVisit  ( const FnIndexOfIterator& );

    void beginVisit( const FnEmptyIterator& );
    void endVisit  ( const FnEmptyIterator& );

    void beginVisit( const FnExistsIterator& );
    void endVisit  ( const FnExistsIterator& );

    void beginVisit( const FnInsertBeforeIterator& );
    void endVisit  ( const FnInsertBeforeIterator& );

    void beginVisit( const FnRemoveIterator& );
    void endVisit  ( const FnRemoveIterator& );

    void beginVisit( const FnReverseIterator& );
    void endVisit  ( const FnReverseIterator& );

    void beginVisit( const FnSubsequenceIterator& );
    void endVisit  ( const FnSubsequenceIterator& );

    void beginVisit( const FnZeroOrOneIterator& );
    void endVisit  ( const FnZeroOrOneIterator& );

    void beginVisit( const FnOneOrMoreIterator& );
    void endVisit  ( const FnOneOrMoreIterator& );

    void beginVisit( const FnExactlyOneIterator& );
    void endVisit  ( const FnExactlyOneIterator& );

    void beginVisit( const FnDeepEqualIterator& );
    void endVisit  ( const FnDeepEqualIterator& );

    void beginVisit( const HashSemiJoinIterator& );
    void endVisit  ( const HashSemiJoinIterator& );

    void beginVisit( const SortSemiJoinIterator& );
    void endVisit  ( const SortSemiJoinIterator& );

    void beginVisit( const FnCountIterator& );
    void endVisit  ( const FnCountIterator& );

    void beginVisit( const FnAvgIterator& );
    void endVisit  ( const FnAvgIterator& );

    void beginVisit( const FnSumIterator& );
    void endVisit  ( const FnSumIterator& );

    void beginVisit( const FnSumDoubleIterator& );
    void endVisit  ( const FnSumDoubleIterator& );

    void beginVisit( const FnSumFloatIterator& );
    void endVisit  ( const FnSumFloatIterator& );

    void beginVisit( const FnSumDecimalIterator& );
    void endVisit  ( const FnSumDecimalIterator& );

    void beginVisit( const FnSumIntegerIterator& );
    void endVisit  ( const FnSumIntegerIterator& );

    void beginVisit( const OpToIterator& );
    void endVisit  ( const OpToIterator& );

    void beginVisit( const FnDocIterator& );
    void endVisit  ( const FnDocIterator& );

    void beginVisit( const FnDocAvailableIterator& );
    void endVisit  ( const FnDocAvailableIterator& );

    void beginVisit( const FnParseIterator& );
    void endVisit  ( const FnParseIterator& );

  }; //class PrinterVisitor
} //namespace zorba


#endif