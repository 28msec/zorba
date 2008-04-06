#ifndef ZORBA_SINGLE_SEQ_FUNC_H
#define ZORBA_SINGLE_SEQ_FUNC_H

#include "functions/function.h"

namespace zorba {

class single_seq_function : public function {
protected:
  int src;
  
public:
  single_seq_function (const signature &sig, int src_ = 0) : function (sig), src (src_) {}
  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
  void compute_annotation (AnnotationHolder *parent, std::vector<AnnotationHolder *> &kids, Annotation::key_t k) const;
};

}

#endif
