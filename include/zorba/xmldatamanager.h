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
    virtual DocumentManager*
    getDocumentManager() const = 0;

    /** \brief Returns a CollectionManager responsible for all collections.
     * 
     * The collection manager provides a set of functions for managing
     * collections identified by a QName and their contents.
     *
     * Please note that the resulting manager is only responsible for
     * dynamic collections identified by a QName, i.e. those that are
     * not declared in the prolog of a module or identified by a URI.
     *
     * @return The collection manager responsible for managing
     *   collections.
     *
     */
    virtual CollectionManager*
    getCollectionManager() const = 0;

    /** \brief Returns a CollectionManager responsible for collections
     * identified by a URI.
     * 
     * The collection manager provides a set of functions for managing
     * collections identified by a URI and their contents.
     *
     * Please note that the resulting manager is only responsible for
     * dynamic collections identified by a URI, i.e. those that are
     * not declared in the prolog of a module or identified by a QName.
     *
     * @return The collection manager responsible for managing
     *   collections.
     *
     */
    virtual CollectionManager*
    getW3CCollectionManager() const = 0;

    /** \brief Parse an XML document and return an Item.
     *
     */
    virtual Item
    parseXML(std::istream& aStream) const = 0;

    /** \brief Fetches an resource refered to by the given URI.
     */
    virtual Item
    fetch(const String& aURI) const = 0;

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

      /** \brief Register an DiagnosticHandler to which errors occuring during the
       * management of documents and collections are reported.
       *
       * If no DiagnosticHandler has been set using this function then subclasses of
       * the ZorbaException class are thrown to report errors.
       *
       *  @param aDiagnosticHandler DiagnosticHandler to which errors are reported. The
       *         caller retains ownership over the DiagnosticHandler passed as
       *         parameter.
       */
      void
      registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler);

    protected:
      /** \brief Destructor
       */
      virtual ~XmlDataManager() {}

  }; /* class XmlDataManager */

} /* namespace zorba */
#endif
