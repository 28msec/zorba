#include "system/globalenv.h"
#include "functions/Constructor.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/constructors.h"

namespace xqp
{
  /* begin class op_enclosed_expr */
  op_enclosed_expr::op_enclosed_expr (
      const signature& sig )
      :
      function ( sig )
  {
  }

  PlanIter_t op_enclosed_expr::operator() (
      const yy::location& loc,
      vector<PlanIter_t>& argv ) const
  {
    return new EnclosedIterator ( loc, argv[0] );
  }

  TypeSystem::xqtref_t op_enclosed_expr::type_check (
      signature& sig ) const
  {
    return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }

  bool op_enclosed_expr::validate_args (
      vector<PlanIter_t>& argv ) const
  {
    return ( argv.size() ==1 );
  }
  /* end class op_enclosed_expr */
  
  /* begin class op_enclosed_expr */
  op_docfilter_expr::op_docfilter_expr (
      const signature& sig )
      :
      function ( sig )
  {
  }
  
  PlanIter_t op_docfilter_expr::operator() (
      const yy::location& loc,
      vector<PlanIter_t>& argv ) const
  {
    return new DocFilterIterator ( loc, argv[0] );
  }
  
  TypeSystem::xqtref_t op_docfilter_expr::type_check (
      signature& sig ) const
  {
    return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }
  
  bool op_docfilter_expr::validate_args (
      vector<PlanIter_t>& argv ) const
  {
    return ( argv.size() ==1 );
  }
  /* end class op_enclosed_expr */
} /* namespace xqp */
