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

#include "stdafx.h"

#include "runtime/visitors/printer_visitor.h"

// get forward declarations for all classes from planitervisitor.h

#include "runtime/visitors/planiter_visitor.h"

#include "runtime/visitors/iterprinter.h"

#include "system/properties.h"

#include "util/string_util.h"

#include "runtime/accessors/accessors.h"
#include "runtime/any_uri/any_uri.h"
#include "runtime/base64/base64.h"
#include "runtime/booleans/booleans.h"
#include "runtime/collections/collections.h"
#include "runtime/context/context.h"
#include "runtime/debug/debug_iterator.h"
#include "runtime/durations_dates_times/durations_dates_times.h"
#include "runtime/errors_and_diagnostics/errors_and_diagnostics.h"
#include "runtime/errors_and_diagnostics/other_diagnostics.h"
#include "runtime/fetch/fetch.h"
#include "runtime/fnput/fnput.h"
#include "runtime/function_item/function_item_iter.h"
#include "runtime/indexing/ic_ddl.h"
#include "runtime/introspection/sctx.h"
#include "runtime/json/json.h"
#include "runtime/maths/maths.h"
#include "runtime/nodes/node_position.h"
#include "runtime/nodes/nodes.h"
#include "runtime/numerics/numerics.h"
#include "runtime/parsing_and_serializing/parse_fragment.h"
#include "runtime/parsing_and_serializing/parsing_and_serializing.h"
#include "runtime/qnames/qnames.h"
#include "runtime/random/random.h"
#include "runtime/schema/schema.h"
#include "runtime/sequences/sequences.h"
#include "runtime/store/documents.h"
#include "runtime/store/maps.h"
#include "runtime/strings/strings.h"
#include "runtime/uris/uris.h"
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
    thePrinter.addAttribute("qname", a->getQName()->show().str());
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
    thePrinter.addAttribute("target_position", ztd::to_string(a->getTargetPos()));
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


