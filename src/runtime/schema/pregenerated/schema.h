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
#ifndef ZORBA_RUNTIME_SCHEMA_SCHEMA_H
#define ZORBA_RUNTIME_SCHEMA_SCHEMA_H


#include "common/shared_types.h"
#include "runtime/base/unarybase.h"


#include "runtime/base/narybase.h"
#include "compiler/parser/parse_constants.h"


namespace zorba {
class TypeManager;
#ifndef ZORBA_NO_XMLSCHEMA
/**
 * iterator backing the validate expression
 * Author: Zorba Team
 */
class ValidateIterator : public UnaryBaseIterator<ValidateIterator, PlanIteratorState>
{ 
protected:
  enum ParseConstants::validation_mode_t validationMode; //
  rchandle<TypeManager> typemgr; //
  store::Item_t typeName; //
public:
  SERIALIZABLE_CLASS(ValidateIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ValidateIterator,
    UnaryBaseIterator<ValidateIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ValidateIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child,
    enum ParseConstants::validation_mode_t aValidationMode,
    TypeManager* aTypemgr,
    store::Item* aTypeName)
    : 
    UnaryBaseIterator<ValidateIterator, PlanIteratorState>(sctx, loc, child),
    validationMode(aValidationMode),
    typemgr(aTypemgr),
    typeName(aTypeName)
  {}

  virtual ~ValidateIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};

#endif

/**
 * iterator backing the validate-updating function
 * Author: Zorba Team
 */
class ZorbaValidateInPlaceIterator : public UnaryBaseIterator<ZorbaValidateInPlaceIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaValidateInPlaceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaValidateInPlaceIterator,
    UnaryBaseIterator<ZorbaValidateInPlaceIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaValidateInPlaceIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child)
    : 
    UnaryBaseIterator<ZorbaValidateInPlaceIterator, PlanIteratorState>(sctx, loc, child)
  {}

  virtual ~ZorbaValidateInPlaceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * iterator backing the schema-type function
 * Author: Zorba Team
 */
class ZorbaSchemaTypeIterator : public NaryBaseIterator<ZorbaSchemaTypeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaSchemaTypeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaSchemaTypeIterator,
    NaryBaseIterator<ZorbaSchemaTypeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaSchemaTypeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaSchemaTypeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaSchemaTypeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * iterator backing the schema:is-validated function
 * Author: Zorba Team
 */
class ZorbaIsValidatedIterator : public NaryBaseIterator<ZorbaIsValidatedIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(ZorbaIsValidatedIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorbaIsValidatedIterator,
    NaryBaseIterator<ZorbaIsValidatedIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  ZorbaIsValidatedIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<ZorbaIsValidatedIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~ZorbaIsValidatedIterator();

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
