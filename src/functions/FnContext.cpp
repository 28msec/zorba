/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska
 */

#include "functions/FnContext.h"
#include "system/globalenv.h"
#include "util/zorba.h"
#include "runtime/fncontext/FnContextImpl.h"
#include "runtime/core/item_iterator.h"

namespace xqp
{

  /* start class CtxVariable */
   ctx_variable::ctx_variable ( const signature& sig ) :function ( sig ) {}

   PlanIter_t ctx_variable::operator() (
      const yy::location& loc,
      vector<PlanIter_t>& argv ) const
  {
    // TODO: undo this hack
    return new CtxVariableIterator ( loc, argv[0].cast<SingletonIterator> ()->getValue ()->getStringProperty () );
  }

  TypeSystem::xqtref_t ctx_variable::type_check (
      signature& sig ) const
  {
    return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
  }

  bool ctx_variable::validate_args ( vector<PlanIter_t>& argv ) const
  {
    return ( argv.size() == 1 );
  }

  /* end class CtxVariable */
}
