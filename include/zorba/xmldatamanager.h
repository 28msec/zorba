#ifndef ZORBA_XMLDATAMANAGER_H
#define ZORBA_XMLDATAMANAGER_H

#include <zorbatypes/representations.h>

#include <zorba/common/api_shared_types.h>


namespace zorba { namespace store {

  class XmlDataManager : public SimpleRCObject
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
      virtual store::Item_t loadDocument(const xqp_anyURI& uri, std::istream& stream) = 0;

      virtual store::Item_t loadDocument(const xqp_anyURI& local_file_uri) = 0;

      virtual store::Item_t loadDocument(const xqp_anyURI& uri, store::Item_t item) = 0;  // error if uri exists or item is not a document

      /**
       * Get an rchandle to the root node of the document with the given uri.
       *
       * @param uri The uri of the document to access.
       */
      virtual store::Item_t getDocument(const xqp_anyURI& uri) = 0;

      /**
       * Delete the document with the given uri.
       *
       * @param uri The uri of the document to delete.
       */
      virtual void deleteDocument(const xqp_anyURI& uri) = 0;




      /* ------------------------ Collection Management ---------------------------*/



      virtual bool createCollection(const xqp_anyURI& uri) = 0;  

      virtual bool deleteCollection(const xqp_anyURI& uri) = 0; 


      // some "depricated" methods which we will support until we have a  
      // better way to do collection management
      // with Zorba-specific functions in XQuery
      // all these "addToCollection" functions throw an error if the  
      // specified collection does not exist in the store
      // loading from SAX, DOM and other XML APIs/source done later


      virtual bool addToCollection(const xqp_anyURI& uri, Iterator_t iterator) = 0;
      virtual bool addToCollection(const xqp_anyURI& uri, std::istream& stream) = 0;

  };
} /* namespace store */
} /* namespace zorba */
#endif
