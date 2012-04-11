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
StaticNamespacesIterator::class_factory<StaticNamespacesIterator>
StaticNamespacesIterator::g_class_factory;


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
DefaultFunctionNamespaceIterator::class_factory<DefaultFunctionNamespaceIterator>
DefaultFunctionNamespaceIterator::g_class_factory;


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
SctxBaseUriIterator::class_factory<SctxBaseUriIterator>
SctxBaseUriIterator::g_class_factory;


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
SctxDefaultCollationIterator::class_factory<SctxDefaultCollationIterator>
SctxDefaultCollationIterator::g_class_factory;


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
StaticNamespaceBindingIterator::class_factory<StaticNamespaceBindingIterator>
StaticNamespaceBindingIterator::g_class_factory;


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
InscopeVariablesIterator::class_factory<InscopeVariablesIterator>
InscopeVariablesIterator::g_class_factory;


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
DefaultCollectionTypeIterator::class_factory<DefaultCollectionTypeIterator>
DefaultCollectionTypeIterator::g_class_factory;


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
XPath10CompatModeIterator::class_factory<XPath10CompatModeIterator>
XPath10CompatModeIterator::g_class_factory;


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
StaticallyKnownDocumentsIterator::class_factory<StaticallyKnownDocumentsIterator>
StaticallyKnownDocumentsIterator::g_class_factory;


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
StaticallyKnownDocumentTypeIterator::class_factory<StaticallyKnownDocumentTypeIterator>
StaticallyKnownDocumentTypeIterator::g_class_factory;


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
StaticallyKnownCollationsIterator::class_factory<StaticallyKnownCollationsIterator>
StaticallyKnownCollationsIterator::g_class_factory;


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
ConstructionModeIterator::class_factory<ConstructionModeIterator>
ConstructionModeIterator::g_class_factory;


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
OrderingModeIterator::class_factory<OrderingModeIterator>
OrderingModeIterator::g_class_factory;


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
DefaultOrderIterator::class_factory<DefaultOrderIterator>
DefaultOrderIterator::g_class_factory;


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
BoundarySpacePolicyIterator::class_factory<BoundarySpacePolicyIterator>
BoundarySpacePolicyIterator::g_class_factory;


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
CopyNamespacesModeIterator::class_factory<CopyNamespacesModeIterator>
CopyNamespacesModeIterator::g_class_factory;


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
FunctionNamesIterator::class_factory<FunctionNamesIterator>
FunctionNamesIterator::g_class_factory;


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
FunctionArgumentsCountIterator::class_factory<FunctionArgumentsCountIterator>
FunctionArgumentsCountIterator::g_class_factory;


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
InScopeSchemaTypesIterator::class_factory<InScopeSchemaTypesIterator>
InScopeSchemaTypesIterator::g_class_factory;


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
InScopeElementDeclarationsIterator::class_factory<InScopeElementDeclarationsIterator>
InScopeElementDeclarationsIterator::g_class_factory;


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
InScopeAttributeDeclarationsIterator::class_factory<InScopeAttributeDeclarationsIterator>
InScopeAttributeDeclarationsIterator::g_class_factory;


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
InScopeElementGroupsIterator::class_factory<InScopeElementGroupsIterator>
InScopeElementGroupsIterator::g_class_factory;


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
InScopeAttributeGroupsIterator::class_factory<InScopeAttributeGroupsIterator>
InScopeAttributeGroupsIterator::g_class_factory;


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
OptionIterator::class_factory<OptionIterator>
OptionIterator::g_class_factory;


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
FunctionAnnotationsIterator::class_factory<FunctionAnnotationsIterator>
FunctionAnnotationsIterator::g_class_factory;


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


