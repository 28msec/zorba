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
#include "compiler/semantic_annotations/tsv_annotation.h"

namespace zorba {

Annotation::value_ref_t TSVAnnotationValue::TRUE_VAL = Annotation::value_ref_t(new TSVAnnotationValue(TSV_TRUE));
Annotation::value_ref_t TSVAnnotationValue::FALSE_VAL = Annotation::value_ref_t(new TSVAnnotationValue(TSV_FALSE));
Annotation::value_ref_t TSVAnnotationValue::MAYBE_VAL = Annotation::value_ref_t(new TSVAnnotationValue(TSV_MAYBE));

}
