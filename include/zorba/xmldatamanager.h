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
#include <zorba/static_context_consts.h>

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
  class ZORBA_DLL_PUBLIC XmlDataManager
  {
  public:


      /**
       * \brief The LoadProperties class stores various properties that affect
       *        how a document load is done. An instance of this class is passed
       *        as input to the setVariableAsDocument and setContextItemAsDocument
       *        method of the DynamicContext class.
       */
      class LoadProperties
      {
      private:
          validation_mode_t theValidationMode;
          bool              theEnableDtdLoader;

      public:
          LoadProperties() :
              theValidationMode(validate_skip),
              theEnableDtdLoader(false)
          {}

          ~LoadProperties() {}

          /**
           * Set the property validationMode, it specifies what validation mode
           * should be used when loading the document. If it is equal to
           * validate_skip, no validation is done. Otherwise, the document will
           * be validated in strict or lax mode using the in-scope schema definitions
           * that are found in the query's static context.
           */
          void setValidationMode(validation_mode_t aValidationMode)
          {
              theValidationMode = aValidationMode;
          }

          /**
           * Get the property validationMode, it specifies what validation mode
           * should be used when loading the document. If it is equal to
           * validate_skip, no validation is done. Otherwise, the document will
           * be validated in strict or lax mode using the in-scope schema definitions
           * that are found in the query's static context.
           */
          validation_mode_t getValidationMode() const
          {
              return theValidationMode;
          }

          /**
           * Set the property enableDtd, which specifies whether the document should be
           * validated against its associated DTD (if any).
           */
          void setEnableDtd(bool aEnableDtdLoader)
          {
              theEnableDtdLoader = aEnableDtdLoader;
          }

          /**
           * Get the property enableDtd, which specifies whether the document should be
           * validated against its associated DTD (if any).
           */
          bool getEnableDtd() const
          {
              return theEnableDtdLoader;
          }
      };

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

      /** \brief Parse an XML document and return an Item.
       *
       * This function parses an XML document from an input stream
       * and returns an XDM Item.
       * Note that this function does not store any reference to
       * the document in the XmlDataManager.
       *
       * @params aStream the document given in an input stream.
       * @return Item the document as an Item
       * @throws ZorbaException if an error occurs.
       *
       */
      virtual Item
      parseDocument(std::istream& aStream) = 0;


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
       * @deprecated Use same name method with LoadProperties argument
       */
      virtual Item
      loadDocument(const String& aURI,
                   std::istream& aStream,
                   bool aReplaceDoc = false) = 0;

      /** \brief Load a document from a file.
       *
       * This function loads a document from a file. The file name is used as
       * the URI of the document.
       *
       * @param aLocalFile the filename of the document as String.
       * @return Item the document as an Item.
       * @throws ZorbaException if an error occurs.
       *
       * @deprecated Use same name method with LoadProperties argument
       */
      virtual Item
      loadDocument(const String& aUri, bool aReplaceDoc = false) = 0;

      /** \brief Load a document from an input stream.
       *
       * This function loads a document from an input stream. The document
       * is identified by the given URI.
       *
       * @param aURI the URI of the document as String.
       * @param aStream the document given in an input stream.
       * @param aLoadProperties the way the document is loaded.
       * @param aReplaceDoc to replace the doc if it already exists.
       * @return Item the document as an Item.
       * @throws ZorbaException if an error occurs.
       *
       */
      virtual Item
      loadDocument(const String& aURI,
                   std::istream& aStream,
                   const LoadProperties& aLoadProperties,
                   bool aReplaceDoc = false) = 0;

      /** \brief Load a document from a file.
       *
       * This function loads a document from a file. The file name is used as
       * the URI of the document.
       *
       * @param aLocalFile the filename of the document as String.
       * @param aLoadProperties the way the document is loaded.
       * @param aReplaceDoc to replace the doc if it already exists.
       * @return Item the document as an Item.
       * @throws ZorbaException if an error occurs.
       *
       */
      virtual Item
      loadDocument(const String& aUri,
                   const LoadProperties& aLoadProperties,
                   bool aReplaceDoc = false) = 0;

      /** \brief Load a document from a Uri.
       *
       * This function loads a document from a Uri.
       * The Uri can be a "file://" or "http://".
       *
       * @param aUri the Uri of the document as String.
       * @return Item the document as an Item.
       * @throws ZorbaException if an error occurs.
       *
       */
      virtual Item
      loadDocumentFromUri(const String& aUri, bool aReplaceDoc = false) = 0;

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

      virtual void
      deleteAllDocuments() = 0;

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
