///Created: Daniel Turcanu @ IPDevel 

#ifndef XQP_ZORBA_H
#define XQP_ZORBA_H

#include "util/rchandle.h"

#if defined (WIN32)
#include "util/win32/compatib_defs.h"
//#elif defined (__FreeBSD__)
//typedef unsigned long unsigned long;
#endif

#include <unicode/utypes.h>
#include <unicode/coll.h>
#include <unicode/ustring.h>
//#include "store/api/item_factory.h"
//#include "store/api/store.h"

#include "compiler/parser/location.hh"
#include "types/representations.h"

#include <stack>
#include <map>

namespace xqp {

class ItemFactory;
//class Zorba_XQueryBinary;
class PlanIterator;
class Store;
class static_context;
class AlertsManagerImpl;
//class Zorba_XQueryExecution;
class serializer;
class CollationManager;
class ResultIteratorWrapper;
class dynamic_context;
class Zorba_XQueryInfo;

typedef rchandle<AlertsManagerImpl>		AlertsManagerImpl_t;

///Thread Local Storage: this object is global specific to each thread
class Zorba
{
	friend class ZorbaEngineImpl;

public:
	static Store				* theStore;
	static ItemFactory	* theItemFactory;
	static yy::location	  null_loc;
	
public:///things specific for each thread
	Zorba_XQueryInfo              * current_xquery;//current xquery executed for this thread
	ResultIteratorWrapper						*current_xqueryresult;

//	std::stack<const PlanIterator*>	  current_iterator;
	CollationManager                * coll_manager;

	std::string                       default_coll_string;
	::Collator::ECollationStrength    default_coll_strength;
	bool					                    is_user_set_coll;
	::Collator		                  * default_coll;

protected:
	AlertsManagerImpl_t				       m_error_manager;

	serializer                      * m_item_serializer;///specific for serializing items
	serializer                      * m_doc_serializer;///specific for serializing complete xml

protected:
	Zorba();
	~Zorba();

public:
  static inline ItemFactory* getItemFactory() { return theItemFactory; }
  static inline Store* getStore() { return theStore; }

	AlertsManagerImpl_t getErrorManager();

	::Collator* getCollator(xqp_string collURI = "");

//	yy::location& GetCurrentLocation();//from top iterator
	
	void setDefaultCollation(
        std::string  coll_string,
        ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY);

	void setDefaultCollation(::Collator *default_coll);

	void getDefaultCollation(
        std::string  *coll_string,
        ::Collator::ECollationStrength *coll_strength,
        ::Collator **default_coll);

	static_context* get_static_context();///of the current xquery
	dynamic_context* get_base_dynamic_context();//of the current ResultIterator

	serializer* getItemSerializer();
	serializer* getDocSerializer();
};

}	/* namespace xqp */
#endif /*	XQP_ZORBA_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
