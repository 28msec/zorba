/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#include "runtime/visitors/profile_visitor.h"
#include "runtime/visitors/planiter_visitor.h"
#include "system/properties.h"
#include "util/string_util.h"
#include "runtime/accessors/accessors.h"
#include "runtime/any_uri/any_uri.h"
#include "runtime/base64/base64.h"
#include "runtime/booleans/booleans.h"
#include "runtime/collections/collections.h"
#include "runtime/context/context.h"
#include "runtime/csv/csv.h"
#include "runtime/datetime/datetime.h"
#include "runtime/debug/debug_iterator.h"
#include "runtime/durations_dates_times/durations_dates_times.h"
#include "runtime/errors_and_diagnostics/errors_and_diagnostics.h"
#include "runtime/errors_and_diagnostics/other_diagnostics.h"
#include "runtime/fetch/fetch.h"
#include "runtime/fnput/fnput.h"
#include "runtime/full_text/ft_module.h"
#include "runtime/hof/fn_hof_functions.h"
#include "runtime/indexing/ic_ddl.h"
#include "runtime/indexing/index_func.h"
#include "runtime/item/item.h"
#include "runtime/json/json.h"
#include "runtime/json/jsoniq_functions.h"
#include "runtime/jsound/jsound.h"
#include "runtime/maths/maths.h"
#include "runtime/nodes/node_position.h"
#include "runtime/nodes/nodes.h"
#include "runtime/numerics/numerics.h"
#include "runtime/parsing_and_serializing/parse_fragment.h"
#include "runtime/parsing_and_serializing/parsing_and_serializing.h"
#include "runtime/qnames/qnames.h"
#include "runtime/random/random.h"
#include "runtime/reference/reference.h"
#include "runtime/schema/schema.h"
#include "runtime/sctx/sctx.h"
#include "runtime/seq/seq.h"
#include "runtime/sequences/sequences.h"
#include "runtime/store/documents.h"
#include "runtime/store/maps.h"
#include "runtime/strings/strings.h"
#include "runtime/uris/uris.h"
#include "runtime/xqdoc/xqdoc.h"

