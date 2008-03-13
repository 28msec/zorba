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
