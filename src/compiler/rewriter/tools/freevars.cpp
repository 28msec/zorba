#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/expr.h"

using namespace std;

namespace zorba {

  var_ptr_set no_free_vars;

  const var_ptr_set &get_varset_annotation (const expr *e, Annotation::key_t k) {
    assert (e != NULL);
    Annotation::value_ref_t ann = e->get_annotation (k);
    return (ann == NULL) ? no_free_vars : dynamic_cast<VarSetAnnVal *> (ann.get ())->varset;
  }

}
