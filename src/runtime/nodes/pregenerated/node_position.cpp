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
#include "runtime/nodes/node_position.h"
#include "system/globalenv.h"



namespace zorba {

// <NodePositionIterator>
const char* NodePositionIterator::class_name_str = "NodePositionIterator";
NodePositionIterator::class_factory<NodePositionIterator>
NodePositionIterator::g_class_factory;

const serialization::ClassVersion 
NodePositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NodePositionIterator::class_versions_count =
sizeof(NodePositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NodePositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

NodePositionIterator::~NodePositionIterator() {}

// </NodePositionIterator>


// <IsAncestorPositionIterator>
const char* IsAncestorPositionIterator::class_name_str = "IsAncestorPositionIterator";
IsAncestorPositionIterator::class_factory<IsAncestorPositionIterator>
IsAncestorPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsAncestorPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAncestorPositionIterator::class_versions_count =
sizeof(IsAncestorPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAncestorPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAncestorPositionIterator::~IsAncestorPositionIterator() {}

// </IsAncestorPositionIterator>


// <IsFollowingSiblingPositionIterator>
const char* IsFollowingSiblingPositionIterator::class_name_str = "IsFollowingSiblingPositionIterator";
IsFollowingSiblingPositionIterator::class_factory<IsFollowingSiblingPositionIterator>
IsFollowingSiblingPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingSiblingPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingSiblingPositionIterator::class_versions_count =
sizeof(IsFollowingSiblingPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingSiblingPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingSiblingPositionIterator::~IsFollowingSiblingPositionIterator() {}

// </IsFollowingSiblingPositionIterator>


// <IsFollowingPositionIterator>
const char* IsFollowingPositionIterator::class_name_str = "IsFollowingPositionIterator";
IsFollowingPositionIterator::class_factory<IsFollowingPositionIterator>
IsFollowingPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingPositionIterator::class_versions_count =
sizeof(IsFollowingPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingPositionIterator::~IsFollowingPositionIterator() {}

// </IsFollowingPositionIterator>


// <IsDescendantPositionIterator>
const char* IsDescendantPositionIterator::class_name_str = "IsDescendantPositionIterator";
IsDescendantPositionIterator::class_factory<IsDescendantPositionIterator>
IsDescendantPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsDescendantPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsDescendantPositionIterator::class_versions_count =
sizeof(IsDescendantPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsDescendantPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDescendantPositionIterator::~IsDescendantPositionIterator() {}

// </IsDescendantPositionIterator>


// <IsPrecedingSiblingPositionIterator>
const char* IsPrecedingSiblingPositionIterator::class_name_str = "IsPrecedingSiblingPositionIterator";
IsPrecedingSiblingPositionIterator::class_factory<IsPrecedingSiblingPositionIterator>
IsPrecedingSiblingPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingSiblingPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingSiblingPositionIterator::class_versions_count =
sizeof(IsPrecedingSiblingPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingSiblingPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingSiblingPositionIterator::~IsPrecedingSiblingPositionIterator() {}

// </IsPrecedingSiblingPositionIterator>


// <IsPrecedingPositionIterator>
const char* IsPrecedingPositionIterator::class_name_str = "IsPrecedingPositionIterator";
IsPrecedingPositionIterator::class_factory<IsPrecedingPositionIterator>
IsPrecedingPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingPositionIterator::class_versions_count =
sizeof(IsPrecedingPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingPositionIterator::~IsPrecedingPositionIterator() {}

// </IsPrecedingPositionIterator>


// <IsChildPositionIterator>
const char* IsChildPositionIterator::class_name_str = "IsChildPositionIterator";
IsChildPositionIterator::class_factory<IsChildPositionIterator>
IsChildPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsChildPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsChildPositionIterator::class_versions_count =
sizeof(IsChildPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsChildPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsChildPositionIterator::~IsChildPositionIterator() {}

// </IsChildPositionIterator>


// <IsAttributeOfPositionIterator>
const char* IsAttributeOfPositionIterator::class_name_str = "IsAttributeOfPositionIterator";
IsAttributeOfPositionIterator::class_factory<IsAttributeOfPositionIterator>
IsAttributeOfPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsAttributeOfPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAttributeOfPositionIterator::class_versions_count =
sizeof(IsAttributeOfPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAttributeOfPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAttributeOfPositionIterator::~IsAttributeOfPositionIterator() {}

// </IsAttributeOfPositionIterator>


// <IsParentPositionIterator>
const char* IsParentPositionIterator::class_name_str = "IsParentPositionIterator";
IsParentPositionIterator::class_factory<IsParentPositionIterator>
IsParentPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsParentPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsParentPositionIterator::class_versions_count =
sizeof(IsParentPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsParentPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsParentPositionIterator::~IsParentPositionIterator() {}

// </IsParentPositionIterator>


// <IsPrecedingInDocumentOrderPositionIterator>
const char* IsPrecedingInDocumentOrderPositionIterator::class_name_str = "IsPrecedingInDocumentOrderPositionIterator";
IsPrecedingInDocumentOrderPositionIterator::class_factory<IsPrecedingInDocumentOrderPositionIterator>
IsPrecedingInDocumentOrderPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsPrecedingInDocumentOrderPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsPrecedingInDocumentOrderPositionIterator::class_versions_count =
sizeof(IsPrecedingInDocumentOrderPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsPrecedingInDocumentOrderPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsPrecedingInDocumentOrderPositionIterator::~IsPrecedingInDocumentOrderPositionIterator() {}

// </IsPrecedingInDocumentOrderPositionIterator>


// <IsFollowingInDocumentOrderPositionIterator>
const char* IsFollowingInDocumentOrderPositionIterator::class_name_str = "IsFollowingInDocumentOrderPositionIterator";
IsFollowingInDocumentOrderPositionIterator::class_factory<IsFollowingInDocumentOrderPositionIterator>
IsFollowingInDocumentOrderPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsFollowingInDocumentOrderPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsFollowingInDocumentOrderPositionIterator::class_versions_count =
sizeof(IsFollowingInDocumentOrderPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsFollowingInDocumentOrderPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsFollowingInDocumentOrderPositionIterator::~IsFollowingInDocumentOrderPositionIterator() {}

// </IsFollowingInDocumentOrderPositionIterator>


// <LevelPositionIterator>
const char* LevelPositionIterator::class_name_str = "LevelPositionIterator";
LevelPositionIterator::class_factory<LevelPositionIterator>
LevelPositionIterator::g_class_factory;

const serialization::ClassVersion 
LevelPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int LevelPositionIterator::class_versions_count =
sizeof(LevelPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void LevelPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

LevelPositionIterator::~LevelPositionIterator() {}

// </LevelPositionIterator>


// <IsAttributePositionIterator>
const char* IsAttributePositionIterator::class_name_str = "IsAttributePositionIterator";
IsAttributePositionIterator::class_factory<IsAttributePositionIterator>
IsAttributePositionIterator::g_class_factory;

const serialization::ClassVersion 
IsAttributePositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsAttributePositionIterator::class_versions_count =
sizeof(IsAttributePositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsAttributePositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsAttributePositionIterator::~IsAttributePositionIterator() {}

// </IsAttributePositionIterator>


// <IsCommentPositionIterator>
const char* IsCommentPositionIterator::class_name_str = "IsCommentPositionIterator";
IsCommentPositionIterator::class_factory<IsCommentPositionIterator>
IsCommentPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsCommentPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsCommentPositionIterator::class_versions_count =
sizeof(IsCommentPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsCommentPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsCommentPositionIterator::~IsCommentPositionIterator() {}

// </IsCommentPositionIterator>


// <IsDocumentPositionIterator>
const char* IsDocumentPositionIterator::class_name_str = "IsDocumentPositionIterator";
IsDocumentPositionIterator::class_factory<IsDocumentPositionIterator>
IsDocumentPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsDocumentPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsDocumentPositionIterator::class_versions_count =
sizeof(IsDocumentPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsDocumentPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsDocumentPositionIterator::~IsDocumentPositionIterator() {}

// </IsDocumentPositionIterator>


// <IsElementPositionIterator>
const char* IsElementPositionIterator::class_name_str = "IsElementPositionIterator";
IsElementPositionIterator::class_factory<IsElementPositionIterator>
IsElementPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsElementPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsElementPositionIterator::class_versions_count =
sizeof(IsElementPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsElementPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsElementPositionIterator::~IsElementPositionIterator() {}

// </IsElementPositionIterator>


// <IsProcessingInstructionPositionIterator>
const char* IsProcessingInstructionPositionIterator::class_name_str = "IsProcessingInstructionPositionIterator";
IsProcessingInstructionPositionIterator::class_factory<IsProcessingInstructionPositionIterator>
IsProcessingInstructionPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsProcessingInstructionPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsProcessingInstructionPositionIterator::class_versions_count =
sizeof(IsProcessingInstructionPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsProcessingInstructionPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsProcessingInstructionPositionIterator::~IsProcessingInstructionPositionIterator() {}

// </IsProcessingInstructionPositionIterator>


// <IsTextPositionIterator>
const char* IsTextPositionIterator::class_name_str = "IsTextPositionIterator";
IsTextPositionIterator::class_factory<IsTextPositionIterator>
IsTextPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsTextPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsTextPositionIterator::class_versions_count =
sizeof(IsTextPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsTextPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsTextPositionIterator::~IsTextPositionIterator() {}

// </IsTextPositionIterator>


// <IsSiblingPositionIterator>
const char* IsSiblingPositionIterator::class_name_str = "IsSiblingPositionIterator";
IsSiblingPositionIterator::class_factory<IsSiblingPositionIterator>
IsSiblingPositionIterator::g_class_factory;

const serialization::ClassVersion 
IsSiblingPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsSiblingPositionIterator::class_versions_count =
sizeof(IsSiblingPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsSiblingPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsSiblingPositionIterator::~IsSiblingPositionIterator() {}

// </IsSiblingPositionIterator>


// <InSameTreePositionIterator>
const char* InSameTreePositionIterator::class_name_str = "InSameTreePositionIterator";
InSameTreePositionIterator::class_factory<InSameTreePositionIterator>
InSameTreePositionIterator::g_class_factory;

const serialization::ClassVersion 
InSameTreePositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InSameTreePositionIterator::class_versions_count =
sizeof(InSameTreePositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InSameTreePositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InSameTreePositionIterator::~InSameTreePositionIterator() {}

// </InSameTreePositionIterator>


// <InCollectionPositionIterator>
const char* InCollectionPositionIterator::class_name_str = "InCollectionPositionIterator";
InCollectionPositionIterator::class_factory<InCollectionPositionIterator>
InCollectionPositionIterator::g_class_factory;

const serialization::ClassVersion 
InCollectionPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InCollectionPositionIterator::class_versions_count =
sizeof(InCollectionPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InCollectionPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InCollectionPositionIterator::~InCollectionPositionIterator() {}

// </InCollectionPositionIterator>


// <InSameCollectionPositionIterator>
const char* InSameCollectionPositionIterator::class_name_str = "InSameCollectionPositionIterator";
InSameCollectionPositionIterator::class_factory<InSameCollectionPositionIterator>
InSameCollectionPositionIterator::g_class_factory;

const serialization::ClassVersion 
InSameCollectionPositionIterator::class_versions[] ={{ 1, 0x000905, false}};

const int InSameCollectionPositionIterator::class_versions_count =
sizeof(InSameCollectionPositionIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void InSameCollectionPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

InSameCollectionPositionIterator::~InSameCollectionPositionIterator() {}

// </InSameCollectionPositionIterator>



}


