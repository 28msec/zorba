///Created: Daniel Turcanu @ IPDevel 

#ifndef XQP_ZORBA_H
#define XQP_ZORBA_H

#include "util/rchandle.h"

#ifdef WIN32
#include "util/win32/compatib_defs.h"
#endif

#include <unicode/utypes.h>
#include <unicode/coll.h>
#include <unicode/ustring.h>
#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "compiler/parser/location.hh"

#include <stack>
#include <map>
//#ifdef WIN32
//#include <windows.h>
//#include "win32/pthread.h"
//#endif

namespace xqp {

class ItemFactory;
class Zorba_XQueryBinary;
class PlanIterator;
class Store;
class static_context;
class AlertsManagerImpl;
class Zorba_XQueryExecution;
class serializer;
class CollationManager;


///Thread Local Storage: this object is global specific to each thread
class Zorba
{
	friend class ZorbaEngineImpl;

public:
	static Store				* theStore;
	static ItemFactory	* theItemFactory;
	static yy::location	  null_loc;
	
public:///things specific for each thread
	Zorba_XQueryBinary              * current_xquery;//current xquery executed for this thread
	Zorba_XQueryExecution           * current_xqueryresult;
	std::stack<const PlanIterator*>	  current_iterator;
	CollationManager                * coll_manager;

	std::string                       default_coll_string;
	::Collator::ECollationStrength    default_coll_strength;
	bool					                    is_user_set_coll;
	::Collator		                  * default_coll;

protected:
	AlertsManagerImpl               * m_error_manager;

	serializer                      * m_item_serializer;///specific for serializing items
	serializer                      * m_doc_serializer;///specific for serializing complete xml

protected:
	Zorba();
	~Zorba();

public:
  static inline ItemFactory* getItemFactory() { return theItemFactory; }
  static inline Store* getStore() { return theStore; }

	AlertsManagerImpl* getErrorManager();

	::Collator* getCollator(xqp_string collURI = "");

	yy::location& GetCurrentLocation();//from top iterator
	
	void setDefaultCollation(
        std::string  coll_string,
        ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY);

	void setDefaultCollation(::Collator *default_coll);

	void getDefaultCollation(
        std::string  *coll_string,
        ::Collator::ECollationStrength *coll_strength,
        ::Collator **default_coll);

	static_context* get_static_context();///of the current xquery

	serializer* getItemSerializer();
	serializer* getDocSerializer();
};

}	/* namespace xqp */
#endif /*	XQP_ZORBA_H */

