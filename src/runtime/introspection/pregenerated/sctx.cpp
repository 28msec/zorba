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
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/introspection/sctx.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"
#include "compiler/expression/var_expr.h"

namespace zorba {

// <StaticNamespacesIterator>
const char* StaticNamespacesIterator::class_name_str = "StaticNamespacesIterator";
StaticNamespacesIterator::class_factory<StaticNamespacesIterator>
StaticNamespacesIterator::g_class_factory;

const serialization::ClassVersion 
StaticNamespacesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StaticNamespacesIterator::class_versions_count =
sizeof(StaticNamespacesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StaticNamespacesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StaticNamespacesIterator::~StaticNamespacesIterator() {}

StaticNamespacesIteratorState::StaticNamespacesIteratorState() {}


void StaticNamespacesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </StaticNamespacesIterator>


// <DefaultFunctionNamespaceIterator>
const char* DefaultFunctionNamespaceIterator::class_name_str = "DefaultFunctionNamespaceIterator";
DefaultFunctionNamespaceIterator::class_factory<DefaultFunctionNamespaceIterator>
DefaultFunctionNamespaceIterator::g_class_factory;

const serialization::ClassVersion 
DefaultFunctionNamespaceIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DefaultFunctionNamespaceIterator::class_versions_count =
sizeof(DefaultFunctionNamespaceIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void DefaultFunctionNamespaceIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DefaultFunctionNamespaceIterator::~DefaultFunctionNamespaceIterator() {}

// </DefaultFunctionNamespaceIterator>


// <SctxBaseUriIterator>
const char* SctxBaseUriIterator::class_name_str = "SctxBaseUriIterator";
SctxBaseUriIterator::class_factory<SctxBaseUriIterator>
SctxBaseUriIterator::g_class_factory;

const serialization::ClassVersion 
SctxBaseUriIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SctxBaseUriIterator::class_versions_count =
sizeof(SctxBaseUriIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SctxBaseUriIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SctxBaseUriIterator::~SctxBaseUriIterator() {}

// </SctxBaseUriIterator>


// <SctxDefaultCollationIterator>
const char* SctxDefaultCollationIterator::class_name_str = "SctxDefaultCollationIterator";
SctxDefaultCollationIterator::class_factory<SctxDefaultCollationIterator>
SctxDefaultCollationIterator::g_class_factory;

const serialization::ClassVersion 
SctxDefaultCollationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SctxDefaultCollationIterator::class_versions_count =
sizeof(SctxDefaultCollationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SctxDefaultCollationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SctxDefaultCollationIterator::~SctxDefaultCollationIterator() {}

// </SctxDefaultCollationIterator>


// <StaticNamespaceBindingIterator>
const char* StaticNamespaceBindingIterator::class_name_str = "StaticNamespaceBindingIterator";
StaticNamespaceBindingIterator::class_factory<StaticNamespaceBindingIterator>
StaticNamespaceBindingIterator::g_class_factory;

const serialization::ClassVersion 
StaticNamespaceBindingIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StaticNamespaceBindingIterator::class_versions_count =
sizeof(StaticNamespaceBindingIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StaticNamespaceBindingIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StaticNamespaceBindingIterator::~StaticNamespaceBindingIterator() {}

// </StaticNamespaceBindingIterator>


// <InscopeVariablesIterator>
const char* InscopeVariablesIterator::class_name_str = "InscopeVariablesIterator";
InscopeVariablesIterator::class_factory<InscopeVariablesIterator>
InscopeVariablesIterator::g_class_factory;

const serialization::ClassVersion 
InscopeVariablesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InscopeVariablesIterator::class_versions_count =
sizeof(InscopeVariablesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InscopeVariablesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InscopeVariablesIterator::~InscopeVariablesIterator() {}

InscopeVariablesIteratorState::InscopeVariablesIteratorState() {}


void InscopeVariablesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </InscopeVariablesIterator>


// <DefaultCollectionTypeIterator>
const char* DefaultCollectionTypeIterator::class_name_str = "DefaultCollectionTypeIterator";
DefaultCollectionTypeIterator::class_factory<DefaultCollectionTypeIterator>
DefaultCollectionTypeIterator::g_class_factory;

const serialization::ClassVersion 
DefaultCollectionTypeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DefaultCollectionTypeIterator::class_versions_count =
sizeof(DefaultCollectionTypeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void DefaultCollectionTypeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DefaultCollectionTypeIterator::~DefaultCollectionTypeIterator() {}

// </DefaultCollectionTypeIterator>


// <XPath10CompatModeIterator>
const char* XPath10CompatModeIterator::class_name_str = "XPath10CompatModeIterator";
XPath10CompatModeIterator::class_factory<XPath10CompatModeIterator>
XPath10CompatModeIterator::g_class_factory;

const serialization::ClassVersion 
XPath10CompatModeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int XPath10CompatModeIterator::class_versions_count =
sizeof(XPath10CompatModeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void XPath10CompatModeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

XPath10CompatModeIterator::~XPath10CompatModeIterator() {}

// </XPath10CompatModeIterator>


// <StaticallyKnownDocumentsIterator>
const char* StaticallyKnownDocumentsIterator::class_name_str = "StaticallyKnownDocumentsIterator";
StaticallyKnownDocumentsIterator::class_factory<StaticallyKnownDocumentsIterator>
StaticallyKnownDocumentsIterator::g_class_factory;

const serialization::ClassVersion 
StaticallyKnownDocumentsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StaticallyKnownDocumentsIterator::class_versions_count =
sizeof(StaticallyKnownDocumentsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StaticallyKnownDocumentsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StaticallyKnownDocumentsIterator::~StaticallyKnownDocumentsIterator() {}

StaticallyKnownDocumentsIteratorState::StaticallyKnownDocumentsIteratorState() {}


void StaticallyKnownDocumentsIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </StaticallyKnownDocumentsIterator>


// <StaticallyKnownDocumentTypeIterator>
const char* StaticallyKnownDocumentTypeIterator::class_name_str = "StaticallyKnownDocumentTypeIterator";
StaticallyKnownDocumentTypeIterator::class_factory<StaticallyKnownDocumentTypeIterator>
StaticallyKnownDocumentTypeIterator::g_class_factory;

const serialization::ClassVersion 
StaticallyKnownDocumentTypeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StaticallyKnownDocumentTypeIterator::class_versions_count =
sizeof(StaticallyKnownDocumentTypeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StaticallyKnownDocumentTypeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StaticallyKnownDocumentTypeIterator::~StaticallyKnownDocumentTypeIterator() {}

// </StaticallyKnownDocumentTypeIterator>


// <StaticallyKnownCollationsIterator>
const char* StaticallyKnownCollationsIterator::class_name_str = "StaticallyKnownCollationsIterator";
StaticallyKnownCollationsIterator::class_factory<StaticallyKnownCollationsIterator>
StaticallyKnownCollationsIterator::g_class_factory;

const serialization::ClassVersion 
StaticallyKnownCollationsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int StaticallyKnownCollationsIterator::class_versions_count =
sizeof(StaticallyKnownCollationsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void StaticallyKnownCollationsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

StaticallyKnownCollationsIterator::~StaticallyKnownCollationsIterator() {}

StaticallyKnownCollationsIteratorState::StaticallyKnownCollationsIteratorState() {}


void StaticallyKnownCollationsIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </StaticallyKnownCollationsIterator>


// <ConstructionModeIterator>
const char* ConstructionModeIterator::class_name_str = "ConstructionModeIterator";
ConstructionModeIterator::class_factory<ConstructionModeIterator>
ConstructionModeIterator::g_class_factory;

const serialization::ClassVersion 
ConstructionModeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ConstructionModeIterator::class_versions_count =
sizeof(ConstructionModeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ConstructionModeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

ConstructionModeIterator::~ConstructionModeIterator() {}

// </ConstructionModeIterator>


// <OrderingModeIterator>
const char* OrderingModeIterator::class_name_str = "OrderingModeIterator";
OrderingModeIterator::class_factory<OrderingModeIterator>
OrderingModeIterator::g_class_factory;

const serialization::ClassVersion 
OrderingModeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int OrderingModeIterator::class_versions_count =
sizeof(OrderingModeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void OrderingModeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

OrderingModeIterator::~OrderingModeIterator() {}

// </OrderingModeIterator>


// <DefaultOrderIterator>
const char* DefaultOrderIterator::class_name_str = "DefaultOrderIterator";
DefaultOrderIterator::class_factory<DefaultOrderIterator>
DefaultOrderIterator::g_class_factory;

const serialization::ClassVersion 
DefaultOrderIterator::class_versions[] ={{ 1, 0x000905, false}};

const int DefaultOrderIterator::class_versions_count =
sizeof(DefaultOrderIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void DefaultOrderIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

DefaultOrderIterator::~DefaultOrderIterator() {}

// </DefaultOrderIterator>


// <BoundarySpacePolicyIterator>
const char* BoundarySpacePolicyIterator::class_name_str = "BoundarySpacePolicyIterator";
BoundarySpacePolicyIterator::class_factory<BoundarySpacePolicyIterator>
BoundarySpacePolicyIterator::g_class_factory;

const serialization::ClassVersion 
BoundarySpacePolicyIterator::class_versions[] ={{ 1, 0x000905, false}};

const int BoundarySpacePolicyIterator::class_versions_count =
sizeof(BoundarySpacePolicyIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void BoundarySpacePolicyIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

BoundarySpacePolicyIterator::~BoundarySpacePolicyIterator() {}

// </BoundarySpacePolicyIterator>


// <CopyNamespacesModeIterator>
const char* CopyNamespacesModeIterator::class_name_str = "CopyNamespacesModeIterator";
CopyNamespacesModeIterator::class_factory<CopyNamespacesModeIterator>
CopyNamespacesModeIterator::g_class_factory;

const serialization::ClassVersion 
CopyNamespacesModeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CopyNamespacesModeIterator::class_versions_count =
sizeof(CopyNamespacesModeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CopyNamespacesModeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CopyNamespacesModeIterator::~CopyNamespacesModeIterator() {}

// </CopyNamespacesModeIterator>


// <FunctionNamesIterator>
const char* FunctionNamesIterator::class_name_str = "FunctionNamesIterator";
FunctionNamesIterator::class_factory<FunctionNamesIterator>
FunctionNamesIterator::g_class_factory;

const serialization::ClassVersion 
FunctionNamesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FunctionNamesIterator::class_versions_count =
sizeof(FunctionNamesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FunctionNamesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FunctionNamesIterator::~FunctionNamesIterator() {}

FunctionNamesIteratorState::FunctionNamesIteratorState() {}


void FunctionNamesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </FunctionNamesIterator>


// <FunctionArgumentsCountIterator>
const char* FunctionArgumentsCountIterator::class_name_str = "FunctionArgumentsCountIterator";
FunctionArgumentsCountIterator::class_factory<FunctionArgumentsCountIterator>
FunctionArgumentsCountIterator::g_class_factory;

const serialization::ClassVersion 
FunctionArgumentsCountIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FunctionArgumentsCountIterator::class_versions_count =
sizeof(FunctionArgumentsCountIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FunctionArgumentsCountIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FunctionArgumentsCountIterator::~FunctionArgumentsCountIterator() {}

FunctionArgumentsCountIteratorState::FunctionArgumentsCountIteratorState() {}


void FunctionArgumentsCountIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </FunctionArgumentsCountIterator>


// <InScopeSchemaTypesIterator>
const char* InScopeSchemaTypesIterator::class_name_str = "InScopeSchemaTypesIterator";
InScopeSchemaTypesIterator::class_factory<InScopeSchemaTypesIterator>
InScopeSchemaTypesIterator::g_class_factory;

const serialization::ClassVersion 
InScopeSchemaTypesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InScopeSchemaTypesIterator::class_versions_count =
sizeof(InScopeSchemaTypesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InScopeSchemaTypesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InScopeSchemaTypesIterator::~InScopeSchemaTypesIterator() {}

InScopeSchemaTypesIteratorState::InScopeSchemaTypesIteratorState() {}


void InScopeSchemaTypesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </InScopeSchemaTypesIterator>


// <InScopeElementDeclarationsIterator>
const char* InScopeElementDeclarationsIterator::class_name_str = "InScopeElementDeclarationsIterator";
InScopeElementDeclarationsIterator::class_factory<InScopeElementDeclarationsIterator>
InScopeElementDeclarationsIterator::g_class_factory;

const serialization::ClassVersion 
InScopeElementDeclarationsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InScopeElementDeclarationsIterator::class_versions_count =
sizeof(InScopeElementDeclarationsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InScopeElementDeclarationsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InScopeElementDeclarationsIterator::~InScopeElementDeclarationsIterator() {}

InScopeElementDeclarationsIteratorState::InScopeElementDeclarationsIteratorState() {}


void InScopeElementDeclarationsIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </InScopeElementDeclarationsIterator>


// <InScopeAttributeDeclarationsIterator>
const char* InScopeAttributeDeclarationsIterator::class_name_str = "InScopeAttributeDeclarationsIterator";
InScopeAttributeDeclarationsIterator::class_factory<InScopeAttributeDeclarationsIterator>
InScopeAttributeDeclarationsIterator::g_class_factory;

const serialization::ClassVersion 
InScopeAttributeDeclarationsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InScopeAttributeDeclarationsIterator::class_versions_count =
sizeof(InScopeAttributeDeclarationsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InScopeAttributeDeclarationsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InScopeAttributeDeclarationsIterator::~InScopeAttributeDeclarationsIterator() {}

InScopeAttributeDeclarationsIteratorState::InScopeAttributeDeclarationsIteratorState() {}


void InScopeAttributeDeclarationsIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </InScopeAttributeDeclarationsIterator>


// <InScopeElementGroupsIterator>
const char* InScopeElementGroupsIterator::class_name_str = "InScopeElementGroupsIterator";
InScopeElementGroupsIterator::class_factory<InScopeElementGroupsIterator>
InScopeElementGroupsIterator::g_class_factory;

const serialization::ClassVersion 
InScopeElementGroupsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InScopeElementGroupsIterator::class_versions_count =
sizeof(InScopeElementGroupsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InScopeElementGroupsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InScopeElementGroupsIterator::~InScopeElementGroupsIterator() {}

InScopeElementGroupsIteratorState::InScopeElementGroupsIteratorState() {}


void InScopeElementGroupsIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </InScopeElementGroupsIterator>


// <InScopeAttributeGroupsIterator>
const char* InScopeAttributeGroupsIterator::class_name_str = "InScopeAttributeGroupsIterator";
InScopeAttributeGroupsIterator::class_factory<InScopeAttributeGroupsIterator>
InScopeAttributeGroupsIterator::g_class_factory;

const serialization::ClassVersion 
InScopeAttributeGroupsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InScopeAttributeGroupsIterator::class_versions_count =
sizeof(InScopeAttributeGroupsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InScopeAttributeGroupsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InScopeAttributeGroupsIterator::~InScopeAttributeGroupsIterator() {}

InScopeAttributeGroupsIteratorState::InScopeAttributeGroupsIteratorState() {}


void InScopeAttributeGroupsIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </InScopeAttributeGroupsIterator>


// <OptionIterator>
const char* OptionIterator::class_name_str = "OptionIterator";
OptionIterator::class_factory<OptionIterator>
OptionIterator::g_class_factory;

const serialization::ClassVersion 
OptionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int OptionIterator::class_versions_count =
sizeof(OptionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void OptionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

OptionIterator::~OptionIterator() {}

// </OptionIterator>


// <FunctionAnnotationsIterator>
const char* FunctionAnnotationsIterator::class_name_str = "FunctionAnnotationsIterator";
FunctionAnnotationsIterator::class_factory<FunctionAnnotationsIterator>
FunctionAnnotationsIterator::g_class_factory;

const serialization::ClassVersion 
FunctionAnnotationsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FunctionAnnotationsIterator::class_versions_count =
sizeof(FunctionAnnotationsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FunctionAnnotationsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FunctionAnnotationsIterator::~FunctionAnnotationsIterator() {}

FunctionAnnotationsIteratorState::FunctionAnnotationsIteratorState() {}


void FunctionAnnotationsIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </FunctionAnnotationsIterator>



}


