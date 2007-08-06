/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#ifndef XQP_BOOLEAN_IMPL_H
#define XQP_BOOLEAN_IMPL_H

#include "context/common.h"
#include "functions/function.h"
#include "runtime/item_iterator.h"
#include "types/sequence_type.h"
#include "util/rchandle.h"

namespace xqp{

class zorba;

/*______________________________________________________________________
|  
|	15.1.1 fn:boolean
|	fn:boolean($arg as item()*) as xs:boolean
|	
|	Computes the effective boolean value of the sequence $arg.
|_______________________________________________________________________*/
class fn_boolean_iterator : public basic_iterator
{
public:
	fn_boolean_iterator(yy::location loc, iterator_t);
	virtual ~fn_boolean_iterator() {}

public:	// iterator interface
	void _open();
	void _close();
	std::ostream&  _show(std::ostream&) const;
	item_t _next();
	bool done() const;

private:
	iterator_t arg0;
	bool donef;
};

}

#endif
