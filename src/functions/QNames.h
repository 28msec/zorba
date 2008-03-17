/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/QNames.h
 *
 */

#ifndef ZORBA_QNAMES_H
#define ZORBA_QNAMES_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba
{
  /*______________________________________________________________________
  *
  * 11 Functions Related to QNames
  *_______________________________________________________________________*/

 /*
  * 11.1.1 fn:resolve-QName
  *-----------------------*/
  class fn_resolve_qname : public function
  {
    public:
      fn_resolve_qname(const signature&);
      ~fn_resolve_qname() {}

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };
  
 /*
  * 11.1.2 fn:QName
  *-----------------------*/
  class fn_qname : public function
  {
    public:
      fn_qname(const signature&);
      ~fn_qname() {}

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };
  
/*
 * 11.2.1 op:QName-equal
 *-----------------------*/
  class op_qname_equal: public function
  {
    public:
      op_qname_equal(const signature&);
      ~op_qname_equal() {}

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 11.2.2 fn:prefix-from-QName
 *-----------------------*/
  class fn_prefix_from_qname: public function
  {
    public:
      fn_prefix_from_qname(const signature&);
      ~fn_prefix_from_qname() {}

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 11.2.3 fn:local-name-from-QName
 *-----------------------*/
  class fn_local_name_from_qname: public function
  {
    public:
      fn_local_name_from_qname(const signature&);
      ~fn_local_name_from_qname() {}

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 11.2.4 fn:namespace-uri-from-QName
 *-----------------------*/
  class fn_namespace_uri_from_qname: public function
  {
    public:
      fn_namespace_uri_from_qname(const signature&);
      ~fn_namespace_uri_from_qname() {}

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 11.2.5 fn:namespace-uri-for-prefix
 *-----------------------*/
  class fn_namespace_uri_for_prefix: public function
  {
    public:
      fn_namespace_uri_for_prefix(const signature&);
      ~fn_namespace_uri_for_prefix() {}

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };

/*
 * 11.2.6 fn:in-scope-prefixes
 *-----------------------*/
  class fn_in_scope_prefixes: public function
  {
    public:
      fn_in_scope_prefixes(const signature&);
      ~fn_in_scope_prefixes() {}

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
      xqtref_t type_check(signature&) const;
      bool validate_args(std::vector<PlanIter_t>&) const;
  };  
} /* namespace zorba */
#endif /* ZORBA_QNAMES_H */
