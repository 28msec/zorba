/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#ifndef ZORBA_RUNTIME_JSON_JSON_H
#define ZORBA_RUNTIME_JSON_JSON_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"


namespace zorba {

/**
 * 
 *    function for parsing strings into json-xdm
 *  
 * Author: Zorba Team
 */
class JSONtoXMLInternal : public NaryBaseIterator<JSONtoXMLInternal, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONtoXMLInternal);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONtoXMLInternal,
    NaryBaseIterator<JSONtoXMLInternal, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONtoXMLInternal(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONtoXMLInternal, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONtoXMLInternal();

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    Function to serialize json/jsonml xdm to string
 *  
 * Author: Zorba Team
 */
class XMLtoJSONInternal : public NaryBaseIterator<XMLtoJSONInternal, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(XMLtoJSONInternal);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(XMLtoJSONInternal,
    NaryBaseIterator<XMLtoJSONInternal, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  XMLtoJSONInternal(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<XMLtoJSONInternal, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~XMLtoJSONInternal();

  zstring getNameAsString() const;

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
