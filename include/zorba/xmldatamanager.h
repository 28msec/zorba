/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_XMLDATAMANAGER_API_H
#define ZORBA_XMLDATAMANAGER_API_H

#include <istream>
#include <zorba/config.h>
#include <zorba/api_shared_types.h>

namespace zorba {
  
  /** \brief Using the XmlDataManager one can manage documents and collections.
   * 
   * The XmlDataManager is a singelton instance. The Zorba object is reponsible
   * for maintaining it's lifetime. The instance can be accessed by calling 
   * getXmlDataManager() on the Zorba object. It may not be accessed anymore
   * after Zorba::shutdown() has been called.
   *
   * XmlDataManager is a thread-safe class.
   */
  class ZORBA_EXTERN_DECL XmlDataManager 
  {
    public:

      /** \brief Register an ErrorHandler to which errors occuring during the 
       * management of documents and collections are reported.
       *
       * If no ErrorHandler has been set using this function then subclasses of
       * the ZorbaException class are thrown to report errors.
       *
       *  @param aErrorHandler ErrorHandler to which errors are reported. The
       *         caller retains ownership over the ErrorHandler passed as
       *         parameter.
       */
      void
      registerErrorHandler(ErrorHandler* aErrorHandler);


      /** \brief Load a document from an input stream.
       *
       * This function loads a document from an input stream. The document
       * is identified by the given URI.
       *
       * @param aURI the URI of the document as String.
       * @param aStream the document given in an input stream.
       * @return Item the document as an Item.
       * @throws ZorbaException if an error occurs.
       *
       */
      virtual Item 
      loadDocument(const String& aURI, std::istream& aStream) = 0;

      /** \brief Load a document from a file.
       *
       * This function loads a document from a file. The file name is used as
       * the URI of the document. 
       *
       * @param aLocalFile the filename of the document as String.
       * @return Item the document as an Item.
       * @throws ZorbaException if an error occurs.
       *
       */
      virtual Item
      loadDocument(const String& aLocalFile) = 0;

      /** \brief Get the document identified by the given URI.
       *
       * @param aURI the URI of the document to get.
       * @return Item the document as an Item (NULL if the document was not found).
       * @throws ZorbaException if an error occurs.
       */
      virtual Item
      getDocument(const String& aURI) = 0;

      /** \brief Delete the document identified by the given URI.
       *
       * @param aURI the URI of the document to delete.
       * @return true if the document was found, false otherwise.
       * @throws ZorbaException if an error occurs.
       */
      virtual bool
      deleteDocument(const String& aURI) = 0;

      /** \brief Create a collection.
       *
       * @param aURI the URI of the collection to create.
       * @return Collection_t the collection that was created.
       * @throws ZorbaException if an error occurs.
       */
      virtual Collection_t
      createCollection(const String& aURI) = 0;

      /** \brief Get a collection.
       *
       * @param aURI the URI of the collection to get.
       * @return Collection_t the collection identified by the given URI
                 (NULL if the collection was not found). 
       * @throws ZorbaException if an error occurs.
       */
      virtual Collection_t
      getCollection(const String& aURI) = 0;


      /** \brief Delete a collection, if the colection has been created before.
       *
       * @param aURI the URI of the collection to delete.
       * @return true if the collection was found, false otherwise.
       * @throws ZorbaException if an error occurs.
       */
      virtual bool
      deleteCollection(const String& aURI) = 0;

    protected:
      /** \brief Destructor
       */
      virtual ~XmlDataManager() {}

  }; /* class XmlDataManager */

} /* namespace zorba */
#endif
