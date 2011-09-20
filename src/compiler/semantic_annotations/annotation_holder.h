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
#ifndef ZORBA_COMPILER_ANNOTATION_HOLDER
#define ZORBA_COMPILER_ANNOTATION_HOLDER

#include <map>
#include "compiler/semantic_annotations/annotations.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/expression/expr_consts.h"

namespace zorba {

class AnnotationHolder : public SimpleRCObject
{
protected:
  typedef std::map<Annotations::Key, AnnotationValue_t> annotations_t;

  annotations_t m_annotations;

public:
  SERIALIZABLE_ABSTRACT_CLASS(AnnotationHolder)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationHolder, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AnnotationHolder() {}

  virtual ~AnnotationHolder() {}

  void put_annotation(Annotations::Key key, AnnotationValue_t annot);

  const AnnotationValue_t get_annotation(Annotations::Key key) const;

  void remove_annotation(Annotations::Key key);
};

}

#endif /* ZORBA_ANNOTATION_HOLDER_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
