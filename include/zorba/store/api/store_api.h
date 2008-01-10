#ifndef ZORBA_XML_DOCUMENTS_STORE_MODULE_EXTERNAL_API_10_JAN_2008
#define ZORBA_XML_DOCUMENTS_STORE_MODULE_EXTERNAL_API_10_JAN_2008

#include "util/rchandle.h"
#include "types/representations.h"
#include "store/api/item.h"
#include "store/api/collection.h"

namespace xqp
{

class XmlDataManager : public rcobject
{
public:
	virtual ~XmlDataManager() {};
  /**
   * Load a document to the store. The document is loaded from an input stream.
   *
   * @param uri The uri of the document to load.
   * @return rchandle to the newly created document or NULL if a document
   *         with the given uri exists already.
   */
  virtual Item_t loadDocument(const xqp_anyURI& uri, std::istream& stream) = 0;

  /**
   * Get an rchandle to the root node of the document with the given uri.
   *
   * @param uri The uri of the document to access.
   */
  virtual Item_t getDocument(const xqp_anyURI& uri) = 0;

  /**
   * Delete the document with the given uri.
   *
   * @param uri The uri of the document to delete.
   */
  virtual void deleteDocument(const xqp_anyURI& uri) = 0;




  /* ------------------------ Collection Management ---------------------------*/



  /**
   * Creates a collection in the store.
   * 
   * @param URI The URI of the collection to create.
   * @return rchandle to the newly created collection or NULL if a collection
   *         with the given uri exists already.
   */
  virtual Collection_t createCollection(const xqp_anyURI& uri) = 0;

  /** Creates a collection in the store (without given URI).
   * 
   * @return handle object of the newly created collection
   */
  virtual Collection_t createCollection() = 0;
	
  /** Returns an XDM instance which is saved in the store 
   * (corresponds to the opening of a connection to a database)
   *
   * @param URI of the colleciton
   * @return handle object of the collection. Returns NULL if the collection does not exist
   */
  virtual Collection_t getCollection(const xqp_anyURI& uri) = 0;
		
  /** Deletes a collection.
   *
   * @param URI to identify the collection to delete.
   */
  virtual void deleteCollection(const xqp_anyURI& uri) = 0;

};

typedef rchandle<XmlDataManager>		XmlDataManager_t;

}//end namespace xqp

#endif
