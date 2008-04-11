#include "compiler/semantic_annotations/tsv_annotation.h"

namespace zorba {

Annotation::value_ref_t TSVAnnotationValue::TRUE_VAL = Annotation::value_ref_t(new TSVAnnotationValue(TSV_TRUE));
Annotation::value_ref_t TSVAnnotationValue::FALSE_VAL = Annotation::value_ref_t(new TSVAnnotationValue(TSV_FALSE));
Annotation::value_ref_t TSVAnnotationValue::MAYBE_VAL = Annotation::value_ref_t(new TSVAnnotationValue(TSV_MAYBE));

}
