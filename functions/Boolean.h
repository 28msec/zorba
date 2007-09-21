/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#ifndef XQP_BOOLEAN_H
#define XQP_BOOLEAN_H

#include <vector>

#include "context/common.h"
#include "functions/function.h"
// #include "runtime/item_iterator.h"
// #include "types/sequence_type.h"
// #include "util/rchandle.h"
// #include "errors/Error.h"

namespace xqp
{
	class GenericOpComparison : public function
	{
		public:
			GenericOpComparison ( const signature&);
			virtual ~GenericOpComparison() {}

			virtual Iterator_t operator() ( yy::location loc, std::vector<Iterator_t>& ) const;
			virtual TypeCode type_check ( signature& ) const;
			virtual bool validate_args ( std::vector<Iterator_t>& ) const;
			
		protected:
			virtual Iterator_t createIterator( yy::location loc, std::vector<Iterator_t>& ) const = 0;
	};
	
	/*----------------------------------- generic comparison --------------------------------*/
	class op_equal : public GenericOpComparison
	{
	public:
		op_equal( const signature&);
		virtual ~op_equal() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	class op_not_equal : public GenericOpComparison
	{
	public:
		op_not_equal( const signature&);
		virtual ~op_not_equal() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	class op_greater : public GenericOpComparison
	{
	public:
		op_greater( const signature&);
		virtual ~op_greater() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	class op_greater_equal : public GenericOpComparison
	{
	public:
		op_greater_equal( const signature&);
		virtual ~op_greater_equal() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	class op_less : public GenericOpComparison
	{
	public:
		op_less( const signature&);
		virtual ~op_less() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	class op_less_equal : public GenericOpComparison
	{
	public:
		op_less_equal( const signature&);
		virtual ~op_less_equal() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	/*----------------------------------- value comparison --------------------------------*/
	class op_value_equal : public GenericOpComparison
	{
	public:
		op_value_equal( const signature&);
		virtual ~op_value_equal() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	class op_value_not_equal : public GenericOpComparison
	{
	public:
		op_value_not_equal( const signature&);
		virtual ~op_value_not_equal() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	class op_value_greater : public GenericOpComparison
	{
	public:
		op_value_greater( const signature&);
		virtual ~op_value_greater() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	class op_value_greater_equal : public GenericOpComparison
	{
	public:
		op_value_greater_equal( const signature&);
		virtual ~op_value_greater_equal() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	class op_value_less : public GenericOpComparison
	{
	public:
		op_value_less( const signature&);
		virtual ~op_value_less() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};
	
	class op_value_less_equal : public GenericOpComparison
	{
	public:
		op_value_less_equal( const signature&);
		virtual ~op_value_less_equal() {}
	protected:
		virtual Iterator_t createIterator ( yy::location loc, std::vector<Iterator_t>& ) const;
	};

// 9.3 Functions on Boolean Values
// 9.3.1 fn:not
//

// 15.1.1 fn:boolean
	class fn_boolean : public function
	{
		public:
			fn_boolean ( const signature& );
			~fn_boolean() {}

		public:
			Iterator_t operator() ( yy::location loc, std::vector<Iterator_t>& ) const;
			TypeCode type_check ( signature& ) const;
			bool validate_args ( std::vector<Iterator_t>& ) const;
	};
}

#endif
