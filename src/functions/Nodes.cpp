#include "functions/Nodes.h"
#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "runtime/nodes/NodesImpl.h"

#include "store/api/iterator.h"

using namespace std;

namespace zorba {

/*******************************************************************************
  14.2 fn:local-name
********************************************************************************/

  fn_local_name::fn_local_name(const signature& sig)
  : function(sig) { }

PlanIter_t fn_local_name::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
    ZORBA_ERROR_LOC( ZorbaError::XPST0017, loc);
  
  return new FnLocalNameIterator ( loc, argv );
}

xqtref_t fn_local_name::type_check(signature& sig) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_QUESTION;
}

bool fn_local_name::validate_args(std::vector<PlanIter_t>& argv) const
{
  return argv.size() == 1;
}

/*******************************************************************************
  14.3 fn:namespace-uri
********************************************************************************/
fn_namespace_uri::fn_namespace_uri(const signature& sig)
  : function(sig) { }

PlanIter_t fn_namespace_uri::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
    ZORBA_ERROR_LOC( ZorbaError::XPST0017, loc);
  
  return new FnNamespaceUriIterator ( loc, argv );
}

xqtref_t fn_namespace_uri::type_check(signature& sig) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_QUESTION;
}

bool fn_namespace_uri::validate_args(std::vector<PlanIter_t>& argv) const
{
  return argv.size() == 1;
}

/*******************************************************************************
  14.5 fn:lang
********************************************************************************/
fn_lang::fn_lang (const signature &sig) : function (sig) {}

xqtref_t fn_lang::type_check(signature&) const
{
  return GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE;
}

PlanIter_t fn_lang::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
    ZORBA_ERROR_LOC( ZorbaError::XPST0017, loc);

  return new FnLangIterator(loc, argv);
}

bool fn_lang::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1 || argv.size() == 2);
}

/*******************************************************************************
  15.5.6 fn:collection
********************************************************************************/
fn_collection::fn_collection (const signature &sig) : function (sig) {}

xqtref_t fn_collection::type_check(signature&) const
{
  return GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR;
}

PlanIter_t fn_collection::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  if (!validate_args(argv))
    ZORBA_ERROR_LOC( ZorbaError::XPST0017, loc);

  return new FnCollectionIterator(loc, argv);
}

bool fn_collection::validate_args(vector<PlanIter_t>& argv) const
{
  return (argv.size() == 1);
}
}/* namespace zorba */
