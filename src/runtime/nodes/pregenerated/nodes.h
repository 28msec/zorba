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
#ifndef ZORBA_RUNTIME_NODES_NODES_H
#define ZORBA_RUNTIME_NODES_NODES_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 *        
 *      declare function ref:node-reference($node as node()) as xs:anyURI
 *    
 * Author: Federico Cavalieri
 */
class NodeReferenceIterator : public NaryBaseIterator<NodeReferenceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodeReferenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeReferenceIterator,
    NaryBaseIterator<NodeReferenceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  NodeReferenceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NodeReferenceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NodeReferenceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      declare function ref:has-node-reference($node as node()) as xs:boolean
 *    
 * Author: Till Westmann
 */
class HasNodeReferenceIterator : public NaryBaseIterator<HasNodeReferenceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(HasNodeReferenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(HasNodeReferenceIterator,
    NaryBaseIterator<HasNodeReferenceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  HasNodeReferenceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<HasNodeReferenceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~HasNodeReferenceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      declare function ref:assign-node-reference($node as node()) as xs:boolean
 *    
 * Author: Till Westmann
 */
class AssignNodeReferenceIterator : public NaryBaseIterator<AssignNodeReferenceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(AssignNodeReferenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AssignNodeReferenceIterator,
    NaryBaseIterator<AssignNodeReferenceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  AssignNodeReferenceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<AssignNodeReferenceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~AssignNodeReferenceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      declare function ref:node-by-reference($reference as xs:anyURI) as node()?
 *    
 * Author: Federico Cavalieri
 */
class NodeByReferenceIterator : public NaryBaseIterator<NodeByReferenceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodeByReferenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeByReferenceIterator,
    NaryBaseIterator<NodeByReferenceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  NodeByReferenceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NodeByReferenceIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NodeByReferenceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    fn:local-name
 *  
 * Author: Zorba Team
 */
class FnLocalNameIterator : public NaryBaseIterator<FnLocalNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnLocalNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnLocalNameIterator,
    NaryBaseIterator<FnLocalNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnLocalNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnLocalNameIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnLocalNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    fn:namespace-uri
 *  
 * Author: Zorba Team
 */
class FnNamespaceUriIterator : public NaryBaseIterator<FnNamespaceUriIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnNamespaceUriIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnNamespaceUriIterator,
    NaryBaseIterator<FnNamespaceUriIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnNamespaceUriIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnNamespaceUriIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnNamespaceUriIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    fn:lang
 *  
 * Author: Zorba Team
 */
class FnLangIterator : public NaryBaseIterator<FnLangIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnLangIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnLangIterator,
    NaryBaseIterator<FnLangIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnLangIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnLangIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnLangIterator();

public:
  bool isLangAttr(const store::Item_t& aAttr) const;
  bool matchesReqLang(const store::Item_t& aLangAttr, const zstring& aRequestLang) const;
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:has-children
 * Author: Zorba Team
 */
class FnHasChildrenIterator : public NaryBaseIterator<FnHasChildrenIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnHasChildrenIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnHasChildrenIterator,
    NaryBaseIterator<FnHasChildrenIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnHasChildrenIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnHasChildrenIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnHasChildrenIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:innermost
 * Author: Zorba Team
 */
class FnInnermostIteratorState : public PlanIteratorState
{
public:
  std::list<store::Item_t> node_list; //temporary list of nodes
  std::list<store::Item_t>::iterator list_it; //iterator through result sequence

  FnInnermostIteratorState();

  ~FnInnermostIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnInnermostIterator : public NaryBaseIterator<FnInnermostIterator, FnInnermostIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnInnermostIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnInnermostIterator,
    NaryBaseIterator<FnInnermostIterator, FnInnermostIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnInnermostIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnInnermostIterator, FnInnermostIteratorState>(sctx, loc, children)
  {}

  virtual ~FnInnermostIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:outermost
 * Author: Zorba Team
 */
class FnOutermostIteratorState : public PlanIteratorState
{
public:
  std::list<store::Item_t> node_list; //temporary list of nodes
  std::list<store::Item_t>::iterator list_it; //iterator through result sequence

  FnOutermostIteratorState();

  ~FnOutermostIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnOutermostIterator : public NaryBaseIterator<FnOutermostIterator, FnOutermostIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnOutermostIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnOutermostIterator,
    NaryBaseIterator<FnOutermostIterator, FnOutermostIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnOutermostIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnOutermostIterator, FnOutermostIteratorState>(sctx, loc, children)
  {}

  virtual ~FnOutermostIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:generate-id
 * Author: Zorba Team
 */
class FnGenerateIdIterator : public NaryBaseIterator<FnGenerateIdIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnGenerateIdIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnGenerateIdIterator,
    NaryBaseIterator<FnGenerateIdIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnGenerateIdIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnGenerateIdIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnGenerateIdIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class IsAncestorIterator : public NaryBaseIterator<IsAncestorIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAncestorIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAncestorIterator,
    NaryBaseIterator<IsAncestorIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsAncestorIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAncestorIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAncestorIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class IsDescendantIterator : public NaryBaseIterator<IsDescendantIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsDescendantIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsDescendantIterator,
    NaryBaseIterator<IsDescendantIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsDescendantIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsDescendantIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsDescendantIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class IsParentIterator : public NaryBaseIterator<IsParentIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsParentIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsParentIterator,
    NaryBaseIterator<IsParentIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsParentIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsParentIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsParentIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class IsChildIterator : public NaryBaseIterator<IsChildIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsChildIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsChildIterator,
    NaryBaseIterator<IsChildIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsChildIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsChildIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsChildIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class IsFollowingIterator : public NaryBaseIterator<IsFollowingIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingIterator,
    NaryBaseIterator<IsFollowingIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsFollowingIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class IsPrecedingIterator : public NaryBaseIterator<IsPrecedingIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingIterator,
    NaryBaseIterator<IsPrecedingIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsPrecedingIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class IsFollowingSiblingIterator : public NaryBaseIterator<IsFollowingSiblingIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsFollowingSiblingIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsFollowingSiblingIterator,
    NaryBaseIterator<IsFollowingSiblingIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsFollowingSiblingIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsFollowingSiblingIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsFollowingSiblingIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class IsPrecedingSiblingIterator : public NaryBaseIterator<IsPrecedingSiblingIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsPrecedingSiblingIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsPrecedingSiblingIterator,
    NaryBaseIterator<IsPrecedingSiblingIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsPrecedingSiblingIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsPrecedingSiblingIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsPrecedingSiblingIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class LevelIterator : public NaryBaseIterator<LevelIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(LevelIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LevelIterator,
    NaryBaseIterator<LevelIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  LevelIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<LevelIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~LevelIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class LeastCommonAncestor : public NaryBaseIterator<LeastCommonAncestor, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(LeastCommonAncestor);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(LeastCommonAncestor,
    NaryBaseIterator<LeastCommonAncestor, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  LeastCommonAncestor(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<LeastCommonAncestor, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~LeastCommonAncestor();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class FnPathIterator : public NaryBaseIterator<FnPathIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnPathIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnPathIterator,
    NaryBaseIterator<FnPathIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnPathIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnPathIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnPathIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 * Author: Zorba Team
 */
class NodeCopyIterator : public NaryBaseIterator<NodeCopyIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodeCopyIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeCopyIterator,
    NaryBaseIterator<NodeCopyIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  NodeCopyIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<NodeCopyIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~NodeCopyIterator();

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