namespace zorba {

void ProfileVisitor::do_something() const {
  // TODO
}


// <NodeNameIterator>
void ProfileVisitor::beginVisit( const NodeNameIterator& a) {
}

void ProfileVisitor::endVisit( const NodeNameIterator& ) {
}
// </NodeNameIterator>


// <NilledIterator>
void ProfileVisitor::beginVisit( const NilledIterator& a) {
}

void ProfileVisitor::endVisit( const NilledIterator& ) {
}
// </NilledIterator>


// <FnStringIterator>
void ProfileVisitor::beginVisit( const FnStringIterator& a) {
}

void ProfileVisitor::endVisit( const FnStringIterator& ) {
}
// </FnStringIterator>


// <FnDataIterator>
void ProfileVisitor::beginVisit( const FnDataIterator& a) {
}

void ProfileVisitor::endVisit( const FnDataIterator& ) {
}
// </FnDataIterator>


// <BaseUriIterator>
void ProfileVisitor::beginVisit( const BaseUriIterator& a) {
}

void ProfileVisitor::endVisit( const BaseUriIterator& ) {
}
// </BaseUriIterator>


// <DocumentUriIterator>
void ProfileVisitor::beginVisit( const DocumentUriIterator& a) {
}

void ProfileVisitor::endVisit( const DocumentUriIterator& ) {
}
// </DocumentUriIterator>


// <RootIterator>
void ProfileVisitor::beginVisit( const RootIterator& a) {
}

void ProfileVisitor::endVisit( const RootIterator& ) {
}
// </RootIterator>


// <ResolveUriIterator>
void ProfileVisitor::beginVisit( const ResolveUriIterator& a) {
}

void ProfileVisitor::endVisit( const ResolveUriIterator& ) {
}
// </ResolveUriIterator>


// <Base64DecodeIterator>
void ProfileVisitor::beginVisit( const Base64DecodeIterator& a) {
}

void ProfileVisitor::endVisit( const Base64DecodeIterator& ) {
}
// </Base64DecodeIterator>


// <Base64EncodeIterator>
void ProfileVisitor::beginVisit( const Base64EncodeIterator& a) {
}

void ProfileVisitor::endVisit( const Base64EncodeIterator& ) {
}
// </Base64EncodeIterator>


// <IsSameNodeIterator>
void ProfileVisitor::beginVisit( const IsSameNodeIterator& a) {
}

void ProfileVisitor::endVisit( const IsSameNodeIterator& ) {
}
// </IsSameNodeIterator>


// <NodeBeforeIterator>
void ProfileVisitor::beginVisit( const NodeBeforeIterator& a) {
}

void ProfileVisitor::endVisit( const NodeBeforeIterator& ) {
}
// </NodeBeforeIterator>


// <NodeAfterIterator>
void ProfileVisitor::beginVisit( const NodeAfterIterator& a) {
}

void ProfileVisitor::endVisit( const NodeAfterIterator& ) {
}
// </NodeAfterIterator>


// <ZorbaCreateCollectionIterator>
void ProfileVisitor::beginVisit( const ZorbaCreateCollectionIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaCreateCollectionIterator& ) {
}
// </ZorbaCreateCollectionIterator>


// <ZorbaDeleteCollectionIterator>
void ProfileVisitor::beginVisit( const ZorbaDeleteCollectionIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaDeleteCollectionIterator& ) {
}
// </ZorbaDeleteCollectionIterator>


// <IsAvailableCollectionIterator>
void ProfileVisitor::beginVisit( const IsAvailableCollectionIterator& a) {
}

void ProfileVisitor::endVisit( const IsAvailableCollectionIterator& ) {
}
// </IsAvailableCollectionIterator>


// <AvailableCollectionsIterator>
void ProfileVisitor::beginVisit( const AvailableCollectionsIterator& a) {
}

void ProfileVisitor::endVisit( const AvailableCollectionsIterator& ) {
}
// </AvailableCollectionsIterator>


// <FnCollectionIterator>
void ProfileVisitor::beginVisit( const FnCollectionIterator& a) {
}

void ProfileVisitor::endVisit( const FnCollectionIterator& ) {
}
// </FnCollectionIterator>


// <ZorbaCollectionIterator>
void ProfileVisitor::beginVisit( const ZorbaCollectionIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaCollectionIterator& ) {
}
// </ZorbaCollectionIterator>


// <ZorbaCollectionNameIterator>
void ProfileVisitor::beginVisit( const ZorbaCollectionNameIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaCollectionNameIterator& ) {
}
// </ZorbaCollectionNameIterator>


// <ZorbaIndexOfIterator>
void ProfileVisitor::beginVisit( const ZorbaIndexOfIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaIndexOfIterator& ) {
}
// </ZorbaIndexOfIterator>


// <ZorbaDeleteIterator>
void ProfileVisitor::beginVisit( const ZorbaDeleteIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaDeleteIterator& ) {
}
// </ZorbaDeleteIterator>


// <ZorbaDeleteFirstIterator>
void ProfileVisitor::beginVisit( const ZorbaDeleteFirstIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaDeleteFirstIterator& ) {
}
// </ZorbaDeleteFirstIterator>


// <ZorbaDeleteLastIterator>
void ProfileVisitor::beginVisit( const ZorbaDeleteLastIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaDeleteLastIterator& ) {
}
// </ZorbaDeleteLastIterator>


// <ZorbaEditIterator>
void ProfileVisitor::beginVisit( const ZorbaEditIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaEditIterator& ) {
}
// </ZorbaEditIterator>


// <ZorbaTruncateCollectionIterator>
void ProfileVisitor::beginVisit( const ZorbaTruncateCollectionIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaTruncateCollectionIterator& ) {
}
// </ZorbaTruncateCollectionIterator>


// <IsAvailableIndexIterator>
void ProfileVisitor::beginVisit( const IsAvailableIndexIterator& a) {
}

void ProfileVisitor::endVisit( const IsAvailableIndexIterator& ) {
}
// </IsAvailableIndexIterator>


// <AvailableIndexesIterator>
void ProfileVisitor::beginVisit( const AvailableIndexesIterator& a) {
}

void ProfileVisitor::endVisit( const AvailableIndexesIterator& ) {
}
// </AvailableIndexesIterator>


// <IsActivatedICIterator>
void ProfileVisitor::beginVisit( const IsActivatedICIterator& a) {
}

void ProfileVisitor::endVisit( const IsActivatedICIterator& ) {
}
// </IsActivatedICIterator>


// <ActivatedICsIterator>
void ProfileVisitor::beginVisit( const ActivatedICsIterator& a) {
}

void ProfileVisitor::endVisit( const ActivatedICsIterator& ) {
}
// </ActivatedICsIterator>


// <IsDeclaredCollectionIterator>
void ProfileVisitor::beginVisit( const IsDeclaredCollectionIterator& a) {
}

void ProfileVisitor::endVisit( const IsDeclaredCollectionIterator& ) {
}
// </IsDeclaredCollectionIterator>


// <DeclaredCollectionsIterator>
void ProfileVisitor::beginVisit( const DeclaredCollectionsIterator& a) {
}

void ProfileVisitor::endVisit( const DeclaredCollectionsIterator& ) {
}
// </DeclaredCollectionsIterator>


// <IsDeclaredIndexIterator>
void ProfileVisitor::beginVisit( const IsDeclaredIndexIterator& a) {
}

void ProfileVisitor::endVisit( const IsDeclaredIndexIterator& ) {
}
// </IsDeclaredIndexIterator>


// <DeclaredIndexesIterator>
void ProfileVisitor::beginVisit( const DeclaredIndexesIterator& a) {
}

void ProfileVisitor::endVisit( const DeclaredIndexesIterator& ) {
}
// </DeclaredIndexesIterator>


// <IsDeclaredICIterator>
void ProfileVisitor::beginVisit( const IsDeclaredICIterator& a) {
}

void ProfileVisitor::endVisit( const IsDeclaredICIterator& ) {
}
// </IsDeclaredICIterator>


// <DeclaredICsIterator>
void ProfileVisitor::beginVisit( const DeclaredICsIterator& a) {
}

void ProfileVisitor::endVisit( const DeclaredICsIterator& ) {
}
// </DeclaredICsIterator>


// <FnURICollectionIterator>
void ProfileVisitor::beginVisit( const FnURICollectionIterator& a) {
}

void ProfileVisitor::endVisit( const FnURICollectionIterator& ) {
}
// </FnURICollectionIterator>


// <CurrentDateTimeIterator>
void ProfileVisitor::beginVisit( const CurrentDateTimeIterator& a) {
}

void ProfileVisitor::endVisit( const CurrentDateTimeIterator& ) {
}
// </CurrentDateTimeIterator>


// <CurrentDateIterator>
void ProfileVisitor::beginVisit( const CurrentDateIterator& a) {
}

void ProfileVisitor::endVisit( const CurrentDateIterator& ) {
}
// </CurrentDateIterator>


// <CurrentTimeIterator>
void ProfileVisitor::beginVisit( const CurrentTimeIterator& a) {
}

void ProfileVisitor::endVisit( const CurrentTimeIterator& ) {
}
// </CurrentTimeIterator>


// <ImplicitTimezoneIterator>
void ProfileVisitor::beginVisit( const ImplicitTimezoneIterator& a) {
}

void ProfileVisitor::endVisit( const ImplicitTimezoneIterator& ) {
}
// </ImplicitTimezoneIterator>


// <DefaultCollationIterator>
void ProfileVisitor::beginVisit( const DefaultCollationIterator& a) {
}

void ProfileVisitor::endVisit( const DefaultCollationIterator& ) {
}
// </DefaultCollationIterator>


// <CsvParseIterator>
void ProfileVisitor::beginVisit( const CsvParseIterator& a) {
}

void ProfileVisitor::endVisit( const CsvParseIterator& ) {
}
// </CsvParseIterator>


// <CsvSerializeIterator>
void ProfileVisitor::beginVisit( const CsvSerializeIterator& a) {
}

void ProfileVisitor::endVisit( const CsvSerializeIterator& ) {
}
// </CsvSerializeIterator>


// <CurrentDate>
void ProfileVisitor::beginVisit( const CurrentDate& a) {
}

void ProfileVisitor::endVisit( const CurrentDate& ) {
}
// </CurrentDate>


// <CurrentDateTime>
void ProfileVisitor::beginVisit( const CurrentDateTime& a) {
}

void ProfileVisitor::endVisit( const CurrentDateTime& ) {
}
// </CurrentDateTime>


// <CurrentTime>
void ProfileVisitor::beginVisit( const CurrentTime& a) {
}

void ProfileVisitor::endVisit( const CurrentTime& ) {
}
// </CurrentTime>


// <MillisToDateTime>
void ProfileVisitor::beginVisit( const MillisToDateTime& a) {
}

void ProfileVisitor::endVisit( const MillisToDateTime& ) {
}
// </MillisToDateTime>


// <ParseDate>
void ProfileVisitor::beginVisit( const ParseDate& a) {
}

void ProfileVisitor::endVisit( const ParseDate& ) {
}
// </ParseDate>


// <ParseDateTime>
void ProfileVisitor::beginVisit( const ParseDateTime& a) {
}

void ProfileVisitor::endVisit( const ParseDateTime& ) {
}
// </ParseDateTime>


// <ParseTime>
void ProfileVisitor::beginVisit( const ParseTime& a) {
}

void ProfileVisitor::endVisit( const ParseTime& ) {
}
// </ParseTime>


// <Timestamp>
void ProfileVisitor::beginVisit( const Timestamp& a) {
}

void ProfileVisitor::endVisit( const Timestamp& ) {
}
// </Timestamp>


// <UTCOffset>
void ProfileVisitor::beginVisit( const UTCOffset& a) {
}

void ProfileVisitor::endVisit( const UTCOffset& ) {
}
// </UTCOffset>

#ifdef ZORBA_WITH_DEBUGGER
// <DebugIterator>
void ProfileVisitor::beginVisit( const DebugIterator& a) {
}

void ProfileVisitor::endVisit( const DebugIterator& ) {
}
// </DebugIterator>

#endif

// <YearsFromDurationIterator>
void ProfileVisitor::beginVisit( const YearsFromDurationIterator& a) {
}

void ProfileVisitor::endVisit( const YearsFromDurationIterator& ) {
}
// </YearsFromDurationIterator>


// <MonthsFromDurationIterator>
void ProfileVisitor::beginVisit( const MonthsFromDurationIterator& a) {
}

void ProfileVisitor::endVisit( const MonthsFromDurationIterator& ) {
}
// </MonthsFromDurationIterator>


// <DaysFromDurationIterator>
void ProfileVisitor::beginVisit( const DaysFromDurationIterator& a) {
}

void ProfileVisitor::endVisit( const DaysFromDurationIterator& ) {
}
// </DaysFromDurationIterator>


// <HoursFromDurationIterator>
void ProfileVisitor::beginVisit( const HoursFromDurationIterator& a) {
}

void ProfileVisitor::endVisit( const HoursFromDurationIterator& ) {
}
// </HoursFromDurationIterator>


// <MinutesFromDurationIterator>
void ProfileVisitor::beginVisit( const MinutesFromDurationIterator& a) {
}

void ProfileVisitor::endVisit( const MinutesFromDurationIterator& ) {
}
// </MinutesFromDurationIterator>


// <SecondsFromDurationIterator>
void ProfileVisitor::beginVisit( const SecondsFromDurationIterator& a) {
}

void ProfileVisitor::endVisit( const SecondsFromDurationIterator& ) {
}
// </SecondsFromDurationIterator>


// <YearFromDatetimeIterator>
void ProfileVisitor::beginVisit( const YearFromDatetimeIterator& a) {
}

void ProfileVisitor::endVisit( const YearFromDatetimeIterator& ) {
}
// </YearFromDatetimeIterator>


// <MonthFromDatetimeIterator>
void ProfileVisitor::beginVisit( const MonthFromDatetimeIterator& a) {
}

void ProfileVisitor::endVisit( const MonthFromDatetimeIterator& ) {
}
// </MonthFromDatetimeIterator>


// <DayFromDatetimeIterator>
void ProfileVisitor::beginVisit( const DayFromDatetimeIterator& a) {
}

void ProfileVisitor::endVisit( const DayFromDatetimeIterator& ) {
}
// </DayFromDatetimeIterator>


// <HoursFromDatetimeIterator>
void ProfileVisitor::beginVisit( const HoursFromDatetimeIterator& a) {
}

void ProfileVisitor::endVisit( const HoursFromDatetimeIterator& ) {
}
// </HoursFromDatetimeIterator>


// <MinutesFromDatetimeIterator>
void ProfileVisitor::beginVisit( const MinutesFromDatetimeIterator& a) {
}

void ProfileVisitor::endVisit( const MinutesFromDatetimeIterator& ) {
}
// </MinutesFromDatetimeIterator>


// <SecondsFromDatetimeIterator>
void ProfileVisitor::beginVisit( const SecondsFromDatetimeIterator& a) {
}

void ProfileVisitor::endVisit( const SecondsFromDatetimeIterator& ) {
}
// </SecondsFromDatetimeIterator>


// <TimezoneFromDatetimeIterator>
void ProfileVisitor::beginVisit( const TimezoneFromDatetimeIterator& a) {
}

void ProfileVisitor::endVisit( const TimezoneFromDatetimeIterator& ) {
}
// </TimezoneFromDatetimeIterator>


// <YearFromDateIterator>
void ProfileVisitor::beginVisit( const YearFromDateIterator& a) {
}

void ProfileVisitor::endVisit( const YearFromDateIterator& ) {
}
// </YearFromDateIterator>


// <MonthFromDateIterator>
void ProfileVisitor::beginVisit( const MonthFromDateIterator& a) {
}

void ProfileVisitor::endVisit( const MonthFromDateIterator& ) {
}
// </MonthFromDateIterator>


// <DayFromDateIterator>
void ProfileVisitor::beginVisit( const DayFromDateIterator& a) {
}

void ProfileVisitor::endVisit( const DayFromDateIterator& ) {
}
// </DayFromDateIterator>


// <TimezoneFromDateIterator>
void ProfileVisitor::beginVisit( const TimezoneFromDateIterator& a) {
}

void ProfileVisitor::endVisit( const TimezoneFromDateIterator& ) {
}
// </TimezoneFromDateIterator>


// <HoursFromTimeIterator>
void ProfileVisitor::beginVisit( const HoursFromTimeIterator& a) {
}

void ProfileVisitor::endVisit( const HoursFromTimeIterator& ) {
}
// </HoursFromTimeIterator>


// <MinutesFromTimeIterator>
void ProfileVisitor::beginVisit( const MinutesFromTimeIterator& a) {
}

void ProfileVisitor::endVisit( const MinutesFromTimeIterator& ) {
}
// </MinutesFromTimeIterator>


// <SecondsFromTimeIterator>
void ProfileVisitor::beginVisit( const SecondsFromTimeIterator& a) {
}

void ProfileVisitor::endVisit( const SecondsFromTimeIterator& ) {
}
// </SecondsFromTimeIterator>


// <TimezoneFromTimeIterator>
void ProfileVisitor::beginVisit( const TimezoneFromTimeIterator& a) {
}

void ProfileVisitor::endVisit( const TimezoneFromTimeIterator& ) {
}
// </TimezoneFromTimeIterator>


// <ErrorIterator>
void ProfileVisitor::beginVisit( const ErrorIterator& a) {
}

void ProfileVisitor::endVisit( const ErrorIterator& ) {
}
// </ErrorIterator>


// <TraceIterator>
void ProfileVisitor::beginVisit( const TraceIterator& a) {
}

void ProfileVisitor::endVisit( const TraceIterator& ) {
}
// </TraceIterator>


// <ReadLineIterator>
void ProfileVisitor::beginVisit( const ReadLineIterator& a) {
}

void ProfileVisitor::endVisit( const ReadLineIterator& ) {
}
// </ReadLineIterator>


// <PrintIterator>
void ProfileVisitor::beginVisit( const PrintIterator& a) {
}

void ProfileVisitor::endVisit( const PrintIterator& ) {
}
// </PrintIterator>


// <FunctionTraceIterator>
void ProfileVisitor::beginVisit( const FunctionTraceIterator& a) {
}

void ProfileVisitor::endVisit( const FunctionTraceIterator& ) {
}
// </FunctionTraceIterator>


// <FetchContentIterator>
void ProfileVisitor::beginVisit( const FetchContentIterator& a) {
}

void ProfileVisitor::endVisit( const FetchContentIterator& ) {
}
// </FetchContentIterator>


// <FetchContentBinaryIterator>
void ProfileVisitor::beginVisit( const FetchContentBinaryIterator& a) {
}

void ProfileVisitor::endVisit( const FetchContentBinaryIterator& ) {
}
// </FetchContentBinaryIterator>


// <FetchContentTypeIterator>
void ProfileVisitor::beginVisit( const FetchContentTypeIterator& a) {
}

void ProfileVisitor::endVisit( const FetchContentTypeIterator& ) {
}
// </FetchContentTypeIterator>


// <FnPutIterator>
void ProfileVisitor::beginVisit( const FnPutIterator& a) {
}

void ProfileVisitor::endVisit( const FnPutIterator& ) {
}
// </FnPutIterator>

#ifndef ZORBA_NO_FULL_TEXT
// <CurrentCompareOptionsIterator>
void ProfileVisitor::beginVisit( const CurrentCompareOptionsIterator& a) {
}

void ProfileVisitor::endVisit( const CurrentCompareOptionsIterator& ) {
}
// </CurrentCompareOptionsIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <CurrentLangIterator>
void ProfileVisitor::beginVisit( const CurrentLangIterator& a) {
}

void ProfileVisitor::endVisit( const CurrentLangIterator& ) {
}
// </CurrentLangIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <HostLangIterator>
void ProfileVisitor::beginVisit( const HostLangIterator& a) {
}

void ProfileVisitor::endVisit( const HostLangIterator& ) {
}
// </HostLangIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsStemLangSupportedIterator>
void ProfileVisitor::beginVisit( const IsStemLangSupportedIterator& a) {
}

void ProfileVisitor::endVisit( const IsStemLangSupportedIterator& ) {
}
// </IsStemLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsStopWordIterator>
void ProfileVisitor::beginVisit( const IsStopWordIterator& a) {
}

void ProfileVisitor::endVisit( const IsStopWordIterator& ) {
}
// </IsStopWordIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsStopWordLangSupportedIterator>
void ProfileVisitor::beginVisit( const IsStopWordLangSupportedIterator& a) {
}

void ProfileVisitor::endVisit( const IsStopWordLangSupportedIterator& ) {
}
// </IsStopWordLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsThesaurusLangSupportedIterator>
void ProfileVisitor::beginVisit( const IsThesaurusLangSupportedIterator& a) {
}

void ProfileVisitor::endVisit( const IsThesaurusLangSupportedIterator& ) {
}
// </IsThesaurusLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <IsTokenizerLangSupportedIterator>
void ProfileVisitor::beginVisit( const IsTokenizerLangSupportedIterator& a) {
}

void ProfileVisitor::endVisit( const IsTokenizerLangSupportedIterator& ) {
}
// </IsTokenizerLangSupportedIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <StemIterator>
void ProfileVisitor::beginVisit( const StemIterator& a) {
}

void ProfileVisitor::endVisit( const StemIterator& ) {
}
// </StemIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <StripDiacriticsIterator>
void ProfileVisitor::beginVisit( const StripDiacriticsIterator& a) {
}

void ProfileVisitor::endVisit( const StripDiacriticsIterator& ) {
}
// </StripDiacriticsIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <ThesaurusLookupIterator>
void ProfileVisitor::beginVisit( const ThesaurusLookupIterator& a) {
}

void ProfileVisitor::endVisit( const ThesaurusLookupIterator& ) {
}
// </ThesaurusLookupIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizeNodeIterator>
void ProfileVisitor::beginVisit( const TokenizeNodeIterator& a) {
}

void ProfileVisitor::endVisit( const TokenizeNodeIterator& ) {
}
// </TokenizeNodeIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizeNodesIterator>
void ProfileVisitor::beginVisit( const TokenizeNodesIterator& a) {
}

void ProfileVisitor::endVisit( const TokenizeNodesIterator& ) {
}
// </TokenizeNodesIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizerPropertiesIterator>
void ProfileVisitor::beginVisit( const TokenizerPropertiesIterator& a) {
}

void ProfileVisitor::endVisit( const TokenizerPropertiesIterator& ) {
}
// </TokenizerPropertiesIterator>

#endif
#ifndef ZORBA_NO_FULL_TEXT
// <TokenizeStringIterator>
void ProfileVisitor::beginVisit( const TokenizeStringIterator& a) {
}

void ProfileVisitor::endVisit( const TokenizeStringIterator& ) {
}
// </TokenizeStringIterator>

#endif

// <FunctionLookupIterator>
void ProfileVisitor::beginVisit( const FunctionLookupIterator& a) {
}

void ProfileVisitor::endVisit( const FunctionLookupIterator& ) {
}
// </FunctionLookupIterator>


// <FunctionNameIterator>
void ProfileVisitor::beginVisit( const FunctionNameIterator& a) {
}

void ProfileVisitor::endVisit( const FunctionNameIterator& ) {
}
// </FunctionNameIterator>


// <FunctionArityIterator>
void ProfileVisitor::beginVisit( const FunctionArityIterator& a) {
}

void ProfileVisitor::endVisit( const FunctionArityIterator& ) {
}
// </FunctionArityIterator>


// <FnForEachPairIterator>
void ProfileVisitor::beginVisit( const FnForEachPairIterator& a) {
}

void ProfileVisitor::endVisit( const FnForEachPairIterator& ) {
}
// </FnForEachPairIterator>


// <FnFoldLeftIterator>
void ProfileVisitor::beginVisit( const FnFoldLeftIterator& a) {
}

void ProfileVisitor::endVisit( const FnFoldLeftIterator& ) {
}
// </FnFoldLeftIterator>


// <ActivateICIterator>
void ProfileVisitor::beginVisit( const ActivateICIterator& a) {
}

void ProfileVisitor::endVisit( const ActivateICIterator& ) {
}
// </ActivateICIterator>


// <DeactivateICIterator>
void ProfileVisitor::beginVisit( const DeactivateICIterator& a) {
}

void ProfileVisitor::endVisit( const DeactivateICIterator& ) {
}
// </DeactivateICIterator>


// <CheckICIterator>
void ProfileVisitor::beginVisit( const CheckICIterator& a) {
}

void ProfileVisitor::endVisit( const CheckICIterator& ) {
}
// </CheckICIterator>


// <IndexKeysIterator>
void ProfileVisitor::beginVisit( const IndexKeysIterator& a) {
}

void ProfileVisitor::endVisit( const IndexKeysIterator& ) {
}
// </IndexKeysIterator>


// <MemSizeIterator>
void ProfileVisitor::beginVisit( const MemSizeIterator& a) {
}

void ProfileVisitor::endVisit( const MemSizeIterator& ) {
}
// </MemSizeIterator>


// <JSONtoXMLInternal>
void ProfileVisitor::beginVisit( const JSONtoXMLInternal& a) {
}

void ProfileVisitor::endVisit( const JSONtoXMLInternal& ) {
}
// </JSONtoXMLInternal>


// <XMLtoJSONInternal>
void ProfileVisitor::beginVisit( const XMLtoJSONInternal& a) {
}

void ProfileVisitor::endVisit( const XMLtoJSONInternal& ) {
}
// </XMLtoJSONInternal>


// <JSONDecodeFromRoundtripIterator>
void ProfileVisitor::beginVisit( const JSONDecodeFromRoundtripIterator& a) {
}

void ProfileVisitor::endVisit( const JSONDecodeFromRoundtripIterator& ) {
}
// </JSONDecodeFromRoundtripIterator>


// <JSONEncodeForRoundtripIterator>
void ProfileVisitor::beginVisit( const JSONEncodeForRoundtripIterator& a) {
}

void ProfileVisitor::endVisit( const JSONEncodeForRoundtripIterator& ) {
}
// </JSONEncodeForRoundtripIterator>


// <JSONParseIterator>
void ProfileVisitor::beginVisit( const JSONParseIterator& a) {
}

void ProfileVisitor::endVisit( const JSONParseIterator& ) {
}
// </JSONParseIterator>


// <MultiObjectKeysIterator>
void ProfileVisitor::beginVisit( const MultiObjectKeysIterator& a) {
}

void ProfileVisitor::endVisit( const MultiObjectKeysIterator& ) {
}
// </MultiObjectKeysIterator>


// <SingleObjectKeysIterator>
void ProfileVisitor::beginVisit( const SingleObjectKeysIterator& a) {
}

void ProfileVisitor::endVisit( const SingleObjectKeysIterator& ) {
}
// </SingleObjectKeysIterator>


// <MultiObjectLookupIterator>
void ProfileVisitor::beginVisit( const MultiObjectLookupIterator& a) {
}

void ProfileVisitor::endVisit( const MultiObjectLookupIterator& ) {
}
// </MultiObjectLookupIterator>


// <SingleObjectLookupIterator>
void ProfileVisitor::beginVisit( const SingleObjectLookupIterator& a) {
}

void ProfileVisitor::endVisit( const SingleObjectLookupIterator& ) {
}
// </SingleObjectLookupIterator>


// <JSONObjectProjectIterator>
void ProfileVisitor::beginVisit( const JSONObjectProjectIterator& a) {
}

void ProfileVisitor::endVisit( const JSONObjectProjectIterator& ) {
}
// </JSONObjectProjectIterator>


// <JSONObjectTrimIterator>
void ProfileVisitor::beginVisit( const JSONObjectTrimIterator& a) {
}

void ProfileVisitor::endVisit( const JSONObjectTrimIterator& ) {
}
// </JSONObjectTrimIterator>


// <MultiArrayMembersIterator>
void ProfileVisitor::beginVisit( const MultiArrayMembersIterator& a) {
}

void ProfileVisitor::endVisit( const MultiArrayMembersIterator& ) {
}
// </MultiArrayMembersIterator>


// <SingleArrayMembersIterator>
void ProfileVisitor::beginVisit( const SingleArrayMembersIterator& a) {
}

void ProfileVisitor::endVisit( const SingleArrayMembersIterator& ) {
}
// </SingleArrayMembersIterator>


// <MultiArrayLookupIterator>
void ProfileVisitor::beginVisit( const MultiArrayLookupIterator& a) {
}

void ProfileVisitor::endVisit( const MultiArrayLookupIterator& ) {
}
// </MultiArrayLookupIterator>


// <SingleArrayLookupIterator>
void ProfileVisitor::beginVisit( const SingleArrayLookupIterator& a) {
}

void ProfileVisitor::endVisit( const SingleArrayLookupIterator& ) {
}
// </SingleArrayLookupIterator>


// <JSONArraySizeIterator>
void ProfileVisitor::beginVisit( const JSONArraySizeIterator& a) {
}

void ProfileVisitor::endVisit( const JSONArraySizeIterator& ) {
}
// </JSONArraySizeIterator>


// <JSONArrayFlattenIterator>
void ProfileVisitor::beginVisit( const JSONArrayFlattenIterator& a) {
}

void ProfileVisitor::endVisit( const JSONArrayFlattenIterator& ) {
}
// </JSONArrayFlattenIterator>


// <JSONNullIterator>
void ProfileVisitor::beginVisit( const JSONNullIterator& a) {
}

void ProfileVisitor::endVisit( const JSONNullIterator& ) {
}
// </JSONNullIterator>


// <JSONObjectInsertIterator>
void ProfileVisitor::beginVisit( const JSONObjectInsertIterator& a) {
}

void ProfileVisitor::endVisit( const JSONObjectInsertIterator& ) {
}
// </JSONObjectInsertIterator>


// <JSONArrayInsertIterator>
void ProfileVisitor::beginVisit( const JSONArrayInsertIterator& a) {
}

void ProfileVisitor::endVisit( const JSONArrayInsertIterator& ) {
}
// </JSONArrayInsertIterator>


// <JSONDeleteIterator>
void ProfileVisitor::beginVisit( const JSONDeleteIterator& a) {
}

void ProfileVisitor::endVisit( const JSONDeleteIterator& ) {
}
// </JSONDeleteIterator>


// <JSONReplaceValueIterator>
void ProfileVisitor::beginVisit( const JSONReplaceValueIterator& a) {
}

void ProfileVisitor::endVisit( const JSONReplaceValueIterator& ) {
}
// </JSONReplaceValueIterator>


// <JSONRenameIterator>
void ProfileVisitor::beginVisit( const JSONRenameIterator& a) {
}

void ProfileVisitor::endVisit( const JSONRenameIterator& ) {
}
// </JSONRenameIterator>


// <JSONArrayAppendIterator>
void ProfileVisitor::beginVisit( const JSONArrayAppendIterator& a) {
}

void ProfileVisitor::endVisit( const JSONArrayAppendIterator& ) {
}
// </JSONArrayAppendIterator>


// <JSONBoxIterator>
void ProfileVisitor::beginVisit( const JSONBoxIterator& a) {
}

void ProfileVisitor::endVisit( const JSONBoxIterator& ) {
}
// </JSONBoxIterator>


// <JSoundAnnotateIterator>
void ProfileVisitor::beginVisit( const JSoundAnnotateIterator& a) {
}

void ProfileVisitor::endVisit( const JSoundAnnotateIterator& ) {
}
// </JSoundAnnotateIterator>


// <JSoundValidateIterator>
void ProfileVisitor::beginVisit( const JSoundValidateIterator& a) {
}

void ProfileVisitor::endVisit( const JSoundValidateIterator& ) {
}
// </JSoundValidateIterator>


// <SqrtIterator>
void ProfileVisitor::beginVisit( const SqrtIterator& a) {
}

void ProfileVisitor::endVisit( const SqrtIterator& ) {
}
// </SqrtIterator>


// <ExpIterator>
void ProfileVisitor::beginVisit( const ExpIterator& a) {
}

void ProfileVisitor::endVisit( const ExpIterator& ) {
}
// </ExpIterator>


// <Exp10Iterator>
void ProfileVisitor::beginVisit( const Exp10Iterator& a) {
}

void ProfileVisitor::endVisit( const Exp10Iterator& ) {
}
// </Exp10Iterator>


// <LogIterator>
void ProfileVisitor::beginVisit( const LogIterator& a) {
}

void ProfileVisitor::endVisit( const LogIterator& ) {
}
// </LogIterator>


// <Log10Iterator>
void ProfileVisitor::beginVisit( const Log10Iterator& a) {
}

void ProfileVisitor::endVisit( const Log10Iterator& ) {
}
// </Log10Iterator>


// <SinIterator>
void ProfileVisitor::beginVisit( const SinIterator& a) {
}

void ProfileVisitor::endVisit( const SinIterator& ) {
}
// </SinIterator>


// <CosIterator>
void ProfileVisitor::beginVisit( const CosIterator& a) {
}

void ProfileVisitor::endVisit( const CosIterator& ) {
}
// </CosIterator>


// <TanIterator>
void ProfileVisitor::beginVisit( const TanIterator& a) {
}

void ProfileVisitor::endVisit( const TanIterator& ) {
}
// </TanIterator>


// <ArcSinIterator>
void ProfileVisitor::beginVisit( const ArcSinIterator& a) {
}

void ProfileVisitor::endVisit( const ArcSinIterator& ) {
}
// </ArcSinIterator>


// <ArcCosIterator>
void ProfileVisitor::beginVisit( const ArcCosIterator& a) {
}

void ProfileVisitor::endVisit( const ArcCosIterator& ) {
}
// </ArcCosIterator>


// <ArcTanIterator>
void ProfileVisitor::beginVisit( const ArcTanIterator& a) {
}

void ProfileVisitor::endVisit( const ArcTanIterator& ) {
}
// </ArcTanIterator>


// <Atan2Iterator>
void ProfileVisitor::beginVisit( const Atan2Iterator& a) {
}

void ProfileVisitor::endVisit( const Atan2Iterator& ) {
}
// </Atan2Iterator>


// <CoshIterator>
void ProfileVisitor::beginVisit( const CoshIterator& a) {
}

void ProfileVisitor::endVisit( const CoshIterator& ) {
}
// </CoshIterator>


// <AcoshIterator>
void ProfileVisitor::beginVisit( const AcoshIterator& a) {
}

void ProfileVisitor::endVisit( const AcoshIterator& ) {
}
// </AcoshIterator>


// <FmodIterator>
void ProfileVisitor::beginVisit( const FmodIterator& a) {
}

void ProfileVisitor::endVisit( const FmodIterator& ) {
}
// </FmodIterator>


// <LdexpIterator>
void ProfileVisitor::beginVisit( const LdexpIterator& a) {
}

void ProfileVisitor::endVisit( const LdexpIterator& ) {
}
// </LdexpIterator>


// <PowIterator>
void ProfileVisitor::beginVisit( const PowIterator& a) {
}

void ProfileVisitor::endVisit( const PowIterator& ) {
}
// </PowIterator>


// <SinhIterator>
void ProfileVisitor::beginVisit( const SinhIterator& a) {
}

void ProfileVisitor::endVisit( const SinhIterator& ) {
}
// </SinhIterator>


// <AsinhIterator>
void ProfileVisitor::beginVisit( const AsinhIterator& a) {
}

void ProfileVisitor::endVisit( const AsinhIterator& ) {
}
// </AsinhIterator>


// <TanhIterator>
void ProfileVisitor::beginVisit( const TanhIterator& a) {
}

void ProfileVisitor::endVisit( const TanhIterator& ) {
}
// </TanhIterator>


// <AtanhIterator>
void ProfileVisitor::beginVisit( const AtanhIterator& a) {
}

void ProfileVisitor::endVisit( const AtanhIterator& ) {
}
// </AtanhIterator>


// <PiNumberIterator>
void ProfileVisitor::beginVisit( const PiNumberIterator& a) {
}

void ProfileVisitor::endVisit( const PiNumberIterator& ) {
}
// </PiNumberIterator>


// <IsInfIterator>
void ProfileVisitor::beginVisit( const IsInfIterator& a) {
}

void ProfileVisitor::endVisit( const IsInfIterator& ) {
}
// </IsInfIterator>


// <IsNaNIterator>
void ProfileVisitor::beginVisit( const IsNaNIterator& a) {
}

void ProfileVisitor::endVisit( const IsNaNIterator& ) {
}
// </IsNaNIterator>


// <ModfIterator>
void ProfileVisitor::beginVisit( const ModfIterator& a) {
}

void ProfileVisitor::endVisit( const ModfIterator& ) {
}
// </ModfIterator>


// <FrexpIterator>
void ProfileVisitor::beginVisit( const FrexpIterator& a) {
}

void ProfileVisitor::endVisit( const FrexpIterator& ) {
}
// </FrexpIterator>


// <NodePositionIterator>
void ProfileVisitor::beginVisit( const NodePositionIterator& a) {
}

void ProfileVisitor::endVisit( const NodePositionIterator& ) {
}
// </NodePositionIterator>


// <IsAncestorPositionIterator>
void ProfileVisitor::beginVisit( const IsAncestorPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsAncestorPositionIterator& ) {
}
// </IsAncestorPositionIterator>


// <IsFollowingSiblingPositionIterator>
void ProfileVisitor::beginVisit( const IsFollowingSiblingPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsFollowingSiblingPositionIterator& ) {
}
// </IsFollowingSiblingPositionIterator>


// <IsFollowingPositionIterator>
void ProfileVisitor::beginVisit( const IsFollowingPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsFollowingPositionIterator& ) {
}
// </IsFollowingPositionIterator>


// <IsInSubtreeOfPositionIterator>
void ProfileVisitor::beginVisit( const IsInSubtreeOfPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsInSubtreeOfPositionIterator& ) {
}
// </IsInSubtreeOfPositionIterator>


// <IsDescendantPositionIterator>
void ProfileVisitor::beginVisit( const IsDescendantPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsDescendantPositionIterator& ) {
}
// </IsDescendantPositionIterator>


// <IsPrecedingSiblingPositionIterator>
void ProfileVisitor::beginVisit( const IsPrecedingSiblingPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsPrecedingSiblingPositionIterator& ) {
}
// </IsPrecedingSiblingPositionIterator>


// <IsPrecedingPositionIterator>
void ProfileVisitor::beginVisit( const IsPrecedingPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsPrecedingPositionIterator& ) {
}
// </IsPrecedingPositionIterator>


// <IsChildPositionIterator>
void ProfileVisitor::beginVisit( const IsChildPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsChildPositionIterator& ) {
}
// </IsChildPositionIterator>


// <IsAttributeOfPositionIterator>
void ProfileVisitor::beginVisit( const IsAttributeOfPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsAttributeOfPositionIterator& ) {
}
// </IsAttributeOfPositionIterator>


// <IsParentPositionIterator>
void ProfileVisitor::beginVisit( const IsParentPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsParentPositionIterator& ) {
}
// </IsParentPositionIterator>


// <IsPrecedingInDocumentOrderPositionIterator>
void ProfileVisitor::beginVisit( const IsPrecedingInDocumentOrderPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsPrecedingInDocumentOrderPositionIterator& ) {
}
// </IsPrecedingInDocumentOrderPositionIterator>


// <IsFollowingInDocumentOrderPositionIterator>
void ProfileVisitor::beginVisit( const IsFollowingInDocumentOrderPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsFollowingInDocumentOrderPositionIterator& ) {
}
// </IsFollowingInDocumentOrderPositionIterator>


// <LevelPositionIterator>
void ProfileVisitor::beginVisit( const LevelPositionIterator& a) {
}

void ProfileVisitor::endVisit( const LevelPositionIterator& ) {
}
// </LevelPositionIterator>


// <IsAttributePositionIterator>
void ProfileVisitor::beginVisit( const IsAttributePositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsAttributePositionIterator& ) {
}
// </IsAttributePositionIterator>


// <IsCommentPositionIterator>
void ProfileVisitor::beginVisit( const IsCommentPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsCommentPositionIterator& ) {
}
// </IsCommentPositionIterator>


// <IsDocumentPositionIterator>
void ProfileVisitor::beginVisit( const IsDocumentPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsDocumentPositionIterator& ) {
}
// </IsDocumentPositionIterator>


// <IsElementPositionIterator>
void ProfileVisitor::beginVisit( const IsElementPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsElementPositionIterator& ) {
}
// </IsElementPositionIterator>


// <IsProcessingInstructionPositionIterator>
void ProfileVisitor::beginVisit( const IsProcessingInstructionPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsProcessingInstructionPositionIterator& ) {
}
// </IsProcessingInstructionPositionIterator>


// <IsTextPositionIterator>
void ProfileVisitor::beginVisit( const IsTextPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsTextPositionIterator& ) {
}
// </IsTextPositionIterator>


// <IsSiblingPositionIterator>
void ProfileVisitor::beginVisit( const IsSiblingPositionIterator& a) {
}

void ProfileVisitor::endVisit( const IsSiblingPositionIterator& ) {
}
// </IsSiblingPositionIterator>


// <InSameTreePositionIterator>
void ProfileVisitor::beginVisit( const InSameTreePositionIterator& a) {
}

void ProfileVisitor::endVisit( const InSameTreePositionIterator& ) {
}
// </InSameTreePositionIterator>


// <InCollectionPositionIterator>
void ProfileVisitor::beginVisit( const InCollectionPositionIterator& a) {
}

void ProfileVisitor::endVisit( const InCollectionPositionIterator& ) {
}
// </InCollectionPositionIterator>


// <InSameCollectionPositionIterator>
void ProfileVisitor::beginVisit( const InSameCollectionPositionIterator& a) {
}

void ProfileVisitor::endVisit( const InSameCollectionPositionIterator& ) {
}
// </InSameCollectionPositionIterator>


// <FnLocalNameIterator>
void ProfileVisitor::beginVisit( const FnLocalNameIterator& a) {
}

void ProfileVisitor::endVisit( const FnLocalNameIterator& ) {
}
// </FnLocalNameIterator>


// <FnNamespaceUriIterator>
void ProfileVisitor::beginVisit( const FnNamespaceUriIterator& a) {
}

void ProfileVisitor::endVisit( const FnNamespaceUriIterator& ) {
}
// </FnNamespaceUriIterator>


// <FnLangIterator>
void ProfileVisitor::beginVisit( const FnLangIterator& a) {
}

void ProfileVisitor::endVisit( const FnLangIterator& ) {
}
// </FnLangIterator>


// <FnHasChildrenIterator>
void ProfileVisitor::beginVisit( const FnHasChildrenIterator& a) {
}

void ProfileVisitor::endVisit( const FnHasChildrenIterator& ) {
}
// </FnHasChildrenIterator>


// <FnInnermostIterator>
void ProfileVisitor::beginVisit( const FnInnermostIterator& a) {
}

void ProfileVisitor::endVisit( const FnInnermostIterator& ) {
}
// </FnInnermostIterator>


// <FnOutermostIterator>
void ProfileVisitor::beginVisit( const FnOutermostIterator& a) {
}

void ProfileVisitor::endVisit( const FnOutermostIterator& ) {
}
// </FnOutermostIterator>


// <FnGenerateIdIterator>
void ProfileVisitor::beginVisit( const FnGenerateIdIterator& a) {
}

void ProfileVisitor::endVisit( const FnGenerateIdIterator& ) {
}
// </FnGenerateIdIterator>


// <IsAncestorIterator>
void ProfileVisitor::beginVisit( const IsAncestorIterator& a) {
}

void ProfileVisitor::endVisit( const IsAncestorIterator& ) {
}
// </IsAncestorIterator>


// <IsDescendantIterator>
void ProfileVisitor::beginVisit( const IsDescendantIterator& a) {
}

void ProfileVisitor::endVisit( const IsDescendantIterator& ) {
}
// </IsDescendantIterator>


// <IsParentIterator>
void ProfileVisitor::beginVisit( const IsParentIterator& a) {
}

void ProfileVisitor::endVisit( const IsParentIterator& ) {
}
// </IsParentIterator>


// <IsChildIterator>
void ProfileVisitor::beginVisit( const IsChildIterator& a) {
}

void ProfileVisitor::endVisit( const IsChildIterator& ) {
}
// </IsChildIterator>


// <IsFollowingIterator>
void ProfileVisitor::beginVisit( const IsFollowingIterator& a) {
}

void ProfileVisitor::endVisit( const IsFollowingIterator& ) {
}
// </IsFollowingIterator>


// <IsPrecedingIterator>
void ProfileVisitor::beginVisit( const IsPrecedingIterator& a) {
}

void ProfileVisitor::endVisit( const IsPrecedingIterator& ) {
}
// </IsPrecedingIterator>


// <IsFollowingSiblingIterator>
void ProfileVisitor::beginVisit( const IsFollowingSiblingIterator& a) {
}

void ProfileVisitor::endVisit( const IsFollowingSiblingIterator& ) {
}
// </IsFollowingSiblingIterator>


// <IsPrecedingSiblingIterator>
void ProfileVisitor::beginVisit( const IsPrecedingSiblingIterator& a) {
}

void ProfileVisitor::endVisit( const IsPrecedingSiblingIterator& ) {
}
// </IsPrecedingSiblingIterator>


// <LevelIterator>
void ProfileVisitor::beginVisit( const LevelIterator& a) {
}

void ProfileVisitor::endVisit( const LevelIterator& ) {
}
// </LevelIterator>


// <LeastCommonAncestor>
void ProfileVisitor::beginVisit( const LeastCommonAncestor& a) {
}

void ProfileVisitor::endVisit( const LeastCommonAncestor& ) {
}
// </LeastCommonAncestor>


// <FnPathIterator>
void ProfileVisitor::beginVisit( const FnPathIterator& a) {
}

void ProfileVisitor::endVisit( const FnPathIterator& ) {
}
// </FnPathIterator>


// <NodeCopyIterator>
void ProfileVisitor::beginVisit( const NodeCopyIterator& a) {
}

void ProfileVisitor::endVisit( const NodeCopyIterator& ) {
}
// </NodeCopyIterator>


// <AbsIterator>
void ProfileVisitor::beginVisit( const AbsIterator& a) {
}

void ProfileVisitor::endVisit( const AbsIterator& ) {
}
// </AbsIterator>


// <CeilingIterator>
void ProfileVisitor::beginVisit( const CeilingIterator& a) {
}

void ProfileVisitor::endVisit( const CeilingIterator& ) {
}
// </CeilingIterator>


// <FloorIterator>
void ProfileVisitor::beginVisit( const FloorIterator& a) {
}

void ProfileVisitor::endVisit( const FloorIterator& ) {
}
// </FloorIterator>


// <RoundIterator>
void ProfileVisitor::beginVisit( const RoundIterator& a) {
}

void ProfileVisitor::endVisit( const RoundIterator& ) {
}
// </RoundIterator>


// <RoundHalfToEvenIterator>
void ProfileVisitor::beginVisit( const RoundHalfToEvenIterator& a) {
}

void ProfileVisitor::endVisit( const RoundHalfToEvenIterator& ) {
}
// </RoundHalfToEvenIterator>


// <FormatNumberIterator>
void ProfileVisitor::beginVisit( const FormatNumberIterator& a) {
}

void ProfileVisitor::endVisit( const FormatNumberIterator& ) {
}
// </FormatNumberIterator>


// <FormatIntegerIterator>
void ProfileVisitor::beginVisit( const FormatIntegerIterator& a) {
}

void ProfileVisitor::endVisit( const FormatIntegerIterator& ) {
}
// </FormatIntegerIterator>


// <FnZorbaParseXmlFragmentIterator>
void ProfileVisitor::beginVisit( const FnZorbaParseXmlFragmentIterator& a) {
}

void ProfileVisitor::endVisit( const FnZorbaParseXmlFragmentIterator& ) {
}
// </FnZorbaParseXmlFragmentIterator>


// <FnZorbaCanonicalizeIterator>
void ProfileVisitor::beginVisit( const FnZorbaCanonicalizeIterator& a) {
}

void ProfileVisitor::endVisit( const FnZorbaCanonicalizeIterator& ) {
}
// </FnZorbaCanonicalizeIterator>


// <FnParseXmlFragmentIterator>
void ProfileVisitor::beginVisit( const FnParseXmlFragmentIterator& a) {
}

void ProfileVisitor::endVisit( const FnParseXmlFragmentIterator& ) {
}
// </FnParseXmlFragmentIterator>


// <FnParseXmlIterator>
void ProfileVisitor::beginVisit( const FnParseXmlIterator& a) {
}

void ProfileVisitor::endVisit( const FnParseXmlIterator& ) {
}
// </FnParseXmlIterator>


// <FnSerializeIterator>
void ProfileVisitor::beginVisit( const FnSerializeIterator& a) {
}

void ProfileVisitor::endVisit( const FnSerializeIterator& ) {
}
// </FnSerializeIterator>


// <ResolveQNameIterator>
void ProfileVisitor::beginVisit( const ResolveQNameIterator& a) {
}

void ProfileVisitor::endVisit( const ResolveQNameIterator& ) {
}
// </ResolveQNameIterator>


// <QNameIterator>
void ProfileVisitor::beginVisit( const QNameIterator& a) {
}

void ProfileVisitor::endVisit( const QNameIterator& ) {
}
// </QNameIterator>


// <QNameEqualIterator>
void ProfileVisitor::beginVisit( const QNameEqualIterator& a) {
}

void ProfileVisitor::endVisit( const QNameEqualIterator& ) {
}
// </QNameEqualIterator>


// <PrefixFromQNameIterator>
void ProfileVisitor::beginVisit( const PrefixFromQNameIterator& a) {
}

void ProfileVisitor::endVisit( const PrefixFromQNameIterator& ) {
}
// </PrefixFromQNameIterator>


// <LocalNameFromQNameIterator>
void ProfileVisitor::beginVisit( const LocalNameFromQNameIterator& a) {
}

void ProfileVisitor::endVisit( const LocalNameFromQNameIterator& ) {
}
// </LocalNameFromQNameIterator>


// <NamespaceUriFromQNameIterator>
void ProfileVisitor::beginVisit( const NamespaceUriFromQNameIterator& a) {
}

void ProfileVisitor::endVisit( const NamespaceUriFromQNameIterator& ) {
}
// </NamespaceUriFromQNameIterator>


// <NamespaceUriForPrefixIterator>
void ProfileVisitor::beginVisit( const NamespaceUriForPrefixIterator& a) {
}

void ProfileVisitor::endVisit( const NamespaceUriForPrefixIterator& ) {
}
// </NamespaceUriForPrefixIterator>


// <InScopePrefixesIterator>
void ProfileVisitor::beginVisit( const InScopePrefixesIterator& a) {
}

void ProfileVisitor::endVisit( const InScopePrefixesIterator& ) {
}
// </InScopePrefixesIterator>


// <SeededRandomIterator>
void ProfileVisitor::beginVisit( const SeededRandomIterator& a) {
}

void ProfileVisitor::endVisit( const SeededRandomIterator& ) {
}
// </SeededRandomIterator>


// <RandomIterator>
void ProfileVisitor::beginVisit( const RandomIterator& a) {
}

void ProfileVisitor::endVisit( const RandomIterator& ) {
}
// </RandomIterator>


// <UuidIterator>
void ProfileVisitor::beginVisit( const UuidIterator& a) {
}

void ProfileVisitor::endVisit( const UuidIterator& ) {
}
// </UuidIterator>


// <ReferenceIterator>
void ProfileVisitor::beginVisit( const ReferenceIterator& a) {
}

void ProfileVisitor::endVisit( const ReferenceIterator& ) {
}
// </ReferenceIterator>


// <HasReferenceIterator>
void ProfileVisitor::beginVisit( const HasReferenceIterator& a) {
}

void ProfileVisitor::endVisit( const HasReferenceIterator& ) {
}
// </HasReferenceIterator>


// <AssignReferenceIterator>
void ProfileVisitor::beginVisit( const AssignReferenceIterator& a) {
}

void ProfileVisitor::endVisit( const AssignReferenceIterator& ) {
}
// </AssignReferenceIterator>


// <DereferenceIterator>
void ProfileVisitor::beginVisit( const DereferenceIterator& a) {
}

void ProfileVisitor::endVisit( const DereferenceIterator& ) {
}
// </DereferenceIterator>

#ifndef ZORBA_NO_XMLSCHEMA
// <ValidateIterator>
void ProfileVisitor::beginVisit( const ValidateIterator& a) {
}

void ProfileVisitor::endVisit( const ValidateIterator& ) {
}
// </ValidateIterator>

#endif

// <ZorbaValidateInPlaceIterator>
void ProfileVisitor::beginVisit( const ZorbaValidateInPlaceIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaValidateInPlaceIterator& ) {
}
// </ZorbaValidateInPlaceIterator>


// <ZorbaSchemaTypeIterator>
void ProfileVisitor::beginVisit( const ZorbaSchemaTypeIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaSchemaTypeIterator& ) {
}
// </ZorbaSchemaTypeIterator>


// <ZorbaIsValidatedIterator>
void ProfileVisitor::beginVisit( const ZorbaIsValidatedIterator& a) {
}

void ProfileVisitor::endVisit( const ZorbaIsValidatedIterator& ) {
}
// </ZorbaIsValidatedIterator>


// <SctxBaseUriIterator>
void ProfileVisitor::beginVisit( const SctxBaseUriIterator& a) {
}

void ProfileVisitor::endVisit( const SctxBaseUriIterator& ) {
}
// </SctxBaseUriIterator>


// <SctxBoundarySpacePolicyIterator>
void ProfileVisitor::beginVisit( const SctxBoundarySpacePolicyIterator& a) {
}

void ProfileVisitor::endVisit( const SctxBoundarySpacePolicyIterator& ) {
}
// </SctxBoundarySpacePolicyIterator>


// <SctxConstructionModeIterator>
void ProfileVisitor::beginVisit( const SctxConstructionModeIterator& a) {
}

void ProfileVisitor::endVisit( const SctxConstructionModeIterator& ) {
}
// </SctxConstructionModeIterator>


// <SctxCopyNamespacesModeIterator>
void ProfileVisitor::beginVisit( const SctxCopyNamespacesModeIterator& a) {
}

void ProfileVisitor::endVisit( const SctxCopyNamespacesModeIterator& ) {
}
// </SctxCopyNamespacesModeIterator>


// <SctxDefaultCollationIterator>
void ProfileVisitor::beginVisit( const SctxDefaultCollationIterator& a) {
}

void ProfileVisitor::endVisit( const SctxDefaultCollationIterator& ) {
}
// </SctxDefaultCollationIterator>


// <SctxDefaultCollectionTypeIterator>
void ProfileVisitor::beginVisit( const SctxDefaultCollectionTypeIterator& a) {
}

void ProfileVisitor::endVisit( const SctxDefaultCollectionTypeIterator& ) {
}
// </SctxDefaultCollectionTypeIterator>


// <SctxDefaultFunctionNamespaceIterator>
void ProfileVisitor::beginVisit( const SctxDefaultFunctionNamespaceIterator& a) {
}

void ProfileVisitor::endVisit( const SctxDefaultFunctionNamespaceIterator& ) {
}
// </SctxDefaultFunctionNamespaceIterator>


// <SctxDefaultOrderIterator>
void ProfileVisitor::beginVisit( const SctxDefaultOrderIterator& a) {
}

void ProfileVisitor::endVisit( const SctxDefaultOrderIterator& ) {
}
// </SctxDefaultOrderIterator>


// <SctxFunctionAnnotationsIterator>
void ProfileVisitor::beginVisit( const SctxFunctionAnnotationsIterator& a) {
}

void ProfileVisitor::endVisit( const SctxFunctionAnnotationsIterator& ) {
}
// </SctxFunctionAnnotationsIterator>


// <SctxFunctionArgumentsCountIterator>
void ProfileVisitor::beginVisit( const SctxFunctionArgumentsCountIterator& a) {
}

void ProfileVisitor::endVisit( const SctxFunctionArgumentsCountIterator& ) {
}
// </SctxFunctionArgumentsCountIterator>


// <SctxFunctionNamesIterator>
void ProfileVisitor::beginVisit( const SctxFunctionNamesIterator& a) {
}

void ProfileVisitor::endVisit( const SctxFunctionNamesIterator& ) {
}
// </SctxFunctionNamesIterator>


// <SctxFunctionsIterator>
void ProfileVisitor::beginVisit( const SctxFunctionsIterator& a) {
}

void ProfileVisitor::endVisit( const SctxFunctionsIterator& ) {
}
// </SctxFunctionsIterator>


// <SctxInScopeAttributeDeclarationsIterator>
void ProfileVisitor::beginVisit( const SctxInScopeAttributeDeclarationsIterator& a) {
}

void ProfileVisitor::endVisit( const SctxInScopeAttributeDeclarationsIterator& ) {
}
// </SctxInScopeAttributeDeclarationsIterator>


// <SctxInScopeAttributeGroupsIterator>
void ProfileVisitor::beginVisit( const SctxInScopeAttributeGroupsIterator& a) {
}

void ProfileVisitor::endVisit( const SctxInScopeAttributeGroupsIterator& ) {
}
// </SctxInScopeAttributeGroupsIterator>


// <SctxInScopeElementDeclarationsIterator>
void ProfileVisitor::beginVisit( const SctxInScopeElementDeclarationsIterator& a) {
}

void ProfileVisitor::endVisit( const SctxInScopeElementDeclarationsIterator& ) {
}
// </SctxInScopeElementDeclarationsIterator>


// <SctxInScopeElementGroupsIterator>
void ProfileVisitor::beginVisit( const SctxInScopeElementGroupsIterator& a) {
}

void ProfileVisitor::endVisit( const SctxInScopeElementGroupsIterator& ) {
}
// </SctxInScopeElementGroupsIterator>


// <SctxInScopeSchemaTypesIterator>
void ProfileVisitor::beginVisit( const SctxInScopeSchemaTypesIterator& a) {
}

void ProfileVisitor::endVisit( const SctxInScopeSchemaTypesIterator& ) {
}
// </SctxInScopeSchemaTypesIterator>


// <SctxInscopeVariablesIterator>
void ProfileVisitor::beginVisit( const SctxInscopeVariablesIterator& a) {
}

void ProfileVisitor::endVisit( const SctxInscopeVariablesIterator& ) {
}
// </SctxInscopeVariablesIterator>


// <SctxOptionIterator>
void ProfileVisitor::beginVisit( const SctxOptionIterator& a) {
}

void ProfileVisitor::endVisit( const SctxOptionIterator& ) {
}
// </SctxOptionIterator>


// <SctxOrderingModeIterator>
void ProfileVisitor::beginVisit( const SctxOrderingModeIterator& a) {
}

void ProfileVisitor::endVisit( const SctxOrderingModeIterator& ) {
}
// </SctxOrderingModeIterator>


// <SctxStaticallyKnownCollationsIterator>
void ProfileVisitor::beginVisit( const SctxStaticallyKnownCollationsIterator& a) {
}

void ProfileVisitor::endVisit( const SctxStaticallyKnownCollationsIterator& ) {
}
// </SctxStaticallyKnownCollationsIterator>


// <SctxStaticallyKnownDocumentsIterator>
void ProfileVisitor::beginVisit( const SctxStaticallyKnownDocumentsIterator& a) {
}

void ProfileVisitor::endVisit( const SctxStaticallyKnownDocumentsIterator& ) {
}
// </SctxStaticallyKnownDocumentsIterator>


// <SctxStaticallyKnownDocumentTypeIterator>
void ProfileVisitor::beginVisit( const SctxStaticallyKnownDocumentTypeIterator& a) {
}

void ProfileVisitor::endVisit( const SctxStaticallyKnownDocumentTypeIterator& ) {
}
// </SctxStaticallyKnownDocumentTypeIterator>


// <SctxStaticallyKnownNamespaceBindingIterator>
void ProfileVisitor::beginVisit( const SctxStaticallyKnownNamespaceBindingIterator& a) {
}

void ProfileVisitor::endVisit( const SctxStaticallyKnownNamespaceBindingIterator& ) {
}
// </SctxStaticallyKnownNamespaceBindingIterator>


// <SctxStaticallyKnownNamespacesIterator>
void ProfileVisitor::beginVisit( const SctxStaticallyKnownNamespacesIterator& a) {
}

void ProfileVisitor::endVisit( const SctxStaticallyKnownNamespacesIterator& ) {
}
// </SctxStaticallyKnownNamespacesIterator>


// <SctxXPath10CompatModeIterator>
void ProfileVisitor::beginVisit( const SctxXPath10CompatModeIterator& a) {
}

void ProfileVisitor::endVisit( const SctxXPath10CompatModeIterator& ) {
}
// </SctxXPath10CompatModeIterator>


// <SeqValueIntersectIterator>
void ProfileVisitor::beginVisit( const SeqValueIntersectIterator& a) {
}

void ProfileVisitor::endVisit( const SeqValueIntersectIterator& ) {
}
// </SeqValueIntersectIterator>


// <SeqValueUnionIterator>
void ProfileVisitor::beginVisit( const SeqValueUnionIterator& a) {
}

void ProfileVisitor::endVisit( const SeqValueUnionIterator& ) {
}
// </SeqValueUnionIterator>


// <SeqValueExceptIterator>
void ProfileVisitor::beginVisit( const SeqValueExceptIterator& a) {
}

void ProfileVisitor::endVisit( const SeqValueExceptIterator& ) {
}
// </SeqValueExceptIterator>


// <FnConcatIterator>
void ProfileVisitor::beginVisit( const FnConcatIterator& a) {
}

void ProfileVisitor::endVisit( const FnConcatIterator& ) {
}
// </FnConcatIterator>


// <FnIndexOfIterator>
void ProfileVisitor::beginVisit( const FnIndexOfIterator& a) {
}

void ProfileVisitor::endVisit( const FnIndexOfIterator& ) {
}
// </FnIndexOfIterator>


// <FnEmptyIterator>
void ProfileVisitor::beginVisit( const FnEmptyIterator& a) {
}

void ProfileVisitor::endVisit( const FnEmptyIterator& ) {
}
// </FnEmptyIterator>


// <FnExistsIterator>
void ProfileVisitor::beginVisit( const FnExistsIterator& a) {
}

void ProfileVisitor::endVisit( const FnExistsIterator& ) {
}
// </FnExistsIterator>


// <FnDistinctValuesIterator>
void ProfileVisitor::beginVisit( const FnDistinctValuesIterator& a) {
}

void ProfileVisitor::endVisit( const FnDistinctValuesIterator& ) {
}
// </FnDistinctValuesIterator>


// <FnInsertBeforeIterator>
void ProfileVisitor::beginVisit( const FnInsertBeforeIterator& a) {
}

void ProfileVisitor::endVisit( const FnInsertBeforeIterator& ) {
}
// </FnInsertBeforeIterator>


// <FnRemoveIterator>
void ProfileVisitor::beginVisit( const FnRemoveIterator& a) {
}

void ProfileVisitor::endVisit( const FnRemoveIterator& ) {
}
// </FnRemoveIterator>


// <FnReverseIterator>
void ProfileVisitor::beginVisit( const FnReverseIterator& a) {
}

void ProfileVisitor::endVisit( const FnReverseIterator& ) {
}
// </FnReverseIterator>


// <FnSubsequenceIterator>
void ProfileVisitor::beginVisit( const FnSubsequenceIterator& a) {
}

void ProfileVisitor::endVisit( const FnSubsequenceIterator& ) {
}
// </FnSubsequenceIterator>


// <SubsequenceIntIterator>
void ProfileVisitor::beginVisit( const SubsequenceIntIterator& a) {
}

void ProfileVisitor::endVisit( const SubsequenceIntIterator& ) {
}
// </SubsequenceIntIterator>


// <SequencePointAccessIterator>
void ProfileVisitor::beginVisit( const SequencePointAccessIterator& a) {
}

void ProfileVisitor::endVisit( const SequencePointAccessIterator& ) {
}
// </SequencePointAccessIterator>


// <FnZeroOrOneIterator>
void ProfileVisitor::beginVisit( const FnZeroOrOneIterator& a) {
}

void ProfileVisitor::endVisit( const FnZeroOrOneIterator& ) {
}
// </FnZeroOrOneIterator>


// <FnOneOrMoreIterator>
void ProfileVisitor::beginVisit( const FnOneOrMoreIterator& a) {
}

void ProfileVisitor::endVisit( const FnOneOrMoreIterator& ) {
}
// </FnOneOrMoreIterator>


// <FnExactlyOneIterator>
void ProfileVisitor::beginVisit( const FnExactlyOneIterator& a) {
}

void ProfileVisitor::endVisit( const FnExactlyOneIterator& ) {
}
// </FnExactlyOneIterator>


// <FnDeepEqualIterator>
void ProfileVisitor::beginVisit( const FnDeepEqualIterator& a) {
}

void ProfileVisitor::endVisit( const FnDeepEqualIterator& ) {
}
// </FnDeepEqualIterator>


// <HashSemiJoinIterator>
void ProfileVisitor::beginVisit( const HashSemiJoinIterator& a) {
}

void ProfileVisitor::endVisit( const HashSemiJoinIterator& ) {
}
// </HashSemiJoinIterator>


// <SortSemiJoinIterator>
void ProfileVisitor::beginVisit( const SortSemiJoinIterator& a) {
}

void ProfileVisitor::endVisit( const SortSemiJoinIterator& ) {
}
// </SortSemiJoinIterator>


// <FnCountIterator>
void ProfileVisitor::beginVisit( const FnCountIterator& a) {
}

void ProfileVisitor::endVisit( const FnCountIterator& ) {
}
// </FnCountIterator>


// <FnAvgIterator>
void ProfileVisitor::beginVisit( const FnAvgIterator& a) {
}

void ProfileVisitor::endVisit( const FnAvgIterator& ) {
}
// </FnAvgIterator>


// <FnSumIterator>
void ProfileVisitor::beginVisit( const FnSumIterator& a) {
}

void ProfileVisitor::endVisit( const FnSumIterator& ) {
}
// </FnSumIterator>


// <FnSumDoubleIterator>
void ProfileVisitor::beginVisit( const FnSumDoubleIterator& a) {
}

void ProfileVisitor::endVisit( const FnSumDoubleIterator& ) {
}
// </FnSumDoubleIterator>


// <FnSumFloatIterator>
void ProfileVisitor::beginVisit( const FnSumFloatIterator& a) {
}

void ProfileVisitor::endVisit( const FnSumFloatIterator& ) {
}
// </FnSumFloatIterator>


// <FnSumDecimalIterator>
void ProfileVisitor::beginVisit( const FnSumDecimalIterator& a) {
}

void ProfileVisitor::endVisit( const FnSumDecimalIterator& ) {
}
// </FnSumDecimalIterator>


// <FnSumIntegerIterator>
void ProfileVisitor::beginVisit( const FnSumIntegerIterator& a) {
}

void ProfileVisitor::endVisit( const FnSumIntegerIterator& ) {
}
// </FnSumIntegerIterator>


// <OpToIterator>
void ProfileVisitor::beginVisit( const OpToIterator& a) {
}

void ProfileVisitor::endVisit( const OpToIterator& ) {
}
// </OpToIterator>


// <FnIdIterator>
void ProfileVisitor::beginVisit( const FnIdIterator& a) {
}

void ProfileVisitor::endVisit( const FnIdIterator& ) {
}
// </FnIdIterator>


// <FnElementWithIdIterator>
void ProfileVisitor::beginVisit( const FnElementWithIdIterator& a) {
}

void ProfileVisitor::endVisit( const FnElementWithIdIterator& ) {
}
// </FnElementWithIdIterator>


// <FnIdRefIterator>
void ProfileVisitor::beginVisit( const FnIdRefIterator& a) {
}

void ProfileVisitor::endVisit( const FnIdRefIterator& ) {
}
// </FnIdRefIterator>


// <FnDocIterator>
void ProfileVisitor::beginVisit( const FnDocIterator& a) {
}

void ProfileVisitor::endVisit( const FnDocIterator& ) {
}
// </FnDocIterator>


// <FnDocAvailableIterator>
void ProfileVisitor::beginVisit( const FnDocAvailableIterator& a) {
}

void ProfileVisitor::endVisit( const FnDocAvailableIterator& ) {
}
// </FnDocAvailableIterator>


// <FnAvailableEnvironmentVariablesIterator>
void ProfileVisitor::beginVisit( const FnAvailableEnvironmentVariablesIterator& a) {
}

void ProfileVisitor::endVisit( const FnAvailableEnvironmentVariablesIterator& ) {
}
// </FnAvailableEnvironmentVariablesIterator>


// <FnEnvironmentVariableIterator>
void ProfileVisitor::beginVisit( const FnEnvironmentVariableIterator& a) {
}

void ProfileVisitor::endVisit( const FnEnvironmentVariableIterator& ) {
}
// </FnEnvironmentVariableIterator>


// <FnUnparsedTextIterator>
void ProfileVisitor::beginVisit( const FnUnparsedTextIterator& a) {
}

void ProfileVisitor::endVisit( const FnUnparsedTextIterator& ) {
}
// </FnUnparsedTextIterator>


// <FnUnparsedTextAvailableIterator>
void ProfileVisitor::beginVisit( const FnUnparsedTextAvailableIterator& a) {
}

void ProfileVisitor::endVisit( const FnUnparsedTextAvailableIterator& ) {
}
// </FnUnparsedTextAvailableIterator>


// <FnUnparsedTextLinesIterator>
void ProfileVisitor::beginVisit( const FnUnparsedTextLinesIterator& a) {
}

void ProfileVisitor::endVisit( const FnUnparsedTextLinesIterator& ) {
}
// </FnUnparsedTextLinesIterator>


// <AvailableDocumentsIterator>
void ProfileVisitor::beginVisit( const AvailableDocumentsIterator& a) {
}

void ProfileVisitor::endVisit( const AvailableDocumentsIterator& ) {
}
// </AvailableDocumentsIterator>


// <IsAvailableDocumentIterator>
void ProfileVisitor::beginVisit( const IsAvailableDocumentIterator& a) {
}

void ProfileVisitor::endVisit( const IsAvailableDocumentIterator& ) {
}
// </IsAvailableDocumentIterator>


// <PutDocumentIterator>
void ProfileVisitor::beginVisit( const PutDocumentIterator& a) {
}

void ProfileVisitor::endVisit( const PutDocumentIterator& ) {
}
// </PutDocumentIterator>


// <RemoveDocumentIterator>
void ProfileVisitor::beginVisit( const RemoveDocumentIterator& a) {
}

void ProfileVisitor::endVisit( const RemoveDocumentIterator& ) {
}
// </RemoveDocumentIterator>


// <RetrieveDocumentIterator>
void ProfileVisitor::beginVisit( const RetrieveDocumentIterator& a) {
}

void ProfileVisitor::endVisit( const RetrieveDocumentIterator& ) {
}
// </RetrieveDocumentIterator>


// <MapCreateIterator>
void ProfileVisitor::beginVisit( const MapCreateIterator& a) {
}

void ProfileVisitor::endVisit( const MapCreateIterator& ) {
}
// </MapCreateIterator>


// <MapDropIterator>
void ProfileVisitor::beginVisit( const MapDropIterator& a) {
}

void ProfileVisitor::endVisit( const MapDropIterator& ) {
}
// </MapDropIterator>


// <MapGetIterator>
void ProfileVisitor::beginVisit( const MapGetIterator& a) {
}

void ProfileVisitor::endVisit( const MapGetIterator& ) {
}
// </MapGetIterator>


// <MapInsertIterator>
void ProfileVisitor::beginVisit( const MapInsertIterator& a) {
}

void ProfileVisitor::endVisit( const MapInsertIterator& ) {
}
// </MapInsertIterator>


// <MapDeleteIterator>
void ProfileVisitor::beginVisit( const MapDeleteIterator& a) {
}

void ProfileVisitor::endVisit( const MapDeleteIterator& ) {
}
// </MapDeleteIterator>


// <MapKeysIterator>
void ProfileVisitor::beginVisit( const MapKeysIterator& a) {
}

void ProfileVisitor::endVisit( const MapKeysIterator& ) {
}
// </MapKeysIterator>


// <MapSizeIterator>
void ProfileVisitor::beginVisit( const MapSizeIterator& a) {
}

void ProfileVisitor::endVisit( const MapSizeIterator& ) {
}
// </MapSizeIterator>


// <AvailableMapsIterator>
void ProfileVisitor::beginVisit( const AvailableMapsIterator& a) {
}

void ProfileVisitor::endVisit( const AvailableMapsIterator& ) {
}
// </AvailableMapsIterator>


// <MapOptionsIterator>
void ProfileVisitor::beginVisit( const MapOptionsIterator& a) {
}

void ProfileVisitor::endVisit( const MapOptionsIterator& ) {
}
// </MapOptionsIterator>


// <CodepointsToStringIterator>
void ProfileVisitor::beginVisit( const CodepointsToStringIterator& a) {
}

void ProfileVisitor::endVisit( const CodepointsToStringIterator& ) {
}
// </CodepointsToStringIterator>


// <StringToCodepointsIterator>
void ProfileVisitor::beginVisit( const StringToCodepointsIterator& a) {
}

void ProfileVisitor::endVisit( const StringToCodepointsIterator& ) {
}
// </StringToCodepointsIterator>


// <CompareStrIterator>
void ProfileVisitor::beginVisit( const CompareStrIterator& a) {
}

void ProfileVisitor::endVisit( const CompareStrIterator& ) {
}
// </CompareStrIterator>


// <CodepointEqualIterator>
void ProfileVisitor::beginVisit( const CodepointEqualIterator& a) {
}

void ProfileVisitor::endVisit( const CodepointEqualIterator& ) {
}
// </CodepointEqualIterator>


// <ConcatStrIterator>
void ProfileVisitor::beginVisit( const ConcatStrIterator& a) {
}

void ProfileVisitor::endVisit( const ConcatStrIterator& ) {
}
// </ConcatStrIterator>


// <StringJoinIterator>
void ProfileVisitor::beginVisit( const StringJoinIterator& a) {
}

void ProfileVisitor::endVisit( const StringJoinIterator& ) {
}
// </StringJoinIterator>


// <SubstringIterator>
void ProfileVisitor::beginVisit( const SubstringIterator& a) {
}

void ProfileVisitor::endVisit( const SubstringIterator& ) {
}
// </SubstringIterator>


// <SubstringIntOptIterator>
void ProfileVisitor::beginVisit( const SubstringIntOptIterator& a) {
}

void ProfileVisitor::endVisit( const SubstringIntOptIterator& ) {
}
// </SubstringIntOptIterator>


// <StringLengthIterator>
void ProfileVisitor::beginVisit( const StringLengthIterator& a) {
}

void ProfileVisitor::endVisit( const StringLengthIterator& ) {
}
// </StringLengthIterator>


// <NormalizeSpaceIterator>
void ProfileVisitor::beginVisit( const NormalizeSpaceIterator& a) {
}

void ProfileVisitor::endVisit( const NormalizeSpaceIterator& ) {
}
// </NormalizeSpaceIterator>


// <NormalizeUnicodeIterator>
void ProfileVisitor::beginVisit( const NormalizeUnicodeIterator& a) {
}

void ProfileVisitor::endVisit( const NormalizeUnicodeIterator& ) {
}
// </NormalizeUnicodeIterator>


// <UpperCaseIterator>
void ProfileVisitor::beginVisit( const UpperCaseIterator& a) {
}

void ProfileVisitor::endVisit( const UpperCaseIterator& ) {
}
// </UpperCaseIterator>


// <LowerCaseIterator>
void ProfileVisitor::beginVisit( const LowerCaseIterator& a) {
}

void ProfileVisitor::endVisit( const LowerCaseIterator& ) {
}
// </LowerCaseIterator>


// <TranslateIterator>
void ProfileVisitor::beginVisit( const TranslateIterator& a) {
}

void ProfileVisitor::endVisit( const TranslateIterator& ) {
}
// </TranslateIterator>


// <EncodeForUriIterator>
void ProfileVisitor::beginVisit( const EncodeForUriIterator& a) {
}

void ProfileVisitor::endVisit( const EncodeForUriIterator& ) {
}
// </EncodeForUriIterator>


// <IriToUriIterator>
void ProfileVisitor::beginVisit( const IriToUriIterator& a) {
}

void ProfileVisitor::endVisit( const IriToUriIterator& ) {
}
// </IriToUriIterator>


// <EscapeHtmlUriIterator>
void ProfileVisitor::beginVisit( const EscapeHtmlUriIterator& a) {
}

void ProfileVisitor::endVisit( const EscapeHtmlUriIterator& ) {
}
// </EscapeHtmlUriIterator>


// <ContainsIterator>
void ProfileVisitor::beginVisit( const ContainsIterator& a) {
}

void ProfileVisitor::endVisit( const ContainsIterator& ) {
}
// </ContainsIterator>


// <StartsWithIterator>
void ProfileVisitor::beginVisit( const StartsWithIterator& a) {
}

void ProfileVisitor::endVisit( const StartsWithIterator& ) {
}
// </StartsWithIterator>


// <EndsWithIterator>
void ProfileVisitor::beginVisit( const EndsWithIterator& a) {
}

void ProfileVisitor::endVisit( const EndsWithIterator& ) {
}
// </EndsWithIterator>


// <SubstringBeforeIterator>
void ProfileVisitor::beginVisit( const SubstringBeforeIterator& a) {
}

void ProfileVisitor::endVisit( const SubstringBeforeIterator& ) {
}
// </SubstringBeforeIterator>


// <SubstringAfterIterator>
void ProfileVisitor::beginVisit( const SubstringAfterIterator& a) {
}

void ProfileVisitor::endVisit( const SubstringAfterIterator& ) {
}
// </SubstringAfterIterator>


// <FnMatchesIterator>
void ProfileVisitor::beginVisit( const FnMatchesIterator& a) {
}

void ProfileVisitor::endVisit( const FnMatchesIterator& ) {
}
// </FnMatchesIterator>


// <FnReplaceIterator>
void ProfileVisitor::beginVisit( const FnReplaceIterator& a) {
}

void ProfileVisitor::endVisit( const FnReplaceIterator& ) {
}
// </FnReplaceIterator>


// <FnTokenizeIterator>
void ProfileVisitor::beginVisit( const FnTokenizeIterator& a) {
}

void ProfileVisitor::endVisit( const FnTokenizeIterator& ) {
}
// </FnTokenizeIterator>


// <FnAnalyzeStringIterator>
void ProfileVisitor::beginVisit( const FnAnalyzeStringIterator& a) {
}

void ProfileVisitor::endVisit( const FnAnalyzeStringIterator& ) {
}
// </FnAnalyzeStringIterator>


// <StringAnalyzeStringIterator>
void ProfileVisitor::beginVisit( const StringAnalyzeStringIterator& a) {
}

void ProfileVisitor::endVisit( const StringAnalyzeStringIterator& ) {
}
// </StringAnalyzeStringIterator>


// <StringMaterializeIterator>
void ProfileVisitor::beginVisit( const StringMaterializeIterator& a) {
}

void ProfileVisitor::endVisit( const StringMaterializeIterator& ) {
}
// </StringMaterializeIterator>


// <StringIsStreamableIterator>
void ProfileVisitor::beginVisit( const StringIsStreamableIterator& a) {
}

void ProfileVisitor::endVisit( const StringIsStreamableIterator& ) {
}
// </StringIsStreamableIterator>


// <StringIsSeekableIterator>
void ProfileVisitor::beginVisit( const StringIsSeekableIterator& a) {
}

void ProfileVisitor::endVisit( const StringIsSeekableIterator& ) {
}
// </StringIsSeekableIterator>


// <StringSplitIterator>
void ProfileVisitor::beginVisit( const StringSplitIterator& a) {
}

void ProfileVisitor::endVisit( const StringSplitIterator& ) {
}
// </StringSplitIterator>


// <DecodeURIIterator>
void ProfileVisitor::beginVisit( const DecodeURIIterator& a) {
}

void ProfileVisitor::endVisit( const DecodeURIIterator& ) {
}
// </DecodeURIIterator>


// <ParseURIIterator>
void ProfileVisitor::beginVisit( const ParseURIIterator& a) {
}

void ProfileVisitor::endVisit( const ParseURIIterator& ) {
}
// </ParseURIIterator>


// <SerializeURIIterator>
void ProfileVisitor::beginVisit( const SerializeURIIterator& a) {
}

void ProfileVisitor::endVisit( const SerializeURIIterator& ) {
}
// </SerializeURIIterator>


// <XQDocContentIterator>
void ProfileVisitor::beginVisit( const XQDocContentIterator& a) {
}

void ProfileVisitor::endVisit( const XQDocContentIterator& ) {
}
// </XQDocContentIterator>

} // namespace zorba
