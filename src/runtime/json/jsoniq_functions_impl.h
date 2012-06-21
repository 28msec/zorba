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

#ifndef ZORBA_RUNTIME_JSON_JSONIQ_FUNCTIONS_IMPL_H
#define ZORBA_RUNTIME_JSON_JSONIQ_FUNCTIONS_IMPL_H


namespace zorba 
{

#ifdef ZORBA_WITH_JSON

class JSONObjectInsertIterator : public NaryBaseIterator<JSONObjectInsertIterator,
                                                         PlanIteratorState>
{ 
protected:
  std::vector<bool> theCopyInputs;

public:
  SERIALIZABLE_CLASS(JSONObjectInsertIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONObjectInsertIterator,
  NaryBaseIterator<JSONObjectInsertIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  JSONObjectInsertIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    bool copyMode);

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif //ZORBA_WITH_JSON

}

#endif
