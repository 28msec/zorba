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
#ifndef ZORBA_RUNTIME_NODES_NODE_POSITION_H
#define ZORBA_RUNTIME_NODES_NODE_POSITION_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 * Author: Federico Cavalieri
 */
class NodePositionIterator : public NaryBaseIterator<NodePositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodePositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodePositionIterator,
    NaryBaseIterator<NodePositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<NodePositionIterator, PlanIteratorState>*)this);
  }

  NodePositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NodePositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NodePositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsAncestorPositionIterator : public NaryBaseIterator<IsAncestorPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAncestorPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAncestorPositionIterator,
    NaryBaseIterator<IsAncestorPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAncestorPositionIterator, PlanIteratorState>*)this);
  }

  IsAncestorPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAncestorPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAncestorPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsFollowingSiblingPositionIterator : public NaryBaseIterator<IsFollowingSiblingPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingSiblingPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingSiblingPositionIterator,
    NaryBaseIterator<IsFollowingSiblingPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingSiblingPositionIterator, PlanIteratorState>*)this);
  }

  IsFollowingSiblingPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingSiblingPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingSiblingPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsFollowingPositionIterator : public NaryBaseIterator<IsFollowingPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingPositionIterator,
    NaryBaseIterator<IsFollowingPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingPositionIterator, PlanIteratorState>*)this);
  }

  IsFollowingPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsInSubtreeOfPositionIterator : public NaryBaseIterator<IsInSubtreeOfPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsInSubtreeOfPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsInSubtreeOfPositionIterator,
    NaryBaseIterator<IsInSubtreeOfPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsInSubtreeOfPositionIterator, PlanIteratorState>*)this);
  }

  IsInSubtreeOfPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsInSubtreeOfPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsInSubtreeOfPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsDescendantPositionIterator : public NaryBaseIterator<IsDescendantPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDescendantPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDescendantPositionIterator,
    NaryBaseIterator<IsDescendantPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsDescendantPositionIterator, PlanIteratorState>*)this);
  }

  IsDescendantPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDescendantPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsDescendantPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsPrecedingSiblingPositionIterator : public NaryBaseIterator<IsPrecedingSiblingPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingSiblingPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingSiblingPositionIterator,
    NaryBaseIterator<IsPrecedingSiblingPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingSiblingPositionIterator, PlanIteratorState>*)this);
  }

  IsPrecedingSiblingPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingSiblingPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingSiblingPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsPrecedingPositionIterator : public NaryBaseIterator<IsPrecedingPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingPositionIterator,
    NaryBaseIterator<IsPrecedingPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingPositionIterator, PlanIteratorState>*)this);
  }

  IsPrecedingPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsChildPositionIterator : public NaryBaseIterator<IsChildPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsChildPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsChildPositionIterator,
    NaryBaseIterator<IsChildPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsChildPositionIterator, PlanIteratorState>*)this);
  }

  IsChildPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsChildPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsChildPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsAttributeOfPositionIterator : public NaryBaseIterator<IsAttributeOfPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAttributeOfPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAttributeOfPositionIterator,
    NaryBaseIterator<IsAttributeOfPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAttributeOfPositionIterator, PlanIteratorState>*)this);
  }

  IsAttributeOfPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAttributeOfPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAttributeOfPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsParentPositionIterator : public NaryBaseIterator<IsParentPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsParentPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsParentPositionIterator,
    NaryBaseIterator<IsParentPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsParentPositionIterator, PlanIteratorState>*)this);
  }

  IsParentPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsParentPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsParentPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsPrecedingInDocumentOrderPositionIterator : public NaryBaseIterator<IsPrecedingInDocumentOrderPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingInDocumentOrderPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingInDocumentOrderPositionIterator,
    NaryBaseIterator<IsPrecedingInDocumentOrderPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingInDocumentOrderPositionIterator, PlanIteratorState>*)this);
  }

  IsPrecedingInDocumentOrderPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingInDocumentOrderPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingInDocumentOrderPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsFollowingInDocumentOrderPositionIterator : public NaryBaseIterator<IsFollowingInDocumentOrderPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingInDocumentOrderPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingInDocumentOrderPositionIterator,
    NaryBaseIterator<IsFollowingInDocumentOrderPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingInDocumentOrderPositionIterator, PlanIteratorState>*)this);
  }

  IsFollowingInDocumentOrderPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingInDocumentOrderPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingInDocumentOrderPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class LevelPositionIterator : public NaryBaseIterator<LevelPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(LevelPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LevelPositionIterator,
    NaryBaseIterator<LevelPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<LevelPositionIterator, PlanIteratorState>*)this);
  }

  LevelPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<LevelPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~LevelPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsAttributePositionIterator : public NaryBaseIterator<IsAttributePositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAttributePositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAttributePositionIterator,
    NaryBaseIterator<IsAttributePositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAttributePositionIterator, PlanIteratorState>*)this);
  }

  IsAttributePositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAttributePositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAttributePositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsCommentPositionIterator : public NaryBaseIterator<IsCommentPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsCommentPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsCommentPositionIterator,
    NaryBaseIterator<IsCommentPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsCommentPositionIterator, PlanIteratorState>*)this);
  }

  IsCommentPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsCommentPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsCommentPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsDocumentPositionIterator : public NaryBaseIterator<IsDocumentPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDocumentPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDocumentPositionIterator,
    NaryBaseIterator<IsDocumentPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsDocumentPositionIterator, PlanIteratorState>*)this);
  }

  IsDocumentPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDocumentPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsDocumentPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsElementPositionIterator : public NaryBaseIterator<IsElementPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsElementPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsElementPositionIterator,
    NaryBaseIterator<IsElementPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsElementPositionIterator, PlanIteratorState>*)this);
  }

  IsElementPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsElementPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsElementPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsProcessingInstructionPositionIterator : public NaryBaseIterator<IsProcessingInstructionPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsProcessingInstructionPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsProcessingInstructionPositionIterator,
    NaryBaseIterator<IsProcessingInstructionPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsProcessingInstructionPositionIterator, PlanIteratorState>*)this);
  }

  IsProcessingInstructionPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsProcessingInstructionPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsProcessingInstructionPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsTextPositionIterator : public NaryBaseIterator<IsTextPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsTextPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsTextPositionIterator,
    NaryBaseIterator<IsTextPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsTextPositionIterator, PlanIteratorState>*)this);
  }

  IsTextPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsTextPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsTextPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsSiblingPositionIterator : public NaryBaseIterator<IsSiblingPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsSiblingPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsSiblingPositionIterator,
    NaryBaseIterator<IsSiblingPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsSiblingPositionIterator, PlanIteratorState>*)this);
  }

  IsSiblingPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsSiblingPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsSiblingPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class InSameTreePositionIterator : public NaryBaseIterator<InSameTreePositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InSameTreePositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InSameTreePositionIterator,
    NaryBaseIterator<InSameTreePositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InSameTreePositionIterator, PlanIteratorState>*)this);
  }

  InSameTreePositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InSameTreePositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~InSameTreePositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class InCollectionPositionIterator : public NaryBaseIterator<InCollectionPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InCollectionPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InCollectionPositionIterator,
    NaryBaseIterator<InCollectionPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InCollectionPositionIterator, PlanIteratorState>*)this);
  }

  InCollectionPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InCollectionPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~InCollectionPositionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class InSameCollectionPositionIterator : public NaryBaseIterator<InSameCollectionPositionIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InSameCollectionPositionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InSameCollectionPositionIterator,
    NaryBaseIterator<InSameCollectionPositionIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InSameCollectionPositionIterator, PlanIteratorState>*)this);
  }

  InSameCollectionPositionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InSameCollectionPositionIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~InSameCollectionPositionIterator();

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
