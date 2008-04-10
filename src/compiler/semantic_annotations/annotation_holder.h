#ifndef ZORBA_ANNOTATION_HOLDER_H
#define ZORBA_ANNOTATION_HOLDER_H

#include <map>
#include "compiler/semantic_annotations/annotations.h"

namespace zorba {

class AnnotationHolder {
  private:
    bool theIsUpdating;
  public:
    AnnotationHolder() : theIsUpdating(false) {}
    virtual ~AnnotationHolder() { }
    void put_annotation(Annotation::key_t key, Annotation::value_ref_t annot);
    const Annotation::value_ref_t get_annotation(Annotation::key_t key) const;
    void remove_annotation(Annotation::key_t key);

    virtual bool isUpdating() const { return theIsUpdating; }
    void setUpdating(bool aIsUpdating) { theIsUpdating = aIsUpdating; }

  protected:
    typedef std::map<Annotation::key_t, Annotation::value_ref_t> annotations_t;
    annotations_t m_annotations;
};

}

#endif /* ZORBA_ANNOTATION_HOLDER_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
