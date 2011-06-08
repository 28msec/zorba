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
#ifndef ZORBA_API_ANNOTATION_IMPL
#define ZORBA_API_ANNOTATION_IMPL

#include <vector>
#include <zorba/annotation.h>

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


/*******************************************************************************
  AnnotationImpl

  the class backing up the Annotation class from the Zorba API
********************************************************************************/
class AnnotationImpl : public Annotation
{
protected:
  
  AnnotationInternal_t  theAnnotation;

public:
  AnnotationImpl(AnnotationInternal* ann) 
    : 
    theAnnotation(ann)
  {
  }

  ~AnnotationImpl() {};

  Item getQName() const;

  unsigned int getLiteralsCount() const; 

  Item getLiteral(unsigned int i) const;
};


/*******************************************************************************

********************************************************************************/
class AnnotationInternal : public SimpleRCObject
{
  friend class AnnotationList;

protected:
  store::Item_t                      theQName;
  std::vector<AnnotationLiteral_t>   theLiteralList;

protected:
  AnnotationInternal(const AnnotationParsenode* annotation); 

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
  friend class AnnotationInternal;
  friend class AnnotationImpl;

protected:
  store::Item_t  theLiteral;

protected:
  AnnotationLiteral(const AnnotationLiteral* literal);

  AnnotationLiteral(const StringLiteral* stringLiteral);

  AnnotationLiteral(const NumericLiteral* numericLiteral);

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
protected:
  std::vector<AnnotationInternal_t> theAnnotationList;

public:
  SERIALIZABLE_CLASS(AnnotationList);
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationList, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AnnotationList() {};

	virtual ~AnnotationList() {}

  AnnotationList(const AnnotationListParsenode* annotations);

  ulong size() const { return (ulong)theAnnotationList.size(); }

  AnnotationInternal* getAnnotation(unsigned int index) const;
};



} /* namespace zorba */
#endif
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
