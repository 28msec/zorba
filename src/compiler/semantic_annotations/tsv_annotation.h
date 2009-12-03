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

#include "compiler/semantic_annotations/annotations.h"
#include "compiler/semantic_annotations/annotation_holder.h"

namespace zorba 
{


class TSVAnnotationValue : public AnnotationValue 
{
  // Dummy to make the compiler happy
  friend class Foo;

public:
  typedef enum 
  {
    TSV_TRUE,
    TSV_FALSE,
    TSV_MAYBE
  } tsv_t;


  static AnnotationValue_t TRUE_VAL;
  static AnnotationValue_t FALSE_VAL;
  static AnnotationValue_t MAYBE_VAL;

private:
  tsv_t  m_value;

public:
  tsv_t getValue() const { return m_value; }

  // pessimistic
  static void update_annotation(
        AnnotationHolder* e,
        Annotations::Key k,
        AnnotationValue_t v) 
  {
    AnnotationValue_t oldv = e->get_annotation(k);

    if (oldv.getp() == FALSE_VAL.getp())
      v = FALSE_VAL;

    else if (oldv.getp() == MAYBE_VAL.getp() || v == NULL)
      v = MAYBE_VAL;
        
    e->put_annotation(k, v);
  }


  static AnnotationValue_t from_bool(bool x) 
  {
    return x ? TRUE_VAL : FALSE_VAL;
  }


  static AnnotationValue_t and3(
        AnnotationValue_t v1,
        AnnotationValue_t v2)
  {
    if (v1.getp() == FALSE_VAL.getp() || v2.getp() == FALSE_VAL.getp()) 
      return FALSE_VAL;

    if (v1.getp() == MAYBE_VAL.getp() || v2.getp() == MAYBE_VAL.getp()) 
      return MAYBE_VAL;

    return TRUE_VAL;
  }


  static AnnotationValue_t or3(
        AnnotationValue_t v1,
        AnnotationValue_t v2)
  {
    if (v1.getp() == TRUE_VAL.getp() || v2.getp() == TRUE_VAL.getp()) 
      return TRUE_VAL;

    if (v1.getp() == MAYBE_VAL.getp() || v2.getp() == MAYBE_VAL.getp())
      return MAYBE_VAL;

    return FALSE_VAL;
  }

private:
  TSVAnnotationValue(tsv_t value) : m_value(value) { }
};

}

/*
 * Local variables:
 * mode: c++
 * End:
 */
