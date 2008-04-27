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
#ifndef ZORBA_ANNOTATION_KEYS_H
#define ZORBA_ANNOTATION_KEYS_H

namespace zorba {

namespace AnnotationKey {

enum {
  IGNORES_SORTED_NODES,
  IGNORES_DUP_NODES,
  PRODUCES_SORTED_NODES,
  PRODUCES_DISTINCT_NODES,
  
  FREE_VARS,

  LET_VAR_NODEID_ANALYSIS,

  EXPENSIVE_OP,
  UNFOLDABLE_OP,
  NONDISCARDABLE_EXPR,
  
  MAX_ANNOTATION
};

}

}

#endif  // ZORBA_ANNOTATION_KEYS_H

/*
 * Local variables:
 * mode: c++
 * End:
 */
