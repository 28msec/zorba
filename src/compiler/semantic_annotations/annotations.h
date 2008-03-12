#ifndef ZORBA_ANNOTATIONS_H
#define ZORBA_ANNOTATIONS_H

#include <boost/shared_ptr.hpp>

namespace zorba {

class AnnotationValue;

class Annotation {
  public:
    typedef enum {
      IGNORES_SORTED_NODES,
      IGNORES_DUPLICATE_NODES,
      PRODUCES_SORTED_NODES,
      PRODUCES_DISTINCT_NODES,
    } key_t;

    typedef boost::shared_ptr<AnnotationValue> value_ref_t;

    virtual key_t getKey() const = 0;
    virtual ~Annotation() { }
};

class AnnotationValue {
  public:
    virtual ~AnnotationValue() { }
};

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

#endif /* ZORBA_ANNOTATIONS_H */
/* vim:set ts=2 sw=2: */
