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
#ifndef ZORBA_FUNCTIONS_ANNOTATION_H
#define ZORBA_FUNCTIONS_ANNOTATION_H

#include <vector>

#include "common/shared_types.h"
#include "compiler/semantic_annotations/annotation_holder.h"
#include "compiler/parsetree/parsenodes.h"
#include "zorba/annotation.h"

namespace zorba
{

class AnnotationLiteral;
class AnnotationInternal;
class AnnotationList;


typedef rchandle<AnnotationList> AnnotationList_t;


/*******************************************************************************
  AnnotationImpl

  the class backing up the Annotation class from the Zorba API
********************************************************************************/
class AnnotationImpl : public Annotation
{
protected:
  store::Item_t                               theQName;
  std::vector<rchandle<AnnotationLiteral> >   theLiteralList;

public:
  AnnotationImpl(const AnnotationInternal* annotation);

  virtual Item getQName() const;

  virtual unsigned int getLiteralsCount() const;

  virtual Item getLiteral(unsigned int i) const;

  virtual ~AnnotationImpl() {};
};


/*******************************************************************************

********************************************************************************/
class AnnotationLiteral : public SimpleRCObject
{
friend class AnnotationInternal;
friend class AnnotationImpl;

protected:
  store::Item_t  theLiteral;

  AnnotationLiteral(const AnnotationLiteral* literal);

  AnnotationLiteral(const StringLiteral* stringLiteral);

  AnnotationLiteral(const NumericLiteral* numericLiteral);

public:
  SERIALIZABLE_CLASS(AnnotationLiteral);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationLiteral, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  store::Item_t getLiteral() const;

  virtual ~AnnotationLiteral() {};
};


/*******************************************************************************

********************************************************************************/
class AnnotationInternal : public SimpleRCObject
{
friend class AnnotationList;

protected:
  store::Item_t                               theQName;
  std::vector<rchandle<AnnotationLiteral> >   theLiteralList;

  AnnotationInternal(const AnnotationParsenode* annotation); // used by AnnotationList

public:
  SERIALIZABLE_CLASS(AnnotationInternal);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationInternal, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  const store::Item* getQName() const;

  unsigned int getLiteralsCount() const;

  const AnnotationLiteral* getLiteral(unsigned int index) const;

  virtual ~AnnotationInternal() { };
};


/*******************************************************************************

********************************************************************************/
class AnnotationList : public SimpleRCObject
{
protected:
  std::vector<rchandle<AnnotationInternal> > theAnnotationList;

public:
  SERIALIZABLE_CLASS(AnnotationList);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationList, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AnnotationList() {};
  AnnotationList(const AnnotationListParsenode* annotations);

  ulong size() const { return (ulong)theAnnotationList.size(); }

  const AnnotationInternal* getAnnotation(unsigned int index) const;

	virtual ~AnnotationList() {}
};



} /* namespace zorba */
#endif
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
