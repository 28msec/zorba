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
#include "runtime/any_uri/any_uri.h"
#include "runtime/base64/base64.h"
#include "runtime/booleans/booleans.h"
#include "runtime/collections/collections.h"
#include "runtime/context/context.h"
#include "runtime/convertors/convertors.h"
#include "runtime/debug/debug.h"
#include "runtime/durations_dates_times/durations_dates_times.h"
#include "runtime/eval/eval.h"
#include "runtime/fnerror/fnerror.h"
#include "runtime/fnput/fnput.h"
#include "runtime/indexing/ic_ddl.h"
#include "runtime/indexing/index_ddl.h"
#include "runtime/introspection/dctx.h"
#include "runtime/introspection/sctx.h"
#include "runtime/maths/maths.h"
#include "runtime/nodes/nodes.h"
#include "runtime/numerics/numerics.h"
#include "runtime/qnames/qnames.h"
#include "runtime/random/random.h"
#include "runtime/schema/schema.h"
#include "runtime/scripting/scripting.h"
#include "runtime/sequences/sequences.h"
#include "runtime/strings/strings.h"
#include "runtime/xqdoc/xqdoc.h"

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


// <Base64DecodeIterator>
void PrinterVisitor::beginVisit ( const Base64DecodeIterator& a) {
  thePrinter.startBeginVisit("Base64DecodeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const Base64DecodeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Base64DecodeIterator>


// <Base64EncodeIterator>
void PrinterVisitor::beginVisit ( const Base64EncodeIterator& a) {
  thePrinter.startBeginVisit("Base64EncodeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const Base64EncodeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Base64EncodeIterator>


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


// <FnCollectionIterator>
void PrinterVisitor::beginVisit ( const FnCollectionIterator& a) {
  thePrinter.startBeginVisit("FnCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnCollectionIterator>


// <ZorbaCollectionIterator>
void PrinterVisitor::beginVisit ( const ZorbaCollectionIterator& a) {
  thePrinter.startBeginVisit("ZorbaCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaCollectionIterator>


// <ZorbaIndexOfIterator>
void PrinterVisitor::beginVisit ( const ZorbaIndexOfIterator& a) {
  thePrinter.startBeginVisit("ZorbaIndexOfIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaIndexOfIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaIndexOfIterator>


// <ZorbaCreateCollectionIterator>
void PrinterVisitor::beginVisit ( const ZorbaCreateCollectionIterator& a) {
  thePrinter.startBeginVisit("ZorbaCreateCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaCreateCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaCreateCollectionIterator>


// <ZorbaDeleteCollectionIterator>
void PrinterVisitor::beginVisit ( const ZorbaDeleteCollectionIterator& a) {
  thePrinter.startBeginVisit("ZorbaDeleteCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaDeleteCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaDeleteCollectionIterator>


// <ZorbaInsertNodesIterator>
void PrinterVisitor::beginVisit ( const ZorbaInsertNodesIterator& a) {
  thePrinter.startBeginVisit("ZorbaInsertNodesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaInsertNodesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaInsertNodesIterator>


// <ZorbaInsertNodesFirstIterator>
void PrinterVisitor::beginVisit ( const ZorbaInsertNodesFirstIterator& a) {
  thePrinter.startBeginVisit("ZorbaInsertNodesFirstIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaInsertNodesFirstIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaInsertNodesFirstIterator>


// <ZorbaInsertNodesLastIterator>
void PrinterVisitor::beginVisit ( const ZorbaInsertNodesLastIterator& a) {
  thePrinter.startBeginVisit("ZorbaInsertNodesLastIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaInsertNodesLastIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaInsertNodesLastIterator>


// <ZorbaInsertNodesBeforeIterator>
void PrinterVisitor::beginVisit ( const ZorbaInsertNodesBeforeIterator& a) {
  thePrinter.startBeginVisit("ZorbaInsertNodesBeforeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaInsertNodesBeforeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaInsertNodesBeforeIterator>


// <ZorbaInsertNodesAfterIterator>
void PrinterVisitor::beginVisit ( const ZorbaInsertNodesAfterIterator& a) {
  thePrinter.startBeginVisit("ZorbaInsertNodesAfterIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaInsertNodesAfterIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaInsertNodesAfterIterator>


// <ZorbaDeleteNodesIterator>
void PrinterVisitor::beginVisit ( const ZorbaDeleteNodesIterator& a) {
  thePrinter.startBeginVisit("ZorbaDeleteNodesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaDeleteNodesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaDeleteNodesIterator>


// <ZorbaDeleteNodesFirstIterator>
void PrinterVisitor::beginVisit ( const ZorbaDeleteNodesFirstIterator& a) {
  thePrinter.startBeginVisit("ZorbaDeleteNodesFirstIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaDeleteNodesFirstIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaDeleteNodesFirstIterator>


// <ZorbaDeleteNodesLastIterator>
void PrinterVisitor::beginVisit ( const ZorbaDeleteNodesLastIterator& a) {
  thePrinter.startBeginVisit("ZorbaDeleteNodesLastIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaDeleteNodesLastIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaDeleteNodesLastIterator>


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


// <ZorbaCSV2XMLIterator>
void PrinterVisitor::beginVisit ( const ZorbaCSV2XMLIterator& a) {
  thePrinter.startBeginVisit("ZorbaCSV2XMLIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaCSV2XMLIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaCSV2XMLIterator>


// <ZorbaTXT2XMLIterator>
void PrinterVisitor::beginVisit ( const ZorbaTXT2XMLIterator& a) {
  thePrinter.startBeginVisit("ZorbaTXT2XMLIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaTXT2XMLIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaTXT2XMLIterator>


// <ZorbaCSV2XMLFromFileIterator>
void PrinterVisitor::beginVisit ( const ZorbaCSV2XMLFromFileIterator& a) {
  thePrinter.startBeginVisit("ZorbaCSV2XMLFromFileIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaCSV2XMLFromFileIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaCSV2XMLFromFileIterator>


// <ZorbaTXT2XMLFromFileIterator>
void PrinterVisitor::beginVisit ( const ZorbaTXT2XMLFromFileIterator& a) {
  thePrinter.startBeginVisit("ZorbaTXT2XMLFromFileIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaTXT2XMLFromFileIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaTXT2XMLFromFileIterator>


// <ZorbaXML2CSVIterator>
void PrinterVisitor::beginVisit ( const ZorbaXML2CSVIterator& a) {
  thePrinter.startBeginVisit("ZorbaXML2CSVIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaXML2CSVIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaXML2CSVIterator>


// <ZorbaXML2CSVFILEIterator>
void PrinterVisitor::beginVisit ( const ZorbaXML2CSVFILEIterator& a) {
  thePrinter.startBeginVisit("ZorbaXML2CSVFILEIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaXML2CSVFILEIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaXML2CSVFILEIterator>


// <ZorbaXML2TXTIterator>
void PrinterVisitor::beginVisit ( const ZorbaXML2TXTIterator& a) {
  thePrinter.startBeginVisit("ZorbaXML2TXTIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaXML2TXTIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaXML2TXTIterator>


// <ZorbaXML2TXTFILEIterator>
void PrinterVisitor::beginVisit ( const ZorbaXML2TXTFILEIterator& a) {
  thePrinter.startBeginVisit("ZorbaXML2TXTFILEIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaXML2TXTFILEIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaXML2TXTFILEIterator>


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


// <TimestampIterator>
void PrinterVisitor::beginVisit ( const TimestampIterator& a) {
  thePrinter.startBeginVisit("TimestampIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const TimestampIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TimestampIterator>


// <EvalIterator>
void PrinterVisitor::beginVisit ( const EvalIterator& a) {
  thePrinter.startBeginVisit("EvalIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const EvalIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </EvalIterator>


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


// <ActivateICIterator>
void PrinterVisitor::beginVisit ( const ActivateICIterator& a) {
  thePrinter.startBeginVisit("ActivateICIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ActivateICIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ActivateICIterator>


// <DeactivateICIterator>
void PrinterVisitor::beginVisit ( const DeactivateICIterator& a) {
  thePrinter.startBeginVisit("DeactivateICIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DeactivateICIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DeactivateICIterator>


// <CheckICIterator>
void PrinterVisitor::beginVisit ( const CheckICIterator& a) {
  thePrinter.startBeginVisit("CheckICIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CheckICIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CheckICIterator>


// <CreateIndexIterator>
void PrinterVisitor::beginVisit ( const CreateIndexIterator& a) {
  thePrinter.startBeginVisit("CreateIndexIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CreateIndexIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CreateIndexIterator>


// <DeleteIndexIterator>
void PrinterVisitor::beginVisit ( const DeleteIndexIterator& a) {
  thePrinter.startBeginVisit("DeleteIndexIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DeleteIndexIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DeleteIndexIterator>


// <CreateInternalIndexIterator>
void PrinterVisitor::beginVisit ( const CreateInternalIndexIterator& a) {
  thePrinter.startBeginVisit("CreateInternalIndexIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CreateInternalIndexIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CreateInternalIndexIterator>


// <RefreshIndexIterator>
void PrinterVisitor::beginVisit ( const RefreshIndexIterator& a) {
  thePrinter.startBeginVisit("RefreshIndexIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const RefreshIndexIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RefreshIndexIterator>


// <IndexEntryBuilderIterator>
void PrinterVisitor::beginVisit ( const IndexEntryBuilderIterator& a) {
  thePrinter.startBeginVisit("IndexEntryBuilderIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IndexEntryBuilderIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IndexEntryBuilderIterator>


// <IndexPointProbeIterator>
void PrinterVisitor::beginVisit ( const IndexPointProbeIterator& a) {
  thePrinter.startBeginVisit("IndexPointProbeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IndexPointProbeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IndexPointProbeIterator>


// <IndexRangeProbeIterator>
void PrinterVisitor::beginVisit ( const IndexRangeProbeIterator& a) {
  thePrinter.startBeginVisit("IndexRangeProbeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IndexRangeProbeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IndexRangeProbeIterator>


// <IsAvailableCollectionIterator>
void PrinterVisitor::beginVisit ( const IsAvailableCollectionIterator& a) {
  thePrinter.startBeginVisit("IsAvailableCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsAvailableCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAvailableCollectionIterator>


// <AvailableCollectionsIterator>
void PrinterVisitor::beginVisit ( const AvailableCollectionsIterator& a) {
  thePrinter.startBeginVisit("AvailableCollectionsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const AvailableCollectionsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AvailableCollectionsIterator>


// <IsAvailableIndexIterator>
void PrinterVisitor::beginVisit ( const IsAvailableIndexIterator& a) {
  thePrinter.startBeginVisit("IsAvailableIndexIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsAvailableIndexIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAvailableIndexIterator>


// <AvailableIndexesIterator>
void PrinterVisitor::beginVisit ( const AvailableIndexesIterator& a) {
  thePrinter.startBeginVisit("AvailableIndexesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const AvailableIndexesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AvailableIndexesIterator>


// <IsActivatedICIterator>
void PrinterVisitor::beginVisit ( const IsActivatedICIterator& a) {
  thePrinter.startBeginVisit("IsActivatedICIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsActivatedICIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsActivatedICIterator>


// <ActivatedICsIterator>
void PrinterVisitor::beginVisit ( const ActivatedICsIterator& a) {
  thePrinter.startBeginVisit("ActivatedICsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ActivatedICsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ActivatedICsIterator>


// <IsDeclaredCollectionIterator>
void PrinterVisitor::beginVisit ( const IsDeclaredCollectionIterator& a) {
  thePrinter.startBeginVisit("IsDeclaredCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsDeclaredCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDeclaredCollectionIterator>


// <DeclaredCollectionsIterator>
void PrinterVisitor::beginVisit ( const DeclaredCollectionsIterator& a) {
  thePrinter.startBeginVisit("DeclaredCollectionsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DeclaredCollectionsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DeclaredCollectionsIterator>


// <IsDeclaredIndexIterator>
void PrinterVisitor::beginVisit ( const IsDeclaredIndexIterator& a) {
  thePrinter.startBeginVisit("IsDeclaredIndexIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsDeclaredIndexIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDeclaredIndexIterator>


// <DeclaredIndexesIterator>
void PrinterVisitor::beginVisit ( const DeclaredIndexesIterator& a) {
  thePrinter.startBeginVisit("DeclaredIndexesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DeclaredIndexesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DeclaredIndexesIterator>


// <StaticNamespacesIterator>
void PrinterVisitor::beginVisit ( const StaticNamespacesIterator& a) {
  thePrinter.startBeginVisit("StaticNamespacesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StaticNamespacesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StaticNamespacesIterator>


// <StaticNamespaceBindingIterator>
void PrinterVisitor::beginVisit ( const StaticNamespaceBindingIterator& a) {
  thePrinter.startBeginVisit("StaticNamespaceBindingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StaticNamespaceBindingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StaticNamespaceBindingIterator>


// <InscopeVariablesIterator>
void PrinterVisitor::beginVisit ( const InscopeVariablesIterator& a) {
  thePrinter.startBeginVisit("InscopeVariablesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const InscopeVariablesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InscopeVariablesIterator>


// <DefaultCollectionTypeIterator>
void PrinterVisitor::beginVisit ( const DefaultCollectionTypeIterator& a) {
  thePrinter.startBeginVisit("DefaultCollectionTypeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DefaultCollectionTypeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DefaultCollectionTypeIterator>


// <XPath10CompatModeIterator>
void PrinterVisitor::beginVisit ( const XPath10CompatModeIterator& a) {
  thePrinter.startBeginVisit("XPath10CompatModeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const XPath10CompatModeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </XPath10CompatModeIterator>


// <StaticallyKnownDocumentsIterator>
void PrinterVisitor::beginVisit ( const StaticallyKnownDocumentsIterator& a) {
  thePrinter.startBeginVisit("StaticallyKnownDocumentsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StaticallyKnownDocumentsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StaticallyKnownDocumentsIterator>


// <StaticallyKnownCollationsIterator>
void PrinterVisitor::beginVisit ( const StaticallyKnownCollationsIterator& a) {
  thePrinter.startBeginVisit("StaticallyKnownCollationsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StaticallyKnownCollationsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StaticallyKnownCollationsIterator>


// <ConstructionModeIterator>
void PrinterVisitor::beginVisit ( const ConstructionModeIterator& a) {
  thePrinter.startBeginVisit("ConstructionModeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ConstructionModeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ConstructionModeIterator>


// <OrderingModeIterator>
void PrinterVisitor::beginVisit ( const OrderingModeIterator& a) {
  thePrinter.startBeginVisit("OrderingModeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const OrderingModeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </OrderingModeIterator>


// <DefaultOrderIterator>
void PrinterVisitor::beginVisit ( const DefaultOrderIterator& a) {
  thePrinter.startBeginVisit("DefaultOrderIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DefaultOrderIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DefaultOrderIterator>


// <BoundarySpacePolicyIterator>
void PrinterVisitor::beginVisit ( const BoundarySpacePolicyIterator& a) {
  thePrinter.startBeginVisit("BoundarySpacePolicyIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const BoundarySpacePolicyIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </BoundarySpacePolicyIterator>


// <CopyNamespacesModeIterator>
void PrinterVisitor::beginVisit ( const CopyNamespacesModeIterator& a) {
  thePrinter.startBeginVisit("CopyNamespacesModeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CopyNamespacesModeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CopyNamespacesModeIterator>


// <FunctionNamesIterator>
void PrinterVisitor::beginVisit ( const FunctionNamesIterator& a) {
  thePrinter.startBeginVisit("FunctionNamesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FunctionNamesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FunctionNamesIterator>


// <FunctionArgumentsCountIterator>
void PrinterVisitor::beginVisit ( const FunctionArgumentsCountIterator& a) {
  thePrinter.startBeginVisit("FunctionArgumentsCountIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FunctionArgumentsCountIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FunctionArgumentsCountIterator>


// <InScopeSchemaTypesIterator>
void PrinterVisitor::beginVisit ( const InScopeSchemaTypesIterator& a) {
  thePrinter.startBeginVisit("InScopeSchemaTypesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const InScopeSchemaTypesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InScopeSchemaTypesIterator>


// <IsDeclaredICIterator>
void PrinterVisitor::beginVisit ( const IsDeclaredICIterator& a) {
  thePrinter.startBeginVisit("IsDeclaredICIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsDeclaredICIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDeclaredICIterator>


// <DeclaredICsIterator>
void PrinterVisitor::beginVisit ( const DeclaredICsIterator& a) {
  thePrinter.startBeginVisit("DeclaredICsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DeclaredICsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DeclaredICsIterator>


// <SqrtIterator>
void PrinterVisitor::beginVisit ( const SqrtIterator& a) {
  thePrinter.startBeginVisit("SqrtIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SqrtIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SqrtIterator>


// <ExpIterator>
void PrinterVisitor::beginVisit ( const ExpIterator& a) {
  thePrinter.startBeginVisit("ExpIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ExpIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ExpIterator>


// <LogIterator>
void PrinterVisitor::beginVisit ( const LogIterator& a) {
  thePrinter.startBeginVisit("LogIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const LogIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LogIterator>


// <SinIterator>
void PrinterVisitor::beginVisit ( const SinIterator& a) {
  thePrinter.startBeginVisit("SinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SinIterator>


// <CosIterator>
void PrinterVisitor::beginVisit ( const CosIterator& a) {
  thePrinter.startBeginVisit("CosIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CosIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CosIterator>


// <TanIterator>
void PrinterVisitor::beginVisit ( const TanIterator& a) {
  thePrinter.startBeginVisit("TanIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const TanIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TanIterator>


// <ArcSinIterator>
void PrinterVisitor::beginVisit ( const ArcSinIterator& a) {
  thePrinter.startBeginVisit("ArcSinIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ArcSinIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ArcSinIterator>


// <ArcCosIterator>
void PrinterVisitor::beginVisit ( const ArcCosIterator& a) {
  thePrinter.startBeginVisit("ArcCosIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ArcCosIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ArcCosIterator>


// <ArcTanIterator>
void PrinterVisitor::beginVisit ( const ArcTanIterator& a) {
  thePrinter.startBeginVisit("ArcTanIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ArcTanIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ArcTanIterator>


// <Atan2Iterator>
void PrinterVisitor::beginVisit ( const Atan2Iterator& a) {
  thePrinter.startBeginVisit("Atan2Iterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const Atan2Iterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Atan2Iterator>


// <CoshIterator>
void PrinterVisitor::beginVisit ( const CoshIterator& a) {
  thePrinter.startBeginVisit("CoshIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const CoshIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </CoshIterator>


// <AcoshIterator>
void PrinterVisitor::beginVisit ( const AcoshIterator& a) {
  thePrinter.startBeginVisit("AcoshIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const AcoshIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AcoshIterator>


// <FmodIterator>
void PrinterVisitor::beginVisit ( const FmodIterator& a) {
  thePrinter.startBeginVisit("FmodIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FmodIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FmodIterator>


// <LdexpIterator>
void PrinterVisitor::beginVisit ( const LdexpIterator& a) {
  thePrinter.startBeginVisit("LdexpIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const LdexpIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LdexpIterator>


// <Log10Iterator>
void PrinterVisitor::beginVisit ( const Log10Iterator& a) {
  thePrinter.startBeginVisit("Log10Iterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const Log10Iterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Log10Iterator>


// <PowIterator>
void PrinterVisitor::beginVisit ( const PowIterator& a) {
  thePrinter.startBeginVisit("PowIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const PowIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PowIterator>


// <SinhIterator>
void PrinterVisitor::beginVisit ( const SinhIterator& a) {
  thePrinter.startBeginVisit("SinhIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SinhIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SinhIterator>


// <AsinhIterator>
void PrinterVisitor::beginVisit ( const AsinhIterator& a) {
  thePrinter.startBeginVisit("AsinhIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const AsinhIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AsinhIterator>


// <TanhIterator>
void PrinterVisitor::beginVisit ( const TanhIterator& a) {
  thePrinter.startBeginVisit("TanhIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const TanhIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </TanhIterator>


// <AtanhIterator>
void PrinterVisitor::beginVisit ( const AtanhIterator& a) {
  thePrinter.startBeginVisit("AtanhIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const AtanhIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AtanhIterator>


// <PiNumberIterator>
void PrinterVisitor::beginVisit ( const PiNumberIterator& a) {
  thePrinter.startBeginVisit("PiNumberIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const PiNumberIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PiNumberIterator>


// <IsInfIterator>
void PrinterVisitor::beginVisit ( const IsInfIterator& a) {
  thePrinter.startBeginVisit("IsInfIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsInfIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsInfIterator>


// <IsNaNIterator>
void PrinterVisitor::beginVisit ( const IsNaNIterator& a) {
  thePrinter.startBeginVisit("IsNaNIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsNaNIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsNaNIterator>


// <ModfIterator>
void PrinterVisitor::beginVisit ( const ModfIterator& a) {
  thePrinter.startBeginVisit("ModfIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ModfIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ModfIterator>


// <FrexpIterator>
void PrinterVisitor::beginVisit ( const FrexpIterator& a) {
  thePrinter.startBeginVisit("FrexpIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FrexpIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FrexpIterator>


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


// <ResolveQNameIterator>
void PrinterVisitor::beginVisit ( const ResolveQNameIterator& a) {
  thePrinter.startBeginVisit("ResolveQNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ResolveQNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ResolveQNameIterator>


// <QNameIterator>
void PrinterVisitor::beginVisit ( const QNameIterator& a) {
  thePrinter.startBeginVisit("QNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const QNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </QNameIterator>


// <QNameEqualIterator>
void PrinterVisitor::beginVisit ( const QNameEqualIterator& a) {
  thePrinter.startBeginVisit("QNameEqualIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const QNameEqualIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </QNameEqualIterator>


// <PrefixFromQNameIterator>
void PrinterVisitor::beginVisit ( const PrefixFromQNameIterator& a) {
  thePrinter.startBeginVisit("PrefixFromQNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const PrefixFromQNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PrefixFromQNameIterator>


// <LocalNameFromQNameIterator>
void PrinterVisitor::beginVisit ( const LocalNameFromQNameIterator& a) {
  thePrinter.startBeginVisit("LocalNameFromQNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const LocalNameFromQNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LocalNameFromQNameIterator>


// <NamespaceUriFromQNameIterator>
void PrinterVisitor::beginVisit ( const NamespaceUriFromQNameIterator& a) {
  thePrinter.startBeginVisit("NamespaceUriFromQNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NamespaceUriFromQNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NamespaceUriFromQNameIterator>


// <NamespaceUriForPrefixIterator>
void PrinterVisitor::beginVisit ( const NamespaceUriForPrefixIterator& a) {
  thePrinter.startBeginVisit("NamespaceUriForPrefixIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NamespaceUriForPrefixIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NamespaceUriForPrefixIterator>


// <InScopePrefixesIterator>
void PrinterVisitor::beginVisit ( const InScopePrefixesIterator& a) {
  thePrinter.startBeginVisit("InScopePrefixesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const InScopePrefixesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InScopePrefixesIterator>


// <NumGenIterator>
void PrinterVisitor::beginVisit ( const NumGenIterator& a) {
  thePrinter.startBeginVisit("NumGenIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NumGenIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NumGenIterator>


// <RandomIterator>
void PrinterVisitor::beginVisit ( const RandomIterator& a) {
  thePrinter.startBeginVisit("RandomIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const RandomIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RandomIterator>


// <UuidIterator>
void PrinterVisitor::beginVisit ( const UuidIterator& a) {
  thePrinter.startBeginVisit("UuidIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const UuidIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </UuidIterator>

#ifndef ZORBA_NO_XMLSCHEMA
// <ValidateIterator>
void PrinterVisitor::beginVisit ( const ValidateIterator& a) {
  thePrinter.startBeginVisit("ValidateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ValidateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ValidateIterator>

#endif

// <ZorbaSchemaTypeIterator>
void PrinterVisitor::beginVisit ( const ZorbaSchemaTypeIterator& a) {
  thePrinter.startBeginVisit("ZorbaSchemaTypeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaSchemaTypeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaSchemaTypeIterator>


// <SequentialIterator>
void PrinterVisitor::beginVisit ( const SequentialIterator& a) {
  thePrinter.startBeginVisit("SequentialIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SequentialIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SequentialIterator>


// <LoopIterator>
void PrinterVisitor::beginVisit ( const LoopIterator& a) {
  thePrinter.startBeginVisit("LoopIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const LoopIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LoopIterator>


// <FlowCtlIterator>
void PrinterVisitor::beginVisit ( const FlowCtlIterator& a) {
  thePrinter.startBeginVisit("FlowCtlIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FlowCtlIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FlowCtlIterator>


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


// <FnDistinctValuesIterator>
void PrinterVisitor::beginVisit ( const FnDistinctValuesIterator& a) {
  thePrinter.startBeginVisit("FnDistinctValuesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnDistinctValuesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnDistinctValuesIterator>


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


// <XQDocIterator>
void PrinterVisitor::beginVisit ( const XQDocIterator& a) {
  thePrinter.startBeginVisit("XQDocIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const XQDocIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </XQDocIterator>


}