///Created: Daniel Turcanu @ IPDevel

#include <map>

#include "compiler/compiled_xquery.h"
#include "zorba.h"

#include "context/common.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "context/collation_manager.h"
#include "api/external/xquery.h"
#include "errors/error_manager.h"
#include "api/serialization/serializer.h"
#include "api/external/result_iterator_wrapper.h"
#include "types/typemanager.h"

using namespace std;
namespace xqp {

Store*				Zorba::theStore = NULL;
ItemFactory	*	Zorba::theItemFactory = NULL;
yy::location	Zorba::null_loc;


Zorba::Zorba()
{
//	coll = NULL;
	current_xquery = NULL;
	current_xqueryresult = NULL;

	m_error_manager = new AlertsManagerImpl;
	m_item_serializer = NULL;
	m_doc_serializer = NULL;
	coll_manager = new CollationManager;

	default_coll_string = "root";
	default_coll_strength = ::Collator::PRIMARY;
	is_user_set_coll = true;//do not try to free
	default_coll = NULL;
}


Zorba::~Zorba()
{
//	if(coll)
//		delete coll;

	//delete m_error_manager;
	delete m_item_serializer;
	delete m_doc_serializer;
	if(!is_user_set_coll)
		coll_manager->removeReference(default_coll_string, default_coll_strength);
	delete coll_manager;

}


///some common functions for TLS

void Zorba::setDefaultCollation(
    std::string coll_string,
    ::Collator::ECollationStrength coll_strength)
{
	if(!is_user_set_coll)
		coll_manager->removeReference(default_coll_string, default_coll_strength);
	default_coll_string = coll_string;
	default_coll_strength = coll_strength;
	is_user_set_coll = false;
	this->default_coll = NULL;
}

void Zorba::setDefaultCollation(::Collator *default_coll)
{
	if(!is_user_set_coll)
		coll_manager->removeReference(default_coll_string, default_coll_strength);
	is_user_set_coll = true;
	this->default_coll = default_coll;
}


void Zorba::getDefaultCollation(
    std::string  *coll_string,
    ::Collator::ECollationStrength *coll_strength,
    ::Collator **default_coll)
{
	*coll_string = default_coll_string;
	*coll_strength = default_coll_strength;
	*default_coll = this->default_coll;
}


::Collator* Zorba::getCollator(xqp_string collURI)
{
	::Collator	*coll;
	if(!get_static_context())
	{//get the zorba default collation, or a hardcoded one
		if(!collURI.empty())
		{
			const CollationManager::COLLATION_DESCR		*coll_descr;
			coll_descr = CollationManager::getHardcodedCollator(collURI);
			if(!coll_descr)
			{
				ZORBA_ERROR_ALERT(ZorbaError::FOCH0002);//unsupported collation
				return NULL;
			}
			coll = coll_manager->getCollation(coll_descr->coll_string, coll_descr->coll_strength);
			if(!coll)
			{
				ZORBA_ERROR_ALERT(ZorbaError::FOCH0002);//unsupported collation
				return NULL;
			}
			return coll;
		}
		else
		{
			if(default_coll)
				return default_coll;
			default_coll = coll_manager->getCollation(default_coll_string, default_coll_strength);
			if(!default_coll)
			{
				ZORBA_ERROR_ALERT(ZorbaError::FOCH0002);//unsupported collation
				return NULL;
			}
			return default_coll;
		}
	}
	
	//redirect to static context wrapper from current_xquery
	if(collURI.empty())///get default collator
	{
		if(current_xquery->default_collator)
			return current_xquery->default_collator;
		current_xquery->default_collator = get_static_context()->getDefaultCollation();
		if(!current_xquery->default_collator)
		{
			ZORBA_ERROR_ALERT(ZorbaError::FOCH0002);//unsupported collation
			return NULL;
		}
		return current_xquery->default_collator;
	}
	else
	{
		coll = get_static_context()->get_collation(collURI);
		if(!coll)
		{
			ZORBA_ERROR_ALERT(ZorbaError::FOCH0002);//unsupported collation
			return NULL;
		}
		return coll;
	}

}

/*
yy::location& Zorba::GetCurrentLocation()//from top iterator
{
	if(current_iterator.empty())
		return null_loc;///no current location information
	else
		return (yy::location&)(current_iterator.top()->loc);
}
*/

static_context* Zorba::get_static_context()///of the current xquery
{
  if(current_xquery)
	  return current_xquery->internal_sctx;
  else
		return NULL;
}

dynamic_context* Zorba::get_base_dynamic_context()//of the current ResultIterator
{
	if(!current_xqueryresult)
		return NULL;
	return current_xqueryresult->internal_dyn_context;
}

AlertsManagerImpl_t Zorba::getErrorManager()
{ 
	return m_error_manager;
}


serializer* Zorba::getItemSerializer()
{
	if(!m_item_serializer)
	{
		m_item_serializer = new serializer;
		m_item_serializer->set_parameter("omit-xml-declaration", "yes");
	}

	return m_item_serializer;
}


serializer* Zorba::getDocSerializer()
{
	if(!m_doc_serializer)
	{
		m_doc_serializer = new serializer;
	}

	return m_doc_serializer;
}

}	/* namespace xqp */



