#include "compiler/semantic_annotations/annotations.h"
#include "compiler/semantic_annotations/annotation_holder.h"

namespace zorba {

class TSVAnnotationValue : public AnnotationValue {
  public:
    static Annotation::value_ref_t TRUE_VAL;
    static Annotation::value_ref_t FALSE_VAL;
    static Annotation::value_ref_t MAYBE_VAL;

    typedef enum {
      TSV_TRUE,
      TSV_FALSE,
      TSV_MAYBE
    } tsv_t;

    tsv_t getValue() const { return m_value; }

  // pessimistic
  static void update_annotation (AnnotationHolder *e, Annotation::key_t k, Annotation::value_ref_t v) {
    Annotation::value_ref_t oldv = e->get_annotation (k);
    if (oldv == FALSE_VAL)
      v = FALSE_VAL;
    else if (oldv == MAYBE_VAL || v == NULL)
      v = MAYBE_VAL;
        
    e->put_annotation (k, v);
  }

  static Annotation::value_ref_t from_bool (bool x) {
    return x ? TRUE_VAL : FALSE_VAL;
  }

  private:
    TSVAnnotationValue(tsv_t value)
      : m_value(value) { }

    // Dummy to make the compiler happy
    friend class Foo;

    tsv_t m_value;
};

}

/*
 * Local variables:
 * mode: c++
 * End:
 */
