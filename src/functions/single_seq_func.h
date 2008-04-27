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
