/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#ifndef XQP_BOOLEAN_H
#define XQP_BOOLEAN_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace xqp
{
	class GenericOpComparison : public function
	{
		public:
			GenericOpComparison ( const signature&);
			virtual ~GenericOpComparison() {}

			virtual PlanIter_t operator() ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
			virtual xqtref_t type_check ( signature& ) const;
			virtual bool validate_args ( std::vector<PlanIter_t>& ) const;
			
		protected:
			virtual PlanIter_t createIterator( const QueryLoc& loc, std::vector<PlanIter_t>& ) const = 0;
	};
	
	/*----------------------------------- generic comparison --------------------------------*/
	class op_equal : public GenericOpComparison
	{
	public:
		op_equal( const signature&);
		virtual ~op_equal() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_not_equal : public GenericOpComparison
	{
	public:
		op_not_equal( const signature&);
		virtual ~op_not_equal() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_greater : public GenericOpComparison
	{
	public:
		op_greater( const signature&);
		virtual ~op_greater() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_greater_equal : public GenericOpComparison
	{
	public:
		op_greater_equal( const signature&);
		virtual ~op_greater_equal() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_less : public GenericOpComparison
	{
	public:
		op_less( const signature&);
		virtual ~op_less() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_less_equal : public GenericOpComparison
	{
	public:
		op_less_equal( const signature&);
		virtual ~op_less_equal() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	/*----------------------------------- value comparison --------------------------------*/
	class op_value_equal : public GenericOpComparison
	{
	public:
		op_value_equal( const signature&);
		virtual ~op_value_equal() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_value_not_equal : public GenericOpComparison
	{
	public:
		op_value_not_equal( const signature&);
		virtual ~op_value_not_equal() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_value_greater : public GenericOpComparison
	{
	public:
		op_value_greater( const signature&);
		virtual ~op_value_greater() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_value_greater_equal : public GenericOpComparison
	{
	public:
		op_value_greater_equal( const signature&);
		virtual ~op_value_greater_equal() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_value_less : public GenericOpComparison
	{
	public:
		op_value_less( const signature&);
		virtual ~op_value_less() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_value_less_equal : public GenericOpComparison
	{
	public:
		op_value_less_equal( const signature&);
		virtual ~op_value_less_equal() {}
	protected:
		virtual PlanIter_t createIterator ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
	};
	
	class op_is_same_node : public function
	{
	public:
		op_is_same_node( const signature& aSig) : function(aSig) {}
		virtual ~op_is_same_node() {}
  public:
    PlanIter_t operator() ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
    xqtref_t type_check ( signature&) const;
    bool validate_args ( std::vector<PlanIter_t>& ) const;
	};
	
	class op_node_before : public function
	{
	public:
		op_node_before( const signature& aSig) : function(aSig) {}
		virtual ~op_node_before() {}
  public:
    PlanIter_t operator() ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
    xqtref_t type_check ( signature&) const;
    bool validate_args ( std::vector<PlanIter_t>& ) const;
	};
	
	class op_node_after : public function
	{
	public:
		op_node_after( const signature& aSig) : function(aSig) {}
		virtual ~op_node_after() {}
  public:
    PlanIter_t operator() ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
    xqtref_t type_check ( signature&) const;
    bool validate_args ( std::vector<PlanIter_t>& ) const;
	};
	
	/*-------------------------- Logical Expressions ---------------------------------------*/
	class op_and : public function
	{
		public:
			op_and ( const signature& );
			~op_and() {}
			
		public:
			PlanIter_t operator() ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
			xqtref_t type_check ( signature&) const;
			bool validate_args ( std::vector<PlanIter_t>& ) const;
	};
	
	class op_or : public function
	{
		public:
			op_or ( const signature& );
			~op_or() {}
			
		public:
			PlanIter_t operator() ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
			xqtref_t type_check ( signature&) const;
			bool validate_args ( std::vector<PlanIter_t>& ) const;
	};


	// 9 Functions and Operators on Boolean Values
	// 9.1.1 fn:true
	class fn_true : public function
	{
		public:
			fn_true ( const signature& );
			~fn_true() {}
			
		public:
			PlanIter_t operator() ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
			xqtref_t type_check ( signature&) const;
			bool validate_args ( std::vector<PlanIter_t>& ) const;
	}; /* class fn_true */
	
	// 9.1.2 fn:false
	class fn_false : public function
	{
		public:
			fn_false ( const signature& );
			~fn_false() {}
			
		public:
			PlanIter_t operator() ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
			xqtref_t type_check ( signature&) const;
			bool validate_args ( std::vector<PlanIter_t>& ) const;
	}; /* class fn_false */
	
	// 9.3.1 fn:not
	class fn_not : public function
	{
	public:
		fn_not ( const signature& );
		~fn_not() {}
		
	public:
		PlanIter_t operator() ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
		xqtref_t type_check ( signature&) const;
		bool validate_args ( std::vector<PlanIter_t>& ) const;
	};

	// 15 Functions and Operators on Sequences
	// 15.1.1 fn:boolean
	class fn_boolean : public function
	{
		public:
			fn_boolean ( const signature& );
			~fn_boolean() {}

		public:
			PlanIter_t operator() ( const QueryLoc& loc, std::vector<PlanIter_t>& ) const;
			xqtref_t type_check ( signature& ) const;
			bool validate_args ( std::vector<PlanIter_t>& ) const;
	}; /* class fn_false */
}

#endif
