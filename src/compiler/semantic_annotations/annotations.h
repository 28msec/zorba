#ifndef ZORBA_ANNOTATIONS_H
#define ZORBA_ANNOTATIONS_H

#include <boost/shared_ptr.hpp>

namespace zorba {

class AnnotationValue;

namespace Annotation {
  typedef int key_t;

  typedef boost::shared_ptr<AnnotationValue> value_ref_t;
};

class AnnotationValue {
public:
  virtual ~AnnotationValue() { }
  virtual bool equals (const AnnotationValue &other) { 
    if (typeid (other) != typeid (*this))
      return false;
    return this == &other;
  }
};

inline bool operator== (Annotation::value_ref_t v1, Annotation::value_ref_t v2) {
  if (v2 == NULL || v1 == NULL)
    return v2 == NULL && v1 == NULL;
  return v2->equals (*v1.get ());
}

}

#endif /* ZORBA_ANNOTATIONS_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
