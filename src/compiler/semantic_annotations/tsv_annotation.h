#include "compiler/semantic_annotations/annotations.h"
#include "compiler/semantic_annotations/annotation_holder.h"

namespace zorba {

class TSVAnnotationValue : public AnnotationValue {
  public:
    static Annotation::value_ref_t TRUE_VALUE;
    static Annotation::value_ref_t FALSE_VALUE;
    static Annotation::value_ref_t UNKNOWN_VALUE;

    typedef enum {
      TSV_TRUE,
      TSV_FALSE,
      TSV_UNKNOWN
    } tsv_t;

    tsv_t getValue() const { return m_value; }

  // pessimistic
  static void update_annotation (AnnotationHolder *e, Annotation::key_t k, Annotation::value_ref_t v) {
    Annotation::value_ref_t oldv = e->get_annotation (k);
    if (oldv == FALSE_VALUE)
      v = FALSE_VALUE;
    else if (oldv == UNKNOWN_VALUE || v == NULL)
      v = UNKNOWN_VALUE;
        
    e->put_annotation (k, v);
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
