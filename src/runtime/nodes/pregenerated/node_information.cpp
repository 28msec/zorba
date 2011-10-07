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
#include "runtime/nodes/node_information.h"
#include "system/globalenv.h"



namespace zorba {

// <NodeInformationIterator>
const char* NodeInformationIterator::class_name_str = "NodeInformationIterator";
NodeInformationIterator::class_factory<NodeInformationIterator>
NodeInformationIterator::g_class_factory;

const serialization::ClassVersion 
NodeInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NodeInformationIterator::class_versions_count =
sizeof(NodeInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NodeInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodeInformationIterator::~NodeInformationIterator() {}

// </NodeInformationIterator>


// <IsAncestorInformationIterator>
const char* IsAncestorInformationIterator::class_name_str = "IsAncestorInformationIterator";
IsAncestorInformationIterator::class_factory<IsAncestorInformationIterator>
IsAncestorInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsAncestorInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAncestorInformationIterator::class_versions_count =
sizeof(IsAncestorInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAncestorInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAncestorInformationIterator::~IsAncestorInformationIterator() {}

// </IsAncestorInformationIterator>


// <IsFollowingSiblingInformationIterator>
const char* IsFollowingSiblingInformationIterator::class_name_str = "IsFollowingSiblingInformationIterator";
IsFollowingSiblingInformationIterator::class_factory<IsFollowingSiblingInformationIterator>
IsFollowingSiblingInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingSiblingInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingSiblingInformationIterator::class_versions_count =
sizeof(IsFollowingSiblingInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingSiblingInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingSiblingInformationIterator::~IsFollowingSiblingInformationIterator() {}

// </IsFollowingSiblingInformationIterator>


// <IsFollowingInformationIterator>
const char* IsFollowingInformationIterator::class_name_str = "IsFollowingInformationIterator";
IsFollowingInformationIterator::class_factory<IsFollowingInformationIterator>
IsFollowingInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingInformationIterator::class_versions_count =
sizeof(IsFollowingInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingInformationIterator::~IsFollowingInformationIterator() {}

// </IsFollowingInformationIterator>


// <IsDescendantInformationIterator>
const char* IsDescendantInformationIterator::class_name_str = "IsDescendantInformationIterator";
IsDescendantInformationIterator::class_factory<IsDescendantInformationIterator>
IsDescendantInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsDescendantInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsDescendantInformationIterator::class_versions_count =
sizeof(IsDescendantInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsDescendantInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDescendantInformationIterator::~IsDescendantInformationIterator() {}

// </IsDescendantInformationIterator>


// <IsPrecedingSiblingInformationIterator>
const char* IsPrecedingSiblingInformationIterator::class_name_str = "IsPrecedingSiblingInformationIterator";
IsPrecedingSiblingInformationIterator::class_factory<IsPrecedingSiblingInformationIterator>
IsPrecedingSiblingInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingSiblingInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingSiblingInformationIterator::class_versions_count =
sizeof(IsPrecedingSiblingInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingSiblingInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingSiblingInformationIterator::~IsPrecedingSiblingInformationIterator() {}

// </IsPrecedingSiblingInformationIterator>


// <IsPrecedingInformationIterator>
const char* IsPrecedingInformationIterator::class_name_str = "IsPrecedingInformationIterator";
IsPrecedingInformationIterator::class_factory<IsPrecedingInformationIterator>
IsPrecedingInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingInformationIterator::class_versions_count =
sizeof(IsPrecedingInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingInformationIterator::~IsPrecedingInformationIterator() {}

// </IsPrecedingInformationIterator>


// <IsChildInformationIterator>
const char* IsChildInformationIterator::class_name_str = "IsChildInformationIterator";
IsChildInformationIterator::class_factory<IsChildInformationIterator>
IsChildInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsChildInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsChildInformationIterator::class_versions_count =
sizeof(IsChildInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsChildInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsChildInformationIterator::~IsChildInformationIterator() {}

// </IsChildInformationIterator>


// <IsAttributeOfInformationIterator>
const char* IsAttributeOfInformationIterator::class_name_str = "IsAttributeOfInformationIterator";
IsAttributeOfInformationIterator::class_factory<IsAttributeOfInformationIterator>
IsAttributeOfInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsAttributeOfInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAttributeOfInformationIterator::class_versions_count =
sizeof(IsAttributeOfInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAttributeOfInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAttributeOfInformationIterator::~IsAttributeOfInformationIterator() {}

// </IsAttributeOfInformationIterator>


// <IsParentInformationIterator>
const char* IsParentInformationIterator::class_name_str = "IsParentInformationIterator";
IsParentInformationIterator::class_factory<IsParentInformationIterator>
IsParentInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsParentInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsParentInformationIterator::class_versions_count =
sizeof(IsParentInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsParentInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsParentInformationIterator::~IsParentInformationIterator() {}

// </IsParentInformationIterator>


// <IsPrecedingInDocumentOrderInformationIterator>
const char* IsPrecedingInDocumentOrderInformationIterator::class_name_str = "IsPrecedingInDocumentOrderInformationIterator";
IsPrecedingInDocumentOrderInformationIterator::class_factory<IsPrecedingInDocumentOrderInformationIterator>
IsPrecedingInDocumentOrderInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingInDocumentOrderInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingInDocumentOrderInformationIterator::class_versions_count =
sizeof(IsPrecedingInDocumentOrderInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingInDocumentOrderInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingInDocumentOrderInformationIterator::~IsPrecedingInDocumentOrderInformationIterator() {}

// </IsPrecedingInDocumentOrderInformationIterator>


// <IsFollowingInDocumentOrderInformationIterator>
const char* IsFollowingInDocumentOrderInformationIterator::class_name_str = "IsFollowingInDocumentOrderInformationIterator";
IsFollowingInDocumentOrderInformationIterator::class_factory<IsFollowingInDocumentOrderInformationIterator>
IsFollowingInDocumentOrderInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingInDocumentOrderInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingInDocumentOrderInformationIterator::class_versions_count =
sizeof(IsFollowingInDocumentOrderInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingInDocumentOrderInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingInDocumentOrderInformationIterator::~IsFollowingInDocumentOrderInformationIterator() {}

// </IsFollowingInDocumentOrderInformationIterator>


// <LevelInformationIterator>
const char* LevelInformationIterator::class_name_str = "LevelInformationIterator";
LevelInformationIterator::class_factory<LevelInformationIterator>
LevelInformationIterator::g_class_factory;

const serialization::ClassVersion 
LevelInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int LevelInformationIterator::class_versions_count =
sizeof(LevelInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void LevelInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LevelInformationIterator::~LevelInformationIterator() {}

// </LevelInformationIterator>


// <IsAttributeInformationIterator>
const char* IsAttributeInformationIterator::class_name_str = "IsAttributeInformationIterator";
IsAttributeInformationIterator::class_factory<IsAttributeInformationIterator>
IsAttributeInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsAttributeInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAttributeInformationIterator::class_versions_count =
sizeof(IsAttributeInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAttributeInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAttributeInformationIterator::~IsAttributeInformationIterator() {}

// </IsAttributeInformationIterator>


// <IsCommentInformationIterator>
const char* IsCommentInformationIterator::class_name_str = "IsCommentInformationIterator";
IsCommentInformationIterator::class_factory<IsCommentInformationIterator>
IsCommentInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsCommentInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsCommentInformationIterator::class_versions_count =
sizeof(IsCommentInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsCommentInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsCommentInformationIterator::~IsCommentInformationIterator() {}

// </IsCommentInformationIterator>


// <IsDocumentInformationIterator>
const char* IsDocumentInformationIterator::class_name_str = "IsDocumentInformationIterator";
IsDocumentInformationIterator::class_factory<IsDocumentInformationIterator>
IsDocumentInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsDocumentInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsDocumentInformationIterator::class_versions_count =
sizeof(IsDocumentInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsDocumentInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDocumentInformationIterator::~IsDocumentInformationIterator() {}

// </IsDocumentInformationIterator>


// <IsElementInformationIterator>
const char* IsElementInformationIterator::class_name_str = "IsElementInformationIterator";
IsElementInformationIterator::class_factory<IsElementInformationIterator>
IsElementInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsElementInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsElementInformationIterator::class_versions_count =
sizeof(IsElementInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsElementInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsElementInformationIterator::~IsElementInformationIterator() {}

// </IsElementInformationIterator>


// <IsProcessingInstructionInformationIterator>
const char* IsProcessingInstructionInformationIterator::class_name_str = "IsProcessingInstructionInformationIterator";
IsProcessingInstructionInformationIterator::class_factory<IsProcessingInstructionInformationIterator>
IsProcessingInstructionInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsProcessingInstructionInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsProcessingInstructionInformationIterator::class_versions_count =
sizeof(IsProcessingInstructionInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsProcessingInstructionInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsProcessingInstructionInformationIterator::~IsProcessingInstructionInformationIterator() {}

// </IsProcessingInstructionInformationIterator>


// <IsTextInformationIterator>
const char* IsTextInformationIterator::class_name_str = "IsTextInformationIterator";
IsTextInformationIterator::class_factory<IsTextInformationIterator>
IsTextInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsTextInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsTextInformationIterator::class_versions_count =
sizeof(IsTextInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsTextInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsTextInformationIterator::~IsTextInformationIterator() {}

// </IsTextInformationIterator>


// <IsSiblingInformationIterator>
const char* IsSiblingInformationIterator::class_name_str = "IsSiblingInformationIterator";
IsSiblingInformationIterator::class_factory<IsSiblingInformationIterator>
IsSiblingInformationIterator::g_class_factory;

const serialization::ClassVersion 
IsSiblingInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsSiblingInformationIterator::class_versions_count =
sizeof(IsSiblingInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsSiblingInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsSiblingInformationIterator::~IsSiblingInformationIterator() {}

// </IsSiblingInformationIterator>


// <InSameTreeInformationIterator>
const char* InSameTreeInformationIterator::class_name_str = "InSameTreeInformationIterator";
InSameTreeInformationIterator::class_factory<InSameTreeInformationIterator>
InSameTreeInformationIterator::g_class_factory;

const serialization::ClassVersion 
InSameTreeInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InSameTreeInformationIterator::class_versions_count =
sizeof(InSameTreeInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InSameTreeInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InSameTreeInformationIterator::~InSameTreeInformationIterator() {}

// </InSameTreeInformationIterator>


// <InCollectionInformationIterator>
const char* InCollectionInformationIterator::class_name_str = "InCollectionInformationIterator";
InCollectionInformationIterator::class_factory<InCollectionInformationIterator>
InCollectionInformationIterator::g_class_factory;

const serialization::ClassVersion 
InCollectionInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InCollectionInformationIterator::class_versions_count =
sizeof(InCollectionInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InCollectionInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InCollectionInformationIterator::~InCollectionInformationIterator() {}

// </InCollectionInformationIterator>


// <InSameCollectionInformationIterator>
const char* InSameCollectionInformationIterator::class_name_str = "InSameCollectionInformationIterator";
InSameCollectionInformationIterator::class_factory<InSameCollectionInformationIterator>
InSameCollectionInformationIterator::g_class_factory;

const serialization::ClassVersion 
InSameCollectionInformationIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InSameCollectionInformationIterator::class_versions_count =
sizeof(InSameCollectionInformationIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InSameCollectionInformationIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InSameCollectionInformationIterator::~InSameCollectionInformationIterator() {}

// </InSameCollectionInformationIterator>



}