// <ZorbaApplyInsertNodesIterator>
void PrinterVisitor::beginVisit ( const ZorbaApplyInsertNodesIterator& a) {
  thePrinter.startBeginVisit("ZorbaApplyInsertNodesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaApplyInsertNodesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaApplyInsertNodesIterator>


// <ZorbaApplyInsertNodesFirstIterator>
void PrinterVisitor::beginVisit ( const ZorbaApplyInsertNodesFirstIterator& a) {
  thePrinter.startBeginVisit("ZorbaApplyInsertNodesFirstIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaApplyInsertNodesFirstIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaApplyInsertNodesFirstIterator>


// <ZorbaApplyInsertNodesLastIterator>
void PrinterVisitor::beginVisit ( const ZorbaApplyInsertNodesLastIterator& a) {
  thePrinter.startBeginVisit("ZorbaApplyInsertNodesLastIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaApplyInsertNodesLastIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaApplyInsertNodesLastIterator>


// <ZorbaApplyInsertNodesBeforeIterator>
void PrinterVisitor::beginVisit ( const ZorbaApplyInsertNodesBeforeIterator& a) {
  thePrinter.startBeginVisit("ZorbaApplyInsertNodesBeforeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaApplyInsertNodesBeforeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaApplyInsertNodesBeforeIterator>


// <ZorbaApplyInsertNodesAfterIterator>
void PrinterVisitor::beginVisit ( const ZorbaApplyInsertNodesAfterIterator& a) {
  thePrinter.startBeginVisit("ZorbaApplyInsertNodesAfterIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaApplyInsertNodesAfterIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaApplyInsertNodesAfterIterator>


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


// <ZorbaTruncateCollectionIterator>
void PrinterVisitor::beginVisit ( const ZorbaTruncateCollectionIterator& a) {
  thePrinter.startBeginVisit("ZorbaTruncateCollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaTruncateCollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaTruncateCollectionIterator>


// <ZorbaCollectionNameIterator>
void PrinterVisitor::beginVisit ( const ZorbaCollectionNameIterator& a) {
  thePrinter.startBeginVisit("ZorbaCollectionNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaCollectionNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaCollectionNameIterator>


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


// <FnURICollectionIterator>
void PrinterVisitor::beginVisit ( const FnURICollectionIterator& a) {
  thePrinter.startBeginVisit("FnURICollectionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnURICollectionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnURICollectionIterator>


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

#ifdef ZORBA_WITH_DEBUGGER
// <DebugIterator>
void PrinterVisitor::beginVisit ( const DebugIterator& a) {
  thePrinter.startBeginVisit("DebugIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DebugIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DebugIterator>

#endif

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


// <FunctionTraceIterator>
void PrinterVisitor::beginVisit ( const FunctionTraceIterator& a) {
  thePrinter.startBeginVisit("FunctionTraceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FunctionTraceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FunctionTraceIterator>


// <FetchContentIterator>
void PrinterVisitor::beginVisit ( const FetchContentIterator& a) {
  thePrinter.startBeginVisit("FetchContentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FetchContentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FetchContentIterator>


// <FetchContentTypeIterator>
void PrinterVisitor::beginVisit ( const FetchContentTypeIterator& a) {
  thePrinter.startBeginVisit("FetchContentTypeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FetchContentTypeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FetchContentTypeIterator>


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


// <FunctionNameIterator>
void PrinterVisitor::beginVisit ( const FunctionNameIterator& a) {
  thePrinter.startBeginVisit("FunctionNameIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FunctionNameIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FunctionNameIterator>


// <FunctionArityIterator>
void PrinterVisitor::beginVisit ( const FunctionArityIterator& a) {
  thePrinter.startBeginVisit("FunctionArityIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FunctionArityIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FunctionArityIterator>


// <PartialApplyIterator>
void PrinterVisitor::beginVisit ( const PartialApplyIterator& a) {
  thePrinter.startBeginVisit("PartialApplyIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const PartialApplyIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PartialApplyIterator>


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


// <DefaultFunctionNamespaceIterator>
void PrinterVisitor::beginVisit ( const DefaultFunctionNamespaceIterator& a) {
  thePrinter.startBeginVisit("DefaultFunctionNamespaceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DefaultFunctionNamespaceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DefaultFunctionNamespaceIterator>


// <SctxBaseUriIterator>
void PrinterVisitor::beginVisit ( const SctxBaseUriIterator& a) {
  thePrinter.startBeginVisit("SctxBaseUriIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SctxBaseUriIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxBaseUriIterator>


// <SctxDefaultCollationIterator>
void PrinterVisitor::beginVisit ( const SctxDefaultCollationIterator& a) {
  thePrinter.startBeginVisit("SctxDefaultCollationIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SctxDefaultCollationIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SctxDefaultCollationIterator>


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


// <StaticallyKnownDocumentTypeIterator>
void PrinterVisitor::beginVisit ( const StaticallyKnownDocumentTypeIterator& a) {
  thePrinter.startBeginVisit("StaticallyKnownDocumentTypeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StaticallyKnownDocumentTypeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StaticallyKnownDocumentTypeIterator>


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


// <InScopeElementDeclarationsIterator>
void PrinterVisitor::beginVisit ( const InScopeElementDeclarationsIterator& a) {
  thePrinter.startBeginVisit("InScopeElementDeclarationsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const InScopeElementDeclarationsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InScopeElementDeclarationsIterator>


// <InScopeAttributeDeclarationsIterator>
void PrinterVisitor::beginVisit ( const InScopeAttributeDeclarationsIterator& a) {
  thePrinter.startBeginVisit("InScopeAttributeDeclarationsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const InScopeAttributeDeclarationsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InScopeAttributeDeclarationsIterator>


// <InScopeElementGroupsIterator>
void PrinterVisitor::beginVisit ( const InScopeElementGroupsIterator& a) {
  thePrinter.startBeginVisit("InScopeElementGroupsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const InScopeElementGroupsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InScopeElementGroupsIterator>


// <InScopeAttributeGroupsIterator>
void PrinterVisitor::beginVisit ( const InScopeAttributeGroupsIterator& a) {
  thePrinter.startBeginVisit("InScopeAttributeGroupsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const InScopeAttributeGroupsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InScopeAttributeGroupsIterator>


// <OptionIterator>
void PrinterVisitor::beginVisit ( const OptionIterator& a) {
  thePrinter.startBeginVisit("OptionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const OptionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </OptionIterator>


// <FunctionAnnotationsIterator>
void PrinterVisitor::beginVisit ( const FunctionAnnotationsIterator& a) {
  thePrinter.startBeginVisit("FunctionAnnotationsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FunctionAnnotationsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FunctionAnnotationsIterator>


// <JSONParseInternal>
void PrinterVisitor::beginVisit ( const JSONParseInternal& a) {
  thePrinter.startBeginVisit("JSONParseInternal", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const JSONParseInternal& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONParseInternal>


// <JSONSerializeInternal>
void PrinterVisitor::beginVisit ( const JSONSerializeInternal& a) {
  thePrinter.startBeginVisit("JSONSerializeInternal", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const JSONSerializeInternal& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </JSONSerializeInternal>


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


// <Exp10Iterator>
void PrinterVisitor::beginVisit ( const Exp10Iterator& a) {
  thePrinter.startBeginVisit("Exp10Iterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const Exp10Iterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </Exp10Iterator>


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


// <NodePositionIterator>
void PrinterVisitor::beginVisit ( const NodePositionIterator& a) {
  thePrinter.startBeginVisit("NodePositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const NodePositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </NodePositionIterator>


// <IsAncestorPositionIterator>
void PrinterVisitor::beginVisit ( const IsAncestorPositionIterator& a) {
  thePrinter.startBeginVisit("IsAncestorPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsAncestorPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAncestorPositionIterator>


// <IsFollowingSiblingPositionIterator>
void PrinterVisitor::beginVisit ( const IsFollowingSiblingPositionIterator& a) {
  thePrinter.startBeginVisit("IsFollowingSiblingPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsFollowingSiblingPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsFollowingSiblingPositionIterator>


// <IsFollowingPositionIterator>
void PrinterVisitor::beginVisit ( const IsFollowingPositionIterator& a) {
  thePrinter.startBeginVisit("IsFollowingPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsFollowingPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsFollowingPositionIterator>


// <IsInSubtreeOfPositionIterator>
void PrinterVisitor::beginVisit ( const IsInSubtreeOfPositionIterator& a) {
  thePrinter.startBeginVisit("IsInSubtreeOfPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsInSubtreeOfPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsInSubtreeOfPositionIterator>


// <IsDescendantPositionIterator>
void PrinterVisitor::beginVisit ( const IsDescendantPositionIterator& a) {
  thePrinter.startBeginVisit("IsDescendantPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsDescendantPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDescendantPositionIterator>


// <IsPrecedingSiblingPositionIterator>
void PrinterVisitor::beginVisit ( const IsPrecedingSiblingPositionIterator& a) {
  thePrinter.startBeginVisit("IsPrecedingSiblingPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsPrecedingSiblingPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsPrecedingSiblingPositionIterator>


// <IsPrecedingPositionIterator>
void PrinterVisitor::beginVisit ( const IsPrecedingPositionIterator& a) {
  thePrinter.startBeginVisit("IsPrecedingPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsPrecedingPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsPrecedingPositionIterator>


// <IsChildPositionIterator>
void PrinterVisitor::beginVisit ( const IsChildPositionIterator& a) {
  thePrinter.startBeginVisit("IsChildPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsChildPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsChildPositionIterator>


// <IsAttributeOfPositionIterator>
void PrinterVisitor::beginVisit ( const IsAttributeOfPositionIterator& a) {
  thePrinter.startBeginVisit("IsAttributeOfPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsAttributeOfPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAttributeOfPositionIterator>


// <IsParentPositionIterator>
void PrinterVisitor::beginVisit ( const IsParentPositionIterator& a) {
  thePrinter.startBeginVisit("IsParentPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsParentPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsParentPositionIterator>


// <IsPrecedingInDocumentOrderPositionIterator>
void PrinterVisitor::beginVisit ( const IsPrecedingInDocumentOrderPositionIterator& a) {
  thePrinter.startBeginVisit("IsPrecedingInDocumentOrderPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsPrecedingInDocumentOrderPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsPrecedingInDocumentOrderPositionIterator>


// <IsFollowingInDocumentOrderPositionIterator>
void PrinterVisitor::beginVisit ( const IsFollowingInDocumentOrderPositionIterator& a) {
  thePrinter.startBeginVisit("IsFollowingInDocumentOrderPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsFollowingInDocumentOrderPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsFollowingInDocumentOrderPositionIterator>


// <LevelPositionIterator>
void PrinterVisitor::beginVisit ( const LevelPositionIterator& a) {
  thePrinter.startBeginVisit("LevelPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const LevelPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LevelPositionIterator>


// <IsAttributePositionIterator>
void PrinterVisitor::beginVisit ( const IsAttributePositionIterator& a) {
  thePrinter.startBeginVisit("IsAttributePositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsAttributePositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAttributePositionIterator>


// <IsCommentPositionIterator>
void PrinterVisitor::beginVisit ( const IsCommentPositionIterator& a) {
  thePrinter.startBeginVisit("IsCommentPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsCommentPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsCommentPositionIterator>


// <IsDocumentPositionIterator>
void PrinterVisitor::beginVisit ( const IsDocumentPositionIterator& a) {
  thePrinter.startBeginVisit("IsDocumentPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsDocumentPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDocumentPositionIterator>


// <IsElementPositionIterator>
void PrinterVisitor::beginVisit ( const IsElementPositionIterator& a) {
  thePrinter.startBeginVisit("IsElementPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsElementPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsElementPositionIterator>


// <IsProcessingInstructionPositionIterator>
void PrinterVisitor::beginVisit ( const IsProcessingInstructionPositionIterator& a) {
  thePrinter.startBeginVisit("IsProcessingInstructionPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsProcessingInstructionPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsProcessingInstructionPositionIterator>


// <IsTextPositionIterator>
void PrinterVisitor::beginVisit ( const IsTextPositionIterator& a) {
  thePrinter.startBeginVisit("IsTextPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsTextPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsTextPositionIterator>


// <IsSiblingPositionIterator>
void PrinterVisitor::beginVisit ( const IsSiblingPositionIterator& a) {
  thePrinter.startBeginVisit("IsSiblingPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsSiblingPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsSiblingPositionIterator>


// <InSameTreePositionIterator>
void PrinterVisitor::beginVisit ( const InSameTreePositionIterator& a) {
  thePrinter.startBeginVisit("InSameTreePositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const InSameTreePositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InSameTreePositionIterator>


// <InCollectionPositionIterator>
void PrinterVisitor::beginVisit ( const InCollectionPositionIterator& a) {
  thePrinter.startBeginVisit("InCollectionPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const InCollectionPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InCollectionPositionIterator>


// <InSameCollectionPositionIterator>
void PrinterVisitor::beginVisit ( const InSameCollectionPositionIterator& a) {
  thePrinter.startBeginVisit("InSameCollectionPositionIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const InSameCollectionPositionIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </InSameCollectionPositionIterator>


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


// <FnHasChildrenIterator>
void PrinterVisitor::beginVisit ( const FnHasChildrenIterator& a) {
  thePrinter.startBeginVisit("FnHasChildrenIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnHasChildrenIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnHasChildrenIterator>


// <FnInnermostIterator>
void PrinterVisitor::beginVisit ( const FnInnermostIterator& a) {
  thePrinter.startBeginVisit("FnInnermostIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnInnermostIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnInnermostIterator>


// <FnOutermostIterator>
void PrinterVisitor::beginVisit ( const FnOutermostIterator& a) {
  thePrinter.startBeginVisit("FnOutermostIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnOutermostIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnOutermostIterator>


// <FnGenerateIdIterator>
void PrinterVisitor::beginVisit ( const FnGenerateIdIterator& a) {
  thePrinter.startBeginVisit("FnGenerateIdIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnGenerateIdIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnGenerateIdIterator>


// <IsAncestorIterator>
void PrinterVisitor::beginVisit ( const IsAncestorIterator& a) {
  thePrinter.startBeginVisit("IsAncestorIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsAncestorIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAncestorIterator>


// <IsDescendantIterator>
void PrinterVisitor::beginVisit ( const IsDescendantIterator& a) {
  thePrinter.startBeginVisit("IsDescendantIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsDescendantIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsDescendantIterator>


// <IsParentIterator>
void PrinterVisitor::beginVisit ( const IsParentIterator& a) {
  thePrinter.startBeginVisit("IsParentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsParentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsParentIterator>


// <IsChildIterator>
void PrinterVisitor::beginVisit ( const IsChildIterator& a) {
  thePrinter.startBeginVisit("IsChildIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsChildIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsChildIterator>


// <IsFollowingIterator>
void PrinterVisitor::beginVisit ( const IsFollowingIterator& a) {
  thePrinter.startBeginVisit("IsFollowingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsFollowingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsFollowingIterator>


// <IsPrecedingIterator>
void PrinterVisitor::beginVisit ( const IsPrecedingIterator& a) {
  thePrinter.startBeginVisit("IsPrecedingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsPrecedingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsPrecedingIterator>


// <IsFollowingSiblingIterator>
void PrinterVisitor::beginVisit ( const IsFollowingSiblingIterator& a) {
  thePrinter.startBeginVisit("IsFollowingSiblingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsFollowingSiblingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsFollowingSiblingIterator>


// <IsPrecedingSiblingIterator>
void PrinterVisitor::beginVisit ( const IsPrecedingSiblingIterator& a) {
  thePrinter.startBeginVisit("IsPrecedingSiblingIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsPrecedingSiblingIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsPrecedingSiblingIterator>


// <LevelIterator>
void PrinterVisitor::beginVisit ( const LevelIterator& a) {
  thePrinter.startBeginVisit("LevelIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const LevelIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LevelIterator>


// <LeastCommonAncestor>
void PrinterVisitor::beginVisit ( const LeastCommonAncestor& a) {
  thePrinter.startBeginVisit("LeastCommonAncestor", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const LeastCommonAncestor& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </LeastCommonAncestor>


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


// <FormatIntegerIterator>
void PrinterVisitor::beginVisit ( const FormatIntegerIterator& a) {
  thePrinter.startBeginVisit("FormatIntegerIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FormatIntegerIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FormatIntegerIterator>


// <FnParseXmlFragmentIterator>
void PrinterVisitor::beginVisit ( const FnParseXmlFragmentIterator& a) {
  thePrinter.startBeginVisit("FnParseXmlFragmentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnParseXmlFragmentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnParseXmlFragmentIterator>


// <FnParseXmlIterator>
void PrinterVisitor::beginVisit ( const FnParseXmlIterator& a) {
  thePrinter.startBeginVisit("FnParseXmlIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnParseXmlIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnParseXmlIterator>


// <FnSerializeIterator>
void PrinterVisitor::beginVisit ( const FnSerializeIterator& a) {
  thePrinter.startBeginVisit("FnSerializeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnSerializeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnSerializeIterator>


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


// <SeededRandomIterator>
void PrinterVisitor::beginVisit ( const SeededRandomIterator& a) {
  thePrinter.startBeginVisit("SeededRandomIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SeededRandomIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SeededRandomIterator>


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

// <ZorbaValidateInPlaceIterator>
void PrinterVisitor::beginVisit ( const ZorbaValidateInPlaceIterator& a) {
  thePrinter.startBeginVisit("ZorbaValidateInPlaceIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaValidateInPlaceIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaValidateInPlaceIterator>


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


// <ZorbaIsValidatedIterator>
void PrinterVisitor::beginVisit ( const ZorbaIsValidatedIterator& a) {
  thePrinter.startBeginVisit("ZorbaIsValidatedIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const ZorbaIsValidatedIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </ZorbaIsValidatedIterator>


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


// <SubsequenceIntIterator>
void PrinterVisitor::beginVisit ( const SubsequenceIntIterator& a) {
  thePrinter.startBeginVisit("SubsequenceIntIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SubsequenceIntIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubsequenceIntIterator>


// <SequencePointAccessIterator>
void PrinterVisitor::beginVisit ( const SequencePointAccessIterator& a) {
  thePrinter.startBeginVisit("SequencePointAccessIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SequencePointAccessIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SequencePointAccessIterator>


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


// <FnIdIterator>
void PrinterVisitor::beginVisit ( const FnIdIterator& a) {
  thePrinter.startBeginVisit("FnIdIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnIdIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnIdIterator>


// <FnElementWithIdIterator>
void PrinterVisitor::beginVisit ( const FnElementWithIdIterator& a) {
  thePrinter.startBeginVisit("FnElementWithIdIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnElementWithIdIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnElementWithIdIterator>


// <FnIdRefIterator>
void PrinterVisitor::beginVisit ( const FnIdRefIterator& a) {
  thePrinter.startBeginVisit("FnIdRefIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnIdRefIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnIdRefIterator>


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


// <FnAvailableEnvironmentVariablesIterator>
void PrinterVisitor::beginVisit ( const FnAvailableEnvironmentVariablesIterator& a) {
  thePrinter.startBeginVisit("FnAvailableEnvironmentVariablesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnAvailableEnvironmentVariablesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnAvailableEnvironmentVariablesIterator>


// <FnEnvironmentVariableIterator>
void PrinterVisitor::beginVisit ( const FnEnvironmentVariableIterator& a) {
  thePrinter.startBeginVisit("FnEnvironmentVariableIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnEnvironmentVariableIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnEnvironmentVariableIterator>


// <FnUnparsedTextIterator>
void PrinterVisitor::beginVisit ( const FnUnparsedTextIterator& a) {
  thePrinter.startBeginVisit("FnUnparsedTextIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnUnparsedTextIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnUnparsedTextIterator>


// <FnUnparsedTextAvailableIterator>
void PrinterVisitor::beginVisit ( const FnUnparsedTextAvailableIterator& a) {
  thePrinter.startBeginVisit("FnUnparsedTextAvailableIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnUnparsedTextAvailableIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnUnparsedTextAvailableIterator>


// <FnUnparsedTextLinesIterator>
void PrinterVisitor::beginVisit ( const FnUnparsedTextLinesIterator& a) {
  thePrinter.startBeginVisit("FnUnparsedTextLinesIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnUnparsedTextLinesIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnUnparsedTextLinesIterator>


// <PutDocumentIterator>
void PrinterVisitor::beginVisit ( const PutDocumentIterator& a) {
  thePrinter.startBeginVisit("PutDocumentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const PutDocumentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </PutDocumentIterator>


// <RemoveDocumentIterator>
void PrinterVisitor::beginVisit ( const RemoveDocumentIterator& a) {
  thePrinter.startBeginVisit("RemoveDocumentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const RemoveDocumentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RemoveDocumentIterator>


// <RetrieveDocumentIterator>
void PrinterVisitor::beginVisit ( const RetrieveDocumentIterator& a) {
  thePrinter.startBeginVisit("RetrieveDocumentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const RetrieveDocumentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </RetrieveDocumentIterator>


// <AvailableDocumentsIterator>
void PrinterVisitor::beginVisit ( const AvailableDocumentsIterator& a) {
  thePrinter.startBeginVisit("AvailableDocumentsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const AvailableDocumentsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AvailableDocumentsIterator>


// <IsAvailableDocumentIterator>
void PrinterVisitor::beginVisit ( const IsAvailableDocumentIterator& a) {
  thePrinter.startBeginVisit("IsAvailableDocumentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const IsAvailableDocumentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </IsAvailableDocumentIterator>


// <MapCreateIterator>
void PrinterVisitor::beginVisit ( const MapCreateIterator& a) {
  thePrinter.startBeginVisit("MapCreateIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MapCreateIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapCreateIterator>


// <MapDestroyIterator>
void PrinterVisitor::beginVisit ( const MapDestroyIterator& a) {
  thePrinter.startBeginVisit("MapDestroyIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MapDestroyIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapDestroyIterator>


// <MapGetIterator>
void PrinterVisitor::beginVisit ( const MapGetIterator& a) {
  thePrinter.startBeginVisit("MapGetIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MapGetIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapGetIterator>


// <MapInsertIterator>
void PrinterVisitor::beginVisit ( const MapInsertIterator& a) {
  thePrinter.startBeginVisit("MapInsertIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MapInsertIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapInsertIterator>


// <MapRemoveIterator>
void PrinterVisitor::beginVisit ( const MapRemoveIterator& a) {
  thePrinter.startBeginVisit("MapRemoveIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MapRemoveIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapRemoveIterator>


// <MapKeysIterator>
void PrinterVisitor::beginVisit ( const MapKeysIterator& a) {
  thePrinter.startBeginVisit("MapKeysIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MapKeysIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapKeysIterator>


// <MapSizeIterator>
void PrinterVisitor::beginVisit ( const MapSizeIterator& a) {
  thePrinter.startBeginVisit("MapSizeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const MapSizeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </MapSizeIterator>


// <AvailableMapsIterator>
void PrinterVisitor::beginVisit ( const AvailableMapsIterator& a) {
  thePrinter.startBeginVisit("AvailableMapsIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const AvailableMapsIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </AvailableMapsIterator>


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


// <SubstringIntOptIterator>
void PrinterVisitor::beginVisit ( const SubstringIntOptIterator& a) {
  thePrinter.startBeginVisit("SubstringIntOptIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const SubstringIntOptIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </SubstringIntOptIterator>


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


// <FnAnalyzeStringIterator>
void PrinterVisitor::beginVisit ( const FnAnalyzeStringIterator& a) {
  thePrinter.startBeginVisit("FnAnalyzeStringIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const FnAnalyzeStringIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </FnAnalyzeStringIterator>


// <StringMaterializeIterator>
void PrinterVisitor::beginVisit ( const StringMaterializeIterator& a) {
  thePrinter.startBeginVisit("StringMaterializeIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StringMaterializeIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringMaterializeIterator>


// <StringIsStreamableIterator>
void PrinterVisitor::beginVisit ( const StringIsStreamableIterator& a) {
  thePrinter.startBeginVisit("StringIsStreamableIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StringIsStreamableIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringIsStreamableIterator>


// <StringSplitIterator>
void PrinterVisitor::beginVisit ( const StringSplitIterator& a) {
  thePrinter.startBeginVisit("StringSplitIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const StringSplitIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </StringSplitIterator>


// <DecodeURIIterator>
void PrinterVisitor::beginVisit ( const DecodeURIIterator& a) {
  thePrinter.startBeginVisit("DecodeURIIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const DecodeURIIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </DecodeURIIterator>


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


// <XQDocContentIterator>
void PrinterVisitor::beginVisit ( const XQDocContentIterator& a) {
  thePrinter.startBeginVisit("XQDocContentIterator", ++theId);
  printCommons( &a, theId );
  thePrinter.endBeginVisit( theId );
}

void PrinterVisitor::endVisit ( const XQDocContentIterator& ) {
  thePrinter.startEndVisit();
  thePrinter.endEndVisit();
}
// </XQDocContentIterator>


}