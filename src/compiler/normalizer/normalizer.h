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
