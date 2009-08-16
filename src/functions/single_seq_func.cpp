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

#include "types/typemanagerimpl.h"

#include "functions/single_seq_func.h"

#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"

namespace zorba 
{

xqtref_t single_seq_function::return_type(const std::vector<xqtref_t>& arg_types) const
{
  return arg_types[src]; 
}


void single_seq_function::compute_annotation(
    AnnotationHolder* parent,
    std::vector<AnnotationHolder *>& kids,
    Annotation::key_t k) const 
{
  switch (k) 
  {
  case AnnotationKey::IGNORES_SORTED_NODES:
  case AnnotationKey::IGNORES_DUP_NODES:
    TSVAnnotationValue::update_annotation(kids[src], k, parent->get_annotation(k));
    break;
  case AnnotationKey::PRODUCES_DISTINCT_NODES:
  case AnnotationKey::PRODUCES_SORTED_NODES:
    parent->put_annotation (k, kids[src]->get_annotation(k));
    break;
  default: break;
  }
}


xqtref_t single_seq_opt_function::return_type(const std::vector<xqtref_t>& arg_types) const
{
  xqtref_t outType = arg_types[src]->get_manager()->
                     create_type_x_quant(*arg_types[src], TypeConstants::QUANT_QUESTION);
  return outType;
}



}

