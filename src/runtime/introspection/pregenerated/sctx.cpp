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
SERIALIZABLE_CLASS_VERSIONS(StaticNamespacesIterator)

void StaticNamespacesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StaticNamespacesIterator, StaticNamespacesIteratorState>*)this);
}


void StaticNamespacesIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(DefaultFunctionNamespaceIterator)

void DefaultFunctionNamespaceIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DefaultFunctionNamespaceIterator, PlanIteratorState>*)this);
}


void DefaultFunctionNamespaceIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(SctxBaseUriIterator)

void SctxBaseUriIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SctxBaseUriIterator, PlanIteratorState>*)this);
}


void SctxBaseUriIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(SctxDefaultCollationIterator)

void SctxDefaultCollationIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SctxDefaultCollationIterator, PlanIteratorState>*)this);
}


void SctxDefaultCollationIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(StaticNamespaceBindingIterator)

void StaticNamespaceBindingIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StaticNamespaceBindingIterator, PlanIteratorState>*)this);
}


void StaticNamespaceBindingIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(InscopeVariablesIterator)

void InscopeVariablesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<InscopeVariablesIterator, InscopeVariablesIteratorState>*)this);
}


void InscopeVariablesIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(DefaultCollectionTypeIterator)

void DefaultCollectionTypeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DefaultCollectionTypeIterator, PlanIteratorState>*)this);
}


void DefaultCollectionTypeIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(XPath10CompatModeIterator)

void XPath10CompatModeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<XPath10CompatModeIterator, PlanIteratorState>*)this);
}


void XPath10CompatModeIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(StaticallyKnownDocumentsIterator)

void StaticallyKnownDocumentsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StaticallyKnownDocumentsIterator, StaticallyKnownDocumentsIteratorState>*)this);
}


void StaticallyKnownDocumentsIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(StaticallyKnownDocumentTypeIterator)

void StaticallyKnownDocumentTypeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StaticallyKnownDocumentTypeIterator, PlanIteratorState>*)this);
}


void StaticallyKnownDocumentTypeIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(StaticallyKnownCollationsIterator)

void StaticallyKnownCollationsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<StaticallyKnownCollationsIterator, StaticallyKnownCollationsIteratorState>*)this);
}


void StaticallyKnownCollationsIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(ConstructionModeIterator)

void ConstructionModeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ConstructionModeIterator, PlanIteratorState>*)this);
}


void ConstructionModeIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(OrderingModeIterator)

void OrderingModeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<OrderingModeIterator, PlanIteratorState>*)this);
}


void OrderingModeIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(DefaultOrderIterator)

void DefaultOrderIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<DefaultOrderIterator, PlanIteratorState>*)this);
}


void DefaultOrderIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(BoundarySpacePolicyIterator)

void BoundarySpacePolicyIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<BoundarySpacePolicyIterator, PlanIteratorState>*)this);
}


void BoundarySpacePolicyIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(CopyNamespacesModeIterator)

void CopyNamespacesModeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CopyNamespacesModeIterator, PlanIteratorState>*)this);
}


void CopyNamespacesModeIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(FunctionNamesIterator)

void FunctionNamesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FunctionNamesIterator, FunctionNamesIteratorState>*)this);
}


void FunctionNamesIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(FunctionArgumentsCountIterator)

void FunctionArgumentsCountIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FunctionArgumentsCountIterator, FunctionArgumentsCountIteratorState>*)this);
}


void FunctionArgumentsCountIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(InScopeSchemaTypesIterator)

void InScopeSchemaTypesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<InScopeSchemaTypesIterator, InScopeSchemaTypesIteratorState>*)this);
}


void InScopeSchemaTypesIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(InScopeElementDeclarationsIterator)

void InScopeElementDeclarationsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<InScopeElementDeclarationsIterator, InScopeElementDeclarationsIteratorState>*)this);
}


void InScopeElementDeclarationsIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(InScopeAttributeDeclarationsIterator)

void InScopeAttributeDeclarationsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<InScopeAttributeDeclarationsIterator, InScopeAttributeDeclarationsIteratorState>*)this);
}


void InScopeAttributeDeclarationsIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(InScopeElementGroupsIterator)

void InScopeElementGroupsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<InScopeElementGroupsIterator, InScopeElementGroupsIteratorState>*)this);
}


void InScopeElementGroupsIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(InScopeAttributeGroupsIterator)

void InScopeAttributeGroupsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<InScopeAttributeGroupsIterator, InScopeAttributeGroupsIteratorState>*)this);
}


void InScopeAttributeGroupsIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(OptionIterator)

void OptionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<OptionIterator, PlanIteratorState>*)this);
}


void OptionIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(FunctionAnnotationsIterator)

void FunctionAnnotationsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FunctionAnnotationsIterator, FunctionAnnotationsIteratorState>*)this);
}


void FunctionAnnotationsIterator::accept(PlanIterVisitor& v) const
{
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


