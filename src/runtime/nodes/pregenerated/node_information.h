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
#ifndef ZORBA_RUNTIME_NODES_NODE_INFORMATION_H
#define ZORBA_RUNTIME_NODES_NODE_INFORMATION_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 * Author: Federico Cavalieri
 */
class NodeInformationIterator : public NaryBaseIterator<NodeInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodeInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeInformationIterator,
    NaryBaseIterator<NodeInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<NodeInformationIterator, PlanIteratorState>*)this);
  }

  NodeInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NodeInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NodeInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsAncestorInformationIterator : public NaryBaseIterator<IsAncestorInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAncestorInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAncestorInformationIterator,
    NaryBaseIterator<IsAncestorInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAncestorInformationIterator, PlanIteratorState>*)this);
  }

  IsAncestorInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAncestorInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAncestorInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsFollowingSiblingInformationIterator : public NaryBaseIterator<IsFollowingSiblingInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingSiblingInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingSiblingInformationIterator,
    NaryBaseIterator<IsFollowingSiblingInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingSiblingInformationIterator, PlanIteratorState>*)this);
  }

  IsFollowingSiblingInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingSiblingInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingSiblingInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsFollowingInformationIterator : public NaryBaseIterator<IsFollowingInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingInformationIterator,
    NaryBaseIterator<IsFollowingInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingInformationIterator, PlanIteratorState>*)this);
  }

  IsFollowingInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsDescendantInformationIterator : public NaryBaseIterator<IsDescendantInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDescendantInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDescendantInformationIterator,
    NaryBaseIterator<IsDescendantInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsDescendantInformationIterator, PlanIteratorState>*)this);
  }

  IsDescendantInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDescendantInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsDescendantInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsPrecedingSiblingInformationIterator : public NaryBaseIterator<IsPrecedingSiblingInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingSiblingInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingSiblingInformationIterator,
    NaryBaseIterator<IsPrecedingSiblingInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingSiblingInformationIterator, PlanIteratorState>*)this);
  }

  IsPrecedingSiblingInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingSiblingInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingSiblingInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsPrecedingInformationIterator : public NaryBaseIterator<IsPrecedingInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingInformationIterator,
    NaryBaseIterator<IsPrecedingInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingInformationIterator, PlanIteratorState>*)this);
  }

  IsPrecedingInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsChildInformationIterator : public NaryBaseIterator<IsChildInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsChildInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsChildInformationIterator,
    NaryBaseIterator<IsChildInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsChildInformationIterator, PlanIteratorState>*)this);
  }

  IsChildInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsChildInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsChildInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsAttributeOfInformationIterator : public NaryBaseIterator<IsAttributeOfInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAttributeOfInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAttributeOfInformationIterator,
    NaryBaseIterator<IsAttributeOfInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAttributeOfInformationIterator, PlanIteratorState>*)this);
  }

  IsAttributeOfInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAttributeOfInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAttributeOfInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsParentInformationIterator : public NaryBaseIterator<IsParentInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsParentInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsParentInformationIterator,
    NaryBaseIterator<IsParentInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsParentInformationIterator, PlanIteratorState>*)this);
  }

  IsParentInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsParentInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsParentInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsPrecedingInDocumentOrderInformationIterator : public NaryBaseIterator<IsPrecedingInDocumentOrderInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingInDocumentOrderInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingInDocumentOrderInformationIterator,
    NaryBaseIterator<IsPrecedingInDocumentOrderInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingInDocumentOrderInformationIterator, PlanIteratorState>*)this);
  }

  IsPrecedingInDocumentOrderInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingInDocumentOrderInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingInDocumentOrderInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsFollowingInDocumentOrderInformationIterator : public NaryBaseIterator<IsFollowingInDocumentOrderInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingInDocumentOrderInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingInDocumentOrderInformationIterator,
    NaryBaseIterator<IsFollowingInDocumentOrderInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingInDocumentOrderInformationIterator, PlanIteratorState>*)this);
  }

  IsFollowingInDocumentOrderInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingInDocumentOrderInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingInDocumentOrderInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class LevelInformationIterator : public NaryBaseIterator<LevelInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(LevelInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LevelInformationIterator,
    NaryBaseIterator<LevelInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<LevelInformationIterator, PlanIteratorState>*)this);
  }

  LevelInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<LevelInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~LevelInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsAttributeInformationIterator : public NaryBaseIterator<IsAttributeInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAttributeInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAttributeInformationIterator,
    NaryBaseIterator<IsAttributeInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAttributeInformationIterator, PlanIteratorState>*)this);
  }

  IsAttributeInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAttributeInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAttributeInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsCommentInformationIterator : public NaryBaseIterator<IsCommentInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsCommentInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsCommentInformationIterator,
    NaryBaseIterator<IsCommentInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsCommentInformationIterator, PlanIteratorState>*)this);
  }

  IsCommentInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsCommentInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsCommentInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsDocumentInformationIterator : public NaryBaseIterator<IsDocumentInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDocumentInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDocumentInformationIterator,
    NaryBaseIterator<IsDocumentInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsDocumentInformationIterator, PlanIteratorState>*)this);
  }

  IsDocumentInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDocumentInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsDocumentInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsElementInformationIterator : public NaryBaseIterator<IsElementInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsElementInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsElementInformationIterator,
    NaryBaseIterator<IsElementInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsElementInformationIterator, PlanIteratorState>*)this);
  }

  IsElementInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsElementInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsElementInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsProcessingInstructionInformationIterator : public NaryBaseIterator<IsProcessingInstructionInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsProcessingInstructionInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsProcessingInstructionInformationIterator,
    NaryBaseIterator<IsProcessingInstructionInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsProcessingInstructionInformationIterator, PlanIteratorState>*)this);
  }

  IsProcessingInstructionInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsProcessingInstructionInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsProcessingInstructionInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsTextInformationIterator : public NaryBaseIterator<IsTextInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsTextInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsTextInformationIterator,
    NaryBaseIterator<IsTextInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsTextInformationIterator, PlanIteratorState>*)this);
  }

  IsTextInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsTextInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsTextInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsSiblingInformationIterator : public NaryBaseIterator<IsSiblingInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsSiblingInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsSiblingInformationIterator,
    NaryBaseIterator<IsSiblingInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsSiblingInformationIterator, PlanIteratorState>*)this);
  }

  IsSiblingInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsSiblingInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsSiblingInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class InSameTreeInformationIterator : public NaryBaseIterator<InSameTreeInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InSameTreeInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InSameTreeInformationIterator,
    NaryBaseIterator<InSameTreeInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InSameTreeInformationIterator, PlanIteratorState>*)this);
  }

  InSameTreeInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InSameTreeInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~InSameTreeInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class InCollectionInformationIterator : public NaryBaseIterator<InCollectionInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InCollectionInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InCollectionInformationIterator,
    NaryBaseIterator<InCollectionInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InCollectionInformationIterator, PlanIteratorState>*)this);
  }

  InCollectionInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InCollectionInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~InCollectionInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class InSameCollectionInformationIterator : public NaryBaseIterator<InSameCollectionInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InSameCollectionInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InSameCollectionInformationIterator,
    NaryBaseIterator<InSameCollectionInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InSameCollectionInformationIterator, PlanIteratorState>*)this);
  }

  InSameCollectionInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InSameCollectionInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~InSameCollectionInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
