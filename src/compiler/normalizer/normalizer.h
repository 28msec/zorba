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
#ifndef ZORBA_NORMALIZER_H
#define ZORBA_NORMALIZER_H

#include "common/shared_types.h"
#include "compiler/api/compilercb.h"
#include "compiler/expression/expr_visitor.h"

namespace zorba {

void normalize_expr_tree (const char *, CompilerCB*, expr_t root);

} /* namespace zorba */
#endif /* ZORBA_NORMALIZER_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
