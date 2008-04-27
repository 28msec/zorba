/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
 /*
  * 11.1.2 fn:QName
  *-----------------------*/
  class fn_qname : public function
  {
    public:
      fn_qname(const signature&);

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };
  
/*
 * 11.2.1 op:QName-equal
 *-----------------------*/
  class op_qname_equal: public function
  {
    public:
      op_qname_equal(const signature&);

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

/*
 * 11.2.2 fn:prefix-from-QName
 *-----------------------*/
  class fn_prefix_from_qname: public function
  {
    public:
      fn_prefix_from_qname(const signature&);

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

/*
 * 11.2.3 fn:local-name-from-QName
 *-----------------------*/
  class fn_local_name_from_qname: public function
  {
    public:
      fn_local_name_from_qname(const signature&);

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

/*
 * 11.2.4 fn:namespace-uri-from-QName
 *-----------------------*/
  class fn_namespace_uri_from_qname: public function
  {
    public:
      fn_namespace_uri_from_qname(const signature&);

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

/*
 * 11.2.5 fn:namespace-uri-for-prefix
 *-----------------------*/
  class fn_namespace_uri_for_prefix: public function
  {
    public:
      fn_namespace_uri_for_prefix(const signature&);

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

/*
 * 11.2.6 fn:in-scope-prefixes
 *-----------------------*/
  class fn_in_scope_prefixes: public function
  {
    public:
      fn_in_scope_prefixes(const signature&);

    public:
      PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };  
} /* namespace zorba */
#endif /* ZORBA_QNAMES_H */
