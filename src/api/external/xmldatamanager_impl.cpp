
#include "xmldatamanager_impl.h"
#include <fstream>
#include "errors/error_factory.h"

namespace xqp
{


XmlDataManager_Impl::XmlDataManager_Impl()
{
	try{
	internal_store = &Store::getInstance();
	}CATCH_ALL_NO_RETURN;

}

XmlDataManager_Impl::~XmlDataManager_Impl()
{
	try{

	}CATCH_ALL_NO_RETURN;
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
		return NULL;
	return loadDocument(local_file_uri, ifuri);

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

	}CATCH_ALL_NO_RETURN;
}

/* ------------------------ Collection Management ---------------------------*/

Collection_t XmlDataManager_Impl::createCollection(const xqp_anyURI& uri)
{
	try{

		return internal_store->createCollection( uri );
	}CATCH_ALL_RETURN_NULL;
}

Collection_t XmlDataManager_Impl::createCollection()
{
	try{

		return internal_store->createCollection();
	}CATCH_ALL_RETURN_NULL;
}

Collection_t XmlDataManager_Impl::getCollection(const xqp_anyURI& uri)
{
	try{
		return internal_store->getCollection(uri);
	}CATCH_ALL_RETURN_NULL;

}

void XmlDataManager_Impl::deleteCollection(const xqp_anyURI& uri)
{
	try{
	internal_store->deleteCollection(uri);
	}CATCH_ALL_NO_RETURN;
}

}//end namespace xqp
