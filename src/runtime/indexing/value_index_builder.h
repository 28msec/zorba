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
#ifndef ZORBA_VALUE_INDEX_BUILDER_H
#define ZORBA_VALUE_INDEX_BUILDER_H

#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"
#include "indexing/value_index.h"

namespace zorba {

class CreateValueIndex : public UnaryBaseIterator<CreateValueIndex, PlanIteratorState> {
  public:
    CreateValueIndex(const QueryLoc& loc, PlanIter_t aChild)
      : UnaryBaseIterator<CreateValueIndex, PlanIteratorState>(loc, aChild) { }

    virtual ~CreateValueIndex() { }

    bool nextImpl(store::Item_t& result, PlanState& planState) const;

    virtual void accept(PlanIterVisitor& v) const;
};

class DropValueIndex : public UnaryBaseIterator<DropValueIndex, PlanIteratorState> {
  public:
    DropValueIndex(const QueryLoc& loc, PlanIter_t aChild)
      : UnaryBaseIterator<DropValueIndex, PlanIteratorState>(loc, aChild) { }

    virtual ~DropValueIndex() { }

    bool nextImpl(store::Item_t& result, PlanState& planState) const;

    virtual void accept(PlanIterVisitor& v) const;
};

class ValueIndexInsertSessionOpener : public UnaryBaseIterator<ValueIndexInsertSessionOpener, PlanIteratorState> {
  public:
    ValueIndexInsertSessionOpener(const QueryLoc& loc, PlanIter_t aChild)
      : UnaryBaseIterator<ValueIndexInsertSessionOpener, PlanIteratorState>(loc, aChild) { }

    virtual ~ValueIndexInsertSessionOpener() { }

    bool nextImpl(store::Item_t& result, PlanState& planState) const;

    virtual void accept(PlanIterVisitor& v) const;
};

class ValueIndexInsertSessionCloser : public UnaryBaseIterator<ValueIndexInsertSessionCloser, PlanIteratorState> {
  public:
    ValueIndexInsertSessionCloser(const QueryLoc& loc, PlanIter_t aChild)
      : UnaryBaseIterator<ValueIndexInsertSessionCloser, PlanIteratorState>(loc, aChild) { }

    virtual ~ValueIndexInsertSessionCloser() { }

    bool nextImpl(store::Item_t& result, PlanState& planState) const;

    virtual void accept(PlanIterVisitor& v) const;
};

class ValueIndexBuilderState : public PlanIteratorState {
  public:
    ValueIndexInsertSession_t theSession;

    void init(PlanState&);
    void reset(PlanState&);
};

class ValueIndexBuilder : public NaryBaseIterator<ValueIndexBuilder, ValueIndexBuilderState> {
  public:
    ValueIndexBuilder(const QueryLoc& loc, std::vector<PlanIter_t>& aChildren)
      : NaryBaseIterator<ValueIndexBuilder, ValueIndexBuilderState>(loc, aChildren) { }

    virtual ~ValueIndexBuilder() { }

    bool nextImpl(store::Item_t& result, PlanState& planState) const;

    virtual void accept(PlanIterVisitor& v) const;
};

}

#endif /* ZORBA_VALUE_INDEX_BUILDER_H */
/* vim:set ts=2 sw=2: */
