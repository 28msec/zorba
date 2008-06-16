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
#ifndef ZORBA_RUNTIME_REST_H
#define ZORBA_RUNTIME_REST_H

#include <istream>
#include <streambuf>
#include "common/shared_types.h"
#include "runtime/base/narybase.h"
#include "runtime/base/noarybase.h"

namespace zorba {

  
typedef void CURL;
typedef void CURLM;


class CurlStreamBuffer;
typedef rchandle<CurlStreamBuffer> CurlStreamBuffer_t;


class CurlStreamBuffer : public std::streambuf, public SimpleRCObject
{
public:
  CurlStreamBuffer(CURLM* aMultiHandle, CURL* aEasyHandle);
  virtual ~CurlStreamBuffer();

  virtual int overflow(int c);
  virtual int underflow();
  int multi_perform();

protected:
  std::auto_ptr<char> CurlErrorBuffer;
  CURLM* MultiHandle;
  CURL* EasyHandle;

  // callback called by curl
  static size_t
  write_callback(char *buffer, size_t size, size_t nitems, void *userp);
  
  static const int INITIAL_BUFFER_SIZE = 1024;
};



/****************************************************************************
 *
 * ChildrenIterator - will return one by one the Items that it was 
 * initialized with. 
 *
 ****************************************************************************/

class ChildrenIteratorState : public PlanIteratorState
{
public:
  ChildrenIteratorState() : index(0) { };
  
  void init(PlanState&);
  void reset(PlanState&);

  unsigned int index;
};

class ChildrenIterator : public NoaryBaseIterator<ChildrenIterator, ChildrenIteratorState >
{
public:
  ChildrenIterator()
  : NoaryBaseIterator<ChildrenIterator, ChildrenIteratorState >(QueryLoc())  { } 
  
  ChildrenIterator(store::Item_t child)
    : NoaryBaseIterator<ChildrenIterator, ChildrenIteratorState >(QueryLoc())
  { 
    children.push_back(child);
  }

  ChildrenIterator(store::Item_t child1, store::Item_t child2)
    : NoaryBaseIterator<ChildrenIterator, ChildrenIteratorState >(QueryLoc())
  {
    children.push_back(child1);
    children.push_back(child2);
  }

  ChildrenIterator(store::Item_t child1, store::Item_t child2, store::Item_t child3)
    : NoaryBaseIterator<ChildrenIterator, ChildrenIteratorState >(QueryLoc())
  {
    children.push_back(child1);
    children.push_back(child2);
    children.push_back(child3);
  }
  
  void addChild(store::Item_t child)  { children.push_back(child); }
    
  bool
  nextImpl(store::Item_t& result, PlanState& aPlanState) const;
    
  virtual void
  accept(PlanIterVisitor& v) const
  {
    v.beginVisit(*this);
    v.endVisit(*this);
  }
  
protected:
  std::vector<store::Item_t> children;
};

typedef rchandle<ChildrenIterator> ChildrenIterator_t;


/****************************************************************************
 *
 * rest-get Iterator state
 *
 ****************************************************************************/

class ZorbaRestGetIteratorState : public PlanIteratorState
{
public:
  ZorbaRestGetIteratorState();
  ~ZorbaRestGetIteratorState();

  void init(PlanState&);
  void reset(PlanState&);

  CURLM* MultiHandle;
  CURL* EasyHandle;
  CurlStreamBuffer_t theStreamBuffer;
  std::auto_ptr<std::vector<std::string> > headers;
};

/****************************************************************************
 *
 * rest-get Iterator 
 *
 ****************************************************************************/

class ZorbaRestGetIterator : public NaryBaseIterator<ZorbaRestGetIterator, ZorbaRestGetIteratorState > 
{
public:                                                                  
  ZorbaRestGetIterator(const QueryLoc& loc, std::vector<PlanIter_t>& aChildren) 
    : NaryBaseIterator<ZorbaRestGetIterator, ZorbaRestGetIteratorState >(loc, aChildren)
  { } 

  bool
  nextImpl(store::Item_t& result, PlanState& aPlanState) const;
                                                                         
  virtual void 
  accept(PlanIterVisitor& v) const
  {
    v.beginVisit(*this);
    std::vector<PlanIter_t>::const_iterator iter =  theChildren.begin();
    std::vector<PlanIter_t>::const_iterator lEnd =  theChildren.end();
    for ( ; iter != lEnd; ++iter ) {
      ( *iter )->accept ( v );
    }
    v.endVisit(*this);
  }
};

/****************************************************************************
 *
 * zorba-rest post iterator
 *
 ****************************************************************************/

class ZorbaRestPostIterator : public NaryBaseIterator<ZorbaRestPostIterator, ZorbaRestGetIteratorState >
{
public:
  ZorbaRestPostIterator(const QueryLoc& loc, std::vector<PlanIter_t>& aChildren)
    : NaryBaseIterator<ZorbaRestPostIterator, ZorbaRestGetIteratorState >(loc, aChildren)
  { }

  bool
  nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  virtual void
      accept(PlanIterVisitor& v) const
  {
    v.beginVisit(*this);
    std::vector<PlanIter_t>::const_iterator iter =  theChildren.begin();
    std::vector<PlanIter_t>::const_iterator lEnd =  theChildren.end();
    for ( ; iter != lEnd; ++iter ) {
      ( *iter )->accept ( v );
    }
    v.endVisit(*this);
  }
};


} /* namespace zorba */

#endif
