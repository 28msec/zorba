#ifndef ZORBA_ANNOTATION_HOLDER_H
#define ZORBA_ANNOTATION_HOLDER_H

#include <map>
#include "compiler/semantic_annotations/annotations.h"
#include "compiler/expression/expr_consts.h"

namespace zorba {

class AnnotationHolder {
  private:
    expr_update_t theUpdateType;
  public:
    AnnotationHolder() : theUpdateType(SIMPLE_EXPR) {}
    virtual ~AnnotationHolder() { }
    void put_annotation(Annotation::key_t key, Annotation::value_ref_t annot);
    const Annotation::value_ref_t get_annotation(Annotation::key_t key) const;
    void remove_annotation(Annotation::key_t key);

    bool isUpdating() const { return theUpdateType == UPDATE_EXPR; }
    expr_update_t getUpdateType() const { return theUpdateType; } 
    void setUpdateType(expr_update_t aUpdateType) { theUpdateType = aUpdateType; }

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
