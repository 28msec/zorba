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
#ifndef ZORBA_RUNTIME_STORE_DOCUMENTS_H
#define ZORBA_RUNTIME_STORE_DOCUMENTS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 *      declare updating function
 *      put($uri as xs:string, $doc as xs:document-node()) as empty-sequence()
 *    
 * Author: Matthias Brantner
 */
class PutDocumentIterator : public NaryBaseIterator<PutDocumentIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(PutDocumentIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PutDocumentIterator,
    NaryBaseIterator<PutDocumentIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  PutDocumentIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<PutDocumentIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~PutDocumentIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      declare updating function
 *      remove($uri as xs:string) as empty-sequence()
 *    
 * Author: Matthias Brantner
 */
class RemoveDocumentIterator : public NaryBaseIterator<RemoveDocumentIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(RemoveDocumentIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RemoveDocumentIterator,
    NaryBaseIterator<RemoveDocumentIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  RemoveDocumentIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<RemoveDocumentIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~RemoveDocumentIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      declare function
 *      document($uri as xs:string) as document-node()
 *    
 * Author: Matthias Brantner
 */
class RetrieveDocumentIterator : public NaryBaseIterator<RetrieveDocumentIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(RetrieveDocumentIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(RetrieveDocumentIterator,
    NaryBaseIterator<RetrieveDocumentIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  RetrieveDocumentIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<RetrieveDocumentIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~RetrieveDocumentIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      declare function
 *      available-documents() as xs:string*
 *    
 * Author: Matthias Brantner
 */
class AvailableDocumentsIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t theNameIterator; //the current iterator

  AvailableDocumentsIteratorState();

  ~AvailableDocumentsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class AvailableDocumentsIterator : public NaryBaseIterator<AvailableDocumentsIterator, AvailableDocumentsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(AvailableDocumentsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AvailableDocumentsIterator,
    NaryBaseIterator<AvailableDocumentsIterator, AvailableDocumentsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  AvailableDocumentsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<AvailableDocumentsIterator, AvailableDocumentsIteratorState>(sctx, loc, children)
  {}

  virtual ~AvailableDocumentsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      declare function
 *      is-available-document() as xs:boolean
 *    
 * Author: Matthias Brantner
 */
class IsAvailableDocumentIterator : public NaryBaseIterator<IsAvailableDocumentIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(IsAvailableDocumentIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(IsAvailableDocumentIterator,
    NaryBaseIterator<IsAvailableDocumentIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  IsAvailableDocumentIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<IsAvailableDocumentIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~IsAvailableDocumentIterator();

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
