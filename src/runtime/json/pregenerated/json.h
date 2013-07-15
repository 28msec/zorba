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
class JSONStringtoXMLInternal : public NaryBaseIterator<JSONStringtoXMLInternal, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(JSONStringtoXMLInternal);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(JSONStringtoXMLInternal,
    NaryBaseIterator<JSONStringtoXMLInternal, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  JSONStringtoXMLInternal(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<JSONStringtoXMLInternal, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~JSONStringtoXMLInternal();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    Function to serialize json/jsonml xdm to string
 *  
 * Author: Zorba Team
 */
class XMLtoJSONStringInternal : public NaryBaseIterator<XMLtoJSONStringInternal, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(XMLtoJSONStringInternal);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(XMLtoJSONStringInternal,
    NaryBaseIterator<XMLtoJSONStringInternal, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  XMLtoJSONStringInternal(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<XMLtoJSONStringInternal, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~XMLtoJSONStringInternal();

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
