// =====================================================================================
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

#ifndef ZORBA_RUNTIME_STRINGS_STRING_IMPL_H
#define ZORBA_RUNTIME_STRINGS_STRING_IMPL_H

#include "runtime/base/narybase.h"
#include "zorbautils/checked_vector.h"
#include "zorbatypes/schema_types.h"



namespace zorba {

/**
 *
 *      fn:substring optimized for int arguments
 *
 * Author: Zorba Team
 */
class SubstringIntOptIterator: public NaryBaseIterator<SubstringIntOptIterator, PlanIterator>
{
public:
    SERIALIZABLE_CLASS(SubstringIntOptIterator,
      NaryBaseIterator<SubstringIntOptIterator, PlanIteratorState>);

    void serialize( ::zorba::serialization::Archiver& ar)
    {
      serialize_baseclass(ar,
      (NaryBaseIterator<SubstringIntOptIterator, PlanIteratorState>)*this);
    }

    SubstringIntOptIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children)
      :
      NaryBaseIterator<SubstringIntOptIterator, PlanIteratorState>(sctx, loc, children)
    {}

    virtual ~SubstringIterator();

    void accept(PlanIterVisitor& v) const;

    bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

}

#endif
