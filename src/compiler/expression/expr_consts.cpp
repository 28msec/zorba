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

