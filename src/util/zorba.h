/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
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
#include "types/sequence_type_mgr.h"
#include "util/rchandle.h"
#include "errors/Error.h"

#include <stack>
#include <map>
#ifdef WIN32
#include "util/win32/pthread.h"
#endif

namespace xqp {

class ZorbaErrorAlerts;
class BasicIterator;


class zorba : public rcobject
{
protected:
  // global zorba objects for each thread
	static std::map<uint64_t, zorba*>		global_zorbas;
	static pthread_mutex_t							global_zorbas_mutex;

protected:
	rchandle<ItemFactory>         theValueFactory;
  rchandle<SequenceTypeManager> theSequenceTypeManager;
	rchandle<Store>               theStore;
	rchandle<static_context>      theStaticContext;
	rchandle<dynamic_context>     theDynamicContext;
	// requestor identity, for concurrency

	//daniel
	rchandle<ZorbaErrorAlerts>	error_manager;
public:
	///keep a track of the current parse node or expr node (at compile time)
	//std::stack<const parsenode*>		current_parsenode;
	///keep a track of the current iterator executed (at execution time)
	std::stack<const BasicIterator*>	current_iterator;
	yy::location	null_loc;
	///end daniel

public:
	zorba();

	zorba(
		rchandle<ItemFactory>,
    rchandle<SequenceTypeManager>,
		rchandle<Store>,
		rchandle<static_context>,
		rchandle<dynamic_context>,
		rchandle<ZorbaErrorAlerts>);

	~zorba() {}

public:
	ItemFactory* getItemFactory() const { return &*theValueFactory; }
  SequenceTypeManager* getSequenceTypeManager() const { return &*theSequenceTypeManager; }
	Store* getStore() const { return &*theStore; }
	static_context* get_static_context() const { return &*theStaticContext; }
	dynamic_context* get_dynamic_context() const { return &*theDynamicContext; }
	//daniel
	ZorbaErrorAlerts* get_error_manager() const { return &*error_manager; }

	void setItemFactory(ItemFactory* v) { theValueFactory = v; }
  void setSequenceTypeManager(rchandle<SequenceTypeManager> mgr) { theSequenceTypeManager = mgr; }
	void setStore(Store* s){theStore = s; }
	void set_static_context(static_context* v) { theStaticContext = v; }
	void set_dynamic_context(dynamic_context* v) { theDynamicContext = v; }
	//daniel
	void set_error_manager(ZorbaErrorAlerts *err_manag) { error_manager = err_manag; }

	void set_static_context(rchandle<static_context> v) { theStaticContext = v; }
	void set_dynamic_context(rchandle<dynamic_context> v) { theDynamicContext = v; }
	//daniel
	void set_error_manager(rchandle<ZorbaErrorAlerts> err_manag) { error_manager = err_manag; }

	yy::location& GetCurrentLocation();//from top iterator

public:	// diagnostics
  enum diagnostic_flag_t {
    trace_functions   = 1,
    trace_timing      = 2,
    trace_all         = 4
  };
	
  uint32_t lineno;
  uint32_t charpos;
//daniel	errors::errcode zorba_errno;

//daniel	errors::errcode get_error() const { return zorba_errno; }
//daniel	void set_error(errors::errcode err) { zorba_errno = err; }


	///functions for accessing global zorba objects for each thread
public:
	static void		initializeZorbaEngine();
	static void		uninitializeZorbaEngine();


	static zorba* getZorbaForCurrentThread();
	
	static zorba*	allocateZorbaForNewThread();
	static void		destroyZorbaForCurrentThread();//when ending the thread

};


}	/* namespace xqp */
#endif /*	XQP_ZORBA_H */

