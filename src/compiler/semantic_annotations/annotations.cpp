#include "compiler/semantic_annotations/tsv_annotation.h"

namespace zorba {

Annotation::value_ref_t TSVAnnotationValue::TRUE_VALUE = Annotation::value_ref_t(new TSVAnnotationValue(TSV_TRUE));
Annotation::value_ref_t TSVAnnotationValue::FALSE_VALUE = Annotation::value_ref_t(new TSVAnnotationValue(TSV_FALSE));
Annotation::value_ref_t TSVAnnotationValue::UNKNOWN_VALUE = Annotation::value_ref_t(new TSVAnnotationValue(TSV_UNKNOWN));

}
