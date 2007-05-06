/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: zorba.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ZORBA_H
#define XQP_ZORBA_H

#include "context/common.h"
#include "context/static_context.h"
#include "context/dynamic_context.h"
#include "runtime/errors.h"
#include "store/data_manager.h"
#include "util/rchandle.h"
#include "values/value_factory.h"


namespace xqp {

class zorba : public rcobject
{
protected:
	rchandle<data_manager> theDataManager;
	rchandle<value_factory> theValueFactory;  // move to data_manager
	rchandle<static_context> theStaticContext;
	rchandle<dynamic_context> theDynamicContext;
	// requestor identity, for concurrency

public:
	zorba();

	zorba(
		rchandle<data_manager>,
		rchandle<value_factory>,
		rchandle<static_context>,
		rchandle<dynamic_context>);

	~zorba() {}

public:
	data_manager* get_data_manager() const { return &*theDataManager; }
	value_factory* get_value_factory() const { return &*theValueFactory; }
	static_context* get_static_context() const { return &*theStaticContext; }
	dynamic_context* get_dynamic_context() const { return &*theDynamicContext; }

	void set_data_manager(data_manager* v) { theDataManager = v; }
	void set_value_factory(value_factory* v) { theValueFactory = v; }
	void set_static_context(static_context* v) { theStaticContext = v; }
	void set_dynamic_context(dynamic_context* v) { theDynamicContext = v; }

	void set_data_manager(rchandle<data_manager> v) { theDataManager = v; }
	void set_value_factory(rchandle<value_factory> v) { theValueFactory = v; }
	void set_static_context(rchandle<static_context> v) { theStaticContext = v; }
	void set_dynamic_context(rchandle<dynamic_context> v) { theDynamicContext = v; }

public:	// diagnostics
  enum diagnostic_flag_t {
    trace_functions   = 1,
    trace_timing      = 2,
    trace_all         = 4
  };
	
  uint32_t lineno;
  uint32_t charpos;
	errors::errcode zorba_errno;

	errors::errcode get_error() const { return zorba_errno; }
	void set_error(errors::errcode err) { zorba_errno = err; }

};


}	/* namespace xqp */
#endif /*	XQP_ZORBA_H */

