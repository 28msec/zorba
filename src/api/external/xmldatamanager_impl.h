
#ifndef ZORBA_XML_STORE_WRAPPER_IMPL_10_JAN_2008
#define ZORBA_XML_STORE_WRAPPER_IMPL_10_JAN_2008

#include "store/api/store_api.h"
#include "store/api/store.h"

namespace xqp
{

class XmlDataManager_Impl : public XmlDataManager
{
	Store*			internal_store;
public:
	XmlDataManager_Impl();
	virtual ~XmlDataManager_Impl();

  virtual Item_t loadDocument(const xqp_anyURI& uri, std::istream& stream);
  virtual Item_t loadDocument(const xqp_anyURI& local_file_uri);
  virtual Item_t getDocument(const xqp_anyURI& uri);
  virtual void deleteDocument(const xqp_anyURI& uri);




  /* ------------------------ Collection Management ---------------------------*/

  virtual Collection_t createCollection(const xqp_anyURI& uri);
  virtual Collection_t createCollection();
  virtual Collection_t getCollection(const xqp_anyURI& uri);
  virtual void deleteCollection(const xqp_anyURI& uri);

};

}//end namespace xqp

#endif
