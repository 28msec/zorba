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
#include "compiler/semantic_annotations/annotation_holder.h"

namespace zorba {

void AnnotationHolder::put_annotation(Annotation::key_t key, Annotation::value_ref_t value)
{
  m_annotations[key] = value;
}

const Annotation::value_ref_t AnnotationHolder::get_annotation(Annotation::key_t key) const
{
  annotations_t::const_iterator i = m_annotations.find(key);
  if (i == m_annotations.end()) {
    return Annotation::value_ref_t();
  }
  return i->second;
}

void AnnotationHolder::remove_annotation(Annotation::key_t key)
{
  annotations_t::iterator i = m_annotations.find(key);
  if (i != m_annotations.end()) {
    m_annotations.erase(i);
  }
}

}
/* vim:set ts=2 sw=2: */
