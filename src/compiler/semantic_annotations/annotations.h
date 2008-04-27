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
  virtual ~AnnotationValue() {}
  virtual bool equals (const AnnotationValue &other) { 
    return this == &other;
  }
};

class IntAnnotationValue : public AnnotationValue {
public:
  int n;
  
  IntAnnotationValue (int n_) : n (n_) {}
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
