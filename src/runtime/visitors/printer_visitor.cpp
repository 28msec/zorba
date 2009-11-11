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

#include "runtime/visitors/printer_visitor.h"

// get forward declarations for all classes from planitervisitor.h

#include "runtime/visitors/planiter_visitor.h"

#include "runtime/visitors/iterprinter.h"

#include "util/properties.h"

#include "zorbautils/strutil.h"

#include "runtime/accessors/accessors.h"
#include "runtime/booleans/booleans.h"
#include "runtime/context/context.h"
#include "runtime/convertors/convertors.h"
#include "runtime/durations_dates_times/durations_dates_times.h"
#include "runtime/fnput/fnput.h"
#include "runtime/maths/maths.h"
#include "runtime/misc/misc.h"
#include "runtime/nodes/nodes.h"
#include "runtime/numerics/numerics.h"
#include "runtime/sequences/sequences.h"
#include "runtime/strings/strings.h"

namespace zorba{

void PrinterVisitor::print() {
  thePrinter.start();
  theIterator->accept(*this);
  thePrinter.stop();
}

void PrinterVisitor::printCommons(const PlanIterator* aIter, int theId) {
  if (! Properties::instance()->noTreeIds()) {
    std::stringstream lStream;
    if (Properties::instance()->stableIteratorIds())
      lStream << theId;
    else
      lStream << aIter;
    thePrinter.addAttribute("id", lStream.str());
  }
}

void PrinterVisitor::printNameOrKindTest(const AxisIteratorHelper* a) {
  thePrinter.addAttribute("test kind", toString(a->getTestKind()));

  if (a->getDocTestKind() != match_no_test)
    thePrinter.addAttribute("doc_test_kind", toString(a->getDocTestKind()));

  if (a->getQName() != 0)
    thePrinter.addAttribute("qname", a->getQName()->show());
  else
    thePrinter.addAttribute("qname","*");

  if (a->getType() != 0)
    thePrinter.addAttribute("typename", a->getType()->toString());
  else
    thePrinter.addAttribute("typename","*");

  std::stringstream lStream;
  lStream << a->nilledAllowed();
  thePrinter.addAttribute("nill allowed", lStream.str());

  if (a->getTargetPos() >= 0)
    thePrinter.addAttribute("target_position", to_string(a->getTargetPos()));
}

// <NodeNameIterator>
void PrinterVisitor::beginVisit ( const NodeNameIterator& a) {
  thePrinter.startBeginVisit("NodeNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NodeNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodeNameIterator>

// <NilledIterator>
void PrinterVisitor::beginVisit ( const NilledIterator& a) {
  thePrinter.startBeginVisit("NilledIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NilledIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NilledIterator>

// <FnStringIterator>
void PrinterVisitor::beginVisit ( const FnStringIterator& a) {
  thePrinter.startBeginVisit("FnStringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnStringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnStringIterator>

// <FnDataIterator>
void PrinterVisitor::beginVisit ( const FnDataIterator& a) {
  thePrinter.startBeginVisit("FnDataIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnDataIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDataIterator>

// <BaseUriIterator>
void PrinterVisitor::beginVisit ( const BaseUriIterator& a) {
  thePrinter.startBeginVisit("BaseUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const BaseUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </BaseUriIterator>

// <DocumentUriIterator>
void PrinterVisitor::beginVisit ( const DocumentUriIterator& a) {
  thePrinter.startBeginVisit("DocumentUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DocumentUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DocumentUriIterator>

// <RootIterator>
void PrinterVisitor::beginVisit ( const RootIterator& a) {
  thePrinter.startBeginVisit("RootIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const RootIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RootIterator>

// <IsSameNodeIterator>
void PrinterVisitor::beginVisit ( const IsSameNodeIterator& a) {
  thePrinter.startBeginVisit("IsSameNodeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsSameNodeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsSameNodeIterator>

// <NodeBeforeIterator>
void PrinterVisitor::beginVisit ( const NodeBeforeIterator& a) {
  thePrinter.startBeginVisit("NodeBeforeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NodeBeforeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodeBeforeIterator>

// <NodeAfterIterator>
void PrinterVisitor::beginVisit ( const NodeAfterIterator& a) {
  thePrinter.startBeginVisit("NodeAfterIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NodeAfterIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodeAfterIterator>

// <CurrentDateTimeIterator>
void PrinterVisitor::beginVisit ( const CurrentDateTimeIterator& a) {
  thePrinter.startBeginVisit("CurrentDateTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CurrentDateTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentDateTimeIterator>

// <CurrentDateIterator>
void PrinterVisitor::beginVisit ( const CurrentDateIterator& a) {
  thePrinter.startBeginVisit("CurrentDateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CurrentDateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentDateIterator>

// <CurrentTimeIterator>
void PrinterVisitor::beginVisit ( const CurrentTimeIterator& a) {
  thePrinter.startBeginVisit("CurrentTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CurrentTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CurrentTimeIterator>

// <ImplicitTimezoneIterator>
void PrinterVisitor::beginVisit ( const ImplicitTimezoneIterator& a) {
  thePrinter.startBeginVisit("ImplicitTimezoneIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ImplicitTimezoneIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ImplicitTimezoneIterator>

// <DefaultCollationIterator>
void PrinterVisitor::beginVisit ( const DefaultCollationIterator& a) {
  thePrinter.startBeginVisit("DefaultCollationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DefaultCollationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DefaultCollationIterator>

// <ZorbaJsonParseIterator>
void PrinterVisitor::beginVisit ( const ZorbaJsonParseIterator& a) {
  thePrinter.startBeginVisit("ZorbaJsonParseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaJsonParseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaJsonParseIterator>

// <ZorbaJsonSerializeIterator>
void PrinterVisitor::beginVisit ( const ZorbaJsonSerializeIterator& a) {
  thePrinter.startBeginVisit("ZorbaJsonSerializeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaJsonSerializeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaJsonSerializeIterator>

// <ZorbaJsonMLParseIterator>
void PrinterVisitor::beginVisit ( const ZorbaJsonMLParseIterator& a) {
  thePrinter.startBeginVisit("ZorbaJsonMLParseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaJsonMLParseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaJsonMLParseIterator>

// <ZorbaJsonMLSerializeIterator>
void PrinterVisitor::beginVisit ( const ZorbaJsonMLSerializeIterator& a) {
  thePrinter.startBeginVisit("ZorbaJsonMLSerializeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaJsonMLSerializeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaJsonMLSerializeIterator>

// <YearsFromDurationIterator>
void PrinterVisitor::beginVisit ( const YearsFromDurationIterator& a) {
  thePrinter.startBeginVisit("YearsFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const YearsFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </YearsFromDurationIterator>

// <MonthsFromDurationIterator>
void PrinterVisitor::beginVisit ( const MonthsFromDurationIterator& a) {
  thePrinter.startBeginVisit("MonthsFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MonthsFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MonthsFromDurationIterator>

// <DaysFromDurationIterator>
void PrinterVisitor::beginVisit ( const DaysFromDurationIterator& a) {
  thePrinter.startBeginVisit("DaysFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DaysFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DaysFromDurationIterator>

// <HoursFromDurationIterator>
void PrinterVisitor::beginVisit ( const HoursFromDurationIterator& a) {
  thePrinter.startBeginVisit("HoursFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const HoursFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HoursFromDurationIterator>

// <MinutesFromDurationIterator>
void PrinterVisitor::beginVisit ( const MinutesFromDurationIterator& a) {
  thePrinter.startBeginVisit("MinutesFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MinutesFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MinutesFromDurationIterator>

// <SecondsFromDurationIterator>
void PrinterVisitor::beginVisit ( const SecondsFromDurationIterator& a) {
  thePrinter.startBeginVisit("SecondsFromDurationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SecondsFromDurationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SecondsFromDurationIterator>

// <YearFromDatetimeIterator>
void PrinterVisitor::beginVisit ( const YearFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("YearFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const YearFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </YearFromDatetimeIterator>

// <MonthFromDatetimeIterator>
void PrinterVisitor::beginVisit ( const MonthFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("MonthFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MonthFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MonthFromDatetimeIterator>

// <DayFromDatetimeIterator>
void PrinterVisitor::beginVisit ( const DayFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("DayFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DayFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DayFromDatetimeIterator>

// <HoursFromDatetimeIterator>
void PrinterVisitor::beginVisit ( const HoursFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("HoursFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const HoursFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HoursFromDatetimeIterator>

// <MinutesFromDatetimeIterator>
void PrinterVisitor::beginVisit ( const MinutesFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("MinutesFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MinutesFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MinutesFromDatetimeIterator>

// <SecondsFromDatetimeIterator>
void PrinterVisitor::beginVisit ( const SecondsFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("SecondsFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SecondsFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SecondsFromDatetimeIterator>

// <TimezoneFromDatetimeIterator>
void PrinterVisitor::beginVisit ( const TimezoneFromDatetimeIterator& a) {
  thePrinter.startBeginVisit("TimezoneFromDatetimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const TimezoneFromDatetimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TimezoneFromDatetimeIterator>

// <YearFromDateIterator>
void PrinterVisitor::beginVisit ( const YearFromDateIterator& a) {
  thePrinter.startBeginVisit("YearFromDateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const YearFromDateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </YearFromDateIterator>

// <MonthFromDateIterator>
void PrinterVisitor::beginVisit ( const MonthFromDateIterator& a) {
  thePrinter.startBeginVisit("MonthFromDateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MonthFromDateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MonthFromDateIterator>

// <DayFromDateIterator>
void PrinterVisitor::beginVisit ( const DayFromDateIterator& a) {
  thePrinter.startBeginVisit("DayFromDateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DayFromDateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DayFromDateIterator>

// <TimezoneFromDateIterator>
void PrinterVisitor::beginVisit ( const TimezoneFromDateIterator& a) {
  thePrinter.startBeginVisit("TimezoneFromDateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const TimezoneFromDateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TimezoneFromDateIterator>

// <HoursFromTimeIterator>
void PrinterVisitor::beginVisit ( const HoursFromTimeIterator& a) {
  thePrinter.startBeginVisit("HoursFromTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const HoursFromTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HoursFromTimeIterator>

// <MinutesFromTimeIterator>
void PrinterVisitor::beginVisit ( const MinutesFromTimeIterator& a) {
  thePrinter.startBeginVisit("MinutesFromTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MinutesFromTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MinutesFromTimeIterator>

// <SecondsFromTimeIterator>
void PrinterVisitor::beginVisit ( const SecondsFromTimeIterator& a) {
  thePrinter.startBeginVisit("SecondsFromTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SecondsFromTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SecondsFromTimeIterator>

// <TimezoneFromTimeIterator>
void PrinterVisitor::beginVisit ( const TimezoneFromTimeIterator& a) {
  thePrinter.startBeginVisit("TimezoneFromTimeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const TimezoneFromTimeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TimezoneFromTimeIterator>

// <FnPutIterator>
void PrinterVisitor::beginVisit ( const FnPutIterator& a) {
  thePrinter.startBeginVisit("FnPutIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnPutIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnPutIterator>

// <FnSQRTIterator>
void PrinterVisitor::beginVisit ( const FnSQRTIterator& a) {
  thePrinter.startBeginVisit("FnSQRTIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSQRTIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSQRTIterator>

// <FnAtan2Iterator>
void PrinterVisitor::beginVisit ( const FnAtan2Iterator& a) {
  thePrinter.startBeginVisit("FnAtan2Iterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnAtan2Iterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnAtan2Iterator>

// <TraceIterator>
void PrinterVisitor::beginVisit ( const TraceIterator& a) {
  thePrinter.startBeginVisit("TraceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const TraceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TraceIterator>

// <ReadLineIterator>
void PrinterVisitor::beginVisit ( const ReadLineIterator& a) {
  thePrinter.startBeginVisit("ReadLineIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ReadLineIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ReadLineIterator>

// <PrintIterator>
void PrinterVisitor::beginVisit ( const PrintIterator& a) {
  thePrinter.startBeginVisit("PrintIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const PrintIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PrintIterator>

// <ResolveUriIterator>
void PrinterVisitor::beginVisit ( const ResolveUriIterator& a) {
  thePrinter.startBeginVisit("ResolveUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ResolveUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ResolveUriIterator>

// <ErrorIterator>
void PrinterVisitor::beginVisit ( const ErrorIterator& a) {
  thePrinter.startBeginVisit("ErrorIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ErrorIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ErrorIterator>

// <NodeReferenceIterator>
void PrinterVisitor::beginVisit ( const NodeReferenceIterator& a) {
  thePrinter.startBeginVisit("NodeReferenceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NodeReferenceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodeReferenceIterator>

// <NodeByReferenceIterator>
void PrinterVisitor::beginVisit ( const NodeByReferenceIterator& a) {
  thePrinter.startBeginVisit("NodeByReferenceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NodeByReferenceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodeByReferenceIterator>

// <FnLocalNameIterator>
void PrinterVisitor::beginVisit ( const FnLocalNameIterator& a) {
  thePrinter.startBeginVisit("FnLocalNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnLocalNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnLocalNameIterator>

// <FnNamespaceUriIterator>
void PrinterVisitor::beginVisit ( const FnNamespaceUriIterator& a) {
  thePrinter.startBeginVisit("FnNamespaceUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnNamespaceUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnNamespaceUriIterator>

// <FnLangIterator>
void PrinterVisitor::beginVisit ( const FnLangIterator& a) {
  thePrinter.startBeginVisit("FnLangIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnLangIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnLangIterator>

// <AbsIterator>
void PrinterVisitor::beginVisit ( const AbsIterator& a) {
  thePrinter.startBeginVisit("AbsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const AbsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AbsIterator>

// <CeilingIterator>
void PrinterVisitor::beginVisit ( const CeilingIterator& a) {
  thePrinter.startBeginVisit("CeilingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CeilingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CeilingIterator>

// <FloorIterator>
void PrinterVisitor::beginVisit ( const FloorIterator& a) {
  thePrinter.startBeginVisit("FloorIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FloorIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FloorIterator>

// <RoundIterator>
void PrinterVisitor::beginVisit ( const RoundIterator& a) {
  thePrinter.startBeginVisit("RoundIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const RoundIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RoundIterator>

// <RoundHalfToEvenIterator>
void PrinterVisitor::beginVisit ( const RoundHalfToEvenIterator& a) {
  thePrinter.startBeginVisit("RoundHalfToEvenIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const RoundHalfToEvenIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RoundHalfToEvenIterator>

// <FormatNumberIterator>
void PrinterVisitor::beginVisit ( const FormatNumberIterator& a) {
  thePrinter.startBeginVisit("FormatNumberIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FormatNumberIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FormatNumberIterator>

// <FnConcatIterator>
void PrinterVisitor::beginVisit ( const FnConcatIterator& a) {
  thePrinter.startBeginVisit("FnConcatIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnConcatIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnConcatIterator>

// <FnIndexOfIterator>
void PrinterVisitor::beginVisit ( const FnIndexOfIterator& a) {
  thePrinter.startBeginVisit("FnIndexOfIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnIndexOfIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnIndexOfIterator>

// <FnEmptyIterator>
void PrinterVisitor::beginVisit ( const FnEmptyIterator& a) {
  thePrinter.startBeginVisit("FnEmptyIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnEmptyIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnEmptyIterator>

// <FnExistsIterator>
void PrinterVisitor::beginVisit ( const FnExistsIterator& a) {
  thePrinter.startBeginVisit("FnExistsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnExistsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnExistsIterator>

// <FnInsertBeforeIterator>
void PrinterVisitor::beginVisit ( const FnInsertBeforeIterator& a) {
  thePrinter.startBeginVisit("FnInsertBeforeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnInsertBeforeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnInsertBeforeIterator>

// <FnRemoveIterator>
void PrinterVisitor::beginVisit ( const FnRemoveIterator& a) {
  thePrinter.startBeginVisit("FnRemoveIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnRemoveIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnRemoveIterator>

// <FnReverseIterator>
void PrinterVisitor::beginVisit ( const FnReverseIterator& a) {
  thePrinter.startBeginVisit("FnReverseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnReverseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnReverseIterator>

// <FnSubsequenceIterator>
void PrinterVisitor::beginVisit ( const FnSubsequenceIterator& a) {
  thePrinter.startBeginVisit("FnSubsequenceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSubsequenceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSubsequenceIterator>

// <FnZeroOrOneIterator>
void PrinterVisitor::beginVisit ( const FnZeroOrOneIterator& a) {
  thePrinter.startBeginVisit("FnZeroOrOneIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnZeroOrOneIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnZeroOrOneIterator>

// <FnOneOrMoreIterator>
void PrinterVisitor::beginVisit ( const FnOneOrMoreIterator& a) {
  thePrinter.startBeginVisit("FnOneOrMoreIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnOneOrMoreIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnOneOrMoreIterator>

// <FnExactlyOneIterator>
void PrinterVisitor::beginVisit ( const FnExactlyOneIterator& a) {
  thePrinter.startBeginVisit("FnExactlyOneIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnExactlyOneIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnExactlyOneIterator>

// <FnDeepEqualIterator>
void PrinterVisitor::beginVisit ( const FnDeepEqualIterator& a) {
  thePrinter.startBeginVisit("FnDeepEqualIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnDeepEqualIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDeepEqualIterator>

// <HashSemiJoinIterator>
void PrinterVisitor::beginVisit ( const HashSemiJoinIterator& a) {
  thePrinter.startBeginVisit("HashSemiJoinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const HashSemiJoinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </HashSemiJoinIterator>

// <SortSemiJoinIterator>
void PrinterVisitor::beginVisit ( const SortSemiJoinIterator& a) {
  thePrinter.startBeginVisit("SortSemiJoinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SortSemiJoinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SortSemiJoinIterator>

// <FnCountIterator>
void PrinterVisitor::beginVisit ( const FnCountIterator& a) {
  thePrinter.startBeginVisit("FnCountIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnCountIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnCountIterator>

// <FnAvgIterator>
void PrinterVisitor::beginVisit ( const FnAvgIterator& a) {
  thePrinter.startBeginVisit("FnAvgIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnAvgIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnAvgIterator>

// <FnSumIterator>
void PrinterVisitor::beginVisit ( const FnSumIterator& a) {
  thePrinter.startBeginVisit("FnSumIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSumIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumIterator>

// <FnSumDoubleIterator>
void PrinterVisitor::beginVisit ( const FnSumDoubleIterator& a) {
  thePrinter.startBeginVisit("FnSumDoubleIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSumDoubleIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumDoubleIterator>

// <FnSumFloatIterator>
void PrinterVisitor::beginVisit ( const FnSumFloatIterator& a) {
  thePrinter.startBeginVisit("FnSumFloatIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSumFloatIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumFloatIterator>

// <FnSumDecimalIterator>
void PrinterVisitor::beginVisit ( const FnSumDecimalIterator& a) {
  thePrinter.startBeginVisit("FnSumDecimalIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSumDecimalIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumDecimalIterator>

// <FnSumIntegerIterator>
void PrinterVisitor::beginVisit ( const FnSumIntegerIterator& a) {
  thePrinter.startBeginVisit("FnSumIntegerIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSumIntegerIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSumIntegerIterator>

// <OpToIterator>
void PrinterVisitor::beginVisit ( const OpToIterator& a) {
  thePrinter.startBeginVisit("OpToIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const OpToIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </OpToIterator>

// <FnDocIterator>
void PrinterVisitor::beginVisit ( const FnDocIterator& a) {
  thePrinter.startBeginVisit("FnDocIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnDocIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDocIterator>

// <FnDocAvailableIterator>
void PrinterVisitor::beginVisit ( const FnDocAvailableIterator& a) {
  thePrinter.startBeginVisit("FnDocAvailableIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnDocAvailableIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDocAvailableIterator>

// <FnParseIterator>
void PrinterVisitor::beginVisit ( const FnParseIterator& a) {
  thePrinter.startBeginVisit("FnParseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnParseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnParseIterator>

// <CodepointsToStringIterator>
void PrinterVisitor::beginVisit ( const CodepointsToStringIterator& a) {
  thePrinter.startBeginVisit("CodepointsToStringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CodepointsToStringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CodepointsToStringIterator>

// <StringToCodepointsIterator>
void PrinterVisitor::beginVisit ( const StringToCodepointsIterator& a) {
  thePrinter.startBeginVisit("StringToCodepointsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StringToCodepointsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringToCodepointsIterator>

// <CompareStrIterator>
void PrinterVisitor::beginVisit ( const CompareStrIterator& a) {
  thePrinter.startBeginVisit("CompareStrIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CompareStrIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CompareStrIterator>

// <CodepointEqualIterator>
void PrinterVisitor::beginVisit ( const CodepointEqualIterator& a) {
  thePrinter.startBeginVisit("CodepointEqualIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CodepointEqualIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CodepointEqualIterator>

// <ConcatStrIterator>
void PrinterVisitor::beginVisit ( const ConcatStrIterator& a) {
  thePrinter.startBeginVisit("ConcatStrIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ConcatStrIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ConcatStrIterator>

// <StringJoinIterator>
void PrinterVisitor::beginVisit ( const StringJoinIterator& a) {
  thePrinter.startBeginVisit("StringJoinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StringJoinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringJoinIterator>

// <SubstringIterator>
void PrinterVisitor::beginVisit ( const SubstringIterator& a) {
  thePrinter.startBeginVisit("SubstringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SubstringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringIterator>

// <StringLengthIterator>
void PrinterVisitor::beginVisit ( const StringLengthIterator& a) {
  thePrinter.startBeginVisit("StringLengthIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StringLengthIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringLengthIterator>

// <NormalizeSpaceIterator>
void PrinterVisitor::beginVisit ( const NormalizeSpaceIterator& a) {
  thePrinter.startBeginVisit("NormalizeSpaceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NormalizeSpaceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NormalizeSpaceIterator>

// <NormalizeUnicodeIterator>
void PrinterVisitor::beginVisit ( const NormalizeUnicodeIterator& a) {
  thePrinter.startBeginVisit("NormalizeUnicodeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NormalizeUnicodeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NormalizeUnicodeIterator>

// <UpperCaseIterator>
void PrinterVisitor::beginVisit ( const UpperCaseIterator& a) {
  thePrinter.startBeginVisit("UpperCaseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const UpperCaseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </UpperCaseIterator>

// <LowerCaseIterator>
void PrinterVisitor::beginVisit ( const LowerCaseIterator& a) {
  thePrinter.startBeginVisit("LowerCaseIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const LowerCaseIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LowerCaseIterator>

// <TranslateIterator>
void PrinterVisitor::beginVisit ( const TranslateIterator& a) {
  thePrinter.startBeginVisit("TranslateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const TranslateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TranslateIterator>

// <EncodeForUriIterator>
void PrinterVisitor::beginVisit ( const EncodeForUriIterator& a) {
  thePrinter.startBeginVisit("EncodeForUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const EncodeForUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </EncodeForUriIterator>

// <IriToUriIterator>
void PrinterVisitor::beginVisit ( const IriToUriIterator& a) {
  thePrinter.startBeginVisit("IriToUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IriToUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IriToUriIterator>

// <EscapeHtmlUriIterator>
void PrinterVisitor::beginVisit ( const EscapeHtmlUriIterator& a) {
  thePrinter.startBeginVisit("EscapeHtmlUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const EscapeHtmlUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </EscapeHtmlUriIterator>

// <ContainsIterator>
void PrinterVisitor::beginVisit ( const ContainsIterator& a) {
  thePrinter.startBeginVisit("ContainsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ContainsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ContainsIterator>

// <StartsWithIterator>
void PrinterVisitor::beginVisit ( const StartsWithIterator& a) {
  thePrinter.startBeginVisit("StartsWithIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StartsWithIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StartsWithIterator>

// <EndsWithIterator>
void PrinterVisitor::beginVisit ( const EndsWithIterator& a) {
  thePrinter.startBeginVisit("EndsWithIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const EndsWithIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </EndsWithIterator>

// <SubstringBeforeIterator>
void PrinterVisitor::beginVisit ( const SubstringBeforeIterator& a) {
  thePrinter.startBeginVisit("SubstringBeforeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SubstringBeforeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringBeforeIterator>

// <SubstringAfterIterator>
void PrinterVisitor::beginVisit ( const SubstringAfterIterator& a) {
  thePrinter.startBeginVisit("SubstringAfterIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SubstringAfterIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringAfterIterator>

// <FnMatchesIterator>
void PrinterVisitor::beginVisit ( const FnMatchesIterator& a) {
  thePrinter.startBeginVisit("FnMatchesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnMatchesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnMatchesIterator>

// <FnReplaceIterator>
void PrinterVisitor::beginVisit ( const FnReplaceIterator& a) {
  thePrinter.startBeginVisit("FnReplaceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnReplaceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnReplaceIterator>

// <FnTokenizeIterator>
void PrinterVisitor::beginVisit ( const FnTokenizeIterator& a) {
  thePrinter.startBeginVisit("FnTokenizeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnTokenizeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnTokenizeIterator>


}