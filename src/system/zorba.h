///Created: Daniel Turcanu @ IPDevel 

#ifndef ZORBA_ZORBA_H
#define ZORBA_ZORBA_H

#include <stack>
#include <map>

#include <zorbatypes/representations.h>

#include <zorba/rchandle.h>
#include <zorba/common/common.h>
#include <zorba/common/libicu.h>


//#include "store/api/item_factory.h"
//#include "store/api/store.h"

#include "compiler/parser/query_loc.h"

namespace zorba {

//class Zorba_XQueryBinary;
class PlanIterator;
namespace store {
  class ItemFactory;
  class Store;
}
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
	static store::Store				* theStore;
	static store::ItemFactory	* theItemFactory;
	static QueryLoc       	    null_loc;
	
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
  static inline store::ItemFactory* getItemFactory() { return theItemFactory; }
  static inline store::Store* getStore() { return theStore; }

	AlertsManagerImpl_t getErrorManager();

	::Collator* getCollator(xqp_string collURI = "");

//	QueryLoc& GetCurrentLocation();//from top iterator
	
	void setDefaultCollation(
        std::string  coll_string
        //::Collator::ECollationStrength coll_strength = ::Collator::TERTIARY
        );

	void setDefaultCollation(::Collator *default_coll);

	void getDefaultCollation(
        std::string  *coll_string,
        //::Collator::ECollationStrength *coll_strength,
        ::Collator **default_coll);

	static_context* get_static_context();///of the current xquery
	dynamic_context* get_base_dynamic_context();//of the current ResultIterator

	serializer* getItemSerializer();
	serializer* getDocSerializer();
};

}	/* namespace zorba */
#endif /*	ZORBA_ZORBA_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
