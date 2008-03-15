#include "compiler/semantic_annotations/annotations.h"

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
