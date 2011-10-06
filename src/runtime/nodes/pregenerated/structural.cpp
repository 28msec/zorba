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
#include "runtime/nodes/structural.h"
#include "system/globalenv.h"



namespace zorba {

// <NodeStructuralInformationIterator>
const char* NodeStructuralInformationIterator::class_name_str = "NodeStructuralInformationIterator";
NodeStructuralInformationIterator::class_factory<NodeStructuralInformationIterator>
NodeStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
NodeStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NodeStructuralInformationIterator::class_versions_count =
sizeof(NodeStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NodeStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodeStructuralInformationIterator::~NodeStructuralInformationIterator() {}

// </NodeStructuralInformationIterator>


// <IsAncestorStructuralInformationIterator>
const char* IsAncestorStructuralInformationIterator::class_name_str = "IsAncestorStructuralInformationIterator";
IsAncestorStructuralInformationIterator::class_factory<IsAncestorStructuralInformationIterator>
IsAncestorStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsAncestorStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAncestorStructuralInformationIterator::class_versions_count =
sizeof(IsAncestorStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAncestorStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAncestorStructuralInformationIterator::~IsAncestorStructuralInformationIterator() {}

// </IsAncestorStructuralInformationIterator>


// <IsFollowingSiblingStructuralInformationIterator>
const char* IsFollowingSiblingStructuralInformationIterator::class_name_str = "IsFollowingSiblingStructuralInformationIterator";
IsFollowingSiblingStructuralInformationIterator::class_factory<IsFollowingSiblingStructuralInformationIterator>
IsFollowingSiblingStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingSiblingStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingSiblingStructuralInformationIterator::class_versions_count =
sizeof(IsFollowingSiblingStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingSiblingStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingSiblingStructuralInformationIterator::~IsFollowingSiblingStructuralInformationIterator() {}

// </IsFollowingSiblingStructuralInformationIterator>


// <IsFollowingStructuralInformationIterator>
const char* IsFollowingStructuralInformationIterator::class_name_str = "IsFollowingStructuralInformationIterator";
IsFollowingStructuralInformationIterator::class_factory<IsFollowingStructuralInformationIterator>
IsFollowingStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingStructuralInformationIterator::class_versions_count =
sizeof(IsFollowingStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingStructuralInformationIterator::~IsFollowingStructuralInformationIterator() {}

// </IsFollowingStructuralInformationIterator>


// <IsDescendantStructuralInformationIterator>
const char* IsDescendantStructuralInformationIterator::class_name_str = "IsDescendantStructuralInformationIterator";
IsDescendantStructuralInformationIterator::class_factory<IsDescendantStructuralInformationIterator>
IsDescendantStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsDescendantStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsDescendantStructuralInformationIterator::class_versions_count =
sizeof(IsDescendantStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsDescendantStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDescendantStructuralInformationIterator::~IsDescendantStructuralInformationIterator() {}

// </IsDescendantStructuralInformationIterator>


// <IsPrecedingSiblingStructuralInformationIterator>
const char* IsPrecedingSiblingStructuralInformationIterator::class_name_str = "IsPrecedingSiblingStructuralInformationIterator";
IsPrecedingSiblingStructuralInformationIterator::class_factory<IsPrecedingSiblingStructuralInformationIterator>
IsPrecedingSiblingStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingSiblingStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingSiblingStructuralInformationIterator::class_versions_count =
sizeof(IsPrecedingSiblingStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingSiblingStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingSiblingStructuralInformationIterator::~IsPrecedingSiblingStructuralInformationIterator() {}

// </IsPrecedingSiblingStructuralInformationIterator>


// <IsPrecedingStructuralInformationIterator>
const char* IsPrecedingStructuralInformationIterator::class_name_str = "IsPrecedingStructuralInformationIterator";
IsPrecedingStructuralInformationIterator::class_factory<IsPrecedingStructuralInformationIterator>
IsPrecedingStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingStructuralInformationIterator::class_versions_count =
sizeof(IsPrecedingStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingStructuralInformationIterator::~IsPrecedingStructuralInformationIterator() {}

// </IsPrecedingStructuralInformationIterator>


// <IsChildStructuralInformationIterator>
const char* IsChildStructuralInformationIterator::class_name_str = "IsChildStructuralInformationIterator";
IsChildStructuralInformationIterator::class_factory<IsChildStructuralInformationIterator>
IsChildStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsChildStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsChildStructuralInformationIterator::class_versions_count =
sizeof(IsChildStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsChildStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsChildStructuralInformationIterator::~IsChildStructuralInformationIterator() {}

// </IsChildStructuralInformationIterator>


// <IsAttributeOfStructuralInformationIterator>
const char* IsAttributeOfStructuralInformationIterator::class_name_str = "IsAttributeOfStructuralInformationIterator";
IsAttributeOfStructuralInformationIterator::class_factory<IsAttributeOfStructuralInformationIterator>
IsAttributeOfStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsAttributeOfStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAttributeOfStructuralInformationIterator::class_versions_count =
sizeof(IsAttributeOfStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAttributeOfStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAttributeOfStructuralInformationIterator::~IsAttributeOfStructuralInformationIterator() {}

// </IsAttributeOfStructuralInformationIterator>


// <IsParentStructuralInformationIterator>
const char* IsParentStructuralInformationIterator::class_name_str = "IsParentStructuralInformationIterator";
IsParentStructuralInformationIterator::class_factory<IsParentStructuralInformationIterator>
IsParentStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsParentStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsParentStructuralInformationIterator::class_versions_count =
sizeof(IsParentStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsParentStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsParentStructuralInformationIterator::~IsParentStructuralInformationIterator() {}

// </IsParentStructuralInformationIterator>


// <IsPrecedingInDocumentOrderStructuralInformationIterator>
const char* IsPrecedingInDocumentOrderStructuralInformationIterator::class_name_str = "IsPrecedingInDocumentOrderStructuralInformationIterator";
IsPrecedingInDocumentOrderStructuralInformationIterator::class_factory<IsPrecedingInDocumentOrderStructuralInformationIterator>
IsPrecedingInDocumentOrderStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingInDocumentOrderStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingInDocumentOrderStructuralInformationIterator::class_versions_count =
sizeof(IsPrecedingInDocumentOrderStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingInDocumentOrderStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingInDocumentOrderStructuralInformationIterator::~IsPrecedingInDocumentOrderStructuralInformationIterator() {}

// </IsPrecedingInDocumentOrderStructuralInformationIterator>


// <IsFollowingInDocumentOrderStructuralInformationIterator>
const char* IsFollowingInDocumentOrderStructuralInformationIterator::class_name_str = "IsFollowingInDocumentOrderStructuralInformationIterator";
IsFollowingInDocumentOrderStructuralInformationIterator::class_factory<IsFollowingInDocumentOrderStructuralInformationIterator>
IsFollowingInDocumentOrderStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingInDocumentOrderStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingInDocumentOrderStructuralInformationIterator::class_versions_count =
sizeof(IsFollowingInDocumentOrderStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingInDocumentOrderStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingInDocumentOrderStructuralInformationIterator::~IsFollowingInDocumentOrderStructuralInformationIterator() {}

// </IsFollowingInDocumentOrderStructuralInformationIterator>


// <LevelStructuralInformationIterator>
const char* LevelStructuralInformationIterator::class_name_str = "LevelStructuralInformationIterator";
LevelStructuralInformationIterator::class_factory<LevelStructuralInformationIterator>
LevelStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
LevelStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int LevelStructuralInformationIterator::class_versions_count =
sizeof(LevelStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void LevelStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LevelStructuralInformationIterator::~LevelStructuralInformationIterator() {}

// </LevelStructuralInformationIterator>


// <IsAttributeStructuralInformationIterator>
const char* IsAttributeStructuralInformationIterator::class_name_str = "IsAttributeStructuralInformationIterator";
IsAttributeStructuralInformationIterator::class_factory<IsAttributeStructuralInformationIterator>
IsAttributeStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsAttributeStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAttributeStructuralInformationIterator::class_versions_count =
sizeof(IsAttributeStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAttributeStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAttributeStructuralInformationIterator::~IsAttributeStructuralInformationIterator() {}

// </IsAttributeStructuralInformationIterator>


// <IsCommentStructuralInformationIterator>
const char* IsCommentStructuralInformationIterator::class_name_str = "IsCommentStructuralInformationIterator";
IsCommentStructuralInformationIterator::class_factory<IsCommentStructuralInformationIterator>
IsCommentStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsCommentStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsCommentStructuralInformationIterator::class_versions_count =
sizeof(IsCommentStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsCommentStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsCommentStructuralInformationIterator::~IsCommentStructuralInformationIterator() {}

// </IsCommentStructuralInformationIterator>


// <IsDocumentStructuralInformationIterator>
const char* IsDocumentStructuralInformationIterator::class_name_str = "IsDocumentStructuralInformationIterator";
IsDocumentStructuralInformationIterator::class_factory<IsDocumentStructuralInformationIterator>
IsDocumentStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsDocumentStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsDocumentStructuralInformationIterator::class_versions_count =
sizeof(IsDocumentStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsDocumentStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDocumentStructuralInformationIterator::~IsDocumentStructuralInformationIterator() {}

// </IsDocumentStructuralInformationIterator>


// <IsElementStructuralInformationIterator>
const char* IsElementStructuralInformationIterator::class_name_str = "IsElementStructuralInformationIterator";
IsElementStructuralInformationIterator::class_factory<IsElementStructuralInformationIterator>
IsElementStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsElementStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsElementStructuralInformationIterator::class_versions_count =
sizeof(IsElementStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsElementStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsElementStructuralInformationIterator::~IsElementStructuralInformationIterator() {}

// </IsElementStructuralInformationIterator>


// <IsProcessingInstructionStructuralInformationIterator>
const char* IsProcessingInstructionStructuralInformationIterator::class_name_str = "IsProcessingInstructionStructuralInformationIterator";
IsProcessingInstructionStructuralInformationIterator::class_factory<IsProcessingInstructionStructuralInformationIterator>
IsProcessingInstructionStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsProcessingInstructionStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsProcessingInstructionStructuralInformationIterator::class_versions_count =
sizeof(IsProcessingInstructionStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsProcessingInstructionStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsProcessingInstructionStructuralInformationIterator::~IsProcessingInstructionStructuralInformationIterator() {}

// </IsProcessingInstructionStructuralInformationIterator>


// <IsTextStructuralInformationIterator>
const char* IsTextStructuralInformationIterator::class_name_str = "IsTextStructuralInformationIterator";
IsTextStructuralInformationIterator::class_factory<IsTextStructuralInformationIterator>
IsTextStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsTextStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsTextStructuralInformationIterator::class_versions_count =
sizeof(IsTextStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsTextStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsTextStructuralInformationIterator::~IsTextStructuralInformationIterator() {}

// </IsTextStructuralInformationIterator>


// <IsSiblingStructuralInformationIterator>
const char* IsSiblingStructuralInformationIterator::class_name_str = "IsSiblingStructuralInformationIterator";
IsSiblingStructuralInformationIterator::class_factory<IsSiblingStructuralInformationIterator>
IsSiblingStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsSiblingStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsSiblingStructuralInformationIterator::class_versions_count =
sizeof(IsSiblingStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsSiblingStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsSiblingStructuralInformationIterator::~IsSiblingStructuralInformationIterator() {}

// </IsSiblingStructuralInformationIterator>


// <InSameTreeStructuralInformationIterator>
const char* InSameTreeStructuralInformationIterator::class_name_str = "InSameTreeStructuralInformationIterator";
InSameTreeStructuralInformationIterator::class_factory<InSameTreeStructuralInformationIterator>
InSameTreeStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
InSameTreeStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InSameTreeStructuralInformationIterator::class_versions_count =
sizeof(InSameTreeStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InSameTreeStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InSameTreeStructuralInformationIterator::~InSameTreeStructuralInformationIterator() {}

// </InSameTreeStructuralInformationIterator>


// <InCollectionStructuralInformationIterator>
const char* InCollectionStructuralInformationIterator::class_name_str = "InCollectionStructuralInformationIterator";
InCollectionStructuralInformationIterator::class_factory<InCollectionStructuralInformationIterator>
InCollectionStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
InCollectionStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InCollectionStructuralInformationIterator::class_versions_count =
sizeof(InCollectionStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InCollectionStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InCollectionStructuralInformationIterator::~InCollectionStructuralInformationIterator() {}

// </InCollectionStructuralInformationIterator>


// <InSameCollectionStructuralInformationIterator>
const char* InSameCollectionStructuralInformationIterator::class_name_str = "InSameCollectionStructuralInformationIterator";
InSameCollectionStructuralInformationIterator::class_factory<InSameCollectionStructuralInformationIterator>
InSameCollectionStructuralInformationIterator::g_class_factory;

const serialization::ClassVersion 
InSameCollectionStructuralInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InSameCollectionStructuralInformationIterator::class_versions_count =
sizeof(InSameCollectionStructuralInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InSameCollectionStructuralInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InSameCollectionStructuralInformationIterator::~InSameCollectionStructuralInformationIterator() {}

// </InSameCollectionStructuralInformationIterator>



}


