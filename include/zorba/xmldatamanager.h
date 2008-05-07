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
#include <zorba/api_shared_types.h>

namespace zorba {
  
  /** \brief Using the XmlDataManager one can manage documents and collections.
   * 
   * The XmlDataManager is a singelton instance. The Zorba object is reponsible for 
   * maintaining it's lifetime. The instance can be accessed by calling getXmlDataManager()
   * on the Zorba object. It may not be accessed anymore after Zorba::shutdown() has been called.
   */
  class XmlDataManager 
  {
    public:
      /** \brief Destructor
       */
      virtual ~XmlDataManager() {}

      /** \brief Load a document from an input stream.
       *
       * This function loads a document from an input stream. The document
       * is identified and accessable by the given URI. Errors are either reported
       * by throwing an exception or calling a callback in an ErrorHandler if one has been
       * passed as parameter.
       *
       * @param aURI the URI of the document as String.
       * @param aStream the document given in an input stream.
       * @param aErrorHandler an optional ErrorHandler whose callbacks are called if an error occurs.
       * @return Item the document as an Item.
       * @throws ZorbaException if an error occurs.
       *
       */
      virtual Item 
      loadDocument(const String& aURI, std::istream& aStream, ErrorHandler* aErrorHandler = 0) = 0;
      virtual Item 
      loadDocument(const String& aURI, std::istream* aStream, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Load a document from a file.
       *
       * This function loads a document from a file. The document
       * is identified and accessable by the given URI. Errors are either reported
       * by throwing an exception or calling a callback in an ErrorHandler if one has been
       * passed as parameter.
       *
       * @param aLocalFile the filename of the document as String.
       * @param aErrorHandler an optional ErrorHandler whose callbacks are called if an error occurs.
       * @return Item the document as an Item.
       * @throws ZorbaException if an error occurs.
       *
       */
      virtual Item
      loadDocument(const String& aLocalFile, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Get the document identified by the given URI.
       *
       * @param aURI the URI of the document to get.
       * @param aErrorHandler an optional ErrorHandler whose callbacks are called if an error occurs.
       * @return Item the document as an Item.
       * @throws ZorbaException if an error occurs.
       */
      virtual Item
      getDocument(const String& aURI, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Delete the document identified by the given URI.
       *
       * @param aURI the URI of the document to delete.
       * @param aErrorHandler an optional ErrorHandler whose callbacks are called if an error occurs.
       * @return true if the document was deleted, false otherwise.
       * @throws ZorbaException if an error occurs.
       */
      virtual bool
      deleteDocument(const String& aURI, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Create a collection.
       *
       * @param aURI the URI of the collection to create.
       * @param aErrorHandler an optional ErrorHandler whose callbacks are called if an error occurs.
       * @return Collection_t the collection that was created.
       * @throws ZorbaException if an error occurs.
       */
      virtual Collection_t
      createCollection(const String& aURI, ErrorHandler* aErrorHandler = 0) = 0;

      /** \brief Get a collection.
       *
       * @param aURI the URI of the collection to get.
       * @param aErrorHandler an optional ErrorHandler whose callbacks are called if an error occurs.
       * @return Collection_t the collection identified by the given URI. 
       * @throws ZorbaException if an error occurs.
       */
      virtual Collection_t
      getCollection(const String& aURI, ErrorHandler* aErrorHandler = 0) = 0;


      /** \brief Delete a collection.
       *
       * @param aURI the URI of the collection to delete.
       * @param aErrorHandler an optional ErrorHandler whose callbacks are called if an error occurs.
       * @return true if the collection was deleted, false otherwise.
       * @throws ZorbaException if an error occurs.
       */
      virtual bool
      deleteCollection(const String& aURI, ErrorHandler* aErrorHandler = 0) = 0;

  }; /* class XmlDataManager */

} /* namespace zorba */
#endif
