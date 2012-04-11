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
NodePositionIterator::class_factory<NodePositionIterator>
NodePositionIterator::g_class_factory;


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
IsAncestorPositionIterator::class_factory<IsAncestorPositionIterator>
IsAncestorPositionIterator::g_class_factory;


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
IsFollowingSiblingPositionIterator::class_factory<IsFollowingSiblingPositionIterator>
IsFollowingSiblingPositionIterator::g_class_factory;


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
IsFollowingPositionIterator::class_factory<IsFollowingPositionIterator>
IsFollowingPositionIterator::g_class_factory;


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


// <IsInSubtreeOfPositionIterator>
IsInSubtreeOfPositionIterator::class_factory<IsInSubtreeOfPositionIterator>
IsInSubtreeOfPositionIterator::g_class_factory;


void IsInSubtreeOfPositionIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

IsInSubtreeOfPositionIterator::~IsInSubtreeOfPositionIterator() {}

// </IsInSubtreeOfPositionIterator>


// <IsDescendantPositionIterator>
IsDescendantPositionIterator::class_factory<IsDescendantPositionIterator>
IsDescendantPositionIterator::g_class_factory;


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
IsPrecedingSiblingPositionIterator::class_factory<IsPrecedingSiblingPositionIterator>
IsPrecedingSiblingPositionIterator::g_class_factory;


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
IsPrecedingPositionIterator::class_factory<IsPrecedingPositionIterator>
IsPrecedingPositionIterator::g_class_factory;


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
IsChildPositionIterator::class_factory<IsChildPositionIterator>
IsChildPositionIterator::g_class_factory;


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
IsAttributeOfPositionIterator::class_factory<IsAttributeOfPositionIterator>
IsAttributeOfPositionIterator::g_class_factory;


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
IsParentPositionIterator::class_factory<IsParentPositionIterator>
IsParentPositionIterator::g_class_factory;


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
IsPrecedingInDocumentOrderPositionIterator::class_factory<IsPrecedingInDocumentOrderPositionIterator>
IsPrecedingInDocumentOrderPositionIterator::g_class_factory;


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
IsFollowingInDocumentOrderPositionIterator::class_factory<IsFollowingInDocumentOrderPositionIterator>
IsFollowingInDocumentOrderPositionIterator::g_class_factory;


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
LevelPositionIterator::class_factory<LevelPositionIterator>
LevelPositionIterator::g_class_factory;


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
IsAttributePositionIterator::class_factory<IsAttributePositionIterator>
IsAttributePositionIterator::g_class_factory;


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
IsCommentPositionIterator::class_factory<IsCommentPositionIterator>
IsCommentPositionIterator::g_class_factory;


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
IsDocumentPositionIterator::class_factory<IsDocumentPositionIterator>
IsDocumentPositionIterator::g_class_factory;


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
IsElementPositionIterator::class_factory<IsElementPositionIterator>
IsElementPositionIterator::g_class_factory;


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
IsProcessingInstructionPositionIterator::class_factory<IsProcessingInstructionPositionIterator>
IsProcessingInstructionPositionIterator::g_class_factory;


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
IsTextPositionIterator::class_factory<IsTextPositionIterator>
IsTextPositionIterator::g_class_factory;


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
IsSiblingPositionIterator::class_factory<IsSiblingPositionIterator>
IsSiblingPositionIterator::g_class_factory;


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
InSameTreePositionIterator::class_factory<InSameTreePositionIterator>
InSameTreePositionIterator::g_class_factory;


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
InCollectionPositionIterator::class_factory<InCollectionPositionIterator>
InCollectionPositionIterator::g_class_factory;


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
InSameCollectionPositionIterator::class_factory<InSameCollectionPositionIterator>
InSameCollectionPositionIterator::g_class_factory;


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


