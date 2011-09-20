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
#ifndef ZORBA_API_ANNOTATIONS_H
#define ZORBA_API_ANNOTATIONS_H

#include <vector>
#include <bitset>
#include "common/shared_types.h"
#include "compiler/parsetree/parsenodes.h"

namespace zorba
{

class AnnotationLiteral;
class AnnotationInternal;
class AnnotationList;

typedef rchandle<AnnotationInternal> AnnotationInternal_t;
typedef rchandle<AnnotationList> AnnotationList_t;
typedef rchandle<AnnotationLiteral> AnnotationLiteral_t;

class const_expr;

/*******************************************************************************

********************************************************************************/
class AnnotationInternal : public SimpleRCObject
{
  friend class AnnotationList;

protected:
  store::Item_t                      theQName;
  std::vector<AnnotationLiteral_t>   theLiteralList;

public:
  AnnotationInternal(const store::Item_t& aExpandedQName); 

  AnnotationInternal(
    const store::Item_t& aExpandedQName,
    const std::vector<AnnotationLiteral_t>& aLiteralList); 

public:
  SERIALIZABLE_CLASS(AnnotationInternal);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationInternal, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  virtual ~AnnotationInternal() { };

  const store::Item* getQName() const;

  unsigned int getNumLiterals() const;

  const AnnotationLiteral* getLiteral(unsigned int index) const;
};



/*******************************************************************************

********************************************************************************/
class AnnotationLiteral : public SimpleRCObject
{
protected:
  store::Item_t  theLiteral;

public:
  AnnotationLiteral(const store::Item_t& aLiteral);

public:
  SERIALIZABLE_CLASS(AnnotationLiteral);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationLiteral, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  virtual ~AnnotationLiteral() {};

  store::Item_t getLiteralItem() const;
};


/*******************************************************************************

********************************************************************************/
class AnnotationList : public SimpleRCObject
{
public:
  typedef std::vector<AnnotationInternal_t> List_t;
  typedef List_t::const_iterator ListConstIter_t;

protected:
  List_t theAnnotationList;

  typedef std::bitset<StaticContextConsts::zann_end + 1> RuleBitSet;
  static std::vector<RuleBitSet> theRuleSet;

public:
  SERIALIZABLE_CLASS(AnnotationList);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationList, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AnnotationList();

	virtual ~AnnotationList();

  size_t size() const { return theAnnotationList.size(); }

  AnnotationInternal* getAnnotation(unsigned int index) const;

  void push_back(
      const store::Item_t& aExpQName,
      const std::vector<rchandle<const_expr> >& aLiterals);

  bool contains(const store::Item_t& aSearchQName) const;

  void checkConflictingDeclarations(const QueryLoc& loc) const;

public:
  static void createBuiltIn(static_context* aCtx);
};


} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
