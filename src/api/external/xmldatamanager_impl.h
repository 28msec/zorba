
#ifndef ZORBA_XML_STORE_WRAPPER_IMPL_10_JAN_2008
#define ZORBA_XML_STORE_WRAPPER_IMPL_10_JAN_2008

#include <iostream>
#include <zorba/xmldatamanager.h>
#include "common/shared_types.h"

namespace zorba { namespace store {

class XmlDataManager_Impl : public XmlDataManager
{
  store::Store*			internal_store;
public:
	XmlDataManager_Impl();
	virtual ~XmlDataManager_Impl();

  virtual store::Item_t loadDocument(const xqp_anyURI& uri, std::istream& stream);
  virtual store::Item_t loadDocument(const xqp_anyURI& local_file_uri);
	virtual store::Item_t loadDocument(const xqp_anyURI& uri, store::Item_t item);  // error if uri exists or item is not a document
  virtual store::Item_t getDocument(const xqp_anyURI& uri);
  virtual void deleteDocument(const xqp_anyURI& uri);




  /* ------------------------ Collection Management ---------------------------*/


	virtual bool createCollection(const xqp_anyURI& uri);  

	virtual bool deleteCollection(const xqp_anyURI& uri); 

	virtual bool addToCollection(const xqp_anyURI& uri, Iterator_t iterator);
	virtual bool addToCollection(const xqp_anyURI& uri, std::istream& stream);


};

}
}//end namespace zorba

#endif
