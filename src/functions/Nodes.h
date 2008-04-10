#ifndef ZORBA_NODES_H
#define ZORBA_NODES_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class fn_local_name : public function {
  public:
    fn_local_name(const signature&);
    
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

class fn_namespace_uri : public function {
  public:
    fn_namespace_uri(const signature&);
    
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

class fn_lang : public function {
  public:
    fn_lang(const signature&);
    
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

class fn_collection : public function {
  public:
    fn_collection(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
    bool requires_dyn_ctx () const { return true; }  // TODO: rename to unfoldable()
};

}

#endif /* ZORBA_NODES_H */
