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
 *  Iterator to implement the zorba:node-reference function.
 *  
 * Author: Zorba Team
 */
class NodeReferenceIterator : public NaryBaseIterator<NodeReferenceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodeReferenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeReferenceIterator,
    NaryBaseIterator<NodeReferenceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<NodeReferenceIterator, PlanIteratorState>*)this);
  }

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
 *      Iterator to implement the zorba:node-by-reference function.
 *    
 * Author: Zorba Team
 */
class NodeByReferenceIterator : public NaryBaseIterator<NodeByReferenceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(NodeByReferenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NodeByReferenceIterator,
    NaryBaseIterator<NodeByReferenceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<NodeByReferenceIterator, PlanIteratorState>*)this);
  }

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

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnLocalNameIterator, PlanIteratorState>*)this);
  }

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

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnNamespaceUriIterator, PlanIteratorState>*)this);
  }

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

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnLangIterator, PlanIteratorState>*)this);
  }

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

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnHasChildrenIterator, PlanIteratorState>*)this);
  }

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

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnInnermostIterator, FnInnermostIteratorState>*)this);
  }

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

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnOutermostIterator, FnOutermostIteratorState>*)this);
  }

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

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnGenerateIdIterator, PlanIteratorState>*)this);
  }

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


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
