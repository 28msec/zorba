#include "functions/Rest.h"
#include "system/globalenv.h"

#include "runtime/rest/rest.h"

namespace zorba {

rest_get_1::rest_get_1(const signature& sig) 
 : function(sig)
{}

PlanIter_t 
rest_get_1::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRestGetIterator(loc, argv);
}

xqtref_t
rest_get_1::return_type (const std::vector<xqtref_t> &arg_types) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

} /* namespace zorba */
