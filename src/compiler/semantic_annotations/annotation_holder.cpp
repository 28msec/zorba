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
#include "stdafx.h"

#include "compiler/semantic_annotations/annotation_holder.h"

namespace zorba {


void AnnotationHolder::serialize(::zorba::serialization::Archiver& ar)
{
  //ar & m_annotations;
}


void AnnotationHolder::put_annotation(
    Annotations::Key key,
    AnnotationValue_t value)
{
  m_annotations[key] = value;
}


const AnnotationValue_t AnnotationHolder::get_annotation(
    Annotations::Key key) const
{
  annotations_t::const_iterator i = m_annotations.find(key);
  if (i == m_annotations.end()) {
    return AnnotationValue_t();
  }
  return i->second;
}


void AnnotationHolder::remove_annotation(Annotations::Key key)
{
  annotations_t::iterator i = m_annotations.find(key);
  if (i != m_annotations.end()) {
    m_annotations.erase(i);
  }
}

}
/* vim:set et sw=2 ts=2: */
