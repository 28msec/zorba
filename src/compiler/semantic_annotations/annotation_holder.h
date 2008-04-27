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
#ifndef ZORBA_ANNOTATION_HOLDER_H
#define ZORBA_ANNOTATION_HOLDER_H

#include <map>
#include "compiler/semantic_annotations/annotations.h"
#include "compiler/expression/expr_consts.h"

namespace zorba {

class AnnotationHolder {
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
    expr_update_t theUpdateType;
};

}

#endif /* ZORBA_ANNOTATION_HOLDER_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
