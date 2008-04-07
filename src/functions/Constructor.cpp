#include "system/globalenv.h"
#include "functions/Constructor.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/constructors.h"

namespace zorba
{
  /* begin class op_enclosed_expr */
  op_enclosed_expr::op_enclosed_expr (
      const signature& sig )
      :
      function ( sig )
  {
  }

  PlanIter_t op_enclosed_expr::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann ) const
  {
    return new EnclosedIterator ( loc, argv[0] );
  }
  /* end class op_enclosed_expr */
  
  
} /* namespace zorba */
