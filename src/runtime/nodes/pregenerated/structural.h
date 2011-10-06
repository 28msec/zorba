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
#ifndef ZORBA_RUNTIME_NODES_STRUCTURAL_H
#define ZORBA_RUNTIME_NODES_STRUCTURAL_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 *  Iterator to implement the zorba:node-reference function.
 *  
 * Author: Federico Cavalieri
 */
class NodeStructuralInformationIterator : public NaryBaseIterator<NodeStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodeStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeStructuralInformationIterator,
    NaryBaseIterator<NodeStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<NodeStructuralInformationIterator, PlanIteratorState>*)this);
  }

  NodeStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NodeStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NodeStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsAncestorStructuralInformationIterator : public NaryBaseIterator<IsAncestorStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAncestorStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAncestorStructuralInformationIterator,
    NaryBaseIterator<IsAncestorStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAncestorStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsAncestorStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAncestorStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAncestorStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsFollowingSiblingStructuralInformationIterator : public NaryBaseIterator<IsFollowingSiblingStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingSiblingStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingSiblingStructuralInformationIterator,
    NaryBaseIterator<IsFollowingSiblingStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingSiblingStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsFollowingSiblingStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingSiblingStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingSiblingStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsFollowingStructuralInformationIterator : public NaryBaseIterator<IsFollowingStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingStructuralInformationIterator,
    NaryBaseIterator<IsFollowingStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsFollowingStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsDescendantStructuralInformationIterator : public NaryBaseIterator<IsDescendantStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDescendantStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDescendantStructuralInformationIterator,
    NaryBaseIterator<IsDescendantStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsDescendantStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsDescendantStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDescendantStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsDescendantStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsPrecedingSiblingStructuralInformationIterator : public NaryBaseIterator<IsPrecedingSiblingStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingSiblingStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingSiblingStructuralInformationIterator,
    NaryBaseIterator<IsPrecedingSiblingStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingSiblingStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsPrecedingSiblingStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingSiblingStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingSiblingStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsPrecedingStructuralInformationIterator : public NaryBaseIterator<IsPrecedingStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingStructuralInformationIterator,
    NaryBaseIterator<IsPrecedingStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsPrecedingStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsChildStructuralInformationIterator : public NaryBaseIterator<IsChildStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsChildStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsChildStructuralInformationIterator,
    NaryBaseIterator<IsChildStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsChildStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsChildStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsChildStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsChildStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsAttributeOfStructuralInformationIterator : public NaryBaseIterator<IsAttributeOfStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAttributeOfStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAttributeOfStructuralInformationIterator,
    NaryBaseIterator<IsAttributeOfStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAttributeOfStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsAttributeOfStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAttributeOfStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAttributeOfStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsParentStructuralInformationIterator : public NaryBaseIterator<IsParentStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsParentStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsParentStructuralInformationIterator,
    NaryBaseIterator<IsParentStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsParentStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsParentStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsParentStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsParentStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsPrecedingInDocumentOrderStructuralInformationIterator : public NaryBaseIterator<IsPrecedingInDocumentOrderStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingInDocumentOrderStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingInDocumentOrderStructuralInformationIterator,
    NaryBaseIterator<IsPrecedingInDocumentOrderStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsPrecedingInDocumentOrderStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsPrecedingInDocumentOrderStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingInDocumentOrderStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingInDocumentOrderStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsFollowingInDocumentOrderStructuralInformationIterator : public NaryBaseIterator<IsFollowingInDocumentOrderStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingInDocumentOrderStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingInDocumentOrderStructuralInformationIterator,
    NaryBaseIterator<IsFollowingInDocumentOrderStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsFollowingInDocumentOrderStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsFollowingInDocumentOrderStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingInDocumentOrderStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingInDocumentOrderStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class LevelStructuralInformationIterator : public NaryBaseIterator<LevelStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(LevelStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LevelStructuralInformationIterator,
    NaryBaseIterator<LevelStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<LevelStructuralInformationIterator, PlanIteratorState>*)this);
  }

  LevelStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<LevelStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~LevelStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsAttributeStructuralInformationIterator : public NaryBaseIterator<IsAttributeStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAttributeStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAttributeStructuralInformationIterator,
    NaryBaseIterator<IsAttributeStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsAttributeStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsAttributeStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAttributeStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAttributeStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsCommentStructuralInformationIterator : public NaryBaseIterator<IsCommentStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsCommentStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsCommentStructuralInformationIterator,
    NaryBaseIterator<IsCommentStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsCommentStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsCommentStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsCommentStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsCommentStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsDocumentStructuralInformationIterator : public NaryBaseIterator<IsDocumentStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDocumentStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDocumentStructuralInformationIterator,
    NaryBaseIterator<IsDocumentStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsDocumentStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsDocumentStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDocumentStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsDocumentStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsElementStructuralInformationIterator : public NaryBaseIterator<IsElementStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsElementStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsElementStructuralInformationIterator,
    NaryBaseIterator<IsElementStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsElementStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsElementStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsElementStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsElementStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsProcessingInstructionStructuralInformationIterator : public NaryBaseIterator<IsProcessingInstructionStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsProcessingInstructionStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsProcessingInstructionStructuralInformationIterator,
    NaryBaseIterator<IsProcessingInstructionStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsProcessingInstructionStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsProcessingInstructionStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsProcessingInstructionStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsProcessingInstructionStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsTextStructuralInformationIterator : public NaryBaseIterator<IsTextStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsTextStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsTextStructuralInformationIterator,
    NaryBaseIterator<IsTextStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsTextStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsTextStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsTextStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsTextStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class IsSiblingStructuralInformationIterator : public NaryBaseIterator<IsSiblingStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsSiblingStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsSiblingStructuralInformationIterator,
    NaryBaseIterator<IsSiblingStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<IsSiblingStructuralInformationIterator, PlanIteratorState>*)this);
  }

  IsSiblingStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsSiblingStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsSiblingStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class InSameTreeStructuralInformationIterator : public NaryBaseIterator<InSameTreeStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InSameTreeStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InSameTreeStructuralInformationIterator,
    NaryBaseIterator<InSameTreeStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InSameTreeStructuralInformationIterator, PlanIteratorState>*)this);
  }

  InSameTreeStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InSameTreeStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~InSameTreeStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class InCollectionStructuralInformationIterator : public NaryBaseIterator<InCollectionStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InCollectionStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InCollectionStructuralInformationIterator,
    NaryBaseIterator<InCollectionStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InCollectionStructuralInformationIterator, PlanIteratorState>*)this);
  }

  InCollectionStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InCollectionStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~InCollectionStructuralInformationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Federico Cavalieri
 */
class InSameCollectionStructuralInformationIterator : public NaryBaseIterator<InSameCollectionStructuralInformationIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(InSameCollectionStructuralInformationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InSameCollectionStructuralInformationIterator,
    NaryBaseIterator<InSameCollectionStructuralInformationIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<InSameCollectionStructuralInformationIterator, PlanIteratorState>*)this);
  }

  InSameCollectionStructuralInformationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<InSameCollectionStructuralInformationIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~InSameCollectionStructuralInformationIterator();

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
