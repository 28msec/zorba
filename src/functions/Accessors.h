/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#ifndef XQP_ACCESSORS_H
#define XQP_ACCESSORS_H

#include "context/common.h"
#include "functions/function.h"

namespace xqp {

	class fn_data_func : public function
	{
		public:
			fn_data_func ( const signature& );
			~fn_data_func() {}

		public:
			PlanIter_t operator() ( const yy::location& loc, std::vector<PlanIter_t>& ) const;
            xqtref_t type_check ( signature& ) const;
			bool validate_args ( std::vector<PlanIter_t>& ) const;
	};


  class fn_root_func : public function
	{
		public:
			fn_root_func(const signature& s);
			~fn_root_func() {}

		public:
			PlanIter_t operator() (const yy::location& loc, std::vector<PlanIter_t>& ) const;
            xqtref_t type_check(signature& s) const;
			bool validate_args(std::vector<PlanIter_t>& ) const;
	};

  class fn_nodename_func : public function
	{
		public:
			fn_nodename_func(const signature& s);
			~fn_nodename_func() {}

		public:
			PlanIter_t operator() (const yy::location& loc, std::vector<PlanIter_t>& ) const;
            xqtref_t type_check(signature& s) const;
			bool validate_args(std::vector<PlanIter_t>& ) const;
	};

  class fn_name_func : public function
	{
		public:
			fn_name_func(const signature& s);
			~fn_name_func() {}

		public:
			PlanIter_t operator() (const yy::location& loc, std::vector<PlanIter_t>& ) const;
            xqtref_t type_check(signature& s) const;
			bool validate_args(std::vector<PlanIter_t>& ) const;
	};
} /* namespace xqp */

#endif /* XQP_ACCESSORS_H */
