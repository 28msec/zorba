
#include "xmldatamanager_impl.h"
#include <fstream>
#include "errors/error_factory.h"
#include "system/zorba_engine.h"
#include "errors/error_manager.h"
#include "store/api/collection.h"
#include "system/globalenv.h"
#include "system/zorba.h"
#include "zorba/store/api/item.h"
#include "zorba/runtime/iterator.h"
#include "store/api/store.h"

namespace xqp
{


XmlDataManager_Impl::XmlDataManager_Impl()
{
	try{
	internal_store = &GENV.getStore();
	}CATCH_ALL_NO_RETURN(;);

}

XmlDataManager_Impl::~XmlDataManager_Impl()
{
	try{

	}CATCH_ALL_NO_RETURN(;);
}

Item_t XmlDataManager_Impl::loadDocument(const xqp_anyURI& uri, std::istream& stream)
{
	try{

	return internal_store->loadDocument(uri, stream);

	}CATCH_ALL_RETURN_NULL;
}

Item_t XmlDataManager_Impl::loadDocument(const xqp_anyURI& local_file_uri)
{
	try{

	std::ifstream			ifuri(local_file_uri.c_str());

	if(!ifuri.is_open())
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0015_CANNOT_OPEN_FILE, NULL, DONT_CONTINUE_EXECUTION, local_file_uri);
		return NULL;
	}
	return loadDocument(local_file_uri, ifuri);

	}CATCH_ALL_RETURN_NULL;
}

Item_t XmlDataManager_Impl::loadDocument(const xqp_anyURI& uri, Item_t item)  // error if uri exists or item is not a document
{
	try{

	return internal_store->loadDocument(uri, item);

	}CATCH_ALL_RETURN_NULL;
}


Item_t XmlDataManager_Impl::getDocument(const xqp_anyURI& uri)
{
	try{

	return internal_store->getDocument(uri);

	}CATCH_ALL_RETURN_NULL;
}

void XmlDataManager_Impl::deleteDocument(const xqp_anyURI& uri)
{
	try{

	internal_store->deleteDocument(uri);

	}CATCH_ALL_NO_RETURN(;);
}

/* ------------------------ Collection Management ---------------------------*/

bool XmlDataManager_Impl::createCollection(const xqp_anyURI& uri)
{
	try{

		if(internal_store->createCollection( uri ) == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0016_CANNOT_CREATE_COLLECTION, NULL, DONT_CONTINUE_EXECUTION, uri);
			return false;
		}
		else
			return true;
	}CATCH_ALL_RETURN_false;
}

bool XmlDataManager_Impl::deleteCollection(const xqp_anyURI& uri)
{
	try{
	internal_store->deleteCollection(uri);
	}CATCH_ALL_RETURN_false;
	
	return true;
}

bool XmlDataManager_Impl::addToCollection(const xqp_anyURI& uri, Iterator_t iterator)
{
	try{
		Collection_t		colec;
		colec = internal_store->getCollection(uri);
		if(colec == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0006_COLLECTION_NOT_FOUND, NULL, DONT_CONTINUE_EXECUTION, uri);
			return false;
		}
		colec->addToCollection(&*iterator);

	}CATCH_ALL_RETURN_false;
	
	return true;
}

bool XmlDataManager_Impl::addToCollection(const xqp_anyURI& uri, std::istream& stream)
{
	try{
		Collection_t		colec;
		colec = internal_store->getCollection(uri);
		if(colec == NULL)
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0006_COLLECTION_NOT_FOUND, NULL, DONT_CONTINUE_EXECUTION, uri);
			return false;
		}
		colec->addToCollection(stream);

	}CATCH_ALL_RETURN_false;
	
	return true;
}


}//end namespace xqp
