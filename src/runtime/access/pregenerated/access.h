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
#ifndef ZORBA_RUNTIME_ACCESS_ACCESS_H
#define ZORBA_RUNTIME_ACCESS_ACCESS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 *      Returns a sequence of xs:anyURI values representing the document URIs of the 
 *      documents in a collection.
 *    
 * Author: Zorba Team
 */
class FnURICollectionIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theIterator; //the current iterator
  bool theIteratorOpened; //flag indicating whether theIterator was opened

  FnURICollectionIteratorState();

  ~FnURICollectionIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnURICollectionIterator : public NaryBaseIterator<FnURICollectionIterator, FnURICollectionIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnURICollectionIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnURICollectionIterator,
    NaryBaseIterator<FnURICollectionIterator, FnURICollectionIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnURICollectionIterator, FnURICollectionIteratorState>*)this);
  }

  FnURICollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnURICollectionIterator, FnURICollectionIteratorState>(sctx, loc, children)
  {}

  virtual ~FnURICollectionIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      Summary: The fn:unparsed-text function reads an external resource (for 
 *      example, a file) and returns its contents as a string.
 *    
 * Author: Zorba Team
 */
class FnUnparsedTextIterator : public NaryBaseIterator<FnUnparsedTextIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnUnparsedTextIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnUnparsedTextIterator,
    NaryBaseIterator<FnUnparsedTextIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnUnparsedTextIterator, PlanIteratorState>*)this);
  }

  FnUnparsedTextIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnUnparsedTextIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnUnparsedTextIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      Because errors in evaluating the fn:unparsed-text function are 
 *      non-recoverable, these two functions are provided to allow an application 
 *      to determine whether a call with particular arguments would succeed.
 *    
 * Author: Zorba Team
 */
class FnUnparsedTextAvailableIterator : public NaryBaseIterator<FnUnparsedTextAvailableIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnUnparsedTextAvailableIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnUnparsedTextAvailableIterator,
    NaryBaseIterator<FnUnparsedTextAvailableIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnUnparsedTextAvailableIterator, PlanIteratorState>*)this);
  }

  FnUnparsedTextAvailableIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnUnparsedTextAvailableIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnUnparsedTextAvailableIterator();

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
