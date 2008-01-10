
#include "xmldatamanager_impl.h"

namespace xqp
{


XmlDataManager_Impl::XmlDataManager_Impl()
{
	internal_store = &Store::getInstance();
}

XmlDataManager_Impl::~XmlDataManager_Impl()
{
}

Item_t XmlDataManager_Impl::loadDocument(const xqp_anyURI& uri, std::istream& stream)
{
	return internal_store->loadDocument(uri, stream);
}

Item_t XmlDataManager_Impl::getDocument(const xqp_anyURI& uri)
{
	return internal_store->getDocument(uri);
}

void XmlDataManager_Impl::deleteDocument(const xqp_anyURI& uri)
{
	internal_store->deleteDocument(uri);
}

/* ------------------------ Collection Management ---------------------------*/

Collection_t XmlDataManager_Impl::createCollection(const xqp_anyURI& uri)
{
	return internal_store->createCollection( uri );
}

Collection_t XmlDataManager_Impl::createCollection()
{
	return internal_store->createCollection();
}

Collection_t XmlDataManager_Impl::getCollection(const xqp_anyURI& uri)
{
	return internal_store->getCollection(uri);
}

void XmlDataManager_Impl::deleteCollection(const xqp_anyURI& uri)
{
	internal_store->deleteCollection(uri);
}

}//end namespace xqp
