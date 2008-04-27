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
#include <string>
#include "compiler/expression/expr_consts.h"

namespace zorba {

std::string toString(match_test_t a)
{
  switch (a){
  case match_no_test:
    return "match_no_test";
  case match_name_test:
    return "match_name_test";
  case match_doc_test:
    return "match_doc_test";
  case match_elem_test:
    return "match_elem_test";
  case match_attr_test:
    return "match_attr_test";
  case match_xs_elem_test:
    return "match_xs_elem_test";
  case match_xs_attr_test:
    return "match_xs_attr_test";
  case match_pi_test:
    return "match_pi_test";
  case match_comment_test:
    return "match_comment_test";
  case match_text_test:
    return "match_text_test";
  case match_anykind_test:
    return "match_anykind_test";
  }
  return "";
}

}

