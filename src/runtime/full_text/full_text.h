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
#pragma once
#ifndef ZORBA_FULL_TEXT_FTCONTAINS_ITERATOR_H
#define ZORBA_FULL_TEXT_FTCONTAINS_ITERATOR_H

/******************************************************************************
 *                                                                            *
 * This USED to be a generated file, but isn't currently because the formerly *
 * corresponding .xml file with the same name wasn't sufficiently flexible.   *
 *                                                                            *
 ******************************************************************************/

#include "common/shared_types.h"
#include "compiler/expression/ftnode.h"
#include "runtime/base/binarybase.h"
#include "zorbatypes/schema_types.h"

namespace zorba {

class FTContainsIterator :
  public BinaryBaseIterator<FTContainsIterator,PlanIteratorState>
{ 
  typedef BinaryBaseIterator<FTContainsIterator,PlanIteratorState> base_type;
public:
  SERIALIZABLE_CLASS(FTContainsIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(FTContainsIterator,base_type);
  void serialize( serialization::Archiver& );

  typedef std::list<PlanIter_t> sub_iter_list_t;

  FTContainsIterator(
    static_context*,
    QueryLoc const&,
    PlanIter_t &search_ctx,
    PlanIter_t &ftignore_option,
    ftnode_t const &ftselection,
    sub_iter_list_t&
  );
  virtual ~FTContainsIterator();

  // inherited
  void accept( PlanIterVisitor& ) const;
  uint32_t getStateSizeOfSubtree() const;
  void openImpl( PlanState&, uint32_t& );
  bool nextImpl( store::Item_t&, PlanState& ) const;
  void resetImpl( PlanState& ) const;
  void closeImpl( PlanState& );

private:
  ftnode_t ftselection_;
  sub_iter_list_t sub_iters_;
};

}
#endif  /* ZORBA_FULL_TEXT_FTCONTAINS_ITERATOR_H */
/* vim:set et sw=2 ts=2: */
