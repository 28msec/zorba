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
#ifndef ZORBA_FUNCTIONS_ANNOTATION_H
#define ZORBA_FUNCTIONS_ANNOTATION_H

#include <vector>

#include "common/shared_types.h"
#include "compiler/semantic_annotations/annotation_holder.h"
#include "compiler/parsetree/parsenodes.h"

namespace zorba
{

class AnnotationLiteral : public SimpleRCObject
{
public:
  SERIALIZABLE_ABSTRACT_CLASS(AnnotationLiteral);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AnnotationLiteral();
  virtual ~AnnotationLiteral();
};


class Annotation : public SimpleRCObject
{
protected:
  store::Item_t                               theQName;
  std::vector<rchandle<AnnotationLiteral> >   theLiteralList;

public:
  SERIALIZABLE_ABSTRACT_CLASS(Annotation);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  Annotation(const AnnotationParsenode* annotation);

  store::Item* getQName() const;

  virtual ~Annotation() { };
};


/*******************************************************************************

********************************************************************************/
class AnnotationList : public SimpleRCObject
{
protected:
  std::vector<rchandle<Annotation> > theAnnotationList;

public:
  SERIALIZABLE_ABSTRACT_CLASS(AnnotationList);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AnnotationList() {};

  AnnotationList(const AnnotationListParsenode* annotations);

  unsigned int size() const { return theAnnotationList.size(); }
  const Annotation* getAnnotation(unsigned int index) const;

	virtual ~AnnotationList() {}
};


typedef rchandle<AnnotationList> AnnotationList_t;


} /* namespace zorba */
#endif
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
