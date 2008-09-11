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
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/expr.h"

using namespace std;

namespace zorba {

  var_ptr_set no_free_vars;

  const var_ptr_set &get_varset_annotation (const expr *e, Annotation::key_t k) {
    assert (e != NULL);
    Annotation::value_ref_t ann = e->get_annotation (k);
    return (ann == NULL) ? no_free_vars : dynamic_cast<VarSetAnnVal *> (ann.getp())->varset;
  }

}
