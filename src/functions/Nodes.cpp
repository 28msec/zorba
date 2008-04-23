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
  return new FnLocalNameIterator ( loc, argv );
}



/*******************************************************************************
  14.3 fn:namespace-uri
********************************************************************************/
fn_namespace_uri::fn_namespace_uri(const signature& sig)
  : function(sig) { }

PlanIter_t fn_namespace_uri::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnNamespaceUriIterator ( loc, argv );
}



/*******************************************************************************
  14.5 fn:lang
********************************************************************************/
fn_lang::fn_lang (const signature &sig) : function (sig) {}


PlanIter_t fn_lang::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnLangIterator(loc, argv);
}


/*******************************************************************************
  15.5.6 fn:collection
********************************************************************************/
fn_collection::fn_collection (const signature &sig) : function (sig) {}

PlanIter_t fn_collection::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnCollectionIterator(loc, argv);
}

}/* namespace zorba */
